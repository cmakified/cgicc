/*
 *  $Id: CgiInput.cpp,v 1.2 2002/03/03 17:39:52 sbooth Exp $
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

#include <iostream>
#include <cstdlib>

#include "cgicc/CgiInput.h"

// ========== Destructor

CGICCNS CgiInput::~CgiInput()
{}

// ========== Members

size_t 
CGICCNS CgiInput::read(char *data, 
		       size_t length)
{
  STDNS cin.read(data, length);
  return STDNS cin.gcount();
}

STDNS string
CGICCNS CgiInput::getenv(const char *varName)
{
  char *var = STDNS getenv(varName);
  return (var == 0) ? "" : var;
}
