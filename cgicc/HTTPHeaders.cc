/*
 *  $Id: HTTPHeaders.cc,v 1.2 1999/06/04 00:07:42 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999 Stephen F. Booth
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

#ifdef __GNUG__
#pragma implementation
#endif

#include "cgicc/HTTPHeaders.hh"

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
  : fSecure(false)
{}

CGICCNS HTTPCookie::HTTPCookie(const STDNS string& name, 
			       const STDNS string& value)
  : fName(name), 
    fValue(value),
    fSecure(false)
{}

CGICCNS HTTPCookie::HTTPCookie(const STDNS string& name, 
			       const STDNS string& value, 
			       const STDNS string& expires, 
			       const STDNS string& path,
			       const STDNS string& domain, 
			       bool secure)
  : fName(name), 
    fValue(value), 
    fExpires(expires), 
    fPath(path), 
    fDomain(domain), 
    fSecure(secure)
{}

CGICCNS HTTPCookie::HTTPCookie(const HTTPCookie& cookie)
  : fName(cookie.getName()), 
    fValue(cookie.getValue()), 
    fExpires(cookie.getExpires()), 
    fPath(cookie.getPath()), 
    fDomain(cookie.getDomain()), 
    fSecure(cookie.isSecure())
{}

CGICCNS HTTPCookie::~HTTPCookie()
{}

void 
CGICCNS HTTPCookie::render(STDNS ostream& out) 	const
{
  out << "Set-Cookie: " << getName() << '=' << getValue() << ';';
  if(! fExpires.empty())
    out << " expires=" << fExpires << ';';
  if(! fPath.empty())
    out << " path=" << fPath << ';';
  if(! fDomain.empty())
    out << " domain=" << fDomain << ';';
  if(fSecure == true)
    out << " secure";
  
  out << STDNS endl;
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
  : fData(header.getData())
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

//EOF
