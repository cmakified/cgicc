/*
 *  $Id: Cgicc.cc,v 1.15 1999/06/01 17:10:18 sbooth Exp $
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

#include <new>
#include <algorithm>
#include <functional>
#include <iterator>

#if (HAVE_SYS_TIME_H && TM_IN_SYS_TIME)
#include <sys/time.h>
#else
#include <time.h>
#endif

#include "CgiUtils.hh"
#include "Cgicc.hh"


CGICC_BEGIN_NAMESPACE

// Handy function missing from STL
template<class In, class Out, class Pred>
Out 
copy_if(In first, 
	In last, 
	Out res, 
	Pred p);

// ============================================================
// Class FE_nameCompare
// ============================================================
class FE_nameCompare : public STDNS unary_function<FormEntry, bool>
{
public:
  
  inline explicit FE_nameCompare(const STDNS string& name)
    : fName(name) {}
  
  inline bool operator() (const FormEntry& entry) 	const
    { return stringsAreEqual(fName, entry.getName()); }
  
private:
  STDNS string fName;
};

// ============================================================
// Class FE_valueCompare
// ============================================================
class FE_valueCompare : public STDNS unary_function<FormEntry, bool>
{
public:
  
  inline explicit FE_valueCompare(const STDNS string& value)
    : fValue(value) {}
  
  inline bool operator() (const FormEntry& entry) 	const
    { return stringsAreEqual(fValue, entry.getValue()); }
  
private:
  STDNS string fValue;
};


// ============================================================
// Class FF_compare
// ============================================================
class FF_compare : public STDNS unary_function<FormFile, bool>
{
public:
  
  inline explicit FF_compare(const STDNS string& name)
    : fName(name) {}
  
  inline bool operator() (const FormFile& entry) 	const
    { return stringsAreEqual(fName, entry.getName()); }
  
private:
  STDNS string fName;
};

CGICC_END_NAMESPACE


// Handy function missing from STL
// This code taken directly from 
// "The C++ Programming Language, Third Edition" by Bjarne Stroustrup
template<class In, class Out, class Pred>
Out 
CGICCNS copy_if(In first, 
		In last, 
		Out res, 
		Pred p)
{
  while(first != last) {
    if(p(*first))
      *res++ = *first;
    ++first;
  }
  return res;
}

// ============================================================
// Class MultipartHeader
// ============================================================
class CGICCNS MultipartHeader 
{
public:
  
  MultipartHeader(const STDNS string& disposition,
		  const STDNS string& name,
		  const STDNS string& filename,
		  const STDNS string& cType);

  MultipartHeader(const MultipartHeader& head);
  ~MultipartHeader();

  MultipartHeader&
  operator= (const MultipartHeader& head);
  
  inline STDNS string 
  getContentDisposition() 				const
    { return fContentDisposition; }
  
  inline STDNS string
  getName() 						const
    { return fName; }

  inline STDNS string 
  getFilename() 					const
    { return fFilename; }

  inline STDNS string 
  getContentType() 					const
    { return fContentType; }

private:
  STDNS string fContentDisposition;
  STDNS string fName;
  STDNS string fFilename;
  STDNS string fContentType;
};

CGICCNS MultipartHeader::MultipartHeader(const STDNS string& disposition,
					 const STDNS string& name,
					 const STDNS string& filename,
					 const STDNS string& cType)
  : fContentDisposition(disposition),
    fName(name),
    fFilename(filename),
    fContentType(cType)
{}

CGICCNS MultipartHeader::MultipartHeader(const MultipartHeader& head)
{ 
  // call operator=
  *this = head;
}

CGICCNS MultipartHeader::~MultipartHeader()
{}

CGICCNS MultipartHeader&
CGICCNS MultipartHeader::operator= (const MultipartHeader& head)
{
  fContentDisposition 	= head.fContentDisposition;
  fName 		= head.fName;
  fFilename 		= head.fFilename;
  fContentType 		= head.fContentType;

  return *this;
}

// ============================================================
// Class Cgicc
// ============================================================
CGICCNS Cgicc::Cgicc()
  : fEnvironment()
{
#if DEBUG
#if HAVE_STRFTIME
  time_t 	now;
  tm 		*date;
  char 		s[80];
  
  now = time(0);
  date = localtime(&now);
  strftime(s, 80, "%A, %B %d, %Y %I:%M:%S %p", date);
  LOG("Cgicc debugging log started on ")
  LOGLN(s)
#else
  LOGLN("Cgicc debugging log started.")
#endif /* HAVE_STRFTIME */
#endif /* DEBUG */
  
  // this can be tweaked for performance
  fFormData.reserve(40);
  fFormFiles.reserve(5);
  
  if(stringsAreEqual(getEnvironment().getRequestMethod(), "post"))
    parseFormInput(getEnvironment().getPostData());
  else
    parseFormInput(getEnvironment().getQueryString());
}

