/* $Id: HTMLTables.cc,v 1.1 1998/02/12 05:31:41 sbooth Exp $ */

#include "HTMLTables.hh"

// ============================================================
// Statics
// ============================================================
bool table::sState = false;
bool caption::sState = false;
bool thead::sState = false;
bool tfoot::sState = false;
bool tbody::sState = false;
bool colgroup::sState = false;
bool tr::sState = false;
bool th::sState = false;
bool td::sState = false;

// ============================================================
// Class table
// ============================================================
table::table(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

table::table(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

table::table(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

table::table(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

table::table(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

table::~table()
{}

// ============================================================
// Class caption
// ============================================================
caption::caption(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

caption::caption(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

caption::caption(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

caption::caption(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

caption::caption(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

caption::~caption()
{}

// ============================================================
// Class thead
// ============================================================
thead::thead(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

thead::thead(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

thead::thead(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

thead::thead(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

thead::thead(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

thead::~thead()
{}

// ============================================================
// Class tfoot
// ============================================================
tfoot::tfoot(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

tfoot::tfoot(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

tfoot::tfoot(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

tfoot::tfoot(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

tfoot::tfoot(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

tfoot::~tfoot()
{}

// ============================================================
// Class tbody
// ============================================================
tbody::tbody(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

tbody::tbody(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

tbody::tbody(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

tbody::tbody(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

tbody::tbody(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

tbody::~tbody()
{}

// ============================================================
// Class colgroup
// ============================================================
colgroup::colgroup(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

colgroup::colgroup(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

colgroup::colgroup(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

colgroup::colgroup(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

colgroup::colgroup(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

colgroup::~colgroup()
{}

// ============================================================
// Class col
// ============================================================
col::col() 
{}

col::col(const HTMLAttributeList& attributes)
	: HTMLElement(&attributes)
{}

col::~col()
{}

// ============================================================
// Class tr
// ============================================================
tr::tr(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

tr::tr(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

tr::tr(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

tr::tr(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

tr::tr(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

tr::~tr()
{}

// ============================================================
// Class th
// ============================================================
th::th(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

th::th(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

th::th(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

th::th(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

th::th(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

th::~th()
{}

// ============================================================
// Class td
// ============================================================
td::td(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

td::td(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

td::td(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

td::td(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

td::td(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

td::~td()
{}
