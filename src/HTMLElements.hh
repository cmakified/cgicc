/* $Id: HTMLElements.hh,v 1.1 1998/04/01 20:49:02 sbooth Exp $ */

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
  HTMLElement();
  HTMLElement(const HTMLElement& element) throw(Exception);
  virtual ~HTMLElement();
  
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
  HTMLSimpleElement();
  HTMLSimpleElement(const HTMLSimpleElement& element) throw(Exception);
  virtual ~HTMLSimpleElement();
  
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
  HTMLBooleanElement();
  HTMLBooleanElement(const HTMLBooleanElement& element) throw(Exception);
  virtual ~HTMLBooleanElement();
  
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
