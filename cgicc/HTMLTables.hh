/*
 *  $Id: HTMLTables.hh,v 1.2 1999/06/04 00:07:41 sbooth Exp $
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

#ifndef _HTMLTABLES_HH_
#define _HTMLTABLES_HH_ 1

#ifdef __GNUG__
#pragma interface
#endif

#include <string>

#include "cgicc/CgiDefs.hh"
#include "cgicc/HTMLElements.hh"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class table
// ============================================================
/** The TABLE element */
class table : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{

  /** Create a new, empty element. */
  table();
  
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  table(const STDNS string& text);
  
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
  table(const STDNS string& text, 
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
  
  virtual inline STDNS string 	getName()	const	{ return "TABLE"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }

private:
  static bool sState;
};

// ============================================================
// Class caption
// ============================================================
/** The CAPTION element */
class caption : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  caption();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  caption(const STDNS string& text);
  
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
  caption(const STDNS string& text, 
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
  
  virtual inline STDNS string 	getName()	const	{ return "CAPTION"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class thead
// ============================================================
/** The THEAD element */
class thead : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  thead();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  thead(const STDNS string& text);
  
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
  thead(const STDNS string& text, 
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
  
  virtual inline STDNS string 	getName()	const	{ return "THEAD"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class tfoot
// ============================================================
/** The TFOOT element */
class tfoot : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  tfoot();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  tfoot(const STDNS string& text);
  
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
  tfoot(const STDNS string& text, 
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
  
  virtual inline STDNS string 	getName()	const	{ return "TFOOT"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class tbody
// ============================================================
/** The TBODY element */
class tbody : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  tbody();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  tbody(const STDNS string& text);
  
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
  tbody(const STDNS string& text,
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
  
  virtual inline STDNS string 	getName()	const	{ return "TBODY"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class colgroup
// ============================================================
/** The COLGROUP element */
class colgroup : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  colgroup();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  colgroup(const STDNS string& text);
  
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
  colgroup(const STDNS string& text, 
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
  
  virtual inline STDNS string 	getName()	const	{ return "COLGROUP"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class col
// ============================================================
/** The COL element */
class col : public HTMLElement 
{
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
  
  virtual inline STDNS string 	getName() 	const 	{ return "COL"; }
};

// ============================================================
// Class tr
// ============================================================
/** The TR element */
class tr : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  tr();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  tr(const STDNS string& text);
  
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
  tr(const STDNS string& text, 
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
  
  virtual inline STDNS string 	getName()	const	{ return "TR"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class th
// ============================================================
/** The TH element */
class th : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  th();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  th(const STDNS string& text);
  
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
  th(const STDNS string& text, 
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
  
  virtual inline STDNS string 	getName()	const	{ return "TH"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class td
// ============================================================
/** The TD element */
class td : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  td();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  td(const STDNS string& text);
  
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
  td(const STDNS string& text, 
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
  
  virtual inline STDNS string 	getName()	const	{ return "TD"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

CGICC_END_NAMESPACE

#endif /* ! _HTMLTABLES_HH_ */
