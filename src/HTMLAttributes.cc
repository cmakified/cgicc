/*
 * $Id: HTMLAttributes.cc,v 1.4 1998/12/08 23:14:33 sbooth Exp $
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

#include "HTMLAttributes.hh"

// ============================================================
// Class HTMLAttribute
// ============================================================
HTMLAttribute::HTMLAttribute() 
  : fName(NULL), fValue(NULL)
{}

HTMLAttribute::HTMLAttribute(const char *name, 
			     const char *value) throw(Exception)
			       : fName(NULL), fValue(NULL)
{
  if(name != NULL)
    setName(name);
  if(value != NULL)
    setValue(value);
}

HTMLAttribute::HTMLAttribute(const HTMLAttribute& attribute)
  : fName(NULL), fValue(NULL)
{
  if(attribute.getName() != NULL)
    setName(attribute.getName());
  if(attribute.getValue() != NULL)
    setValue(attribute.getValue());
}

HTMLAttribute::~HTMLAttribute() {
  delete [] fName;
  delete [] fValue;
}

void
HTMLAttribute::setName(const char *name) throw (Exception) {
  delete [] fName;
  fName = new char [ strlen(name) + 1];
  if(fName == NULL)
    throw Exception("new failed", ERRINFO);
  strcpy(fName, name);
}

void
HTMLAttribute::setValue(const char *value) throw (Exception) {
  delete [] fValue;
  fValue = new char [ strlen(value) + 1];
  if(fValue == NULL)
    throw Exception("new failed", ERRINFO);  
  strcpy(fValue, value);
}

void 
HTMLAttribute::render(ostream& out) const {
  out << getName() << "=\"" << getValue() << "\"";
}

// ============================================================
// Class HTMLAtomicAttribute
// ============================================================
HTMLAtomicAttribute::HTMLAtomicAttribute()
{}

HTMLAtomicAttribute::HTMLAtomicAttribute(const char *name) throw(Exception)
  : HTMLAttribute(name, NULL)
{}

HTMLAtomicAttribute::HTMLAtomicAttribute(const HTMLAtomicAttribute& attribute)
  : HTMLAttribute(attribute)
{}

HTMLAtomicAttribute::~HTMLAtomicAttribute()
{}

void 
HTMLAtomicAttribute::render(ostream& out) const {
  out << getName();
}

// ============================================================
// Class HTMLAttributeList
// ============================================================
HTMLAttributeList::HTMLAttributeList() 
{}

HTMLAttributeList::HTMLAttributeList(const HTMLAttribute& head) {
  append(head);
}

HTMLAttributeList::HTMLAttributeList(const HTMLAttributeList& list)
  : LinkedList(list)
{}

HTMLAttributeList::~HTMLAttributeList()
{}

HTMLAttributeList&
HTMLAttributeList::add(const char *name, const char *value) throw(Exception) { 
  if(name != NULL && value != NULL)
    append(HTMLAttribute(name, value));
  else if(name != NULL && value == NULL)
    append(HTMLAtomicAttribute(name));
  return *this;
}

// ============================================================
// List manipulators
// ============================================================
HTMLAttributeList
add(const char *name, 
    const char *value) throw(Exception) 
{
  return HTMLAttributeList(HTMLAttribute(name, value));
}

