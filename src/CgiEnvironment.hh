/* $Id: CgiEnvironment.hh,v 1.3 1998/04/03 09:10:20 sbooth Exp $ */

#ifndef __CGI_ENVIRONMENT__
#define __CGI_ENVIRONMENT__ 1

#ifndef __EXCEPTION__
#include "Exception.hh"
#endif

#ifndef __LINKED_LIST__
#include "LinkedList.hh"
#endif

#ifndef __CGI_DEFS__
#include "CgiDefs.hh"
#endif

#ifndef __HTTP_HEADERS__
#include "HTTPHeaders.hh"
#endif


// ============================================================
// Class CgiEnvironment
// ============================================================
/**
 * Encapsulates all the data passed from the server to the application.
 * <P>To read in the environment, simply instantiate an object of this type.
 * <BR><P>The getXXX() methods in this class, with the exception of
 * getPostData(), will <EM>never</EM> return NULL.</P>
 */
class CgiEnvironment
{
public:

  friend class Cgicc;

  /**@name Constructors */
  //@{
  
  /** 
   * Read in the environment.
   * @exception Exception
   */
  CgiEnvironment()	throw(Exception);
  
  /** Destructor */
  ~CgiEnvironment();
  //@}
  
  
  /**@name Server information */
  //@{
  
  /**
   * Get the name and version of the http server software.
   * An example of this is Netscape-FastTrack/2.01.
   * @return The name of the server software, or ""
   */
  inline const char* getServerSoftware() const	{ return fServerSoftware; }
  
  /**
   * Get the hostname, DNS name or IP address of the http server.
   * This is <EM>not</EM> a URL, for example www.cs.hmc.edu.
   * @return The name of the server, or ""
   */
  inline const char* getServerName() const	{ return fServerName; }
  
  /**
   * Get the name and version of the gateway interface.
   * This is usually CGI/1.1.
   * @return The name and version of the gateway interface, or ""
   */
  inline const char* getGatewayInterface() const { return fGatewayInterface; }
  
  /**
   * Get the name and revision of the protocol used for this request.
   * This is usually HTTP/1.0.
   * @return The protocol in use, or ""
   */
  inline const char* getServerProtocol() const	{ return fServerProtocol; }
  
  /**
   * Get the port number on the server to which this request was sent.
   * This will usually be 80.
   * @return The port number
   */
  inline long getServerPort() const		{ return fServerPort; }
  //@}
  
  
  /**@name Information on this CGI query */
  //@{
  
  /**
   * Get the HTTP cookies associated with this query, if any.
   * @return The HTTP cookies, or ""
   */
  inline const char* getCookies() const	{ return fCookie; }

  /**
   * Get a LinkedList containing the HTTP cookies associated with this query.
   * @return A list containing the HTTP cookies associated with this query.
   * @see LinkedList
   * @see HTTPCookie
   */
  inline const LinkedList<HTTPCookie>* getCookieList() const 
  { return fCookies; }

  /**
   * Get the request method used for this query.
   * This is usually one of GET or POST.
   * @return The request method, or ""
   */
  inline const char* getRequestMethod() const	{ return fRequestMethod; }
  
  /**
   * Get the extra path information for this request, given by the client.
   * @return The absolute path info, or ""
   */
  inline const char* getPathInfo() const	{ return fPathInfo; }
  
  /**
   * Get the translated path information (virtual to physical mapping).
   * @return The translated path info, or ""
   */
  inline const char* getPathTranslated() const	{ return fPathTranslated; }
  
  /**
   * Get the path to this application, for self-referencing URLs.
   * @return The name of this application, or ""
   */
  inline const char* getScriptName() const	{ return fScriptName; }
  
  /**
   * Get string following the ? in the URL which called this application.
   * This is usually only valid for scripts called with the GET method.
   * @return The query string, or ""
   */
  inline const char* getQueryString() const	{ return fQueryString; }
  
  /**
   * Get the length of the data read from standard in, in chars.
   * @return The data length
   */
  inline long getContentLength() const		{ return fContentLength; }
  
  /**
   * Get the content type of the attached information.
   * For POST methods, this is usually application/x-www-form-urlencoded.
   * @return The content type, or ""
   */
  inline const char* getContentType() const	{ return fContentType; }
  
  /**
   * Get the data passed via standard input.
   * This data is of MIME type getContentType().
   * If getContentLength() == 0, this will return NULL.
   * @return The post data, or NULL if none
   */
  inline const char* getPostData() const	{ return fPostData; }
  //@}
  
