/*
 *  $Id: test.cpp,v 1.19 2002/12/04 17:04:07 sbooth Exp $
 *
 *  Copyright (C) 1996 - 2002 Stephen F. Booth
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

/*! \file test.cpp
 * \brief GNU %cgicc test application
 *
 * Tests and demonstrates access of form data using the GNU %cgicc library.
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

#if HAVE_UNAME
#  include <sys/utsname.h>
#endif

#if HAVE_SYS_TIME_H
#  include <sys/time.h>
#endif

// To use logging, the variable gLogFile MUST be defined, and it _must_
// be an ofstream
#if DEBUG
  std::ofstream gLogFile( "/change_this_path/cgicc.log", std::ios::app );
#endif

using namespace std;
using namespace cgicc;

// Function prototypes
void dumpEnvironment(const CgiEnvironment& env);
void dumpList(const Cgicc& formData);
void showForm(const Cgicc& formData);

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
    
    // If the user wants to throw an exception, go ahead and do it
    if(cgi.queryCheckbox("throw") && ! cgi.queryCheckbox("restore"))
      throw std::runtime_error("User-requested Exception thrown in main()");
    
    // Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
    cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
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
    cout << "col.data { background-color: #DDD; text-align: left; }" << endl;
    cout << "td.data, tr.data { background-color: #ddd; text-align: left; }"
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

    cout << title() << "GNU cgicc v" << cgi.getVersion() << " Test Results" 
	 << title() << endl;

    cout << head() << endl;
    
    // Start the HTML body
    cout << body() << endl;

    cout << h1() << "GNU cgi" << span("cc").set("class","red")
	 << " v"<< cgi.getVersion() << " Test Results" << h1() << endl;
    
    // Get a pointer to the environment
    const CgiEnvironment& env = cgi.getEnvironment();
    
    // Generic thank you message
    cout << comment() << "This page generated by cgicc for "
	 << env.getRemoteHost() << comment() << endl;
    cout << h4() << "Thanks for using cgi" << span("cc").set("class", "red") 
	 << ", " << env.getRemoteHost() 
	 << '(' << env.getRemoteAddr() << ")!" << h4() << endl;  
    
    // If the user wants to save the submission, do it
    if(cgi.queryCheckbox("save")) {
      // Make sure the save file is readable and writable by the CGI process
      cgi.save("save");
      cout << p(h2("Data Saved")) << endl;
      
      cout << cgicc::div().set("class", "notice") << endl;
      cout << "Your data has been saved, and may be restored (by anyone) "
	   << "via the same form." << endl << cgicc::div() << p() << endl;
    }

    // If the user wants to restore from the last submission, do it
    if(cgi.queryCheckbox("restore")) {
      cgi.restore("save");
      cout << p(h2("Data Restored")) << endl;
      
      cout << cgicc::div().set("class", "notice") << endl;
      cout << "The data displayed has been restored from a file on disk."
	   << endl << cgicc::div() << p() << endl;
    }
    
    // If the user requested a dump of the environment,
    // create a simple table showing the values of the 
    // environment variables
    if(cgi.queryCheckbox("showEnv"))
      dumpEnvironment(env);
    
    // If the user requested, print out the raw form data from 
    // the vector of FormEntries.  This will contain every 
    // element in the list.
    // This is one of two ways to get at form data, the other
    // being the use of Cgicc's getElement() methods.  
    if(cgi.queryCheckbox("showFE"))
      dumpList(cgi);
    
    // If the user requested data via Cgicc's getElement() methods, do it.
    // This is different than the use of the list of FormEntries 
    // because it requires prior knowledge of the name of form elements.
    // Usually they will be known, but you never know.
    if(cgi.queryCheckbox("showForm"))
      showForm(cgi);

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
    cout << " (" << (double) (us/1000000.0) << " s)";
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
    cout << "span.red, STRONG.red { color: red; }" << endl;
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

// Print out a table of the CgiEnvironment
void
dumpEnvironment(const CgiEnvironment& env) 
{
  // This is just a brain-dead dump of information.
  // Almost all of this code is for HTML formatting
  cout << h2("Environment information from CgiEnvironment") << endl;
  
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
  
  cout << tr() << td("Request Method").set("class","title") 
       << td(env.getRequestMethod()).set("class","data") << tr() << endl;
  cout << tr() << td("Path Info").set("class","title") 
       << td(env.getPathInfo()).set("class","data") << tr() << endl;
  cout << tr() << td("Path Translated").set("class","title") 
       << td(env.getPathTranslated()).set("class","data") << tr() << endl;
  cout << tr() << td("Script Name").set("class","title") 
       << td(env.getScriptName()).set("class","data") << tr() << endl;
  cout << tr() << td("HTTP Referrer").set("class","title") 
       << td(env.getReferrer()).set("class","data") << tr() << endl;
  cout << tr() << td("HTTP Cookie").set("class","title") 
       << td(env.getCookies()).set("class","data") << tr() << endl;
  cout << tr() << td("Query String").set("class","title") 
       << td(env.getQueryString()).set("class","data") << tr() << endl;
  cout << tr() << td("Content Length").set("class","title") 
       << td().set("class","data") << env.getContentLength() 
       << td() << tr() << endl;
  cout << tr() << td("Post Data").set("class","title")
       << td().set("class","data")
       << pre(env.getPostData()).set("class","data") << td() 
       << tr() << endl;
  cout << tr() << td("Remote Host").set("class","title") 
       << td(env.getRemoteHost()).set("class","data") << tr() << endl;
  cout << tr() << td("Remote Address").set("class","title") 
       << td(env.getRemoteAddr()).set("class","data") << tr() << endl;
  cout << tr() << td("Authorization Type").set("class","title") 
       << td(env.getAuthType()).set("class","data") << tr() << endl;
  cout << tr() << td("Remote User").set("class","title") 
       << td(env.getRemoteUser()).set("class","data") << tr() << endl;
  cout << tr() << td("Remote Identification").set("class","title") 
       << td(env.getRemoteIdent()).set("class","data") << tr() << endl;
  cout << tr() << td("Content Type").set("class","title") 
       << td(env.getContentType()).set("class","data") << tr() << endl;
  cout << tr() << td("HTTP Accept").set("class","title") 
       << td(env.getAccept()).set("class","data") << tr() << endl;
  cout << tr() << td("User Agent").set("class","title") 
       << td(env.getUserAgent()).set("class","data") << tr() << endl;
  cout << tr() << td("Server Software").set("class","title") 
       << td(env.getServerSoftware()).set("class","data") << tr() << endl;
  cout << tr() << td("Server Name").set("class","title") 
       << td(env.getServerName()).set("class","data") << tr() << endl;
  cout << tr() << td("Gateway Interface").set("class","title") 
       << td(env.getGatewayInterface()).set("class","data") << tr() << endl;
  cout << tr() << td("Server Protocol").set("class","title") 
       << td(env.getServerProtocol()).set("class","data") << tr() << endl;
  cout << tr() << td("Server Port").set("class","title") 
       << td().set("class","data") << env.getServerPort() 
       << td() << tr() << endl;
  cout << tr() << td("HTTPS").set("class","title")
       << td().set("class","data") << (env.usingHTTPS() ? "true" : "false")
       << td() << tr() << endl;
  cout << tr() << td("Redirect Request").set("class","title") 
       << td(env.getRedirectRequest()).set("class","data") << tr() << endl;
  cout << tr() << td("Redirect URL").set("class","title") 
       << td(env.getRedirectURL()).set("class","data") << tr() << endl;
  cout << tr() << td("Redirect Status").set("class","title") 
       << td(env.getRedirectStatus()).set("class","data") << tr() << endl;
  
  cout << table() << cgicc::div() << endl;
}

// Print out the value of every form element
void
dumpList(const Cgicc& formData) 
{
  cout << h2("Form Data via vector") << endl;
  
  cout << cgicc::div().set("align","center") << endl;
  
  cout << table().set("border","0").set("rules","none").set("frame","void")
		 .set("cellspacing","2").set("cellpadding","2")
		 .set("class","cgi") << endl;
  cout << colgroup().set("span","2") << endl;
  cout << col().set("align","center").set("span","2") << endl;
  cout << colgroup() << endl;
  
  cout << tr().set("class","title") << td("Element Name") 
       << td("Element Value") << tr() << endl;
  
  // Iterate through the vector, and print out each value
  const_form_iterator iter;
  for(iter = formData.getElements().begin(); 
      iter != formData.getElements().end(); 
      ++iter) {
    cout << tr().set("class","data") << td(iter->getName()) 
	 << td(iter->getValue()) << tr() << endl;
  }
  cout << table() << cgicc::div() << endl;
}

// Print out information customized for each element
void
showForm(const Cgicc& formData) 
{

  // I am using an if statement to check if each element is found
  cout << h2("Form Data via Cgicc") << endl;
  
  cout << cgicc::div().set("class","notice") << endl;

  //getElement
  const_form_iterator name = formData.getElement("name");
  if(name != (*formData).end() && ! name->isEmpty())
    cout << "Your name is " << **name << '.' << br() << endl;
  else
    cout << "You don't have a name." << br() << endl;

  // getElement and getDoubleValue
  const_form_iterator salary = formData.getElement("bucks");
  if(salary != (*formData).end() && ! salary->isEmpty())
    cout << "You make " << (*salary).getDoubleValue(80, 120) 
	 << " million dollars." << br() << endl;
  else
    cout << "You don't have a salary." << br() << endl;

  // getElement and getIntegerValue
  const_form_iterator hours = formData.getElement("time");
  if(hours != (*formData).end() && ! (*hours).isEmpty())
    cout << "You've wasted " << (*hours).getIntegerValue() 
	 << " hours on the web." << br() << endl;
  else
    cout << "You haven't wasted any time on the web." << br() << endl;

  // getElement and getStrippedValue
  const_form_iterator thoughts = formData.getElement("thoughts");
  if(thoughts != (*formData).end() && ! (*thoughts).isEmpty()) {
    std::string temp = (*thoughts).getStrippedValue();
    cout << "Your thoughts : " << temp << br() << endl;
  }
  else
    cout << "You don't have any thoughts!?" << br() << endl;
  
  // queryCheckbox
  if(formData.queryCheckbox("hungry"))
    cout << "You are hungry." << br() << endl;
  else
    cout << "You are not hungry." << br() << endl;

  // getElement
  std::vector<FormEntry> flavors;
  formData.getElement("flavors", flavors);
  if(! flavors.empty()) {
    cout << "You like ";
    for(std::string::size_type i = 0; i < flavors.size(); i++) {
      cout << flavors[i].getValue();
      if(i < flavors.size() - 2)
	cout << ", ";
      else if(i == flavors.size() - 2)
	cout << " and ";
    }
    cout << " ice cream." << br() << endl;
  }
  else
    cout << "You don't like ice cream!?" << br() << endl;
  
  // getElement
  const_form_iterator hair = formData.getElement("hair");
  if(hair != (*formData).end())
    cout << "Your hair is " << **hair << '.' << br() << endl;
  else
    cout << "You don't have any hair." << br() << endl;
  
  const_form_iterator vote = formData.getElement("vote");
  if(vote != (*formData).end())
    cout << "You voted for " << **vote << '.' << br() << endl;
  else
    cout << "This should never happen. ERROR!" << br() << endl;
  
  // getElement
  std::vector<FormEntry> friends;
  formData.getElement("friends", friends);
  if(! friends.empty()) {
    cout << "You like ";
    for(std::string::size_type i = 0; i < friends.size(); i++) {
      cout << friends[i].getValue();
      if(i < friends.size() - 2)
	cout << ", ";
      else if(i == friends.size() - 2)
	cout << " and ";
    }
    cout << " on Friends." << br() << endl;
  }
  else
    cout << "You don't watch Friends!?" << br() << endl;
  
  cout << cgicc::div() << endl;
}
