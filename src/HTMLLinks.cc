/*
 * $Id: HTMLLinks.cc,v 1.2 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

#include "HTMLLinks.hh"

// ============================================================
// Statics
// ============================================================
bool a::sState = false;

// ============================================================
// Class a
// ============================================================
a::a(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

a::a(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

a::a(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

a::a(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

a::a(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

a::~a()
{}

// ============================================================
// Class link_
// ============================================================
link_::link_() 
{}

link_::link_(const HTMLAttributeList& attributes)
	: HTMLElement(&attributes)
{}

link_::~link_()
{}

// ============================================================
// Class base
// ============================================================
base::base() 
{}

base::base(const HTMLAttributeList& attributes)
	: HTMLElement(&attributes)
{}

base::~base()
{}
