/* -*-c++-*- */
/*
 *  $Id: HTTPHeaders.h,v 1.3 1999/08/16 17:40:05 sbooth Exp $
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

#ifndef _HTTPHEADERS_H_
#define _HTTPHEADERS_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

#include <string>

#include "cgicc/MStreamable.h"
#include "cgicc/CgiDefs.h"

CGICC_BEGIN_NAMESPACE
  
// ============================================================
// Class HTMLDoctype
// ============================================================
/** 
 * Specifies the DTD of the HTML 4 document.
 * <P>To use this class, simply write an object of this type to an ostream:
 * <BR><PRE CLASS="code">
 * . out << HTMLDoctype();
 * </PRE>
 * <P>For more information, see <TT>\URL{http://www.w3.org/MarkUp/}</TT> and 
 * <TT>\URL{http://www.w3.org/TR/REC-html40/}</TT></P>
 */
class CGICC_API HTMLDoctype : public MStreamable 
{
public:
    
  /** The DTD used by this document. */
  enum EDocumentType {
    /** The HTML 4.0 strict DTD */
    eStrict,
    /** The HTML 4.0 Transitional DTD */
    eTransitional,
    /** The HTML 4.0 Frameset DTD */
    eFrames
  };

    
  /**
   * Constructor.
   * @param type The version of the HTML 4.0 DTD used by this document.
   */
  HTMLDoctype(EDocumentType type = eStrict);
    
  /** Destructor */
  virtual ~HTMLDoctype();
    
  virtual void 
  render(STDNS ostream& out) 			const;
    
private:
  EDocumentType fType;
};
  
// ============================================================
// Class HTTPCookie
// ============================================================
/**
 * An HTTP cookie. 
 * <P>Use this like any other \Ref{MStreamable} object. For example, to set 
 * an HTTP cookie:</P>
 * <PRE class="code">
 *  out << HTTPCookie("count","1");
 * </PRE>
 */
class CGICC_API HTTPCookie : public MStreamable 
{
public:

  /** Create a new, empty HTTPCookie. */
  HTTPCookie();
    
  /**
   * Create a new HTTPCookie.
   * @param name The name of the cookie.
   * @param value The value of the cookie.
   */
  HTTPCookie(const STDNS string& name, 
	     const STDNS string& value);
  
  /**
   * Create a new HTTPCookie.
   * @param name The name of the cookie.
   * @param value The value of the cookie.
   * @param comment Any comment associated with the cookie.
   * @param domain The domain for which this cookie is valid- an empty string
   * will use the hostname of the server which generated the cookie response.
   * If specified, the domain <EM>must</EM> start with a period('.'). 
   * @param maxAge A number of seconds defining the lifetime of this cookie.
   * A value of <TT>0</TT> indicates the cookie expires immediately.
   * @param path The subset of URLS in a domain for which the cookie is 
   * valid, for example "/".
   * @param secure Specifies whether this is a secure cookie.
   */
  HTTPCookie(const STDNS string& name, 
	     const STDNS string& value, 
	     const STDNS string& comment, 
	     const STDNS string& domain, 
	     unsigned long maxAge, 
	     const STDNS string& path,
	     bool secure);
    
  /**
   * Copy constructor.
   * @param cookie The HTTPCookie to copy.
   */
  HTTPCookie(const HTTPCookie& cookie);
    
  /** Destructor */
  virtual ~HTTPCookie();



  /** 
   * Compare two HTTPCookies for equality.
   * @param cookie The HTTPCookie to compare to this one
   * @return true if the two HTTPCookies are equal, false otherwise.
   */
  bool 
  operator== (const HTTPCookie& cookie) 	const;

  /** 
   * Compare two HTTPCookies for inequality.
   * @param cookie The HTTPCookie to compare to this one
   * @return false if the two HTTPCookies are equal, true otherwise.
   */
  inline bool 
  operator != (const HTTPCookie& cookie) 	const
  { return ! operator==(cookie); }

#ifdef WIN32
  /** Dummy operator for MSVC++ */
  inline bool 
  operator< (const HTTPCookie& cookie) 		const
  { return false; }
#endif

