/* -*-c++-*- */
/*
 *  $Id: HTTPPlainHeader.h,v 1.2 2002/03/06 02:49:55 sbooth Exp $
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

#ifndef _HTTPPLAINHEADER_H_
#define _HTTPPLAINHEADER_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file HTTPPlainHeader.h
 * \brief Shortcut to HTTPContentHeader for \c text/plain
 * 
 */

#include <string>

#include "cgicc/HTTPContentHeader.h"

CGICC_BEGIN_NAMESPACE
  
// ============================================================
// Class HTTPPlainHeader
// ============================================================
/*! \class HTTPPlainHeader HTTPPlainHeader.h cgicc/HTTPPlainHeader.h
 * \brief Shortcut to HTTPContentHeader for \c text/html
 *
 */
class CGICC_API HTTPPlainHeader : public HTTPContentHeader 
{
public:
  /*! \brief Create a new \c text/plain header  */
  HTTPPlainHeader();

  /*! \brief Destructor */
  virtual ~HTTPPlainHeader();
};

CGICC_END_NAMESPACE

#endif /* ! _HTTPPLAINHEADER_H_ */
