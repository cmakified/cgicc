/*
 * $Id: example.cpp,v 1.6 2002/12/04 17:04:07 sbooth Exp $ 
 *
 * Skeleton of a CGI application written using the GNU cgicc library
 */

#include <exception>
#include <iostream>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

// To use the debug logging feature, the variable gLogFile MUST be
// defined, and it _must_ be an ofstream
#if DEBUG
  ofstream gLogFile( "/change_this_path/cgicc.log", ios::app );
#endif

using namespace std;
using namespace cgicc;

int
main(int argc, 
     char **argv)
{
  try {
    Cgicc cgi;
    
    // Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
    cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
    cout << html().set("lang", "en").set("dir", "ltr") << endl;

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
