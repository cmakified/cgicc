/*
 *  $Id: HTMLElements.hh,v 1.5 1998/12/09 00:48:57 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __HTML_ELEMENTS__
#define __HTML_ELEMENTS__ 1

#include "MStreamable.hh"
#include "LinkedList.hh"
#include "HTMLAttributes.hh"

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
