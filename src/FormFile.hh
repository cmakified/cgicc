/*
 *  $Id: FormFile.hh,v 1.14 1999/05/28 19:37:12 sbooth Exp $
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

#ifndef _FORMFILE_HH_
#define _FORMFILE_HH_ 1

#ifdef __GNUG__
#pragma interface
#endif

#include <iostream>
#include <string>

#include "CgiDefs.hh"

CGICC_BEGIN_NAMESPACE

/** 
 * Immutable class representing a file uploaded via the HTTP file upload 
 * mechanism.
 * <P>If you are going to use file upload, remember to set the 
 * <TT>ENCTYPE</TT> of the form to <TT>multipart/form-data</TT>:
 * <PRE CLASS="html">
 * &lt;FORM METHOD="POST" ACTION="..." ENCTYPE="multipart/form-data"&gt;
 * </PRE>
 * </P>
 */
class FormFile
{
public:
  
  /**@name Constructors */
  //@{
  
  /** Default constructor - shouldn't be used. */
  FormFile()
    {}
  
  /**
   * Create a new FormFile.
   * @param name The <EM>name</EM> of the form element.
   * @param filename The <EM>filename</EM> of the file on the remote machine.
   * @param dataType The MIME content type of the data, if specified, or 0.
   * @param data The file data.
   */
  FormFile(const STDNS string& name, 
	   const STDNS string& filename, 
	   const STDNS string& dataType, 
	   const STDNS string& data);
  
  /**
   * Copy constructor.
   * @param file The FormFile to copy.
   */
  FormFile(const FormFile& file);
  
  /** Destructor */
  ~FormFile();
  //@}
  
  
  /**@name Overloaded Operators */
  //@{
  
  /**
   * Compare two FormFiles for equality.
   * FormFiles are equal if they have the same filename.
   * @param file The FormFile to compare to this one.
   * @return true if the two FormFiles are equal, false otherwise.
   */
  bool 
  operator== (const FormFile& file) 			const;
  
  /**
   * Compare two FormFiles for inequality.
   * FormFiles are equal if they have the same filename.
   * @param file The FormFile to compare to this one.
   * @return false if the two FormFiles are equal, true otherwise.
   */
  inline bool 
  operator!= (const FormFile& file) 			const
    { return ! operator==(file); }
  
  /**
   * Assign one FormFile to another.
   * @param file The FormFile to copy.
   * @return A reference to this.
   */
  FormFile& 
  operator= (const FormFile& file);
  
  //@}
  
  /**@name Accessor methods */
  //@{
  
  /**
   * Write this file data to the specified stream.
   * @param out The ostream to which to write.
   */
  void 
  writeToStream(STDNS ostream& out) 			const;

  /**
   * Get the name of the form element.
   * @return The name of the form element.
   */
  inline STDNS string
  getName() 						const
    { return fName; }
  
  /**
   * Get the name of the file on the remote machine.
   * @return The name of the file on the remote machine.
   */
  inline STDNS string
  getFilename() 					const
    { return fFilename; }

  /**
   * Get the MIME type of the file data.
   * @return The MIME type of the file data.  
   */
  inline STDNS string 
  getDataType() 					const
    { return fDataType; }
    
  /**
   * Get the file data.  
   * @return The file data.
   */
  inline STDNS string 
  getData() 					const
    { return fData; }
  
  /**
   * Get the length of the file data, in bytes.
   * @return The length of the file data, in bytes.
   */
  inline STDNS string::size_type
  getDataLength() 				const
    { return fData.length(); }
  
  //@}
  
private:
  STDNS string 	fName;
  STDNS string 	fFilename;
  STDNS string 	fDataType;
  STDNS string 	fData;
};

CGICC_END_NAMESPACE

#endif /* ! _FORMFILE_HH_ */
