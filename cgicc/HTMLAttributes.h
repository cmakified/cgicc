/* -*-c++-*- */
/*
 *  $Id: HTMLAttributes.h,v 1.5 2001/09/02 19:53:17 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _HTMLATTRIBUTES_H_
#define _HTMLATTRIBUTES_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file HTMLAttributes.h
 * \brief Classes dealing with HTML element attributes
 *
 * For example, in the HTML code
 * <pre>
 * \<br clear="all"\>
 * </pre>
 * \c clear is an attribute of the \c br element.
 */

#include <string>
#include <iostream>
#include <vector>

#include "cgicc/CgiDefs.h"
#include "cgicc/MStreamable.h"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class HTMLAttribute
// ============================================================

/*! \class HTMLAttribute HTMLAttributes.h cgicc/HTMLAttributes.h
 * \brief Class representing a name or a single name/value pair
 *
 * An HTMLAttribute represents a single name/value
 * pair inside an HTML element.  For example, in the HTML code:
 * <pre>
 * \<a href="mailto:sbooth@gnu.org"\>Send mail\</A\>
 * </pre>
 * The (name, value) pair <tt>(href, mailto:sbooth@gnu.org)</tt> is
 * an HTMLAttribute.
 */
class CGICC_API HTMLAttribute : public MStreamable 
{
public:
    
  // ============================================================

  /*! \name Constructors and Destructor */
  //@{
  
  /*!
   * \brief Create an empty HTMLAttribute. 
   *
   * The name and value are set to an empty string.
   */
  HTMLAttribute();
  
  /*!
   * \brief Create an HTMLAttribute with the given name.
   *
   * This will simply set the name and value to the same value.
   * \param name The name of the attribute.
   */
  HTMLAttribute(const STDNS string& name);
  
  /*!
   * \brief Create an HTMLAttribute with the given name and value.
   *
   * Most attributes are of this form
   * \param name The attribute's name, for example \c href
   * \param value The attributes's alue, for exampe \c foo.html
   */
  HTMLAttribute(const STDNS string& name, 
		const STDNS string& value);

  /*!
   * \brief Copy constructor.
   *
   * Sets the name of value of this attribute to those of \c attribute
   * \param attribute The HTMLAttribute to copy.
   */
  HTMLAttribute(const HTMLAttribute& attribute);
  
  /*!
   * \brief Destructor 
   *
   * Delete this HTMLAttribute object
   */
  virtual ~HTMLAttribute();
  //@}

  // ============================================================

  /*! \name Overloaded Operators */
  //@{

  /*!
   * \brief Compare two HTMLAttributes for equality.
   *
   * HTMLAttributes are equal if they have the same name and value.
   * \param att The HTMLAttribute to compare to this one.
   * \return \c true if the two HTMLAttributes are equal, \c false otherwise.
   */
  bool 
  operator== (const HTMLAttribute& att) 		const;

  /*!
   * \brief Compare two HTMLAttributes for inequality.
   *
   * HTMLAttributes are equal if they have the same name and value.
   * \param att The HTMLAttribute to compare to this one.
   * \return \c false if the two HTMLAttributes are equal, \c true otherwise.
   */
  inline bool 
  operator!= (const HTMLAttribute& att) 		const
    { return ! operator==(att); }

#ifdef WIN32
  /* Dummy operator for MSVC++ */
  inline bool
  operator< (const HTMLAttribute& att) const
  { return false; }
#endif

  /*!
   * \brief Assign one HTMLAttribute to another.
   *
   * Sets the name of value of this attribute to those of \c att
   * \param att The HTMLAttribute to copy.
   * \return A reference to this.
   */
  HTMLAttribute& 
  operator= (const HTMLAttribute& att);
  //@}  
  
  // ============================================================

  /*! \name Accessor Methods 
   * Information on the attribute
   */
  //@{

  /*!
   * \brief Get the name of this HTMLAttribute.
   *
   * For example, \c HREF
   * \return The attribute's name.
   */
  inline STDNS string 
  getName() 						const
    { return fName; }
  
  /*!
   * \brief Get the value of this HTMLAttribute.
   *
   * For example, \c http://www.gnu.org
   * \return The attribute's value.
   */
  inline STDNS string
  getValue() 						const
    { return fValue; }
  //@}
  
  // ============================================================

  /*! \name Mutator Methods 
   * Set properties of the attribute
   */
  //@{

  /*!
   * \brief Set the name of this HTMLAttribute.
   *
   * Use this method if the name wasn't specified in the constructor
   * \param name The new name of the attribute.
   */
  inline void 
  setName(const STDNS string& name)
    { fName = name; }
  
