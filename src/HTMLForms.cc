/*
 *  $Id: HTMLForms.cc,v 1.6 1999/05/25 19:16:46 sbooth Exp $
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

#include "HTMLForms.hh"

// ============================================================
// Statics
// ============================================================
bool CGICCNS form::sState 	= false;
bool CGICCNS button::sState 	= false;
bool CGICCNS select::sState 	= false;
bool CGICCNS optgroup::sState 	= false;
bool CGICCNS option::sState 	= false;
bool CGICCNS textarea::sState 	= false;
bool CGICCNS label::sState 	= false;
bool CGICCNS fieldset::sState 	= false;
bool CGICCNS legend::sState 	= false;

// ============================================================
// Class form
// ============================================================
CGICCNS form::form()
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS form::form(const STDNS string& text)
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS form::form(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS form::form(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS form::form(const STDNS string& text, 
		   const HTMLAttributeList& attributes)
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS form::form(const HTMLAttributeList& attributes, 
		   const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS form::~form()
{}

// ============================================================
// Class input
// ============================================================
CGICCNS input::input()
{}

CGICCNS input::input(const HTMLAttributeList& attributes)
  : HTMLElement(&attributes)
{}

CGICCNS input::~input()
{}

// ============================================================
// Class button
// ============================================================
CGICCNS button::button()
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS button::button(const STDNS string& text)
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS button::button(const HTMLAttributeList& attributes) 
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS button::button(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS button::button(const STDNS string& text, 
		       const HTMLAttributeList& attributes)
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS button::button(const HTMLAttributeList& attributes, 
		       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS button::~button()
{}

// ============================================================
// Class select
// ============================================================
CGICCNS select::select()
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS select::select(const STDNS string& text)
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS select::select(const HTMLAttributeList& attributes) 
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS select::select(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS select::select(const STDNS string& text, 
		       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS select::select(const HTMLAttributeList& attributes, 
		       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS select::~select()
{}

// ============================================================
// Class optgroup
// ============================================================
CGICCNS optgroup::optgroup()
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS optgroup::optgroup(const STDNS string& text)
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS optgroup::optgroup(const HTMLAttributeList& attributes) 
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS optgroup::optgroup(const HTMLSimpleElement& embed) 
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS optgroup::optgroup(const STDNS string& text, 
			   const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS optgroup::optgroup(const HTMLAttributeList& attributes, 
			   const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}
       
CGICCNS optgroup::~optgroup()
{}

// ============================================================
// Class option
// ============================================================
CGICCNS option::option()
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS option::option(const STDNS string& text)
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS option::option(const HTMLAttributeList& attributes) 
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS option::option(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS option::option(const STDNS string& text, 
		       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS option::option(const HTMLAttributeList& attributes, 
		       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS option::~option()
{}

// ============================================================
// Class textarea
// ============================================================
CGICCNS textarea::textarea()
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS textarea::textarea(const STDNS string& text)
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS textarea::textarea(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS textarea::textarea(const HTMLSimpleElement& embed) 
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS textarea::textarea(const STDNS string& text, 
			   const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS textarea::textarea(const HTMLAttributeList& attributes, 
			   const HTMLSimpleElement& embed) 
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS textarea::~textarea()
{}

// ============================================================
// Class label
// ============================================================
CGICCNS label::label()
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS label::label(const STDNS string& text)
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS label::label(const HTMLAttributeList& attributes) 
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS label::label(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS label::label(const STDNS string& text, 
		     const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS label::label(const HTMLAttributeList& attributes, 
		     const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS label::~label()
{}

// ============================================================
// Class fieldset
// ============================================================
CGICCNS fieldset::fieldset()
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS fieldset::fieldset(const STDNS string& text)
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS fieldset::fieldset(const HTMLAttributeList& attributes) 
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS fieldset::fieldset(const HTMLSimpleElement& embed) 
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS fieldset::fieldset(const STDNS string& text, 
			   const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS fieldset::fieldset(const HTMLAttributeList& attributes, 
			   const HTMLSimpleElement& embed) 
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS fieldset::~fieldset()
{}

// ============================================================
// Class legend
// ============================================================
CGICCNS legend::legend()
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS legend::legend(const STDNS string& text)
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS legend::legend(const HTMLAttributeList& attributes) 
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS legend::legend(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS legend::legend(const STDNS string& text, 
		       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS legend::legend(const HTMLAttributeList& attributes, 
		       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS legend::~legend()
{}

//EOF
