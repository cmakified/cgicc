/* -*-c++-*- */
/*
 *  $Id: HTMLGeneric.h,v 1.4 2001/09/02 19:53:17 sbooth Exp $
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

#ifndef _HTMLGENERIC_H_
#define _HTMLGENERIC_H_ 1

/*! \file HTMLGeneric.h
 * \brief Template classes for concrete HTMLElement subclasses
 *
 */

#include <new>

#include "cgicc/HTMLElements.h"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Template for concrete atomic HTML element classes
// ============================================================

/*! \class GenericAtomicElement HTMLGeneric.h cgicc/HTMLGeneric.h
 * \brief Template for concrete atomic HTMLElement subclasses
 *
 * An atomic HTML element is an element in which the opening and closing 
 * tags are combined.  For example, in the HTML code
 \verbatim
 <meta link="made" href="mailto:sbooth@gnu.org" />
 \endverbatim
 * The \c meta tag is an atomic HTML element because the opening and closing
 * tags appear together.
 */
template<class Tag>
class GenericAtomicElement : public HTMLElement 
{
public:

  // ============================================================

  /*! \name Constructors and Destructor */
  //@{

  /*! Create a new empty atomic element. */
  GenericAtomicElement()
    : HTMLElement(0, 0, 0, eAtomic)
  {}
  
  /*!
   * Create a new element, specifying the HTMLAttributes.
   * \param attributes The HTMLAttributes contained within the element.
   */
  GenericAtomicElement(const HTMLAttributeList& attributes)
    : HTMLElement(&attributes, 0, 0, eAtomic)
  {}

  
  /*! Destructor */
  virtual ~GenericAtomicElement()
  {}
  //@}

  /*! 
   * Clone this element 
   * \return A newly-allocated copy of this element
   */
  virtual inline HTMLElement* 
  clone() 					const
  { return new GenericAtomicElement<Tag>(*this); }

  
  /*!
   * Get the name of this element.  For example, \r meta.
   * \return The name of this element
   */
  virtual inline const char* 
  getName() 					const
  { return Tag::getName(); }
};


// ============================================================
// Template for concrete boolean HTML element classes
// ============================================================

/*! \class GenericBooleanElement HTMLGeneric.h cgicc/HTMLGeneric.h
 * \brief Template for concrete boolean HTMLElement subclasses
 *
 * A boolean HTML element is an element having a boolean (open or closed)
 * state.  Most commonly used HTML tags are boolean elements:
 \verbatim
 <a href="http://www.gnu.org">GNU Project</a>
 \endverbatim
 * The \c a element is boolean, since it is either open or closed.  Boolean
 * elements are often additive:
 \verbatim
 <b>bold text<i>bold italic text</i></b>
 \endverbatim
 * Note than under the XHTML 1.0 standard, elements may not overlap; ie,
 * in the example above, it would be illegal to close the \c b tag before
 * the \c i tag.
 */
template<class Tag>
class GenericBooleanElement : public HTMLElement 
{
public:

  // ============================================================
  
  /*! \name Constructors and Destructor */
  //@{

  /*! Create a new empty boolean element. */
  GenericBooleanElement()
    : HTMLElement(0, 0, 0, eBoolean)
  {}

  /*!
   * Create a new element, specifying the enclosed text.
   * \param text The text within the element.
   */
  GenericBooleanElement(const STDNS string& text)
    : HTMLElement(0, 0, &text, eBoolean)
  {}
  
  /*!
   * Create a new element, specifying the HTMLAttributes.
   * \param attributes The HTMLAttributes contained within the element.
   */
  GenericBooleanElement(const HTMLAttributeList& attributes)
    : HTMLElement(&attributes, 0, 0, eBoolean)
  {}
  
  /*!
   * Create a new element, specifying an embedded HTMLElement.
   * \param embed The HTMLElement embedded inside the element.
   */
  GenericBooleanElement(const HTMLElement& embedded)
    : HTMLElement(0, &embedded, 0, eBoolean)
  {}
  
  /*!
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * \param attributes The HTMLAttributes contained within the element.
   * \param text The text within the element.
   */
  GenericBooleanElement(const STDNS string& text, 
                        const HTMLAttributeList& attributes)
    : HTMLElement(&attributes, 0, &text, eBoolean)
  {}

  /*!
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * \param attributes The HTMLAttributes contained within the element.
   * \param embed The HTMLElement embedded inside the element.
   */
  GenericBooleanElement(const HTMLAttributeList& attributes, 
                        const HTMLElement& embed)
    : HTMLElement(&attributes, &embed, 0, eBoolean)
  {}

  /*! Destructor */
  virtual ~GenericBooleanElement()
  {}
  //@}

  // ============================================================

  /*!
   * Clone this element 
   * \return A newly-allocated copy of this element
   */  
  virtual inline HTMLElement* 
  clone() 					const
  { return new GenericBooleanElement<Tag>(*this); }

  // ============================================================

  /*!
   * Get the name of this element.  For example, "STRONG"
   * \return The name of this element
   */
  virtual inline const char*
  getName() 					const
  { return Tag::getName(); }

  // ============================================================

  /*! \name State Management */
  //@{

  /*!
   * Swap the state of this boolean element
   */
  virtual inline void 
  swapState() 					const
  { sState = ! sState; }
  
  /*! 
   * Get the state of this boolean element 
   * \return \c true if this element is open, \c false otherwise
   */
  virtual inline bool 
  getState() 					const 
  { return sState; }
  
  /*! Reset the state of this boolean element to closed */
  static inline void 
  reset()
  { sState = false; }
  //@}

private:
  static bool sState;
};

template<class Tag>
bool CGICCNS GenericBooleanElement<Tag>::sState = false;

// ============================================================
// Class comment - needs special render function
// ============================================================

class nullTag
{ public: inline static const char* getName() { return 0; } };

/*! \class comment HTMLGeneric.h cgicc/HTMLGeneric.h
 * \brief An HTML comment
 */
class comment : public GenericBooleanElement<nullTag>
{
  virtual void render(STDNS ostream& out) 	const
  {
    if(getData().empty() && dataSpecified() == false) {
      swapState();
      out << (getState() ? "<!-- " : " -->");
    }
    else
      out << "<!-- " << getData() << " -->";
  }
};

CGICC_END_NAMESPACE

#endif /* ! _HTMLGENERIC_H_ */
