/*
 *  $Id: HTTPHeaders.hh,v 1.6 1998/12/09 17:57:47 sbooth Exp $
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

#ifndef __HTTP_HEADERS__
#define __HTTP_HEADERS__ 1

#include "Exception.hh"
#include "LinkedList.hh"

// ============================================================
// Class HTMLDoctype
// ============================================================
/** 
 * Specifies the DTD of the HTML 4 document.
 * <P>To use this class, simply write an object of this type to an ostream:<BR>
 * <PRE CLASS="code">
 * . out << HTMLDoctype();
 * </PRE>
 * <P>For more information, see <TT>\URL{http://www.w3.org/MarkUp/}</TT> and 
 * <TT>\URL{http://www.w3.org/TR/REC-html40/}</TT></P>
 */
class HTMLDoctype : public MStreamable {
public:
  /**@name Enumerations */
  //@{

  /** 
   * The DTD used by this document.
   * <BR><TT>eStrict</TT> - The HTML 4.0 Strict DTD.<BR>
   * <TT>eTransitional</TT> - The HTML 4.0 Transitional DTD.<BR>
   * <TT>eFrames</TT> - The HTML 4.0 Frameset DTD.
   */
  enum EDocumentType {
    eStrict,
    eTransitional,
    eFrames
  };
  //@}

  /**@name Constructors */
  //@{

  /**
   * Constructor.
   * @param type The version of the HTML 4.0 DTD used by this document.
   */
  HTMLDoctype(EDocumentType type = eStrict);

  /** Destructor */
  virtual ~HTMLDoctype();
  //@}
  
  virtual void render(ostream& out) const;
  
private:
  EDocumentType fType;
};

// ============================================================
// Class HTTPCookie
// ============================================================
/**
 * An HTTP cookie. 
 * <P>Use this like any other \Ref{MStreamable} object. For example, to set an 
 * HTTP cookie:</P>
 * <PRE class="code">
 *  out << HTTPCookie("count","1");
 * </PRE>
 */
class HTTPCookie : public MStreamable {
public:
  /**@name Constructors */
  //@{

  /**
   * Create a new HTTPCookie.
   * @param name The name of the cookie (required).
   * @param value The value of the cookie (required).
   * @param expires The expiration date of the cookie in the form of
   * Wdy, DD-Mon-YYYY HH:MM:SS GMT. If NULL the cookie will expire 
   * as soon as the session ends.
   * @param path The subset of URLS in a domain for which the cookie is 
   * valid, for example "/", or NULL.
   * @param domain The domain for this cookie- NULL will use the hostname 
   * of the server which generated the cookie response. If specified, 
   * the domain <EM>must</EM> contain at least two periods('.'). 
   * @param secure Specifies whether this is a secure cookie.
   */
  HTTPCookie(const char *name, 
	     const char *value, 
	     const char *expires = NULL, 
	     const char *path = NULL,
	     const char *domain = NULL, 
	     bool secure = false) throw(Exception);

  /**
   * Copy constructor.
   * @param cookie The HTTPCookie to copy.
   */
  HTTPCookie(const HTTPCookie& cookie);

  /** Destructor */
  virtual ~HTTPCookie();
  //@}

  /**@name Accessor Functions */
  //@{

  /**
   * Get the name of this cookie.
   * @return The name of this cookie.
   */
  inline const char* getName() const 	{ return fName; }

  /**
   * Get the value of this cookie.
   * @return The value of this cookie.
   */
  inline const char* getValue() const 	{ return fValue; }

  /**
   * Get the expiration date of this cookie, if any.
   * @return The expiration date of this cookie, or NULL if none.
   */
  inline const char* getExpires() const { return fExpires; }

  /**
   * Get the path of this cookie.
   * @return The path of this cookie, or NULL if none.
   */
  inline const char* getPath() const 	{ return fPath; }

  /**
   * Get the domain of this cookie.
   * @return The domain of this cookie, or NULL if none.
   */
  inline const char* getDomain() const 	{ return fDomain; }

  /**
   * Determine if this is a secure cookie.
   * @return True if this cookie is secure, false if not.
   */
  inline bool isSecure() const 		{ return fSecure; }
  //@}  

  /**@name Mutator Functions */
  //@{

  /**
   * Set the name of this cookie.
   * @param name The name of this cookie.
   * @exception Exception
   */
  void setName(const char *name) 	throw(Exception);

  /**
   * Set the value of this cookie.
   * @param value The value of this cookie.
   * @exception Exception
   */
  void setValue(const char *value) 	throw(Exception);

  /**
   * Set the expiration date of this cookie.
   * @param expires The expiration date of this cookie, in the form 
   * Wdy, DD-Mon-YYYY HH:MM:SS GMT.
   * @exception Exception
   */
  void setExpires(const char *expires) 	throw(Exception);

  /**
   * Set the path of this cookie.
   * @param path The path of this cookie.
   * @exception Exception
   */
  void setPath(const char *path) 	throw(Exception);

  /**
   * Set the domain of this cookie.
   * @param domain The domain of this cookie.
   * @exception Exception
   */
  void setDomain(const char *domain) 	throw(Exception);

  /**
   * Mark this cookie as secure or unsecure.
   * @param secure Whether this is a secure cookie.
   */
  void setSecure(bool secure);
  //@}

  virtual void render(ostream& out) const;

private:
  HTTPCookie() {}
  void set(char* &attr, const char *value) throw(Exception);
  
  char *fName;
  char *fValue;
  char *fExpires;
  char *fPath;
  char *fDomain;
  bool fSecure;
};

