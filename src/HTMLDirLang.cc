/* $Id: HTMLDirLang.cc,v 1.1 1998/02/12 05:31:41 sbooth Exp $ */

#include "HTMLDirLang.hh"

// ============================================================
// Statics
// ============================================================
bool bdo::sState = false;

// ============================================================
// Class bdo
// ============================================================
bdo::bdo(const char *text) 
  : HTMLBooleanElement(text, NULL, NULL)
{}

bdo::bdo(const HTMLAttributeList& attributes)
  : HTMLBooleanElement(NULL, &attributes, NULL)
{}

bdo::bdo(const HTMLSimpleElement& embed)
  : HTMLBooleanElement(NULL, NULL, &embed)
{}

bdo::bdo(const char *text, const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, NULL)
{}

bdo::bdo(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
  : HTMLBooleanElement(NULL, &attributes, &embed)
{}

bdo::~bdo()
{}
