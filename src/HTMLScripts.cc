/*
 * $Id: HTMLScripts.cc,v 1.2 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

#include "HTMLScripts.hh"

// ============================================================
// Statics
// ============================================================
bool script::sState = false;
bool noscript::sState = false;

// ============================================================
// Class script
// ============================================================
script::script(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

script::script(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

script::script(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

script::script(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

script::script(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

script::~script()
{}

// ============================================================
// Class noscript
// ============================================================
noscript::noscript(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

noscript::noscript(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

noscript::noscript(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

noscript::noscript(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

noscript::noscript(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

noscript::~noscript()
{}
