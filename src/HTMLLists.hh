/*
 * $Id: HTMLLists.hh,v 1.4 1998/12/08 23:14:33 sbooth Exp $
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

#ifndef __HTML_LISTS__
#define __HTML_LISTS__ 1

#include "HTMLElements.hh"

// ============================================================
// Class ul
// ============================================================
/** The UL element */
class ul : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  ul(const char *text = NULL);
  
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
  ul(const char *text, 
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
  
  virtual inline const char* getName() const { return "UL"; }
  
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
// Class ol
// ============================================================
/** The OL element */
class ol : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  ol(const char *text = NULL);
  
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
  ol(const char *text, 
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
  
  virtual inline const char* getName() const { return "OL"; }
  
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
// Class li
// ============================================================
/** The LI element */
class li : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  li(const char *text = NULL);
  
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
  li(const char *text, 
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
  
  virtual inline const char* getName() const { return "LI"; }
  
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
// Class dl_
// ============================================================
/** The DL element */
class dl_ : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  dl_(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  dl_(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  dl_(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  dl_(const char *text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  dl_(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~dl_();
  //@}
  
  virtual inline const char* getName() const { return "DL"; }
  
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
// Class dt
// ============================================================
/** The DT element */
class dt : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  dt(const char *text = NULL);
  
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
  dt(const char *text, 
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
  
  virtual inline const char* getName() const { return "DT"; }
  
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
// Class dd
// ============================================================
/** The DD element */
class dd : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  dd(const char *text = NULL);
  
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
  dd(const char *text, 
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
  
  virtual inline const char* getName() const { return "DD"; }
  
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
