/*
 *  $Id: HTMLDirLang.cc,v 1.4 1998/12/09 00:48:39 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "HTMLDirLang.hh"

// ============================================================
// Statics
// ============================================================
bool bdo::sState = false;

// ============================================================
// Class bdo
// ============================================================
bdo::bdo(const char *text) 
  : HTMLBooleanElement(text, NULL, NULL)
{}

bdo::bdo(const HTMLAttributeList& attributes)
  : HTMLBooleanElement(NULL, &attributes, NULL)
{}

bdo::bdo(const HTMLSimpleElement& embed)
  : HTMLBooleanElement(NULL, NULL, &embed)
{}

bdo::bdo(const char *text, const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, NULL)
{}

bdo::bdo(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
  : HTMLBooleanElement(NULL, &attributes, &embed)
{}

bdo::~bdo()
{}
