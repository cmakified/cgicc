/*
 *  $Id: HTMLLists.hh,v 1.8 1999/05/28 19:37:14 sbooth Exp $
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

#ifndef _HTMLLISTS_HH_
#define _HTMLLISTS_HH_ 1

#ifdef __GNUG__
#pragma interface
#endif

#include <string>

#include "HTMLElements.hh"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class ul
// ============================================================
/** The UL element */
class ul : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  ul();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  ul(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  ul(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  ul(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  ul(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  ul(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~ul();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "UL"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class ol
// ============================================================
/** The OL element */
class ol : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  ol();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  ol(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  ol(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  ol(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  ol(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  ol(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~ol();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "OL"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class li
// ============================================================
/** The LI element */
class li : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  li();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  li(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  li(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  li(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  li(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  li(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~li();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "LI"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class dl
// ============================================================
/** The DL element */
class dl : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  dl();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  dl(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  dl(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  dl(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  dl(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  dl(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~dl();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "DL"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class dt
// ============================================================
/** The DT element */
class dt : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  dt();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  dt(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  dt(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  dt(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  dt(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  dt(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~dt();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "DT"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class dd
// ============================================================
/** The DD element */
class dd : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{

  /** Create a new, empty element. */
  dd();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  dd(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  dd(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  dd(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  dd(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  dd(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~dd();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "DD"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

CGICC_END_NAMESPACE

#endif /* ! _HTMLLISTS_HH_ */
