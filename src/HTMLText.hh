/*
 *  $Id: HTMLText.hh,v 1.8 1999/05/28 19:37:15 sbooth Exp $
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

#ifndef _HTMLTEXT_HH_
#define _HTMLTEXT_HH_ 1

#ifdef __GNUG__
#pragma interface
#endif

#include <string>

#include "CgiDefs.hh"
#include "HTMLElements.hh"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class em
// ============================================================
/** The EM element */
class em : public HTMLBooleanElement 
{
public:
  /**@name Constructors */
  //@{

  /** Create a new, empty element. */
  em();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  em(const STDNS string& text);
    
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  em(const HTMLAttributeList& attributes);
    
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  em(const HTMLSimpleElement& embed);
    
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  em(const STDNS string& text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  em(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~em();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "EM"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class strong
// ============================================================
/** The STRONG element */
class strong : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  strong();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  strong(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  strong(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  strong(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  strong(const STDNS string& text, 
	 const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  strong(const HTMLAttributeList& attributes, 
	 const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~strong();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "STRONG"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class dfn
// ============================================================
/** The DFN element */
class dfn : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  dfn();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  dfn(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  dfn(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  dfn(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  dfn(const STDNS string& text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  dfn(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~dfn();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "DFN"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class code
// ============================================================
/** The CODE element */
class code : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  code();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  code(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  code(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  code(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  code(const STDNS string& text, 
       const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  code(const HTMLAttributeList& attributes, 
       const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~code();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "CODE"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class samp
// ============================================================
/** The SAMP element */
class samp : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  samp();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  samp(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  samp(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  samp(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  samp(const STDNS string& text, 
       const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  samp(const HTMLAttributeList& attributes, 
       const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~samp();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "SAMP"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class kbd
// ============================================================
/** The KBD element */
class kbd : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  kbd();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  kbd(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  kbd(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  kbd(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  kbd(const STDNS string& text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  kbd(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~kbd();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "KBD"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class var
// ============================================================
/** The VAR element */
class var : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  var();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  var(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  var(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  var(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  var(const STDNS string& text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  var(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~var();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "VAR"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class cite
// ============================================================
/** The CITE element */
class cite : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  cite();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  cite(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  cite(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  cite(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  cite(const STDNS string& text, 
       const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  cite(const HTMLAttributeList& attributes, 
       const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~cite();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "CITE"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class abbr
// ============================================================
/** The ABBR element */
class abbr : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  abbr();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  abbr(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  abbr(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  abbr(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  abbr(const STDNS string& text, 
       const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  abbr(const HTMLAttributeList& attributes, 
       const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~abbr();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "ABBR"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class acronym
// ============================================================
/** The ACRONYM element */
class acronym : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
   
  /** Create a new, empty element. */
  acronym();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  acronym(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  acronym(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  acronym(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  acronym(const STDNS string& text, 
	  const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  acronym(const HTMLAttributeList& attributes, 
	  const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~acronym();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "ACRONYM"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class blockquote
// ============================================================
/** The BLOCKQUOTE element */
class blockquote : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  blockquote();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  blockquote(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  blockquote(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  blockquote(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  blockquote(const STDNS string& text, 
	     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  blockquote(const HTMLAttributeList& attributes, 
	     const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~blockquote();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "BLOCKQUOTE";}
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class q
// ============================================================
/** The Q element */
class q : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  q();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  q(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  q(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  q(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  q(const STDNS string& text, 
    const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  q(const HTMLAttributeList& attributes, 
    const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~q();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "Q"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class sub
// ============================================================
/** The SUB element */
class sub : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  sub();
  
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  sub(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  sub(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  sub(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  sub(const STDNS string& text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  sub(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~sub();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "SUB"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class sup
// ============================================================
/** The SUP element */
class sup : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  sup();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  sup(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  sup(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  sup(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  sup(const STDNS string& text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  sup(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~sup();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "SUP"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class p
// ============================================================
/** The P element */
class p : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  p();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  p(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  p(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  p(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  p(const STDNS string& text, 
    const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  p(const HTMLAttributeList& attributes, 
    const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~p();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "P"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class br
// ============================================================
/** The BR element */
class br : public HTMLElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new empty element. */
  br();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  br(const HTMLAttributeList& attributes);
  
  /** Destructor */
  virtual ~br();
  //@}
  
  virtual inline STDNS string 	getName() 	const 	{ return "BR"; }
};

// ============================================================
// Class pre
// ============================================================
/** The PRE element */
class pre : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  pre();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  pre(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  pre(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  pre(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  pre(const STDNS string& text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  pre(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~pre();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "PRE"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class ins
// ============================================================
/** The INS element */
class ins : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  ins();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  ins(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  ins(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  ins(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  ins(const STDNS string& text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  ins(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~ins();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "INS"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class del
// ============================================================
/** The DEL element */
class del : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new, empty element. */
  del();
    
  /**
   * Create a new element, specifying the enclosed text.
   * @param text The text within the element.
   */
  del(const STDNS string& text);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  del(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  del(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  del(const STDNS string& text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  del(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~del();
  //@}
  
  virtual inline STDNS string 	getName()	const	{ return "DEL"; }
  virtual inline void 		swapState() 	const 	{ sState = ! sState; }
  virtual inline bool 		getState() 	const 	{ return sState; }
  static inline void 		reset() 		{ sState = false; }
  
private:
  static bool sState;
};

CGICC_END_NAMESPACE

#endif /* ! _HTMLTEXT_HH_ */
