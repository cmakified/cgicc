/* -*-c++-*- */
/*
 *  $Id: HTMLBooleanElement.h,v 1.1 2001/09/03 22:06:39 sbooth Exp $
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

#ifndef _HTMLBOOLEANELEMENT_H_
#define _HTMLBOOLEANELEMENT_H_ 1

/*! \file HTMLBooleanElement.h
 * \brief Template class for concrete boolean HTMLElement subclasses
 *
 */

#include <new>

#include "cgicc/HTMLElement.h"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Template for concrete boolean HTML element classes
// ============================================================

/*! \class HTMLBooleanElement HTMLBooleanElement.h cgicc/HTMLBooleanElement.h
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
 * \sa HTMLElement
 * \sa HTMLAtomicElement
 */
template<class Tag>
class HTMLBooleanElement : public HTMLElement 
{
public:

  // ============================================================
  
  /*! \name Constructors and Destructor */
  //@{

  /*! 
   * \brief Create a new empty boolean element. 
   *
   */
  HTMLBooleanElement()
    : HTMLElement(0, 0, 0, eBoolean)
  {}

  /*!
   * \brief Create a new element, specifying the enclosed text.
   * \param text The text within the element.
   */
  HTMLBooleanElement(const STDNS string& text)
    : HTMLElement(0, 0, &text, eBoolean)
  {}
  
  /*!
   * \brief Create a new element, specifying the HTMLAttribute objects.
   * \param attributes The HTMLAttributes contained within the element.
   */
  HTMLBooleanElement(const HTMLAttributeList& attributes)
    : HTMLElement(&attributes, 0, 0, eBoolean)
  {}
  
  /*!
   * \brief Create a new element, specifying an embedded HTMLElement.
   * \param embed The HTMLElement embedded inside the element.
   */
  HTMLBooleanElement(const HTMLElement& embedded)
    : HTMLElement(0, &embedded, 0, eBoolean)
  {}
  
  /*!
   * \brief Create a new element, specifying the enclosed text and 
   * HTMLAttribute objects.
   * \param attributes The HTMLAttributes contained within the element.
   * \param text The text within the element.
   */
  HTMLBooleanElement(const STDNS string& text, 
                        const HTMLAttributeList& attributes)
    : HTMLElement(&attributes, 0, &text, eBoolean)
  {}

  /*!
   * \brief Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * \param attributes The HTMLAttributes contained within the element.
   * \param embed The HTMLElement embedded inside the element.
   */
  HTMLBooleanElement(const HTMLAttributeList& attributes, 
                        const HTMLElement& embed)
    : HTMLElement(&attributes, &embed, 0, eBoolean)
  {}

  /*! 
   * \brief Destructor 
   *
   */
  virtual ~HTMLBooleanElement()
  {}
  //@}

  // ============================================================

  /*!
   * \brief Clone this element 
   * \return A newly-allocated copy of this element
   */  
  virtual inline HTMLElement* 
  clone() 					const
  { return new HTMLBooleanElement<Tag>(*this); }

  // ============================================================

  /*!
   * \brief Get the name of this element.  For example, "strong"
   * \return The name of this element
   */
  virtual inline const char*
  getName() 					const
  { return Tag::getName(); }

  // ============================================================

  /*! \name State Management */
  //@{

  /*!
   * \brief Swap the state of this boolean element
   *
   * A state of \c true indicates the element is currently open
   */
  virtual inline void 
  swapState() 					const
  { sState = ! sState; }
  
  /*! 
   * \brief Get the state of this boolean element 
   * \return \c true if this element is open, \c false otherwise
   */
  virtual inline bool 
  getState() 					const 
  { return sState; }
  
  /*! 
   * \brief Reset the state of this boolean element to closed
   *
   */
  static inline void 
  reset()
  { sState = false; }
  //@}

private:
  static bool sState;
};

template<class Tag>
bool CGICCNS HTMLBooleanElement<Tag>::sState = false;

CGICC_END_NAMESPACE

#endif /* ! _HTMLBOOLEANELEMENT_H_ */
