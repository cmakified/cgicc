/*
 * $Id: HTMLGraphics.cc,v 1.2 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
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
