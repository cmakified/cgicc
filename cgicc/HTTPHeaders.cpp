/*
 *  $Id: HTTPHeaders.cpp,v 1.4 2001/09/02 19:53:17 sbooth Exp $
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

#include "cgicc/HTTPHeaders.h"
#include "cgicc/CgiUtils.h"

// ============================================================
// Class HTMLDoctype
// ============================================================
CGICCNS HTMLDoctype::HTMLDoctype(EDocumentType type)
  : fType(type)
{}

CGICCNS HTMLDoctype::~HTMLDoctype()
{}

void
CGICCNS HTMLDoctype::render(STDNS ostream &out) 	const
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

// ============================================================
// Class HTTPCookie
// ============================================================
CGICCNS HTTPCookie::HTTPCookie()
  : fMaxAge(0), 
    fSecure(false)
{}

CGICCNS HTTPCookie::HTTPCookie(const STDNS string& name, 
			       const STDNS string& value)
  : fName(name), 
    fValue(value),
    fMaxAge(0),
    fSecure(false)
{}

CGICCNS HTTPCookie::HTTPCookie(const STDNS string& name, 
			       const STDNS string& value, 
			       const STDNS string& comment, 
			       const STDNS string& domain, 
			       unsigned long maxAge, 
			       const STDNS string& path,
			       bool secure)
  : fName(name), 
    fValue(value), 
    fComment(comment), 
    fDomain(domain), 
    fMaxAge(maxAge),
    fPath(path), 
    fSecure(secure)
{}

CGICCNS HTTPCookie::HTTPCookie(const HTTPCookie& cookie)
  : MStreamable(),
    fName(cookie.getName()), 
    fValue(cookie.getValue()), 
    fComment(cookie.getComment()),
    fDomain(cookie.getDomain()), 
    fMaxAge(cookie.getMaxAge()),
    fPath(cookie.getPath()), 
    fSecure(cookie.isSecure())
{}

CGICCNS HTTPCookie::~HTTPCookie()
{}

bool 
CGICCNS HTTPCookie::operator== (const HTTPCookie& cookie) const
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
CGICCNS HTTPCookie::render(STDNS ostream& out) 	const
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
  
  out << "; Version=1" << STDNS endl;
}

// ============================================================
// Class HTTPHeader
// ============================================================
CGICCNS HTTPHeader::HTTPHeader()
{}

CGICCNS HTTPHeader::HTTPHeader(const STDNS string& data)
  : fData(data)
{}

CGICCNS HTTPHeader::HTTPHeader(const HTTPHeader& header)
  : MStreamable(),
    fData(header.getData())
{}

CGICCNS HTTPHeader::~HTTPHeader()
{}

// ============================================================
// Class HTTPContentHeader
// ============================================================
CGICCNS HTTPContentHeader::HTTPContentHeader(const STDNS string& mimeType) 
  : HTTPHeader(mimeType)
{}

CGICCNS HTTPContentHeader::~HTTPContentHeader()
{}

void 
CGICCNS HTTPContentHeader::render(STDNS ostream& out)	const
{
  out << "Content-Type: " << getData() << STDNS endl << STDNS endl;
}

// ============================================================
// Class HTTPRedirectHeader
// ============================================================
CGICCNS HTTPRedirectHeader::HTTPRedirectHeader(const STDNS string& url) 
  : HTTPHeader(url)
{}

CGICCNS HTTPRedirectHeader::~HTTPRedirectHeader()
{}

void 
CGICCNS HTTPRedirectHeader::render(STDNS ostream& out) 	const
{
  out << "Location: " << getData() << STDNS endl << STDNS endl;
}

// ============================================================
// Class HTTPStatusHeader
// ============================================================
CGICCNS HTTPStatusHeader::HTTPStatusHeader()
  : HTTPHeader(""), 
    fStatus(-1)
{}

CGICCNS HTTPStatusHeader::HTTPStatusHeader(int status, 
					   const STDNS string& message) 
  : HTTPHeader(message), 
    fStatus(status)
{}

CGICCNS HTTPStatusHeader::~HTTPStatusHeader()
{}

void 
CGICCNS HTTPStatusHeader::render(STDNS ostream& out) 	const
{
  out << "Status: " << getStatusCode() << ' ' << getData() 
      << STDNS endl << STDNS endl;
}

// ============================================================
// Class HTTPNPHeader
// ============================================================
CGICCNS HTTPNPHeader::HTTPNPHeader()
  : HTTPHeader("HTTP/1.1 204 No Response")
{}

CGICCNS HTTPNPHeader::~HTTPNPHeader()
{}

void 
CGICCNS HTTPNPHeader::render(STDNS ostream& out) 	const
{
  out << getData() << STDNS endl << STDNS endl;
}

// ============================================================
// Class HTTPHTMLHeader
// ============================================================
CGICCNS HTTPHTMLHeader::HTTPHTMLHeader()
  : HTTPContentHeader("text/html")
{}

CGICCNS HTTPHTMLHeader::~HTTPHTMLHeader()
{}

// ============================================================
// Class HTTPPlainHeader
// ============================================================
CGICCNS HTTPPlainHeader::HTTPPlainHeader()
  : HTTPContentHeader("text/plain")
{}

CGICCNS HTTPPlainHeader::~HTTPPlainHeader()
{}

// ============================================================
// Class HTTPGIFHeader
// ============================================================
CGICCNS HTTPGIFHeader::HTTPGIFHeader()
  : HTTPContentHeader("image/gif")
{}

CGICCNS HTTPGIFHeader::~HTTPGIFHeader()
{}

// ============================================================
// Class HTTPJPEGHeader
// ============================================================
CGICCNS HTTPJPEGHeader::HTTPJPEGHeader()
  : HTTPContentHeader("image/jpeg")
{}

CGICCNS HTTPJPEGHeader::~HTTPJPEGHeader()
{}

// ============================================================
// Class HTTPXBMHeader
// ============================================================
CGICCNS HTTPXBMHeader::HTTPXBMHeader()
  : HTTPContentHeader("image/x-xbitmap")
{}

CGICCNS HTTPXBMHeader::~HTTPXBMHeader()
{}

// ============================================================
// Class HTTPAudioHeader
// ============================================================
CGICCNS HTTPAudioHeader::HTTPAudioHeader()
  : HTTPContentHeader("audio/basic")
{}

CGICCNS HTTPAudioHeader::~HTTPAudioHeader()
{}
