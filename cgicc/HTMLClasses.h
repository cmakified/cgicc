/* -*-c++-*- */
/*
 *  $Id: HTMLClasses.h,v 1.6 1999/09/22 22:30:11 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999 Stephen F. Booth
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _HTMLCLASSES_H_
#define _HTMLCLASSES_H_ 1

#include "cgicc/CgiDefs.h"
#include "cgicc/HTMLGeneric.h"


// ============================================================
// Macros defining types of elements
// ============================================================

#define TAG(name, tag) \
class name##Tag   \
{ public: inline static const char* getName() { return tag; } }

#define ATOMIC_ELEMENT(name, tag) \
TAG(name, tag); typedef GenericAtomicElement<name##Tag> name

#define BOOLEAN_ELEMENT(name, tag) \
TAG(name, tag); typedef GenericBooleanElement<name##Tag> name


// ============================================================
// HTML 4.0 elements - for details see http://www.w3c.org/
// ============================================================

CGICC_BEGIN_NAMESPACE

// 'comment' is defined in HTMLGeneric.hh

// global structure

BOOLEAN_ELEMENT (html,       "HTML");       // HTML document
BOOLEAN_ELEMENT (head,       "HEAD");       // document head
BOOLEAN_ELEMENT (title,      "TITLE");      // document title
ATOMIC_ELEMENT  (meta,       "META");       // meta data
BOOLEAN_ELEMENT (style,      "STYLE");      // style sheet
BOOLEAN_ELEMENT (body,       "BODY");       // document body
#if CGICC_USE_NAMESPACES
BOOLEAN_ELEMENT (div,        "DIV");        // block-level grouping
#else
BOOLEAN_ELEMENT (div_,       "DIV");        // block-level grouping
#endif
BOOLEAN_ELEMENT (span,       "SPAN");       // inline grouping
BOOLEAN_ELEMENT (h1,         "H1");         // level 1 heading
BOOLEAN_ELEMENT (h2,         "H2");         // level 2 heading
BOOLEAN_ELEMENT (h3,         "H3");         // level 3 heading
BOOLEAN_ELEMENT (h4,         "H4");         // level 4 heading
BOOLEAN_ELEMENT (h5,         "H5");         // level 5 heading
BOOLEAN_ELEMENT (h6,         "H6");         // level 6 heading
BOOLEAN_ELEMENT (address,    "ADDRESS");    // contact information

// text markup

BOOLEAN_ELEMENT (em,         "EM");         // emphasis
BOOLEAN_ELEMENT (strong,     "STRONG");     // stronger emphasis
BOOLEAN_ELEMENT (cite,       "CITE");       // citation/reference
BOOLEAN_ELEMENT (dfn,        "DFN");        // defining instance
BOOLEAN_ELEMENT (code,       "CODE");       // computer code
BOOLEAN_ELEMENT (samp,       "SAMP");       // sample output
BOOLEAN_ELEMENT (kbd,        "KBD");        // user input
BOOLEAN_ELEMENT (var,        "VAR");        // variable/argument
BOOLEAN_ELEMENT (abbr,       "ABBR");       // abbreviated form
BOOLEAN_ELEMENT (acronym,    "ACRONYM");    // acronym
BOOLEAN_ELEMENT (blockquote, "BLOCKQUOTE"); // block-level quotation
BOOLEAN_ELEMENT (q,          "Q");          // inline quotation
BOOLEAN_ELEMENT (sub,        "SUB");        // subscript
BOOLEAN_ELEMENT (sup,        "SUP");        // superscript
BOOLEAN_ELEMENT (p,          "P");          // paragraph
ATOMIC_ELEMENT  (br,         "BR");         // line break
BOOLEAN_ELEMENT (pre,        "PRE");        // preformatted text
BOOLEAN_ELEMENT (ins,        "INS");        // inserted text
BOOLEAN_ELEMENT (del,        "DEL");        // deleted text
BOOLEAN_ELEMENT (bdo,        "BDO");        // overriding direction

// lists

BOOLEAN_ELEMENT (ul,         "UL");         // unordered list
BOOLEAN_ELEMENT (ol,         "OL");         // ordered list
BOOLEAN_ELEMENT (li,         "LI");         // list item 
BOOLEAN_ELEMENT (dl,         "DL");         // definition list         
BOOLEAN_ELEMENT (dt,         "DT");         // term to be defined
BOOLEAN_ELEMENT (dd,         "DD");         // definition of term

// tables

BOOLEAN_ELEMENT (table,      "TABLE");      // table element
BOOLEAN_ELEMENT (caption,    "CAPTION");    // table caption
BOOLEAN_ELEMENT (thead,      "THEAD");      // table head section
BOOLEAN_ELEMENT (tfoot,      "TFOOT");      // table foot section
BOOLEAN_ELEMENT (tbody,      "TBODY");      // table body section
BOOLEAN_ELEMENT (colgroup,   "COLGROUP");   // vertical section
ATOMIC_ELEMENT  (col,        "COL");        // column attributes
BOOLEAN_ELEMENT (tr,         "TR");         // table row
BOOLEAN_ELEMENT (th,         "TH");         // table header cell
BOOLEAN_ELEMENT (td,         "TD");         // table data cell

// links

BOOLEAN_ELEMENT (a,          "A");          // anchor
#if CGICC_USE_NAMESPACES
ATOMIC_ELEMENT  (link,       "LINK");       // document link
#else
ATOMIC_ELEMENT  (link_,      "LINK");       // document link
#endif
ATOMIC_ELEMENT  (base,       "BASE");       // path information

// objects

ATOMIC_ELEMENT  (img,        "IMG");        // inline image
BOOLEAN_ELEMENT (object,     "OBJECT");     // generic object
ATOMIC_ELEMENT  (param,      "PARAM");      // object parameters
BOOLEAN_ELEMENT (map,        "MAP");        // client image map
ATOMIC_ELEMENT  (area,       "AREA");       // image map region
ATOMIC_ELEMENT  (hr,         "HR");         // horizontal rule

// fonts - preferably use stylesheets

BOOLEAN_ELEMENT (tt,         "TT");         // monospaced text
BOOLEAN_ELEMENT (i,          "I");          // italic text style
BOOLEAN_ELEMENT (b,          "B");          // bold text style
BOOLEAN_ELEMENT (big,        "BIG");        // large font
BOOLEAN_ELEMENT (small,      "SMALL");      // small font

// frames - not part of the strict DTD

BOOLEAN_ELEMENT (frameset,   "FRAMESET");   // frame layout
ATOMIC_ELEMENT  (frame,      "FRAME");      // frame contents
BOOLEAN_ELEMENT (noframes,   "NOFRAMES");   // alternative text
BOOLEAN_ELEMENT (iframe,     "IFRAME");     // inline frame

// forms

BOOLEAN_ELEMENT (form,       "FORM");       // form element
ATOMIC_ELEMENT  (input,      "INPUT");      // generic input
BOOLEAN_ELEMENT (button,     "BUTTON");     // special button
#if CGICC_USE_NAMESPACES
BOOLEAN_ELEMENT (select,     "SELECT");     // option menu
#else
BOOLEAN_ELEMENT (select_,    "SELECT");     // option menu
#endif
BOOLEAN_ELEMENT (optgroup,   "OPTGROUP");   // option group
BOOLEAN_ELEMENT (option,     "OPTION");     // option item
BOOLEAN_ELEMENT (textarea,   "TEXTAREA");   // multi-line text input
BOOLEAN_ELEMENT (label,      "LABEL");      // input label
BOOLEAN_ELEMENT (fieldset,   "FIELDSET");   // grouping input fields
BOOLEAN_ELEMENT (legend,     "LEGEND");     // caption for field set

// scripts

BOOLEAN_ELEMENT (script,     "SCRIPT");     // script element
BOOLEAN_ELEMENT (noscript,   "NOSCRIPT");   // alternative text

CGICC_END_NAMESPACE

#endif /* ! _HTMLCLASSES_H_ */
