/*
 *  $Id: HTMLGraphics.hh,v 1.6 1999/04/26 22:42:30 sbooth Exp $
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

#ifndef __HTML_GRAPHICS__
#define __HTML_GRAPHICS__ 1

#include <string>

#include "HTMLElements.hh"

CGICC_BEGIN_NAMESPACE

// except for hr, use stylesheets instead of these elements

// ============================================================
// Class tt
// ============================================================
/** The TT element - preferably use stylesheets to this element */
class tt : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{

  /** Create a new, empty element. */
  tt();
  
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  tt(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  tt(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  tt(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  tt(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  tt(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~tt();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "TT"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class i
// ============================================================
/** The I element - preferably use stylesheets to this element */
class i : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  i();
  
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  i(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  i(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  i(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  i(const STDNS string& text, 
    const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  i(const HTMLAttributeList& attributes, 
    const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~i();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "I"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class b
// ============================================================
/** The B element - preferably use stylesheets to this element */
class b : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  b();
  
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  b(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  b(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  b(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  b(const STDNS string& text, 
    const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  b(const HTMLAttributeList& attributes, 
    const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~b();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "B"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class big
// ============================================================
/** The BIG element - preferably use stylesheets to this element */
class big : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  big();
  
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  big(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  big(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  big(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  big(const STDNS string& text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  big(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~big();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "BIG"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }

private:
  static bool sState;
};

// ============================================================
// Class small
// ============================================================
/** The SMALL element - preferably use stylesheets to this element */
class small : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  small();
  
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  small(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  small(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  small(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  small(const STDNS string& text, 
	const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  small(const HTMLAttributeList& attributes, 
	const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~small();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "SMALL"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class hr
// ============================================================
/** The HR element */
class hr : public HTMLElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  hr();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  hr(const HTMLAttributeList& attributes);
  
  /** Destructor */
  virtual ~hr();
  //@}
  
  virtual inline STDNS string 	getName() 	const 	{ return "HR"; }
};

CGICC_END_NAMESPACE

#endif
