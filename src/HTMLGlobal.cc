/*
 *  $Id: HTMLGlobal.cc,v 1.5 1999/04/26 22:42:30 sbooth Exp $
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

#include "HTMLGlobal.hh"

// ============================================================
// Statics
// ============================================================
bool CGICCNS comment::sState 	= false;
bool CGICCNS html::sState 	= false;
bool CGICCNS head::sState 	= false;
bool CGICCNS title::sState 	= false;
bool CGICCNS body::sState 	= false;
bool CGICCNS div::sState 	= false;
bool CGICCNS span::sState 	= false;
bool CGICCNS h1::sState 	= false;
bool CGICCNS h2::sState 	= false;
bool CGICCNS h3::sState 	= false;
bool CGICCNS h4::sState 	= false;
bool CGICCNS h5::sState 	= false;
bool CGICCNS h6::sState 	= false;
bool CGICCNS address::sState 	= false;

// ============================================================
// Class comment
// ============================================================
CGICCNS comment::comment() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS comment::comment(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

void
CGICCNS comment::render(STDNS ostream& out) const 
{
  if(getData().empty()) {
    swapState();
    if(getState())
      out << '<' << getName();
    else
      out << " -->";
  }
  else
    out << '<' << getName() << getData() << " -->";
}

CGICCNS comment::~comment()
{}

// ============================================================
// Class html
// ============================================================
CGICCNS html::html() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS html::html(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS html::html(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS html::html(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS html::html(const STDNS string& text, 
		   const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS html::html(const HTMLAttributeList& attributes, 
		   const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS html::~html()
{}

// ============================================================
// Class head
// ============================================================
CGICCNS head::head() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS head::head(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS head::head(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS head::head(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS head::head(const STDNS string& text, 
		   const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS head::head(const HTMLAttributeList& attributes, 
		   const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS head::~head()
{}

// ============================================================
// Class title
// ============================================================
CGICCNS title::title() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS title::title(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS title::title(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS title::title(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS title::title(const STDNS string& text, 
		     const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS title::title(const HTMLAttributeList& attributes, 
		     const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS title::~title()
{}

// ============================================================
// Class meta
// ============================================================
CGICCNS meta::meta() 
{}

CGICCNS meta::meta(const HTMLAttributeList& attributes)
  : HTMLElement(&attributes)
{}

CGICCNS meta::~meta()
{}

// ============================================================
// Class body
// ============================================================
CGICCNS body::body() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS body::body(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS body::body(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS body::body(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS body::body(const STDNS string& text, 
		   const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS body::body(const HTMLAttributeList& attributes, 
		   const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS body::~body()
{}

// ============================================================
// Class div
// ============================================================
CGICCNS div::div() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS div::div(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS div::div(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS div::div(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS div::div(const STDNS string& text, 
		 const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS div::div(const HTMLAttributeList& attributes, 
		 const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS div::~div()
{}

// ============================================================
// Class span
// ============================================================
CGICCNS span::span() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS span::span(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS span::span(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS span::span(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS span::span(const STDNS string& text, 
		   const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS span::span(const HTMLAttributeList& attributes, 
		   const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS span::~span()
{}

// ============================================================
// Class h1
// ============================================================
CGICCNS h1::h1() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS h1::h1(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS h1::h1(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS h1::h1(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS h1::h1(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS h1::h1(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS h1::~h1()
{}

// ============================================================
// Class h2
// ============================================================
CGICCNS h2::h2() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS h2::h2(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS h2::h2(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS h2::h2(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS h2::h2(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS h2::h2(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS h2::~h2()
{}

// ============================================================
// Class h3
// ============================================================
CGICCNS h3::h3() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS h3::h3(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS h3::h3(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS h3::h3(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS h3::h3(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS h3::h3(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS h3::~h3()
{}

// ============================================================
// Class h4
// ============================================================
CGICCNS h4::h4() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS h4::h4(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS h4::h4(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS h4::h4(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS h4::h4(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS h4::h4(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS h4::~h4()
{}

// ============================================================
// Class h5
// ============================================================
CGICCNS h5::h5() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS h5::h5(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS h5::h5(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS h5::h5(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS h5::h5(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS h5::h5(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS h5::~h5()
{}

// ============================================================
// Class h6
// ============================================================
CGICCNS h6::h6() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS h6::h6(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS h6::h6(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS h6::h6(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS h6::h6(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS h6::h6(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS h6::~h6()
{}

// ============================================================
// Class address
// ============================================================
CGICCNS address::address() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS address::address(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS address::address(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS address::address(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS address::address(const STDNS string& text, 
			 const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS address::address(const HTMLAttributeList& attributes, 
			 const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS address::~address()
{}
