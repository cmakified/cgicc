/* -*-c++-*- */
/*
 *  $Id: HTTPRedirectHeader.h,v 1.2 2002/03/06 02:49:55 sbooth Exp $
 *
 *  Copyright (C) 1996 - 2002 Stephen F. Booth
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

CGICC_BEGIN_NAMESPACE
  
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
  HTTPRedirectHeader(const STDNS string& url);
    
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
  render(STDNS ostream& out) 			const;
  //@}
    
private:
  HTTPRedirectHeader();
};

CGICC_END_NAMESPACE

#endif /* ! _HTTPREDIRECTHEADER_H_ */
