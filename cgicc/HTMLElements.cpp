/*
 *  $Id: HTMLElements.cpp,v 1.5 2000/09/21 15:21:28 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999, 2000 Stephen F. Booth
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

#ifdef __GNUG__
#  pragma implementation
#endif

#include <new>

#include "cgicc/HTMLElements.h"

// ============================================================
// Class HTMLElement
// ============================================================
CGICCNS HTMLElement::HTMLElement(const HTMLElement& element)
  : MStreamable()
{
  this->operator= (element);
}

CGICCNS HTMLElement::HTMLElement(const HTMLAttributeList *attributes,
				 const HTMLElement *embedded,
				 const STDNS string *data,
				 EElementType type)
  : fAttributes(0),
    fEmbedded(0),
    fData(),
    fType(type),
    fDataSpecified(false)
{
  if(attributes != 0) {
    fAttributes = new HTMLAttributeList(*attributes);
  }

  if(embedded != 0)
    fEmbedded = new HTMLElementList(*embedded);

  if(data != 0) {
    fData = *data;
    fDataSpecified = true;
  }
}

CGICCNS HTMLElement::~HTMLElement()
{
  delete fAttributes;
  delete fEmbedded;
}

bool
CGICCNS HTMLElement::operator== (const HTMLElement& element) const
{
  // this is really lame, but only necessary for template instantiation
  return (strcmp(getName(), element.getName()) == 0
	  && fDataSpecified == element.fDataSpecified);
}

CGICCNS HTMLElement&
CGICCNS HTMLElement::operator= (const HTMLElement& element)
{
  fAttributes    = element.fAttributes;
  fEmbedded      = element.fEmbedded;
  fData          = element.fData;
  fType          = element.fType;
  fDataSpecified = element.fDataSpecified;

  // perform a deep copy
  if(fAttributes != 0)
    fAttributes = new HTMLAttributeList(*fAttributes);

  if(fEmbedded != 0)
    fEmbedded = new HTMLElementList(*fEmbedded);

  return *this;
}

void 
CGICCNS HTMLElement::setAttributes(const HTMLAttributeList& attributes)
{ 
  delete fAttributes;
  fAttributes = new HTMLAttributeList(attributes);
}

void
CGICCNS HTMLElement::setEmbedded(const HTMLElementList& embedded)
{
  delete fEmbedded;
  fEmbedded = new HTMLElementList(embedded);
}

CGICCNS HTMLElement&
CGICCNS HTMLElement::add(const HTMLElement& element)
{
  if(fEmbedded == 0)
    fEmbedded = new HTMLElementList();
  fEmbedded->add(element);
  return *this;
}

CGICCNS HTMLElement&
CGICCNS HTMLElement::add(HTMLElement *element)
{
  if(fEmbedded == 0)
    fEmbedded = new HTMLElementList();
  fEmbedded->add(element);
  return *this;
}

CGICCNS HTMLElement&
CGICCNS HTMLElement::set(const STDNS string& name)
{
  if(fAttributes == 0)
    fAttributes = new HTMLAttributeList();
  fAttributes->set(name);
  return *this;
}

CGICCNS  HTMLElement&
CGICCNS HTMLElement::set(const STDNS string& name,
			 const STDNS string& value)
{
  if(fAttributes == 0)
    fAttributes = new HTMLAttributeList();
  fAttributes->set(name, value);
  return *this;
}

void
CGICCNS HTMLElement::render(STDNS ostream& out) 	const
{
  if(getType() == eBoolean && dataSpecified() == false) {
    /* no embedded elements */
    if(getEmbedded() == 0) {
      swapState();
      /* getState() == true ===> element is active */
      if(getState() == true) {
	out << '<' << getName();
	/* render attributes, if present */
	if(getAttributes() != 0) {
	  out << ' ';
	  getAttributes()->render(out);
	}
	out << '>';
      }
      else
	out << "</" << getName() << '>';
    }
    /* embedded elements present */
    else {
      out << '<' << getName();
      /* render attributes, if present */
      if(getAttributes() != 0) {
	out << ' ';
	getAttributes()->render(out);
      }
      out << '>';
      getEmbedded()->render(out);
      out << "</" << getName() << '>';
    }
  }
  else {
    out << '<' << getName();
    if(getAttributes() != 0) {
      out << ' ';
      getAttributes()->render(out);
    }
    out << '>';
    
    if(getType() == eAtomic)
      return; 
    
    if(getEmbedded() != 0)
      getEmbedded()->render(out);
    else
      out << getData();
    out << "</" << getName() << '>';
  }
}


// ============================================================
// Class HTMLElementList
// ============================================================
CGICCNS HTMLElementList::HTMLElementList()
{
  fElements.reserve(5);
}

CGICCNS HTMLElementList::HTMLElementList(const HTMLElement& head) 
{
  fElements.reserve(5);
  fElements.push_back(head.clone());
}

CGICCNS HTMLElementList::HTMLElementList(const HTMLElementList& list)
{
  this->operator=(list);
}

CGICCNS HTMLElementList::~HTMLElementList()
{
  STDNS vector<HTMLElement*>::const_iterator iter;
  for(iter = fElements.begin(); iter != fElements.end(); ++iter)
    delete *iter;
}

CGICCNS HTMLElementList&
CGICCNS HTMLElementList::operator= (const HTMLElementList& list)
{
  fElements = list.fElements;
  
  STDNS vector<HTMLElement*>::iterator iter;
  for(iter = fElements.begin(); iter != fElements.end(); ++iter)
    *iter = (*iter)->clone();

  return *this;
}

CGICCNS HTMLElementList&
CGICCNS HTMLElementList::add(const HTMLElement& element)
{ 
  fElements.push_back(element.clone());
  return *this;
}

CGICCNS HTMLElementList&
CGICCNS HTMLElementList::add(HTMLElement *element)
{ 
  fElements.push_back(element);
  return *this;
}

void 
CGICCNS HTMLElementList::render(STDNS ostream& out) 	const
{
  STDNS vector<HTMLElement*>::const_iterator iter;
  for(iter = fElements.begin(); iter != fElements.end(); ++iter) {
    (*iter)->render(out);
  }
}
