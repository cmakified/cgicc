/* -*-c++-*- */
/*
 *  $Id: HTTPHTMLHeader.h,v 1.1 2001/09/03 22:06:39 sbooth Exp $
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

#ifndef _HTTPHTMLHEADER_H_
#define _HTTPHTMLHEADER_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file HTTPHTMLHeader.h
 * \brief Shortcut to HTTPContentHeader for \c text/html
 * 
 */

#include <string>

#include "cgicc/HTTPContentHeader.h"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class HTTPHTMLHeader
// ============================================================
/*! \class HTTPHTMLHeader HTTPHTMLHeader.h cgicc/HTTPHTMLHeader.h
 * \brief Shortcut to HTTPContentHeader for \c text/html
 *
 */
class CGICC_API HTTPHTMLHeader : public HTTPContentHeader 
{
public:

  /*! \name Constructor and Destructor */
  //@{

  /*!
   * \brief Create a new \c text/html header 
   *
   */
  HTTPHTMLHeader();

  /*!
   * \brief Destructor 
   *
   */
  virtual ~HTTPHTMLHeader();
  //@}
};
  
CGICC_END_NAMESPACE

#endif /* ! _HTTPHTMLHEADER_H_ */
