/* $Id: FormEntry.hh,v 1.7 1998/04/03 21:13:26 sbooth Exp $ */

#ifndef __FORM_ENTRY__
#define __FORM_ENTRY__ 1

#ifndef __EXCEPTION__
#include "Exception.hh"
#endif

#ifndef __MSTREAMABLE__
#include "MStreamable.hh"
#endif

#ifndef __CGI_DEFS__
#include "CgiDefs.hh"
#endif

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
   */
  FormEntry(const char *name, const char *value, int valueLen = -1);
  
  /**
   * Copy constructor.
   * @param entry The FormEntry to copy.
   */
  FormEntry(const FormEntry& entry);

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
