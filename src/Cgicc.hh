/* $Id: Cgicc.hh,v 1.1 1998/04/01 20:50:03 sbooth Exp $ */

#ifndef __CGI_CC__
#define __CGI_CC__ 1

/*
  The Cgicc library, by Stephen Booth <sbooth@hmc.edu>. 
  The latest version can be found on http://www.cs.hmc.edu/~sbooth/cgicc/

  Cgicc is intended to simplify and speed the development of C++ CGI(Common
  Gateway Interface) applications by providing a simple, yet comprehensive  
  set of classes that present full CGI functionality.
  */


#ifndef __EXCEPTION__
#include "Exception.hh"
#endif

#ifndef __CGI_DEFS__
#include "CgiDefs.hh"
#endif

#ifndef __CGI_FORM__
#include "CgiForm.hh"
#endif

#ifndef __CGI_ENVIRONMENT__
#include "CgiEnvironment.hh"
#endif


/* Function pointed to by signal() */
void 
die(int signal);

/**
 * Get the date on which this library was compiled.
 * <P>This is a string of the form mmm dd yyyy.</P>
 * @return The compile date
 */
const char* 
getCompileDate();

/**
 * Get the time at which this library was compiled.
 * <P>This is a string of the form hh:mm:ss in 24-hour time.</P>
 * @return The compile time
 */
const char* 
getCompileTime();

/**
 * Get the version number of Cgicc.
 * <P>The version number is a string of the form #.#.</P>
 * @return The version number
 */
const char* 
getCgiccVersion();

/**
 * The function that processes and responds to form data.
 * <P>For Cgicc to function properly, all output should be written
 * to <TT>out</TT></P>
 * @param formData The form data
 * @param out The stream to which to write output.
 * @return <TT>EXIT_SUCCESS</TT> if all went well, <TT>EXIT_FAILURE</TT> 
 * otherwise.
 * @exception Exception
 */
int 
cgiMain(CgiForm *formData, 
	ostream& out) throw(Exception);

#endif /* CGI_CC */
