/*
 *  $Id: HTMLElements.cc,v 1.7 1999/05/25 19:16:45 sbooth Exp $
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

#ifdef __GNUG__
#pragma implementation
#endif

#include "HTMLElements.hh"

// ============================================================
// Class HTMLElement
// ============================================================
CGICCNS HTMLElement::HTMLElement()
  : fAttributes(0)
{}

CGICCNS HTMLElement::HTMLElement(const HTMLElement& element)
  : fAttributes(element.fAttributes)
{}

CGICCNS HTMLElement::HTMLElement(const HTMLAttributeList *attributes)
  : fAttributes(attributes)
{}

CGICCNS HTMLElement::~HTMLElement()
{}

void
CGICCNS HTMLElement::render(STDNS ostream& out) 	const
{
  out << '<' << getName();
  if(getAttributes() != 0) {
    out << ' ';
    getAttributes()->render(out);
  }
  out << '>';
}

// ============================================================
// Class HTMLSimpleElement
// ============================================================
CGICCNS HTMLSimpleElement::HTMLSimpleElement()
{}

CGICCNS HTMLSimpleElement::HTMLSimpleElement(const HTMLSimpleElement& element)
  : HTMLElement(element), 
    fEmbedded(element.fEmbedded),
    fData(element.fData)
{}

CGICCNS HTMLSimpleElement::HTMLSimpleElement(const STDNS string& data, 
					     const HTMLAttributeList *attributes,
					     const HTMLSimpleElement *embedded)
  : HTMLElement(attributes), 
    fEmbedded(embedded), 
    fData(data)
{}

CGICCNS HTMLSimpleElement::~HTMLSimpleElement()
{}

void
CGICCNS HTMLSimpleElement::render(STDNS ostream& out)  	const
{
  out << '<';
  out << getName();
  if(getAttributes() != 0) {
    out << ' ';
    getAttributes()->render(out);
  }
  out << '>';
  if(getEmbedded() == 0)
    out << getData();
  else
    getEmbedded()->render(out);
  out << "</" << getName() << '>';
}

// ============================================================
// Class HTMLBooleanElement
// ============================================================
CGICCNS HTMLBooleanElement::HTMLBooleanElement()
{}

CGICCNS HTMLBooleanElement::HTMLBooleanElement(const HTMLBooleanElement& element)
  : HTMLSimpleElement(element)
{}

CGICCNS HTMLBooleanElement::HTMLBooleanElement(const STDNS string& data, 
					       const HTMLAttributeList *attributes,
					       const HTMLSimpleElement *embedded,
					       bool dataSpecified)
    : HTMLSimpleElement(data, attributes, embedded),
      fDataSpecified(dataSpecified)
{}

CGICCNS HTMLBooleanElement::~HTMLBooleanElement()
{}

void
CGICCNS HTMLBooleanElement::render(STDNS ostream& out) 	const
{
  if(getData().empty() && ! dataSpecified()) {
    if(getEmbedded() == 0) {
      swapState();
      out << '<';
      if(getState()) {
	out << getName();
	if(getAttributes() != 0) {
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
      if(getAttributes() != 0) {
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

//EOF
