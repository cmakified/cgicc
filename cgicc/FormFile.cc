/*
 *  $Id: FormFile.cc,v 1.2 1999/06/04 00:07:37 sbooth Exp $
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

#ifdef __GNUG__
#pragma implementation
#endif

#include "cgicc/FormFile.hh"
#include "cgicc/CgiUtils.hh"

CGICCNS FormFile::FormFile(const STDNS string& name, 
			   const STDNS string& filename, 
			   const STDNS string& dataType, 
			   const STDNS string& data)
  : fName(name),
    fFilename(filename),
    fData(data)
{
  fDataType = dataType.empty() ? "text/plain" : dataType;

  LOG("Got file ") LOG(getFilename()) LOG(" (") LOG(getDataType())
  LOG(" / ") LOG(getDataLength()) LOGLN(" bytes)")
}

CGICCNS FormFile::~FormFile()
{}

CGICCNS FormFile::FormFile(const FormFile& file)
{
  // call operator=
  *this = file;
}

bool
CGICCNS FormFile::operator== (const FormFile& file) 		const
{
  return (stringsAreEqual(fName, file.fName) && 
	  stringsAreEqual(fFilename, file.fFilename) &&
	  stringsAreEqual(fDataType, file.fDataType));
}

CGICCNS FormFile& 
CGICCNS FormFile::operator= (const FormFile& file)
{
  fName 	= file.fName;
  fFilename 	= file.fFilename;
  fDataType 	= file.fDataType;
  fData 	= file.fData;

  return *this;
}

void 
CGICCNS FormFile::writeToStream(STDNS ostream& out) 		const
{
  out.write(getData().data(), getDataLength());
}

//EOF
