/* -*-c++-*- */
/*
 *  $Id: CgiEnvironment.h,v 1.4 1999/08/20 20:51:43 sbooth Exp $
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

#ifndef _CGIENVIRONMENT_H_
#define _CGIENVIRONMENT_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

#include <vector>
#include <string>
#include <cstdlib>

#include "cgicc/CgiDefs.h"
#include "cgicc/CgiUtils.h"
#include "cgicc/HTTPHeaders.h"

CGICC_BEGIN_NAMESPACE

#ifdef WIN32
  template class CGICC_API STDNS vector<HTTPCookie>;
#endif

// ============================================================
// Class CgiEnvironment
// ============================================================
/**
 * Encapsulates all the data passed from the server to the application.
 * <P>To read in the environment, simply instantiate an object of this type.
 * </P>
 */
class CGICC_API CgiEnvironment
{
public:
  
  friend class Cgicc;
  
  /** Read in the environment */
  CgiEnvironment();
  
  /** Destructor */
  ~CgiEnvironment();

  
  /**
   * Get the name and version of the http server software.
   * An example of this is Apache/1.3.4.
   * @return The name of the server software
   */
  inline STDNS string 
  getServerSoftware() 				const
    { return fServerSoftware; }
  
  /**
   * Get the hostname, DNS name or IP address of the http server.
   * This is <EM>not</EM> a URL, for example www.gnu.org.
   * @return The name of the server
   */
  inline STDNS string 
  getServerName() 				const
    { return fServerName; }
  
  /**
   * Get the name and version of the gateway interface.
   * This is usually CGI/1.1.
   * @return The name and version of the gateway interface
   */
  inline STDNS string 
  getGatewayInterface() 			const
    { return fGatewayInterface;}
  
  /**
   * Get the name and revision of the protocol used for this request.
   * This is usually HTTP/1.0.
   * @return The protocol in use
   */
  inline STDNS string 
  getServerProtocol() 				const
    { return fServerProtocol; }
  
  /**
   * Get the port number on the server to which this request was sent.
   * This will usually be 80.
   * @return The port number
   */
  inline unsigned long
  getServerPort() 				const
    { return fServerPort; }

  
  /**
   * Get the HTTP cookies associated with this query, if any.
   * @return The HTTP cookies
   */
  inline STDNS string 
  getCookies() 					const
    { return fCookie; }
  
  /**
   * Get a vector containing the HTTP cookies associated with this query.
   * @return A vector containing the HTTP cookies associated with this query.
   * @see HTTPCookie
   */
  inline const STDNS vector<HTTPCookie>& 
  getCookieList() 				const
    { return fCookies; }
  
  /**
   * Get the request method used for this query.
   * This is usually one of GET or POST.
   * @return The request method
   */
  inline STDNS string 
  getRequestMethod()   				const
    { return fRequestMethod; }
  
  /**
   * Get the extra path information for this request, given by the client.
   * @return The absolute path info
   */
  inline STDNS string
  getPathInfo() 				const
    { return fPathInfo; }
  
  /**
   * Get the translated path information (virtual to physical mapping).
   * @return The translated path info
   */
  inline STDNS string 
  getPathTranslated() 				const
    { return fPathTranslated; }
  
  /**
   * Get the path to this application, for self-referencing URLs.
   * @return The name of this application
   */
  inline STDNS string 
  getScriptName() 				const
    { return fScriptName; }
  
  /**
   * Get string following the ? in the URL which called this application.
   * This is usually only valid for scripts called with the GET method.
   * @return The query string
   */
  inline STDNS string 
  getQueryString()  				const
    { return fQueryString; }
  
  /**
   * Get the length of the data read from standard in, in chars.
   * @return The data length
   */
  inline unsigned long 
  getContentLength() 				const
    { return fContentLength; }
  
  /**
   * Get the content type of the attached information.
   * For POST methods, this is usually application/x-www-form-urlencoded.
   * @return The content type
   */
  inline STDNS string 
  getContentType() 				const
    { return fContentType; }
  
  /**
   * Get the data passed via standard input.
   * This data is of MIME type getContentType().
   * @return The post data.
   */
  inline STDNS string
  getPostData() 				const
    { return fPostData; }

  
  /**
   * Get the page which called this application.
   * Depending on the http server software, this may not be set.
   * @return The URL which called this application.
   */
  inline STDNS string 
  getReferrer() 				const
    { return fReferrer; }

  
  /**
   * Get the hostname making this request.
   * @return The remote host
   */
  inline STDNS string 
  getRemoteHost() 				const
    { return fRemoteHost; }
  
