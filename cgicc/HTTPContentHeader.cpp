/* -*-mode:c++; c-file-style: "gnu";-*- */
/*
 *  $Id: HTTPContentHeader.cpp,v 1.6 2004/06/30 04:27:27 sbooth Exp $
 *
 *  Copyright (C) 1996 - 2004 Stephen F. Booth <sbooth@gnu.org>
 *  Part of the GNU cgicc library, http://www.cgicc.org
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

#include "cgicc/HTTPContentHeader.h"

// ============================================================
// Class HTTPContentHeader
// ============================================================
cgicc::HTTPContentHeader::HTTPContentHeader(const std::string& mimeType) 
  : HTTPHeader(mimeType)
{}

cgicc::HTTPContentHeader::~HTTPContentHeader()
{}

void 
cgicc::HTTPContentHeader::render(std::ostream& out)	const
{
  out << "Content-Type: " << getData() << std::endl;
  
  std::vector<HTTPCookie>::const_iterator iter; 
  for(iter = getCookies().begin(); iter != getCookies().end(); ++iter)
    out << *iter << std::endl;
  
  out << std::endl;
}
