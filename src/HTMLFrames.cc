/*
 * $Id: HTMLFrames.cc,v 1.3 1998/12/08 23:14:33 sbooth Exp $
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

#include "HTMLFrames.hh"

// ============================================================
// Statics
// ============================================================
bool frameset::sState = false;
bool noframes::sState = false;
bool iframe::sState = false;

// ============================================================
// Class frameset
// ============================================================
frameset::frameset(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

frameset::frameset(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

frameset::frameset(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

frameset::frameset(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

frameset::frameset(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

frameset::~frameset()
{}

// ============================================================
// Class frame
// ============================================================
frame::frame() 
{}

frame::frame(const HTMLAttributeList& attributes)
	: HTMLElement(&attributes)
{}

frame::~frame()
{}

// ============================================================
// Class noframes
// ============================================================
noframes::noframes(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

noframes::noframes(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

noframes::noframes(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

noframes::noframes(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

noframes::noframes(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

noframes::~noframes()
{}

// ============================================================
// Class iframe
// ============================================================
iframe::iframe(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

iframe::iframe(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

iframe::iframe(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

iframe::iframe(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

iframe::iframe(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

iframe::~iframe()
{}
