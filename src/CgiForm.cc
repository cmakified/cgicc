/* $Id: CgiForm.cc,v 1.2 1998/04/01 20:52:38 sbooth Exp $ */

#include "CgiForm.hh"

bool
nameCompare(const FormEntry& element, void *data) {
  const char *name = (const char*) data;

  if(stringsAreEqual(element.getName(), name, true))
    return true;
  else
    return false;
}

bool
valueCompare(const FormEntry& element, void *data) {
  const char *value = (const char*) data;

  if(stringsAreEqual(element.getValue(), value, true))
    return true;
  else
    return false;
}

// ========== MultipartHeader

class MultipartHeader {
public:
  
  MultipartHeader(const char *data,
		  int dispStart, int dispEnd,
		  int nameStart, int nameEnd,
		  int filenameStart, int filenameEnd,
		  int cTypeStart, int cTypeEnd) throw(Exception);
  ~MultipartHeader();
  
  inline const char* getContentDisposition() const
  { return fContentDisposition; }
  
  inline const char* getName() const  		{ return fName; }
  inline const char* getFilename() const  	{ return fFilename; }
  inline const char* getContentType() const 	{ return fContentType; }

  inline bool isEmpty() const { return fEmpty; }

private:
  static int calcLen(int end, int start);

  char *fContentDisposition;
  char *fName;
  char *fFilename;
  char *fContentType;

  bool fEmpty;
};

int
MultipartHeader::calcLen(int end, int start)
{
  if(start == -1 && end == -1)
    return -1;
  else
    return (end - start);
}

MultipartHeader::MultipartHeader(const char *data,
				 int dispStart, int dispEnd,
				 int nameStart, int nameEnd,
				 int filenameStart, int filenameEnd,
				 int cTypeStart, int cTypeEnd) throw(Exception)
  : fContentDisposition(NULL), fName(NULL), fFilename(NULL), fContentType(NULL)
  , fEmpty(false)
{
  int dispLen = calcLen(dispEnd, dispStart);
  int nameLen = calcLen(nameEnd, nameStart);
  int filenameLen = calcLen(filenameEnd, filenameStart);
  int cTypeLen = calcLen(cTypeEnd, cTypeStart);

  if(dispLen != -1) {
    fContentDisposition =  new char [dispLen + 1];
    strncpy(fContentDisposition, data + dispStart, dispLen);
    fContentDisposition[dispLen] = '\0';
  }

  if(nameLen != -1) {
    fName = new char [nameLen + 1];
    strncpy(fName, data + nameStart, nameLen);
    fName[nameLen] = '\0';
  }
  
  if(filenameLen == 0)
    fEmpty = true;
  else if(filenameLen != -1) {
    // This is hairy: Netscape encodes the filenames, and IE doesn't.
    // The RFC says they should be encoded, so I will assume they are.
    unescapeChars(data + filenameStart, filenameLen, fFilename);
    //fFilename = new char [filenameLen + 1];
    //strncpy(fFilename, data + filenameStart, filenameLen);
    //fFilename[filenameLen] = '\0';
  }

  if(cTypeLen != -1) {
    fContentType = new char[cTypeLen + 1];
    strncpy(fContentType, data + cTypeStart, cTypeLen);
    fContentType[cTypeLen] = '\0';
  }
}

MultipartHeader::~MultipartHeader()
{
  delete [] fContentDisposition;
  delete [] fName;
  delete [] fFilename;
  delete [] fContentType;
}

// ========== Constructor/Destructor

CgiForm::CgiForm()
{
  logln("Entering CgiForm::CgiForm");
  fEnvironment = new CgiEnvironment();
  
  if(stringsAreEqual(getEnvironment()->getRequestMethod(), "post", true))
    parseFormInput(getEnvironment()->getPostData());
  else
    parseFormInput(getEnvironment()->getQueryString());
}


CgiForm::~CgiForm()
{
  logln("Entering CgiForm::~CgiForm");
  delete fEnvironment;
}

