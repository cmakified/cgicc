/* -*-c++-*- */
/*
 *  $Id: HTMLElements.h,v 1.6 2000/07/03 02:54:03 sbooth Exp $
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

#ifndef _HTMLELEMENTS_H_
#define _HTMLELEMENTS_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/MStreamable.h"
#include "cgicc/HTMLAttributes.h"

CGICC_BEGIN_NAMESPACE

class HTMLElementList;

// ============================================================
// Class HTMLElement
// ============================================================
/** Class representing an HTML element. */
class CGICC_API HTMLElement : public MStreamable 
{
public:

  /** Possible types of HTMLElements */
  enum EElementType {
    /** Atomic element, such as HR */
    eAtomic,
    /** Boolean element, such as STRONG */
    eBoolean
  };
  

  /**
   * Copy constructor.
   * @param element The HTMLElement to copy.
   */
  HTMLElement(const HTMLElement& element);

  /** Destructor */
  virtual ~HTMLElement();


  /**
   * Compare two HTMLElements for equality.
   * @param element The HTMLElement to compare to this one.
   * @return true if the two HTMLElements are equal, false otherwise.
   */
  bool 
  operator== (const HTMLElement& element) 		const;

  /**
   * Compare two HTMLElements for inequality.
   * @param element The HTMLElement to compare to this one.
   * @return false if the two HTMLElements are equal, true otherwise.
   */
  inline bool 
  operator!= (const HTMLElement& element) 		const
    { return ! operator==(element); }

#ifdef WIN32
  /** Dummy operator for MSVC++ */
  inline bool
  operator< (const HTMLElement& element)		const
  { return false; }
#endif

  /** Assignment operator */
  HTMLElement&
  operator= (const HTMLElement& element);
  

  /**
   * Get the name of this element.
   * For example, HTML or BODY.
   * @return The name of this element.
   */
  virtual const char*
  getName() 					const = 0;

  
  /**
   * Get the attributes associated with this element.
   * @return The attribute list.
   */
  inline const HTMLAttributeList*
  getAttributes() 				const
  { return fAttributes; }

  /**
   * Get the data contained in this element, if any.
   * @return The data contained in this element.
   */
  inline STDNS string
  getData()  					const
  { return fData; }

  /**
   * Get the HTMLElementList embedded in this element, if any.
   * @return The embedded element list.
   */
  inline const HTMLElementList*
  getEmbedded() 				const
  { return fEmbedded; }


  /**
   * Set the data contained in this element.
   * @param data The data to store in this element.
   */
  inline void
  setData(const STDNS string& data)
  { fData = data; }

  /**
   * Set the attributes associated with this element.
   * @param attributes The HTMLAttributeList containing the HTMLAttributes 
   * belonging to this element.
   */
  void 
  setAttributes(const HTMLAttributeList& attributes);

  /**
   * Set the HTMLElementList associated with this element.
   * @param elements The HTMLElementList containing the HTMLElements
   * embedded in this element.
   */
  void 
  setEmbedded(const HTMLElementList& embedded);


  /** Get the type of this element */
  inline EElementType
  getType() 					const
  { return fType; }


  /** Clone this HTMLElement */
  virtual HTMLElement*
  clone() 					const = 0;


  /** Add an embedded HTMLElement in this one */
  HTMLElement&
  add(const HTMLElement& element);

  /** Add an embedded HTMLElement in this one */
  HTMLElement&
  add(HTMLElement *element);


  /** Set an HTMLAttribute on this HTMLElement */
  HTMLElement&
  set(const STDNS string& name);

  /** Set an HTMLAttribute on this HTMLElement */
  HTMLElement&
  set(const STDNS string& name,
      const STDNS string& value);


  /** Boolean element methods - for subclasses to override */

  /** Swap the state of this boolean element */
  virtual void 
  swapState() 					const
  {}
  
  /** Get the state of this boolean element */
  virtual bool 
  getState() 					const
  { return false; }


  /** Render this HTMLElement */
  virtual void 
  render(STDNS ostream& out) 			const;
  
protected:

  /** Subclass ctor */
  HTMLElement(const HTMLAttributeList *attributes,
              const HTMLElement *embedded,
              const STDNS string *data,
              EElementType type);

  /** For subclasses only - true if data was specified in ctor */
  inline bool
  dataSpecified() 				const
  { return fDataSpecified; }

private:
  HTMLElement() {}

  HTMLAttributeList *fAttributes;
  HTMLElementList   *fEmbedded;
  STDNS string      fData;
  EElementType      fType;
  bool              fDataSpecified;
};


// ============================================================
// Class HTMLElementList
// ============================================================

#ifdef WIN32
  template class CGICC_API STDNS vector<HTMLElement*>;
#endif

/**
 * An HTMLElementList represents any number of
 * HTMLSimpleElements embedded in an HTMLSimpleElement.
 * @see HTMLSimpleElement
 */
class CGICC_API HTMLElementList
{
public:

  /** Create an empty HTMLElementList. */
  HTMLElementList();

  /**
   * Create a new HTMLElementList, specifying the first element.
   * @param head The first element of the list
   */
  HTMLElementList(const HTMLElement& head);

  /**
   * Copy constructor.
   * @param list The HTMLElementList to copy.
   */
  HTMLElementList(const HTMLElementList& list);

  /** Destructor */
  ~HTMLElementList();


  /** Assignment operator */
  HTMLElementList&
  operator= (const HTMLElementList& list);
  
  /** 
   * Add an HTMLElement to the list.
   * @param element The HTMLElement to add.
   * @return A reference to the list.
   */
  HTMLElementList&
  add(const HTMLElement& element);

  /** 
   * Add an HTMLElement to the list.
   * @param element The HTMLElement to add.
   * @return A reference to the list.
   */
  HTMLElementList&
  add(HTMLElement *element);


  /** Render this HTMLElementList */
  void 
  render(STDNS ostream& out) 				const;

private:
  STDNS vector<HTMLElement*> fElements;
  // elements must be stored as pointers, otherwise polymorphism does not work
};

CGICC_END_NAMESPACE

#endif /* ! _HTMLELEMENTS_H_ */
