/*
 * $Id: FormEntry.hh,v 1.11 1998/12/08 23:14:33 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
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

#ifndef __FORM_ENTRY__
#define __FORM_ENTRY__ 1

#include "Exception.hh"
#include "MStreamable.hh"
#include "CgiDefs.hh"

#include <limits.h>
#include <float.h>

/** Immutable class representing a single HTML form entry (name/value pair). */
class FormEntry : public MStreamable
{
public:
  /**@name Constructors */
  //@{
  
  /**
   * Create a new FormEntry
   * @param name The name of the form element
   * @param value The value of the form element
   * @param valueLen The length, in bytes, of value if not NULL-terminated.
   * @exception Exception
   */
  FormEntry(const char *name, const char *value, 
	    int valueLen = -1) throw (Exception);
  
  /**
   * Copy constructor.
   * @param entry The FormEntry to copy.
   * @exception Exception
   */
  FormEntry(const FormEntry& entry) throw (Exception);

  /** Delete this FormEntry */
  virtual ~FormEntry();
  //@}

  virtual void render(ostream& out) const;

  /**@name Accessor methods */
  //@{
  
  /**
   * Get the name of the form element.
   * @return The name of the form element.
   */
  inline const char* getName() const	{ return fName; }
  
  /**
   * Get the value of the form element.
   * The value may contain line breaks.
   * @return The value of the form element.
   */
  inline const char* getValue() const	{ return fValue; }

  /**
   * Get the value of the form element.
   * The value may contain line breaks.
   * @return The value of the form element.
   */
  inline const char* operator* () const { return getValue();}

  /**
   * Get the value of the form element, truncated to a specific length.
   * The value may contain line breaks.<BR>
   * <STRONG CLASS="red">It is the caller's responsibility to delete 
   * <TT>value</TT> when it is no longer needed.</STRONG>
   * @param maxChars The maximum number of characters to return.
   * @param value The location to store the result.
   * @exception Exception
   */
  void getValue(int 	maxChars,
		char* 	&value) const throw(Exception);

  /**
   * Get the value of the form element, stripped of all line breaks.
   * <BR><STRONG CLASS="red">It is the caller's responsibility to delete 
   * <TT>value</TT> when it is no longer needed.</STRONG>
   * @param value The location to store the result.
   * @exception Exception
   */
  void getStrippedValue(char* &value) const throw(Exception);

  /**
   * Get the value of the form element, stripped of all line breaks
   * and truncated to a specific length.
   * <BR><STRONG CLASS="red">It is the caller's responsibility to delete 
   * <TT>value</TT> when it is no longer needed.</STRONG>
   * @param maxChars The maximum number of characters to return.
   * @param value The location to store the result.
   * @exception Exception
   */
  void getStrippedValue(int 	maxChars,
			char* 	&value) const throw(Exception);

  /**
   * Get the value of the form element as an integer.
   * @param min The minimum value to return (optional).
   * @param max The maximum value to return (optional).
   * @return The integer value of the form element.
   */
  int getIntegerValue(int min = INT_MIN, 
		      int max = INT_MAX) const;

  /**
   * Get the value of the form element as a double.
   * @param min The minimum value to return (optional).
   * @param max The maximum value to return (optional).
   * @return The double value of the form element.
   */
  double getDoubleValue(double min = DBL_MIN, 
			double max = DBL_MAX) const;

  /**
   * Get the length of the value of the form element.
   * @return The length of the value of the form element, in bytes.
   */
  inline int length() const 		{ return fLength; }

  /**
   * Determine if this form element is empty (length() == 0).
   * @return True if this form element is empty, false otherwise.
   */
  inline bool isEmpty() const 		{ return (length() == 0); }
  //@}
  
protected:
  /* Shouldn't be used */
  FormEntry() : fName(NULL), fValue(NULL), fLength(0) {}

private:  
  /* Utility function to optionally truncate and/or strip newlines
     Returns: -1 = truncated, 0 = source string empty, 1 = OK */
  int makeString(char*	&result, 
		 int 	maxLen, 
		 int 	allowNewlines) const;

  char		*fName;		/* the name of this form element */
  char		*fValue;	/* the value of this form element */
  int		fLength;
};

#endif
