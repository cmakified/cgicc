/* -*-c++-*- */
/*
 *  $Id: HTTPContentHeader.h,v 1.2 2002/03/06 02:49:55 sbooth Exp $
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

#ifndef _HTTPCONTENTHEADER_H_
#define _HTTPCONTENTHEADER_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file HTTPContentHeader.h
 * \brief Class for sending data of a specific MIME type
 * 
 */

#include <string>

#include "cgicc/HTTPHeader.h"

CGICC_BEGIN_NAMESPACE
  
// ============================================================
// Class HTTPContentHeader
// ============================================================
/*! \class HTTPContentHeader HTTPContentHeader.h cgicc/HTTPContentHeader.h
 * \brief HTTP header for data of a specified MIME type. 
 *
 */
class CGICC_API HTTPContentHeader : public HTTPHeader 
{
public:

  /*! \name Constructor and Destructor */
  //@{

  /*!
   * \brief Create a new MIME type header.
   * \param mimeType The MIME type of the data which will be sent.
   */
  HTTPContentHeader(const STDNS string& mimeType);
    
  /*!
   * \brief Destructor 
   *
   */
  virtual ~HTTPContentHeader();
  //@}

  /*! \name Inherited Methods */
  //@{ 
  virtual void 
  render(STDNS ostream& out) 			const;
  //@}

private:
  HTTPContentHeader();
};
  
CGICC_END_NAMESPACE

#endif /* ! _HTTPCONTENTHEADER_H_ */
