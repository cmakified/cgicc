/* $Id: FormEntry.cc,v 1.2 1998/04/01 20:52:21 sbooth Exp $ */

#include "FormEntry.hh"

/* Create a new FormEntry */
FormEntry::FormEntry(const char	*name,
		     const char	*value,
		     int valueLen)
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
}

FormEntry::FormEntry(const FormEntry& entry) {
  fName = new char[strlen(entry.getName()) + 1];
  strcpy(fName, entry.getName());

  fValue = new char[strlen(entry.getValue()) + 1];
  strcpy(fValue, entry.getValue());
}

/* Delete this FormEntry */
FormEntry::~FormEntry()
{
  delete [] fName;
  delete [] fValue;
}

void
FormEntry::render(ostream& out) const {
  out << getName() << '=' << getValue();
}
