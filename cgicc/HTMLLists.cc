/*
 *  $Id: HTMLLists.cc,v 1.2 1999/06/04 00:07:40 sbooth Exp $
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

#include "cgicc/HTMLLists.hh"

// ============================================================
// Statics
// ============================================================
bool CGICCNS ul::sState = false;
bool CGICCNS ol::sState = false;
bool CGICCNS li::sState = false;
bool CGICCNS dl::sState = false;
bool CGICCNS dt::sState = false;
bool CGICCNS dd::sState = false;

// ============================================================
// Class ul
// ============================================================
CGICCNS ul::ul() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS ul::ul(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS ul::ul(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS ul::ul(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS ul::ul(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS ul::ul(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS ul::~ul()
{}

// ============================================================
// Class ol
// ============================================================
CGICCNS ol::ol() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS ol::ol(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS ol::ol(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS ol::ol(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS ol::ol(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS ol::ol(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS ol::~ol()
{}

// ============================================================
// Class li
// ============================================================
CGICCNS li::li() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS li::li(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS li::li(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS li::li(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS li::li(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS li::li(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS li::~li()
{}

// ============================================================
// Class dl
// ============================================================
CGICCNS dl::dl() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS dl::dl(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS dl::dl(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS dl::dl(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS dl::dl(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS dl::dl(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS dl::~dl()
{}

// ============================================================
// Class dt
// ============================================================
CGICCNS dt::dt() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS dt::dt(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS dt::dt(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS dt::dt(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS dt::dt(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS dt::dt(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS dt::~dt()
{}

// ============================================================
// Class dd
// ============================================================
CGICCNS dd::dd() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS dd::dd(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS dd::dd(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS dd::dd(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS dd::dd(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS dd::dd(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS dd::~dd()
{}
