/*
 *  $Id: HTMLGlobal.hh,v 1.6 1999/04/26 22:42:30 sbooth Exp $
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

#ifndef __HTML_GLOBAL__
#define __HTML_GLOBAL__ 1

#include <string>

#include "CgiDefs.hh"
#include "HTMLElements.hh"

#if ! USE_NAMESPACES
#define div div_
#endif

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class comment
// ============================================================
/** An HTML comment */
class comment : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  comment();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  comment(const STDNS string& text);
  
  /** Destructor */
  virtual ~comment();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "!-- "; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }

  virtual void 			render(STDNS ostream& out) const;
  
private:
  static bool sState;
};

// ============================================================
// Class html
// ============================================================
/** The HTML element */
class html : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  html();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  html(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  html(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  html(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  html(const STDNS string& text, 
       const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  html(const HTMLAttributeList& attributes, 
       const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~html();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "HTML"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class head
// ============================================================
/** The HEAD element */
class head : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  head();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  head(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  head(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  head(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  head(const STDNS string& text, 
       const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  head(const HTMLAttributeList& attributes, 
       const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~head();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "HEAD"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class title
// ============================================================
/** The TITLE element */
class title : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  title();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  title(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  title(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  title(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  title(const STDNS string& text, 
	const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  title(const HTMLAttributeList& attributes, 
	const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~title();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "TITLE"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class meta
// ============================================================
/** The META element */
class meta : public HTMLElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  meta();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  meta(const HTMLAttributeList& attributes);
  
  /** Destructor */
  virtual ~meta();
  //@}
  
  virtual inline STDNS string 	getName() 	const 	{ return "META"; }
};

// ============================================================
// Class body
// ============================================================
/** The BODY element */
class body : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  body();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  body(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  body(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  body(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  body(const STDNS string& text, 
       const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  body(const HTMLAttributeList& attributes, 
       const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~body();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "BODY"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class div
// ============================================================
/** The DIV element */
class div : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  div();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  div(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  div(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  div(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  div(const STDNS string& text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  div(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~div();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "DIV"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class span
// ============================================================
/** The SPAN element */
class span : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  span();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  span(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  span(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  span(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  span(const STDNS string& text, 
       const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  span(const HTMLAttributeList& attributes, 
       const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~span();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "SPAN"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class h1
// ============================================================
/** The H1 element */
class h1 : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  h1();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  h1(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  h1(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  h1(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  h1(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  h1(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~h1();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "H1"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class h2
// ============================================================
/** The H2 element */
class h2 : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  h2();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  h2(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  h2(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  h2(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  h2(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  h2(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~h2();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "H2"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class h3
// ============================================================
/** The H3 element */
class h3 : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  h3();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  h3(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  h3(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  h3(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  h3(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  h3(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~h3();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "H3"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class h4
// ============================================================
/** The H4 element */
class h4 : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  h4();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  h4(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  h4(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  h4(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  h4(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  h4(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~h4();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "H4"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class h5
// ============================================================
/** The H5 element */
class h5 : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  h5();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  h5(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  h5(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  h5(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  h5(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  h5(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~h5();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "H5"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class h6
// ============================================================
/** The H6 element */
class h6 : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  h6();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  h6(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  h6(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  h6(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  h6(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  h6(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~h6();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "H6"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class address
// ============================================================
/** The ADDRESS element */
class address : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{

  /** Create a new, empty element. */
  address();

  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  address(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  address(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  address(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  address(const STDNS string& text, 
	  const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  address(const HTMLAttributeList& attributes, 
	  const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~address();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "ADDRESS"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

CGICC_END_NAMESPACE

#endif

//EOF