// ============================================================
// Class HTTPHeader
// ============================================================
/** Abstract base class for all HTTP headers. */
class HTTPHeader : public MStreamable {
public:
  /**@name Constructors */
  //@{
  
  /**
   * Constructor.
   * @param data The header data.  May be NULL.
   * @exception Exception
   */
  HTTPHeader(const char *data = NULL) throw(Exception);

  /**
   * Copy constructor.
   * @param header The HTTPHeader to copy.
   */
  HTTPHeader(const HTTPHeader& header);

  /** Destructor */
  virtual ~HTTPHeader();
  //@}

  /**@name Header data */
  //@{

  /**
   * Get the data contained in this HTTP header.
   * @return The data contained in this header.
   */
  inline const char* getData() const { return fData; }

  /**
   * Set the data contained in this HTTP header.
   * @param data The header data.
   * @exception Exception
   */
  void setData(const char *data) throw(Exception);
  //@}
  
  virtual void render(ostream& out) const = 0;
  
private:
  char *fData;
};

// ============================================================
// Class HTTPContentHeader
// ============================================================
/** HTTP header for data of a specified MIME type. */
class HTTPContentHeader : public HTTPHeader {
public:
  /**
   * Create a new MIME type header.
   * @param mimeType The MIME type of the data which will be sent.
   * @exception Exception
   */
  HTTPContentHeader(const char *mimeType) throw(Exception);

  /** Destructor */
  virtual ~HTTPContentHeader();

  virtual void render(ostream& out) const;
  
private:
  HTTPContentHeader() throw(Exception) {}
};

// ============================================================
// Class HTTPRedirectHeader
// ============================================================
/** HTTP Redirection Header */
class HTTPRedirectHeader : public HTTPHeader {
public:
  /**
   * Create a new redirection header.
   * @param url The redirection URL.
   * @exception Exception
   */
  HTTPRedirectHeader(const char *url) throw(Exception);

  /** Destructor */
  virtual ~HTTPRedirectHeader();
  
  virtual void render(ostream& out) const;
  
private:
  HTTPRedirectHeader() throw(Exception) {}
};

// ============================================================
// Class HTTPStatusHeader
// ============================================================
/** HTTP Status Header */
class HTTPStatusHeader : public HTTPHeader {
public:
  /**@name Constructors */
  //@{
  /**
   * Create a new status header.
   * @param status The 3-digit status code, for example 404.
   * @param message The message associated with the status code, for example
   * "not found".
   * @exception Exception
   */
  HTTPStatusHeader(int status, 
		   const char *message) throw(Exception);

  /** Destructor */
  virtual ~HTTPStatusHeader();
  //@}

  /**@name Accessor Methods */
  //@{
  /**
   * Get the status code associated with this header.
   * @return The 3-digit status code of this header.
   */
  inline int getStatusCode() const { return fStatus; }
  //@}

  /**@name Mutator Methods */
  //@{
  /**
   * Set the 3-digit status code of this header.
   * @param status The 3-digit status code.
   */
  inline void setStatusCode(int status) { fStatus = status; }
  //@}
  
  virtual void render(ostream& out) const;
  
private:
  HTTPStatusHeader() throw(Exception);
  int fStatus;
};

// ============================================================
// Class HTTPNPHeader
// ============================================================
/** HTTP No-parse Header */
class HTTPNPHeader : public HTTPHeader {
public:
  /**
   * Create a new No-parse header.
   * @exception Exception
   */
  HTTPNPHeader() throw(Exception);

  /** Destructor */
  virtual ~HTTPNPHeader();
  
  virtual void render(ostream& out) const;
};

// ============================================================
// Class HTTPHTMLHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "text/html" */
class HTTPHTMLHeader : public HTTPContentHeader {
public:
  /**
   * Create a new "text/html" header.
   * @exception Exception
   */
  HTTPHTMLHeader() throw(Exception);
  virtual ~HTTPHTMLHeader();
};

// ============================================================
// Class HTTPPlainHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "text/plain" */
class HTTPPlainHeader : public HTTPContentHeader {
public:
  /**
   * Create a new "text/plain" header.
   * @exception Exception
   */
  HTTPPlainHeader() throw(Exception);

  /** Destructor */
  virtual ~HTTPPlainHeader();
};

// ============================================================
// Class HTTPGIFHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "image/gif" */
class HTTPGIFHeader : public HTTPContentHeader {
public:
  /**
   * Create a new "image/gif" header.
   * @exception Exception
   */
  HTTPGIFHeader() throw(Exception);

  /** Destructor */
  virtual ~HTTPGIFHeader();
};

// ============================================================
// Class HTTPJPEGHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "image/jpeg" */
class HTTPJPEGHeader : public HTTPContentHeader {
public:
  /**
   * Create a new "image/jpeg" header.
   * @exception Exception
   */
  HTTPJPEGHeader() throw(Exception);

  /** Destructor */
  virtual ~HTTPJPEGHeader();
};

// ============================================================
// Class HTTPXBMHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "image/x-xbitmap" */
class HTTPXBMHeader : public HTTPContentHeader {
public:
  /**
   * Create a new "image/x-xbitmap" header.
   * @exception Exception
   */
  HTTPXBMHeader() throw(Exception);

  /** Destructor */
  virtual ~HTTPXBMHeader();
};

// ============================================================
// Class HTTPAudioHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "audio/basic" */
class HTTPAudioHeader : public HTTPContentHeader {
public:
  /**
   * Create a new "audio/basic" header.
   * @exception Exception
   */
  HTTPAudioHeader() throw(Exception);

  /** Destructor */
  virtual ~HTTPAudioHeader();
};

#endif
