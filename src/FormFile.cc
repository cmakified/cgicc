/*
 * $Id: FormFile.cc,v 1.4 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

#include "FormFile.hh"

/* Create a new FormFile */
FormFile::FormFile(const char *name, 
		   const char *filename, 
		   const char *dataType, 
		   const char *data, 
		   int dataLen) throw (Exception)
  : FormEntry(name, filename), fDataLength(dataLen)
{
  fData = data;
  if(dataType != NULL) {
    fDataType = new char[strlen(dataType) + 1];
    if(fDataType == NULL)
      throw Exception("new failed", ERRINFO);
    strcpy(fDataType, dataType);
  }
  else
    fDataType = NULL;

  log("Got file "); log(getFilename()); log(" ("); 
  log((getDataType() == NULL ? "Type not specified" : getDataType()));
  log(" / "); log(getDataLength()); logln(" bytes)");
}

/* Delete this FormEntry, removing it from the list */
FormFile::~FormFile()
{
  delete [] fDataType;
}

FormFile::FormFile(const FormFile& file) throw (Exception)
  : FormEntry(file.getName(), file.getValue(), file.getDataLength())
{
  fDataType = new char[strlen(file.getDataType()) + 1];
  if(fDataType == NULL)
    throw Exception("new failed", ERRINFO);
  strcpy(fDataType, file.getDataType());

  fData = file.getData();
  fDataLength = file.getDataLength();
}

void 
FormFile::writeToStream(ostream& out) const
{
  out.write(getData(), getDataLength());
}

//EOF
