# $Id: Makefile.am,v 1.1 1998/12/10 03:06:42 sbooth Exp $

SUBDIRS = src test doc

CLEANFILES = *~

dist-hook:
	cp -p test/test.cc $(top_distdir)/doc
	cp -p test/dns.cc $(top_distdir)/doc
