/* $Id: CgiDefs.cc,v 1.2 1998/04/01 20:52:31 sbooth Exp $ */

#include "CgiDefs.hh"

/* Fetch an environment variable - will NEVER return 0, only "" or a value */
void 	
safeGetenv(const char 	*varName, 
	   char*	&where) throw(Exception)
{
  char *var = getenv(varName);
  
  if(var != NULL) {
    where = new char[ strlen(var) + 1];
    if( ! where )
      throw Exception("new failed", ERRINFO);
    strcpy(where, var);
  }
  else {
    where = new char[1];
    if( ! where )
      throw Exception("new failed", ERRINFO);
    where[0] = '\0';
  }
}

/* A safer alternative to system() */
int 
saferSystem(const char *command) throw(Exception)
{
  char *s, *sp;
  int result = 0, len = 3*strlen(command) + 1;	// worst case is all | or ;
  
  s = new char[len];
  if( ! s )
    throw Exception("new failed", ERRINFO);
  sp = s;
  for(int i = 0; i < len; i++) {
    if(command[i] == ';')
      *sp++ = '\\';
    else if(command[i] == '|')
      *sp++ = '\\';
    *sp++ = command[i];
  }
  *sp = '\0';
  result = system(s);
  delete [] s;
  
  return result;
}

char 
firstNonspaceChar(const char *s) 
{
  int len = strspn( s, " \n\r\t" );
  return s[ len ];
}

char
hexToChar(char first, char second)
{
  char digit;
  digit = (first >= 'A' ? ((first & 0xDF) - 'A') + 10 : (first - '0'));
  digit *= 16;
  digit += (second >= 'A' ? ((second & 0xDF) - 'A') + 10 : (second - '0'));
  return digit;
}

void
unescapeChars(const char *src, int len, char* &result) throw(Exception)
{
  int srcPos = 0, dstPos = 0;
  char c = 0x00;
  result = new char[ len + 1 ];

  if( ! result ) 
    throw Exception("new failed", ERRINFO);

  while( srcPos < len ) {
    c = src[srcPos++];
    if(c == '+')
      result[dstPos++] = ' ';
    // changed because of weird byte-order swaps on some systems
    // shouldn't the following work (LTR eval order!?!)?
    // result[dstPos++] = hexToChar(src[srcPos++], src[srcPos++]);
    else if(c == '%') {
      result[dstPos++] = hexToChar(src[srcPos], src[srcPos + 1]);
      srcPos += 2;
    }
    else
      result[dstPos++] = c;
  }
  result[dstPos] = '\0';
}

/* find first occurence of search in data, and return index of first char */
int
findBytes(const char *data, int dataLen, const char *search)
{
  const char *d = data;
  bool gotMatch = false;

  while(gotMatch == false) {
    while( (*d++ != search[0]) && (d - data < dataLen)); // do nothing
    if(d - data > dataLen)
      return -1;
    *d--;
    if(bytesAreEqual(d, search, strlen(search)))
      gotMatch = true;
    else
      *d++;
  }
  
  return (d - data);
}

/* locate data between separators, and return the boundaries */
void
extractBetween(const char *data, int dataLen, 
	       const char *separator1, const char *separator2,
	       int &start, int &end)
{
  start = findBytes(data, dataLen, separator1);
  if(start != -1) {
    start += strlen(separator1);
    end = findBytes(data + start, dataLen - start, separator2);
    if(end != -1)
      end += start;
  }
  else
    end = -1;
}

void
extractBetween(const char *data, int dataLen, const char *separator, 
	       int &start, int &end)
{ extractBetween(data, dataLen, separator, separator, start, end); }

//EOF
