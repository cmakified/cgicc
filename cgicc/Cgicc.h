/* -*-c++-*- */
/*
 *  $Id: Cgicc.h,v 1.9 2002/03/03 17:40:38 sbooth Exp $
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

#ifndef _CGICC_H_
#define _CGICC_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file Cgicc.h
 * The main header file for the GNU cgicc library
 */

/*
 * The GNU cgicc library, by Stephen F. Booth <sbooth@gnu.org>
 * http://www.cgicc.org
 *
 * The latest version can be found on your closest GNU mirror site.
 * Please mail bug reports to <bug-cgicc@gnu.org>
 */

#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/FormEntry.h"
#include "cgicc/FormFile.h"
#include "cgicc/CgiInput.h"
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

//! A vector of FormEntry objects
typedef STDNS vector<FormEntry>::iterator 	form_iterator;
//! A vector of \c const FormEntry objects
typedef STDNS vector<FormEntry>::const_iterator const_form_iterator;

//! A vector of FormFile objects
typedef STDNS vector<FormFile>::iterator 	file_iterator;
//! A vector of \c const FormFile objects
typedef STDNS vector<FormFile>::const_iterator 	const_file_iterator;

// ============================================================
// Class Cgicc
// ============================================================

/*! \class Cgicc Cgicc.h cgicc/Cgicc.h
 * \brief The main class of the GNU %cgicc library
 *
 * Cgicc is used to retrieve information on specific HTML form elements 
 * (such as checkboxes, radio buttons, and text fields), on uploaded files,
 * and to save, restore, and retrieve information on the CGI
 * environment.
 *
 * Normally, you will instantiate an object of this type in 
 * \c main():
 * \code
 * int
 * main(int argc, char **argv) {
 *   try {
 *     cgicc::Cgicc cgi;
 *     // do something with cgi
 *   }
 *
 *   catch(const exception& e) {
 *    //handle the error
 *   }
 * }
 * \endcode
 */
class CGICC_API Cgicc {
public:

  // ============================================================

  /*! \name Constructor and Destructor */
  //@{

  /*! 
   * \brief Constructor 
   *
   * If you are using %cgicc with FastCGI, you will need to pass 
   * a \c CgiInput subclass that %cgicc will use to read input.  If
   * \c input is omitted, standard input and environment
   * variables will be used.
   * \param input A CgiInput object to use for reading input
   */
  Cgicc(CgiInput input = CgiInput());
  
  /*! 
   * \brief Destructor 
   *
   * Delete this Cgicc object
   */
  ~Cgicc();
  //@}
  
  // ============================================================

  /*! \name Library Information 
   * Information on this installation of %cgicc
   */
  //@{

  /*!
   * \brief Get the date on which this library was compiled.
   * 
   * This is a string of the form <TT>mmm dd yyyy</TT>.
   * \return The compile date
   */
  const char*
  getCompileDate() 					const;
  
  /*!
   * \brief Get the time at which this library was compiled.
   *
   * This is a string of the form \c hh:mm:ss in 24-hour time.
   * \return The compile time
   */
  const char*
  getCompileTime() 					const;
  
  /*!
   * \brief Get the version number of cgicc.
   *
   * The version number is a string of the form \c #.#.
   * \return The version number
   */
  const char*
  getVersion() 						const;

  /*! 
   * \brief Get the platform for which Cgicc was configured.
   *
   * The host is a string of the form \c processor-manufacturer-os
   * return The host triplet.
   */
  const char*
  getHost() 						const;
  //@}
  
  // ============================================================

  /*! \name Form Element Access 
  * Information on submitted form elements
  */
  //@{

  /*!
   * \brief Query whether a checkbox is checked.
   *
   * \param elementName The name of the element to query
   * \return \c true if the desired checkbox was checked, \c false if not
   */
  bool 
  queryCheckbox(const STDNS string& elementName) 	const;
  
  /*!
   * \brief Find a radio button in a radio group, or a selected list item.
   *
   * \param name The name of the radio button or list item to find.
   * \return An iterator referring to the desired element, if found.
   */
  inline form_iterator 
  operator[] (const STDNS string& name)
    { return getElement(name); }

