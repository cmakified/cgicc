/*
 *  $Id: FormEntry.hh,v 1.14 1999/05/14 17:57:48 sbooth Exp $
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

#ifndef __FORM_ENTRY__
#define __FORM_ENTRY__ 1

#include <iostream>
#include <string>
#include <climits>
#include <cfloat>

#include "CgiDefs.hh"

CGICC_BEGIN_NAMESPACE

/** Immutable class representing a single HTML form entry (name/value pair). */
class FormEntry
{
public:
  /**@name Constructors */
  //@{
  
  /**
   * Default constructor - shouldn't be used 
   */
  FormEntry()
    {}
  
  /**
   * Create a new FormEntry
   * @param name The name of the form element
   * @param value The value of the form element
   */
  FormEntry(const STDNS string& name, 
	    const STDNS string& value);
  
  /**
   * Copy constructor.
   * @param entry The FormEntry to copy.
   */
  FormEntry(const FormEntry& entry);
  
  /** Delete this FormEntry */
  ~FormEntry();
  //@}
  
  /**@name Overloaded Operators */
  //@{
  
  /**
   * Compare two FormEntries for equality.
   * FormEntries are equal if they have the same name and value.
   * @param entry The FormEntry to compare to this one.
   * @return true if the two FormEntries are equal, false otherwise.
   */
  bool 
  operator== (const FormEntry& entry) 			const;
  
  /**
   * Compare two FormEntries for inequality.
   * FormEntries are equal if they have the same name and value.
   * @param entry The FormEntry to compare to this one.
   * @return false if the two FormEntries are equal, true otherwise.
   */
  inline bool
  operator!= (const FormEntry& entry) 			const
    { return ! operator==(entry); }
  
  /**
   * Assign one FormEntry to another.
   * @param entry The FormEntry to copy.
   * @return A reference to this.
   */
  FormEntry& 
  operator= (const FormEntry& entry);
  
  //@}
  
  /**@name Accessor methods */
  //@{
  
  /**
   * Get the name of the form element.
   * @return The name of the form element.
   */
  inline STDNS string
  getName() 						const
    { return fName; }
  
  /**
   * Get the value of the form element.
   * The value may contain line breaks.
   * @return The value of the form element.
   */
  inline STDNS string
  getValue() 						const
    { return fValue; }
  
  /**
   * Get the value of the form element.
   * The value may contain line breaks.
   * @return The value of the form element.
   */
  inline STDNS string
  operator* () 						const
    { return getValue(); }
  
  /**
   * Get the value of the form element, truncated to a specific length.
   * The value may contain line breaks.<BR>
   * <STRONG CLASS="red">It is the caller's responsibility to delete 
   * <TT>value</TT> when it is no longer needed.</STRONG>
   * @param maxChars The maximum number of characters to return.
   * @return The value of the form element, truncated to the specified  length.
   */
  inline STDNS string
  getValue(STDNS string::size_type maxChars) 			const
    { return makeString(maxChars, true); }
  
  /**
   * Get the value of the form element, stripped of all line breaks.
   * <BR><STRONG CLASS="red">It is the caller's responsibility to delete 
   * <TT>value</TT> when it is no longer needed.</STRONG>
   * @return The value of the form element, stripped of all line breaks.
   */
  inline STDNS string
  getStrippedValue() 					const
    { return getStrippedValue(INT_MAX); }
  
  /**
   * Get the value of the form element, stripped of all line breaks
   * and truncated to a specific length.
   * <BR><STRONG CLASS="red">It is the caller's responsibility to delete 
   * <TT>value</TT> when it is no longer needed.</STRONG>
   * @param maxChars The maximum number of characters to return.
   * @return The value of the form element, stripped of all line breaks and
   * truncated to the specified length.
   */
  inline STDNS string
  getStrippedValue(STDNS string::size_type maxChars) 		const
    { return makeString(maxChars, false); }
  
  /**
   * Get the value of the form element as an integer.
   * @param min The minimum value to return (optional).
   * @param max The maximum value to return (optional).
   * @return The integer value of the form element.
   */
  long
  getIntegerValue(long min = LONG_MIN, 
		  long max = LONG_MAX) 			const;
  
  /**
   * Get the value of the form element as a double.
   * @param min The minimum value to return (optional).
   * @param max The maximum value to return (optional).
   * @return The double value of the form element.
   */
  double 
  getDoubleValue(double min = DBL_MIN, 
		 double max = DBL_MAX) 			const;
  
  /**
   * Get the length of the value of the form element.
   * @return The length of the value of the form element, in bytes.
   */
  inline STDNS string::size_type
  length() 						const
    { return fValue.length(); }
  
  /**
   * Determine if this form element is empty (length() == 0).
   * @return True if this form element is empty, false otherwise.
   */
  inline bool 
  isEmpty() 						const
    { return (length() == 0); }
  //@}
  
private:  
  // utility function
  STDNS string
  makeString(STDNS string::size_type maxLen, 
	     bool allowNewlines) 			const;
  
  STDNS string fName;		// the name of this form element
  STDNS string fValue;		// the value of this form element
};

CGICC_END_NAMESPACE

#endif

//EOF
