/* $Id: FormFile.cc,v 1.3 1998/09/24 01:37:58 sbooth Exp $ */

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
