/*
 * $Id: HTMLElements.cc,v 1.4 1998/12/08 23:14:33 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
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

#include "HTMLElements.hh"

// ============================================================
// Class HTMLElement
// ============================================================
HTMLElement::HTMLElement()
  : fAttributes(NULL)
{}

HTMLElement::HTMLElement(const HTMLElement& element) throw(Exception)
  : fAttributes(NULL)
{
  if(element.getAttributes() != NULL)
    setAttributes(element.getAttributes());
}

HTMLElement::HTMLElement(const HTMLAttributeList *attributes) {
  setAttributes(attributes);
}

HTMLElement::~HTMLElement()
{}

void
HTMLElement::render(ostream& out) const {
  out << '<' << getName();
  if(getAttributes() != NULL) {
    out << ' ';
    getAttributes()->render(out);
  }
  out << '>';
}

// ============================================================
// Class HTMLSimpleElement
// ============================================================
HTMLSimpleElement::HTMLSimpleElement()
  : fData(NULL)
{}

HTMLSimpleElement::HTMLSimpleElement(const HTMLSimpleElement& element)
  throw(Exception)
  : HTMLElement(element), fEmbedded(NULL), fData(NULL)
{
  if(element.getEmbedded() != NULL)
    setEmbedded(element.getEmbedded());

  if(element.getData() != NULL)
    setData(element.getData());
}

HTMLSimpleElement::HTMLSimpleElement(const char *data, 
				     const HTMLAttributeList *attributes,
				     const HTMLSimpleElement *embedded) 
  throw(Exception)
    : HTMLElement(attributes), fEmbedded(embedded), fData(NULL)
{
  if(data != NULL)
    setData(data);
  else
    fData = NULL;
}

HTMLSimpleElement::~HTMLSimpleElement()
{
  delete [] fData;
}

void
HTMLSimpleElement::setData(const char *data) throw (Exception) {
  delete [] fData;
  fData = new char [ strlen(data) + 1 ];
  if(fData == NULL)
    throw Exception("new failed", ERRINFO);
  strcpy(fData, data);
}

void
HTMLSimpleElement::render(ostream& out) const {
  out << '<';
  out << getName();
  if(getAttributes() != NULL) {
    out << ' ';
    getAttributes()->render(out);
  }
  out << '>';
  if(getEmbedded() == NULL)
    out << getData();
  else
    getEmbedded()->render(out);
  out << "</" << getName() << '>';
}

// ============================================================
// Class HTMLBooleanElement
// ============================================================
HTMLBooleanElement::HTMLBooleanElement()
{}

HTMLBooleanElement::HTMLBooleanElement(const HTMLBooleanElement& element)
  throw(Exception)
  : HTMLSimpleElement(element)
{}

HTMLBooleanElement::HTMLBooleanElement(const char *data, 
				       const HTMLAttributeList *attributes,
				       const HTMLSimpleElement *embedded)
  throw(Exception)
    : HTMLSimpleElement(data, attributes, embedded)
{}

HTMLBooleanElement::~HTMLBooleanElement()
{}

void
HTMLBooleanElement::render(ostream& out) const {
  if(getData() == NULL) {
    if(getEmbedded() == NULL) {
      swapState();
      out << '<';
      if(getState()) {
	out << getName();
	if(getAttributes() != NULL) {
	  out << ' ';
	  getAttributes()->render(out);
	}
	out << '>';
      }
      else
	out << '/' << getName() << '>';
    }
    else {
      out << '<' << getName();
      if(getAttributes() != NULL) {
	out << ' ';
	getAttributes()->render(out);
      }
      out << '>';
      getEmbedded()->render(out);
      out << "</" << getName() << '>';		
    }
  }
  else
    HTMLSimpleElement::render(out);
}
