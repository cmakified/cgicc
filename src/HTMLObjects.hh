/*
 *  $Id: HTMLObjects.hh,v 1.6 1999/04/26 22:42:31 sbooth Exp $
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

#ifndef __HTML_OBJECTS__
#define __HTML_OBJECTS__ 1

#include <string>

#include "HTMLElements.hh"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class img
// ============================================================
/** The IMG element */
class img : public HTMLElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  img();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  img(const HTMLAttributeList& attributes);
  
  /** Destructor */
  virtual ~img();
  //@}
  
  virtual inline STDNS string 	getName() 	const 	{ return "IMG"; }
};

// ============================================================
// Class object
// ============================================================
/** The OBJECT element */
class object : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{

  /** Create a new, empty element. */
  object();  

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  object(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  object(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  object(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  object(const STDNS string& text, 
	 const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  object(const HTMLAttributeList& attributes, 
	 const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~object();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "OBJECT"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class param
// ============================================================
/** The PARAM element */
class param : public HTMLElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new empty element. */
  param();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  param(const HTMLAttributeList& attributes);
  
  /** Destructor */
  virtual ~param();
  //@}
  
  virtual inline STDNS string 	getName() 	const 	{ return "PARAM"; }
};

// ============================================================
// Class map
// ============================================================
/** The MAP element */
class map : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{

  /** Create a new, empty element. */
  map();  

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  map(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  map(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  map(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  map(const STDNS string& text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  map(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~map();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "MAP"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class area
// ============================================================
/** The AREA element */
class area : public HTMLElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  area();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  area(const HTMLAttributeList& attributes);
  
  /** Destructor */
  virtual ~area();
  //@}
  
  virtual inline STDNS string 	getName() 	const 	{ return "AREA"; }
};

CGICC_END_NAMESPACE

#endif
