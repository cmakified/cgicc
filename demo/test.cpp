/*
 *  $Id: test.cpp,v 1.6 1999/08/20 20:54:05 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999 Stephen F. Booth
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

#include <new>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
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
  STDNS ofstream gLogFile( "/change_this_path/Cgicc.log", STDNS ios::app );
#endif

#if CGICC_USE_NAMESPACES
  using namespace std;
  using namespace cgicc;
#else
#  define div div_
#  define select select_
#endif

// Function prototypes
void dumpEnvironment(const CgiEnvironment& env);
void dumpList(const Cgicc& formData);
void showForm(const Cgicc& formData);
void showFile(const Cgicc& formData);

// Main Street, USA
int
main(int /*argc*/, 
     char **/*argv*/)
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
      throw STDNS runtime_error("User-requested Exception thrown in main()");
    
    // Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
    cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
    cout << html().set("lang", "EN").set("dir", "LTR") << endl;

    // Set up the page's header and title.
    // I will put in lfs to ease reading of the produced HTML. 
    cout << head() << endl;

    // Output the style sheet portion of the header
    cout << style() << comment() << endl;
    cout << "BODY { color: black; background-color: white; }" << endl;
    cout << "HR.half { width: 60%; align: center; }" << endl;
    cout << "SPAN.red, STRONG.red { color: red; }" << endl;
    cout << "DIV.smaller { font-size: small; }" << endl;
    cout << "DIV.notice { border: solid thin; padding: 1em; margin: 1em 0; "
	 << "background: #DDD; }" << endl;
    cout << "SPAN.blue { color: blue; }" << endl;
    cout << "COL.title { color: white; background-color: black; ";
    cout << "font-weight: bold; text-align: center; }" << endl;
    cout << "COL.data { background-color: #DDD; text-align: left; }" << endl;
    cout << "TD.data, TR.data { background-color: #DDD; text-align: left; }"
	 << endl;
    cout << "TD.grayspecial { background-color: #DDD; text-align: left; }"
	 << endl;
    cout << "TD.ltgray, TR.ltgray { background-color: #DDD; }" << endl;
    cout << "TD.dkgray, TR.dkgray { background-color: #BBB; }" << endl;
    cout << "COL.black, TD.black, TD.title, TR.title { color: white; " 
	 << "background-color: black; font-weight: bold; text-align: center; }"
	 << endl;
    cout << "COL.gray, TD.gray { background-color: #DDD; text-align: center; }"
	 << endl;
    cout << "TABLE.cgi { left-margin: auto; right-margin: auto; width: 90%; }"
	 << endl;

    cout << comment() << style() << endl;

    cout << title() << "GNU Cgicc v" << cgi.getVersion() << " Test Results" 
	 << title() << endl;
    cout << meta().set("name", "author").set("content", "Stephen F. Booth") 
	 << endl;

    cout << head() << endl;
    
    // Start the HTML body
    cout << body() << endl;

    cout << h1() << "GNU Cgi" << span("cc").set("class","red")
	 << " v"<< cgi.getVersion() << " Test Results" << h1() << endl;
    
    // Get a pointer to the environment
    const CgiEnvironment& env = cgi.getEnvironment();
    
    // Generic thank you message
    cout << comment() << "This page generated by Cgicc for "
	 << env.getRemoteHost() << comment() << endl;
    cout << h4() << "Thanks for using Cgi" << span("cc").set("class", "red") 
	 << ", " << env.getRemoteHost() 
	 << '(' << env.getRemoteAddr() << ")!" << h4() << endl;  
    
    // If the user wants to save the submission, do it
    if(cgi.queryCheckbox("save")) {
      cgi.save("save");
      cout << p(h2("Data Saved")) << endl;
      
      cout << CGICCNS div().set("class", "notice") << endl;
      cout << "Your data has been saved, and may be restored (by anyone) "
	   << "via the same form." << endl << CGICCNS div() << p() << endl;
    }

    // If the user wants to restore from the last submission, do it
    if(cgi.queryCheckbox("restore")) {
      cgi.restore("save");
      cout << p(h2("Data Restored")) << endl;
      
      cout << CGICCNS div().set("class", "notice") << endl;
      cout << "The data displayed has been restored from a file on disk."
	   << endl << CGICCNS div() << p() << endl;
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

    // If the user requested information on the uploaded file,
    // create a simple table showing the information
    // Disabled for demo
    if(cgi.queryCheckbox("showFile"))
      showFile(cgi);

    // Now print out a footer with some fun info
    cout << p() << CGICCNS div().set("align","center");
    cout << a("Back to form").set("href", cgi.getEnvironment().getReferrer()) 
	 << endl;
    cout << CGICCNS div() << br() << hr(set("class","half")) << endl;
    
    // Information on Cgicc
    cout << CGICCNS div().set("align","center").set("class","smaller") << endl;
    cout << "GNU Cgi" << span("cc").set("class","red") << " v";
    cout << cgi.getVersion();
    cout << " by " << a("Stephen F. Booth")
                       .set("href", "http://www.lmi.net/~sbooth/") 
	 << br() << endl;
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
    cout << CGICCNS div() << endl;
    cout << body() << html() << endl;

    // No chance for failure in this example
    return EXIT_SUCCESS;
  }

  // Did any errors occur?
  catch(const STDNS exception& e) {

    // This is a dummy exception handler, as it doesn't really do
    // anything except print out information.

    // Reset all the HTML elements that might have been used to 
    // their initial state so we get valid output
    html::reset(); 	head::reset(); 		body::reset();
    title::reset(); 	h1::reset(); 		h4::reset();
    comment::reset(); 	td::reset(); 		tr::reset(); 
    table::reset();	CGICCNS div::reset(); 	p::reset(); 
    a::reset();		h2::reset(); 		colgroup::reset();

    // Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
    cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
    cout << html().set("lang","EN").set("dir","LTR") << endl;

    // Set up the page's header and title.
    // I will put in lfs to ease reading of the produced HTML. 
    cout << head() << endl;

    // Output the style sheet portion of the header
    cout << style() << comment() << endl;
    cout << "BODY { color: black; background-color: white; }" << endl;
    cout << "HR.half { width: 60%; align: center; }" << endl;
    cout << "SPAN.red, STRONG.red { color: red; }" << endl;
    cout << "DIV.notice { border: solid thin; padding: 1em; margin: 1em 0; "
	 << "background: #DDD; }" << endl;

    cout << comment() << style() << endl;

    cout << title("GNU Cgicc exception") << endl;
    cout << meta().set("name", "author")
		  .set("content", "Stephen F. Booth") << endl;
    cout << head() << endl;
    
    cout << body() << endl;
    
    cout << h1() << "GNU Cgi" << span("cc", set("class","red"))
	 << " caught an exception" << h1() << endl; 
  
    cout << CGICCNS div().set("align","center").set("class","notice") << endl;

    cout << h2(e.what()) << endl;

    // End of document
    cout << CGICCNS div() << endl;
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
  
  cout << CGICCNS div().set("align","center") << endl;
  
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
  cout << tr() << td("Remote Setress").set("class","title") 
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
  
  cout << table() << CGICCNS div() << endl;
}