CGICCNS Cgicc::~Cgicc()
{
  LOGLN("Cleaning up...")
  LOGLN("Cgicc debugging log closed.")
}

STDNS string
CGICCNS Cgicc::getCompileDate() 				const
{ return __DATE__; }

STDNS string
CGICCNS Cgicc::getCompileTime() 				const
{ return __TIME__; }

STDNS string
CGICCNS Cgicc::getVersion() 					const
{ return VERSION; }

STDNS string
CGICCNS Cgicc::getHost() 					const
{ return HOST; }

void
CGICCNS Cgicc::save(const STDNS string& filename) 		const
{
  LOGLN("Cgicc::save")
  getEnvironment().save(filename);
}

void
CGICCNS Cgicc::restore(const STDNS string& filename)
{
  LOGLN("Cgicc::restore")
  
  ((CgiEnvironment&)getEnvironment()).restore(filename);

  // clear the current data and re-parse the enviroment
  fFormData.clear();
  fFormFiles.clear();
  if(stringsAreEqual(getEnvironment().getRequestMethod(), "post"))
    parseFormInput(getEnvironment().getPostData());
  else
    parseFormInput(getEnvironment().getQueryString());
}

bool 
CGICCNS Cgicc::queryCheckbox(const STDNS string& elementName) 	const
{
  STDNS vector<FormEntry>::const_iterator iter = getElement(elementName);
  return ((iter != fFormData.end()) && 
	  stringsAreEqual( (*iter).getValue(), "on"));
}

STDNS vector<CGICCNS FormEntry>::iterator 
CGICCNS Cgicc::getElement(const STDNS string& name)
{
  return STDNS find_if(fFormData.begin(), fFormData.end(), 
		       FE_nameCompare(name));
}

STDNS vector<CGICCNS FormEntry>::const_iterator 
CGICCNS Cgicc::getElement(const STDNS string& name) 		const
{
  return STDNS find_if(fFormData.begin(), fFormData.end(), 
		       FE_nameCompare(name));
}

bool 
CGICCNS Cgicc::getElement(const STDNS string& name, 
			  STDNS vector<FormEntry>& result) 	const
{ 
  return findEntries(name, true, result); 
}

STDNS vector<CGICCNS FormEntry>::iterator 
CGICCNS Cgicc::getElementByValue(const STDNS string& value)
{
  return STDNS find_if(fFormData.begin(), fFormData.end(), 
		       FE_valueCompare(value));
}

STDNS vector<CGICCNS FormEntry>::const_iterator 
CGICCNS Cgicc::getElementByValue(const STDNS string& value) 	const
{
  return STDNS find_if(fFormData.begin(), fFormData.end(), 
		       FE_valueCompare(value));
}

bool 
CGICCNS Cgicc::getElementByValue(const STDNS string& value, 
				 STDNS vector<FormEntry>& result) 	const
{ 
  return findEntries(value, true, result); 
}

STDNS vector<CGICCNS FormFile>::iterator 
CGICCNS Cgicc::getFile(const STDNS string& name)
{
  return STDNS find_if(fFormFiles.begin(), fFormFiles.end(), 
		       FF_compare(name));
}

STDNS vector<CGICCNS FormFile>::const_iterator 
CGICCNS Cgicc::getFile(const STDNS string& name) 		const
{
  return STDNS find_if(fFormFiles.begin(), fFormFiles.end(), 
		       FF_compare(name));
}


// implementation method
bool
CGICCNS Cgicc::findEntries(const STDNS string& param, 
			   bool byName,
			   STDNS vector<FormEntry>& result) 	const
{
  // empty the target vector
  result.clear();

#ifdef _MSC_VER
  // Workaround for Microsoft C++ compiler bug, which is unable to instantiate
  // the copy_if() template functions.
  if(byName) {
    STDNS vector<FormEntry>::const_iterator i = fFormData.begin();
    while(i != fFormData.end()) {
      if(stringsAreEqual((*i).getName(), param))
        result.push_back(*i);
      ++i;
    }
  }
  else {
    STDNS vector<FormEntry>::const_iterator i = fFormData.begin();
    while(i != fFormData.end()) {
      if(stringsAreEqual((*i).getValue(), param))
        result.push_back(*i);
      ++i;
    }
  }
#else
  if(byName)
    copy_if(fFormData.begin(), 
	    fFormData.end(), 
	    STDNS back_inserter(result),
	    FE_nameCompare(param));
  else
    copy_if(fFormData.begin(), 
	    fFormData.end(), 
	    STDNS back_inserter(result),
	    FE_valueCompare(param));
#endif 
  return ! result.empty();
}