  /*!
   * \brief Find a radio button in a radio group, or a selected list item.
   *
   * \param name The name of the radio button or list item to find.
   * \return An iterator referring to the desired element, if found.
   */
  inline const_form_iterator 
  operator[] (const STDNS string& name) 		const
    { return getElement(name); }
  
  /*!
   * \brief Find a radio button in a radio group, or a selected list item.
   *
   * \param name The name of the radio button or list item to find.
   * \return An iterator referring to the desired element, if found.
   */
  form_iterator 
  getElement(const STDNS string& name);
  
  /*!
   * \brief Find a radio button in a radio group, or a selected list item.
   *
   * \param name The name of the radio button or list item to find.
   * \return A const_iterator referring to the desired element, if found.
   */
  const_form_iterator 
  getElement(const STDNS string& name) 			const;
  
  /*!
   * \brief Find multiple checkboxes in a group or selected items in a list.
   *
   * \param name The name of the checkboxes or list to find.
   * \param result A vector to hold the result.
   * \return \c true if any elements were found, \c false if not.
   */
  bool 
  getElement(const STDNS string& name,
	     STDNS vector<FormEntry>& result) 		const;

  /*!
   * \brief Find a radio button in a radio group, or a selected list item.
   *
   * \param value The value of the radio button or list item to find.
   * \return An iterator referring to the desired element, if found.
   */
  form_iterator 
  getElementByValue(const STDNS string& value);
  
  /*!
   * \brief Find a radio button in a radio group, or a selected list item.
   *
   * \param value The value of the radio button or list item to find.
   * \return A const_iterator referring to the desired element, if found.
   */
  const_form_iterator 
  getElementByValue(const STDNS string& value) 		const;
  
  /*!
   * \brief Find multiple checkboxes in a group or selected items in a list.
   *
   * \param value The value of the checkboxes or list to find.
   * \param result A vector to hold the result.
   * \return true if any elements were found, false if not.
   */
  bool 
  getElementByValue(const STDNS string& value,
		    STDNS vector<FormEntry>& result) 	const;

  /*!
   * \brief Get all the submitted form entries, excluding files.
   *
   * \return A vector containing all the submitted elements.
   */
  inline const STDNS vector<FormEntry>& 
  operator* () 						const
    { return fFormData; }
  
  /*!
   * \brief Get all the submitted form elements, excluding files.
   *
   * \return A vector containing all the submitted elements.
   */
  inline const STDNS vector<FormEntry>&
  getElements() 					const
    { return fFormData; }
  //@}

  // ============================================================

  /*! \name Uploaded File Access */
  //@{

  /*!
   * \brief Find an uploaded file.
   *
   * \param name The name of the file.
   * \return An iterator referring to the desired file, if found.
   */
  file_iterator 
  getFile(const STDNS string& name);
  
  /*!
   * \brief Find an uploaded file.
   *
   * \param name The name of the file.
   * \return An iterator referring to the desired file, if found.
   */
  const_file_iterator 
  getFile(const STDNS string& name) 			const;

  /*!
   * Get all uploaded files.
   * \return A vector containing all the uploaded files.
   */
  inline const STDNS vector<FormFile>&
  getFiles() 						const
    { return fFormFiles; }
  //@}
  
  // ============================================================

  /*! \name Environment Access */
  //@{

  /*!
   * Get the current runtime environment.
   * \return The current CGI environment.
   */
  inline const CgiEnvironment&
  getEnvironment() 					const
    { return fEnvironment;}
  //@}
  
  // ============================================================

  /*! \name Save and Restore */
  //@{
  
  /*!
   * \brief Save the current CGI environment to a file.
   *
   * This is useful for debugging CGI applications.
   * \param filename The name of the file to which to save.
   */
  void 
  save(const STDNS string& filename) 			const;
  
  /*!
   * \brief Restore from a previously-saved CGI environment.
   *
   * This is useful for debugging CGI applications.
   * \param filename The name of the file from which to restore.
   */
  void 
  restore(const STDNS string& filename);
  //@}
  
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
