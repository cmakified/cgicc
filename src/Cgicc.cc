/* $Id: Cgicc.cc,v 1.2 1998/04/01 20:52:46 sbooth Exp $ */

#ifndef __CGI_CC__
#include "Cgicc.hh"
#endif

#include "HTMLClasses.hh"

#if HAS_UNAME
#include <sys/utsname.h>
#endif

/*
  The Cgicc library, by Stephen Booth, version 2.0. 
  The latest version can be found on http://www.cs.hmc.edu/~sbooth/cgicc/
  
  Cgicc is intended to simplify and speed the development of C++ cgi(common
  gateway interface) applications by providing a simple, user friendly set of
  classes that present full cgi functionality. 
  */

void
die(int signal)
{
  char *errorText = "Allotted process time expired";

  html::reset();	head::reset();		title::reset();
  style::reset();	comment::reset();	body::reset();
  h1::reset();		span::reset();		div_::reset();
  table::reset();	colgroup::reset();	tr::reset();
  td::reset();		p::reset();
    
  cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
  cout << html(add("lang","EN").add("dir","LTR")) << endl;
    
  cout << head() << endl;
  cout << title() << "Cgicc Error: " << errorText << title() << endl;
  cout << meta(add("name", "author")
	       .add("content", "Stephen F. Booth")) << endl;
    
  cout << style() << comment() << endl;

  cout << "BODY { color: black; background-color: white; }" << endl;
  cout << "TABLE.cgi { margin-left: auto; margin-right: auto; width: 90%; }" 
       << endl;
  cout << "DIV.smaller { font-size: small; }" << endl;
  cout << "SPAN.red, COL.red, PRE.red { color: red }" << endl;
  cout << "TR.title, TD.title, COL.title { color: white;"
       << "background-color: black; font-weight: bold; text-align: center; }"
       << endl;
  cout << "TR.data, TD.data, COL.data {background-color: #CCCCCC; }" << endl;
  cout << "HR.half { width: 60%; }" << endl;
  
  cout << comment() << style() << endl;
  
  cout << head() << endl;
  
  cout << body() << endl;
  
  cout << h1() << "Cgi" << span("cc", add("class","red"))
       << " v"<< getCgiccVersion() << " Encountered an Error" 
       << h1() << endl;
  
  cout << div_(add("align","center")) << endl;
  
  cout << table(add("border","0").add("rules","none").add("frame","void")
		.add("cellspacing","2").add("cellpadding","2")
		.add("class","cgi")) << endl;
  cout << colgroup(add("span","2")) << endl;
  cout << col(add("align","center").add("class","title").add("span","1")) 
       << endl;
  cout << col(add("align","left").add("class","data").add("span","1")) 
       << endl;
  cout << colgroup() << endl;
  
  cout << tr() << td("Specification", add("class","title")) 
       << td(errorText, add("class","data")) << tr() << endl;
  cout << table();
  
  cout << p() << "If the error persists, please contact <TT><A HREF=\"mailto:"
       << ADMIN << "\">" << ADMIN << "</A></TT> for assistance." << p();
  
  cout << body() << endl;
  
  cout << hr(add("class","half")) << div_() << endl;
    
    cout << div_(add("align","center").add("class","smaller")) << endl;
    cout << "Cgi" << span("cc",add("class","red")) << " v";
    cout << getCgiccVersion();
    cout << " by " << a("Stephen F. Booth", 
			add("href", "http://www2.hmc.edu/~sbooth")) << br();
    cout << "Compiled at " << getCompileTime();
    cout << " on " << getCompileDate();
    
    // I don't know if everyone has uname...
#if HAS_UNAME
    struct utsname info;
    if(uname(&info) != -1) {
      cout << ". Running on " << info.sysname;
      cout << ' ' << info.release << " (";
      cout << info.nodename << ')' << endl;
    }
#else
    cout << '.' << endl;
#endif
    
    cout << html();

  // Terminate with moderate prejudice
  exit(1);
}

/* Version and compile time information */
const char* getCompileDate() { return __DATE__; }
const char* getCompileTime() { return __TIME__; }
const char* getCgiccVersion() { return "2.2"; }


