/* -*-c++-*- */
/*
 *  $Id: HTTPHeaders.h,v 1.5 2001/09/03 16:16:48 sbooth Exp $
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

#ifndef _HTTPHEADERS_H_
#define _HTTPHEADERS_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file HTTPHeaders.h
 * \brief Classes dealing with HTTP headers
 * 
 * These classes are used to tell the client what type of response it
 * is receiving.
 */

#include <string>

#include "cgicc/MStreamable.h"
#include "cgicc/CgiDefs.h"
#include "cgicc/HTTPCookie.h"

CGICC_BEGIN_NAMESPACE
  
// ============================================================
// Class HTMLDoctype
// ============================================================
/** 
 * Specifies the DTD of the HTML 4 document.
 * <p>To use this class, simply write an object of this type to an ostream:
 * <br /><pre class="code">
 * . out << HTMLDoctype();
 * </pre>
 * <p>For more information, see <tt>http://www.w3.org/MarkUp/</tt> and 
 * <tt>http://www.w3.org/TR/REC-html40/</tt></p>
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
// Class HTTPHeader
// ============================================================
/** Abstract base class for all HTTP response headers. */
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


  inline HTTPHeader&
  setCookie(const HTTPCookie& cookie)
  { fCookies.push_back(cookie); return *this; }

  inline const STDNS vector<HTTPCookie>&
  getCookies() 					const
  { return fCookies; }

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
  STDNS vector<HTTPCookie> fCookies;
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

// Below here are "advanced" headers that most users won't need

// ============================================================
// Class HTTPResponseHeader
// ============================================================
/*! \class HTTPResponseHeader HTTPHeaders.h cgicc/HTTPHeaders.h
 * \brief Generic HTTP response header
 *
 * This class represents an HTTP response header as defined in
 * section 6 of RFC 2616 (see http://www.w3.org)
 *
 * All HTTP/1.1 reponses consist of an initial status line containing
 * the HTTP version, a 3-digit status code, and a human-readable reason
 * phrase explaining the status code.
 *
 * The first digit of the Status-Code defines the class of
 * response. The last two digits do not have any categorization
 * role. There are 5 values for the first digit:
 * <ul>
 * <li>1xx: Informational - Request received, continuing process</li>
 * <li>2xx: Success - The action was successfully received,
 understood, and accepted</li>
 * <li>3xx: Redirection - Further action must be taken in order to
 * complete the request</li>
 * <li>4xx: Client Error - The request contains bad syntax or cannot
 * be fulfilled</li>
 * <li>5xx: Server Error - The server failed to fulfill an apparently
 * valid request</li></ul>
 */
class CGICC_API HTTPResponseHeader : public MStreamable
{
public:

  /*! \name Constructor and Destructor */
  //@{

  /*!
   * \brief Constructor
   *
   * Create a new HTTP response header
   * \param http_version The HTTP version string, usually \c HTTP/1.1
   * \param status_code The 3-digit HTTP status code
   * \param reason_phrase A short textual description of the status code
   */
  HTTPResponseHeader(const STDNS string& http_version,
		     int status_code,
		     const STDNS string& reason_phrase);
  
  /*!
   * \brief Destructor 
   *
   * Delete this HTTPResponseHeader
   */
  virtual ~HTTPResponseHeader();
  //@}

  // ============================================================

  /*! \name Additional Header Management */
  //@{

  /*!
   * \brief Add a general, response, or entity header to this one
   * 
   * \param header The text of the header to add
   * \return A reference to this
   */
  inline HTTPResponseHeader&
  addHeader(const STDNS string& header)
  { fHeaders.push_back(header); return *this; }

  /*!
   * \brief Get a list of all additional headers
   *
   * \return A list of all additional headers
   */
  inline const STDNS vector<STDNS string>&
  getHeaders() 					const
  { return fHeaders; }
  //@}

  // ============================================================

  /*! \name Accessor methods 
   * Retrieve information on the header
   */
  //@{

  /*!
   * \brief Get the HTTP version
   *
   * The HTTP version is a string of the form \c HTTP/1.1
   * \return The HTTP version
   */
  inline const STDNS string&
  getHTTPVersion() 				const
  { return fHTTPVersion; }

  /*!
   * \brief Get the 3-digit status code
   *
   * The 3-digit status code indicates the disposition of the response.
   * \return The 3-digit status code
   */
  inline int
  getStatusCode() 				const
  { return fStatusCode; }

  /*!
   * \brief Get the reason phrase associated with the stats code
   *
   * The reason phrase is a human-readable interpretation of the status code
   * \return The reason phrase
   */
  inline const STDNS string&
  getReasonPhrase() 				const
  { return fReasonPhrase; }
  //@}

  // ============================================================

  /*! \name Mutator methods 
   * Set information on the header
   */
  //@{

  /*!
   * \brief Set the HTTP version
   *
   * The HTTP version is a string of the form \c HTTP/1.1
   * \param http_version The HTTP version string, usually \c HTTP/1.1
   * \return A reference to this
   */
  inline HTTPResponseHeader&
  getHTTPVersion(const STDNS string& http_version)
  { fHTTPVersion = http_version; return *this; }

  /*!
   * \brief Get the 3-digit status code
   *
   * The 3-digit status code indicates the disposition of the response.
   * \param status_code The 3-digit HTTP status code
   * \return A reference to this
   */
  inline HTTPResponseHeader&
  getStatusCode(int status_code)
  { fStatusCode = status_code; return *this; }

  /*!
   * \brief Get the reason phrase associated with the stats code
   *
   * The reason phrase is a human-readable interpretation of the status code
   * \param reason_phrase A short textual description of the status code
   * \return A reference to this
   */
  inline HTTPResponseHeader&
  getReasonPhrase(const STDNS string& reason_phrase)
  { fReasonPhrase = reason_phrase; return *this; }
  //@}

  // ============================================================

  /*! \name Inherited Methods */
  //@{
  virtual void 
  render(STDNS ostream& out) 			const;
  //@}

private:
  HTTPResponseHeader();

  STDNS string fHTTPVersion;
  int fStatusCode;
  STDNS string fReasonPhrase;

  STDNS vector<STDNS string> fHeaders;
};

// ============================================================
// Class HTTPNPHeader
// ============================================================
/*! \class HTTPNPHeader HTTPHeaders.h cgicc/HTTPHeaders.h
 * \brief HTTP No-parse Header 
 *
 * The presence of this header indicates that the server will
 * <strong>not</strong> process the data sent from the CGI in any way.
 */
class CGICC_API HTTPNPHeader : public HTTPResponseHeader 
{
public:

  /*! \name Constructor and Destructor */
  //@{

  /*!
   * \brief Constructor
   *
   * Create a new No-parse header 
   */
  HTTPNPHeader();
    
  /*! 
   * \brief Destructor 
   *
   * Delete this HTTPNPHeader
   */
  virtual ~HTTPNPHeader();
  //@}
};
  
CGICC_END_NAMESPACE

#endif /* ! _HTTPHEADERS_H_ */
