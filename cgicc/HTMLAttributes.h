/* -*-c++-*- */
/*
 *  $Id: HTMLAttributes.h,v 1.3 1999/08/16 17:40:04 sbooth Exp $
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

#ifndef _HTMLATTRIBUTES_H_
#define _HTMLATTRIBUTES_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

#include <string>
#include <iostream>
#include <vector>

#include "cgicc/CgiDefs.h"
#include "cgicc/MStreamable.h"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class HTMLAttribute
// ============================================================
/**
 * An HTMLAttribute represents a either a name or a single name/value 
 * pair inside an HTML tag.
 * For example, in the HTML code:
 * <PRE class="html">
 * &lt;A HREF="mailto:sbooth@saaba.lmi.net">Send mail&lt;/A></PRE>
 * The name/value pair <TT>(HREF, mailto:sbooth@saaba.lmi.net)</TT>
 * is an HTMLAttribute.
 */
class CGICC_API HTMLAttribute : public MStreamable 
{
public:
  
  /** Create an empty HTMLAttribute. */
  HTMLAttribute();
  
  /**
   * Create an HTMLAttribute with the given name.
   * @param name The name of the attribute.
   */
  HTMLAttribute(const STDNS string& name);
  
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
   */
  HTMLAttribute(const HTMLAttribute& attribute);
  
  /** Destructor */
  virtual ~HTMLAttribute();


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

#ifdef WIN32
  /** Dummy operator for MSVC++ */
  inline bool
  operator< (const HTMLAttribute& att) const
  { return false; }
#endif

  /**
   * Assign one HTMLAttribute to another.
   * @param att The HTMLAttribute to copy.
   * @return A reference to this.
   */
  HTMLAttribute& 
  operator= (const HTMLAttribute& att);
  
  
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

  /**
   * Determine if this is an atomic HTMLAttribute.
   * @return true if this is an atomic HTMLAttribute, false otherwise.
   */
  inline bool
  isAtomic() 						const
    { return fAtomic; }

  
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
   */
  inline void 
  setValue(const STDNS string& value)
    { fValue = value; }

  /** 
   * Set whether this is an atomic HTMLAttribute.
   * @param atomic Whether this is an atomic HTMLAttribute.
   */
  inline void
  setAtomic(bool atomic)
    { fAtomic = atomic; }

  
  /* Render this attribute */
  virtual void 
  render(STDNS ostream& out) 				const;
  
private:
  STDNS string fName;
  STDNS string fValue;
  bool fAtomic;
};


// ============================================================
// Class HTMLAttributeList
// ============================================================

#ifdef WIN32
  template class CGICC_API STDNS vector<HTMLAttribute>;
#endif

/**
 * An HTMLAttributeList represents any number of HTMLAttributes inside an 
 * HTMLElement.
 * @see HTMLAttribute
 */
class CGICC_API HTMLAttributeList 
{
public:

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
  ~HTMLAttributeList();


  /**
   * Assign one HTMLAttributeList to another.
   */
  HTMLAttributeList&
  operator= (const HTMLAttributeList &list);
  
  /** 
   * Set an HTMLAtomicAttribute on an HTMLElement.
   * @param name The name of the HTMLAttribute to set.
   * @return A reference to the list.
   */
  HTMLAttributeList& 
  set(const STDNS string& name);

  /** 
   * Set an HTMLAttribute name/value pair on an HTMLElement.
   * @param name The name of the HTMLAttribute to set.
   * @param value The value of the HTMLAttribute to set.
   * @return A reference to the list.
   */
  HTMLAttributeList& 
  set(const STDNS string& name, 
      const STDNS string& value);
  
  /** Render this HTMLAttributeList */
  void 
  render(STDNS ostream& out) 				const;

private:
  STDNS vector<HTMLAttribute> fAttributes;
};

// ============================================================
// List manipulators
// ============================================================
/**
 * Create a new HTMLAttributeList, and set an HTMLAttribute.
 * <P>This function is usually called from within the constructor of an
 * \Ref{HTMLElement}:
 * <PRE class="code">
 * out << img(set("ISINDEX")) << endl;
 * </PRE></P>
 * @param name The name of the HTMLAttribute to set.
 * @return A reference to the list.
 */
inline HTMLAttributeList 
set(const STDNS string& name)
{ return HTMLAttributeList(HTMLAttribute(name)); }

/**
 * Create a new HTMLAttributeList, and set an HTMLAttribute.
 * <P>This function is usually called from within the constructor of an
 * \Ref{HTMLElement}:
 * <PRE class="code">
 * out << a("link text", set("HREF","http://www.foo.com")) << endl;
 * </PRE></P>
 * @param name The name of the HTMLAttribute to set.
 * @param value The value of the HTMLAttribute to set.
 * @return A reference to the list.
 */
inline HTMLAttributeList 
set(const STDNS string& name, 
    const STDNS string& value)
{ return HTMLAttributeList(HTMLAttribute(name, value)); }

CGICC_END_NAMESPACE

#endif /* ! _HTMLATTRIBUTES_H_ */
