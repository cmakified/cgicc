# $Id: Makefile.am,v 1.2 1998/12/11 01:41:29 sbooth Exp $

if TESTS
	TEST = test
else
	TEST =
endif

SUBDIRS = src $(TEST) doc

CLEANFILES = *~

dist-hook:
	cp -p test/test.cc $(top_distdir)/doc
	cp -p test/dns.cc $(top_distdir)/doc