void
CgiForm::reset() throw(Exception)
{
  logln("CgiForm::reset()");
  deleteAll();
  if( stringsAreEqual(getEnvironment()->getRequestMethod(), "post", true ))
    parseFormInput(getEnvironment()->getPostData()); 
  else
    parseFormInput(getEnvironment()->getQueryString());
}

// ========== Access to form data as strings

bool
CgiForm::getAsString( 	const char 	*elementName, 
			char*		&dest) const throw(Exception)
{ return getAsString(elementName, INT_MAX, dest); }

bool
CgiForm::getAsString( 	const char 	*elementName, 
			int 		maxLen,
			char*		&dest) const throw(Exception)
{ return getString(elementName, maxLen, dest, true); }

bool
CgiForm::getAsStringNoNewlines( const char 	*elementName, 
				char*		&dest) const throw(Exception)
{ return getAsStringNoNewlines(elementName, INT_MAX, dest); }

bool
CgiForm::getAsStringNoNewlines( const char 	*elementName, 
				int 		maxLen,
				char*		&dest) const throw(Exception)
{ return getString(elementName, maxLen, dest, false); }


// ========== Access to form data as integers

bool 
CgiForm::getAsInteger(const char 	*elementName, 
		      int 		&value) const  throw(Exception)
{ return getAsBoundedInteger(elementName, INT_MIN, INT_MAX, value); }

bool 
CgiForm::getAsBoundedInteger(const char *elementName, 
			     int min, 
			     int max, 
			     int &value) const throw(Exception)
{
  const FormEntry *entry = findEntryByName(elementName);
  bool found = (entry != NULL);
  char c;
  
  if( found ) {
    c = firstNonspaceChar(entry->getValue());
    if( (! isdigit(c)) && (c != '-') && (c != '+') )
      found = false;
    else {
      value = atoi(entry->getValue());
      if(value > max)
	value = max;
      else if(value < min)
	value = min;	
    }
  }
  else
    value = 0;
  
  return found;
}


// ========== Access to form data as doubles

bool 
CgiForm::getAsDouble(const char *elementName, 
		     double &value) const throw(Exception)
{ return getAsBoundedDouble(elementName, DBL_MIN, DBL_MAX, value); }

bool 
CgiForm::getAsBoundedDouble(const char *elementName, 
			    double min, 
			    double max, 
			    double &value) const throw(Exception)
{
  const FormEntry *entry = findEntryByName(elementName);
  bool found = (entry != NULL);
  char c;
  
  if( found ) {
    c = firstNonspaceChar(entry->getValue());
    if( (! isdigit(c)) && (c != '-') && (c != '+') )
      found = false;
    else {
      value = atof(entry->getValue());
      if(value > max)
	value = max;
      else if(value < min)
	value = min;	
    }
  }
  else
    value = 0;
  
  return found;
}


// ========== Access to checkboxes

bool 
CgiForm::queryCheckbox(const char *elementName) const throw(Exception)
{
  const FormEntry *found = findEntryByName(elementName);
  return ((found != NULL) && stringsAreEqual(found->getValue(), "on", true));
}

bool
CgiForm::getCheckboxMultiple(	const char *elementName, 
				char** &value, 
				int &numFound) const throw(Exception)
{ return getMultiple(elementName, value, numFound); }


// ========== Access to radio buttons

bool 
CgiForm::getRadio(const char *elementName, 
		  char* &value) const throw(Exception)
{ return getAsStringNoNewlines(elementName, value); }


// ========== Access to list items

bool 
CgiForm::getSelectSingle(const char *elementName, 
			 char* &value) const throw(Exception)
{ return getAsStringNoNewlines(elementName, value); }

bool 
CgiForm::getSelectMultiple(const char *elementName, 
			   char** &value, 
			   int &numFound) const throw(Exception)
{ return getMultiple(elementName, value, numFound); }

const FormEntry* 
CgiForm::findEntryByName(const char *name) const
{ return findEntry(name, true); }

const FormEntry* 
CgiForm::findEntryByValue(const char *value) const
{ return findEntry(value, false); }

