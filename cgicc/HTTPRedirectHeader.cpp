/*
 *  $Id: HTTPRedirectHeader.cpp,v 1.4 2003/07/13 14:20:35 sbooth Exp $
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

#include "cgicc/HTTPRedirectHeader.h"

// ============================================================
// Class HTTPRedirectHeader
// ============================================================
cgicc::HTTPRedirectHeader::HTTPRedirectHeader(const std::string& url) 
  : HTTPHeader(url)
{}

cgicc::HTTPRedirectHeader::~HTTPRedirectHeader()
{}

void 
cgicc::HTTPRedirectHeader::render(std::ostream& out) 	const
{
  out << "Location: " << getData() << std::endl;
  
  if(getCookies().empty() == false) {
    std::vector<HTTPCookie>::const_iterator iter; 
    
    for(iter = getCookies().begin(); iter != getCookies().end(); ++iter)
      out << *iter << std::endl;
  }
  
  out << std::endl;
}
