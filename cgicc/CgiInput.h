/* -*-c++-*- */
/*
 *  $Id: CgiInput.h,v 1.1 2002/03/02 06:21:15 sbooth Exp $
 *
 *  Copyright (C) 1996 - 2002 Stephen F. Booth
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

#ifndef _CGIINPUT_H_
#define _CGIINPUT_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file CgiInput.h
 * \brief Class that abstracts a data source
 *
 * This class allows the data source for the CGI application to be
 * something other than standard input.
 */

#include <string>

#include "cgicc/CgiDefs.h"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class CgiInput
// ============================================================

/*! \class CgiInput CgiInput.h cgicc/CgiInput.h 
 * \brief Class that abstracts a data source
 *
 * The \c CgiInput class is an abstraction for all input data to the
 * CGI application. This allows input data to come from something other than 
 * standard input (cin).  This is useful, in fact necessary, when using
 * %cgicc with FastCgi.
 * Library users wishing to exploit this functionality should create a
 * subclass and override the \c read and \c getenv methods.
 */
class CGICC_API CgiInput
{
 public:

  // ============================================================

  /*! \name Constructor and Destructor */
  //@{

  /*! 
   * \brief Constructor
   *
   * Create a new CgiInput object
   */
  CgiInput();

  /*!
   * \brief Destructor 
   *
   * Delete this CgiInput object
   */
  virtual ~CgiInput();
  //@}

  // ============================================================

  /*! \name Data Sources */
  //@{

  /*!
   * \brief Read data from a data source
   *
   * In the default implementation, this is a wrapper for \c cin.read()
   * \param data The target buffer
   * \param length The number of characters to read
   * \return The number of characters read
   */
  virtual size_t read(char *data, size_t length);

  /*!
   * \brief Query the value of an environment variable
   *
   * In the default implementation, this is a wrapper for std::getenv()
   * \param varName The name of an environment variable
   * \return The value of the requested environment variable, or an empty
   * string if not found.
   */
  virtual STDNS string getenv(const char *varName);
  //@}
};

CGICC_END_NAMESPACE

#endif /* ! _CGIINPUT_H_ */
