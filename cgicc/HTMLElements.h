/* -*-c++-*- */
/*
 *  $Id: HTMLElements.h,v 1.8 2001/09/03 16:18:46 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _HTMLELEMENTS_H_
#define _HTMLELEMENTS_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file HTMLElements.h
 * \brief Classes dealing with HTML elements
 * 
 * For example, \c a, \c img, \c html, and \c body, are all HTML elements.
 */

#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/MStreamable.h"
#include "cgicc/HTMLAttributes.h"

CGICC_BEGIN_NAMESPACE

class HTMLElementList;

// ============================================================
// Class HTMLElement
// ============================================================

/*! \class HTMLElement HTMLElements.h cgicc/HTMLElements.h
 * \brief Class representing an HTML element.
 *
 * An HTML element is any entity enclosed in angle brackets (\< and \>)
 * interpreted as HTML, for example \c A, \c IMG, \c HTML, and \c BODY.
 */
class CGICC_API HTMLElement : public MStreamable 
{
public:

  /*! 
   * \brief Possible types of HTMLElements 
   *
   * An HTMLElement is either atomic, meaning it has no corresponding
   * closing tag (elements such as \c HR and \c BR are atomic) or
   * boolean (elements such as \c A and \c OL are boolean)
   */
  enum EElementType {
    /*! Atomic element, such as \c HR */
    eAtomic,
    /*! Boolean element, such as \c STRONG */
    eBoolean
  };
  
  // ============================================================

  /*! \name Constructors and Destructor */
  //@{

  /*!
   * \brief Copy constructor.
   *
   * Sets the name and internal state of this element to those of \c element
   * \param element The HTMLElement to copy.
   */
  HTMLElement(const HTMLElement& element);

  /*!
   * \brief Destructor 
   *
   * Delete this HTMLElement object
   */
  virtual ~HTMLElement();
  //@}

  // ============================================================

  /*! \name Overloaded Operators */
  //@{

  /*!
   * \brief Compare two HTMLElements for equality.
   *
   * HTMLElements are equal if they have the same name
   * \param element The HTMLElement to compare to this one.
   * \return \c true if the two HTMLElements are equal, \cfalse otherwise.
   */
  bool 
  operator== (const HTMLElement& element) 		const;

  /*!
   * \brief Compare two HTMLElements for inequality.
   *
   * HTMLElements are equal if they have the same name
   * \param element The HTMLElement to compare to this one.
   * \return \c false if the two HTMLElements are equal, \c true otherwise.
   */
  inline bool 
  operator!= (const HTMLElement& element) 		const
    { return ! operator==(element); }

#ifdef WIN32
  /* Dummy operator for MSVC++ */
  inline bool
  operator< (const HTMLElement& element)		const
  { return false; }
#endif

  /*!
   * \brief Assignment operator 
   *
   * Sets the name and internal state of this element to those of \c element
   * \param element The HTMLElement to copy
   * \return A reference to \c this
   */
  HTMLElement&
  operator= (const HTMLElement& element);
  //@}

  // ============================================================
  
  /*! \name Accessor Methods 
   * Information on the element
   */
  //@{

  /*!
   * \brief Get the name of this element.
   *
   * For example, \c HTML or \c BODY.
   * \return The name of this element.
   */
  virtual const char*
  getName() 					const = 0;

  /*!
   * \brief Get the data contained in this element, if any.
   *
   * This is only applicable for boolean elements
   * \return The data contained in this element.
   */
  inline STDNS string
  getData()  					const
  { return fData; }

  /*!
   * \brief Get the type of this element 
   *
   * Most HTMLElements are boolean
   * \return The type of this element
   */
  inline EElementType
  getType() 					const
  { return fType; }
  //@}

  // ============================================================

  /*! \name Mutator Methods 
   * Set properties of the element
   */
  //@{

  /*!
   * \brief Set the data contained in this element.
   *
   * The data is the text contained between the opening and closing tags
   * \param data The data to store in this element.
   */
  inline void
  setData(const STDNS string& data)
  { fData = data; }
  //@}

  // ============================================================

  /*!
   * \brief Clone this HTMLElement 
   *
   * This performs a deep copy of the element
   * \return A pointer to a newly-allocated copy of \c this.
   */
  virtual HTMLElement*
  clone() 					const = 0;

  // ============================================================

  /*! \name Embedded HTMLElement Management 
   * Manage elements embedded in this one
   */
  //@{

  /*!
   * \brief Get the HTMLElementList embedded in this element, if any.
   *
   * If this method returns 0, no elements are embedded
   * \return The embedded element list.
   */
  inline const HTMLElementList*
  getEmbedded() 				const
  { return fEmbedded; }

  /*!
   * \brief Set the HTMLElementList associated with this element.
   *
   * This is usually called by subclass constructors
   * \param elements The HTMLElementList containing the HTMLElements
   * embedded in this element.
   */
  void 
  setEmbedded(const HTMLElementList& embedded);

  /*!
   * \brief Add an embedded HTMLElement in this one 
   *
   * 
   * \param A reference to an HTMLElement to embed in this one
   * \return A reference to \c this
   */
  HTMLElement&
  add(const HTMLElement& element);

