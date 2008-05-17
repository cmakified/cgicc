## $Id: Makefile.am,v 1.40 2008/05/17 09:09:06 sebdiaz Exp $

AUTOMAKE_OPTIONS = check-news dist-bzip2

if DEMOS
DEMO = demo contrib
else
DEMO =
endif

ACLOCAL_AMFLAGS= -I m4 --install

SUBDIRS = cgicc doc support $(DEMO)

CLEANFILES = *~

MAINTAINERCLEANFILES = aclocal.m4 cgicc-*.tar.*

EXTRA_DIST = BUGS README.WIN COPYING.DOC example win

dist-hook:
	cd $(distdir)/example && (make distclean || exit 0)
	rm -rf $(distdir)/example/CVS
	rm -f $(distdir)/example/autogen
	rm -rf $(distdir)/win/CVS

install-data-hook:
	$(INSTALL_DATA) example/cgicc.m4 /usr/share/aclocal

## Tag sources before making distribution, but don't make a
## distribution if checks fail.
CVS = cvs
cvs-dist: distcheck
	cd $(srcdir) && \
	 $(CVS) -q tag `echo "release-$(VERSION)" | sed 's/\./-/g'`
	$(MAKE) dist

## Generate detached signature files (binary and ascii-armored)
## as well as directive files for GNU server ftp upload
GPG = gpg
gpg-dist:
	for file in $(DIST_ARCHIVES); do \
		$(GPG) -b $$file; \
		$(GPG) -ba $$file; \
		echo "directory: cgicc" > $$file.directive; \
		$(GPG) --clearsign $$file.directive
	done

## Generate md5 checksum files
MD5 = md5sum
md5-dist:
	for file in $(DIST_ARCHIVES); do \
		$(MD5) $$file > $$file.md5; \
	done

## Upload triplet files to GNU ftp server
FTP = ftp
FTP_URL = ftp://ftp-upload.gnu.org/incoming/ftp
ftp-release: gpg-dist
	for file in $(DIST_ARCHIVES); do \
		$(FTP) -a -u $(FTP_URL) $$file $$file.sig $$file.directive.asc
	done
