/*
 * $Id: HTMLForms.cc,v 1.2 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

#include "HTMLForms.hh"

// ============================================================
// Statics
// ============================================================
bool form::sState = false;
bool button::sState = false;
bool select::sState = false;
bool optgroup::sState = false;
bool option::sState = false;
bool textarea::sState = false;
bool label::sState = false;
bool fieldset::sState = false;
bool legend::sState = false;

// ============================================================
// Class form
// ============================================================
form::form(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

form::form(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

form::form(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

form::form(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

form::form(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

form::~form()
{}

// ============================================================
// Class input
// ============================================================
input::input() 
{}

input::input(const HTMLAttributeList& attributes)
	: HTMLElement(&attributes)
{}

input::~input()
{}

// ============================================================
// Class button
// ============================================================
button::button(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

button::button(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

button::button(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

button::button(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

button::button(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

button::~button()
{}

// ============================================================
// Class select
// ============================================================
select::select(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

select::select(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

select::select(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

select::select(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

select::select(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

select::~select()
{}

// ============================================================
// Class optgroup
// ============================================================
optgroup::optgroup(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

optgroup::optgroup(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

optgroup::optgroup(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

optgroup::optgroup(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

optgroup::optgroup(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

optgroup::~optgroup()
{}

// ============================================================
// Class option
// ============================================================
option::option(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

option::option(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

option::option(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

option::option(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

option::option(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

option::~option()
{}

// ============================================================
// Class textarea
// ============================================================
textarea::textarea(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

textarea::textarea(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

textarea::textarea(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

textarea::textarea(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

textarea::textarea(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

textarea::~textarea()
{}

// ============================================================
// Class label
// ============================================================
label::label(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

label::label(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

label::label(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

label::label(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

label::label(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

label::~label()
{}

// ============================================================
// Class fieldset
// ============================================================
fieldset::fieldset(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

fieldset::fieldset(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

fieldset::fieldset(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

fieldset::fieldset(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

fieldset::fieldset(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

fieldset::~fieldset()
{}

// ============================================================
// Class legend
// ============================================================
legend::legend(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

legend::legend(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

legend::legend(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

legend::legend(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

legend::legend(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

legend::~legend()
{}
