/*
 *  $Id: HTTPHeader.cpp,v 1.3 2002/12/04 17:04:07 sbooth Exp $
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

#ifdef __GNUG__
#  pragma implementation
#endif

#include "cgicc/HTTPHeader.h"

// ============================================================
// Class HTTPHeader
// ============================================================
cgicc::HTTPHeader::HTTPHeader()
{
  fCookies.reserve(5);
}

cgicc::HTTPHeader::HTTPHeader(const std::string& data)
  : fData(data)
{
  fCookies.reserve(5);
}

cgicc::HTTPHeader::HTTPHeader(const HTTPHeader& header)
  : MStreamable(),
    fData(header.getData()),
    fCookies(header.getCookies())
{}

cgicc::HTTPHeader::~HTTPHeader()
{}
