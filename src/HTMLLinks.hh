/* $Id: HTMLLinks.hh,v 1.1 1998/04/01 20:49:02 sbooth Exp $ */

#ifndef __HTML_LINKS__
#define __HTML_LINKS__ 1

#ifndef __HTML_ELEMENTS__
#include "HTMLElements.hh"
#endif

// ============================================================
// Class a
// ============================================================
/** The A element */
class a : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  a(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  a(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  a(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  a(const char *text, 
    const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  a(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed);
  
  virtual ~a();
  //@}
  
  virtual inline const char* getName() const { return "A"; }
  
  virtual void swapState() const	{ sState = ! sState; }
  virtual bool getState() const 	{ return sState; }
  static void reset() 			{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class link_
// ============================================================
/** The LINK element */
class link_ : public HTMLElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new empty element. */
  link_();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  link_(const HTMLAttributeList& attributes);
  
  virtual ~link_();
  //@}
  
  virtual inline const char* getName() const { return "LINK"; }
};

// ============================================================
// Class base
// ============================================================
/** The BASE element */
class base : public HTMLElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new empty element. */
  base();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  base(const HTMLAttributeList& attributes);
  
  virtual ~base();
  //@}
  
  virtual inline const char* getName() const { return "BASE"; }
};

#endif
