/*
 *  $Id: CgiEnvironment.cc,v 1.6 1998/12/09 00:48:39 sbooth Exp $
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

#include "CgiEnvironment.hh"

#include <stdlib.h>

// ========== Constructor/Destructor

CgiEnvironment::CgiEnvironment() throw(Exception)
{
  logln("Entering CgiEnvironment::CgiEnvironment");
  
  readEnvironmentVariables();
  
  if( stringsAreEqual( getRequestMethod(), "get", true )) {
    logln("GET method recognized");
    fPostData = NULL;
  }
  else if( stringsAreEqual( getRequestMethod(), "post", true )) {
    logln("POST method recognized");
    if( getContentLength() == 0) {
      fPostData = NULL;
    }
    else {
      fPostData = new char[ getContentLength() + 1];
      if( ! fPostData ) 
	throw Exception("new failed", ERRINFO);
      
      cin.read( fPostData, getContentLength() );
      fPostData [getContentLength() ] = '\0';
      if( cin.gcount() != (unsigned int) getContentLength() )
	throw Exception("I/O error", ERRINFO);
    }
  }

  fCookies = new LinkedList<HTTPCookie>;
  //if( ! fCookies )
  //throw Exception("new failed", ERRINFO);
  parseCookies();
}

CgiEnvironment::~CgiEnvironment()
{
  logln("CgiEnvironment::~CgiEnvironment");
  reclaimStorage();
}

void
CgiEnvironment::parseCookies()
{
  const char *data = getCookies();
  if(data != NULL) {
    int dataLen = strlen(data);
    const char *sep = "; ";
    
    int extractedLen = 0;
    while(extractedLen <= dataLen) {
      int newLen;
      newLen = findBytes(data + extractedLen, 
			 dataLen - extractedLen, 
			 sep);
      if(newLen == -1)
	newLen = dataLen - extractedLen;
      
      parseCookie(data + extractedLen, newLen);      
      extractedLen += (newLen + strlen(sep));
    }
  }
}

void
CgiEnvironment::parseCookie(const char *data, int dataLen)
{
  // Find the divider
  int sepPos = 0;
  const char *sep = "=";
  sepPos = findBytes(data, dataLen, sep);
  
  // fix for bug reported by Sergei Prognimak
  // need to check if sepPos == -1
  if(sepPos == -1)
    return;

  // Extract data, convert, and add
  char *name;
  char *value;
  unescapeChars(data, sepPos, name);
  unescapeChars(data + sepPos + 1, dataLen - sepPos - 1, value);
  
  fCookies->append(HTTPCookie(name, value));
  
  delete [] name;
  delete [] value;
}

/* Read in all the environment variables */
void
CgiEnvironment::readEnvironmentVariables() throw(Exception)
{
  safeGetenv( "SERVER_SOFTWARE", fServerSoftware );
  safeGetenv( "SERVER_NAME", fServerName );
  safeGetenv( "GATEWAY_INTERFACE", fGatewayInterface );
  safeGetenv( "SERVER_PROTOCOL", fServerProtocol );

  char *port;
  safeGetenv( "SERVER_PORT", port );
  fServerPort = atol(port);
  delete [] port;

  safeGetenv( "REQUEST_METHOD", fRequestMethod );
  safeGetenv( "PATH_INFO", fPathInfo );
  safeGetenv( "PATH_TRANSLATED", fPathTranslated );
  safeGetenv( "SCRIPT_NAME", fScriptName );
  safeGetenv( "QUERY_STRING", fQueryString );
  safeGetenv( "REMOTE_HOST", fRemoteHost );
  safeGetenv( "REMOTE_ADDR", fRemoteAddr );
  safeGetenv( "AUTH_TYPE", fAuthType );
  safeGetenv( "REMOTE_USER", fRemoteUser );
  safeGetenv( "REMOTE_IDENT", fRemoteIdent );
  safeGetenv( "CONTENT_TYPE", fContentType );

  char *length;
  safeGetenv( "CONTENT_LENGTH", length ); 
  fContentLength = atol(length);
  delete [] length;

  safeGetenv( "HTTP_ACCEPT", fAccept );
  safeGetenv( "HTTP_USER_AGENT", fUserAgent );
  safeGetenv( "REDIRECT_REQUEST", fRedirectRequest );
  safeGetenv( "REDIRECT_URL", fRedirectURL );
  safeGetenv( "REDIRECT_STATUS", fRedirectStatus );
  safeGetenv( "HTTP_REFERER", fReferrer );
  safeGetenv( "HTTP_COOKIE", fCookie );
}

