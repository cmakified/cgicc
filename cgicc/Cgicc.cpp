/*
 *  $Id: Cgicc.cpp,v 1.16 2003/07/13 14:20:35 sbooth Exp $
 *
 *  Copyright (C) 1996 - 2003 Stephen F. Booth
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

#include <new>
#include <algorithm>
#include <functional>
#include <iterator>

#if (HAVE_SYS_TIME_H && TM_IN_SYS_TIME)
#include <sys/time.h>
#else
#include <time.h>
#endif

#include "cgicc/CgiUtils.h"
#include "cgicc/Cgicc.h"


namespace cgicc {

  // ============================================================
  // Class FE_nameCompare
  // ============================================================
  class FE_nameCompare : public std::unary_function<FormEntry, bool>
  {
  public:
    
    inline explicit FE_nameCompare(const std::string& name)
      : fName(name) {}
    
    inline bool operator() (const FormEntry& entry) 	const
    { return stringsAreEqual(fName, entry.getName()); }
    
  private:
    std::string fName;
  };
  
  // ============================================================
  // Class FE_valueCompare
  // ============================================================
  class FE_valueCompare : public std::unary_function<FormEntry, bool>
  {
  public:
    
    inline explicit FE_valueCompare(const std::string& value)
      : fValue(value) {}
    
    inline bool operator() (const FormEntry& entry) 	const
    { return stringsAreEqual(fValue, entry.getValue()); }
    
  private:
    std::string fValue;
  };
  
  
  // ============================================================
  // Class FF_compare
  // ============================================================
  class FF_compare : public std::unary_function<FormFile, bool>
  {
  public:
    
    inline explicit FF_compare(const std::string& name)
      : fName(name) {}
    
    inline bool operator() (const FormFile& entry) 	const
    { return stringsAreEqual(fName, entry.getName()); }
    
  private:
    std::string fName;
  };
  
  // ============================================================
  // Function copy_if (handy, missing from STL)
  // ============================================================
  // This code taken directly from 
  // "The C++ Programming Language, Third Edition" by Bjarne Stroustrup
  template<class In, class Out, class Pred>
  Out 
  copy_if(In first, 
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
  
} // namespace cgicc

// ============================================================
// Class MultipartHeader
// ============================================================
class cgicc::MultipartHeader 
{
public:
  
  MultipartHeader(const std::string& disposition,
		  const std::string& name,
		  const std::string& filename,
		  const std::string& cType);
  
  MultipartHeader(const MultipartHeader& head);
  ~MultipartHeader();

  MultipartHeader&
  operator= (const MultipartHeader& head);
  
  inline std::string 
  getContentDisposition() 				const
    { return fContentDisposition; }
  
  inline std::string
  getName() 						const
    { return fName; }

  inline std::string 
  getFilename() 					const
    { return fFilename; }

  inline std::string 
  getContentType() 					const
    { return fContentType; }

private:
  std::string fContentDisposition;
  std::string fName;
  std::string fFilename;
  std::string fContentType;
};

cgicc::MultipartHeader::MultipartHeader(const std::string& disposition,
					const std::string& name,
					const std::string& filename,
					const std::string& cType)
  : fContentDisposition(disposition),
    fName(name),
    fFilename(filename),
    fContentType(cType)
{}

cgicc::MultipartHeader::MultipartHeader(const MultipartHeader& head)
{ 
  // call operator=
  *this = head;
}

cgicc::MultipartHeader::~MultipartHeader()
{}

cgicc::MultipartHeader&
cgicc::MultipartHeader::operator= (const MultipartHeader& head)
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
cgicc::Cgicc::Cgicc(CgiInput *input)
  : fEnvironment(input)
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

cgicc::Cgicc::~Cgicc()
{
  LOGLN("Cleaning up...")
  LOGLN("Cgicc debugging log closed.")
}

const char*
cgicc::Cgicc::getCompileDate() 					const
{ return __DATE__; }

const char*
cgicc::Cgicc::getCompileTime() 					const
{ return __TIME__; }

const char*
cgicc::Cgicc::getVersion() 					const
{ return VERSION; }

const char*
cgicc::Cgicc::getHost() 					const
{ return HOST; }

void
cgicc::Cgicc::save(const std::string& filename) 		const
{
  LOGLN("Cgicc::save")
  getEnvironment().save(filename);
}

void
cgicc::Cgicc::restore(const std::string& filename)
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
cgicc::Cgicc::queryCheckbox(const std::string& elementName) 	const
{
  const_form_iterator iter = getElement(elementName);
  return ((iter != fFormData.end()) && 
	  stringsAreEqual( (*iter).getValue(), "on"));
}

cgicc::form_iterator 
cgicc::Cgicc::getElement(const std::string& name)
{
  return std::find_if(fFormData.begin(), fFormData.end(), 
		       FE_nameCompare(name));
}

cgicc::const_form_iterator 
cgicc::Cgicc::getElement(const std::string& name) 		const
{
  return std::find_if(fFormData.begin(), fFormData.end(), 
		       FE_nameCompare(name));
}

bool 
cgicc::Cgicc::getElement(const std::string& name, 
			  std::vector<FormEntry>& result) 	const
{ 
  return findEntries(name, true, result); 
}

cgicc::form_iterator 
cgicc::Cgicc::getElementByValue(const std::string& value)
{
  return std::find_if(fFormData.begin(), fFormData.end(), 
		       FE_valueCompare(value));
}

cgicc::const_form_iterator 
cgicc::Cgicc::getElementByValue(const std::string& value) 	const
{
  return std::find_if(fFormData.begin(), fFormData.end(), 
		       FE_valueCompare(value));
}

bool 
cgicc::Cgicc::getElementByValue(const std::string& value, 
				 std::vector<FormEntry>& result)	const
{ 
  return findEntries(value, false, result); 
}

cgicc::file_iterator 
cgicc::Cgicc::getFile(const std::string& name)
{
  return std::find_if(fFormFiles.begin(), fFormFiles.end(), 
		       FF_compare(name));
}

cgicc::const_file_iterator 
cgicc::Cgicc::getFile(const std::string& name) 			const
{
  return std::find_if(fFormFiles.begin(), fFormFiles.end(), 
		       FF_compare(name));
}


// implementation method
bool
cgicc::Cgicc::findEntries(const std::string& param, 
			  bool byName,
			  std::vector<FormEntry>& result) 	const
{
  // empty the target vector
  result.clear();

  if(byName)
    copy_if(fFormData.begin(), 
	    fFormData.end(), 
	    std::back_inserter(result),
	    FE_nameCompare(param));
  else
    copy_if(fFormData.begin(), 
	    fFormData.end(), 
	    std::back_inserter(result),
	    FE_valueCompare(param));

  return ! result.empty();
}

void
cgicc::Cgicc::parseFormInput(const std::string& data)
{
  std::string env 	= getEnvironment().getContentType();
  std::string cType 	= "multipart/form-data";
  LOGLN(data)
  if(stringsAreEqual(cType, env, cType.length())) {
    LOGLN("Multipart data detected.")

    // Find out what the separator is
    std::string 		bType 	= "boundary=";
    std::string::size_type 	pos 	= env.find(bType);

    // generate the separators
    std::string sep = env.substr(pos + bType.length());
    sep.append("\r\n");
    sep.insert(0, "--");

    std::string sep2 = env.substr(pos + bType.length());
    sep2.append("--\r\n");
    sep2.insert(0, "--");

    // Find the data between the separators
    std::string::size_type start  = data.find(sep);
    std::string::size_type sepLen = sep.length();
    std::string::size_type oldPos = start + sepLen;

    while(true) {
      pos = data.find(sep, oldPos);

      // If sep wasn't found, the rest of the data is an item
      if(pos == std::string::npos)
	break;

      // parse the data
      parseMIME(data.substr(oldPos, pos - oldPos));

      // update position
      oldPos = pos + sepLen;
    }

    // The data is terminated by sep2
    pos = data.find(sep2, oldPos);
    // parse the data, if found
    if(pos != std::string::npos) {
      parseMIME(data.substr(oldPos, pos - oldPos));
    }
  }
  else if(! data.empty()) {
    std::string::size_type pos;
    std::string::size_type oldPos = 0;

    while(true) {
      // find the '&' separating a name=value pairs
      pos = data.find_first_of("&", oldPos);

      // if no '&' was found, the rest of the string is a pair
      if(pos == std::string::npos) {
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

cgicc::MultipartHeader
cgicc::Cgicc::parseHeader(const std::string& data)
{
  std::string disposition;
  disposition = extractBetween(data, "Content-Disposition: ", ";");
  
  std::string name;
  name = extractBetween(data, "name=\"", "\"");
  
  std::string filename;
  filename = extractBetween(data, "filename=\"", "\"");

  std::string cType;
  cType = extractBetween(data, "Content-Type: ", "\r\n\r\n");

  // This is hairy: Netscape and IE don't encode the filenames
  // The RFC says they should be encoded, so I will assume they are.
  filename = form_urldecode(filename);

  return MultipartHeader(disposition, name, filename, cType);
}

void
cgicc::Cgicc::parsePair(const std::string& data)
{
  // find the '=' separating the name and value
  std::string::size_type pos = data.find_first_of("=", 0);

  // if no '=' was found, return
  if(pos == std::string::npos)
    return;
  
  // unescape the data, and add to the form entry list
  std::string name 	= form_urldecode(data.substr(0, pos));
  std::string value 	= form_urldecode(data.substr(++pos, 
						     std::string::npos));
  
  fFormData.push_back(FormEntry(name, value));
}

void
cgicc::Cgicc::parseMIME(const std::string& data)
{
  // Find the header
  std::string end = "\r\n\r\n";
  std::string::size_type headLimit = data.find(end, 0);
  
  // Detect error
  if(headLimit == std::string::npos)
    return;

  // Extract the value - there is still a trailing CR/LF to be subtracted off
  std::string::size_type valueStart = headLimit + end.length();
  std::string value = data.substr(valueStart, data.length() - valueStart - 2);

  // Parse the header - pass trailing CR/LF x 2 to parseHeader
  MultipartHeader head = parseHeader(data.substr(0, valueStart));

  if(head.getFilename().empty())
    fFormData.push_back(FormEntry(head.getName(), value));
  else
    fFormFiles.push_back(FormFile(head.getName(), 
				  head.getFilename(), 
				  head.getContentType(), 
				  value));
}
