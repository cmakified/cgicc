/*
 *  $Id: MStreamable.hh,v 1.2 1999/06/04 00:07:42 sbooth Exp $
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

#ifndef _MSTREAMABLE_HH_
#define _MSTREAMABLE_HH_ 1

#ifdef __GNUG__
#pragma interface
#endif

#include <iostream>

#include "cgicc/CgiDefs.hh"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class MStreamable
// ============================================================
/** 
 * Abstract mix-in class which makes classes streamable via
 * the << operator.
 * Written in the spirit of a Java interface.
 */
class MStreamable 
{
  
  friend STDNS ostream& operator<<(STDNS ostream& out, const MStreamable& obj);
  
public:
  /**
   * Write this object to a stream.  Subclasses must implement this function.
   * @param out The ostream to which to write.
   */
  virtual void
  render(STDNS ostream& out) 				const = 0;
};
  
CGICC_END_NAMESPACE

#endif /* ! _MSTREAMABLE_HH_ */
