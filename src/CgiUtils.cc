/*
 *  $Id: CgiUtils.cc,v 1.6 1999/06/01 17:10:18 sbooth Exp $
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

#ifdef __GNUG__
#pragma implementation
#endif

#include <stdexcept>
#include <cstdlib> 	// for getenv, system
#include <cctype> 	// for toupper

#include "CgiUtils.hh"

// Fetch an environment variable
STDNS string
CGICCNS safeGetenv(const char *varName)
{
  char *var = getenv(varName);
  return (var == 0) ? "" : var;
}

// case-insensitive string comparison
// This code based on code from 
// "The C++ Programming Language, Third Edition" by Bjarne Stroustrup
bool 
CGICCNS stringsAreEqual(const STDNS string& s1, 
			const STDNS string& s2)
{
  STDNS string::const_iterator p1 = s1.begin();
  STDNS string::const_iterator p2 = s2.begin();
  STDNS string::const_iterator l1 = s1.end();
  STDNS string::const_iterator l2 = s2.end();

  while(p1 != l1 && p2 != l2) {
    if(toupper(*(p1++)) != toupper(*(p2++)))
      return false;
  }

  return (s2.size() == s1.size()) ? true : false;
}

// case-insensitive string comparison
bool 
CGICCNS stringsAreEqual(const STDNS string& s1, 
			const STDNS string& s2,
			size_t n)
{
  STDNS string::const_iterator p1 = s1.begin();
  STDNS string::const_iterator p2 = s2.begin();
  bool good = (n <= s1.length() && n <= s2.length());
  STDNS string::const_iterator l1 = good ? (s1.begin() + n) : s1.end();
  STDNS string::const_iterator l2 = good ? (s2.begin() + n) : s2.end();

  while(p1 != l1 && p2 != l2) {
    if(toupper(*(p1++)) != toupper(*(p2++)))
      return false;
  }
  
  return good;
}

// A safer alternative to system()
int 
CGICCNS saferSystem(const STDNS string& command)
{
  STDNS string s = command;
  STDNS string::size_type pos = 0;

  // escape out all semicolons, pipes, and redirects
  while(true) {
    pos = s.find_first_of(";|<>", pos);
    if(pos == STDNS string::npos)
      break;
    s.insert(pos++, 1, '\\');
    ++pos;
  }

  // make the call
  return system(s.c_str());
}

char
CGICCNS hexToChar(char first, 
		  char second)
{
  char digit;
  digit = (first >= 'A' ? ((first & 0xDF) - 'A') + 10 : (first - '0'));
  digit *= 16;
  digit += (second >= 'A' ? ((second & 0xDF) - 'A') + 10 : (second - '0'));
  return digit;
}

STDNS string
CGICCNS unescapeString(const string& src)
{
  STDNS string result;
  STDNS string::const_iterator iter;
  char c;

  for(iter = src.begin(); iter != src.end(); ++iter) {
    switch(*iter) {
    case '+':
      result.append(1, ' ');
      break;
    case '%':
      // assume well-formed input
      // ensure evaluation order for hexToChar
      c = *++iter;
      result.append(1, hexToChar(c, *(++iter)));
      break;
    default:
      result.append(1, *iter);
      break;
    }
  }
  
  return result;
}

// locate data between separators, and return it
STDNS string
CGICCNS extractBetween(const STDNS string& data, 
		       const STDNS string& separator1, 
		       const STDNS string& separator2)
{
  STDNS string result;
  unsigned int start, limit;
  
  start = data.find(separator1, 0);
  if(start != STDNS string::npos) {
    start += separator1.length();
    limit = data.find(separator2, start);
    if(limit != STDNS string::npos)
      result = data.substr(start, limit - start);
  }
  
  return result;
}

// write a string
void 
CGICCNS writeString(STDNS ostream& out, 
		    const STDNS string& s)
{ 
  out << s.length() << ' ' << s.data(); 
}

// write a long
void 
CGICCNS writeLong(STDNS ostream& out, 
		  unsigned long l)
{ 
  out << l << ' '; 
}

// read a string
STDNS string
CGICCNS readString(STDNS istream& in)
{
  STDNS string::size_type dataSize = 0;
  STDNS string s;
  
  in >> dataSize;
  in.get(); // skip ' '
  // should work, but not in egcs-1.1.2
  //auto_ptr<char> temp = new char[dataSize];
  char *temp = new char[dataSize];
  in.read(temp, dataSize);
  if(in.gcount() != dataSize) {
    delete [] temp;
    throw STDNS runtime_error("I/O error");
  }
  s = STDNS string(temp, dataSize);
  delete [] temp;
  return s;
}

// read a long
unsigned long
CGICCNS readLong(STDNS istream& in)
{
  unsigned long l;

  in >> l;
  in.get(); // skip ' '
  return l;
}

