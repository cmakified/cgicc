/*
 * $Id: HTMLElements.hh,v 1.3 1998/10/05 22:21:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

#ifndef __HTML_ELEMENTS__
#define __HTML_ELEMENTS__ 1

#ifndef __MSTREAMABLE__
#include "MStreamable.hh"
#endif

#ifndef __LINKED_LIST__
#include "LinkedList.hh"
#endif

#ifndef __HTML_ATTRIBUTES__
#include "HTMLAttributes.hh"
#endif

// ============================================================
// Class HTMLElement
// ============================================================
/** An abstract class representing an HTML tag.*/
class HTMLElement : public MStreamable {
public:
  /**@name Constructors */
  //@{
  
  /** Constructor */
  HTMLElement();

  /**
   * Copy constructor.
   * @param element The HTMLElement to copy.
   * @exception Exception
   */
  HTMLElement(const HTMLElement& element) throw(Exception);

  /** Destructor */
  virtual ~HTMLElement();
  //@}

  /**@name Accessor Functions */
  //@{	
  
  /**
   * Get the name of this element.
   * For example, HTML or BODY.
   * @return The name of this element.
   */
  virtual inline const char* getName() const = 0;
  
  /**
   * Get the attributes associated with this element.
   * @return An HTMLAttributeList containing all the HTMLAttributes belonging 
   * to this element.
   */
  inline const HTMLAttributeList* getAttributes() const { return fAttributes; }
  //@}
  
  /**@name Mutator Functions */
  //@{
  /**
   * Set the attributes associated with this element.
   * @param attributes The HTMLAttributeList containing the HTMLAttributes 
   * belonging to this element.
   */
  inline void setAttributes(const HTMLAttributeList *attributes) 
  { fAttributes = attributes; }
  //@}
  
  virtual void render(ostream& out) const;
  
protected:
  HTMLElement(const HTMLAttributeList *attributes);
  
private:
  const HTMLAttributeList *fAttributes;
};

// ============================================================
// Class HTMLSimpleElement
// ============================================================
/**
 * A simple HTMLElement with no state.  
 * HTMLSimpleElements may be embedded within each other.
 * @see HTMLElement
 */
class HTMLSimpleElement : public HTMLElement {
public:
  /**@name Constructors */
  //@{

  /** Constructor */
  HTMLSimpleElement();

  /**
   * Copy constructor.
   * @param element The HTMLSimpleElement to copy.
   * @exception Exception
   */
  HTMLSimpleElement(const HTMLSimpleElement& element) throw(Exception);

  /** Destructor */
  virtual ~HTMLSimpleElement();
  //@}

  /**@name Accessor Functions */
  //@{
  
  /**
   * Get the data contained in this element, if any.
   * For example, in the tag &lt;EM>foo&lt;/EM> the data is foo.
   * @return The data contained in this element, or NULL if none.
   */
  inline const char* getData() const { return fData; }
  
  /**
   * Get the HTMLSimpleElement embedded in this element, if any.
   * @return The embedded element, or NULL if none.
   */
  inline const HTMLSimpleElement* getEmbedded() const { return fEmbedded; }
  //@}
  
  /**@name Mutator Functions */
  //@{
  
  /**
   * Set the data contained in this element.
   * @param data The data to store in this element.
   * @exception Exception
   */
  void setData(const char *data) throw (Exception);
  
  /**
   * Set the HTMLSimpleElement embedded in this one.
   * @param embedded The HTMLSimpleElement to embed; takes precedence over all
   * data.
   */
  inline void setEmbedded(const HTMLSimpleElement *embedded) 
  { fEmbedded = embedded; }
  //@}
  
  virtual void render(ostream& out) const;
  
protected:
  HTMLSimpleElement(const char *data, 
		    const HTMLAttributeList *attributes, 
		    const HTMLSimpleElement *embedded) throw(Exception);

private:
  const HTMLSimpleElement *fEmbedded;
  char *fData;
};

// ============================================================
// Class HTMLBooleanElement
// ============================================================
/**
 * An HTMLElement which maintains a boolean (on/off) state.
 * @see HTMLElement
 * @see HTMLSimpleElement
 */
class HTMLBooleanElement : public HTMLSimpleElement {
public:
  /**@name Constructors */
  //@{

  /** Default constructor. */
  HTMLBooleanElement();

  /**
   * Copy constructor.
   * @param element The HTMLBooleanElement to copy.
   * @exception Exception
   */
  HTMLBooleanElement(const HTMLBooleanElement& element) throw(Exception);

  /** Destructor */
  virtual ~HTMLBooleanElement();
  //@}
  
  /**@name State Functions */
  //@{
  /** Swap the state of the element */
  virtual void swapState() const = 0;
  
  /**
   * Get the state of the element.
   * @return True if the element is active, false if inactive.
   */
  virtual bool getState() const = 0;
  //@}
  
  virtual void render(ostream& out) const;
  
protected:
  HTMLBooleanElement(const char *data, 
		     const HTMLAttributeList *attributes,
		     const HTMLSimpleElement *embedded) throw(Exception);
};

#endif
