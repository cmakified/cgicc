/* $Id: Exception.cc,v 1.1 1998/02/12 05:31:41 sbooth Exp $ */

#include "Exception.hh"

// ============================================================
// Class Exception
// ============================================================
Exception::Exception()
  : fMessage("An exception was thrown."), fFile(__FILE__), fLine(__LINE__)
{}

Exception::Exception(char *msg)
  : fMessage(msg), fFile(__FILE__), fLine(__LINE__)
{}

Exception::Exception(char *msg, 
		     char *file, 
		     int line)
  : fMessage(msg), fFile(file), fLine(line)
{}

Exception::~Exception()
{}
