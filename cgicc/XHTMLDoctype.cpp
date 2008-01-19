/* -*-mode:c++; c-file-style: "gnu";-*- */
/*
 *  $Id: XHTMLDoctype.cpp,v 1.1 2008/01/19 15:43:57 sebdiaz Exp $
 *
 *  Copyright (C) 1996 - 2004 Stephen F. Booth <sbooth@gnu.org>
 *                       2007 David Roberts
		     2007 Sebastien DIAZ <sebastien.diaz@gmail.com>
 *  Part of the GNU cgicc library, http://www.gnu.org/software/cgicc
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 3 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA 
 */
#include "XHTMLDoctype.h"


cgicc::XHTMLDoctype::XHTMLDoctype(EDocumentType type) : fType(type) {}

cgicc::XHTMLDoctype::~XHTMLDoctype() {}

void cgicc::XHTMLDoctype::render(std::ostream &out) const {
	out << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 ";
	
	switch(fType) {
		case eStrict: out << "Strict"; break;
		case eTransitional: out << "Transitional"; break;
		case eFrames: out << "Frameset"; break;
	}
	
	out << "//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-";
	
	switch(fType) {
		case eStrict: out << "strict"; break;
		case eTransitional: out << "transitional"; break;
		case eFrames: out << "frameset"; break;
	}
	
	out << ".dtd\">";
}
