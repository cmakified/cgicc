/* -*-c++-*- */
/*
 *  $Id: Cgicc.h,v 1.6 2001/03/09 23:22:37 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001 Stephen F. Booth
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

#ifndef _CGICC_H_
#define _CGICC_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*
 * The GNU Cgicc library, by Stephen F. Booth. 
 *
 * The latest version can be found on your closest GNU mirror site.
 *
 * Please mail bug reports to <mailto:bug-cgicc@gnu.org>
 *
 * To subscribe, send a message to <mailto:bug-cgicc-request@gnu.org>
 * with the word "subscribe" in the subject field.
 *
 * Cgicc is intended to simplify and speed the development of C++
 * CGI(Common Gateway Interface) applications by providing a simple,
 * yet comprehensive set of classes that present full CGI
 * functionality.  
 */

#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/FormEntry.h"
#include "cgicc/FormFile.h"
#include "cgicc/CgiEnvironment.h"

CGICC_BEGIN_NAMESPACE

#ifdef WIN32
  template class CGICC_API STDNS vector<FormEntry>;
  template class CGICC_API STDNS vector<FormFile>;
#endif
  
class MultipartHeader;

// ============================================================
// Iterator typedefs
// ============================================================
typedef STDNS vector<FormEntry>::iterator 	form_iterator;
typedef STDNS vector<FormEntry>::const_iterator const_form_iterator;

typedef STDNS vector<FormFile>::iterator 	file_iterator;
typedef STDNS vector<FormFile>::const_iterator 	const_file_iterator;

// ============================================================
// Class Cgicc
// ============================================================
/**
 * Cgicc is the main class of the Cgicc library.
 * <P>Normally, you will instantiate an object of this type in 
 * <TT>main()</TT>:</P>
 * <PRE CLASS="code">
 * int
 * main(int argc, char **argv) {
 *   try {
 *     Cgicc cgi;
 *     <SPAN CLASS="green">\\ do something with cgi</SPAN>
 *   }
 *
 *   catch(const exception& e) {
 *    <SPAN CLASS="green"> \\ handle the error</SPAN>
 *   }
 * }
 * </PRE>
 */
class CGICC_API Cgicc {
public:
  
  /** Constructor */
  Cgicc(reader_function_t stream_reader = NULL);
  
  /** Destructor */
  ~Cgicc();
  
  
  /**
   * Get the date on which this library was compiled.
   * <P>This is a string of the form mmm dd yyyy.</P>
   * @return The compile date
   */
  const char*
  getCompileDate() 					const;
  
  /**
   * Get the time at which this library was compiled.
   * <P>This is a string of the form hh:mm:ss in 24-hour time.</P>
   * @return The compile time
   */
  const char*
  getCompileTime() 					const;
  
  /**
   * Get the version number of Cgicc.
   * <P>The version number is a string of the form #.#.</P>
   * @return The version number
   */
  const char*
  getVersion() 						const;

  /** 
   * Get the platform for which Cgicc was configured.
   * <P>The host is a string of the form processor-manufacturer-os</P>
   * @return The host triplet.
   */
  const char*
  getHost() 						const;

  
  /**
   * Query whether a checkbox is checked.
   * @param elementName The name of the element to query
   * @return True if the desired checkbox was checked, false if not
   */
  bool 
  queryCheckbox(const STDNS string& elementName) 	const;
  
  /**
   * Find a radio button in a radio group, or a selected list item.
   * @param name The name of the radio button or list item to find.
   * @return An iterator referring to the desired element, if found.
   */
  inline form_iterator 
  operator[] (const STDNS string& name)
    { return getElement(name); }

  /**
   * Find a radio button in a radio group, or a selected list item.
   * @param name The name of the radio button or list item to find.
   * @return An iterator referring to the desired element, if found.
   */
  inline const_form_iterator 
  operator[] (const STDNS string& name) 		const
    { return getElement(name); }
  
