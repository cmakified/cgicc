/* $Id: CgiForm.hh,v 1.1 1998/04/01 20:50:55 sbooth Exp $ */

#ifndef __CGI_FORM__
#define __CGI_FORM__ 1

#ifndef __EXCEPTION__
#include "Exception.hh"
#endif

#ifndef __LINKED_LIST__
#include "LinkedList.hh"
#endif

#ifndef __CGI_DEFS__
#include "CgiDefs.hh"
#endif

#ifndef __FORM_ENTRY__
#include "FormEntry.hh"
#endif

#ifndef __FORM_FILE__
#include "FormFile.hh"
#endif

#ifndef __CGI_ENVIRONMENT__
#include "CgiEnvironment.hh"
#endif


class MultipartHeader;

/**
 * This class is used to retrieve form data.
 * <P>When instantiated, it will read in the environment and parse the
 * form data into a \Ref{LinkedList} of \Ref{FormEntry}s.</P>
 * <P>For example, to print out every form element:
 * <PRE class="code">
 * LinkedList&lt;FormEntry&gt;::Iterator iter = formData->begin();
 * while(iter.isValid()) {
 *   out << (*iter).getName() << ' ' << (*iter++).getValue() << br() << endl;
 * }
 * </PRE></P>
 * <P>To query if a checkbox is checked:
 * <PRE class="code">
 * if(formData->queryCheckbox("foo")) {
 *   // the box was checked
 * }
 * else {
 *   // the box wasn't checked
 * }
 * </PRE></P>
 * @see FormEntry
 * @see CgiEnvironment
 */
class CgiForm : public LinkedList<FormEntry>
{
public:
  
  // ========== Constructor/Destructor
  
  /**@name Constructor */
  //@{
  /** Create a new CgiForm. */
  CgiForm();
  
  /* Destructor */
  ~CgiForm();
  //@}
  
  
  // ========== Access to form data as strings
  
  /**@name Access to form data as strings */
  //@{
  
  /**
   * Extract the value of a form element as a string.
   * The value extracted may contain line breaks.<BR>
   * <STRONG CLASS="red">It is the caller's responsibility to delete dest when
   * it is no longer needed.</STRONG> 
   * @param elementName The name of the element to query
   * @param dest The location to store the result, if found
   * @return True if the desired item was found, false if not
   * @exception Exception
   */
  bool getAsString(const char *elementName, 
		   char* &dest) const throw(Exception);
  
  /**
   * Extract the value of a form element as a string.
   * The value may contain line breaks.<BR>
   * <STRONG CLASS="red">It is the caller's responsibility to delete dest when
   * it is no longer needed.</STRONG> 
   * @param elementName The name of the element to query
   * @param maxLen The maximum length for the result
   * @param dest The location to store the result, if found
   * @return True if the desired item was found, false if not
   * @exception Exception
   */
  bool getAsString(const char *elementName, 
		   int maxLen, 
		   char* &dest) const throw(Exception);
  
  /**
   * Extract the value of a form element as a string.
   * The value will <EM>not</EM> contain line breaks.<BR>
   * <STRONG CLASS="red">It is the caller's responsibility to delete dest when
   * it is no longer needed.</STRONG> 
   * @param elementName The name of the element to query
   * @param dest The location to store the result, if found
   * @return True if the desired item was found, false if not
   * @exception Exception
   */
  bool getAsStringNoNewlines(const char *elementName, 
			     char* &dest) const throw(Exception);
  
  /**
   * Extract the value of a form element as a string.
   * The value will <EM>not</EM> contain line breaks.<BR>
   * <STRONG CLASS="red">It is the caller's responsibility to delete dest when
   * it is no longer needed.</STRONG> 
   * @param elementName The name of the element to query
   * @param maxLen The maximum length for the result
   * @param dest The location to store the result, if found
   * @return True if the desired item was found, false if not
   * @exception Exception
   */
  bool getAsStringNoNewlines(const char *elementName, 
			     int maxLen, 
			     char* &dest) const throw(Exception);
  //@}
  
  
  // ========== Access to form data as integers
  
  /**@name Access to form data as integers */
  //@{
  
  /**
   * Extract the value of a form element as an integer.
   * @param elementName The name of the element to query
   * @param value The value of the queried form element, if found
   * @return True if the desired item was found, false if not
   * @exception Exception
   */
  bool getAsInteger(const char *elementName, 
		    int &value) const throw(Exception);
  
  /**
   * Extract the value of a form element as an integer.
   * The result will be constrained to an inclusive range.
   * @param elementName The name of the element to query
   * @param value The value of the queried form element, if found
   * @param min The minimum value for the result, if found
   * @param max The maximum value for the result, if found
   * @return True if the desired item was found, false if not
   * @exception Exception
   */
  bool getAsBoundedInteger(const char *elementName, 
			   int min, 
			   int max, 
			   int &value) const throw(Exception);
  //@}
  
  // ========== Access to form data as doubles
  
  /**@name Access to form data as doubles */
  //@{
  
