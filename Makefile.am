## $Id: Makefile.am,v 1.17 1999/08/09 18:36:43 sbooth Exp $

AUTOMAKE_OPTIONS = check-news dist-zip

if DEMOS
DEMO = demo
else
DEMO =
endif

SUBDIRS = cgicc info $(DEMO)

CLEANFILES = *~

EXTRA_DIST = acconfig.h

dist-hook:
	test -d $(distdir)/example || mkdir $(distdir)/example || exit 1
	cp -p $(srcdir)/example/README $(distdir)/example
	cp -p $(srcdir)/example/Makefile.in $(distdir)/example
	cp -p $(srcdir)/example/yourSource.cpp $(distdir)/example
	test -d $(distdir)/support || mkdir $(distdir)/support || exit 1
	cp -p $(srcdir)/support/config.guess $(distdir)/support
	cp -p $(srcdir)/support/config.sub $(distdir)/support
	cp -p $(srcdir)/support/install-sh $(distdir)/support
	cp -p $(srcdir)/support/ltconfig $(distdir)/support
	cp -p $(srcdir)/support/ltmain.sh $(distdir)/support
	cp -p $(srcdir)/support/mdate-sh $(distdir)/support
	cp -p $(srcdir)/support/missing $(distdir)/support
	cp -p $(srcdir)/support/mkinstalldirs $(distdir)/support

if MAINTAINER_MODE
################################################################
##
## Everything past here is useful to the maintainer, but probably not
## to anybody else (taken from libtool/Makefile.am).
##

## set it to `:' to avoid CVS operations
CVS = cvs

## Tag sources before making distribution, but don't make a
## distribution if checks fail.
cvs-dist: distcheck
	cd $(srcdir) && \
	 $(CVS) -q tag `echo "release-$(VERSION)" | sed 's/\./-/g'`
	$(MAKE) dist

## Generate a context diff file containing the patch info for the
## current version.
cvs-diff:
	thisver=`echo "release-$(VERSION)" | sed 's/\./-/g'`; \
	if test -z "$$OLDVERSION"; then \
	  prevno=`echo "$(VERSION)" - 0.01 | bc | sed 's/^\./0./'`; \
	else prevno="$$OLDVERSION"; fi; \
	prevver=release-`echo $$prevno | sed 's/\./-/g'`; \
	$(CVS) -f rdiff -c -r $$prevver -r $$thisver $(PACKAGE) \
	    > $(PACKAGE)-$$prevno-$(VERSION).diff
endif