  /**
   * Get the IP address of the remote host making this request.
   * @return The remote IP address
   */
  inline STDNS string 
  getRemoteAddr() 				const
    { return fRemoteAddr; }
  
  /**
   * Get the protocol-specific user authentication method used.
   * This is only applicable if the server supports user authentication,
   * and the user has authenticated.
   * @return The authorization type
   */
  inline STDNS string 
  getAuthType() 				const
    { return fAuthType; }
  
  /**
   * Get the authenticated remote user name.
   * This is only applicable if the server supports user authentication,
   * and the user has authenticated.
   * @return The remote username 
   */
  inline STDNS string 
  getRemoteUser() 				const
    { return fRemoteUser; }
  
  /**
   * Get the remote user name retrieved from the server.
   * This is only applicable if the server supports RFC 931 
   * identification.  This variable should <EM>only</EM> be used
   * for logging.
   * @return The remote identification
   */
  inline STDNS string 
  getRemoteIdent()    				const
    { return fRemoteIdent; }
  
  /**
   * Get the MIME data types accepted by the client's browser.
   * For example image/gif, image/x-xbitmap, image/jpeg, image/pjpeg.
   * @return The accepted data types
   */
  inline STDNS string 
  getAccept() 					const
    { return fAccept; }
  
  /**
   * Get the name of the browser used for this CGI request.
   * For example Mozilla/4.01 [en] (WinNT; U).
   * @return The browser name
   */
  inline STDNS string 
  getUserAgent() 				const
    { return fUserAgent; }


  /**
   * Determine whether this is a secure request (using https).
   * @return true if this connection is via https
   */
  inline bool
  usingHTTPS() 					const
  { return (getenv("HTTPS") != 0); }
  

  /**
   * Get the redirect request.
   * This will only be valid if you are using this script as a script
   * to use in place of the default server messages.
   * @return The redirect request.
   */
  inline STDNS string 
  getRedirectRequest() 				const
    { return fRedirectRequest; }
  
  /**
   * Get the redirect URL.
   * This will only be valid if you are using this script as a script
   * to use in place of the default server messages.
   * @return The redirect URL.
   * @see \URL{http://hoohoo.ncsa.uiuc.edu/docs/setup/srm/ErrorDocument.html}
   */
  inline STDNS string 
  getRedirectURL() 				const
    { return fRedirectURL; }
  
  /**
   * Get the redirect status.
   * This will only be valid if you are using this script as a script
   * to use in place of the default server messages.
   * @return The redirect status.
   */
  inline STDNS string 
  getRedirectStatus() 				const
    { return fRedirectStatus; }
  
protected:
  
  // Implementation of save
  void 
  save(const STDNS string& filename) 		const;
  
  // Implementation of restore
  void 
  restore(const STDNS string& filename);
  
private:
  
  // Parse the list of cookies from a string to a vector
  void 
  parseCookies();

  // Parse a single cookie string (name=value) pair
  void
  parseCookie(const STDNS string& data);
  
  // Read in all the environment variables
  void 
  readEnvironmentVariables();
  
  unsigned long 		fServerPort;
  unsigned long 		fContentLength;
  STDNS string 			fServerSoftware;
  STDNS string 			fServerName;
  STDNS string 			fGatewayInterface;
  STDNS string 			fServerProtocol;
  STDNS string 			fRequestMethod;
  STDNS string 			fPathInfo;
  STDNS string 			fPathTranslated;
  STDNS string 			fScriptName;
  STDNS string 			fQueryString;
  STDNS string 			fRemoteHost;
  STDNS string 			fRemoteAddr;
  STDNS string 			fAuthType;
  STDNS string 			fRemoteUser;
  STDNS string 			fRemoteIdent;
  STDNS string 			fContentType;
  STDNS string 			fAccept;
  STDNS string 			fUserAgent;
  STDNS string 			fPostData;
  STDNS string 			fRedirectRequest;
  STDNS string 			fRedirectURL;
  STDNS string 			fRedirectStatus;
  STDNS string 			fReferrer;
  STDNS string 			fCookie;
  STDNS vector<HTTPCookie> 	fCookies;
};

CGICC_END_NAMESPACE

#endif /* ! _CGIENVIRONMENT_H_ */
