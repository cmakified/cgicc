/*
 *  $Id: CgiDefs.hh,v 1.8 1999/05/25 19:16:43 sbooth Exp $
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

#ifndef __CGI_DEFS__
#define __CGI_DEFS__ 1

#ifdef __GNUG__
#pragma interface
#endif

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

#endif
