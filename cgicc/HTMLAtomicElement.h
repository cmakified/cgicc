/* -*-c++-*- */
/*
 *  $Id: HTMLAtomicElement.h,v 1.1 2001/09/03 22:06:39 sbooth Exp $
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

#ifndef _HTMLATOMICELEMENT_H_
#define _HTMLATOMICELEMENT_H_ 1

/*! \file HTMLAtomicElement.h
 * \brief Template class for concrete atomic HTMLElement subclasses
 *
 */

#include <new>

#include "cgicc/HTMLElement.h"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Template for concrete atomic HTML element classes
// ============================================================

/*! \class HTMLAtomicElement HTMLAtomicElement.h cgicc/HTMLAtomicElement.h
 * \brief Template for concrete atomic HTMLElement subclasses
 *
 * An atomic HTML element is an element in which the opening and closing 
 * tags are combined.  For example, in the HTML code
 \verbatim
 <meta link="made" href="mailto:sbooth@gnu.org" />
 \endverbatim
 * The \c meta tag is an atomic HTML element because the opening and closing
 * tags appear together.
 * \sa HTMLElement
 * \sa HTMLBooleanElement
 */
template<class Tag>
class HTMLAtomicElement : public HTMLElement 
{
public:

  // ============================================================

  /*! \name Constructors and Destructor */
  //@{

  /*!
   * \brief Create a new empty atomic element. 
   *
   */
  HTMLAtomicElement()
    : HTMLElement(0, 0, 0, eAtomic)
  {}
  
  /*!
   * \brief Create a new element, specifying the HTMLAttributes.
   *
   * \param attributes The HTMLAttributes contained within the element.
   */
  HTMLAtomicElement(const HTMLAttributeList& attributes)
    : HTMLElement(&attributes, 0, 0, eAtomic)
  {}

  
  /*!
   * \brief Destructor 
   *
   */
  virtual ~HTMLAtomicElement()
  {}
  //@}

  /*! 
   * \brief Clone this element
   *
   * \return A newly-allocated copy of this element
   */
  virtual inline HTMLElement* 
  clone() 					const
  { return new HTMLAtomicElement<Tag>(*this); }

  
  /*!
   * \brief Get the name of this element.  
   *
   * For example, \c meta.
   * \return The name of this element
   */
  virtual inline const char* 
  getName() 					const
  { return Tag::getName(); }
};

CGICC_END_NAMESPACE

#endif /* ! _HTMLATOMICELEMENT_H_ */
