/* -*-c++-*- */
/*
 *  $Id: MStreamable.h,v 1.9 2003/07/13 14:20:35 sbooth Exp $
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

#ifndef _MSTREAMABLE_H_
#define _MSTREAMABLE_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file MStreamable.h
 * \brief Abstract base class for all streamable objects.
 * 
 * A streamable object is an object that can be written to an \c
 * ostream using the \c << operator.
 */

#include <iostream>

#include "cgicc/CgiDefs.h"

namespace cgicc {

  class MStreamable;

  /*!
   * Prototype for overloading streaming operator 
   * \param out The ostream to which to write
   * \param obj The MStreamable object to write
   * \return A reference to \c out
   */
  CGICC_API std::ostream& 
  operator<<(std::ostream& out, const MStreamable& obj);
  
  // ============================================================
  // Class MStreamable
  // ============================================================
  
  /*! \class MStreamable MStreamable.h cgicc/MStreamable.h
   * \brief Mix-in streamable interface.
   *
   * Abstract mix-in class which makes classes streamable via
   * the \c << operator.
   * Written in the spirit of a Java interface.
   */
  class CGICC_API MStreamable 
  {
    
    friend CGICC_API std::ostream& 
    operator<<(std::ostream& out, const MStreamable& obj);
    
  public:
    /*! 
     * \brief Empty constructor 
     *
     */
    inline MStreamable() 
    {}
    
    /*! 
     * \brief Empty destructor 
     *
     */
    inline virtual ~MStreamable() 
    {}
    
    /*!
     * \brief Write this object to a stream.  
     *
     * Subclasses must implement this function.
     * \param out The ostream to which to write.
     */
    virtual void
    render(std::ostream& out) 				const = 0;
  };
  
} // namespace cgicc

#endif /* ! _MSTREAMABLE_H_ */
