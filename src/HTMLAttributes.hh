/*
 *  $Id: HTMLAttributes.hh,v 1.8 1999/05/28 19:37:12 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999 Stephen F. Booth
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _HTMLATTRIBUTES_HH_
#define _HTMLATTRIBUTES_HH_ 1

#ifdef __GNUG__
#pragma interface
#endif

#include <string>
#include <iostream>
#include <vector>

#include "CgiDefs.hh"
#include "MStreamable.hh"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class HTMLAttribute
// ============================================================
/**
 * An HTMLAttribute represents a single name/value pair inside an HTML tag.
 * For example, in the HTML code:
 * <PRE class="html">
 * &lt;A HREF="mailto:sbooth@saaba.lmi.net">Send mail&lt;/A></PRE>
 * The name/value pair <TT>(HREF, mailto:sbooth@saaba.lmi.net)</TT>
 * is an HTMLAttribute.
 */
class HTMLAttribute : public MStreamable 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create an empty HTMLAttribute. */
  HTMLAttribute();
  
  /**
   * Create an HTMLAttribute with the given name and value.
   * @param name The attribute's name, for example <TT>HREF</TT>.
   * @param value The attributes's alue, for exampe <TT>foo.html</TT>.
   */
  HTMLAttribute(const STDNS string& name, 
		const STDNS string& value);

  /**
   * Copy constructor.
   * @param attribute The HTMLAttribute to copy.
   * @exception bad_alloc
   */
  HTMLAttribute(const HTMLAttribute& attribute);
  
  /** Destructor */
  virtual ~HTMLAttribute();
  //@}

  /**@name Overloaded Operators */
  //@{

  /**
   * Compare two HTMLAttributes for equality.
   * HTMLAttributes are equal if they have the same name and value.
   * @param att The HTMLAttribute to compare to this one.
   * @return true if the two HTMLAttributes are equal, false otherwise.
   */
  bool 
  operator== (const HTMLAttribute& att) 		const;

  /**
   * Compare two HTMLAttributes for inequality.
   * HTMLAttributes are equal if they have the same name and value.
   * @param att The HTMLAttribute to compare to this one.
   * @return false if the two HTMLAttributes are equal, true otherwise.
   */
  inline bool 
  operator!= (const HTMLAttribute& att) 		const
    { return ! operator==(att); }

  /**
   * Assign one HTMLAttribute to another.
   * @param att The HTMLAttribute to copy.
   * @return A reference to this.
   */
  HTMLAttribute& 
  operator= (const HTMLAttribute& att);
  
  //@}

  /**@name Accessor Methods */
  //@{
  
  /**
   * Get the name of this HTMLAttribute.
   * @return The attribute's name.
   */
  inline STDNS string 
  getName() 						const
    { return fName; }
  
  /**
   * Get the value of this HTMLAttribute.
   * @return The attribute's value.
   */
  inline STDNS string
  getValue() 						const
    { return fValue; }
  //@}
  
  /**@name Mutator Methods */
  //@{
  
  /**
   * Set the name of this HTMLAttribute.
   * @param name The new name of the attribute.
   */
  inline void 
  setName(const STDNS string& name)
    { fName = name; }
  
  /**
   * Set the value of this HTMLAttribute.
   * @param value The new value of the attribute.
   * @exception bad_alloc
   */
  inline void 
  setValue(const STDNS string& value)
    { fValue = value; }
  //@}
  
  /* Render this attribute */
  virtual void 
  render(STDNS ostream& out) 				const;
  
private:
  STDNS string fName;
  STDNS string fValue;
};

// ============================================================
// Class HTMLAtomicAttribute
// ============================================================
/**
 * An HTMLAtomicAttribute represents a special instance of HTMLAttribute.
 * For example, in the HTML code:
 * <PRE CLASS="html">&lt;IMG SRC="foo.jpg" ISMAP&gt;</PRE>
 * The keyword <EM>ISMAP</EM> is an HTMLAtomicAttribute.
 */
class HTMLAtomicAttribute : public HTMLAttribute 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create an empty HTMLAtomicAttribute. */
  HTMLAtomicAttribute();
  
  /**
   * Create an HTMLAtomicAttribute with the given name.
   * @param name The name of the attribute.
   */	
  HTMLAtomicAttribute(const STDNS string& name);

  /**
   * Copy constructor.
   * @param attribute The HTMLAtomicAttribute to copy.
   */
  HTMLAtomicAttribute(const HTMLAtomicAttribute& attribute);

  /** Destructor */
  virtual ~HTMLAtomicAttribute();
  //@}
  
  /* Render this attribute */
  virtual void 
  render(STDNS ostream& out) 				const;
};

// ============================================================
// Class HTMLAttributeList
// ============================================================
/**
 * An HTMLAttributeList represents any number of HTMLAttributes inside an 
 * HTMLElement.
 * @see HTMLAttribute
 * @see HTMLAtomicAttribute
 */
class HTMLAttributeList 
{
public:

  /**@name Constructors */
  //@{

  /** Create an empty HTMLAttributeList. */
  HTMLAttributeList();

  /**
   * Create a new HTMLAttributeList, specifying the first element.
   * @param head The first element of the list
   */
  HTMLAttributeList(const HTMLAttribute& head);

  /**
   * Copy constructor.
   * @param list The HTMLAttributeList to copy.
   */
  HTMLAttributeList(const HTMLAttributeList& list);

  /** Destructor */
  virtual ~HTMLAttributeList();
  //@}

  /**@name List Addition */
  //@{
  
  /** 
   * Add an HTMLAtomicAttribute name to the list.
   * @param name The name of the HTMLAttribute to add.
   * @return A reference to the list.
   */
  HTMLAttributeList& 
  add(const STDNS string& name);

  /** 
   * Add an HTMLAttribute name/value pair to the list.
   * @param name The name of the HTMLAttribute to add.
   * @param value The value of the HTMLAttribute to add.
   * If NULL, an HTMLAtomicAttribute will be added.
   * @return A reference to the list.
   * @exception bad_alloc
   */
  HTMLAttributeList& 
  add(const STDNS string& name, 
      const STDNS string& value);
  
  //@}

  /* Render this attribute list */
  void 
  render(STDNS ostream& out) 				const;

private:
  STDNS vector<HTMLAttribute> fAttributes;
};

// ============================================================
// List manipulators
// ============================================================
/**
 * Create a new HTMLAttributeList, and add an HTMLAttribute to it.
 * <P>This function is usually called from within the constructor of an
 * \Ref{HTMLElement}:
 * <PRE class="code">
 * out << img(add("isindex")) << endl;
 * </PRE></P>
 * @param name The name of the HTMLAttribute to add.
 * @return A reference to the list.
 */
inline HTMLAttributeList 
add(const STDNS string& name)
{ return HTMLAttributeList(HTMLAtomicAttribute(name)); }

/**
 * Create a new HTMLAttributeList, and add an HTMLAttribute to it.
 * <P>This function is usually called from within the constructor of an
 * \Ref{HTMLElement}:
 * <PRE class="code">
 * out << a("link text", add("href","http://www.foo.com")) << endl;
 * </PRE></P>
 * @param name The name of the HTMLAttribute to add.
 * @param value The value of the HTMLAttribute to add.
 * If NULL, an HTMLAtomicAttribute will be added.
 * @return A reference to the list.
 */
inline HTMLAttributeList 
add(const STDNS string& name, 
    const STDNS string& value)
{ return HTMLAttributeList(HTMLAttribute(name, value)); }

CGICC_END_NAMESPACE

#endif /* ! _HTMLATTRIBUTES_HH_ */