  /**
   * Get the name of this cookie.
   * @return The name of this cookie.
   */
  inline STDNS string 
  getName() 					const
    { return fName; }
    
  /**
   * Get the value of this cookie.
   * @return The value of this cookie.
   */
  inline STDNS string 
  getValue() 					const
    { return fValue; }

  /**
   * Get the comment of this cookie.
   * @return The comment of this cookie.
   */
  inline STDNS string 
  getComment() 					const
    { return fComment; }
  
  /**
   * Get the domain of this cookie.
   * @return The domain of this cookie, or "" if none.
   */
  inline STDNS string 
  getDomain() 					const
    { return fDomain; }
  
  /**
   * Get the lifetime of this cookie, in seconds.
   * @return The lifetime of this cookie, or 0 if none.
   */
  inline unsigned long
  getMaxAge() 					const
    { return fMaxAge; }
    
  /**
   * Get the path of this cookie.
   * @return The path of this cookie, or "" if none.
   */
  inline STDNS string 
  getPath() 					const
    { return fPath; }
    
  /**
   * Determine if this is a secure cookie.
   * @return True if this cookie is secure, false if not.
   */
  inline bool 
  isSecure() 					const
    { return fSecure; }


  /**
   * Set the name of this cookie.
   * @param name The name of this cookie.
   */
  inline void 
  setName(const STDNS string& name)
    { fName = name; }
    
  /**
   * Set the value of this cookie.
   * @param value The value of this cookie.
   */
  inline void 
  setValue(const STDNS string& value)
    { fValue = value; }
    
  /**
   * Set the comment of this cookie.
   * @param comment The comment of this cookie.
   */
  inline void 
  setComment(const STDNS string& comment)
    { fComment = comment; }
        
  /**
   * Set the domain of this cookie.
   * @param domain The domain of this cookie.
   */
  inline void 
  setDomain(const STDNS string& domain)
    { fDomain = domain; }

  /**
   * Set the lifetime of this cookie, in seconds.
   * @param maxAge The lifetime of this cookie, in seconds. 
   */
  inline void 
  setMaxAge(unsigned long maxAge)
    { fMaxAge = maxAge; }
    
  /**
   * Set the path of this cookie.
   * @param path The path of this cookie.
   */
  inline void 
  setPath(const STDNS string& path)
    { fPath = path; }
    
  /**
   * Mark this cookie as secure or unsecure.
   * @param secure Whether this is a secure cookie.
   */
  inline void 
  setSecure(bool secure)
    { fSecure = secure; }
    

  virtual void 
  render(STDNS ostream& out) 			const;
    
private:
  STDNS string 		fName;
  STDNS string 		fValue;
  STDNS string 		fComment;
  STDNS string 		fDomain;
  unsigned long 	fMaxAge;
  STDNS string 		fPath;
  bool 			fSecure;
};
  
// ============================================================
// Class HTTPHeader
// ============================================================
/** Abstract base class for all HTTP headers. */
class CGICC_API HTTPHeader : public MStreamable 
{
public:
    
  /**
   * Constructor.
   * @param data The header data.
   */
  HTTPHeader(const STDNS string& data);

  /**
   * Copy constructor.
   * @param header The HTTPHeader to copy.
   */
  HTTPHeader(const HTTPHeader& header);
    
  /** Destructor */
  virtual ~HTTPHeader();

    
  /**
   * Get the data contained in this HTTP header.
   * @return The data contained in this header.
   */
  inline STDNS string 
  getData() 					const
    { return fData; }
    
  virtual void 
  render(STDNS ostream& out) 			const = 0;
    
private:
  HTTPHeader();

  STDNS string fData;
};
  
// ============================================================
// Class HTTPContentHeader
// ============================================================
/** HTTP header for data of a specified MIME type. */
class CGICC_API HTTPContentHeader : public HTTPHeader 
{
public:
  /**
   * Create a new MIME type header.
   * @param mimeType The MIME type of the data which will be sent.
   */
  HTTPContentHeader(const STDNS string& mimeType);
    