/* reclaim storage */
void
CgiEnvironment::reclaimStorage()
{
  logln("reclaimStorage()");

  delete [] fServerSoftware;
  delete [] fServerName;
  delete [] fGatewayInterface;
  delete [] fServerProtocol;
  delete [] fRequestMethod;
  delete [] fPathInfo;
  delete [] fPathTranslated;
  delete [] fScriptName;
  delete [] fQueryString;
  delete [] fRemoteHost;
  delete [] fRemoteAddr;
  delete [] fAuthType;
  delete [] fRemoteUser;
  delete [] fRemoteIdent;
  delete [] fContentType;
  delete [] fAccept;
  delete [] fUserAgent;
  delete [] fRedirectRequest;
  delete [] fRedirectURL;
  delete [] fRedirectStatus;
  delete [] fReferrer;
  delete [] fCookie;
  if(fPostData != NULL)
    delete [] fPostData;

  delete fCookies;
}

/* read a string */
void
CgiEnvironment::readString(istream& in, char* &s)
{
  int dataSize = 0;
  
  in >> dataSize;
  in.get(); // skip ' '
  s = new char [dataSize + 1];
  in.read(s, dataSize);
  s[dataSize] = '\0';
}

void
CgiEnvironment::save( const char *filename ) const throw(Exception)
{
  logln("save");
  ofstream file( filename, ios::out );

  if( ! file )
    throw Exception("I/O error", ERRINFO);

  file << getContentLength() << ' ';
  file << getServerPort() << ' ';

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
  
  if( stringsAreEqual( getRequestMethod(), "post", true ) )
    writeString(file,getPostData());
  
  file.close();
}


void
CgiEnvironment::restore( const char *filename ) throw(Exception)
{
  logln("restore()");
  ifstream file( filename, ios::in );

  if( ! file )
    throw Exception("I/O error", ERRINFO);

  file.flags(file.flags() & ios::skipws);

  reclaimStorage();

  file >> fContentLength;
  file.get(); // skip trailing space
  file >> fServerPort;
  file.get(); // skip trailing space

  readString(file, fServerSoftware);
  readString(file, fServerName);
  readString(file, fGatewayInterface);
  readString(file, fServerProtocol);
  readString(file, fRequestMethod);
  readString(file, fPathInfo);
  readString(file, fPathTranslated);
  readString(file, fScriptName);
  readString(file, fQueryString);
  readString(file, fRemoteHost);
  readString(file, fRemoteAddr);
  readString(file, fAuthType);
  readString(file, fRemoteUser);
  readString(file, fRemoteIdent);
  readString(file, fContentType);
  readString(file, fAccept);
  readString(file, fUserAgent);
  readString(file, fRedirectRequest);
  readString(file, fRedirectURL);
  readString(file, fRedirectStatus);
  readString(file, fReferrer);
  readString(file, fCookie);
  
  if( stringsAreEqual( getRequestMethod(), "post", true ) ) {
    if(getContentLength() != 0)
      readString(file,fPostData);
    else
      fPostData = NULL;
  }
  else
    fPostData = NULL;

  file.close();

  fCookies = new LinkedList<HTTPCookie>;
  parseCookies();
}

/* End of class CgiEnvironment */
