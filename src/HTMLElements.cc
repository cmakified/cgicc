/*
 * $Id: HTMLElements.cc,v 1.3 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

#include "HTMLElements.hh"

// ============================================================
// Class HTMLElement
// ============================================================
HTMLElement::HTMLElement()
  : fAttributes(NULL)
{}

HTMLElement::HTMLElement(const HTMLElement& element) throw(Exception)
  : fAttributes(NULL)
{
  if(element.getAttributes() != NULL)
    setAttributes(element.getAttributes());
}

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

HTMLSimpleElement::HTMLSimpleElement(const HTMLSimpleElement& element)
  throw(Exception)
  : HTMLElement(element), fEmbedded(NULL), fData(NULL)
{
  if(element.getEmbedded() != NULL)
    setEmbedded(element.getEmbedded());

  if(element.getData() != NULL)
    setData(element.getData());
}

HTMLSimpleElement::HTMLSimpleElement(const char *data, 
				     const HTMLAttributeList *attributes,
				     const HTMLSimpleElement *embedded) 
  throw(Exception)
    : HTMLElement(attributes), fEmbedded(embedded), fData(NULL)
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

HTMLBooleanElement::HTMLBooleanElement(const HTMLBooleanElement& element)
  throw(Exception)
  : HTMLSimpleElement(element)
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
