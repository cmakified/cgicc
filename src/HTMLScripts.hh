/*
 * $Id: HTMLScripts.hh,v 1.4 1998/12/08 23:14:33 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
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

#ifndef __HTML_SCRIPTS__
#define __HTML_SCRIPTS__ 1

#include "HTMLElements.hh"

// ============================================================
// Class script
// ============================================================
/** The SCRIPT element */
class script : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  script(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  script(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  script(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  script(const char *text, 
	 const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  script(const HTMLAttributeList& attributes, 
	 const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~script();
  //@}
  
  virtual inline const char* getName() const { return "SCRIPT"; }
  
  virtual void swapState() const	{ sState = ! sState; }
  virtual bool getState() const 	{ return sState; }

  /**@name State functions */
  //@{

  /** Reset the element to the initial (off) state */
  static void reset() 			{ sState = false; }
  //@}
  
private:
  static bool sState;
};

// ============================================================
// Class noscript
// ============================================================
/** The NOSCRIPT element */
class noscript : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  noscript(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  noscript(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  noscript(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  noscript(const char *text, 
	   const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  noscript(const HTMLAttributeList& attributes, 
	   const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~noscript();
  //@}
  
  virtual inline const char* getName() const { return "NOSCRIPT"; }
  
  virtual void swapState() const	{ sState = ! sState; }
  virtual bool getState() const 	{ return sState; }

  /**@name State functions */
  //@{

  /** Reset the element to the initial (off) state */
  static void reset() 			{ sState = false; }
  //@}
  
private:
  static bool sState;
};

#endif
