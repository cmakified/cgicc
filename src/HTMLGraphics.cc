/*
 * $Id: HTMLGraphics.cc,v 1.3 1998/12/08 23:14:33 sbooth Exp $
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

#include "HTMLGraphics.hh"

// ============================================================
// Statics
// ============================================================
bool tt::sState = false;
bool i::sState = false;
bool b::sState = false;
bool big::sState = false;
bool small::sState = false;

// ============================================================
// Class tt
// ============================================================
tt::tt(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

tt::tt(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

tt::tt(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

tt::tt(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

tt::tt(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

tt::~tt()
{}

// ============================================================
// Class i
// ============================================================
i::i(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

i::i(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

i::i(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

i::i(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

i::i(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

i::~i()
{}

// ============================================================
// Class b
// ============================================================
b::b(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

b::b(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

b::b(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

b::b(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

b::b(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

b::~b()
{}

// ============================================================
// Class big
// ============================================================
big::big(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

big::big(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

big::big(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

big::big(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

big::big(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

big::~big()
{}

// ============================================================
// Class small
// ============================================================
small::small(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

small::small(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

small::small(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

small::small(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

small::small(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

small::~small()
{}

// ============================================================
// Class hr
// ============================================================
hr::hr() 
{}

hr::hr(const HTMLAttributeList& attributes) 
	: HTMLElement(&attributes)
{}

hr::~hr()
{}
