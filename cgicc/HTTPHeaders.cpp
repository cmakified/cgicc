/*
 *  $Id: HTTPHeaders.cpp,v 1.5 2001/09/03 16:16:48 sbooth Exp $
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
// Class HTTPHeader
// ============================================================
CGICCNS HTTPHeader::HTTPHeader()
{
  fCookies.reserve(5);
}

CGICCNS HTTPHeader::HTTPHeader(const STDNS string& data)
  : fData(data)
{
  fCookies.reserve(5);
}

CGICCNS HTTPHeader::HTTPHeader(const HTTPHeader& header)
  : MStreamable(),
    fData(header.getData()),
    fCookies(header.getCookies())
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
  out << "Content-Type: " << getData() << STDNS endl;

  if(getCookies().empty() == false) {
    STDNS vector<HTTPCookie>::const_iterator iter; 
    
    for(iter = getCookies().begin(); iter != getCookies().end(); ++iter)
      out << *iter << STDNS endl;
  }

  out << STDNS endl;
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
  out << "Location: " << getData() << STDNS endl;

  if(getCookies().empty() == false) {
    STDNS vector<HTTPCookie>::const_iterator iter; 
    
    for(iter = getCookies().begin(); iter != getCookies().end(); ++iter)
      out << *iter << STDNS endl;
  }

  out << STDNS endl;
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
  out << "Status: " << getStatusCode() << ' ' << getData() << STDNS endl;

  if(getCookies().empty() == false) {
    STDNS vector<HTTPCookie>::const_iterator iter; 
    
    for(iter = getCookies().begin(); iter != getCookies().end(); ++iter)
      out << *iter << STDNS endl;
  }

  out << STDNS endl;
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

void 
CGICCNS HTTPResponseHeader::render(STDNS ostream& out)	const
{
  STDNS vector<STDNS string>::const_iterator iter;
  
  out << fHTTPVersion << ' ' << fStatusCode << ' ' << fReasonPhrase 
      << STDNS endl;

  for(iter = fHeaders.begin(); iter != fHeaders.end(); ++iter) {
    out << *iter << STDNS endl;
  }
  out << STDNS endl;
}

// ============================================================
// Class HTTPNPHeader
// ============================================================
CGICCNS HTTPNPHeader::HTTPNPHeader()
  : HTTPResponseHeader("HTTP/1.1", 204, "No Response")
{}

CGICCNS HTTPNPHeader::~HTTPNPHeader()
{}
