/*
 *  $Id: yourSource.cpp,v 1.4 2000/10/15 15:52:27 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999, 2000 Stephen F. Booth
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <exception>
#include <iostream>

#include "cgicc/Cgicc.h"
#include "cgicc/HTMLClasses.h"

// To use the debug logging feature, the variable gLogFile MUST be
// defined, and it _must_ be an ofstream
#if DEBUG
  ofstream gLogFile( "/change_this_path/cgicc.log", ios::app );
#endif

#if CGICC_USE_NAMESPACES
  using namespace std;
  using namespace cgicc;
#else
#  define div div_
#  define select select_
#endif

int
main(int argc, 
     char **argv)
{
  try {
    Cgicc cgi;
    
    // Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
    cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
    cout << html().set("lang", "EN").set("dir", "LTR") << endl;

    // Set up the page's header and title.
    cout << head() << endl;
    cout << title() << "GNU cgicc v" << cgi.getVersion() << title() << endl;
    cout << head() << endl;
    
    // Start the HTML body
    cout << body() << endl;

    // Print out a message
    cout << h1("Hello, world from GNU cgicc") << endl;

    // Close the document
    cout << body() << html();
  }
  
  catch(const exception& e) {
    // handle error condition
  }
  
  return 0;
}
