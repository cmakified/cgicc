## $Id: Makefile.am,v 1.32 2002/03/09 18:37:29 sbooth Exp $

AUTOMAKE_OPTIONS = check-news dist-zip dist-bzip2

if DEMOS
DEMO = demo contrib
else
DEMO =
endif

SUBDIRS = cgicc doc support $(DEMO)

CLEANFILES = *~

MAINTAINERCLEANFILES = config.guess config.sub aclocal.m4	\
	cgicc-*.tar.gz cgicc-*.diff

EXTRA_DIST = README.WIN COPYING.DOC example win

dist-hook:
	rm -rf `find $(distdir)/example -name CVS`
	rm -rf `find $(distdir)/win -name CVS`

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