// Print out the value of every form element
void
dumpList(const Cgicc& formData) 
{
  cout << h2("Form Data via vector") << endl;
  
  cout << CGICCNS div().set("align","center") << endl;
  
  cout << table().set("border","0").set("rules","none").set("frame","void")
		 .set("cellspacing","2").set("cellpadding","2")
		 .set("class","cgi") << endl;
  cout << colgroup().set("span","2") << endl;
  cout << col().set("align","center").set("span","2") << endl;
  cout << colgroup() << endl;
  
  cout << tr().set("class","title") << td("Element Name") 
       << td("Element Value") << tr() << endl;
  
  // Iterate through the vector, and print out each value
  STDNS vector<FormEntry>::const_iterator iter;
  for(iter = formData.getElements().begin(); 
      iter != formData.getElements().end(); 
      ++iter) {
    cout << tr().set("class","data") << td(iter->getName()) 
	 << td(iter->getValue()) << tr() << endl;
  }
  cout << table() << CGICCNS div() << endl;
}

// Print out information customized for each element
void
showForm(const Cgicc& formData) 
{

  // I am using an if statement to check if each element is found
  cout << h2("Form Data via Cgicc") << endl;
  
  cout << CGICCNS div().set("class","notice") << endl;

  //getElement
  STDNS vector<FormEntry>::const_iterator name = formData.getElement("name");
  if(name != (*formData).end() && ! name->isEmpty())
    cout << "Your name is " << **name << '.' << br() << endl;
  else
    cout << "You don't have a name." << br() << endl;

  // getElement and getDoubleValue
  STDNS vector<FormEntry>::const_iterator salary = formData.getElement("bucks");
  if(salary != (*formData).end() && ! salary->isEmpty())
    cout << "You make " << (*salary).getDoubleValue(80, 120) 
	 << " million dollars." << br() << endl;
  else
    cout << "You don't have a salary." << br() << endl;

  // getElement and getIntegerValue
  STDNS vector<FormEntry>::const_iterator hours = formData.getElement("time");
  if(hours != (*formData).end() && ! (*hours).isEmpty())
    cout << "You've wasted " << (*hours).getIntegerValue() 
	 << " hours on the web." << br() << endl;
  else
    cout << "You haven't wasted any time on the web." << br() << endl;

  // getElement and getStrippedValue
  STDNS vector<FormEntry>::const_iterator sheep = formData.getElement("sheep");
  if(sheep != (*formData).end() && ! (*sheep).isEmpty()) {
    STDNS string temp = (*sheep).getStrippedValue();
    cout << "Your thoughts about sheep cloning: " << temp << br() << endl;
  }
  else
    cout << "You don't have any thoughts about sheep!?" << br() << endl;
  
  // queryCheckbox
  if(formData.queryCheckbox("hungry"))
    cout << "You are hungry." << br() << endl;
  else
    cout << "You are not hungry." << br() << endl;

  // getElement
  STDNS vector<FormEntry> flavors;
  formData.getElement("flavors", flavors);
  if(! flavors.empty()) {
    cout << "You like ";
    for(STDNS string::size_type i = 0; i < flavors.size(); i++) {
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
  STDNS vector<FormEntry>::const_iterator hair = formData.getElement("hair");
  if(hair != (*formData).end())
    cout << "Your hair is " << **hair << '.' << br() << endl;
  else
    cout << "You don't have any hair." << br() << endl;
  
  STDNS vector<FormEntry>::const_iterator vote = formData.getElement("vote");
  if(vote != (*formData).end())
    cout << "You voted for " << **vote << '.' << br() << endl;
  else
    cout << "This should never happen. ERROR!" << br() << endl;
  
  // getElement
  STDNS vector<FormEntry> friends;
  formData.getElement("friends", friends);
  if(! friends.empty()) {
    cout << "You like ";
    for(STDNS string::size_type i = 0; i < friends.size(); i++) {
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
  
  cout << CGICCNS div() << endl;
}

// Show the uploaded file
// This will work if you uncomment the appropriate lines in testform.html
void
showFile(const Cgicc& formData) 
{
  cout << h2("File Uploaded via FormFile") << endl;
  
  STDNS vector<FormFile>::const_iterator file;
  file = formData.getFile("userfile");
				
  if(file != formData.getFiles().end()) {
    cout << CGICCNS div().set("align","center") << endl;
    
    cout << table().set("border","0").set("rules","none").set("frame","void")
		   .set("cellspacing","2").set("cellpadding","2")
		   .set("class","cgi") << endl;
    cout << colgroup().set("span","2") << endl;
    cout << col().set("align","center").set("class","title").set("span","1") 
	 << endl;
    cout << col().set("align","left").set("class","data").set("span","1") 
	 << endl;
    cout << colgroup() << endl;
    
    cout << tr() << td("Name").set("class","title")
	 << td((*file).getName()).set("class","data") << tr() << endl;

    cout << tr() << td("Data Type").set("class","title")
	 << td((*file).getDataType()).set("class","data") << tr() << endl;
    
    cout << tr() << td("Filename").set("class","title") 
	 << td((*file).getFilename()).set("class","data") << tr() << endl;
    cout << tr() << td("Data Length").set("class","title") 
	 << td().set("class","data") << (*file).getDataLength() 
	 << td() << tr() << endl;
    
    cout << tr() << td("File Data").set("class","title")
	 << td().set("class","data") << pre();
    (*file).writeToStream(cout);
    cout << pre() << td() << tr() << endl;
    
    cout << table() << CGICCNS div() << endl;
  }
  else {
    cout << p() << CGICCNS div().set("class", "notice") << endl;
    cout << "No file was uploaded." << endl << CGICCNS div() << p() << endl;
  }
}
