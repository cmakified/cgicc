/*
 *  $Id: CgiUtils.hh,v 1.3 1999/05/28 19:37:12 sbooth Exp $
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

#ifndef _CGIUTILS_HH_
#define _CGIUTILS_HH_ 1

#ifdef __GNUG__
#pragma interface
#endif

#include <new>
#include <string>
#include <fstream>

#include "CgiDefs.hh"

#if DEBUG

extern ofstream gLogFile;
#define LOGLN(s) 	gLogFile << s << endl;
#define LOG(s) 		gLogFile << s;

#else

/**
 * Output a string to the debugging log, followed by a newline.
 * <P>The debugging log is a user-specified ostream.</P>
 * @param s The string to log
 */
#define LOGLN(s)

/**
 * Output a string to the debugging log.
 * <P>The debugging log is a user-specified ostream.</P>
 * @param s The string to log
 */
#define LOG(s)

#endif


CGICC_BEGIN_NAMESPACE

/**
 * Query the value of an environment variable.
 * This function never returns null.
 * @param varName The name of an environment variable
 * @return The value of the requested environment variable, or an empty
 * string if not found.
 */
STDNS string
safeGetenv(const char *varName);

/*
 * Compare two strings for equality, ignoring case.
 * For case-sensitive comparison, use (s1 == s2);
 * @param s1 The first string to compare
 * @param s2 The second string to compare
 * @return True if the strings are equal, false if they are not
 */
bool 
stringsAreEqual(const STDNS string& s1, 
		const STDNS string& s2);

/*
 * Compare two strings for equality, ignoring case.
 * For case-sensitive comparison, use (s1 == s2);
 * @param s1 The first string to compare
 * @param s2 The second string to compare
 * @param n The number of characters to compare.
 * @return True if the strings are equal, false if they are not
 */
bool 
stringsAreEqual(const STDNS string& s1, 
		const STDNS string& s2,
		size_t n);

/**
 * A safer alternative to system().
 * <P>This command will escape out (by prepending \) all semicolons, pipes 
 * and redirects (;|&lt;&gt;) present in the command string.</P>
 * @param command The command to be sanitized and run
 * @return The result of running the sanitized version of <EM>command</EM>
 */
int 
saferSystem(const STDNS string& command);

/**
 * Convert encoded characters in form data to normal ASCII. 
 * <P>For example, %21 is converted to ! and + is converted to a space.
 * Normally, this is called internally to decode the query string or post 
 * data.</P>
 * @param src The src string containing the encoded characters
 * @return The converted string
 */
STDNS string
unescapeString(const STDNS string& src);

/**
 * Convert a hex-encoded character to its ASCII equivalent.
 * <P>For example, after the call
 * <PRE class="code">
 * . char c = hexToChar('2', '1');
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
 * Extract a substring contained within two separators.
 * <P>For example, after the call
 * <PRE class="code">
 * STDNS string data = "11foo22";
 *
 * STDNS string res;
 * res = extractBetween(data, "11", "22");
 * </PRE>
 * <TT>res</TT> will be "foo".
 * @param data The data to search.
 * @param separator1 The first logical separator.
 * @param separator2 The second logical separator.
 * return The substring between the separators.
 */
STDNS string
extractBetween(const STDNS string& data, 
	       const STDNS string& separator1, 
	       const STDNS string& separator2);

/**
 * Extract a substring contained between a separator.
 * @param data The data to search.
 * @param separator The separator.
 * return The substring between the separator.
 */
inline STDNS string
extractBetween(const STDNS string& data, 
	       const STDNS string& separator)
{ return extractBetween(data, separator, separator); }

/**
 * Write a string to an ostream.
 * <P>This function is used internally by Cgicc for saving environments.</P>
 * @param out The ostream to which to write.
 * @param s The string to write.
 */
void 
writeString(STDNS ostream& out, 
	    const STDNS string& s);

/**
 * Write a long to an ostream.
 * <P>This function is used internally by Cgicc for saving environments.</P>
 * @param out The ostream to which to write.
 * @param l The long to write.
 */
void 
writeLong(STDNS ostream& out, 
	  unsigned long l);

/**
 * Read a string from an istream.
 * <P>This function is used internally by Cgicc for restoring 
 * environments.</P>
 * @param in The istream from which to read.
 * @return The string read.
 */
STDNS string
readString(STDNS istream& in);

/**
 * Read a long from an istream.
 * <P>This function is used internally by Cgicc for restoring 
 * environments.</P>
 * @param in The istream from which to read.
 * @return The long read.
 */
unsigned long
readLong(STDNS istream& in);

CGICC_END_NAMESPACE

#endif /* ! _CGIUTILS_HH_ */