const FormEntry*
CgiForm::findEntry(const char *param, 
		   bool byName) const
{
  LinkedList<FormEntry>::ConstIterator found = 
    (byName 	? find(nameCompare, (void*) param)
     		: find(valueCompare, (void*) param));
  
  return (found.isValid() ? &(*found) : NULL);
}

// ========== Utility functions

void
CgiForm::parseFormInput(const char *data) throw(Exception)
{
  const char *cType = "multipart/form-data;";
  
  if(stringsAreEqual(cType, getEnvironment()->getContentType(), 
		     strlen(cType), true)) {
    logln("Multipart data detected.");
    // Find out what the separator is
    char *sep;
    
    const char *bType = "boundary=";
    char *fSeparator = strstr(getEnvironment()->getContentType(), bType)
      + strlen(bType);
    
    sep = new char [strlen(fSeparator) + 2 + 2 + 1];
    strcpy(sep, "--");
    strcat(sep, fSeparator);
    strcat(sep, "\r\n");

    char *sep2 = new char [strlen(fSeparator) + 2 + 2 + 2 + 1];
    strcpy(sep2, "--");
    strcat(sep2, fSeparator);
    strcat(sep2, "--");
    strcat(sep2, "\r\n");

    // Extract the data between the separators
    int start = 0, end = 0;

    extractBetween(data, getEnvironment()->getContentLength(), sep, sep2, 
		   start, end);

    int dataLen = end - start;
    
    int extractedLen = 0;
    while(extractedLen <= dataLen) {
      int newLen;
      newLen = findBytes(data + start + extractedLen, 
			 dataLen - extractedLen, 
			 sep);
      if(newLen == -1)
	newLen = dataLen - extractedLen;
      // - 2 to subtract off the trailing CR/LF sequence
      parseMIME(data + start + extractedLen, newLen - 2);
      extractedLen += (newLen + strlen(sep));
    }
  }
  else {
    int dataLen = strlen(data);
    const char *sep = "&";
    
    int extractedLen = 0;
    while(extractedLen <= dataLen) {
      int newLen;
      newLen = findBytes(data + extractedLen, 
			 dataLen - extractedLen, 
			 sep);
      if(newLen == -1)
	newLen = dataLen - extractedLen;
      
      parsePair(data + extractedLen, newLen);      
      extractedLen += (newLen + strlen(sep));
    }
  }
}

MultipartHeader*
CgiForm::parseHeader(const char *data, int headLen)
{
  int dispStart, dispEnd;
  extractBetween(data, headLen, "Content-Disposition: ", ";",
		 dispStart, dispEnd);
  
  int nameStart, nameEnd;
  extractBetween(data, headLen, "name=\"", "\"",
		 nameStart, nameEnd);
  
  int filenameStart, filenameEnd;
  extractBetween(data, headLen, "filename=\"", "\"",
		 filenameStart, filenameEnd);
  
  // Why is it that Netscape uses "Content-Type: " and Microsoft
  // uses "Content-type: " ?  To make my life more difficult?
  // This is a hack- it's not optimal but should work.

  int cTypeStart, cTypeEnd;
  extractBetween(data, headLen, "Content-Type: ", "\r\n\r\n",
		 cTypeStart, cTypeEnd); // for Netscape style
  if(cTypeStart == -1 && cTypeEnd == -1)
    extractBetween(data, headLen, "Content-type: ", "\r\n\r\n",
		   cTypeStart, cTypeEnd); // for Microsoft style

  return new MultipartHeader(data, 
			     dispStart, dispEnd,
			     nameStart, nameEnd,
			     filenameStart, filenameEnd,
			     cTypeStart, cTypeEnd);
}

void
CgiForm::parsePair(const char *data, int dataLen)
{
  // Find the divider
  int sepPos = 0;
  const char *sep = "=";
  sepPos = findBytes(data, dataLen, sep);
  
  // Extract data, convert, and add
  char *name;
  char *value;
  unescapeChars(data, sepPos, name);
  unescapeChars(data + sepPos + 1, dataLen - sepPos - 1, value);
  
  log("Got ("); log(name); log(", "); log(value); logln(")");
  append(FormEntry(name, value));
  
  delete [] name;
  delete [] value;
}

