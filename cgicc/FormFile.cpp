/*
 *  $Id: FormFile.cpp,v 1.6 2003/07/13 14:20:35 sbooth Exp $
 *
 *  Copyright (C) 1996 - 2003 Stephen F. Booth
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

#ifdef __GNUG__
#  pragma implementation
#endif

#include "cgicc/FormFile.h"
#include "cgicc/CgiUtils.h"

cgicc::FormFile::FormFile(const std::string& name, 
			  const std::string& filename, 
			  const std::string& dataType, 
			  const std::string& data)
  : fName(name),
    fFilename(filename),
    fData(data)
{
  fDataType = dataType.empty() ? std::string("text/plain") : dataType;

  LOG("Got file ") LOG(getFilename()) LOG(" (") LOG(getDataType())
  LOG(" / ") LOG(getDataLength()) LOGLN(" bytes)")
}

bool
cgicc::FormFile::operator== (const FormFile& file) 		const
{
  return (stringsAreEqual(fName, file.fName) && 
	  stringsAreEqual(fFilename, file.fFilename) &&
	  stringsAreEqual(fDataType, file.fDataType));
}

cgicc::FormFile& 
cgicc::FormFile::operator= (const FormFile& file)
{
  fName 	= file.fName;
  fFilename 	= file.fFilename;
  fDataType 	= file.fDataType;
  fData 	= file.fData;

  return *this;
}

void 
cgicc::FormFile::writeToStream(std::ostream& out) 		const
{
  out.write(getData().data(), getDataLength());
}
