/* $Id: HTMLText.cc,v 1.1 1998/02/12 05:31:41 sbooth Exp $ */

#include "HTMLText.hh"

// ============================================================
// Statics
// ============================================================
bool em::sState = false;
bool strong::sState = false;
bool dfn::sState = false;
bool samp::sState = false;
bool code::sState = false;
bool kbd::sState = false;
bool var::sState = false;
bool cite::sState = false;
bool abbr::sState = false;
bool acronym::sState = false;
bool blockquote::sState = false;
bool q::sState = false;
bool sub::sState = false;
bool sup::sState = false;
bool p::sState = false;
bool pre::sState = false;
bool ins::sState = false;
bool del::sState = false;

// ============================================================
// Class em
// ============================================================
em::em(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

em::em(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

em::em(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

em::em(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

em::em(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

em::~em()
{}

// ============================================================
// Class strong
// ============================================================
strong::strong(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

strong::strong(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

strong::strong(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

strong::strong(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

strong::strong(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

strong::~strong()
{}

// ============================================================
// Class dfn
// ============================================================
dfn::dfn(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

dfn::dfn(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

dfn::dfn(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

dfn::dfn(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

dfn::dfn(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

dfn::~dfn()
{}

// ============================================================
// Class samp
// ============================================================
samp::samp(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

samp::samp(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

samp::samp(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

samp::samp(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

samp::samp(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

samp::~samp()
{}

// ============================================================
// Class code
// ============================================================
code::code(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

code::code(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

code::code(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

code::code(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

code::code(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

code::~code()
{}

// ============================================================
// Class kbd
// ============================================================
kbd::kbd(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

kbd::kbd(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

kbd::kbd(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

kbd::kbd(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

kbd::kbd(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

kbd::~kbd()
{}

// ============================================================
// Class var
// ============================================================
var::var(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

var::var(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

var::var(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

var::var(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

var::var(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

var::~var()
{}

// ============================================================
// Class cite
// ============================================================
cite::cite(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

cite::cite(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

cite::cite(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

cite::cite(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

cite::cite(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

cite::~cite()
{}

// ============================================================
// Class abbr
// ============================================================
abbr::abbr(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

abbr::abbr(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

abbr::abbr(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

abbr::abbr(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

abbr::abbr(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

abbr::~abbr()
{}

// ============================================================
// Class acronym
// ============================================================
acronym::acronym(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

acronym::acronym(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

acronym::acronym(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

acronym::acronym(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

acronym::acronym(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

acronym::~acronym()
{}

// ============================================================
// Class blockquote
// ============================================================
blockquote::blockquote(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

blockquote::blockquote(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

blockquote::blockquote(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

blockquote::blockquote(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

blockquote::blockquote(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

blockquote::~blockquote()
{}

// ============================================================
// Class q
// ============================================================
q::q(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

q::q(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

q::q(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

q::q(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

q::q(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

q::~q()
{}

// ============================================================
// Class sub
// ============================================================
sub::sub(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

sub::sub(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

sub::sub(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

sub::sub(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

sub::sub(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

sub::~sub()
{}

// ============================================================
// Class sup
// ============================================================
sup::sup(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

sup::sup(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

sup::sup(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

sup::sup(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

sup::sup(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

sup::~sup()
{}

// ============================================================
// Class p
// ============================================================
p::p(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

p::p(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

p::p(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

p::p(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

p::p(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

p::~p()
{}

// ============================================================
// Class br
// ============================================================
br::br() 
{}

br::br(const HTMLAttributeList& attributes) 
	: HTMLElement(&attributes)
{}

br::~br() 
{}

// ============================================================
// Class pre
// ============================================================
pre::pre(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

pre::pre(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

pre::pre(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

pre::pre(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

pre::pre(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

pre::~pre()
{}

// ============================================================
// Class ins
// ============================================================
ins::ins(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

ins::ins(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

ins::ins(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

ins::ins(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

ins::ins(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

ins::~ins()
{}

// ============================================================
// Class del
// ============================================================
del::del(const char *text) 
	: HTMLBooleanElement(text, NULL, NULL)
{}

del::del(const HTMLAttributeList& attributes)
	: HTMLBooleanElement(NULL, &attributes, NULL)
{}

del::del(const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, NULL, &embed)
{}

del::del(const char *text, const HTMLAttributeList& attributes) 
	: HTMLBooleanElement(text, &attributes, NULL)
{}

del::del(const HTMLAttributeList& attributes, const HTMLSimpleElement& embed)
	: HTMLBooleanElement(NULL, &attributes, &embed)
{}

del::~del()
{}
