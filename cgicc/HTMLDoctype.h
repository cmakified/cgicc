/* -*-c++-*- */
/*
 *  $Id: HTMLDoctype.h,v 1.3 2002/03/06 02:49:55 sbooth Exp $
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

#ifndef _HTMLDOCTYPE_H_
#define _HTMLDOCTYPE_H_ 1

#ifdef __GNUG__
#  pragma interface
#endif

/*! \file HTMLDoctype.h
 * \brief Class which specifies the DTD of the HTML 4 document
 * 
 */

#include <string>

#include "cgicc/MStreamable.h"

CGICC_BEGIN_NAMESPACE
  
// ============================================================
// Class HTMLDoctype
// ============================================================

/*! \class HTMLDoctype HTMLDoctype.h cgicc/HTMLDoctype.h
 * \brief Specifies the DTD of the HTML 4 document
 *
 * To use this class, simply write an object of this type to an ostream:
 * \code
 * out << cgicc::HTMLDoctype();
 * \endcode
 * For more information, see \c http://www.w3.org/MarkUp/ and 
 * \c http://www.w3.org/TR/REC-html40/
 */
class CGICC_API HTMLDoctype : public MStreamable 
{
public:
    
  /*! The DTD used by this document. */
  enum EDocumentType {
    /*! The HTML 4.0 strict DTD (the default) */
    eStrict,
    /*! The HTML 4.0 Transitional DTD */
    eTransitional,
    /*! The HTML 4.0 Frameset DTD */
    eFrames
  };

    
  /*!
   * \brief Constructor.
   * \param type The version of the HTML 4.0 DTD used by this document.
   */
  HTMLDoctype(EDocumentType type = eStrict);
    
  /*!
   * \brief Destructor 
   *
   */
  virtual ~HTMLDoctype();
    
  virtual void 
  render(STDNS ostream& out) 			const;
    
private:
  EDocumentType fType;
};

CGICC_END_NAMESPACE

#endif /* ! _HTMLDOCTYPE_H_ */
