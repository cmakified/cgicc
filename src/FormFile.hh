/*
 * $Id: FormFile.hh,v 1.9 1998/12/08 23:14:33 sbooth Exp $
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

#ifndef __FORM_FILE__
#define __FORM_FILE__ 1

#include "Exception.hh"
#include "CgiDefs.hh"
#include "FormEntry.hh"

/** 
 * Immutable class representing a file uploaded via the HTTP file upload 
 * mechanism.
 * <P>If you are going to use file upload, remember to set the 
 * <TT>ENCTYPE</TT> of the form to <TT>multipart/form-data</TT>:
 * <PRE CLASS="html">
 * &lt;FORM METHOD="POST" ACTION="..something.." ENCTYPE="multipart/form-data"&gt;
 * </PRE>
 * </P>
 */
class FormFile : public FormEntry
{
public:
  
  /**@name Constructors */
  //@{
  
  /**
   * Create a new FormFile.
   * @param name The <EM>name</EM> of the form element.
   * @param filename The <EM>filename</EM> of the file on the remote machine.
   * @param dataType The MIME content type of the data, if specified, or NULL.
   * @param data The file data, not necessarily null-terminated.
   * @param dataLen The length of the file data, in bytes.
   * @exception Exception
   */
  FormFile(const char *name, 
	   const char *filename, 
	   const char *dataType, 
	   const char *data, 
	   int dataLen) throw (Exception);
  
  /**
   * Copy constructor.
   * @param file The FormFile to copy.
   * @exception Exception
   */
  FormFile(const FormFile& file) throw (Exception);
  
  /** Destructor */
  virtual ~FormFile();
  //@}
  
  /**@name Accessor methods */
  //@{
  
  /**
   * Write this file data to the specified stream.
   * @param out The ostream to which to write.
   */
  void writeToStream(ostream& out) const;
  
  /**
   * Get the MIME type of the file data.
   * @return The MIME type of the file data, or NULL if not specified.  
   * If not specified, assume the data is of type <TT>text/plain</TT>.
   */
  const char* getDataType() const 	{ return fDataType; }

  /**
   * Get the name of the file on the remote machine.
   * @return The name of the file on the remote machine.
   */
  const char* getFilename() const   	{ return getValue(); }
  
  /**
   * Get the file data.  
   * <BR><STRONG CLASS="red">This is not necessarily null-terminated.</STRONG>
   * @return The file data.
   */
  const char* getData() const 		{ return fData; }
  
  /**
   * Get the length of the file data, in bytes.
   * @return The length of the file data, in bytes.
   */
  int getDataLength() const 		{ return fDataLength; }
  
  //@}
  
private:
  
  FormFile() {}
  
  int		fDataLength;
  const char	*fData;
  char 		*fDataType;
};

#endif
