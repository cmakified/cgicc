/* $Id: FormEntry.hh,v 1.1 1998/04/01 20:45:46 sbooth Exp $ */

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

/** 
 * Immutable class representing a single HTML form entry (name/value pair).
 * @see FormFile
 * @see CgiForm
 */
class FormEntry : public MStreamable
{
public:
  /**@name Constructor */
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
   * Get the name of the form element
   * @return The name of the form element
   */
  const char* getName() const	{ return fName; }
  
  /**
   * Get the value of the form element
   * @return The value of the form element
   */
  const char* getValue() const	{ return fValue; }
  //@}
  
protected:
  /* Shouldn't be used */
  FormEntry() : fName(NULL), fValue(NULL) {}

private:  
  char		*fName;		/* the name of this form element */
  char		*fValue;	/* the value of this form element */
};

#endif
