/*
 * $Id: fcgi-test.cpp,v 1.3 2003/07/13 14:21:58 sbooth Exp $ 
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

#include <unistd.h>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include "FCgiIO.h"

// To use the debug logging feature, the variable gLogFile MUST be
// defined, and it _must_ be an ofstream
#if DEBUG
  std::ofstream gLogFile( "/change_this_path/cgicc.log", std::ios::app );
#endif

using namespace std;
using namespace cgicc;

int 
main(int /*argc*/, 
     const char **/*argv*/, 
     char **/*envp*/)
{
  unsigned count = 0;

  FCGX_Request request;

  FCGX_Init();
  FCGX_InitRequest(&request, 0, 0);

  while(FCGX_Accept_r(&request) == 0) {

    try {
      FCgiIO IO(request);
      Cgicc CGI(&IO);

      // Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
      IO << HTTPHTMLHeader() << HTMLDoctype( HTMLDoctype::eStrict ) << endl
         << html().set( "lang", "en" ).set( "dir", "ltr" ) << endl;

      // Set up the page's header and title.
      IO << head() << endl
         << title() << "GNU cgicc v" << CGI.getVersion() << title() << endl
         << head() << endl;

      // Start the HTML body
      IO << body() << endl;

      // Print out a message
      IO << h1("Cgicc/FastCGI Test") << endl
         << "PID: " << getpid() << br() << endl
         << "count: " << count++ << br() << endl;

      IO  << "Form Elements:" << br() << endl;

      for(const_form_iterator i = CGI.getElements().begin(); 
	  i != CGI.getElements().end(); ++i )
        IO << i->getName() << " = " << i->getValue() << br() << endl;

      // Close the document
      IO << body() << html();
    }
    catch(const exception&) {
      // handle error condition
    }

    FCGX_Finish_r(&request);
  }

  return 0;
}
