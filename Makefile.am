# $Id: Makefile.am,v 1.5 1999/01/05 22:51:02 sbooth Exp $

if TESTS
TEST = test
else
TEST =
endif

if DOCS
DOC = doc
else
DOC =
endif

SUBDIRS = src $(TEST) $(DOC) example

CLEANFILES = *~

dist-hook:
	cp -p test/test.cc $(top_distdir)/doc
	cp -p test/dns.cc $(top_distdir)/doc
