/*
 *  $Id: HTMLTables.cc,v 1.5 1999/04/26 22:42:32 sbooth Exp $
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

#include "HTMLTables.hh"

// ============================================================
// Statics
// ============================================================
bool CGICCNS table::sState 	= false;
bool CGICCNS caption::sState 	= false;
bool CGICCNS thead::sState 	= false;
bool CGICCNS tfoot::sState 	= false;
bool CGICCNS tbody::sState 	= false;
bool CGICCNS colgroup::sState 	= false;
bool CGICCNS tr::sState 	= false;
bool CGICCNS th::sState 	= false;
bool CGICCNS td::sState 	= false;

// ============================================================
// Class table
// ============================================================
CGICCNS table::table() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS table::table(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS table::table(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS table::table(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS table::table(const STDNS string& text, 
		    const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS table::table(const HTMLAttributeList& attributes, 
		    const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS table::~table()
{}

// ============================================================
// Class caption
// ============================================================
CGICCNS caption::caption() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS caption::caption(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS caption::caption(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS caption::caption(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS caption::caption(const STDNS string& text, 
			const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS caption::caption(const HTMLAttributeList& attributes, 
			const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS caption::~caption()
{}

// ============================================================
// Class thead
// ============================================================
CGICCNS thead::thead() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS thead::thead(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS thead::thead(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS thead::thead(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS thead::thead(const STDNS string& text, 
		    const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS thead::thead(const HTMLAttributeList& attributes, 
		    const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS thead::~thead()
{}

// ============================================================
// Class tfoot
// ============================================================
CGICCNS tfoot::tfoot() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS tfoot::tfoot(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS tfoot::tfoot(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS tfoot::tfoot(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS tfoot::tfoot(const STDNS string& text, 
		    const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS tfoot::tfoot(const HTMLAttributeList& attributes, 
		    const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS tfoot::~tfoot()
{}

// ============================================================
// Class tbody
// ============================================================
CGICCNS tbody::tbody() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS tbody::tbody(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS tbody::tbody(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS tbody::tbody(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS tbody::tbody(const STDNS string& text, 
		    const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS tbody::tbody(const HTMLAttributeList& attributes, 
		    const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS tbody::~tbody()
{}

// ============================================================
// Class colgroup
// ============================================================
CGICCNS colgroup::colgroup() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS colgroup::colgroup(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS colgroup::colgroup(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS colgroup::colgroup(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS colgroup::colgroup(const STDNS string& text, 
			  const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS colgroup::colgroup(const HTMLAttributeList& attributes, 
			  const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS colgroup::~colgroup()
{}

// ============================================================
// Class col
// ============================================================
CGICCNS col::col() 
{}

CGICCNS col::col(const HTMLAttributeList& attributes)
  : HTMLElement(&attributes)
{}

CGICCNS col::~col()
{}

// ============================================================
// Class tr
// ============================================================
CGICCNS tr::tr() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS tr::tr(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS tr::tr(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS tr::tr(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS tr::tr(const STDNS string& text, 
	      const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS tr::tr(const HTMLAttributeList& attributes, 
	      const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS tr::~tr()
{}

// ============================================================
// Class th
// ============================================================
CGICCNS th::th() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS th::th(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS th::th(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS th::th(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS th::th(const STDNS string& text, 
	      const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS th::th(const HTMLAttributeList& attributes, 
	      const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS th::~th()
{}

// ============================================================
// Class td
// ============================================================
CGICCNS td::td() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS td::td(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS td::td(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS td::td(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS td::td(const STDNS string& text, 
	      const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS td::td(const HTMLAttributeList& attributes, 
	      const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS td::~td()
{}