  /**
   * Extract the value of a form element as a double.
   * @param elementName The name of the element to query
   * @param value The value of the queried form element, if found
   * @return True if the desired item was found, false if not
   * @exception Exception
   */
  bool getAsDouble(const char *elementName, 
		   double &value) const throw(Exception);
  
  /**
   * Extract the value of a form element as a double.
   * The result will be constrained to an inclusive range.
   * @param elementName The name of the element to query
   * @param value The value of the queried form element, if found
   * @param min The minimum value for the result, if found
   * @param max The maximum value for the result, if found
   * @return True if the desired item was found, false if not
   * @exception Exception
   */
  bool getAsBoundedDouble(const char *elementName, 
			  double min, 
			  double max, 
			  double &value) const throw(Exception);
  //@}
  
  
  // ========== Access to checkboxes
  
  /**@name Access to checkboxes */
  //@{
  
  /**
   * Query whether a checkbox is checked.
   * @param elementName The name of the element to query
   * @return True if the desired checkbox was checked, false if not
   * @exception Exception
   */
  bool queryCheckbox(const char *elementName) const throw(Exception);
  
  /**
   * Query which checkboxes in a group are checked.
   * <BR>
   * <STRONG CLASS="red">It is the caller's responsibility to delete value when
   * it is no longer needed.</STRONG> 
   * @param elementName The name of the element to query
   * @param value An array of values for all checked boxes in this group
   * @param numFound The number of checkboxes found, if any
   * @return True if any checkboxes were found, false if not
   * @exception Exception
   */
  bool getCheckboxMultiple(const char *elementName, 
			   char** &value, 
			   int &numFound) const throw(Exception);
  //@}
  
  
  // ========== Access to radio buttons
  
  /**@name Access to radio buttons */
  //@{
  
  /**
   * Extract the value of a radio button from a radio group.
   * @param elementName The name of the element to query
   * @param value The value of the selected radio button, if any
   * @return True if the desired item was found, false if not
   * @exception Exception
   */
  bool getRadio(const char *elementName, 
		char* &value) const throw(Exception);
  //@}
  
  
  // ========== Access to list items
  
  /**@name Access to list items */
  //@{
  
  /**
   * Query which item in a list item was selected.
   * <BR>
   * <STRONG CLASS="red">It is the caller's responsibility to delete value when
   * it is no longer needed.</STRONG> 
   * @param elementName The name of the element to query
   * @param value The value of selected item, if any
   * @return True if the desired list was found, false if not
   * @exception Exception
   */
  bool getSelectSingle(const char *elementName, 
		       char* &value) const throw(Exception);
  
  /**
   * Query which items in a list item were selected.
   * <BR>
   * <STRONG CLASS="red">It is the caller's responsibility to delete value when
   * it is no longer needed.</STRONG> 
   * @param elementName The name of the element to query
   * @param value An array of values for all selected items in this list
   * @param numFound The number of items selected, if any
   * @return True if the desired list was found, false if not
   * @exception Exception
   */
  bool getSelectMultiple(const char *elementName, 
			 char** &value, 
			 int &numFound) const throw(Exception);
  //@}  

  /**@name Searching for entries */
  //@{
  
  /**
   * Find an element in the linked list of entries
   * @param name The <EM>name</EM> of the list element to search for
   * @return The desired list element, or NULL if not found
   */
  const FormEntry* findEntryByName(const char *name) const;
  
  /**
   * Find an element in the linked list of entries
   * @param value The <EM>value</EM> of the list element to search for
   * @return The desired list element, or NULL if not found
   */
  const FormEntry* findEntryByValue(const char *value) const;
    
  /* Find an element in the linked list of entries */
  const FormEntry* findEntry(const char *param, 
			     bool byName) const;
  //@}
  
  // ========== Access the current environment
  
  /**@name Access to the current environment */
  //@{
  
  /**
   * Get a pointer to the current runtime environment.
   * @return A pointer to the environment
   */
  inline const CgiEnvironment* getEnvironment() const { return fEnvironment; }
  
  /**
   * Re-parse all the form data.
   * This is useful after a call to getEnvironment()->restore().
   * @exception Exception
   */
  void reset() throw(Exception);
  //@}
  
private:
  
  // ========== Utility functions
  
  /* Convert query string into a linked list of FormEntrys */
  void parseFormInput(const char *data) throw(Exception);
  
  /* Utility function to optionally truncate and/or strip newlines
     Returns: -1 = truncated, 0 = source string empty, 1 = OK */
  int makeString(const char *src, 
		 char* &result,
		 int maxLen, 
		 int allowNewlines) const;
  
  /* Extract a string from the form data */
  bool getString(const char *elementName, 
		 int maxLen, 
		 char* &dest, 
		 bool allowNewlines) const throw(Exception);
  
  /* Extract multiple items with the same name */
  bool getMultiple(const char *elementName, 
		   char** &value, 
		   int &numFound) const throw(Exception);
  
  void parsePair(const char *data, int dataLen);
  void parseMIME(const char *data, int dataLen);
  MultipartHeader* parseHeader(const char *data, int headLen);
  
  CgiEnvironment 	*fEnvironment;
};


#endif
