/*
 *  $Id: HTTPResponseHeader.cpp,v 1.2 2001/09/05 02:18:28 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001 Stephen F. Booth
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

#include "cgicc/HTTPResponseHeader.h"

// ============================================================
// Class HTTPResponseHeader
// ============================================================
CGICCNS HTTPResponseHeader::HTTPResponseHeader(const STDNS string& version,
					       int status_code,
					       const STDNS string& reason)
  : MStreamable(),
    fHTTPVersion(version),
    fStatusCode(status_code),
    fReasonPhrase(reason)
{
  fHeaders.reserve(5);
}

CGICCNS HTTPResponseHeader::~HTTPResponseHeader()
{}

CGICCNS HTTPResponseHeader&
CGICCNS HTTPResponseHeader::addHeader(const STDNS string& header)
{
  fHeaders.push_back(header); 
  return *this; 
}

CGICCNS HTTPResponseHeader&
CGICCNS HTTPResponseHeader::addHeader(const STDNS string& name,
				      const STDNS string& value)
{ 
  fHeaders.push_back(name + ": " + value); 
  return *this; 
}

CGICCNS HTTPResponseHeader&
CGICCNS HTTPResponseHeader::setCookie(const HTTPCookie& cookie)
{ 
  fCookies.push_back(cookie); 
  return *this; 
}

void 
CGICCNS HTTPResponseHeader::render(STDNS ostream& out)	const
{
  STDNS vector<STDNS string>::const_iterator iter;
  STDNS vector<HTTPCookie>::const_iterator cookie_iter; 
  
  out << fHTTPVersion << ' ' << fStatusCode << ' ' << fReasonPhrase 
      << STDNS endl;
  
  for(iter = fHeaders.begin(); iter != fHeaders.end(); ++iter)
    out << *iter << STDNS endl;
  
  for(cookie_iter = getCookies().begin(); 
      cookie_iter != getCookies().end(); 
      ++cookie_iter)
    out << *cookie_iter << STDNS endl;

  out << STDNS endl;
}
