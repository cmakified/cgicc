/* $Id: FormFile.cc,v 1.1 1998/02/12 05:31:41 sbooth Exp $ */

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

void 
FormFile::writeToStream(ostream& out) const
{
  out.write(getData(), getDataLength());
}

//EOF
