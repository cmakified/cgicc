/* -*-c++-*- */
/*
 *  $Id: HTTPNPHeader.h,v 1.1 2001/09/03 22:06:39 sbooth Exp $
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

#ifndef _HTTPNPHEADER_H_
#define _HTTPNPHEADER_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file HTTPNPHeader.h
 * \brief Class for simple, non-parsed header (NPH) scripts
 * 
 * These classes are used to tell the client what type of response it
 * is receiving.
 */

#include <string>

#include "cgicc/HTTPResponseHeader.h"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class HTTPNPHeader
// ============================================================

/*! \class HTTPNPHeader HTTPNPHeader.h cgicc/HTTPNPHeader.h
 * \brief HTTP No-parse Header 
 *
 * The presence of this header indicates that the server will
 * <strong>not</strong> process the data sent from the CGI in any way.
 */
class CGICC_API HTTPNPHeader : public HTTPResponseHeader 
{
public:

  /*! \brief Create a new No-parse header */
  HTTPNPHeader();
    
  /*! \brief Destructor */
  virtual ~HTTPNPHeader();
};
  
CGICC_END_NAMESPACE

#endif /* ! _HTTPNPHEADER_H_ */
