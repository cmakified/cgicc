/*
 *  $Id: HTMLElement.cpp,v 1.4 2003/07/13 14:20:35 sbooth Exp $
 *
 *  Copyright (C) 1996 - 2003 Stephen F. Booth
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

#ifdef __GNUG__
#  pragma implementation
#endif

#include <new>

#include "cgicc/HTMLElement.h"
#include "cgicc/HTMLElementList.h"

// ============================================================
// Class HTMLElement
// ============================================================
cgicc::HTMLElement::HTMLElement(const HTMLElement& element)
  : MStreamable(),
    fAttributes(0),
    fEmbedded(0)
{
  this->operator= (element);
}

cgicc::HTMLElement::HTMLElement(const HTMLAttributeList *attributes,
				const HTMLElement *embedded,
				const std::string *data,
				EElementType type)
  : fAttributes(0),
    fEmbedded(0),
    fData(),
    fType(type),
    fDataSpecified(false)
{
  if(attributes != 0)
    fAttributes = new HTMLAttributeList(*attributes);

  if(embedded != 0)
    fEmbedded = new HTMLElementList(*embedded);

  if(data != 0) {
    fData = *data;
    fDataSpecified = true;
  }
}

cgicc::HTMLElement::~HTMLElement()
{
  delete fAttributes;
  delete fEmbedded;
}

bool
cgicc::HTMLElement::operator== (const HTMLElement& element) const
{
  // this is really lame, but only necessary for template instantiation
  return (strcmp(getName(), element.getName()) == 0
	  && fDataSpecified == element.fDataSpecified);
}

cgicc::HTMLElement&
cgicc::HTMLElement::operator= (const HTMLElement& element)
{
  // avoid memory leak; bug fix from Francois Degros
  delete fAttributes;
  delete fEmbedded;

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
cgicc::HTMLElement::setAttributes(const HTMLAttributeList& attributes)
{ 
  delete fAttributes;
  fAttributes = new HTMLAttributeList(attributes);
}

void
cgicc::HTMLElement::setEmbedded(const HTMLElementList& embedded)
{
  delete fEmbedded;
  fEmbedded = new HTMLElementList(embedded);
}

cgicc::HTMLElement&
cgicc::HTMLElement::add(const HTMLElement& element)
{
  if(fEmbedded == 0)
    fEmbedded = new HTMLElementList();
  fEmbedded->add(element);
  return *this;
}

cgicc::HTMLElement&
cgicc::HTMLElement::add(HTMLElement *element)
{
  if(fEmbedded == 0)
    fEmbedded = new HTMLElementList();
  fEmbedded->add(element);
  return *this;
}

cgicc::HTMLElement&
cgicc::HTMLElement::set(const std::string& name)
{
  if(fAttributes == 0)
    fAttributes = new HTMLAttributeList();
  fAttributes->set(name);
  return *this;
}

cgicc:: HTMLElement&
cgicc::HTMLElement::set(const std::string& name,
			 const std::string& value)
{
  if(fAttributes == 0)
    fAttributes = new HTMLAttributeList();
  fAttributes->set(name, value);
  return *this;
}

void
cgicc::HTMLElement::render(std::ostream& out) 	const
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
  /* For non-boolean elements */
  else {
    if(getType() == eAtomic) {
      out << '<' << getName();
      if(getAttributes() != 0) {
	out << ' ';
	getAttributes()->render(out);
      }
      out << " />";
    }
    else {
      out << '<' << getName();
      if(getAttributes() != 0) {
	out << ' ';
	getAttributes()->render(out);
      }
      out << '>';
      
      if(getEmbedded() != 0)
	getEmbedded()->render(out);
      else
	out << getData();
      out << "</" << getName() << '>';
    }
  }
}
