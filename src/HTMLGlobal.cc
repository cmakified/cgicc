/*
 *  $Id: HTMLGlobal.cc,v 1.4 1998/12/09 00:48:39 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "HTMLGlobal.hh"

// ============================================================
// Statics
// ============================================================
bool comment::sState = false;
bool html::sState = false;
bool head::sState = false;
bool title::sState = false;
bool body::sState = false;
bool div_::sState = false;
bool span::sState = false;
bool h1::sState = false;
bool h2::sState = false;
bool h3::sState = false;
bool h4::sState = false;
bool h5::sState = false;
bool h6::sState = false;
bool address::sState = false;

// ============================================================
// Class comment
// ============================================================
comment::comment(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

void
comment::render(ostream& out) const {
	if(getData() == NULL) {
		swapState();
		if(getState())
			out << '<' << getName();
		else
			out << " -->";
	}
	else
		out << '<' << getName() << getData() << " -->";
}

comment::~comment()
{}

// ============================================================
// Class html
// ============================================================
html::html(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

html::html(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

html::html(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

html::html(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

html::html(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

html::~html()
{}

// ============================================================
// Class head
// ============================================================
head::head(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

head::head(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

head::head(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

head::head(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

head::head(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

head::~head()
{}

// ============================================================
// Class title
// ============================================================
title::title(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

title::title(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

title::title(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

title::title(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

title::title(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

title::~title()
{}

// ============================================================
// Class meta
// ============================================================
meta::meta() 
{}

meta::meta(const HTMLAttributeList& attributes)
	: HTMLElement(&attributes)
{}

meta::~meta()
{}

// ============================================================
// Class body
// ============================================================
body::body(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

body::body(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

body::body(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

body::body(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

body::body(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

body::~body()
{}

// ============================================================
// Class div_
// ============================================================
div_::div_(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

div_::div_(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

div_::div_(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

div_::div_(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

div_::div_(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

div_::~div_()
{}

// ============================================================
// Class span
// ============================================================
span::span(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

span::span(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

span::span(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

span::span(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

span::span(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

span::~span()
{}

// ============================================================
// Class h1
// ============================================================
h1::h1(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

h1::h1(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

h1::h1(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

h1::h1(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

h1::h1(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

h1::~h1()
{}

// ============================================================
// Class h2
// ============================================================
h2::h2(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

h2::h2(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

h2::h2(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

h2::h2(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

h2::h2(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

h2::~h2()
{}

// ============================================================
// Class h3
// ============================================================
h3::h3(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

h3::h3(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

h3::h3(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

h3::h3(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

h3::h3(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

h3::~h3()
{}

// ============================================================
// Class h4
// ============================================================
h4::h4(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

h4::h4(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

h4::h4(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

h4::h4(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

h4::h4(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

h4::~h4()
{}

// ============================================================
// Class h5
// ============================================================
h5::h5(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

h5::h5(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

h5::h5(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

h5::h5(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

h5::h5(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

h5::~h5()
{}

// ============================================================
// Class h6
// ============================================================
h6::h6(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

h6::h6(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

h6::h6(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

h6::h6(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

h6::h6(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

h6::~h6()
{}

// ============================================================
// Class address
// ============================================================
address::address(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

address::address(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

address::address(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

address::address(const char* text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

address::address(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

address::~address()
{}
