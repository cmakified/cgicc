/*
 * $Id: HTMLLists.cc,v 1.3 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

#include "HTMLLists.hh"

// ============================================================
// Statics
// ============================================================
bool ul::sState = false;
bool ol::sState = false;
bool li::sState = false;
bool dl_::sState = false;
bool dt::sState = false;
bool dd::sState = false;

// ============================================================
// Class ul
// ============================================================
ul::ul(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

ul::ul(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

ul::ul(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

ul::ul(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

ul::ul(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

ul::~ul()
{}

// ============================================================
// Class ol
// ============================================================
ol::ol(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

ol::ol(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

ol::ol(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

ol::ol(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

ol::ol(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

ol::~ol()
{}

// ============================================================
// Class li
// ============================================================
li::li(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

li::li(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

li::li(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

li::li(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

li::li(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

li::~li()
{}

// ============================================================
// Class dl_
// ============================================================
dl_::dl_(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

dl_::dl_(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

dl_::dl_(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

dl_::dl_(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

dl_::dl_(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

dl_::~dl_()
{}

// ============================================================
// Class dt
// ============================================================
dt::dt(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

dt::dt(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

dt::dt(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

dt::dt(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

dt::dt(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

dt::~dt()
{}

// ============================================================
// Class dd
// ============================================================
dd::dd(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

dd::dd(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

dd::dd(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

dd::dd(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

dd::dd(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

dd::~dd()
{}
