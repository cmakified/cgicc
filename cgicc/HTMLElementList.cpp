/*
 *  $Id: HTMLElementList.cpp,v 1.1 2001/09/03 22:06:39 sbooth Exp $
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

#ifdef __GNUG__
#  pragma implementation
#endif

#include <new>

#include "cgicc/HTMLElementList.h"


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