  /**@name Server-specific */
  //@{
  
  /**
   * Get the page which called this application.
   * Depending on the http server software, this may not be set.
   * @return The URL which called this application, or "".
   */
  inline const char* getReferrer() const 	{ return fReferrer; }
  //@}
  
  /**@name Remote user information */
  //@{
  
  /**
   * Get the hostname making this request.
   * @return The remote host, or ""
   */
  inline const char* getRemoteHost() const	{ return fRemoteHost; }
  
  /**
   * Get the IP address of the remote host making this request.
   * @return The remote IP address, or ""
   */
  inline const char* getRemoteAddr() const	{ return fRemoteAddr; }
  
  /**
   * Get the protocol-specific user authentication method used.
   * This is only applicable if the server supports user authentication,
   * and the user has authenticated.
   * @return The authorization type, or ""
   */
  inline const char* getAuthType() const	{ return fAuthType; }
  
  /**
   * Get the authenticated remote user name.
   * This is only applicable if the server supports user authentication,
   * and the user has authenticated.
   * @return The remote username , or ""
   */
  inline const char* getRemoteUser() const	{ return fRemoteUser; }
  
  /**
   * Get the remote user name retrieved from the server.
   * This is only applicable if the server supports RFC 931 
   * identification.  This variable should <EM>only</EM> be used
   * for logging.
   * @return The remote identification, or ""
   */
  inline const char* getRemoteIdent() const	{ return fRemoteIdent; }
  
  /**
   * Get the MIME data types accepted by the client's browser.
   * For example image/gif, image/x-xbitmap, image/jpeg, image/pjpeg.
   * @return The accepted data types, or ""
   */
  inline const char* getAccept() const		{ return fAccept; }
  
  /**
   * Get the name of the browser used for this CGI request.
   * For example Mozilla/4.01 [en] (WinNT; U).
   * @return The browser name, or ""
   */
  inline const char* getUserAgent() const	{ return fUserAgent; }
  //@}
  
  /**@name ErrorDocument handling */
  //@{
  
  /**
   * Get the redirect request.
   * This will only be valid if you are using this script as a script
   * to use in place of the default server messages.
   * @return The redirect request, or "".
   */
  inline const char* getRedirectRequest() const { return fRedirectRequest; }
  
  /**
   * Get the redirect URL.
   * This will only be valid if you are using this script as a script
   * to use in place of the default server messages.
   * @return The redirect URL, or "".
   * @see \URL{http://hoohoo.ncsa.uiuc.edu/docs/setup/srm/ErrorDocument.html}
   */
  inline const char* getRedirectURL() const 	{ return fRedirectURL; }
  
  /**
   * Get the redirect status.
   * This will only be valid if you are using this script as a script
   * to use in place of the default server messages.
   * @return The redirect status, or "".
   */
  inline const char* getRedirectStatus() const 	{ return fRedirectStatus; }
  //@}

protected:
  
  void save(const char *filename) const 	throw(Exception);
  void restore(const char *filename)		throw(Exception);
  
private:

  void parseCookies();
  void parseCookie(const char *data, int dataLen);
  
  /* Write a string to an ostream */
  inline void writeString(ostream& out, const char *s) const
  { out << strlen(s) << ' ' << s; }
  
  /* Read a string from an istream */
  void readString(istream& in, char* &s);
  
  /* Read in all the environment variables */
  void readEnvironmentVariables() throw(Exception);
  
  /* reclaim storage */
  void reclaimStorage();
  
  long 		fServerPort;
  long 		fContentLength;
  char 		*fServerSoftware;
  char 		*fServerName;
  char 		*fGatewayInterface;
  char 		*fServerProtocol;
  char 		*fRequestMethod;
  char 		*fPathInfo;
  char 		*fPathTranslated;
  char 		*fScriptName;
  char 		*fQueryString;
  char 		*fRemoteHost;
  char 		*fRemoteAddr;
  char 		*fAuthType;
  char 		*fRemoteUser;
  char 		*fRemoteIdent;
  char 		*fContentType;
  char 		*fAccept;
  char 		*fUserAgent;
  char		*fPostData;
  char		*fRedirectRequest;
  char		*fRedirectURL;
  char		*fRedirectStatus;
  char		*fReferrer;
  char		*fCookie;

  LinkedList<HTTPCookie> *fCookies;
};

#endif
