/* $Id: Cgicc.hh,v 1.8 1998/04/10 22:27:29 sbooth Exp $ */

#ifndef __CGICC__
#define __CGICC__ 1

/*
  The Cgicc library, by Stephen Booth <mailto:sbooth@hmc.edu>. 
  The latest version can be found on http://www.cs.hmc.edu/~sbooth/cgicc/

  Cgicc is intended to simplify and speed the development of C++ CGI(Common
  Gateway Interface) applications by providing a simple, yet comprehensive  
  set of classes that present full CGI functionality.
  */


#ifndef __EXCEPTION__
#include "Exception.hh"
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

// ============================================================
// Class Cgicc
// ============================================================
/**
 * Cgicc is the main class of the Cgicc library.
 * <P>Normally, you will instantiate an object of this type in 
 * <TT>main()</TT>:</P>
 * <PRE CLASS="code">
 * int
 * main(int argc, char **argv) {
 *   try {
 *     Cgicc *cgi = new Cgicc();
 *     <SPAN CLASS="green">\\ do something with cgi</SPAN>
 *   }
 *
 *   catch(Exception e) {
 *    <SPAN CLASS="green"> \\ handle the error</SPAN>
 *   }
 * }
 * </PRE>
 */
class Cgicc {
public:
  /**@name Constructors */
  //@{

  /** 
   * Default constructor. 
   * @exception Exception
   */
  Cgicc() throw(Exception);

  /** Destructor */
  ~Cgicc();
  //@}

  /**@name Cgicc Information */
  //@{

  /**
   * Get the date on which this library was compiled.
   * <P>This is a string of the form mmm dd yyyy.</P>
   * @return The compile date
   */
  inline const char* getCompileDate() const 	{ return __DATE__; }

  /**
   * Get the time at which this library was compiled.
   * <P>This is a string of the form hh:mm:ss in 24-hour time.</P>
   * @return The compile time
   */
  inline const char* getCompileTime() const 	{ return __TIME__; }

  /**
   * Get the version number of Cgicc.
   * <P>The version number is a string of the form #.#.</P>
   * @return The version number
   */
  inline const char* getCgiccVersion() const 	{ return "2.2"; }
  //@}

  /**@name Form Element Access */
  //@{

  /**
   * Query whether a checkbox is checked.
   * @param elementName The name of the element to query
   * @return True if the desired checkbox was checked, false if not
   */
  bool queryCheckbox(const char *elementName) const;

  /**
   * Find a radio button in a radio group, or a selected list item.
   * @param name The name of the radio button or list item to find.
   * @return An Iterator referring to the desired element.  If the element
   * is not found, the Iterator will not be valid.
   */
  LinkedList<FormEntry>::Iterator operator[] (const char *name)
  { return getElement(name); }

  /**
   * Find a radio button in a radio group, or a selected list item.
   * @param name The name of the radio button or list item to find.
   * @return An Iterator referring to the desired element.  If the element
   * is not found, the Iterator will not be valid.
   */
  LinkedList<FormEntry>::Iterator getElement(const char *name);

  /**
   * Find a radio button in a radio group, or a selected list item.
   * @param name The name of the radio button or list item to find.
   * @return A ConstIterator referring to the desired element.  If the element
   * is not found, the ConstIterator will not be valid.
   */
  LinkedList<FormEntry>::ConstIterator getElement(const char *name) const;

  /**
   * Find multiple checkboxes in a group or selected items in a list.
   * @param name The name of the checkboxes or list to find.
   * @param result A LinkedList to hold the result.
   * @return True if any elements were found, false if not.
   */
  bool getElementMultiple(const char *elementName,
			  LinkedList<FormEntry>& result) const;
  //@}

  /**@name Access to all form entries */
  //@{

  /**
   * Get all the submitted form elements.
   * @return A LinkedList containing all the submitted elements.
   */
  inline const LinkedList<FormEntry>& operator* () const 
  { return *fFormData; }
  
  /**
   * Get all the submitted form elements.
   * @return A LinkedList containing all the submitted elements.
   */
  inline const LinkedList<FormEntry>* getAllElements() const 
  { return fFormData; }
  //@}  

  /**@name Searching for form entries */
  //@{
  
  /**
   * Find an element in the linked list of entries by name.
   * @param name The <EM>name</EM> of the list element to search for
   * @return The desired list element, or NULL if not found
   */
  const FormEntry* findEntryByName(const char *name) const;
  
  /**
   * Find an element in the linked list of entries by value.
   * @param value The <EM>value</EM> of the list element to search for
   * @return The desired list element, or NULL if not found
   */
  const FormEntry* findEntryByValue(const char *value) const;

  /**
   * Find elements in the linked list of entries by name.
   * @param name The <EM>name</EM> of the list elements to search for.
   * @param result Where to store the found elements, if any.
   * @return True if any items were found, false if not.
   */
  bool findEntriesByName(const char 		*name,
			 LinkedList<FormEntry>& result) const;

  /**
   * Find elements in the linked list of entries by value.
   * @param value The <EM>name</EM> of the list elements to search for.
   * @param result Where to store the found elements, if any.
   * @return True if any items were found, false if not.
   */
  bool findEntriesByValue(const char 			*value,
			  LinkedList<FormEntry>& 	result) const;
    
  /* Find an element in the linked list of entries */
  const FormEntry* findEntry(const char *param, 
			     bool 	byName) const;

  /* Find elements in the linked list of entries */
  bool findEntries(const char 			*param, 
		   bool 			byName,
		   LinkedList<FormEntry>& 	result) const;
  //@}

  /**@name Access to the current environment */
  //@{
  
  /**
   * Get a pointer to the current runtime environment.
   * @return A pointer to the environment
   */
  inline const CgiEnvironment* getEnvironment() const { return fEnvironment; }
  //@}

  /**@name Save and Restore */
  //@{

  /**
   * Save the current CGI environment to a file.
   * @param filename The name of the file to which to save.
   * @exception Exception
   */
  void save(const char *filename) const throw(Exception);

  /**
   * Restore from a previously-saved CGI environment.
   * @param filename The name of the file from which to restore.
   * @exception Exception
   */
  void restore(const char *filename) throw(Exception);
  //@}

private:
  CgiEnvironment 	*fEnvironment;
  LinkedList<FormEntry> *fFormData;

  /* Convert query string into a linked list of FormEntriess */
  void parseFormInput(const char *data) throw(Exception);
  
  MultipartHeader* parseHeader(const char *data, int headLen);
  void parsePair(const char *data, int dataLen);
  void parseMIME(const char *data, int dataLen);
};

#endif
