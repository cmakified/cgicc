/*
 *  $Id: yourSource.cc,v 1.1 1999/01/05 22:48:05 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999 Stephen F. Booth
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

#include "HTMLClasses.hh"
#include "Cgicc.hh"
#include "Exception.hh"

// To use logging, the variable gLogFile MUST be defined, and it _must_
// be an ofstream
#if DEBUG
ofstream gLogFile( "/change_this_path/Cgicc.log", ios::app );
#endif

#include <stdlib.h>

int
main(int argc, char **argv)
{
  try {
    Cgicc cgi;
    
  }
  
  catch(const Exception& e) {
    
  }
  
  return EXIT_SUCCESS;
}
