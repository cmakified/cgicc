/* $Id: FormFile.cc,v 1.2 1998/04/01 20:52:21 sbooth Exp $ */

#include "FormFile.hh"

/* Create a new FormFile */
FormFile::FormFile(const char *name, const char *filename, 
		   const char *dataType, const char *data, int dataLen)
  : FormEntry(name, filename), fDataLength(dataLen)
{
  fData = data;
  if(dataType != NULL) {
    fDataType = new char[strlen(dataType) + 1];
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

FormFile::FormFile(const FormFile& file) 
  : FormEntry(file.getName(), file.getValue(), file.getDataLength())
{
  fDataType = new char[strlen(file.getDataType()) + 1];
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
