/* $Id: Exception.hh,v 1.1 1998/04/01 20:44:48 sbooth Exp $ */

#ifndef __EXCEPTION__
#define __EXCEPTION__ 1

/** 
 * A convenience macro for passing in filename and line number information. 
 * <P>This is a just a more convenient form of <TT>__FILE__, __LINE__</TT>.</P>
 * @see Exception
 */
#define ERRINFO __FILE__,__LINE__

// ============================================================
// Class Exception
// ============================================================
/** 
 * Base class for all exceptions which may be thrown.
 * <P>Throw this class and subclasses just like any other exception type.<BR>
 * For simplified use, instead of passing in explicit values for
 * file and line (either directly or via <TT>__FILE__</TT> and 
 * <TT>__LINE__</TT>), try passing in the macro <TT>\Ref{ERRINFO}</TT>:</P>
 * 
 * <PRE CLASS="code">
 * try {
 *   ... // do something here
 *   if( ! success )
 *      throw Exception("Oh no!  An error!", ERRINFO);
 * }
 * catch(Exception e) {
 *    cerr << "Message : " << e.getMessage() << endl;
 *    cerr << "File    : " << e.getFile() << endl;
 *    cerr << "Line    : " << e.getLine() << endl;    
 * } 
 * </PRE>
 * @see ERRINFO
 */
class Exception
{
public:
  /**@name Constructors */
  //@{
  
  /** Create a new exception to be thrown. */
  Exception();
  
  /**
   * Create a new exception to be thrown. 
   * @param msg The error message  
   */
  Exception(char *msg);
  
  /**
   * Create a new exception to be thrown.
   * @param msg The error message
   * @param file The file in which the exception occurred
   * @param line The line number causing the exception
   */
  Exception(char *msg, 
	    char *file, 
	    int line);
  
  /* Destructor */
  virtual ~Exception();
  //@}
  
  /**@name Exception information */
  //@{
  
  /**
   * Get the error message associated with this exception.
   * @return The error message
   */
  inline const char* getMessage() const 	{ return fMessage; }
  
  /**
   * Get the name of the file from which this exception was thrown.
   * @return The name of the file which caused the error
   */
  inline const char* getFile() const 		{ return fFile; }
  
  /**
   * Get the line number at which this exception was thrown.
   * @return The line number which caused the error
   */
  inline int getLine() const			{ return fLine; }
  //@}
  
private:
  char 	*fMessage;	/* the error message for this error */
  char 	*fFile;		/* the file in which the error occured */
  int 	fLine;		/* the line number at which the error occurred */
};

#endif
