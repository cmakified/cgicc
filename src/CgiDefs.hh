/*
 *  $Id: CgiDefs.hh,v 1.10 1999/05/28 19:37:11 sbooth Exp $
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

#ifndef _CGIDEFS_HH_
#define _CGIDEFS_HH_ 1

#if HAVE_CONFIG_H
#include "config.h"
#endif

// Handle namespaces
#if USE_NAMESPACES
#define CGICC_BEGIN_NAMESPACE namespace cgicc {
#define CGICC_END_NAMESPACE }
#define CGICCNS cgicc::
#define STDNS std::
#else
#define CGICC_BEGIN_NAMESPACE 
#define CGICC_END_NAMESPACE 
#define CGICCNS 
#define STDNS 
#endif

#endif /* ! _CGIDEFS_HH_ */
