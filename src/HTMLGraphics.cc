/*
 *  $Id: HTMLGraphics.cc,v 1.5 1999/04/26 22:42:30 sbooth Exp $
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

#include "HTMLGraphics.hh"

// ============================================================
// Statics
// ============================================================
bool CGICCNS tt::sState 	= false;
bool CGICCNS i::sState 		= false;
bool CGICCNS b::sState 		= false;
bool CGICCNS big::sState 	= false;
bool CGICCNS small::sState 	= false;

// ============================================================
// Class tt
// ============================================================
CGICCNS tt::tt() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS tt::tt(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS tt::tt(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS tt::tt(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS tt::tt(const STDNS string& text, 
	      const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS tt::tt(const HTMLAttributeList& attributes, 
	      const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS tt::~tt()
{}

// ============================================================
// Class i
// ============================================================
CGICCNS i::i() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS i::i(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS i::i(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS i::i(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS i::i(const STDNS string& text, 
	    const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS i::i(const HTMLAttributeList& attributes, 
	    const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS i::~i()
{}

// ============================================================
// Class b
// ============================================================
CGICCNS b::b() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS b::b(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS b::b(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS b::b(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS b::b(const STDNS string& text, 
	    const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS b::b(const HTMLAttributeList& attributes, 
	    const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS b::~b()
{}

// ============================================================
// Class big
// ============================================================
CGICCNS big::big() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS big::big(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS big::big(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS big::big(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS big::big(const STDNS string& text, 
		const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS big::big(const HTMLAttributeList& attributes, 
		const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS big::~big()
{}

// ============================================================
// Class small
// ============================================================
CGICCNS small::small() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS small::small(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS small::small(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS small::small(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS small::small(const STDNS string& text, 
		    const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS small::small(const HTMLAttributeList& attributes, 
		    const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS small::~small()
{}

// ============================================================
// Class hr
// ============================================================
CGICCNS hr::hr() 
{}

CGICCNS hr::hr(const HTMLAttributeList& attributes) 
  : HTMLElement(&attributes)
{}

CGICCNS hr::~hr()
{}
