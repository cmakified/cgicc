/*
 *  $Id: CgiException.hh,v 1.1 1999/04/26 23:03:31 sbooth Exp $
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

#ifndef __CGI_EXCEPTION__
#define __CGI_EXCEPTION__ 1

/** 
 * A convenience macro for passing in filename and line number information. 
 * <P>This is a just a more convenient form of <TT>__FILE__, __LINE__</TT>.</P>
 * @see CgiException
 */
#define ERRINFO __FILE__,__LINE__

#include <exception>

#include "CgiDefs.hh"

CGICC_BEGIN_NAMESPACE

// ============================================================
// Class CgiException
// ============================================================
/** 
 * Base class for all exceptions which may be thrown by Cgicc.
 * <P>This is a subclass of the more general class <TT>exception</TT>
 * defined in the C++ Standard Template Library (STL).</P>
 * <P>Throw this class and subclasses just like any other exception type.<BR>
 * For simplified use, instead of passing in explicit values for
 * file and line (either directly or via <TT>__FILE__</TT> and 
 * <TT>__LINE__</TT>), try passing in the macro <TT>\Ref{ERRINFO}</TT>:</P>
 * 
 * <PRE CLASS="code">
 * . try {
 * .   ... // do something here
 * .   if( ! success )
 * .      throw CgiException("Oh no!  An error!", ERRINFO);
 * . }
 * . catch(CgiException e) {
 * .    cerr << "Message : " << e.getMessage() << endl;
 * .    cerr << "File    : " << e.getFile() << endl;
 * .    cerr << "Line    : " << e.getLine() << endl;    
 * . } 
 * </PRE>
 * @see ERRINFO
 */
class CgiException : public STDNS exception
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new exception to be thrown. */
  CgiException() 				throw();
  
  /**
   * Create a new exception to be thrown. 
   * @param msg The error message  
   */
  CgiException(const char *msg) 		throw();
  
  /**
   * Create a new exception to be thrown.
   * @param msg The error message
   * @param file The file in which the exception occurred
   * @param line The line number causing the exception
   */
  CgiException(const char *msg, 
	       const char *file, 
	       int line) 			throw();
  
  /* Destructor */
  virtual ~CgiException() 			throw();
  //@}
  
  /**@name Exception information */
  //@{
  
  /**
   * Get the error message associated with this exception.
   * @return The error message for this exception
   */
  inline const char* 
  getMessage() 				const 	throw()	
    { return fMessage; }
  
  /**
   * Get the name of the file from which this exception was thrown.
   * @return The name of the file which caused the error
   */
  inline const char* 
  getFile() 				const 	throw() 	
    { return fFile; }
  
  /**
   * Get the line number at which this exception was thrown.
   * @return The line number which caused the error
   */
  inline int 
  getLine() 				const 	throw()
    { return fLine; }
  
  /**
   * Get the error message associated with this exception.
   * This method is identical to \Ref{getMessage}, and is
   * for Standard Template Library compatibility.
   * @return The error message for this exception
   */
  virtual inline const char* 
  what() 				const 	throw()
    { return getMessage();}
  //@}
  
private:
  const char 	*fMessage;	/* the error message */
  const char 	*fFile;		/* the file in which the error occured */
  int 		fLine;		/* the line at which the error occurred */
};

CGICC_END_NAMESPACE

#endif

//EOF
