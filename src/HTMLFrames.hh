/*
 *  $Id: HTMLFrames.hh,v 1.6 1999/04/26 22:42:29 sbooth Exp $
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

#ifndef __HTML_FRAMES__
#define __HTML_FRAMES__ 1

#include <string>

#include "CgiDefs.hh"
#include "HTMLElements.hh"

CGICC_BEGIN_NAMESPACE

// these elements not part of strict dtd

// ============================================================
// Class frameset
// ============================================================
/**
 * The FRAMESET element 
 * FRAMESET is not part of the strict DTD.
 */
class frameset : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new element. */
  frameset();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  frameset(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  frameset(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  frameset(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  frameset(const STDNS string& text, 
	   const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  frameset(const HTMLAttributeList& attributes, 
	   const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~frameset();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "FRAMESET"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class frame
// ============================================================
/** 
 * The FRAME element
 * FRAME is not part of the strict DTD.
 */
class frame : public HTMLElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new empty element. */
  frame();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  frame(const HTMLAttributeList& attributes);
  
  /** Destructor */
  virtual ~frame();
  //@}
  
  virtual inline STDNS string 	getName() const 	{ return "FRAME"; }
};

// ============================================================
// Class noframes
// ============================================================
/** 
 * The NOFRAMES element
 * NOFRAMES is not part of the strict DTD 
 */
class noframes : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new element. */
  noframes();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  noframes(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  noframes(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  noframes(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  noframes(const STDNS string& text, 
	   const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  noframes(const HTMLAttributeList& attributes, 
	   const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~noframes();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "NOFRAMES"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class iframe
// ============================================================
/** 
 * The IFRAME element
 * IFRAME is not part of the strict DTD
 */
class iframe : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{

  /** Create a new element. */
  iframe();
  
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  iframe(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  iframe(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  iframe(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  iframe(const STDNS string& text, 
	 const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  iframe(const HTMLAttributeList& attributes, 
	 const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~iframe();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "IFRAME"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

CGICC_END_NAMESPACE

#endif

//EOF
