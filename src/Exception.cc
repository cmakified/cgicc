/*
 *  $Id: Exception.cc,v 1.4 1998/12/09 00:48:39 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Exception.hh"

// ============================================================
// Class Exception
// ============================================================
Exception::Exception()
  : fMessage("An exception was thrown."), fFile(__FILE__), fLine(__LINE__)
{}

Exception::Exception(char *msg)
  : fMessage(msg), fFile(__FILE__), fLine(__LINE__)
{}

Exception::Exception(char *msg, 
		     char *file, 
		     int line)
  : fMessage(msg), fFile(file), fLine(line)
{}

Exception::~Exception()
{}
