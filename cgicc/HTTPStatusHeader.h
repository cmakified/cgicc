/* -*-c++-*- */
/*
 *  $Id: HTTPStatusHeader.h,v 1.2 2002/03/06 02:49:55 sbooth Exp $
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

#ifndef _HTTPSTATUSHEADER_H_
#define _HTTPSTATUSHEADER_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file HTTPStatusHeader.h
 * \brief HTTP header to set a specific request status
 * 
 */

#include <string>

#include "cgicc/HTTPHeader.h"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class HTTPStatusHeader
// ============================================================

/*! \class HTTPStatusHeader HTTPStatusHeader.h cgicc/HTTPStatusHeader.h
 * \brief HTTP header to set a specific request status
 *
 */
class CGICC_API HTTPStatusHeader : public HTTPHeader 
{
public:

  /*!
   * \brief Create a new status header.
   * \param status The 3-digit status code, for example 404.
   * \param message The message associated with the status code, for example
   * "not found".
   */
  HTTPStatusHeader(int status, 
		   const STDNS string& message);
    
  /*! \brief Destructor */
  virtual ~HTTPStatusHeader();
    
  /*!
   * \brief Get the status code associated with this header.
   * \return The 3-digit status code of this header.
   */
  inline int 
  getStatusCode() 				const
    { return fStatus; }
  

  /*!
   * \brief Write this HTTPStatusHeader to a stream.  
   * \param out The ostream to which to write.
   */
  virtual void 
  render(STDNS ostream& out) 			const;
    
private:
  HTTPStatusHeader();
  int fStatus;
};
  
CGICC_END_NAMESPACE

#endif /* ! _HTTPSTATUSHEADER_H_ */
