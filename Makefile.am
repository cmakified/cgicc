## $Id: Makefile.am,v 1.30 2002/01/09 17:16:41 sbooth Exp $

AUTOMAKE_OPTIONS = check-news dist-zip dist-bzip2

if DEMOS
DEMO = demo contrib
else
DEMO =
endif

if MAINTAINER_MODE
HTML = html
else
HTML =
endif

SUBDIRS = cgicc doc support $(HTML) $(DEMO)

DIST_SUBDIRS = cgicc doc support $(DEMO)

CLEANFILES = *~

MAINTAINERCLEANFILES = config.guess config.sub ltmain.sh aclocal.m4 \
	cgicc-*.tar.gz cgicc-*.diff

EXTRA_DIST = acconfig.h README.WIN COPYING.DOC

dist-hook:
	test -d $(distdir)/example || mkdir $(distdir)/example || exit 1
	cp -p $(srcdir)/example/AUTHORS $(distdir)/example
	cp -p $(srcdir)/example/COPYING $(distdir)/example
	cp -p $(srcdir)/example/ChangeLog $(distdir)/example
	cp -p $(srcdir)/example/INSTALL $(distdir)/example
	cp -p $(srcdir)/example/Makefile.am $(distdir)/example
	cp -p $(srcdir)/example/Makefile.in $(distdir)/example
	cp -p $(srcdir)/example/NEWS $(distdir)/example
	cp -p $(srcdir)/example/README $(distdir)/example
	cp -p $(srcdir)/example/acinclude.m4 $(distdir)/example
	cp -p $(srcdir)/example/aclocal.m4 $(distdir)/example
	cp -p $(srcdir)/example/autogen $(distdir)/example
	cp -p $(srcdir)/example/config.guess $(distdir)/example
	cp -p $(srcdir)/example/config.sub $(distdir)/example
	cp -p $(srcdir)/example/configure $(distdir)/example
	cp -p $(srcdir)/example/configure.ac $(distdir)/example
	cp -p $(srcdir)/example/example.cpp $(distdir)/example
	cp -p $(srcdir)/example/install-sh $(distdir)/example
	cp -p $(srcdir)/example/missing $(distdir)/example
	cp -p $(srcdir)/example/mkinstalldirs $(distdir)/example
	test -d $(distdir)/win || mkdir $(distdir)/win || exit 1
	cp -p $(srcdir)/win/cgicc.dsw $(distdir)/win
	cp -p $(srcdir)/win/cgicc.dsp $(distdir)/win
	cp -p $(srcdir)/win/test.dsp $(distdir)/win
	cp -p $(srcdir)/win/dns.dsp $(distdir)/win
	cp -p $(srcdir)/win/example.dsp $(distdir)/win

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
