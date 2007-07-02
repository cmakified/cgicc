/* -*-mode:c++; c-file-style: "gnu";-*- */
/*
 *  $Id: HTTPRedirectHeader.h,v 1.7 2007/07/02 18:48:19 sebdiaz Exp $
 *
 *  Copyright (C) 1996 - 2004 Stephen F. Booth <sbooth@gnu.org>
 *                       2007 Sebastien DIAZ <sebastien.diaz@gmail.com>
 *  Part of the GNU cgicc library, http://www.gnu.org/software/cgicc
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 3 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA 
 */

#ifndef _HTTPREDIRECTHEADER_H_
#define _HTTPREDIRECTHEADER_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file HTTPRedirectHeader.h
 * \brief Class for redirecting the client to a different URI
 * 
 */

#include <string>

#include "cgicc/HTTPHeader.h"

namespace cgicc {
  
  // ============================================================
  // Class HTTPRedirectHeader
  // ============================================================
  
  /*! \class HTTPRedirectHeader HTTPRedirectHeader.h cgicc/HTTPRedirectHeader.h
   * \brief Class for redirecting the client to a different URI
   *
   */
  class CGICC_API HTTPRedirectHeader : public HTTPHeader 
  {
  public:
    
    /*! \name Constructor and Destructor */
    //@{
    
    /*!
     * \brief Create a new redirection header.
     * \param url The redirection URL.
     */
    HTTPRedirectHeader(const std::string& url);
    
    /*! 
     * \brief Destructor 
     *
     */
    virtual ~HTTPRedirectHeader();
    //@}
    
    // ============================================================
    
    /*! \name Inherited Methods */
    //@{ 
    virtual void 
    render(std::ostream& out) 			const;
    //@}
    
  private:
    HTTPRedirectHeader();
  };
  
} // namespace cgicc

#endif /* ! _HTTPREDIRECTHEADER_H_ */
