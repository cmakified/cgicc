/* $Id: HTMLStyles.cc,v 1.1 1998/02/12 05:31:41 sbooth Exp $ */

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
