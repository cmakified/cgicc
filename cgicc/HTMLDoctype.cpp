/*
 *  $Id: HTMLDoctype.cpp,v 1.4 2003/07/13 14:20:35 sbooth Exp $
 *
 *  Copyright (C) 1996 - 2003 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifdef __GNUG__
#  pragma implementation
#endif

#include "cgicc/HTMLDoctype.h"

// ============================================================
// Class HTMLDoctype
// ============================================================

cgicc::HTMLDoctype::HTMLDoctype(EDocumentType type)
  : fType(type)
{}

cgicc::HTMLDoctype::~HTMLDoctype()
{}

void
cgicc::HTMLDoctype::render(std::ostream &out) 	const
{
  out << "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0";
  
  switch(fType) {
  case eStrict:
    break;

  case eTransitional:
    out << " Transitional";
    break;
    
  case eFrames:
    out << " Frameset";
    break;
  }
  
  out << "//EN\" \"http://www.w3.org/TR/REC-html40/";
  
  switch(fType) {
  case eStrict:
    out << "strict.dtd\"";
    break;
    
  case eTransitional:
    out << "transitional.dtd\"";
    break;
    
  case eFrames:
    out << "frameset.dtd\"";
    break;
  }
  out << '>';
}
