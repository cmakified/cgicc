/*
 *  $Id: HTMLLinks.hh,v 1.8 1999/05/28 19:37:14 sbooth Exp $
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

#ifndef _HTMLLINKS_HH_
#define _HTMLLINKS_HH_ 1

#ifdef __GNUG__
#pragma interface
#endif

#include <string>

#include "HTMLElements.hh"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class a
// ============================================================
/** The A element */
class a : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{

  /** Create a new, empty element. */
  a();  

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  a(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  a(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  a(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  a(const STDNS string& text, 
    const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  a(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~a();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "A"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }

private:
  static bool sState;
};

// ============================================================
// Class link
// ============================================================
/** The LINK element */
class link : public HTMLElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new empty element. */
  link();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  link(const HTMLAttributeList& attributes);
  
  /** Destructor */
  virtual ~link();
  //@}
  
  virtual inline STDNS string 	getName() 	const 	{ return "LINK"; }
};

// ============================================================
// Class base
// ============================================================
/** The BASE element */
class base : public HTMLElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new empty element. */
  base();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  base(const HTMLAttributeList& attributes);
  
  /** Destructor */
  virtual ~base();
  //@}
  
  virtual inline STDNS string 	getName() 	const 	{ return "BASE"; }
};

CGICC_END_NAMESPACE

#endif /* ! _HTMLLINKS_HH_ */
