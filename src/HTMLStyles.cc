/*
 * $Id: HTMLStyles.cc,v 1.2 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

#include "HTMLStyles.hh"

// ============================================================
// Statics
// ============================================================
bool style::sState = false;

// ============================================================
// Class style
// ============================================================
style::style(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

style::style(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

style::style(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

style::style(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

style::style(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

style::~style()
{}
