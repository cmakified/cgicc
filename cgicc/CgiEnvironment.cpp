/*
 *  $Id: CgiEnvironment.cpp,v 1.8 2001/09/05 02:18:28 sbooth Exp $
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

#include <new>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <cctype>

#ifdef WIN32
#include <io.h>
#include <fcntl.h>
#endif

#include "cgicc/CgiEnvironment.h"

// ========== Constructor/Destructor

CGICCNS CgiEnvironment::CgiEnvironment(reader_function_t stream_reader)
{
  LOGLN("CgiEnvironment::CgiEnvironment")
  
  readEnvironmentVariables();

  // On Win32, use binary read to avoid CRLF conversion
#ifdef WIN32
  _setmode(_fileno(stdin), _O_BINARY);
#endif
  
  if(stringsAreEqual( getRequestMethod(), "get")) {
    LOGLN("GET method recognized")
  }
  else if(stringsAreEqual( getRequestMethod(), "post")) {
    LOGLN("POST method recognized");
          
    STDNS auto_ptr<char> temp(new char[getContentLength()]);

    // use the appropriate reader function
    if(stream_reader == NULL) {
      STDNS cin.read(temp.get(), getContentLength());
      if((unsigned long)STDNS cin.gcount() != getContentLength())
	throw STDNS runtime_error("I/O error");
    }
    else {
      // user specified a reader function
      if((*stream_reader)
	 (temp.get(), getContentLength()) != getContentLength())
	throw STDNS runtime_error("I/O error");
    }

    fPostData = STDNS string(temp.get(), getContentLength());
  }
  
  fCookies.reserve(10);
  parseCookies();
}

CGICCNS CgiEnvironment::~CgiEnvironment()
{
  LOGLN("CgiEnvironment::~CgiEnvironment")
}

void
CGICCNS CgiEnvironment::parseCookies()
{
  STDNS string data = getCookies();

  if(! data.empty()) {
    STDNS string::size_type pos 	= 0;
    STDNS string::size_type oldPos	= 0;

    while(true) {
      // find the ';' terminating a name=value pair
      pos = data.find(";", oldPos);

      // if no ';' was found, the rest of the string is a single cookie
      if(pos == STDNS string::npos) {
	parseCookie(data.substr(oldPos));
	return;
      }

      // otherwise, the string contains multiple cookies
      // extract it and add the cookie to the list
      parseCookie(data.substr(oldPos, pos - oldPos));
      
      // update pos (+1 to skip ';')
      oldPos = pos + 1;
    }
  }
}

void
CGICCNS CgiEnvironment::parseCookie(const STDNS string& data)
{
  // find the '=' separating the name and value
  STDNS string::size_type pos = data.find("=", 0);

  // if no '=' was found, return
  if(pos == STDNS string::npos)
    return;

  // skip leading whitespace - " \f\n\r\t\v"
  STDNS string::size_type wscount = 0;
  STDNS string::const_iterator data_iter;
  
  for(data_iter = data.begin(); data_iter != data.end(); ++data_iter,++wscount)
    if(isspace(*data_iter) == 0)
      break;			
  
  // unescape the data, and add to the cookie list
  STDNS string name 	= unescapeString(data.substr(wscount, pos - wscount));
  STDNS string value 	= unescapeString(data.substr(++pos));

  fCookies.push_back(HTTPCookie(name, value));
}

// Read in all the environment variables
void
CGICCNS CgiEnvironment::readEnvironmentVariables()
{
  fServerSoftware 	= safeGetenv("SERVER_SOFTWARE");
  fServerName 		= safeGetenv("SERVER_NAME");
  fGatewayInterface 	= safeGetenv("GATEWAY_INTERFACE");
  fServerProtocol 	= safeGetenv("SERVER_PROTOCOL");

  STDNS string port 	= safeGetenv("SERVER_PORT");
  fServerPort 		= atol(port.c_str());

  fRequestMethod 	= safeGetenv("REQUEST_METHOD");
  fPathInfo 		= safeGetenv("PATH_INFO");
  fPathTranslated 	= safeGetenv("PATH_TRANSLATED");
  fScriptName 		= safeGetenv("SCRIPT_NAME");
  fQueryString 		= safeGetenv("QUERY_STRING");
  fRemoteHost 		= safeGetenv("REMOTE_HOST");
  fRemoteAddr 		= safeGetenv("REMOTE_ADDR");
  fAuthType 		= safeGetenv("AUTH_TYPE");
  fRemoteUser 		= safeGetenv("REMOTE_USER");
  fRemoteIdent 		= safeGetenv("REMOTE_IDENT");
  fContentType 		= safeGetenv("CONTENT_TYPE");

  STDNS string length 	= safeGetenv("CONTENT_LENGTH");
  fContentLength 	= atol(length.c_str());

  fAccept 		= safeGetenv("HTTP_ACCEPT");
  fUserAgent 		= safeGetenv("HTTP_USER_AGENT");
  fRedirectRequest 	= safeGetenv("REDIRECT_REQUEST");
  fRedirectURL 		= safeGetenv("REDIRECT_URL");
  fRedirectStatus 	= safeGetenv("REDIRECT_STATUS");
  fReferrer 		= safeGetenv("HTTP_REFERER");
  fCookie 		= safeGetenv("HTTP_COOKIE");

#ifdef WIN32
  // Win32 bug fix by Peter Goedtkindt
  STDNS string https 	= safeGetenv("HTTPS");
  if(stringsAreEqual(https, "on"))
    fUsingHTTPS = true;
  else
    fUsingHTTPS = false;
#else
  fUsingHTTPS = (getenv("HTTPS") != 0);
#endif
}

void
CGICCNS CgiEnvironment::save(const STDNS string& filename) 	const
{
  LOGLN("CgiEnvironment::save")
  STDNS ofstream file( filename.c_str(), STDNS ios::out );

  if( ! file )
    throw STDNS runtime_error("I/O error");

  writeLong(file, getContentLength());
  writeLong(file, getServerPort());
  writeLong(file, (unsigned long) usingHTTPS());

  writeString(file, getServerSoftware());
  writeString(file, getServerName());
  writeString(file, getGatewayInterface());
  writeString(file, getServerProtocol());
  writeString(file, getRequestMethod());
  writeString(file, getPathInfo());
  writeString(file, getPathTranslated());
  writeString(file, getScriptName());
  writeString(file, getQueryString());
  writeString(file, getRemoteHost());
  writeString(file, getRemoteAddr());
  writeString(file, getAuthType());
  writeString(file, getRemoteUser());
  writeString(file, getRemoteIdent());
  writeString(file, getContentType());
  writeString(file, getAccept());
  writeString(file, getUserAgent());
  writeString(file, getRedirectRequest());
  writeString(file, getRedirectURL());
  writeString(file, getRedirectStatus());
  writeString(file, getReferrer());
  writeString(file, getCookies());
  
  if(stringsAreEqual(getRequestMethod(), "post"))
    writeString(file, getPostData());

  if(file.bad() || file.fail())
    throw STDNS runtime_error("I/O error");

  file.close();
}

void
CGICCNS CgiEnvironment::restore(const STDNS string& filename)
{
  LOGLN("CgiEnvironment::restore()")
  STDNS ifstream file( filename.c_str(), STDNS ios::in );

  if( ! file )
    throw STDNS runtime_error("I/O error");

  file.flags(file.flags() & STDNS ios::skipws);

  fContentLength 	= readLong(file);
  fServerPort 		= readLong(file);
  fUsingHTTPS 		= (bool) readLong(file);

  fServerSoftware 	= readString(file);
  fServerName 		= readString(file);
  fGatewayInterface 	= readString(file);
  fServerProtocol 	= readString(file);
  fRequestMethod 	= readString(file);
  fPathInfo 		= readString(file);
  fPathTranslated 	= readString(file);
  fScriptName 		= readString(file);
  fQueryString 		= readString(file);
  fRemoteHost 		= readString(file);
  fRemoteAddr 		= readString(file);
  fAuthType 		= readString(file);
  fRemoteUser 		= readString(file);
  fRemoteIdent 		= readString(file);
  fContentType 		= readString(file);
  fAccept 		= readString(file);
  fUserAgent 		= readString(file);
  fRedirectRequest 	= readString(file);
  fRedirectURL 		= readString(file);
  fRedirectStatus	= readString(file);
  fReferrer 		= readString(file);
  fCookie 		= readString(file);
  
  if(stringsAreEqual(getRequestMethod(), "post"))
    fPostData = readString(file);

  file.close();

  fCookies.clear();
  fCookies.reserve(10);
  parseCookies();
}
