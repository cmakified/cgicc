/*
 *  $Id: CgiUtils.cpp,v 1.9 2002/12/04 17:04:06 sbooth Exp $
 *
 *  Copyright (C) 1996 - 2002 Stephen F. Booth
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

#ifdef __GNUG__
#  pragma implementation
#endif

#include <stdexcept>
#include <memory>
#include <vector>
#include <cctype> 	// for toupper

#include "cgicc/CgiUtils.h"

// case-insensitive string comparison
// This code based on code from 
// "The C++ Programming Language, Third Edition" by Bjarne Stroustrup
bool 
cgicc::stringsAreEqual(const std::string& s1, 
		       const std::string& s2)
{
  std::string::const_iterator p1 = s1.begin();
  std::string::const_iterator p2 = s2.begin();
  std::string::const_iterator l1 = s1.end();
  std::string::const_iterator l2 = s2.end();

  while(p1 != l1 && p2 != l2) {
    if(std::toupper(*(p1++)) != std::toupper(*(p2++)))
      return false;
  }

  return (s2.size() == s1.size()) ? true : false;
}

// case-insensitive string comparison
bool 
cgicc::stringsAreEqual(const std::string& s1, 
		       const std::string& s2,
		       size_t n)
{
  std::string::const_iterator p1 = s1.begin();
  std::string::const_iterator p2 = s2.begin();
  bool good = (n <= s1.length() && n <= s2.length());
  std::string::const_iterator l1 = good ? (s1.begin() + n) : s1.end();
  std::string::const_iterator l2 = good ? (s2.begin() + n) : s2.end();

  while(p1 != l1 && p2 != l2) {
    if(std::toupper(*(p1++)) != std::toupper(*(p2++)))
      return false;
  }
  
  return good;
}

char
cgicc::hexToChar(char first, 
		 char second)
{
  int digit;
  digit = (first >= 'A' ? ((first & 0xDF) - 'A') + 10 : (first - '0'));
  digit *= 16;
  digit += (second >= 'A' ? ((second & 0xDF) - 'A') + 10 : (second - '0'));
  return static_cast<char>(digit);
}

std::string
cgicc::unescapeString(const std::string& src)
{
  std::string result;
  std::string::const_iterator iter;
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
std::string
cgicc::extractBetween(const std::string& data, 
		      const std::string& separator1, 
		      const std::string& separator2)
{
  std::string result;
  unsigned int start, limit;
  
  start = data.find(separator1, 0);
  if(start != std::string::npos) {
    start += separator1.length();
    limit = data.find(separator2, start);
    if(limit != std::string::npos)
      result = data.substr(start, limit - start);
  }
  
  return result;
}

// write a string
void 
cgicc::writeString(std::ostream& out, 
		   const std::string& s)
{ 
  out << s.length() << ' ';
  out.write(s.data(), s.length()); 
}

// write a long
void 
cgicc::writeLong(std::ostream& out, 
		 unsigned long l)
{ 
  out << l << ' '; 
}

// read a string
std::string
cgicc::readString(std::istream& in)
{
  std::string::size_type dataSize = 0;
  
  in >> dataSize;
  in.get(); // skip ' '
  
  // Avoid allocation of a zero-length vector
  if(dataSize == 0) {
    return std::string("");
  }

  // Don't use auto_ptr, but vector instead
  // Bug reported by bostjan@optonline.net / fix by alexoss@verizon.net
  std::vector<char> temp(dataSize);

  in.read(&temp[0], dataSize);
  if((std::string::size_type)in.gcount() != dataSize) {
    throw std::runtime_error("I/O error");
  }

  return std::string(&temp[0], dataSize);
}

// read a long
unsigned long
cgicc::readLong(std::istream& in)
{
  unsigned long l;

  in >> l;
  in.get(); // skip ' '
  return l;
}

