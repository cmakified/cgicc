/* -*-c++-*- */
/*
 *  $Id: HTMLGeneric.h,v 1.3 1999/08/10 00:29:04 sbooth Exp $
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

#ifndef _HTMLGENERIC_H_
#define _HTMLGENERIC_H_ 1

#include <new>

#include "cgicc/HTMLElements.h"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Template for concrete atomic HTML element classes
// ============================================================
template<class Tag>
class GenericAtomicElement : public HTMLElement 
{
public:
  
  /** Create a new empty element. */
  GenericAtomicElement()
    : HTMLElement(0, 0, 0, eAtomic)
  {}
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  GenericAtomicElement(const HTMLAttributeList& attributes)
    : HTMLElement(&attributes, 0, 0, eAtomic)
  {}

  
  /** Destructor */
  virtual ~GenericAtomicElement()
  {}


  /** Clone this element */
  virtual inline HTMLElement* 
  clone() 					const
  { return new GenericAtomicElement<Tag>(*this); }

  
  /** Get the name of this element */
  virtual inline const char* 
  getName() 					const
  { return Tag::getName(); }
};


// ============================================================
// Template for concrete boolean HTML element classes
// ============================================================
template<class Tag>
class GenericBooleanElement : public HTMLElement 
{
public:
  
  /** Create a new element. */
  GenericBooleanElement()
    : HTMLElement(0, 0, 0, eBoolean)
  {}

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  GenericBooleanElement(const STDNS string& text)
    : HTMLElement(0, 0, &text, eBoolean)
  {}
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  GenericBooleanElement(const HTMLAttributeList& attributes)
    : HTMLElement(&attributes, 0, 0, eBoolean)
  {}
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  GenericBooleanElement(const HTMLElement& embedded)
    : HTMLElement(0, &embedded, 0, eBoolean)
  {}
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  GenericBooleanElement(const STDNS string& text, 
                        const HTMLAttributeList& attributes)
    : HTMLElement(&attributes, 0, &text, eBoolean)
  {}

  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  GenericBooleanElement(const HTMLAttributeList& attributes, 
                        const HTMLElement& embed)
    : HTMLElement(&attributes, &embed, 0, eBoolean)
  {}

  /** Destructor */
  virtual ~GenericBooleanElement()
  {}


  /** Clone this element */  
  virtual inline HTMLElement* 
  clone() 					const
  { return new GenericBooleanElement<Tag>(*this); }


  /** Get the name of this element */
  virtual inline const char*
  getName() 					const
  { return Tag::getName(); }


  /** Swap the state of this boolean element */
  virtual inline void 
  swapState() 					const
  { sState = ! sState; }
  
  /** Get the state of this boolean element */
  virtual inline bool 
  getState() 					const 
  { return sState; }
  
  /** Reset the state of this boolean element to off */
  static inline void 
  reset()
  { sState = false; }
  
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
