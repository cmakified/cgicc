/* $Id: HTMLStyles.hh,v 1.1 1998/04/01 20:49:02 sbooth Exp $ */

#ifndef __HTML_STYLES__
#define __HTML_STYLES__ 1

#ifndef __HTML_ELEMENTS__
#include "HTMLElements.hh"
#endif

// ============================================================
// Class style
// ============================================================
/** The STYLE element */
class style : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  style(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  style(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  style(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  style(const char *text, 
	const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and embedded 
   * HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  style(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed);
  
  virtual ~style();
  //@}
  
  virtual inline const char* getName() const { return "STYLE"; }
  
  virtual void swapState() const	{ sState = ! sState; }
  virtual bool getState() const 	{ return sState; }
  static void reset() 			{ sState = false; }
  
private:
  static bool sState;
};

#endif
