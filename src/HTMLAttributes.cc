/* $Id: HTMLAttributes.cc,v 1.2 1998/04/01 20:52:15 sbooth Exp $ */

#include "HTMLAttributes.hh"

// ============================================================
// Class HTMLAttribute
// ============================================================
HTMLAttribute::HTMLAttribute() 
  : fName(NULL), fValue(NULL)
{}

HTMLAttribute::HTMLAttribute(const char *name, 
			     const char *value) throw(Exception)
			       : fName(NULL), fValue(NULL)
{
  if(name != NULL)
    setName(name);
  if(value != NULL)
    setValue(value);
}

HTMLAttribute::HTMLAttribute(const HTMLAttribute& attribute)
  : fName(NULL), fValue(NULL)
{
  if(attribute.getName() != NULL)
    setName(attribute.getName());
  if(attribute.getValue() != NULL)
    setValue(attribute.getValue());
}

HTMLAttribute::~HTMLAttribute() {
  delete [] fName;
  delete [] fValue;
}

void
HTMLAttribute::setName(const char *name) throw (Exception) {
  delete [] fName;
  fName = new char [ strlen(name) + 1];
  if(fName == NULL)
    throw Exception("new failed", ERRINFO);
  strcpy(fName, name);
}

void
HTMLAttribute::setValue(const char *value) throw (Exception) {
  delete [] fValue;
  fValue = new char [ strlen(value) + 1];
  if(fValue == NULL)
    throw Exception("new failed", ERRINFO);  
  strcpy(fValue, value);
}

void 
HTMLAttribute::render(ostream& out) const {
  out << getName() << "=\"" << getValue() << "\"";
}

// ============================================================
// Class HTMLAtomicAttribute
// ============================================================
HTMLAtomicAttribute::HTMLAtomicAttribute()
{}

HTMLAtomicAttribute::HTMLAtomicAttribute(const char *name) throw(Exception)
  : HTMLAttribute(name, NULL)
{}

HTMLAtomicAttribute::HTMLAtomicAttribute(const HTMLAtomicAttribute& attribute)
  : HTMLAttribute(attribute)
{}

HTMLAtomicAttribute::~HTMLAtomicAttribute()
{}

void 
HTMLAtomicAttribute::render(ostream& out) const {
  out << getName();
}

// ============================================================
// Class HTMLAttributeList
// ============================================================
HTMLAttributeList::HTMLAttributeList() 
{}

HTMLAttributeList::HTMLAttributeList(const HTMLAttribute& head) {
  append(head);
}

HTMLAttributeList::HTMLAttributeList(const HTMLAttributeList& list)
  : LinkedList(list)
{}

HTMLAttributeList::~HTMLAttributeList()
{}

HTMLAttributeList&
HTMLAttributeList::add(const char *name, const char *value) throw(Exception) { 
  if(name != NULL && value != NULL)
    append(HTMLAttribute(name, value));
  else if(name != NULL && value == NULL)
    append(HTMLAtomicAttribute(name));
  return *this;
}

// ============================================================
// List manipulators
// ============================================================
HTMLAttributeList
add(const char *name, 
    const char *value) throw(Exception) 
{
  return HTMLAttributeList(HTMLAttribute(name, value));
}

