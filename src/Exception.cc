/*
 * $Id: Exception.cc,v 1.2 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

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
