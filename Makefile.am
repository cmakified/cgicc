## $Id: Makefile.am,v 1.13 1999/06/02 22:08:36 sbooth Exp $

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

if MAINTAINER_MODE
################################################################
##
## Everything past here is useful to the maintainer, but probably not
## to anybody else (taken from libtool/Makefile.am).
##

## set it to `:' to avoid CVS operations
CVS = cvs

## Tag sources before making distribution, but don't make a
## distribution if checks fail.  Also, make sure the NEWS file is
## up-to-date.
cvs-dist: distcheck
	@if sed '1,9d;10q' $(srcdir)/NEWS | grep -e "$(VERSION)" > /dev/null; \
	then :; else \
	  echo "NEWS not updated; not releasing" 1>&2; \
	  exit 1;				\
	fi
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
