/* $Id: Cgicc.cc,v 1.3 1998/04/02 04:55:01 sbooth Exp $ */

#ifndef __CGICC__
#include "Cgicc.hh"
#endif

#if HAS_UNAME
#include <sys/utsname.h>
#endif

/*
  The Cgicc library, by Stephen Booth, version 2.2. 
  The latest version can be found on http://www.cs.hmc.edu/~sbooth/cgicc/
  
  Cgicc is intended to simplify and speed the development of C++ CGI(common
  gateway interface) applications by providing a simple, user friendly set of
  classes that present full cgi functionality. 
  */

// ============================================================
// Class Cgicc
// ============================================================
Cgicc::Cgicc() throw(Exception)
  : fFormData(NULL)
{
#if DEBUG
  time_t 	now;
  tm 		*date;
  char 		s[80];
  
  now = time(NULL);
  date = localtime(&now);
  strftime(s, 80, "%A, %B %d, %Y %I:%M:%S %p", date);
  log("Cgicc debugging log started on ");
  logln(s);
#endif
  
  fFormData = new CgiForm();
  if(! fFormData)
    throw Exception("new failed", ERRINFO);
}

Cgicc::~Cgicc()
{
  logln("Cleaning up...");
  delete fFormData;
  logln("Cgicc debugging log closed.");
}

//EOF
