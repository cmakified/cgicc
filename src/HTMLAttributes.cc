/* $Id: HTMLAttributes.cc,v 1.1 1998/02/12 05:31:41 sbooth Exp $ */

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

HTMLAttributeList::~HTMLAttributeList()
{}

HTMLAttributeList& 
HTMLAttributeList::add(const char *name, const char *value) throw(Exception) { 
  if(name != NULL && value != NULL)
    return add(new HTMLAttribute(name, value));
  else if(name != NULL && value == NULL)
    return add(new HTMLAtomicAttribute(name));
  else
    return *this;
}

HTMLAttributeList& 
HTMLAttributeList::add(const HTMLAttribute *attribute) { 
  if(attribute != NULL)
    LinkedList::add(attribute); 
  return *this; 
}

void 
HTMLAttributeList::render(ostream& out) const {
  const HTMLAttribute *current = (const HTMLAttribute*) getHead();
  
  while(current != NULL) {
    const HTMLAttribute *next = (const HTMLAttribute*) current->getNext();
    current->render(out);
    if(next != NULL)
      out << ' ';
    current = next;
  }
}

// ============================================================
// List manipulators
// ============================================================
static LinkedList *sLists = NULL;

HTMLAttributeList& 
add(const char *name, 
    const char *value) throw(Exception) 
{
  HTMLAttributeList *list = new HTMLAttributeList();
  registerList(list);
  list->add(name, value);
  return *list;
}

void 
registerList(const LinkedList *list) {	
  if(sLists == NULL) {
    sLists = new LinkedList();
    sLists->add(list);
  }
  else
    sLists->add(list);
}

void 
deleteAllLists() {
  if(sLists != NULL)
    delete sLists;
}
