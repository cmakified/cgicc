/*
 *  $Id: HTTPCookie.cpp,v 1.5 2003/07/13 14:20:35 sbooth Exp $
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

#include "cgicc/HTTPCookie.h"
#include "cgicc/CgiUtils.h"

// ============================================================
// Class HTTPCookie
// ============================================================
cgicc::HTTPCookie::HTTPCookie()
  : fMaxAge(0),
    fSecure(false)
{}

cgicc::HTTPCookie::HTTPCookie(const std::string& name, 
			      const std::string& value)
  : fName(name),
    fValue(value),
    fMaxAge(0),
    fSecure(false)
{}

cgicc::HTTPCookie::HTTPCookie(const std::string& name, 
			      const std::string& value, 
			      const std::string& comment, 
			      const std::string& domain, 
			      unsigned long maxAge, 
			      const std::string& path,
			      bool secure)
  : fName(name),
    fValue(value), 
    fComment(comment), 
    fDomain(domain), 
    fMaxAge(maxAge),
    fPath(path), 
    fSecure(secure)
{}

cgicc::HTTPCookie::HTTPCookie(const HTTPCookie& cookie)
  : MStreamable(),
    fName(cookie.getName()), 
    fValue(cookie.getValue()), 
    fComment(cookie.getComment()),
    fDomain(cookie.getDomain()), 
    fMaxAge(cookie.getMaxAge()),
    fPath(cookie.getPath()), 
    fSecure(cookie.isSecure())
{}

cgicc::HTTPCookie::~HTTPCookie()
{}

bool 
cgicc::HTTPCookie::operator== (const HTTPCookie& cookie) const
{
  return (stringsAreEqual(fName, cookie.fName)
	  && stringsAreEqual(fValue, cookie.fValue)
	  && stringsAreEqual(fComment, cookie.fComment)
	  && stringsAreEqual(fDomain, cookie.fDomain)
	  && fMaxAge == cookie.fMaxAge
	  && stringsAreEqual(fPath, cookie.fPath)
	  && fSecure == cookie.fSecure);
}

void 
cgicc::HTTPCookie::render(std::ostream& out) 	const
{
  out << "Set-Cookie:" << getName() << '=' << getValue();
  if(fComment.empty() == false)
    out << "; Comment=" << fComment;
  if(fDomain.empty() == false)
    out << "; Domain=" << fDomain;
  if(fMaxAge != 0)
    out << "; Max-Age=" << fMaxAge;
  if(fPath.empty() == false)
    out << "; Path=" << fPath;
  if(fSecure == true)
    out << "; Secure";
  
  out << "; Version=1";
}
