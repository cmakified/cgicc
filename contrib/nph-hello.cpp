/*
 * $Id: nph-hello.cpp,v 1.5 2003/07/13 14:21:58 sbooth Exp $ 
 *
 *  Copyright (C) 1996 - 2003 Stephen F. Booth
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
 *
 */

#include <exception>
#include <iostream>
#include <ctime>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPResponseHeader.h"
#include "cgicc/HTMLClasses.h"

#if HAVE_SYS_TIME_H
#  include <sys/time.h>
#endif

// To use the debug logging feature, the variable gLogFile MUST be
// defined, and it _must_ be an ofstream
#if DEBUG
  std::ofstream gLogFile( "/change_this_path/cgicc.log", std::ios::app );
#endif

using namespace std;
using namespace cgicc;

extern char **environ;

int
main(int /*argc*/, 
     char ** /*argv*/)
{
  try {
    Cgicc cgi;

    // Get the current time in the format Sun, 06 Nov 1994 08:49:37 GMT
    char current_date [30];
    time_t now = time(&now);
    strftime(current_date, 30, "%a, %d %b %Y %H:%M:%S GMT", gmtime(&now));

    // Build our own server string
    string server_string("GNU cgicc/");
    server_string += cgi.getVersion();

    // Tell the server not to parse our headers
    cout << HTTPResponseHeader("HTTP/1.1", 200, "OK")
      .addHeader("Date", current_date)
      .addHeader("Server", server_string)
      .addHeader("Content-Language", "en")
      .addHeader("Content-Type", "text/html");

    cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    
    cout << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"DTD/xhtml1-strict.dtd\">" << endl;
    cout << "<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\" lang=\"en\">" << endl;

    cout << "<head>" << endl;

    // Output the style sheet portion of the header
    cout << "<style><!-- " << endl;
    cout << "   body { color: black; background-color: white; }" << endl;
    cout << "   span.red { color: red; }" << endl;
    cout << " --></style>" << endl;

    cout << "<title>GNU cgicc v" << cgi.getVersion() << "</title>" << endl;
    cout << "</head>" << endl;

    cout << "<body>" << endl;
    cout << "<h1>Hello, world from GNU cgi<span class=\"red\">cc</span> v";
    cout << cgi.getVersion() << "</h1>" << endl;
    cout << "</body></html>" << endl;
  }
  
  catch(const exception& e) {
    // handle error condition
  }
  
  return 0;
}
