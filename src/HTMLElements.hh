/*
 *  $Id: HTMLElements.hh,v 1.8 1999/05/28 19:37:13 sbooth Exp $
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

#ifndef _HTMLELEMENTS_HH_
#define _HTMLELEMENTS_HH_ 1

#ifdef __GNUG__
#pragma interface
#endif

#include <string>

#include "CgiDefs.hh"
#include "MStreamable.hh"
#include "HTMLAttributes.hh"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class HTMLElement
// ============================================================
/** An abstract class representing an HTML tag. */
class HTMLElement : public MStreamable 
{
public:
  /**@name Constructors */
  //@{
  
  /** Constructor */
  HTMLElement();

  /**
   * Copy constructor.
   * @param element The HTMLElement to copy.
   */
  HTMLElement(const HTMLElement& element);

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
  virtual STDNS string   
  getName() 					const = 0;
  
  /**
   * Get the attributes associated with this element.
   * @return An HTMLAttributeList containing all the HTMLAttributes belonging 
   * to this element.
   */
  inline const HTMLAttributeList* 
  getAttributes() 				const
    { return fAttributes; }
  //@}
  
  /**@name Mutator Functions */
  //@{
  /**
   * Set the attributes associated with this element.
   * @param attributes The HTMLAttributeList containing the HTMLAttributes 
   * belonging to this element.
   */
  inline void 
  setAttributes(const HTMLAttributeList *attributes)
    { fAttributes = attributes; }
  //@}
  
  virtual void 
  render(STDNS ostream& out) 			const;
  
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
class HTMLSimpleElement : public HTMLElement 
{
public:
  /**@name Constructors */
  //@{

  /** Constructor */
  HTMLSimpleElement();

  /**
   * Copy constructor.
   * @param element The HTMLSimpleElement to copy.
   */
  HTMLSimpleElement(const HTMLSimpleElement& element);

  /** Destructor */
  virtual ~HTMLSimpleElement();
  //@}

  /**@name Accessor Functions */
  //@{
  
  /**
   * Get the data contained in this element, if any.
   * For example, in the tag &lt;EM>foo&lt;/EM> the data is foo.
   * @return The data contained in this element.
   */
  inline STDNS string 
  getData()  					const
    { return fData; }
  
  /**
   * Get the HTMLSimpleElement embedded in this element, if any.
   * @return The embedded element, or 0 if none.
   */
  inline const HTMLSimpleElement* 
  getEmbedded() 				const
    { return fEmbedded; }
  //@}
  
  /**@name Mutator Functions */
  //@{
  
  /**
   * Set the data contained in this element.
   * @param data The data to store in this element.
   */
  inline void 
  setData(const STDNS string& data)
    { fData = data; }
  
  /**
   * Set the HTMLSimpleElement embedded in this one.
   * @param embedded The HTMLSimpleElement to embed; takes precedence over all
   * data.
   */
  inline void 
  setEmbedded(const HTMLSimpleElement *embedded)
    { fEmbedded = embedded; }
  //@}
  
  virtual void 
  render(STDNS ostream& out) 			const;
  
protected:
  HTMLSimpleElement(const STDNS string& data, 
		    const HTMLAttributeList *attributes, 
		    const HTMLSimpleElement *embedded);


private:
  const HTMLSimpleElement 	*fEmbedded;
  STDNS string 			fData;
};

// ============================================================
// Class HTMLBooleanElement
// ============================================================
/**
 * An HTMLElement which maintains a boolean (on/off) state.
 * @see HTMLElement
 * @see HTMLSimpleElement
 */
class HTMLBooleanElement : public HTMLSimpleElement 
{
public:
  /**@name Constructors */
  //@{

  /** Default constructor. */
  HTMLBooleanElement();

  /**
   * Copy constructor.
   * @param element The HTMLBooleanElement to copy.
   */
  HTMLBooleanElement(const HTMLBooleanElement& element);

  /** Destructor */
  virtual ~HTMLBooleanElement();
  //@}
  
  /**@name State Functions */
  //@{
  /** Swap the state of the element */
  virtual void 
  swapState() 					const = 0;
  
  /**
   * Get the state of the element.
   * @return True if the element is active, false if inactive.
   */
  virtual bool 
  getState() 					const = 0;
  //@}
  
  virtual void 
  render(STDNS ostream& out) 			const;
  
protected:
  HTMLBooleanElement(const STDNS string& data, 
		     const HTMLAttributeList *attributes,
		     const HTMLSimpleElement *embedded,
		     bool dataSpecified);
  inline bool
  dataSpecified() 				const
    { return fDataSpecified; }

private:
  bool fDataSpecified;

};

CGICC_END_NAMESPACE

#endif /* ! _HTMLELEMENTS_HH_ */
