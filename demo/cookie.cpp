/*
 *  $Id: cookie.cpp,v 1.6 2004/06/28 00:25:30 sbooth Exp $
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
 */

/*! \file cookie.cpp
 * \brief HTTP cookie demo
 *
 * Tests and demonstrates how to use the HTTPCookie class
 */

#include <new>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#if HAVE_SYS_UTSNAME_H
#  include <sys/utsname.h>
#endif

#if HAVE_SYS_TIME_H
#  include <sys/time.h>
#endif

using namespace std;
using namespace cgicc;

// Main Street, USA
int
main(int /*argc*/, 
     char ** /*argv*/)
{
  try {
#if HAVE_GETTIMEOFDAY
    timeval start;
    gettimeofday(&start, NULL);
#endif

    // Create a new Cgicc object containing all the CGI data
    Cgicc cgi;

    // Get the name and value of the cookie to set
    const_form_iterator name = cgi.getElement("name");
    const_form_iterator value = cgi.getElement("value");

    // Output the headers for an HTML document with the cookie only
    // if the cookie is not empty
    if(name != cgi.getElements().end() && value != cgi.getElements().end()
       && value->getValue().empty() == false)
      cout << HTTPHTMLHeader()
	.setCookie(HTTPCookie(name->getValue(), value->getValue()));
    else
      cout << HTTPHTMLHeader();
    
    // Output the HTML 4.0 DTD info
    cout << HTMLDoctype(HTMLDoctype::eStrict) << endl;
    cout << html().set("lang", "en").set("dir", "ltr") << endl;

    // Set up the page's header and title.
    // I will put in lfs to ease reading of the produced HTML. 
    cout << head() << endl;

    // Output the style sheet portion of the header
    cout << style() << comment() << endl;
    cout << "body { color: black; background-color: white; }" << endl;
    cout << "hr.half { width: 60%; align: center; }" << endl;
    cout << "span.red, strong.red { color: red; }" << endl;
    cout << "div.smaller { font-size: small; }" << endl;
    cout << "div.notice { border: solid thin; padding: 1em; margin: 1em 0; "
	 << "background: #ddd; }" << endl;
    cout << "span.blue { color: blue; }" << endl;
    cout << "col.title { color: white; background-color: black; ";
    cout << "font-weight: bold; text-align: center; }" << endl;
    cout << "col.data { background-color: #ddd; text-align: left; }" << endl;
    cout << "td.data, TR.data { background-color: #ddd; text-align: left; }"
	 << endl;
    cout << "td.grayspecial { background-color: #ddd; text-align: left; }"
	 << endl;
    cout << "td.ltgray, tr.ltgray { background-color: #ddd; }" << endl;
    cout << "td.dkgray, tr.dkgray { background-color: #bbb; }" << endl;
    cout << "col.black, td.black, td.title, tr.title { color: white; " 
	 << "background-color: black; font-weight: bold; text-align: center; }"
	 << endl;
    cout << "col.gray, td.gray { background-color: #ddd; text-align: center; }"
	 << endl;
    cout << "table.cgi { left-margin: auto; right-margin: auto; width: 90%; }"
	 << endl;

    cout << comment() << style() << endl;

    cout << title() << "GNU cgicc v" << cgi.getVersion() 
	 << " HTTPCookie Results" << title() << endl;

    cout << head() << endl;
    
    // Start the HTML body
    cout << body() << endl;

    cout << h1() << "GNU cgi" << span("cc").set("class","red")
	 << " v"<< cgi.getVersion() << " HTTPCookie Test Results" 
	 << h1() << endl;
    
    // Get a pointer to the environment
    const CgiEnvironment& env = cgi.getEnvironment();
    
    // Generic thank you message
    cout << comment() << "This page generated by cgicc for "
	 << env.getRemoteHost() << comment() << endl;
    cout << h4() << "Thanks for using cgi" << span("cc").set("class", "red") 
	 << ", " << env.getRemoteHost() 
	 << '(' << env.getRemoteAddr() << ")!" << h4() << endl;  
    
    if(name != cgi.getElements().end() && value != cgi.getElements().end()
       && value->getValue().empty() == false) {
      cout << p() << "A cookie with the name " << em(name->getValue())
	   << " and value " << em(value->getValue()) << " was set." << br();
      cout << "In order for the cookie to show up here you must "
	   << a("refresh").set("href",env.getScriptName()) << p();
    }

    // Show the cookie info from the environment
    cout << h2("Cookie Information from the Environment") << endl;
  
    cout << cgicc::div().set("align","center") << endl;
    
    cout << table().set("border","0").set("rules","none").set("frame","void")
      .set("cellspacing","2").set("cellpadding","2")
      .set("class","cgi") << endl;
    cout << colgroup().set("span","2") << endl;
    cout << col().set("align","center").set("class","title").set("span","1") 
	 << endl;
    cout << col().set("align","left").set("class","data").set("span","1") 
	 << endl;
    cout << colgroup() << endl;
    
    cout << tr() << td("HTTPCookie").set("class","title")
	 << td(env.getCookies()).set("class","data") << tr() << endl;
    
    cout << table() << cgicc::div() << endl;


    // Show the cookie info from the cookie list
    cout << h2("HTTP Cookies via vector") << endl;
  
    cout << cgicc::div().set("align","center") << endl;
  
    cout << table().set("border","0").set("rules","none").set("frame","void")
      .set("cellspacing","2").set("cellpadding","2")
      .set("class","cgi") << endl;
    cout << colgroup().set("span","2") << endl;
    cout << col().set("align","center").set("span","2") << endl;
    cout << colgroup() << endl;
    
    cout << tr().set("class","title") << td("Cookie Name") 
	 << td("Cookie Value") << tr() << endl;
    
    // Iterate through the vector, and print out each value
    const_cookie_iterator iter;
    for(iter = env.getCookieList().begin(); 
	iter != env.getCookieList().end(); 
	++iter) {
      cout << tr().set("class","data") << td(iter->getName()) 
	   << td(iter->getValue()) << tr() << endl;
    }
    cout << table() << cgicc::div() << endl;
    

    // Now print out a footer with some fun info
    cout << p() << cgicc::div().set("align","center");
    cout << a("Back to form").set("href", cgi.getEnvironment().getReferrer()) 
	 << endl;
    cout << cgicc::div() << br() << hr(set("class","half")) << endl;
    
    // Information on cgicc
    cout << cgicc::div().set("align","center").set("class","smaller") << endl;
    cout << "GNU cgi" << span("cc").set("class","red") << " v";
    cout << cgi.getVersion() << br() << endl;
    cout << "Compiled at " << cgi.getCompileTime();
    cout << " on " << cgi.getCompileDate() << br() << endl;

    cout << "Configured for " << cgi.getHost();  
#if HAVE_UNAME
    struct utsname info;
    if(uname(&info) != -1) {
      cout << ". Running on " << info.sysname;
      cout << ' ' << info.release << " (";
      cout << info.nodename << ")." << endl;
    }
#else
    cout << "." << endl;
#endif

#if HAVE_GETTIMEOFDAY
    // Information on this query
    timeval end;
    gettimeofday(&end, NULL);
    long us = ((end.tv_sec - start.tv_sec) * 1000000)
      + (end.tv_usec - start.tv_usec);

    cout << br() << "Total time for request = " << us << " us";
    cout << " (" << static_cast<double>(us/1000000.0) << " s)";
#endif

    // End of document
    cout << cgicc::div() << endl;
    cout << body() << html() << endl;

    // No chance for failure in this example
    return EXIT_SUCCESS;
  }

  // Did any errors occur?
  catch(const std::exception& e) {

    // This is a dummy exception handler, as it doesn't really do
    // anything except print out information.

    // Reset all the HTML elements that might have been used to 
    // their initial state so we get valid output
    html::reset(); 	head::reset(); 		body::reset();
    title::reset(); 	h1::reset(); 		h4::reset();
    comment::reset(); 	td::reset(); 		tr::reset(); 
    table::reset();	cgicc::div::reset(); 	p::reset(); 
    a::reset();		h2::reset(); 		colgroup::reset();

    // Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
    cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
    cout << html().set("lang","en").set("dir","ltr") << endl;

    // Set up the page's header and title.
    // I will put in lfs to ease reading of the produced HTML. 
    cout << head() << endl;

    // Output the style sheet portion of the header
    cout << style() << comment() << endl;
    cout << "body { color: black; background-color: white; }" << endl;
    cout << "hr.half { width: 60%; align: center; }" << endl;
    cout << "span.red, strong.red { color: red; }" << endl;
    cout << "div.notice { border: solid thin; padding: 1em; margin: 1em 0; "
	 << "background: #ddd; }" << endl;

    cout << comment() << style() << endl;

    cout << title("GNU cgicc exception") << endl;
    cout << head() << endl;
    
    cout << body() << endl;
    
    cout << h1() << "GNU cgi" << span("cc", set("class","red"))
	 << " caught an exception" << h1() << endl; 
  
    cout << cgicc::div().set("align","center").set("class","notice") << endl;

    cout << h2(e.what()) << endl;

    // End of document
    cout << cgicc::div() << endl;
    cout << hr().set("class","half") << endl;
    cout << body() << html() << endl;
    
    return EXIT_SUCCESS;
  }
}
