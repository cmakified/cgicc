/*
 *  $Id: FormFile.cc,v 1.6 1998/12/09 00:48:39 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
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