  /*!
   * \brief Add an embedded HTMLElement in this one 
   *
   * This element takes ownership of \c element, which should not be deleted.
   * \param A pointer to an HTMLElement to embed.
   * \return A reference to \c this
   */
  HTMLElement&
  add(HTMLElement *element);
  //@}
  
  // ============================================================

  /*! \name HTMLAttribute Management 
   * Manage attributes embedded in this element
   */
  //@{

  /*!
   * \brief Get the attributes associated with this element.
   *
   * If this method returns 0, no attributes are embedded
   * \return The attribute list.
   */
  inline const HTMLAttributeList*
  getAttributes() 				const
  { return fAttributes; }

  /*!
   * \brief Set the attributes associated with this element.
   *
   * This is usually called by subclass constructors
   * \param attributes The HTMLAttributeList containing the HTMLAttributes 
   * belonging to this element.
   */
  void 
  setAttributes(const HTMLAttributeList& attributes);

  /*!
   * \brief Set an HTMLAttribute on this HTMLElement 
   *
   * 
   * \param name The name of the HTMLAttribute to set
   * \return A reference to \c this
   */
  HTMLElement&
  set(const STDNS string& name);

  /*!
   * \brief Set an HTMLAttribute on this HTMLElement 
   *
   *
   * \param name The name of the HTMLAttribute
   * \param value The value of the HTMLAttribute
   * \return A reference to \c this
   */
  HTMLElement&
  set(const STDNS string& name,
      const STDNS string& value);
  //@}
  
  // ============================================================

  /*! \name Boolean element methods 
   * Methods specific to boolean elements
   */
  //@{

  /*! 
   * \brief Swap the state of the boolean element 
   *
   * A state of \c true means the element is active
   */
  virtual void 
  swapState() 					const
  {}
  
  /*!
   * \brief Get the state of this boolean element 
   *
   * 
   * \return \c true if the element is active, \c false otherwise
   */
  virtual bool 
  getState() 					const
  { return false; }
  //@}

  /*!
   * \brief Render this HTMLElement to an ostream
   *
   * This is used for output
   * \param out The ostream to which to write
   */
  virtual void 
  render(STDNS ostream& out) 			const;
  
protected:

  /*!
   * \brief Subclass constructor
   *
   * This allows the subclasses to fully specify all properties
   * \param attributes A pointer to an HTMLAttributeList containing the
   * HTMLAttributes for this HTMLElement, if any
   * \param embedded A pointer to the embedded HTMLElement, if any
   * \param data A pointer to the data, if any
   * \param type The type of element
   */
  HTMLElement(const HTMLAttributeList *attributes,
              const HTMLElement *embedded,
              const STDNS string *data,
              EElementType type);

  /*!
   * \brief For subclasses only
   *
   * Returns \c true if data was specified in the constructor.
   * \return \c true if data was specified in the constructor, \false otherwise
   */
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

/*! \class HTMLElementList HTMLElements.h cgicc/HTMLElements.h
 * \brief An expandable list of HTMLElements
 *
 * An HTMLElementList represents any number of
 * HTMLElements.  To add HTMLElements to the list, use the add() methods:
 * \code
 * HTMLElementList list;
 * list.add(br());
 * \endcode
 * \see HTMLElement
 */
class CGICC_API HTMLElementList
{
public:
  
  // ============================================================

  /*! \name Constructors and Destructor */
  //@{

  /*!
   * \brief Create an empty HTMLElementList. 
   *
   * HTMLElementLists are most often created with the add() functions
   */
  HTMLElementList();

  /*!
   * \brief Create a new HTMLElementList, specifying the first element.
   *
   * The first element in the list is set to \c head
   * \param head The first element of the list
   */
  HTMLElementList(const HTMLElement& head);

  /*!
   * \brief Copy constructor.
   *
   * Sets the elements in this list to those of \c list
   * \param list The HTMLElementList to copy.
   */
  HTMLElementList(const HTMLElementList& list);

  /*!
   * \brief Destructor 
   *
   * Deletes this HTMLElementList object
   */
  ~HTMLElementList();
  //@}

  // ============================================================

  /*! \name Overloaded Operators */
  //@{

  /*!
   * \brief Assignment operator 
   *
   * Sets the elements in this list to those of \c list
   * \param list The HTMLElementList to copy
   * \return A reference to \c this
   */
  HTMLElementList&
  operator= (const HTMLElementList& list);
  //@}

  // ============================================================

  /*! \name List Management 
   * Manage the elements in the list
   */
  //@{

  /*!
   * \brief Add an HTMLElement to the list.
   *
   * \param element The HTMLElement to add.
   * \return A reference to \c this
   */
  HTMLElementList&
  add(const HTMLElement& element);

  /*!
   * Add an HTMLElement to the list.
   * \param element The HTMLElement to add.
   * \return A reference to the \c this
   */
  HTMLElementList&
  add(HTMLElement *element);
  //@}

  /*!
   * Render this HTMLElementList 
   * \param out The ostream to which to write
   */
  void 
  render(STDNS ostream& out) 				const;

private:
  STDNS vector<HTMLElement*> fElements;
  // elements must be stored as pointers, otherwise polymorphism does not work
};

CGICC_END_NAMESPACE

#endif /* ! _HTMLELEMENTS_H_ */
