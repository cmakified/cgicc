/* $Id: Cgicc.cc,v 1.1 1998/02/12 05:31:41 sbooth Exp $ */

#ifndef __CGI_CC__
#include "Cgicc.hh"
#endif

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
  /*
  HTMLDocument	errorDoc(cout);
  char	     	*errorText = "Allotted process time expired.";
  time_t 	Now;
  tm 		*Date;
  char 		S[80];
  
  Now = time(NULL);
  Date = localtime(&Now);
  strftime(S, 80, "%A, %B %d, %Y %I:%M:%S %p", Date);
  
  errorDoc.printHeader().html().head().title().put("Cgicc Error: ");
  errorDoc.put(errorText).title().head().body("#FFFFFF");
  
  errorDoc.h1().put("Cgi<FONT COLOR=#FF0000>cc</FONT> v");
  errorDoc.put(getCgiccVersion()).put(" encountered an error.").h1();
  
  errorDoc.center().table("50%",0,2,2,"MIDDLE");
  errorDoc.tr().td("CENTER", "#000000", "30%");
  errorDoc.b("<FONT COLOR=#FFFFFF>Specification</FONT>").td();
  errorDoc.td("LEFT", "#CCCCCC").put(errorText).td().tr();
  errorDoc.tr().td("CENTER", "#000000", "30%");
  errorDoc.b("<FONT COLOR=#FFFFFF>Time</FONT>").td();
  errorDoc.td("LEFT", "#CCCCCC").put(S).td().tr();
  errorDoc.table().center();
  
  errorDoc.br().p().p().lf();
  errorDoc.put("Cgi<FONT COLOR=#FF0000>cc</FONT> encountered an error ");
  errorDoc.put("while executing ");
  errorDoc.put("the cgi code.  If the error is due to ");
  errorDoc.put("low memory or an input/output difficulty, ");
  errorDoc.put("please <A HREF=\"mailto:").put(ADMIN).put("\">");
  errorDoc.put("contact the administrator</A> for assistance.").br().p();
  
  errorDoc.foot().center().hr(50);
  errorDoc.font('-', 1).put("Cgi<FONT COLOR=#FF0000>cc</FONT> v");
  errorDoc.put(getCgiccVersion()).put(" by ");
  errorDoc.link("http://www2.hmc.edu/~sbooth","Stephen F. Booth").br();
  errorDoc.put("Compiled at ").put(getCompileTime());
  errorDoc.put(" on ").put(getCompileDate());
  
#if HAS_UNAME
  struct utsname info;
  if(uname(&info) != -1) {
    errorDoc.put(". Running on ").put(info.sysname);
    errorDoc.put(' ').put(info.release).put(" (");
    errorDoc.put(info.nodename).put(')');
  }
#else
  errorDoc.put('.');
#endif
  
  errorDoc.font().center().foot().html();
  */
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
    //result = cgiMain(formData, *out);
    result = cgiMain(formData, cout);
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
    
    /*
    HTMLDocument	errorDoc(cout);
    time_t 		Now;
    tm 			*Date;
    char 		S[80];
    
    log("Message : ");
    logln(err.getMessage());
    log("File    : ");
    logln(err.getFile());
    log("Line    : ");
    logln(err.getLine());
    
    Now = time(NULL);
    Date = localtime(&Now);
    strftime(S, 80, "%A, %B %d, %Y %I:%M:%S %p", Date);
    
    errorDoc.printHeader().html().head().title().put("Cgicc Error: ");
    errorDoc.put(err.getMessage()).title().head().body("#FFFFFF");

    errorDoc.h1().put("Cgi<FONT COLOR=#FF0000>cc</FONT> v");
    errorDoc.put(getCgiccVersion()).put(" encountered an error.").h1();

    errorDoc.center().table("50%",0,2,2,"MIDDLE");
    errorDoc.tr().td("CENTER", "#000000", "30%");
    errorDoc.b("<FONT COLOR=#FFFFFF>Specification</FONT>").td();
    errorDoc.td("LEFT", "#CCCCCC").put(err.getMessage()).td().tr();
    errorDoc.tr().td("CENTER", "#000000", "30%");
    errorDoc.b("<FONT COLOR=#FFFFFF>Filename</FONT>").td();
    errorDoc.td("LEFT", "#CCCCCC").put(err.getFile()).td().tr();
    errorDoc.tr().td("CENTER", "#000000", "30%");
    errorDoc.b("<FONT COLOR=#FFFFFF>Line Number</FONT>").td();
    errorDoc.td("LEFT", "#CCCCCC").put(err.getLine()).td().tr();
    errorDoc.tr().td("CENTER", "#000000", "30%");
    errorDoc.b("<FONT COLOR=#FFFFFF>Time</FONT>").td();
    errorDoc.td("LEFT", "#CCCCCC").put(S).td().tr();
    errorDoc.table().center();

    errorDoc.br().p().p().lf();
    errorDoc.put("Cgi<FONT COLOR=#FF0000>cc</FONT> encountered an error ");
    errorDoc.put("while executing ");
    errorDoc.put("the cgi code.  If the error is due to ");
    errorDoc.put("low memory or an input/output difficulty, ");
    errorDoc.put("please try re-calling the program.  Otherwise, ");
    errorDoc.put("please <A HREF=\"mailto:").put(ADMIN).put("\">");
    errorDoc.put("contact the administrator</A> for assistance.").br().p();

    errorDoc.foot().center().hr(50);
    errorDoc.font('-', 1).put("Cgi<FONT COLOR=#FF0000>cc</FONT> v");
    errorDoc.put(getCgiccVersion()).put(" by ");
    errorDoc.link("http://www2.hmc.edu/~sbooth","Stephen F. Booth").br();
    errorDoc.put("Compiled at ").put(getCompileTime());
    errorDoc.put(" on ").put(getCompileDate());
    
#if HAS_UNAME
    struct utsname info;
    if(uname(&info) != -1) {
      errorDoc.put(". Running on ").put(info.sysname);
      errorDoc.put(' ').put(info.release).put(" (");
      errorDoc.put(info.nodename).put(')');
    }
#else
    errorDoc.put('.');
#endif

errorDoc.font().center().foot().html();
    */    
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}

//EOF
