/*
 *  $Id: FormEntry.cpp,v 1.3 2001/09/02 19:53:17 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001 Stephen F. Booth
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

#include <new>
#include <cstdlib>

#include "cgicc/FormEntry.h"

// local macro for integer maximum
#define MAX(a, b) ((a) > (b) ? (a) : (b))

CGICCNS FormEntry& 
CGICCNS FormEntry::operator= (const FormEntry& entry)
{
  fName  = entry.getName();
  fValue = entry.getValue();

  return *this;
}

long
CGICCNS FormEntry::getIntegerValue(long min, 
				   long max) 		const
{
  long value = atol(fValue.c_str());
  if(value > max)
    value = max;
  else if(value < min)
    value = min;
  
  return value;
}

double
CGICCNS FormEntry::getDoubleValue(double min, 
				  double max) 		const
{
  double value = atof(fValue.c_str());
  if(value > max)
    value = max;
  else if(value < min)
    value = min;
  
  return value;
}

STDNS string
CGICCNS FormEntry::makeString(STDNS string::size_type maxLen, 
			      bool allowNewlines)	const
{
  STDNS string::size_type	len 		= 0;
  STDNS string::size_type	avail 		= maxLen;
  STDNS string::size_type	crCount 	= 0;
  STDNS string::size_type	lfCount 	= 0;	
  STDNS string::const_iterator 	src 		= fValue.begin();
  STDNS string::const_iterator 	lim 		= fValue.end();
  STDNS string 			dst;


  while(src != lim && len < avail) {

    // handle newlines
    if(*src == '\r' || *src == '\n') {
      crCount = 0;
      lfCount = 0;
      
      // Count the number of each kind of line break ('\r' and '\n')
      while( (*src == '\r' || *src == '\n') && (src != lim)) {
	if(*src == '\r') 
	  crCount++;
	else 
	  lfCount++;
	++src;
      }
      
      // if newlines are allowed, add them
      if(allowNewlines) {
	// output the larger value
	int lfsAdd = MAX(crCount, lfCount);
	dst.append(lfsAdd, '\n');
	len += lfsAdd;		
      }
    }
    // just append all other characters
    else {
      dst.append(1, *src);
      ++len;
      ++src;
    }
  }
  
  return dst;
}
