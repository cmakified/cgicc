## $Id: Makefile.am,v 1.37 2004/06/22 01:38:08 sbooth Exp $

AUTOMAKE_OPTIONS = check-news dist-bzip2

if DEMOS
DEMO = demo contrib
else
DEMO =
endif

SUBDIRS = cgicc doc support $(DEMO)

CLEANFILES = *~

MAINTAINERCLEANFILES = aclocal.m4 cgicc-*.tar.*

EXTRA_DIST = BUGS README.WIN COPYING.DOC example win

dist-hook:
	cd $(distdir)/example && (make distclean || exit 0)
	rm -rf $(distdir)/example/CVS
	rm -f $(distdir)/example/autogen
	rm -rf $(distdir)/win/CVS

## Tag sources before making distribution, but don't make a
## distribution if checks fail.
CVS = cvs
cvs-dist: distcheck
	cd $(srcdir) && \
	 $(CVS) -q tag `echo "release-$(VERSION)" | sed 's/\./-/g'`
	$(MAKE) dist

## Generate detached signature files
GPG = gpg -ba
gpg-dist:
	for file in $(DIST_ARCHIVES); do \
		echo " $(GPG) $$file"; \
		$(GPG) $$file; \
	done

## Generate md5 checksum files
MD5 = md5sum
md5-dist:
	for file in $(DIST_ARCHIVES); do \
		echo " $(MD5) $$file > $$file.md5"; \
		$(MD5) $$file > $$file.md5; \
	done