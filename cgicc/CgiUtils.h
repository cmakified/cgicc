/* -*-c++-*- */
/*
 *  $Id: CgiUtils.h,v 1.4 2001/09/03 16:19:51 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _CGIUTILS_H_
#define _CGIUTILS_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file CgiUtils.h
 * \brief A collection of utility functions.
 *
 * These utility functions are used internally by cgicc to
 * decode posted form data, and to read/write from streams.
 */

#include <new>
#include <string>
#include <fstream>

#include "cgicc/CgiDefs.h"

#if DEBUG

extern STDNS ofstream gLogFile;
#define LOGLN(s) 	gLogFile << s << STDNS endl;
#define LOG(s) 		gLogFile << s;

#else

/*!
 * \brief Output a string to the debugging log, followed by a newline.
 *
 * The debugging log is a user-specified \c ostream.
 * \param s The string to log
 */
#define LOGLN(s)

/*!
 * \brief Output a string to the debugging log
 *
 * The debugging log is a user-specified \c ostream.
 * \param s The string to log
 */
#define LOG(s)

#endif


CGICC_BEGIN_NAMESPACE

/*!
 * \brief Query the value of an environment variable
 *
 * This function is used internally by CgiEnvironment
 * \param varName The name of an environment variable
 * \return The value of the requested environment variable, or an empty
 * string if not found.
 */
CGICC_API STDNS string
safeGetenv(const char *varName);

/*!
 * \brief Compare two strings for equality, ignoring case.
 *
 * For case-sensitive comparison, use (s1 == s2);
 * \param s1 The first string to compare
 * \param s2 The second string to compare
 * \return \c true if the strings are equal, \c false if they are not
 */
CGICC_API bool
stringsAreEqual(const STDNS string& s1, 
		const STDNS string& s2);

/*!
 * \brief Compare two strings for equality, ignoring case.
 *
 * For case-sensitive comparison, use (s1 == s2);
 * \param s1 The first string to compare
 * \param s2 The second string to compare
 * \param n The number of characters to compare.
 * \return \c true if the strings are equal, \c false if they are not
 */
CGICC_API bool
stringsAreEqual(const STDNS string& s1, 
		const STDNS string& s2,
		size_t n);

/*!
 * \brief A safer alternative to system().
 *
 * This command will escape out (by prepending \) all semicolons, pipes 
 * and redirects (;|<>) present in the command string.
 * \param command The command to be sanitized and run
 * \return The result of running the sanitized version of \e command
 */
CGICC_API int
saferSystem(const STDNS string& command);

/*!
 * \brief Convert encoded characters in form data to normal ASCII. 
 *
 * For example, %21 is converted to ! and + is converted to a space.
 * Normally, this is called internally to decode the query string or post 
 * data.
 * \param src The src string containing the encoded characters
 * \return The converted string
 */
CGICC_API STDNS string
unescapeString(const STDNS string& src);

/*!
 * \brief Convert a hex-encoded character to its ASCII equivalent.
 *
 * For example, after the call
 * \code
 * char c = hexToChar('2', '1');
 * \endcode
 * \c c will have a value of  '!'.
 * Normally, this is called internally to decode encoded characters in
 * the query string or post data.
 * \param first The first character of the hex value
 * \param second the second character of the hex value
 * \return The ASCII character
 */
CGICC_API char
hexToChar(char first, 
	  char second);

/*!
 * \brief Extract a substring contained within two separators.
 *
 * For example, after the call
 * \code
 * STDNS string data = "11foo22";
 * STDNS string res;
 * res = extractBetween(data, "11", "22");
 * \endcode
 * \c res will be "foo".
 * \param data The data to search.
 * \param separator1 The first logical separator.
 * \param separator2 The second logical separator.
 * \return The substring between the separators.
 */
STDNS string
extractBetween(const STDNS string& data, 
	       const STDNS string& separator1, 
	       const STDNS string& separator2);

/*!
 * \brief Extract a substring contained between a separator.
 *
 * This function is used internally to decode \c multipart/form-data
 * \param data The data to search.
 * \param separator The separator.
 * \return The substring between the separator.
 */
inline STDNS string
extractBetween(const STDNS string& data, 
	       const STDNS string& separator)
{ return extractBetween(data, separator, separator); }

/*!
 * \brief Write a string to an ostream.
 *
 * This function is used internally  for saving environments.
 * \param out The ostream to which to write.
 * \param s The string to write.
 */
void 
writeString(STDNS ostream& out, 
	    const STDNS string& s);

/*!
 * \brief Write a long to an ostream.
 *
 * This function is used internally for saving environments.
 * \param out The ostream to which to write.
 * \param l The long to write.
 */
void 
writeLong(STDNS ostream& out, 
	  unsigned long l);

/*!
 * \brief Read a string from an istream.
 *
 * This function is used internally by cgicc for restoring environments.
 * \param in The istream from which to read.
 * \return The string read.
 */
STDNS string
readString(STDNS istream& in);

/*!
 * \brief Read a long from an istream.
 *
 * This function is used internally by cgicc for restoring environments.
 * \param in The istream from which to read.
 * \return The long read.
 */
unsigned long
readLong(STDNS istream& in);

CGICC_END_NAMESPACE

#endif /* ! _CGIUTILS_H_ */
