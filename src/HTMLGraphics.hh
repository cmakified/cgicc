/* $Id: HTMLGraphics.hh,v 1.1 1998/04/01 20:49:02 sbooth Exp $ */

#ifndef __HTML_GRAPHICS__
#define __HTML_GRAPHICS__ 1

#ifndef __HTML_ELEMENTS__
#include "HTMLElements.hh"
#endif

// except for hr, use stylesheets instead of these elements

// ============================================================
// Class tt
// ============================================================
/** The TT element - preferably use stylesheets to this element */
class tt : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  tt(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  tt(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  tt(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  tt(const char *text, 
     const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  tt(const HTMLAttributeList& attributes, 
     const HTMLSimpleElement& embed);
  
  virtual ~tt();
  //@}
  
  virtual inline const char* getName() const { return "TT"; }
  
  virtual void swapState() const	{ sState = ! sState; }
  virtual bool getState() const 	{ return sState; }
  static void reset() 			{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class i
// ============================================================
/** The I element - preferably use stylesheets to this element */
class i : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  i(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  i(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  i(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  i(const char *text, 
    const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  i(const HTMLAttributeList& attributes, 
    const HTMLSimpleElement& embed);
  
  virtual ~i();
  //@}
  
  virtual inline const char* getName() const { return "I"; }
  
  virtual void swapState() const	{ sState = ! sState; }
  virtual bool getState() const 	{ return sState; }
  static void reset() 			{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class b
// ============================================================
/** The B element - preferably use stylesheets to this element */
class b : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  b(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  b(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  b(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  b(const char *text, 
    const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  b(const HTMLAttributeList& attributes, 
    const HTMLSimpleElement& embed);
  
  virtual ~b();
  //@}
  
  virtual inline const char* getName() const { return "B"; }
  
  virtual void swapState() const	{ sState = ! sState; }
  virtual bool getState() const 	{ return sState; }
  static void reset() 			{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class big
// ============================================================
/** The BIG element - preferably use stylesheets to this element */
class big : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  big(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  big(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  big(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  big(const char *text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  big(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  virtual ~big();
  //@}
  
  virtual inline const char* getName() const { return "BIG"; }
  
  virtual void swapState() const	{ sState = ! sState; }
  virtual bool getState() const 	{ return sState; }
  static void reset() 			{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class small
// ============================================================
/** The SMALL element - preferably use stylesheets to this element */
class small : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  small(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  small(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  small(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  small(const char *text, 
	const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  small(const HTMLAttributeList& attributes, 
	const HTMLSimpleElement& embed);
  
  virtual ~small();
  //@}
  
  virtual inline const char* getName() const { return "SMALL"; }
  
  virtual void swapState() const	{ sState = ! sState; }
  virtual bool getState() const 	{ return sState; }
  static void reset() 			{ sState = false; }
  
private:
  static bool sState;
};

// ============================================================
// Class hr
// ============================================================
/** The HR element */
class hr : public HTMLElement {
public:
  /**@name Constructors */
  //@{
  
  /** Create a new empty element. */
  hr();
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  hr(const HTMLAttributeList& attributes);
  
  virtual ~hr();
  //@}
  
  virtual inline const char* getName() const { return "HR"; }
};

#endif
