/* $Id: FormFile.hh,v 1.4 1998/04/02 11:26:09 sbooth Exp $ */

#ifndef __FORM_FILE__
#define __FORM_FILE__ 1

#ifndef __EXCEPTION__
#include "Exception.hh"
#endif

#ifndef __CGI_DEFS__
#include "CgiDefs.hh"
#endif

#ifndef __FORM_ENTRY__
#include "FormEntry.hh"
#endif

/** 
 * Immutable class representing a file uploaded via the HTTP file upload 
 * mechanism.
 */
class FormFile : public FormEntry
{
public:
  
  // ========== Constructor/Destructor
  
  /**@name Constructor */
  //@{
  
  /**
   * Create a new FormFile.
   * @param name The <EM>name</EM> of the form element.
   * @param filename The <EM>filename</EM> of the file on the remote machine.
   * @param dataType The MIME content type of the data, if specified, or NULL.
   * @param data The file data, not necessarily null-terminated.
   * @param dataLen The length of the file data, in bytes.
   */
  FormFile(const char *name, 
	   const char *filename, 
	   const char *dataType, 
	   const char *data, 
	   int dataLen);
  
  /**
   * Copy constructor.
   * @param file The FormFile to copy.
   */
  FormFile(const FormFile& file);
  
  /* Destructor - remove this from the list */
  virtual ~FormFile();
  //@}
  
  
  // ========== Accessor methods
  
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
