/*
 *  $Id: HTMLText.cc,v 1.5 1999/04/26 22:42:32 sbooth Exp $
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

#include "HTMLText.hh"

// ============================================================
// Statics
// ============================================================
bool CGICCNS em::sState 	= false;
bool CGICCNS strong::sState 	= false;
bool CGICCNS dfn::sState 	= false;
bool CGICCNS samp::sState 	= false;
bool CGICCNS code::sState 	= false;
bool CGICCNS kbd::sState 	= false;
bool CGICCNS var::sState 	= false;
bool CGICCNS cite::sState 	= false;
bool CGICCNS abbr::sState 	= false;
bool CGICCNS acronym::sState 	= false;
bool CGICCNS blockquote::sState = false;
bool CGICCNS q::sState 		= false;
bool CGICCNS sub::sState 	= false;
bool CGICCNS sup::sState 	= false;
bool CGICCNS p::sState 		= false;
bool CGICCNS pre::sState 	= false;
bool CGICCNS ins::sState 	= false;
bool CGICCNS del::sState 	= false;

// ============================================================
// Class em
// ============================================================
CGICCNS em::em() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS em::em(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS em::em(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS em::em(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS em::em(const STDNS string& text, 
	       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS em::em(const HTMLAttributeList& attributes, 
	       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS em::~em()
{}

// ============================================================
// Class strong
// ============================================================
CGICCNS strong::strong() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS strong::strong(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS strong::strong(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS strong::strong(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS strong::strong(const STDNS string& text, 
		       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS strong::strong(const HTMLAttributeList& attributes, 
		       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS strong::~strong()
{}

// ============================================================
// Class dfn
// ============================================================
CGICCNS dfn::dfn() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS dfn::dfn(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS dfn::dfn(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS dfn::dfn(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS dfn::dfn(const STDNS string& text, 
		 const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS dfn::dfn(const HTMLAttributeList& attributes, 
		 const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS dfn::~dfn()
{}

// ============================================================
// Class samp
// ============================================================
CGICCNS samp::samp() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS samp::samp(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS samp::samp(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS samp::samp(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS samp::samp(const STDNS string& text, 
		   const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS samp::samp(const HTMLAttributeList& attributes, 
		   const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS samp::~samp()
{}

// ============================================================
// Class code
// ============================================================
CGICCNS code::code() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS code::code(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS code::code(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS code::code(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS code::code(const STDNS string& text, 
		   const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS code::code(const HTMLAttributeList& attributes, 
		   const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS code::~code()
{}

// ============================================================
// Class kbd
// ============================================================
CGICCNS kbd::kbd() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS kbd::kbd(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS kbd::kbd(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS kbd::kbd(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS kbd::kbd(const STDNS string& text, 
		 const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS kbd::kbd(const HTMLAttributeList& attributes, 
		 const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS kbd::~kbd()
{}

// ============================================================
// Class var
// ============================================================
CGICCNS var::var() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS var::var(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS var::var(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS var::var(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS var::var(const STDNS string& text, 
		 const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS var::var(const HTMLAttributeList& attributes, 
		 const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS var::~var()
{}

// ============================================================
// Class cite
// ============================================================
CGICCNS cite::cite() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS cite::cite(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS cite::cite(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS cite::cite(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS cite::cite(const STDNS string& text, 
		   const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS cite::cite(const HTMLAttributeList& attributes, 
		   const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS cite::~cite()
{}

// ============================================================
// Class abbr
// ============================================================
CGICCNS abbr::abbr() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS abbr::abbr(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS abbr::abbr(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS abbr::abbr(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS abbr::abbr(const STDNS string& text, 
		   const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS abbr::abbr(const HTMLAttributeList& attributes, 
		   const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS abbr::~abbr()
{}

// ============================================================
// Class acronym
// ============================================================
CGICCNS acronym::acronym() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS acronym::acronym(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS acronym::acronym(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS acronym::acronym(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS acronym::acronym(const STDNS string& text, 
			 const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS acronym::acronym(const HTMLAttributeList& attributes, 
			 const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS acronym::~acronym()
{}

// ============================================================
// Class blockquote
// ============================================================
CGICCNS blockquote::blockquote() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS blockquote::blockquote(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS blockquote::blockquote(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS blockquote::blockquote(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS blockquote::blockquote(const STDNS string& text, 
			       const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS blockquote::blockquote(const HTMLAttributeList& attributes, 
			       const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS blockquote::~blockquote()
{}

// ============================================================
// Class q
// ============================================================
CGICCNS q::q() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS q::q(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS q::q(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS q::q(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS q::q(const STDNS string& text, 
	     const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS q::q(const HTMLAttributeList& attributes, 
	     const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS q::~q()
{}

// ============================================================
// Class sub
// ============================================================
CGICCNS sub::sub() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS sub::sub(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS sub::sub(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS sub::sub(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS sub::sub(const STDNS string& text, 
		 const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS sub::sub(const HTMLAttributeList& attributes, 
		 const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS sub::~sub()
{}

// ============================================================
// Class sup
// ============================================================
CGICCNS sup::sup() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS sup::sup(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS sup::sup(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS sup::sup(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS sup::sup(const STDNS string& text, 
		 const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS sup::sup(const HTMLAttributeList& attributes, 
		 const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS sup::~sup()
{}

// ============================================================
// Class p
// ============================================================
CGICCNS p::p() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS p::p(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS p::p(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS p::p(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS p::p(const STDNS string& text, 
	     const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS p::p(const HTMLAttributeList& attributes, 
	     const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS p::~p()
{}

// ============================================================
// Class br
// ============================================================
CGICCNS br::br() 
{}

CGICCNS br::br(const HTMLAttributeList& attributes) 
  : HTMLElement(&attributes)
{}

CGICCNS br::~br() 
{}

// ============================================================
// Class pre
// ============================================================
CGICCNS pre::pre() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS pre::pre(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS pre::pre(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS pre::pre(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS pre::pre(const STDNS string& text, 
		 const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS pre::pre(const HTMLAttributeList& attributes, 
		 const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS pre::~pre()
{}

// ============================================================
// Class ins
// ============================================================
CGICCNS ins::ins() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS ins::ins(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS ins::ins(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS ins::ins(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS ins::ins(const STDNS string& text, 
		 const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS ins::ins(const HTMLAttributeList& attributes, 
		 const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS ins::~ins()
{}

// ============================================================
// Class del
// ============================================================
CGICCNS del::del() 
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS del::del(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS del::del(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS del::del(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS del::del(const STDNS string& text, 
		 const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS del::del(const HTMLAttributeList& attributes, 
		 const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS del::~del()
{}
