/*
 * $Id: HTMLDirLang.hh,v 1.3 1998/10/05 22:21:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

#ifndef __HTML_DIRLANG__
#define __HTML_DIRLANG__ 1

#ifndef __HTML_ELEMENTS__
#include "HTMLElements.hh"
#endif

// ============================================================
// Class bdo
// ============================================================
/** The BDO element - Bidirectional text reordering */
class bdo : public HTMLBooleanElement {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new element, optionally specifying the enclosed text.
   * @param text The text within the element.
   */
  bdo(const char *text = NULL);
  
  /**
   * Create a new element, specifying the HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   */
  bdo(const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying an embedded HTMLElement.
   * @param embed The HTMLElement embedded inside the element.
   */
  bdo(const HTMLSimpleElement& embed);
  
  /**
   * Create a new element, specifying the enclosed text and HTMLAttributes.
   * @param attributes The HTMLAttributes contained within the element.
   * @param text The text within the element.
   */
  bdo(const char *text, 
      const HTMLAttributeList& attributes);
  
  /**
   * Create a new element, specifying the HTMLAttributes and 
   * embedded HTMLElement.
   * @param attributes The HTMLAttributes contained within the element.
   * @param embed The HTMLElement embedded inside the element.
   */
  bdo(const HTMLAttributeList& attributes, 
      const HTMLSimpleElement& embed);
  
  /** Destructor */
  virtual ~bdo();
  //@}
  
  virtual inline const char* getName() const { return "BDO"; }
  
  virtual void swapState() const	{ sState = ! sState; }
  virtual bool getState() const 	{ return sState; }
  static void reset() 			{ sState = false; }
  
private:
  static bool sState;
};

#endif
