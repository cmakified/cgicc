/*
 * $Id: HTMLDirLang.cc,v 1.2 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

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
