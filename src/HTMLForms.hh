/*
 * $Id: HTMLForms.hh,v 1.4 1998/12/08 23:14:33 sbooth Exp $
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

#ifndef __HTML_FORMS__
#define __HTML_FORMS__ 1

#include "HTMLElements.hh"

// ============================================================
// Class form
// ============================================================
/** The FORM element */
class form : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  form(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  form(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  form(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  form(const char *text, 
       const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  form(const HTMLAttributeList& attributes, 
       const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~form();
  //@}
  
  virtual inline const char* getName() const { return "FORM"; }
  
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
// Class input
// ============================================================
/** The INPUT element */
class input : public HTMLElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new empty element. */
  input();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  input(const HTMLAttributeList& attributes);
  
  /** Destructor */
  virtual ~input();
  //@}
  
  virtual inline const char* getName() const { return "INPUT"; }
};

// ============================================================
// Class button
// ============================================================
/** The BUTTON element */
class button : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  button(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  button(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  button(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  button(const char *text, 
	 const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  button(const HTMLAttributeList& attributes, 
	 const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~button();
  //@}
  
  virtual inline const char* getName() const { return "BUTTON"; }
  
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
// Class select
// ============================================================
/** The SELECT element */
class select : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  select(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  select(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  select(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  select(const char *text, 
	 const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  select(const HTMLAttributeList& attributes, 
	 const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~select();
  //@}
  
  virtual inline const char* getName() const { return "SELECT"; }
  
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
// Class optgroup
// ============================================================
/** The OPTGROUP element */
class optgroup : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  optgroup(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  optgroup(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  optgroup(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  optgroup(const char *text, 
	   const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  optgroup(const HTMLAttributeList& attributes, 
	   const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~optgroup();
  //@}
  
  virtual inline const char* getName() const { return "OPTGROUP"; }
  
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
// Class option
// ============================================================
/** The OPTION element */
class option : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  option(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  option(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  option(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  option(const char *text, 
	 const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  option(const HTMLAttributeList& attributes, 
	 const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~option();
  //@}
  
  virtual inline const char* getName() const { return "OPTION"; }
  
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
// Class textarea
// ============================================================
/** The TEXTAREA element */
class textarea : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  textarea(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  textarea(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  textarea(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  textarea(const char *text, 
	   const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  textarea(const HTMLAttributeList& attributes, 
	   const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~textarea();
  //@}
  
  virtual inline const char* getName() const { return "TEXTAREA"; }
  
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
// Class label
// ============================================================
/** The LABEL element */
class label : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  label(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  label(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  label(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  label(const char *text, 
	const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  label(const HTMLAttributeList& attributes, 
	const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~label();
  //@}
  
  virtual inline const char* getName() const { return "LABEL"; }
  
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
// Class fieldset
// ============================================================
/** The FIELDSET element */
class fieldset : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  fieldset(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  fieldset(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  fieldset(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  fieldset(const char *text, 
	   const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  fieldset(const HTMLAttributeList& attributes, 
	   const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~fieldset();
  //@}
  
  virtual inline const char* getName() const { return "FIELDSET"; }
  
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
// Class legend
// ============================================================
/** The LEGEND element */
class legend : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  legend(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  legend(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  legend(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  legend(const char *text, 
	 const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  legend(const HTMLAttributeList& attributes, 
	 const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~legend();
  //@}
  
  virtual inline const char* getName() const { return "LEGEND"; }
  
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