void
CgiForm::parseMIME(const char *data, int dataLen)
{
  // Find the header
  int headLen = 0;
  const char *end = "\r\n\r\n";
  headLen = findBytes(data, dataLen, end) + strlen(end);

  // Parse the header
  MultipartHeader *head = parseHeader(data, headLen);

  if(head->isEmpty() == false) {
    // Extract data
    if(head->getFilename() == NULL)
      append(FormEntry(head->getName(), 
		       data + headLen, dataLen - headLen));
    else
      append(FormFile(head->getName(), head->getFilename(), 
		      head->getContentType(), 
		      data + headLen, dataLen - headLen));
  }
  delete head;
}

int 
CgiForm::makeString(const char	*src, 
		    char*	&result, 
		    int 	maxLen, 
		    int 	allowNewlines) const
{
  char *dest, *s;
  int truncated = 0;
  int len 	= 0;
  int avail 	= maxLen - 1;
  int crCount 	= 0;
  int lfCount 	= 0;	

  dest 	= result;
  s 	= (char*) src;	

  while(true) {
    char c = *s;

    if( len == avail ) {
      truncated = true;
      break;
    }	 
		
    // Fix the CR/LF, LF, CR nightmare: watch for
    // consecutive bursts of CRs and LFs in whatever
    // pattern, then actually output the larger number 
    // of LFs. Consistently sane, yet it still allows
    // consecutive blank lines when the user
    // actually intends them.
    if( ( c == 13 ) || ( c == 10 ) ) 
      if( c == 13 ) 
	crCount++;
      else 
	lfCount++;
    else {
      if( crCount || lfCount ) {
	int lfsAdd = crCount;
	if( lfCount > crCount ) 
	  lfsAdd = lfCount;
	
	// Stomp all newlines if desired
	if ( ! allowNewlines ) 
	  lfsAdd = 0;
	
	while( lfsAdd ) {
	  if( len == avail ) {
	    truncated = true;
	    break;
	  }
	  *dest++ = 10;
	  lfsAdd--;
	  len++;		
	}
	crCount = 0;
	lfCount = 0;
      }
      if( c == '\0' ) {
	// The end of the source string
	break;				
      }
      *dest++ = c;
      len++;
    }
    s++;	
  }
  *dest = '\0';
  
  if( truncated ) 
    return -1;
  else if( ! len) 
    return 0;
  else 
    return 1;
}

bool 
CgiForm::getString(const char *elementName, 
		   int maxLen, 
		   char* &dest, 
		   bool allowNewlines) const throw(Exception)
{
  const FormEntry *entry = findEntryByName(elementName);
  bool found = (entry != NULL);
  
  if( found ) {
    dest = new char[ strlen(entry->getValue()) +1 ];
    if( ! dest )
      throw Exception("new failed", ERRINFO);
    int result = makeString(entry->getValue(), dest, maxLen, allowNewlines);
    if( ! result ) {
      delete [] dest;
      dest = NULL;
      found = false;
    }
  }
  else
    dest = NULL;
  
  return found;
}

/* Extract multiple items with the same name */
bool 
CgiForm::getMultiple(const char *elementName, 
		     char** &value, 
		     int &numFound) const throw(Exception)
{
  LinkedList<FormEntry> found;
  findAll(nameCompare, (void*) elementName, found);

  if(! found.isEmpty()) {
    numFound = found.length();
    value = new char* [ numFound ];
    if( ! value )
      throw Exception("new failed", ERRINFO);
    
    LinkedList<FormEntry>::Iterator iter = found.begin();
    
    int index = 0;
    while(iter.isValid()) {
      value[ index ] = new char [ strlen((*iter).getValue()) + 1];
      if( ! value[ index ] )
	throw Exception("new failed", ERRINFO);
      
      strcpy(value[index++], (*iter++).getValue());
    }
  }
  else {
    value = NULL;
    numFound = 0;
  }
  
  return (! found.isEmpty());
}


/* end of class CgiForm */