  /*!
   * \brief Set the value of this HTMLAttribute.
   *
   * Use this method if the value wasn't specified in the constructor
   * \param value The new value of the attribute.
   */
  inline void 
  setValue(const STDNS string& value)
    { fValue = value; }
  //@}
  
  /*!
   * \brief Render this attribute to an ostream
   *
   * This is used for output purposes
   * \param out The ostream to which to write
   */
  virtual void 
  render(STDNS ostream& out) 				const;
  
private:
  STDNS string fName;
  STDNS string fValue;
};


// ============================================================
// Class HTMLAttributeList
// ============================================================

#ifdef WIN32
  template class CGICC_API STDNS vector<HTMLAttribute>;
#endif

/*! \class HTMLAttributeList HTMLAttributes.h cgicc/HTMLAttributes.h
 * \brief An expandable list of HTMLAttributes
 * 
 * An HTMLAttributeList represents any number of HTMLAttributes which may
 * be embedded in an HTMLElement.  To add HTMLAttributes to an 
 * HTMLAttributeList, use the set() methods or functions.  For example,
 * \code
 * cgicc::HTMLAttributeList list = cgicc::set("HEIGHT", "100").set("WIDTH", "100");
 * \endcode
 * generates an HTMLAttributeList with two elements.
 * \see HTMLAttribute
 * \see HTMLElement
 */
class CGICC_API HTMLAttributeList 
{
public:
    
  // ============================================================

  /*! \name Constructors and Destructor */
  //@{

  /*!
   * \brief Create an empty HTMLAttributeList. 
   *
   * HTMLAttributeLists are most often created with the set functions
   */
  HTMLAttributeList();

  /*!
   * \brief Create a new HTMLAttributeList, specifying the first element.
   *
   * The first attribute in the list is set to \c head
   * \param head The first element of the list
   */
  HTMLAttributeList(const HTMLAttribute& head);

  /*!
   * \brief Copy constructor.
   *
   * Sets the elements in this list to those in \c list
   * \param list The HTMLAttributeList to copy.
   */
  HTMLAttributeList(const HTMLAttributeList& list);

  /*!
   * \brief Destructor 
   *
   * Delete this HTMLAttributeList object
   */
  ~HTMLAttributeList();
  //@}

    
  // ============================================================

  /*! \name Overloaded Operators */
  //@{

  /*!
   * \brief Assign one HTMLAttributeList to another.
   *
   * Sets the elements in this list to those in \c list
   * \param list The HTMLAttributeList to copy
   */
  HTMLAttributeList&
  operator= (const HTMLAttributeList &list);
  //@}

    
  // ============================================================

  /*! \name List Management 
   * Add attributes to the list
   */
  //@{

  /*! 
   * \brief Add an atomic HTMLAttribute to this list
   *
   * \c ISINDEX is an example of an atomic attribute.
   * \param name The name of the HTMLAttribute to set.
   * \return A reference to \c this
   */
  HTMLAttributeList& 
  set(const STDNS string& name);

  /*!
   * \brief Add a HTMLAttribute to this list
   *
   * For a list of possible attributes see http://www.w3.org/TR/REC-html40/
   * \param name The name of the HTMLAttribute to set.
   * \param value The value of the HTMLAttribute to set.
   * \return A reference to \c this
   */
  HTMLAttributeList& 
  set(const STDNS string& name, 
      const STDNS string& value);
  //@}

  /*! 
   * \brief Render this HTMLAttributeList to an ostream
   *
   * This is used for output
   * \param out The ostream to which to write
   */
  void 
  render(STDNS ostream& out) 				const;

private:
  STDNS vector<HTMLAttribute> fAttributes;
};

// ============================================================
// List manipulators
// ============================================================

/*!
 * \brief Create a new HTMLAttributeList, and set an HTMLAttribute.
 *
 * This function is usually called from within the constructor of an
 * HTMLElement:
 * \code
 * out << img(set("ISINDEX")) << endl;
 * \endcode
 * \param name The name of the HTMLAttribute to set.
 * \return A reference to the list.
 */
inline HTMLAttributeList 
set(const STDNS string& name)
{ return HTMLAttributeList(HTMLAttribute(name)); }

/*!
 * \brief Create a new HTMLAttributeList, and set an HTMLAttribute.
 *
 * This function is usually called from within the constructor of an
 * HTMLElement:
 * \code
 * out << a("link text", set("HREF","http://www.foo.com")) << endl;
 * \endcode
 * \param name The name of the HTMLAttribute to set.
 * \param value The value of the HTMLAttribute to set.
 * \return A reference to the list.
 */
inline HTMLAttributeList 
set(const STDNS string& name, 
    const STDNS string& value)
{ return HTMLAttributeList(HTMLAttribute(name, value)); }

CGICC_END_NAMESPACE

#endif /* ! _HTMLATTRIBUTES_H_ */
