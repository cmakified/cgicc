/*
 *  $Id: dns.cpp,v 1.13 2000/10/15 15:59:20 sbooth Exp $
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

#include <cstdlib>
#include <new>
#include <vector>
#include <stdexcept>
#include <iostream>

#include "cgicc/CgiDefs.h"
#include "cgicc/HTMLClasses.h"
#include "cgicc/Cgicc.h"

#if HAVE_UNAME
#  include <sys/utsname.h>
#endif

#if HAVE_SYS_TIME_H
#  include <sys/time.h>
#endif

#ifdef WIN32
#  include <winsock2.h>
#else
#  include <sys/types.h>
#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <arpa/inet.h>
#  include <netdb.h>
#endif /* WIN32 */

// To use logging, the variable gLogFile MUST be defined, and it _must_
// be an ofstream
#if DEBUG
  STDNS ofstream gLogFile( "/change_this_path/cgicc.log", STDNS ios::app );
#endif

#if CGICC_USE_NAMESPACES
  using namespace std;
  using namespace cgicc;
#else
#  define div div_
#  define link link_
#  define select select_
#endif

// DNS gateway cgi
int
main(int /*argc*/, 
     char ** /*argv*/)
{

  try {
#if HAVE_GETTIMEOFDAY
    timeval start;
    gettimeofday(&start, NULL);
#endif

    Cgicc cgi;
    
    cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
    cout << html().set("lang","EN").set("dir","LTR") << endl;
    
    // Set up the page; I will put in lfs to ease reading of the
    // produced HTML. These are optional, and except in <PRE>
    // tags have no effect on HTML appearance.
    cout << head() << endl;

    // Output the style sheet portion of the header
    cout << style() << comment() << endl;
    cout << "BODY { color: black; background-color: white; }" << endl;
    cout << "HR.half { width: 60%; align: center; }" << endl;
    cout << "SPAN.red, STRONG.red { color: red; }" << endl;
    cout << "DIV.smaller { font-size: small; }" << endl;
    cout << "DIV.dns { border: solid thin; margin: 1em 0; "
	 << "background: #DDD; text-align: center; }" << endl;
    cout << "SPAN.blue { color: blue; }" << endl;
    cout << "COL.title { color: white; background-color: black; ";
    cout << "font-weight: bold; text-align: center; }" << endl;
    cout << "COL.data { background-color: #DDD; text-align: left; }" << endl;
    cout << comment() << style() << endl;

    cout << title("DNS Gateway") << endl;
    cout << meta().set("name", "author")
		  .set("content", "Stephen F. Booth") << endl;
    cout << head() << endl;
    
    cout << h1() << "GNU cgi" << span("cc").set("class","red")
	 << " DNS Gateway" << h1() << endl;
  
    form_iterator ip = cgi.getElement("ip");
    form_iterator name = cgi.getElement("hostname");

    if(ip != (*cgi).end()) {
      cout << h3() << "Query results for " << **ip << h3() << endl;
      
      u_long addr;
      struct hostent *hp;
      char **p;
      
      if((int)(addr = inet_addr((**ip).c_str())) == -1) {
	cout << CGICCNS div().set("class", "dns") << endl
	     << strong(span("ERROR").set("class","red"))
	     << " - IP address must be of the form x.x.x.x"
	     << endl << CGICCNS div() << endl;
      }
      else {
	hp = gethostbyaddr((char*)&addr, sizeof (addr), AF_INET);
	if(hp == NULL) {
	  cout << CGICCNS div().set("class", "dns") << endl
	       << strong(span("ERROR").set("class","red")) 
	       << " - Host information for " << em((**ip)) << " not found."
	       << endl << CGICCNS div() << endl;
	}
	else {
	  for(p = hp->h_addr_list; *p != 0; p++) {
	    struct in_addr in;
	    //char **q;
	    
	    (void) memcpy(&in.s_addr, *p, sizeof(in.s_addr));
	    
	    cout << CGICCNS div().set("class", "dns") << endl
		 << span(inet_ntoa(in)).set("class","blue") 
		 << " - " << ' ' << hp->h_name;
	    //for(q = hp->h_aliases; *q != 0; q++)
	    //	    cout << *q << ' ';
	    cout << endl << CGICCNS div() << endl;
	  }
	}
      }
    }
    

    if(name != (*cgi).end()) {
      cout << h3() << "Query results for " << **name << h3() << endl;
      
      struct hostent *hp;
      char **p;
      
      hp = gethostbyname((**name).c_str());
      if(hp == NULL) {
	cout << CGICCNS div().set("class", "dns") << endl
	     << strong(span("ERROR").set("class","red"))
	     << " - Host information for " << em(**name) << " not found."
	     << endl << CGICCNS div() << endl;
      }
      else {
	for(p = hp->h_addr_list; *p != 0; p++) {
	  struct in_addr in;
	  //char **q;
	  
	  (void) memcpy(&in.s_addr, *p, sizeof(in.s_addr));
	  
	  cout << CGICCNS div().set("class", "dns") << endl
	       << inet_ntoa(in) << " - " << ' ' 
	       << span(hp->h_name).set("class","blue");
	  //	for(q = hp->h_aliases; *q != 0; q++)
	  //	  cout << *q << ' ';
	  cout << endl << CGICCNS div() << endl;
	}
      }
    }
    
    cout << p("Please enter an IP address or a hostname.") << endl;
    
    cout << table().set("border","0")
		   .set("rules","none")
		   .set("frame","void")
		   .set("cellspacing","2").set("cellpadding","2") << endl;
    cout << colgroup().set("span","2") << endl;
    cout << col().set("align","center")
		 .set("class","title")
		 .set("span","1") << endl;
    cout << col().set("align","left")
		 .set("class","data")
		 .set("span","1") << endl;
    cout << colgroup() << endl;
    
    cout << "<FORM METHOD=\"POST\" ACTION=\"http://"
	 << cgi.getEnvironment().getServerName();
    if(cgi.getEnvironment().getServerPort() != 80)
      cout << ":" << cgi.getEnvironment().getServerPort();
    cout << cgi.getEnvironment().getScriptName() << "\">" << endl;
    
    cout << tr() << endl;
    cout << td(strong("IP Address: ")) << endl;
    cout << td() << "<INPUT TYPE=\"TEXT\" NAME=\"ip\"";
    if(ip != (*cgi).end())
      cout << " VALUE=\"" << **ip << "\">";
    else
      cout << ">";
    cout << td() << tr() << "</FORM>" << endl;
    
    cout << "<FORM METHOD=\"POST\" ACTION=\"http://"
	 << cgi.getEnvironment().getServerName();
    if(cgi.getEnvironment().getServerPort() != 80)
      cout << ":" << cgi.getEnvironment().getServerPort();
    cout << cgi.getEnvironment().getScriptName() << "\">" << endl;
    
    cout << tr() << endl;
    cout << td(strong("Hostname: ")) << endl;
    cout << td() << "<INPUT TYPE=\"TEXT\" NAME=\"hostname\"";
    if(name != (*cgi).end())
      cout << " VALUE=\"" << **name << "\">";
    else
      cout << ">";
    cout << td() << tr() << endl;
    cout << "</FORM>" << table() << p() << endl;
    
    // Now print cout a footer with some fun info
    cout << hr(set("class","half")) << endl;
    cout << CGICCNS div().set("align","center").set("class","smaller") << endl;
    cout << "GNU cgi" << span("cc").set("class","red") << " v"
	 << cgi.getVersion();
    cout << " by " << a("Stephen F. Booth")
			.set("href", "http://home.earthlink.net/~sfbooth/") 
	 << br() << endl;
    cout << "Compiled at " << cgi.getCompileTime() 
	 << " on " << cgi.getCompileDate() << br() << endl;
    
    cout << "Configured for " << cgi.getHost();  
    // I don't know if everyone has uname...
#if HAVE_UNAME
    struct utsname info;
    if(uname(&info) != -1) {
      cout << ". Running on " << info.sysname;
      cout << ' ' << info.release << " (";
      cout << info.nodename << ')' << endl;
    }
#else
    cout << '.' << endl;
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

    return EXIT_SUCCESS;
  }

  catch(const STDNS exception& e) {
    return EXIT_FAILURE;
  }
}
