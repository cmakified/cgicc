/*
 *  $Id: CgiDefs.hh,v 1.4 1998/12/09 00:48:57 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __CGI_DEFS__
#define __CGI_DEFS__ 1

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <iostream.h>
#include <fstream.h>
#include <string.h>

#include "Exception.hh"

#ifndef ADMIN
#define ADMIN "webmaster"
#endif

#if DEBUG

extern ofstream gLogFile;
#define logln(s) 	gLogFile << s << endl
#define log(s) 		gLogFile << s

#else

/**
 * Output a string to the debugging log, followed by a newline.
 * <P>The debugging log is a user-specified ostream.</P>
 * @param s The string to log
 */
#define logln(s)

/**
 * Output a string to the debugging log.
 * <P>The debugging log is a user-specified ostream.</P>
 * @param s The string to log
 */
#define log(s)

#endif

/**
 * Query the value of an environment variable.
 * <P>The value stored in <TT>where</TT> is guaranteed not to be NULL.<BR>
 * <STRONG CLASS="red">It is the caller's responsibility to delete 
 * <TT>where</TT> when it is no longer needed</STRONG>.</P>
 * @param varName The name of an environment variable
 * @param where Where to store the result
 * @exception Exception
 */
void 
safeGetenv(const char *varName, 
	   char* &where) throw(Exception);      

/*
 * Compare two strings for equality.  
 * This is a shortcut to strncmp and strncasecmp.
 * @param s1 The first string to compare
 * @param s2 The second string to compare
 * @param n The number of characters to compare
 * @param ignoreCase Whether a case-insensitive compare should be done 
 * @return True if the strings are equal, false if they are not
 */
inline bool 
stringsAreEqual(const char *s1, 
		const char *s2, 
		int n, 
		bool ignoreCase)
{ return ! (ignoreCase ? strncasecmp(s1,s2,n) : strncmp(s1,s2,n)); }

/*
 * Compare two strings for equality.
 * This is a shortcut to strcasecmp and strcmp.
 * @param s1 The first string to compare
 * @param s2 The second string to compare
 * @param ignoreCase Whether a case-insensitive compare should be done 
 * @return True if the strings are equal, false if they are not
 */
inline bool 
stringsAreEqual(const char *s1, 
		const char *s2, 
		bool ignoreCase)
{ return ! (ignoreCase ? strcasecmp(s1,s2) : strcmp(s1,s2)); }

/**
 * A safer alternative to system().
 * <P>This command will escape out (by prepending \) all semicolons and 
 * pipes (; and |) present in the command string.</P>
 * @param command The command to be sanitized and run
 * @return The result of running the sanitized version of <EM>command</EM>
 * @exception Exception
 */
int 
saferSystem(const char *command) throw(Exception);

/**
 * Convert encoded characters in form data to normal ASCII. 
 * <P>For example, %21 is converted to ! and + is converted to a space.
 * Normally, this is called internally to decode the query string or post 
 * data.</P>
 * @param src The src string containing the encoded characters
 * @param len The number of characters to convert
 * @param result Where to store the converted string
 * @exception Exception
 */
void
unescapeChars(const char *src, 
	      int len,
	      char* &result) throw(Exception);

/**
 * Extract the first non-whitespace character from a string.
 * <P>Normally this function is called internally during MIME decoding.</P>
 * @param s The string
 * @return The first non-whitespace character.
 */
char firstNonspaceChar(const char *s);

/**
 * Convert a hex-encoded character to its ASCII equivalent.
 * <P>For example, after the call
 * <PRE class="code">
 * char c = hexToChar('2', '1');
 * </PRE>
 * <TT>c</TT> will have a value of  '!'.</P>
 * <P>Normally, this is called internally to decode encoded characters in
 * the query string or post data.</P>
 * @param first The first character of the hex value
 * @param second the second character of the hex value
 * @return The ASCII character
 */
char 
hexToChar(char first, 
	  char second);
  
/**
 * Compare bytes for equality.  
 * <P>This is a simple byte-by-byte test for equality which returns after the
 * first difference is found.</P>
 * @param s1 An array of bytes.
 * @param s2 An array of bytes.
 * @param len The number of bytes to compare.
 * @return True if the bytes are equal, false if not.
 */
inline bool
bytesAreEqual(const char *s1, 
	      const char *s2, 
	      int len)
{
  for(int i = 0; i < len; i++)
    if(*s1++ != *s2++)
      return false;
  return true;
}

/**
 * Find the first occurence of a sequence of bytes.
 * <P>For example, after the call
 * <PRE CLASS="code">
 * const char *data = "this is a test";
 * int loc = findBytes(data, strlen(data), "test");
 * </PRE>
 * <TT>loc</TT> will be 10.</P>
 * @param data The array of bytes to search.
 * @param dataLen The length of <TT>data</TT>, in bytes.
 * @param search The search sequence.
 * @return The index of the first char of <TT>search</TT> in <TT>data</TT>.
 */
int 
findBytes(const char *data, 
	  int dataLen, 
	  const char *search);

/**
 * Locate an array of bytes contained within two separators.
 * <P>For example, after the call
 * <PRE class="code">
 * int start = 0;
 * int end = 0;
 * const char *data = "11foo22";
 *
 * extractBetween(data, strlen(data), "11", "22", start, end);
 * </PRE>
 * <TT>start</TT> will be 2, and <TT>end</TT> will be 5.</P>
 * @param data The data to search.
 * @param dataLen The length of <TT>data</TT>, in bytes.
 * @param separator1 The first logical separator.
 * @param separator2 The second logical separator.
 * @param start The index of the first char after <TT>separator1</TT> in 
 * <TT>data</TT>.
 * @param end The index of the first char of <TT>separator2</TT> in 
 * <TT>data</TT>.
 */
void
extractBetween(const char *data, 
	       int dataLen, 
	       const char *separator1, 
	       const char *separator2,
	       int& start, 
	       int& end);

/**
 * Locate an array of bytes contained within two separators.
 * <P>For example, after the call
 * <PRE class="code">
 * int start = 0;
 * int end = 0;
 * const char *data = "11foo11";
 *
 * extractBetween(data, strlen(data), "11", start, end);
 * </PRE>
 * <TT>start</TT> will be 2, and <TT>end</TT> will be 5.</P>
 * @param data The data to search.
 * @param dataLen The length of <TT>data</TT>, in bytes.
 * @param separator1 The separator.
 * @param start The index of the first char after <TT>separator</TT> in 
 * <TT>data</TT>.
 * @param end The index of the first char of <TT>separator</TT> in 
 * <TT>data</TT> after the initial occurrence.
 */
void
extractBetween(const char *data, 
	       int dataLen, 
	       const char *separator, 
	       int& start, 
	       int& end);

#endif
