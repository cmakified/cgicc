# $Id: Makefile.am,v 1.6 1999/01/05 23:29:14 sbooth Exp $

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
	test -d $(distdir)/example || mkdir $(distdir)/example
	cp -p example/Makefile.in $(top_distdir)/example
	cp -p example/yourSource.cc $(top_distdir)/example