void
CGICCNS Cgicc::parseFormInput(const STDNS string& data)
{
  STDNS string env 	= getEnvironment().getContentType();
  STDNS string cType 	= "multipart/form-data";

  if(stringsAreEqual(cType, env, cType.length())) {
    LOGLN("Multipart data detected.")

    // Find out what the separator is
    STDNS string 		bType 	= "boundary=";
    STDNS string::size_type 	pos 	= env.find(bType);

    // generate the separators
    STDNS string sep = env.substr(pos + bType.length());
    sep.append("\r\n");
    sep.insert(0, "--");

    STDNS string sep2 = env.substr(pos + bType.length());
    sep2.append("--\r\n");
    sep2.insert(0, "--");

    // Find the data between the separators
    STDNS string::size_type start  = data.find(sep);
    STDNS string::size_type sepLen = sep.length();

    pos = 0;
    STDNS string::size_type oldPos = start + sepLen;

    while(true) {
      pos = data.find(sep, oldPos);

      if(pos == STDNS string::npos)
	break;

      // parse the data
      parseMIME(data.substr(oldPos, pos - oldPos));

      // update position
      oldPos = pos + sepLen;
    }
  }
  else if(! data.empty()) {
    STDNS string::size_type pos 	= 0;
    STDNS string::size_type oldPos	= 0;

    while(true) {
      // find the '&' separating a name=value pairs
      pos = data.find_first_of("&", oldPos);

      // if no '&' was found, the rest of the string is a pair
      if(pos == STDNS string::npos) {
	parsePair(data.substr(oldPos));
	break;
      }
      
      // otherwise, parse the name=value pair
      parsePair(data.substr(oldPos, pos - oldPos));
      
      // update position
      oldPos = pos + 1;
    }
  }
}

CGICCNS MultipartHeader
CGICCNS Cgicc::parseHeader(const STDNS string& data)
{
  STDNS string disposition;
  disposition = extractBetween(data, "Content-Disposition: ", ";");
  
  STDNS string name;
  name = extractBetween(data, "name=\"", "\"");
  
  STDNS string filename;
  filename = extractBetween(data, "filename=\"", "\"");

  STDNS string cType;
  cType = extractBetween(data, "Content-Type: ", "\r\n\r\n");

  // This is hairy: Netscape and IE don't encode the filenames
  // The RFC says they should be encoded, so I will assume they are.
  filename = unescapeString(filename);

  return MultipartHeader(disposition, name, filename, cType);
}

void
CGICCNS Cgicc::parsePair(const STDNS string& data)
{
  // find the '=' separating the name and value
  STDNS string::size_type pos = data.find_first_of("=", 0);

  // if no '=' was found, return
  if(pos == STDNS string::npos)
    return;
  
  // unescape the data, and add to the form entry list
  STDNS string name 	= unescapeString(data.substr(0, pos));
  STDNS string value 	= unescapeString(data.substr(++pos, 
						     STDNS string::npos));
  
  fFormData.push_back(FormEntry(name, value));
}

void
CGICCNS Cgicc::parseMIME(const STDNS string& data)
{
  // Find the header
  STDNS string end = "\r\n\r\n";
  STDNS string::size_type headLimit = data.find(end, 0);
  
  // Detect error
  if(headLimit == STDNS string::npos)
    return;

  // Parse the header
  MultipartHeader head = parseHeader(data.substr(0, headLimit));

  // Extract the value - there is still a trailing CR/LF to be subtracted off
  STDNS string::size_type valueStart = headLimit + end.length();
  STDNS string value = data.substr(valueStart, data.length() - valueStart - 2);

  if(head.getFilename().empty())
    fFormData.push_back(FormEntry(head.getName(), value));
  else
    fFormFiles.push_back(FormFile(head.getName(), 
				  head.getFilename(), 
				  head.getContentType(), 
				  value));
}

//EOF








