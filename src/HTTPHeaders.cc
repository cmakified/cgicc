/*
 *  $Id: HTTPHeaders.cc,v 1.6 1998/12/09 00:48:39 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "HTTPHeaders.hh"

// ============================================================
// Class HTMLDoctype
// ============================================================
HTMLDoctype::HTMLDoctype(EDocumentType type) {
  fType = type;
}

HTMLDoctype::~HTMLDoctype()
{}

void
HTMLDoctype::render(ostream &out) const {
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
HTTPCookie::HTTPCookie(const char *name, 
		       const char *value, 
		       const char *expires, 
		       const char *path,
		       const char *domain, 
		       bool secure) throw(Exception)
  : fName(NULL), fValue(NULL), fExpires(NULL), fPath(NULL), 
    fDomain(NULL), fSecure(secure)
{
  setName(name);
  setValue(value);
  if(expires != NULL)
    setExpires(expires);
  if(path != NULL)
    setPath(path);
  if(domain != NULL)
    setDomain(domain);
}

HTTPCookie::HTTPCookie(const HTTPCookie& cookie) 
  : fName(NULL), fValue(NULL), fExpires(NULL), fPath(NULL), 
    fDomain(NULL), fSecure(cookie.isSecure())
{
  setName(cookie.getName());
  setValue(cookie.getValue());
  if(cookie.getExpires() != NULL)
    setExpires(cookie.getExpires());
  if(cookie.getPath() != NULL)
    setPath(cookie.getPath());
  if(cookie.getDomain() != NULL)
    setDomain(getDomain());
}

HTTPCookie::~HTTPCookie() {
  delete [] fName;
  delete [] fValue;
  delete [] fExpires;
  delete [] fPath;
  delete [] fDomain;
}

void 
HTTPCookie::setName(const char *name) throw(Exception) 
{ set(fName, name); }

void 
HTTPCookie::setValue(const char *value) throw(Exception) 
{ set(fValue, value); }

void 
HTTPCookie::setExpires(const char *expires) throw(Exception) 
{ set(fExpires, expires); }

void 
HTTPCookie::setPath(const char *path) throw(Exception) 
{ set(fPath, path); }

void 
HTTPCookie::setDomain(const char *domain) throw(Exception) 
{ set(fDomain, domain); }

void 
HTTPCookie::setSecure(bool secure)
{ fSecure = secure; }

void 
HTTPCookie::set(char* &attr, const char *value) throw(Exception) {
  delete [] attr;
  attr = new char [ strlen(value) + 1];
  if(attr == NULL)
    throw Exception("new failed", ERRINFO);
  strcpy(attr, value);
}

void 
HTTPCookie::render(ostream& out) const {
  out << "Set-Cookie: " << getName() << '=' << getValue() << ';';
  if(getExpires() != NULL)
    out << " expires=" << getExpires() << ';';
  if(getPath() != NULL)
    out << " path=" << getPath() << ';';
  if(getDomain() != NULL)
    out << " domain=" << getDomain() << ';';
  if(isSecure())
    out << " secure";
  
  out << endl;
}

// ============================================================
// Class HTTPHeader
// ============================================================
HTTPHeader::HTTPHeader(const char *data) throw(Exception)
  : fData(NULL)
{
  if(data != NULL)
    setData(data);
}

HTTPHeader::HTTPHeader(const HTTPHeader& header) {
  if(header.getData() != NULL)
    setData(header.getData());
}

HTTPHeader::~HTTPHeader() {
  delete [] fData;
}

void
HTTPHeader::setData(const char *data) throw(Exception) {
  delete [] fData;
  fData = new char [strlen(data) + 1];
  if(fData == NULL)
    throw Exception("new failed", ERRINFO);
  strcpy(fData, data);
}

// ============================================================
// Class HTTPContentHeader
// ============================================================
HTTPContentHeader::HTTPContentHeader(const char *mimeType) throw(Exception) {
  if(mimeType != NULL)
    setData(mimeType);
}

HTTPContentHeader::~HTTPContentHeader()
{}

void 
HTTPContentHeader::render(ostream& out) const {
  out << "Content-type: " << getData() << endl << endl;
}

// ============================================================
// Class HTTPRedirectHeader
// ============================================================
HTTPRedirectHeader::HTTPRedirectHeader(const char *url) throw(Exception)
  : HTTPHeader(url)
{}

HTTPRedirectHeader::~HTTPRedirectHeader()
{}

void 
HTTPRedirectHeader::render(ostream& out) const {
  out << "Location: " << getData() << endl << endl;
}

// ============================================================
// Class HTTPStatusHeader
// ============================================================
HTTPStatusHeader::HTTPStatusHeader() throw(Exception)
  : HTTPHeader(), fStatus(-1)
{}

HTTPStatusHeader::HTTPStatusHeader(int status, const char *message) 
  throw(Exception)
    : HTTPHeader(message), fStatus(status)
{}

HTTPStatusHeader::~HTTPStatusHeader()
{}

void 
HTTPStatusHeader::render(ostream& out) const {
  out << "Status: " << getStatusCode() << ' ' << getData() << endl << endl;
}

// ============================================================
// Class HTTPNPHeader
// ============================================================
HTTPNPHeader::HTTPNPHeader() throw(Exception)
  //: HTTPHeader("HTTP/1.0 204 No Response")
  : HTTPHeader("HTTP/1.1 204 No Response")
{}

HTTPNPHeader::~HTTPNPHeader()
{}

void 
HTTPNPHeader::render(ostream& out) const {
  out << getData() << endl << endl;
}

// ============================================================
// Class HTTPHTMLHeader
// ============================================================
HTTPHTMLHeader::HTTPHTMLHeader() throw(Exception)
  : HTTPContentHeader("text/html")
{}

HTTPHTMLHeader::~HTTPHTMLHeader()
{}

// ============================================================
// Class HTTPPlainHeader
// ============================================================
HTTPPlainHeader::HTTPPlainHeader() throw(Exception)
  : HTTPContentHeader("text/plain")
{}

HTTPPlainHeader::~HTTPPlainHeader()
{}

// ============================================================
// Class HTTPGIFHeader
// ============================================================
HTTPGIFHeader::HTTPGIFHeader() throw(Exception)
  : HTTPContentHeader("image/gif")
{}

HTTPGIFHeader::~HTTPGIFHeader()
{}

// ============================================================
// Class HTTPJPEGHeader
// ============================================================
HTTPJPEGHeader::HTTPJPEGHeader() throw(Exception)
  : HTTPContentHeader("image/jpeg")
{}

HTTPJPEGHeader::~HTTPJPEGHeader()
{}

// ============================================================
// Class HTTPXBMHeader
// ============================================================
HTTPXBMHeader::HTTPXBMHeader() throw(Exception)
  : HTTPContentHeader("image/x-xbitmap")
{}

HTTPXBMHeader::~HTTPXBMHeader()
{}

// ============================================================
// Class HTTPAudioHeader
// ============================================================
HTTPAudioHeader::HTTPAudioHeader() throw(Exception)
  : HTTPContentHeader("audio/basic")
{}

HTTPAudioHeader::~HTTPAudioHeader()
{}