  /**
   * Find a radio button in a radio group, or a selected list item.
   * @param name The name of the radio button or list item to find.
   * @return An iterator referring to the desired element, if found.
   */
  form_iterator 
  getElement(const STDNS string& name);
  
  /**
   * Find a radio button in a radio group, or a selected list item.
   * @param name The name of the radio button or list item to find.
   * @return A const_iterator referring to the desired element, if found.
   */
  const_form_iterator 
  getElement(const STDNS string& name) 			const;
  
  /**
   * Find multiple checkboxes in a group or selected items in a list.
   * @param name The name of the checkboxes or list to find.
   * @param result A vector to hold the result.
   * @return true if any elements were found, false if not.
   */
  bool 
  getElement(const STDNS string& name,
	     STDNS vector<FormEntry>& result) 		const;

  /**
   * Find a radio button in a radio group, or a selected list item.
   * @param value The value of the radio button or list item to find.
   * @return An iterator referring to the desired element, if found.
   */
  form_iterator 
  getElementByValue(const STDNS string& value);
  
  /**
   * Find a radio button in a radio group, or a selected list item.
   * @param value The value of the radio button or list item to find.
   * @return A const_iterator referring to the desired element, if found.
   */
  const_form_iterator 
  getElementByValue(const STDNS string& value) 		const;
  
  /**
   * Find multiple checkboxes in a group or selected items in a list.
   * @param value The value of the checkboxes or list to find.
   * @param result A vector to hold the result.
   * @return true if any elements were found, false if not.
   */
  bool 
  getElementByValue(const STDNS string& value,
		    STDNS vector<FormEntry>& result) 	const;

  /**
   * Get all the submitted form entries, excluding files.
   * @return A vector containing all the submitted elements.
   */
  inline const STDNS vector<FormEntry>& 
  operator* () 						const
    { return fFormData; }
  
  /**
   * Get all the submitted form elements, excluding files.
   * @return A vector containing all the submitted elements.
   */
  inline const STDNS vector<FormEntry>&
  getElements() 					const
    { return fFormData; }


  /**
   * Find an uploaded file.
   * @param name The name of the file.
   * @return An iterator referring to the desired file, if found.
   */
  file_iterator 
  getFile(const STDNS string& name);
  
  /**
   * Find an uploaded file.
   * @param name The name of the file.
   * @return An iterator referring to the desired file, if found.
   */
  const_file_iterator 
  getFile(const STDNS string& name) 			const;

  /** 
   * Get all uploaded files.
   * @return A vector containing all the uploaded files.
   */
  inline const STDNS vector<FormFile>&
  getFiles() 						const
    { return fFormFiles; }

  
  /**
   * Get the current runtime environment.
   * @return The current CGI environment.
   */
  inline const CgiEnvironment&
  getEnvironment() 					const
    { return fEnvironment;}

  
  /**
   * Save the current CGI environment to a file.
   * @param filename The name of the file to which to save.
   */
  void 
  save(const STDNS string& filename) 			const;
  
  /**
   * Restore from a previously-saved CGI environment.
   * @param filename The name of the file from which to restore.
   */
  void 
  restore(const STDNS string& filename);
  
private:
  CgiEnvironment 		fEnvironment;
  STDNS vector<FormEntry> 	fFormData;
  STDNS vector<FormFile> 	fFormFiles;
  
  // Convert query string into a list of FormEntries
  void 
  parseFormInput(const STDNS string& data);
  
  // Parse a multipart/form-data header
  MultipartHeader
  parseHeader(const STDNS string& data);
  
  // Parse a (name=value) form entry
  void 
  parsePair(const STDNS string& data);
  
  // Parse a MIME entry for ENCTYPE=""
  void
  parseMIME(const STDNS string& data);

  // Find elements in the list of entries
  bool 
  findEntries(const STDNS string& param, 
	      bool byName,
	      STDNS vector<FormEntry>& result) 		const;
};

CGICC_END_NAMESPACE

#endif /* ! _CGICC_H_ */
