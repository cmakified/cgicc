/* $Id: Cgicc.cc,v 1.4 1998/04/02 11:10:08 sbooth Exp $ */

#ifndef __CGICC__
#include "Cgicc.hh"
#endif

#if HAS_UNAME
#include <sys/utsname.h>
#endif

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

// ============================================================
// Class MultipartHeader
// ============================================================
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

// ============================================================
// Class Cgicc
// ============================================================
Cgicc::Cgicc() throw(Exception)
  : fEnvironment(NULL), fFormData(NULL)
{
#if DEBUG
  time_t 	now;
  tm 		*date;
  char 		s[80];
  
  now = time(NULL);
  date = localtime(&now);
  strftime(s, 80, "%A, %B %d, %Y %I:%M:%S %p", date);
  log("Cgicc debugging log started on ");
  logln(s);
#endif
  
  fEnvironment = new CgiEnvironment();
  if(! fEnvironment)
    throw Exception("new failed", ERRINFO);

  fFormData = new LinkedList<FormEntry>();
  if(! fFormData)
    throw Exception("new failed", ERRINFO);
  
  if(stringsAreEqual(getEnvironment()->getRequestMethod(), "post", true))
    parseFormInput(getEnvironment()->getPostData());
  else
    parseFormInput(getEnvironment()->getQueryString());
}

Cgicc::~Cgicc()
{
  logln("Cleaning up...");
  delete fEnvironment;
  delete fFormData;
  logln("Cgicc debugging log closed.");
}

void
Cgicc::save(const char *filename) const throw(Exception) {
  logln("Cgicc::save");
  getEnvironment()->save(filename);
}

void
Cgicc::restore(const char *filename) throw(Exception) {
  logln("Cgicc::restore");
  ((CgiEnvironment*) getEnvironment())->restore(filename);
  fFormData->deleteAll();
  if(stringsAreEqual(getEnvironment()->getRequestMethod(), "post", true))
    parseFormInput(getEnvironment()->getPostData());
  else
    parseFormInput(getEnvironment()->getQueryString());
}

bool 
Cgicc::queryCheckbox(const char *elementName) const {
  const FormEntry *found = findEntryByName(elementName);
  return ((found != NULL) && stringsAreEqual(found->getValue(), "on", true));
}

LinkedList<FormEntry>::Iterator 
Cgicc::getElement(const char *name) {
  return fFormData->find(nameCompare, (void*) name);
}

LinkedList<FormEntry>::ConstIterator 
Cgicc::getElement(const char *name) const {
  return ((const LinkedList<FormEntry>*) fFormData)->
    find(nameCompare, (void*) name);
}

bool 
Cgicc::getElementMultiple(const char *elementName, 
			    LinkedList<FormEntry>& result) const  { 
  return findEntriesByName(elementName, result); 
}

const FormEntry* 
Cgicc::findEntryByName(const char *name) const {
  return findEntry(name, true); 
}

const FormEntry* 
Cgicc::findEntryByValue(const char *value) const {
  return findEntry(value, false); 
}

bool
Cgicc::findEntriesByName(const char *name,
			   LinkedList<FormEntry>& result) const {
  return findEntries(name, true, result); 
}

bool
Cgicc::findEntriesByValue(const char *value,
			    LinkedList<FormEntry>& result) const { 
  return findEntries(value, false, result); 
}

const FormEntry*
Cgicc::findEntry(const char *param, 
		   bool byName) const {
  LinkedList<FormEntry>::Iterator found = 
    (byName 	? fFormData->find(nameCompare, (void*) param)
     		: fFormData->find(valueCompare, (void*) param));
  
  return (found.isValid() ? &(*found) : NULL);
}

bool
Cgicc::findEntries(const char *param, 
		     bool byName,
		     LinkedList<FormEntry>& result) const {
  if(byName)
    fFormData->findAll(nameCompare, (void*) param, result);
  else
    fFormData->findAll(valueCompare, (void*) param, result);
  
  return ! (result.isEmpty());
}

void
Cgicc::parseFormInput(const char *data) throw(Exception)
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
Cgicc::parseHeader(const char *data, int headLen)
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
Cgicc::parsePair(const char *data, int dataLen)
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
  fFormData->append(FormEntry(name, value));
  
  delete [] name;
  delete [] value;
}

void
Cgicc::parseMIME(const char *data, int dataLen)
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
      fFormData->append(FormEntry(head->getName(), 
				  data + headLen, dataLen - headLen));
    else
      fFormData->append(FormFile(head->getName(), head->getFilename(), 
				 head->getContentType(), 
				 data + headLen, dataLen - headLen));
  }
  delete head;
}

//EOF
