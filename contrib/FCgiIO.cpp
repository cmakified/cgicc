/*
 *  $Id: FCgiIO.cpp,v 1.5 2004/06/09 14:37:12 sbooth Exp $
 *
 *  Copyright (C) 2002 Steve McAndrewSmith
 *  Copyright (C) 2002 - 2004 Stephen F. Booth
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

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "FCgiIO.h"

cgicc::FCgiIO::FCgiIO(FCGX_Request& request)
  : std::ostream(&fOutBuf),
	 fRequest(request), 
	 fOutBuf(request.out), 
	 fErrBuf(request.err), 
	 fErr(&fErrBuf)
{
  rdbuf(&fOutBuf);
  fErr.rdbuf(&fErrBuf);

  // Parse environment
  for(char **e = fRequest.envp; *e != NULL; ++e) {
    std::string s(*e);
    std::string::size_type i = s.find('=');
    if(i == std::string::npos)
      throw std::runtime_error("Illegally formed environment");
    fEnv[s.substr(0, i)] = s.substr(i + 1);
  }
}

cgicc::FCgiIO::FCgiIO(const FCgiIO& io)
  : CgiInput(io),
    std::ostream(&fOutBuf),
	 fRequest(io.fRequest), 
	 fErr(&fErrBuf), 
	 fEnv(io.fEnv)
{
  rdbuf(&fOutBuf);
  fErr.rdbuf(&fErrBuf);
}
