## $Id: Makefile.am,v 1.9 1999/04/26 22:41:54 sbooth Exp $

if DEMOS
DEMO = demo
else
DEMO =
endif

SUBDIRS = src info $(DEMO)

CLEANFILES = *~

EXTRA_DIST = acconfig.h

dist-hook:
	test -d $(distdir)/example || mkdir $(distdir)/example || exit 1
	cp -p $(srcdir)/example/README $(distdir)/example
	cp -p $(srcdir)/example/Makefile.in $(distdir)/example
	cp -p $(srcdir)/example/yourSource.cc $(distdir)/example
