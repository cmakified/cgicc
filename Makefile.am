# $Id: Makefile.am,v 1.4 1998/12/16 01:11:19 sbooth Exp $

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

SUBDIRS = src $(TEST) $(DOC)

CLEANFILES = *~

dist-hook:
	cp -p test/test.cc $(top_distdir)/doc
	cp -p test/dns.cc $(top_distdir)/doc
