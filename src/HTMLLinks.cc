/*
 * $Id: HTMLLinks.cc,v 1.3 1998/12/08 23:14:33 sbooth Exp $
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
