/*
 * $Id: nph-login.cpp,v 1.1 2001/09/03 22:19:00 sbooth Exp $
 * 
 * Written by Peter Goedtkindt <peter.goedtkindt@axstech.com>
 */

/* 
 * In this example, we will control the HTTPNPH header so that the user
 * will need to provide authentication before the cgi does something.
 * So far, this CGI has only been tested on IIS 5 servers and using
 * browsers IE 5 (Mac OS 9, MacOS X, Windows), Netscape 4.7 (Windows,
 * Linux, Mac), Omniweb 4 (Mac) The ask for user authentication, the
 * cgi issues a 403 http response code.  
 *
 * IMPORTANT: To be able to control the response type HTTP header, the
 * name of the cgi executable needs to start with "nph-". The cgi is
 * then fully responsible for the creation of _ALL_ http headers.
 *
 * IMPORTANT2: Once a valid username/password has been accepted, the
 * browser will send the pair with each request until you quit your
 * browser.  
 *
 * IMPORTANT3: On Windows servers, make certain your webserver is
 * configured to allow basic authentication.
 */

#include <exception>
#include <iostream>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHeaders.h"
#include "cgicc/HTMLClasses.h"

// To use the debug logging feature, the variable gLogFile MUST be
// defined, and it _must_ be an ofstream
#if DEBUG
STDNS ofstream gLogFile( "/tmp/cgicc.log", STDNS ios::app );
#endif

#if CGICC_USE_NAMESPACES
using namespace std;
using namespace cgicc;
#else
#  define div div_
#  define select select_
#endif

int
main(int /*argc*/, 
     char ** /*argv*/)
{
  try {
    Cgicc cgi;
    // Get a pointer to the environment
    const CgiEnvironment& env = cgi.getEnvironment();
    string remoteuser = env.getRemoteUser();
    string serversw = env.getServerSoftware();
    string clientsw = env.getUserAgent();

    string authtype = env.getAuthType();
    
    if(! authtype.empty()) {
      cout <<"authtype = " << authtype << endl;
      return 0;
    }

    if(remoteuser.empty()) {
      if (serversw.find("Microsoft") != string::npos 
	  && clientsw.find("Win") != string::npos) {
	/*
	  Server and client are running on Microsoft OS, so we
	  probably can request NTLM authentication the last test was
	  needed to prevent IE on Mac's to use NTLM, because it seems
	  to be broken on Macs 
	*/
        cout << HTTPResponseHeader("HTTP/1.1", 401, "Unauthorized")
	  .addHeader("WWW-Authenticate: NTLM")
	  .addHeader("WWW-Authenticate: Basic realm=\"cgicc\"")
	  .addHeader("Content-Type: text/html");

	/*
	  There is a bug in all version of Microsoft Internet Explorer
	  at least up to 5.5 by which the NTLM authentication scheme
	  MUST be declared first or it won't be selected. This goes
	  against RFC 2616, which recites "A user agent MUST choose to
	  use the strongest auth- scheme it understands" and NTLM, while
	  broken in many ways, is still worlds stronger than Basic.
        */
      }
      else {
	// we're not chatting fully MS: only support basic
        cout << HTTPResponseHeader("HTTP/1.1", 401, "Unauthorized")
	  .addHeader("WWW-Authenticate: Basic realm=\"cgicc\"")
	  .addHeader("Content-Type: text/html");
      }

      cout << HTMLDoctype(HTMLDoctype::eStrict) << endl;
      cout << html().set("lang", "EN").set("dir", "LTR") << endl;
    
      cout << head() << endl;
      cout << title("401 Authorization Required")  << endl;
      cout << head() << endl;
    
      cout << body() << endl;
      cout << h1("401 Authorization Required") << endl;
      cout << p() << "This server could not verify that you are "
	   << "authorized to access the document requested. Either you "
	   << "supplied the wrong credentials (e.g., bad password), or "
	   << "your browser doesn't understand how to supply the "
	   << "credentials required." << p();

      cout << hr() << endl;
      cout << address() << "GNU cgicc \"server\" version " << cgi.getVersion()
	   << address() << endl;

      return 0;
    }
    
    
    // Output the HTTP headers 200 OK header for an HTML document, and
    // the HTML 4.0 DTD info
    cout << HTTPResponseHeader(env.getServerProtocol(), 200 ,"OK");
    cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
    cout << html().set("lang", "EN").set("dir", "LTR") << endl;
    
    // Set up the page's header and title.
    cout << head() << endl;
    cout << title() << "GNU cgicc v" << cgi.getVersion() << title() << endl;
    cout << head() << endl;
    
    // Start the HTML body
    cout << body() << endl;

    // Print out a message
    cout << "Hello " << env.getRemoteUser() 
	 << " your login was accepted" << br() << endl;
    cout << "You were authenticated using authentication scheme : " 
	 << env.getAuthType() << br() << endl;
    cout << "Your server software is :" << serversw << br() << endl;
    cout << "Your browser software is :" << clientsw << br() << endl;
    // Close the document
    cout << body() << html();
  }
  
  catch(const exception& e) {
    // handle error condition
  }
  
  return 0;
}
