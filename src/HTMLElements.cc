/* $Id: HTMLElements.cc,v 1.1 1998/02/12 05:31:41 sbooth Exp $ */

#include "HTMLElements.hh"

// ============================================================
// Class HTMLElement
// ============================================================
HTMLElement::HTMLElement()
  : fAttributes(NULL)
{}

HTMLElement::HTMLElement(const HTMLAttributeList *attributes) {
  setAttributes(attributes);
}

HTMLElement::~HTMLElement()
{}

void
HTMLElement::render(ostream& out) const {
  out << '<' << getName();
  if(getAttributes() != NULL) {
    out << ' ';
    getAttributes()->render(out);
  }
  out << '>';
}

// ============================================================
// Class HTMLSimpleElement
// ============================================================
HTMLSimpleElement::HTMLSimpleElement()
  : fData(NULL)
{}

HTMLSimpleElement::HTMLSimpleElement(const char *data, 
				     const HTMLAttributeList *attributes,
				     const HTMLSimpleElement *embedded) 
  throw(Exception)
    : fData(NULL), HTMLElement(attributes), fEmbedded(embedded)
{
  if(data != NULL)
    setData(data);
  else
    fData = NULL;
}

HTMLSimpleElement::~HTMLSimpleElement()
{
  delete [] fData;
}

void
HTMLSimpleElement::setData(const char *data) throw (Exception) {
  delete [] fData;
  fData = new char [ strlen(data) + 1 ];
  if(fData == NULL)
    throw Exception("new failed", ERRINFO);
  strcpy(fData, data);
}

void
HTMLSimpleElement::render(ostream& out) const {
  out << '<';
  out << getName();
  if(getAttributes() != NULL) {
    out << ' ';
    getAttributes()->render(out);
  }
  out << '>';
  if(getEmbedded() == NULL)
    out << getData();
  else
    getEmbedded()->render(out);
  out << "</" << getName() << '>';
}

// ============================================================
// Class HTMLBooleanElement
// ============================================================
HTMLBooleanElement::HTMLBooleanElement()
{}

HTMLBooleanElement::HTMLBooleanElement(const char *data, 
				       const HTMLAttributeList *attributes,
				       const HTMLSimpleElement *embedded)
  throw(Exception)
    : HTMLSimpleElement(data, attributes, embedded)
{}

HTMLBooleanElement::~HTMLBooleanElement()
{}

void
HTMLBooleanElement::render(ostream& out) const {
  if(getData() == NULL) {
    if(getEmbedded() == NULL) {
      swapState();
      out << '<';
      if(getState()) {
	out << getName();
	if(getAttributes() != NULL) {
	  out << ' ';
	  getAttributes()->render(out);
	}
	out << '>';
      }
      else
	out << '/' << getName() << '>';
    }
    else {
      out << '<' << getName();
      if(getAttributes() != NULL) {
	out << ' ';
	getAttributes()->render(out);
      }
      out << '>';
      getEmbedded()->render(out);
      out << "</" << getName() << '>';		
    }
  }
  else
    HTMLSimpleElement::render(out);
}
