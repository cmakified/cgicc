/* -*-mode:c++; c-file-style: "gnu";-*- */
/*
 *  $Id: HTTPStatusHeader.cpp,v 1.7 2007/07/02 18:48:19 sebdiaz Exp $
 *
 *  Copyright (C) 1996 - 2004 Stephen F. Booth <sbooth@gnu.org>
 *                       2007 Sebastien DIAZ <sebastien.diaz@gmail.com>
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

#ifdef __GNUG__
#  pragma implementation
#endif

#include "cgicc/HTTPStatusHeader.h"

// ============================================================
// Class HTTPStatusHeader
// ============================================================
cgicc::HTTPStatusHeader::HTTPStatusHeader()
  : HTTPHeader(""),
    fStatus(-1)
{}

cgicc::HTTPStatusHeader::HTTPStatusHeader(int status, 
					  const std::string& message) 
  : HTTPHeader(message),
    fStatus(status)
{}

cgicc::HTTPStatusHeader::~HTTPStatusHeader()
{}

void 
cgicc::HTTPStatusHeader::render(std::ostream& out) 	const
{
  std::vector<HTTPCookie>::const_iterator iter; 

  out << "Status: " << getStatusCode() << ' ' << getData() << std::endl;
  
  for(iter = getCookies().begin(); iter != getCookies().end(); ++iter)
    out << *iter << std::endl;

  out << std::endl;
}