// Main Street, U.S.A
int
main(int argc, 
     char **argv) 
{
  // Give the process thirty seconds,  should be plenty.
  signal(SIGALRM, die);
  alarm(30);
  
  // The main try block 
  // Most, if not all, of the code is called from here
  
  try {
    ostrstream		*out;
    CgiForm		*formData;
    int			result;
    
#if DEBUG
    time_t 		now;
    tm 			*date;
    char 		s[80];
    
    now = time(NULL);
    date = localtime(&now);
    strftime(s, 80, "%A, %B %d, %Y %I:%M:%S %p", date);
    log("Cgicc debugging log started on ");
    logln(s);
#endif
    
    formData = new CgiForm();
    if(! formData)
      throw Exception("new failed", ERRINFO);
    
    out = new ostrstream();
    if(! out)
      throw Exception("new failed", ERRINFO);
    
    // Call the users function
    logln("calling cgiMain()");
    result = cgiMain(formData, *out);
    //result = cgiMain(formData, cout);
    if(result != EXIT_SUCCESS)
      throw Exception("Error in cgiMain()", ERRINFO);
    
    // Adios
    logln("Cleaning up...");
    delete formData;
    *out << ends;
    cout << out->str();
    delete out;
    logln("Cgicc debugging log closed.");
  }
  
  /* Catch any exceptions that were thrown */  
  catch(Exception err) {
    logln("Caught an exception");
    log("Message : ");
    logln(err.getMessage());
    log("File    : ");
    logln(err.getFile());
    log("Line    : ");
    logln(err.getLine());

    html::reset();	head::reset();		title::reset();
    style::reset();	comment::reset();	body::reset();
    h1::reset();	span::reset();		div_::reset();
    table::reset();	colgroup::reset();	tr::reset();
    td::reset();
    
    cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
    cout << html(add("lang","EN").add("dir","LTR")) << endl;
    
    cout << head() << endl;
    cout << title() << "Cgicc Error: " << err.getMessage() << title() << endl;
    cout << meta(add("name", "author")
		 .add("content", "Stephen F. Booth")) << endl;
    
    cout << style() << comment() << endl;

    cout << "BODY { color: black; background-color: white; }" << endl;
    cout << "TABLE.cgi { margin-left: auto; margin-right: auto; width: 90%; }" 
	 << endl;
    cout << "DIV.smaller { font-size: small; }" << endl;
    cout << "SPAN.red, COL.red, PRE.red { color: red }" << endl;
    cout << "TR.title, TD.title, COL.title { color: white;"
	 << "background-color: black; font-weight: bold; text-align: center; }"
	 << endl;
    cout << "TR.data, TD.data, COL.data {background-color: #CCCCCC; }" << endl;
    cout << "HR.half { width: 60%; }" << endl;

    cout << comment() << style() << endl;

    cout << head() << endl;
    
    cout << body() << endl;

    cout << h1() << "Cgi" << span("cc", add("class","red"))
	 << " v"<< getCgiccVersion() << " Encountered an Error" 
	 << h1() << endl;

    cout << div_(add("align","center")) << endl;

    cout << table(add("border","0").add("rules","none").add("frame","void")
		 .add("cellspacing","2").add("cellpadding","2")
		 .add("class","cgi")) << endl;
    cout << colgroup(add("span","2")) << endl;
    cout << col(add("align","center").add("class","title").add("span","1")) 
	 << endl;
    cout << col(add("align","left").add("class","data").add("span","1")) 
	 << endl;
    cout << colgroup() << endl;
    
    cout << tr() << td("Message", add("class","title")) 
	 << td(err.getMessage(), add("class","data")) << tr() << endl;
    cout << tr() << td("File", add("class","title")) 
	 << td(err.getFile(), add("class","data")) << tr() << endl;
    cout << tr() << td("Line", add("class","title")) 
	 << td(add("class","data")) << err.getLine() << td() << tr() << endl;
    cout << table();

    cout << body() << endl;
    
    cout << hr(add("class","half")) << div_() << endl;
    
    cout << div_(add("align","center").add("class","smaller")) << endl;
    cout << "Cgi" << span("cc",add("class","red")) << " v";
    cout << getCgiccVersion();
    cout << " by " << a("Stephen F. Booth", 
			add("href", "http://www2.hmc.edu/~sbooth")) << br();
    cout << "Compiled at " << getCompileTime();
    cout << " on " << getCompileDate();
    
    // I don't know if everyone has uname...
#if HAS_UNAME
    struct utsname info;
    if(uname(&info) != -1) {
      cout << ". Running on " << info.sysname;
      cout << ' ' << info.release << " (";
      cout << info.nodename << ')' << endl;
    }
#else
    cout << '.' << endl;
#endif
    
    cout << html();
    
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}

//EOF
