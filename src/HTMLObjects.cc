/*
 *  $Id: HTMLObjects.cc,v 1.5 1999/04/26 22:42:31 sbooth Exp $
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

#include "HTMLObjects.hh"

// ============================================================
// Statics
// ============================================================
bool CGICCNS object::sState 	= false;
bool CGICCNS map::sState 	= false;

// ============================================================
// Class img
// ============================================================
CGICCNS img::img() 
{}

CGICCNS img::img(const HTMLAttributeList& attributes)
  : HTMLElement(&attributes)
{}

CGICCNS img::~img()
{}

// ============================================================
// Class object
// ============================================================
CGICCNS object::object() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS object::object(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS object::object(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS object::object(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS object::object(const STDNS string& text, 
		      const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS object::object(const HTMLAttributeList& attributes, 
		      const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS object::~object()
{}

// ============================================================
// Class param
// ============================================================
CGICCNS param::param() 
{}

CGICCNS param::param(const HTMLAttributeList& attributes)
  : HTMLElement(&attributes)
{}

CGICCNS param::~param()
{}

// ============================================================
// Class map
// ============================================================
CGICCNS map::map() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS map::map(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS map::map(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS map::map(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS map::map(const STDNS string& text, 
		const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS map::map(const HTMLAttributeList& attributes, 
		const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS map::~map()
{}

// ============================================================
// Class area
// ============================================================
CGICCNS area::area() 
{}

CGICCNS area::area(const HTMLAttributeList& attributes)
  : HTMLElement(&attributes)
{}

CGICCNS area::~area()
{}