  /** Destructor */
  virtual ~HTTPContentHeader();
    
  virtual void 
  render(STDNS ostream& out) 			const;
    
private:
  HTTPContentHeader();
};
  
// ============================================================
// Class HTTPRedirectHeader
// ============================================================
/** HTTP Redirection Header */
class CGICC_API HTTPRedirectHeader : public HTTPHeader 
{
public:
  /**
   * Create a new redirection header.
   * @param url The redirection URL.
   */
  HTTPRedirectHeader(const STDNS string& url);
    
  /** Destructor */
  virtual ~HTTPRedirectHeader();
    
  virtual void 
  render(STDNS ostream& out) 			const;
    
private:
  HTTPRedirectHeader();
};
  
// ============================================================
// Class HTTPStatusHeader
// ============================================================
/** HTTP Status Header */
class CGICC_API HTTPStatusHeader : public HTTPHeader 
{
public:
  /**
   * Create a new status header.
   * @param status The 3-digit status code, for example 404.
   * @param message The message associated with the status code, for example
   * "not found".
   */
  HTTPStatusHeader(int status, 
		   const STDNS string& message);
    
  /** Destructor */
  virtual ~HTTPStatusHeader();
    
  /**
   * Get the status code associated with this header.
   * @return The 3-digit status code of this header.
   */
  inline int 
  getStatusCode() 				const
    { return fStatus; }
  
  virtual void 
  render(STDNS ostream& out) 			const;
    
private:
  HTTPStatusHeader();
  int fStatus;
};
  
// ============================================================
// Class HTTPNPHeader
// ============================================================
/** HTTP No-parse Header */
class CGICC_API HTTPNPHeader : public HTTPHeader 
{
public:
  /** Create a new No-parse header */
  HTTPNPHeader();
    
  /** Destructor */
  virtual ~HTTPNPHeader();
    
  virtual void 
  render(STDNS ostream& out) 			const;
};
  
// ============================================================
// Class HTTPHTMLHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "text/html" */
class CGICC_API HTTPHTMLHeader : public HTTPContentHeader 
{
public:
  /** Create a new "text/html" header */
  HTTPHTMLHeader();

  /** Destructor */
  virtual ~HTTPHTMLHeader();
};
  
// ============================================================
// Class HTTPPlainHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "text/plain" */
class CGICC_API HTTPPlainHeader : public HTTPContentHeader 
{
public:
  /** Create a new "text/plain" header */
  HTTPPlainHeader();
    
  /** Destructor */
  virtual ~HTTPPlainHeader();
};
  
// ============================================================
// Class HTTPGIFHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "image/gif" */
class CGICC_API HTTPGIFHeader : public HTTPContentHeader 
{
public:
  /** Create a new "image/gif" header */
  HTTPGIFHeader();
    
  /** Destructor */
  virtual ~HTTPGIFHeader();
};
  
// ============================================================
// Class HTTPJPEGHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "image/jpeg" */
class CGICC_API HTTPJPEGHeader : public HTTPContentHeader 
{
public:
  /** Create a new "image/jpeg" header */
  HTTPJPEGHeader();
    
  /** Destructor */
  virtual ~HTTPJPEGHeader();
};
  
// ============================================================
// Class HTTPXBMHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "image/x-xbitmap" */
class CGICC_API HTTPXBMHeader : public HTTPContentHeader 
{
public:
  /** Create a new "image/x-xbitmap" header */
  HTTPXBMHeader();
    
  /** Destructor */
  virtual ~HTTPXBMHeader();
};
  
// ============================================================
// Class HTTPAudioHeader
// ============================================================
/** Shortcut to HTTPContentHeader for "audio/basic" */
class CGICC_API HTTPAudioHeader : public HTTPContentHeader 
{
public:
  /** Create a new "audio/basic" header */
  HTTPAudioHeader();
    
  /** Destructor */
  virtual ~HTTPAudioHeader();
};
  
CGICC_END_NAMESPACE

#endif /* ! _HTTPHEADERS_H_ */
