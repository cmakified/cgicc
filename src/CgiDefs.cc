/*
 * $Id: CgiDefs.cc,v 1.4 1998/12/08 23:14:33 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
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

#include "CgiDefs.hh"

#include <ctype.h>
#include <stdlib.h>

/* Fetch an environment variable - will NEVER return 0, only "" or a value */
void 	
safeGetenv(const char 	*varName, 
	   char*	&where) throw(Exception)
{
  char *var = getenv(varName);
  
  if(var != NULL) {
    where = new char[ strlen(var) + 1];
    if( ! where )
      throw Exception("new failed", ERRINFO);
    strcpy(where, var);
  }
  else {
    where = new char[1];
    if( ! where )
      throw Exception("new failed", ERRINFO);
    where[0] = '\0';
  }
}

/* A safer alternative to system() */
int 
saferSystem(const char *command) throw(Exception)
{
  char *s, *sp;
  int result = 0, len = 3*strlen(command) + 1;	// worst case is all | or ;
  
  s = new char[len];
  if( ! s )
    throw Exception("new failed", ERRINFO);
  sp = s;
  for(int i = 0; i < len; i++) {
    if(command[i] == ';')
      *sp++ = '\\';
    else if(command[i] == '|')
      *sp++ = '\\';
    *sp++ = command[i];
  }
  *sp = '\0';
  result = system(s);
  delete [] s;
  
  return result;
}

inline char 
firstNonspaceChar(const char *s) 
{
  int i;
  for(i = 0; i < strlen(s); ++i)
    if( ! isspace(s[i]))
      break;
  return s[i];
}

inline char
hexToChar(char first, char second)
{
  char digit;
  digit = (first >= 'A' ? ((first & 0xDF) - 'A') + 10 : (first - '0'));
  digit *= 16;
  digit += (second >= 'A' ? ((second & 0xDF) - 'A') + 10 : (second - '0'));
  return digit;
}

void
unescapeChars(const char *src, int len, char* &result) throw(Exception)
{
  int srcPos = 0, dstPos = 0;
  char c = 0x00;
  result = new char[ len + 1 ];

  if( ! result ) 
    throw Exception("new failed", ERRINFO);

  while( srcPos < len ) {
    c = src[srcPos++];
    if(c == '+')
      result[dstPos++] = ' ';
    else if(c == '%') {
      result[dstPos++] = hexToChar(src[srcPos], src[srcPos + 1]);
      srcPos += 2;
    }
    else
      result[dstPos++] = c;
  }
  result[dstPos] = '\0';
}

/* find first occurence of search in data, and return index of first char */
int
findBytes(const char *data, int dataLen, const char *search)
{
  const char *d = data;
  bool gotMatch = false;

  while(gotMatch == false) {
    while( (*d++ != search[0]) && (d - data < dataLen)); // do nothing
    if(d - data > dataLen)
      return -1;
    *d--;
    if(bytesAreEqual(d, search, strlen(search)))
      gotMatch = true;
    else
      *d++;
  }
  
  return (d - data);
}

/* locate data between separators, and return the boundaries */
void
extractBetween(const char *data, int dataLen, 
	       const char *separator1, const char *separator2,
	       int &start, int &end)
{
  start = findBytes(data, dataLen, separator1);
  if(start != -1) {
    start += strlen(separator1);
    end = findBytes(data + start, dataLen - start, separator2);
    if(end != -1)
      end += start;
  }
  else
    end = -1;
}

void
extractBetween(const char *data, int dataLen, const char *separator, 
	       int &start, int &end)
{ extractBetween(data, dataLen, separator, separator, start, end); }

//EOF

