/* $Id: FormEntry.cc,v 1.1 1998/02/12 05:31:41 sbooth Exp $ */

#include "FormEntry.hh"

/* initializs head and tail to NULL */
FormEntry* FormEntry::sHead = NULL;		/* the head of the list */
FormEntry* FormEntry::sTail = NULL;		/* the tail of the list */

void 
FormEntry::deleteAll()
{
  logln("FormEntry::deleteAll()");
  FormEntry *current = (FormEntry*) getHead();
  
  while(current != NULL) {
    FormEntry *next = (FormEntry*) current->getNextEntry();
    delete current;
    current = next;
  }
}

/* Find a FormEntry in the list by name */
const FormEntry* 
FormEntry::findEntryByName(const char *name)
{ return findEntry(name, true, getHead()); }

const FormEntry* 
FormEntry::findEntryByName(const char *name, const FormEntry *start)
{ return findEntry(name, true, start); }

/* Find a FormEntry in the list by value */
const FormEntry* 
FormEntry::findEntryByValue(const char *value)
{ return findEntry(value, false, getHead()); }

const FormEntry* 
FormEntry::findEntryByValue(const char *value, const FormEntry *start)
{ return findEntry(value, false, start); }

/* Find a FormEntry in the list */
const FormEntry* 
FormEntry::findEntry(const char *param, 
		     bool 	byName )
{ return findEntry(param, byName, getHead()); }

const FormEntry* 
FormEntry::findEntry(const char 	*param, 
		     bool 		byName,
		     const FormEntry 	*start )
{
  FormEntry *current = (FormEntry*) start;
  
  while(current != NULL) {
    const char *s = (byName ? current->getName() : current->getValue());
    if( stringsAreEqual( param, s, true ))
      break;
    current = (FormEntry*) current->getNextEntry();
  }
  
  return current;
}

/* Create a new FormEntry */
FormEntry::FormEntry(const char	*name,
		     const char	*value,
		     int valueLen)
  : fNext(NULL)
{
  fName = new char[strlen(name) + 1];
  strcpy(fName, name);
  
  if(valueLen == -1) {
    fValue = new char[strlen(value) + 1];
    strcpy(fValue, value);  
  }
  else {
    fValue = new char[valueLen + 1];
    strncpy(fValue, value, valueLen);
    fValue[valueLen] = '\0';
  }

  addEntry(this);
}

/* Delete this FormEntry, removing it from the list */
FormEntry::~FormEntry()
{
  FormEntry *current = (FormEntry*) getHead();
  FormEntry *previous = NULL;
  
  delete [] fName;
  delete [] fValue;
  
  if( this != getHead() ) {
    while( current != this ) {
      previous	= current;
      current 	= (FormEntry*) current->getNextEntry();
    } 
    
    // take this element out of the list
    previous->fNext = 
      (FormEntry*) (current->getNextEntry() == NULL ? NULL 
		    : current->getNextEntry());
  }
  else
    sHead = (FormEntry*) current->getNextEntry();
}

/* Add a FormEntry to the list */
void 
FormEntry::addEntry( const FormEntry *newEntry )
{
  if( getHead() == NULL )
    sHead = sTail = (FormEntry*) newEntry;
  else {
    FormEntry *oldTail = (FormEntry*) getTail();
    
    oldTail->fNext = (FormEntry*) newEntry;
    sTail = (FormEntry*) newEntry;
  }
}

//EOF
