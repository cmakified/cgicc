/*
 * $Id: HTMLObjects.cc,v 1.2 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

#include "HTMLObjects.hh"

// ============================================================
// Statics
// ============================================================
bool object::sState = false;
bool map_::sState = false;

// ============================================================
// Class img
// ============================================================
img::img() 
{}

img::img(const HTMLAttributeList& attributes)
	: HTMLElement(&attributes)
{}

img::~img()
{}

// ============================================================
// Class object
// ============================================================
object::object(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

object::object(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

object::object(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

object::object(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

object::object(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

object::~object()
{}

// ============================================================
// Class param
// ============================================================
param::param() 
{}

param::param(const HTMLAttributeList& attributes)
	: HTMLElement(&attributes)
{}

param::~param()
{}

// ============================================================
// Class map_
// ============================================================
map_::map_(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

map_::map_(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

map_::map_(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

map_::map_(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

map_::map_(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

map_::~map_()
{}

// ============================================================
// Class area
// ============================================================
area::area() 
{}

area::area(const HTMLAttributeList& attributes)
	: HTMLElement(&attributes)
{}

area::~area()
{}
