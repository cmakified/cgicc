/*
 * $Id: HTMLTables.hh,v 1.4 1998/12/08 23:14:33 sbooth Exp $
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

#ifndef __HTML_TABLES__
#define __HTML_TABLES__ 1

#include "HTMLElements.hh"

// ============================================================
// Class table
// ============================================================
/** The TABLE element */
class table : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  table(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  table(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  table(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  table(const char *text, 
	const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  table(const HTMLAttributeList& attributes, 
	const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~table();
  //@}
  
  virtual inline const char* getName() const { return "TABLE"; }
  
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
// Class caption
// ============================================================
/** The CAPTION element */
class caption : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  caption(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  caption(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  caption(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  caption(const char *text, 
	  const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  caption(const HTMLAttributeList& attributes, 
	  const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~caption();
  //@}
  
  virtual inline const char* getName() const { return "CAPTION"; }
  
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
// Class thead
// ============================================================
/** The THEAD element */
class thead : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  thead(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  thead(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  thead(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  thead(const char *text, 
	const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  thead(const HTMLAttributeList& attributes, 
	const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~thead();
  //@}
  
  virtual inline const char* getName() const { return "THEAD"; }
  
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
// Class tfoot
// ============================================================
/** The TFOOT element */
class tfoot : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  tfoot(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  tfoot(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  tfoot(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  tfoot(const char *text, 
	const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  tfoot(const HTMLAttributeList& attributes, 
	const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~tfoot();
  //@}
  
  virtual inline const char* getName() const { return "TFOOT"; }
  
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
// Class tbody
// ============================================================
/** The TBODY element */
class tbody : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  tbody(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  tbody(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  tbody(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  tbody(const char *text,
	const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  tbody(const HTMLAttributeList& attributes, 
	const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~tbody();
  //@}
  
  virtual inline const char* getName() const { return "TBODY"; }
  
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
// Class colgroup
// ============================================================
/** The COLGROUP element */
class colgroup : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  colgroup(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  colgroup(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  colgroup(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  colgroup(const char *text, 
	   const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  colgroup(const HTMLAttributeList& attributes, 
	   const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~colgroup();
  //@}
  
  virtual inline const char* getName() const { return "COLGROUP"; }
  
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
// Class col
// ============================================================
/** The COL element */
class col : public HTMLElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new empty element. */
  col();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  col(const HTMLAttributeList& attributes);
  
  /** Destructor */
  virtual ~col();
  //@}
  
  virtual inline const char* getName() const { return "COL"; }
};

// ============================================================
// Class tr
// ============================================================
/** The TR element */
class tr : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  tr(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  tr(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  tr(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  tr(const char *text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  tr(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~tr();
  //@}
  
  virtual inline const char* getName() const { return "TR"; }
  
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
// Class th
// ============================================================
/** The TH element */
class th : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  th(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  th(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  th(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  th(const char *text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  th(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~th();
  //@}
  
  virtual inline const char* getName() const { return "TH"; }
  
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
// Class td
// ============================================================
/** The TD element */
class td : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  td(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  td(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  td(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  td(const char *text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  td(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~td();
  //@}
  
  virtual inline const char* getName() const { return "TD"; }
  
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
