/*
 *  $Id: HTMLAttributes.cc,v 1.6 1999/04/26 22:42:28 sbooth Exp $
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

#include "HTMLAttributes.hh"
#include "CgiUtils.hh"

// ============================================================
// Class HTMLAttribute
// ============================================================
CGICCNS HTMLAttribute::HTMLAttribute()
{}

CGICCNS HTMLAttribute::HTMLAttribute(const STDNS string& name, 
				     const STDNS string& value)
  : fName(name), 
    fValue(value)
{}

CGICCNS HTMLAttribute::HTMLAttribute(const HTMLAttribute& attribute)
  : fName(attribute.fName), 
    fValue(attribute.fValue)
{}

CGICCNS HTMLAttribute::~HTMLAttribute()
{}

bool
CGICCNS HTMLAttribute::operator== (const HTMLAttribute& att) 	const
{
  return (stringsAreEqual(fName, att.fName) 
	  && stringsAreEqual(fValue, att.fValue));
}

CGICCNS HTMLAttribute& 
CGICCNS HTMLAttribute::operator= (const HTMLAttribute& att) 
{
  fName 	= att.fName;
  fValue 	= att.fValue;

  return *this;
}

void 
CGICCNS HTMLAttribute::render(STDNS ostream& out) 		const
{
  out << getName() << "=\"" << getValue() << "\"";
}

// ============================================================
// Class HTMLAtomicAttribute
// ============================================================
CGICCNS HTMLAtomicAttribute::HTMLAtomicAttribute()
{}

CGICCNS HTMLAtomicAttribute::HTMLAtomicAttribute(const STDNS string& name) 
  : HTMLAttribute(name, "")
{}

CGICCNS HTMLAtomicAttribute::HTMLAtomicAttribute(const HTMLAtomicAttribute& attribute)
  : HTMLAttribute(attribute)
{}

CGICCNS HTMLAtomicAttribute::~HTMLAtomicAttribute()
{}

void 
CGICCNS HTMLAtomicAttribute::render(STDNS ostream& out) 	const
{
  out << getName();
}

// ============================================================
// Class HTMLAttributeList
// ============================================================
CGICCNS HTMLAttributeList::HTMLAttributeList()
{
  fAttributes.reserve(5);
}

CGICCNS HTMLAttributeList::HTMLAttributeList(const HTMLAttribute& head) 
{
  fAttributes.reserve(5);
  fAttributes.push_back(head);
}

CGICCNS HTMLAttributeList::HTMLAttributeList(const HTMLAttributeList& list)
  : fAttributes(list.fAttributes)
{}

CGICCNS HTMLAttributeList::~HTMLAttributeList()
{}

CGICCNS HTMLAttributeList&
CGICCNS HTMLAttributeList::add(const STDNS string& name)
{ 
  fAttributes.push_back(HTMLAtomicAttribute(name));
  return *this;
}

CGICCNS HTMLAttributeList&
CGICCNS HTMLAttributeList::add(const STDNS string& name, 
			       const STDNS string& value)
{ 
  fAttributes.push_back(HTMLAttribute(name, value));
  return *this;
}

void 
CGICCNS HTMLAttributeList::render(STDNS ostream& out) 	const
{
  STDNS vector<HTMLAttribute>::const_iterator iter;
  for(iter = fAttributes.begin(); iter != fAttributes.end(); ++iter) {
    out << *iter << ' ';
  }
}
