/* $Id: Cgicc.hh,v 1.2 1998/04/02 04:54:44 sbooth Exp $ */

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

#ifndef __CGI_FORM__
#include "CgiForm.hh"
#endif


// ============================================================
// Class Cgicc
// ============================================================
/** 
 * Cgicc is a wrapper class for \Ref{CgiForm}.
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
 *   catch(\Ref{Exception} e) {
 *    <SPAN CLASS="green"> \\ handle the error</SPAN>
 *   }
 * }
 * </PRE>
 */
class Cgicc {
public:
  /**@name Constructor */
  //@{

  /** 
   * Default constructor. 
   * @exception Exception
   */
  Cgicc() throw(Exception);

  /* Destructor */
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
  inline const char* getCgiccVersion() const 	{ return "2.2b"; }
  //@}

  /**@name Acess to CGI data */
  //@{
  
  /**
   * Get the form data.
   * @return The form data.
   */
  CgiForm* 		operator* () 		{ return getFormData(); }

  /**
   * Get the form data.
   * @return The form data.
   */
  const CgiForm* 	operator* () const 	{ return getFormData(); }
  
  /**
   * Get the form data.
   * @return The form data.
   */
  inline CgiForm* 	getFormData() 		{ return fFormData; }

  /**
   * Get the form data.
   * @return The form data.
   */
  inline const CgiForm* getFormData() const 	{ return fFormData; }
  //@}

private:
  CgiForm *fFormData;
};

#endif
