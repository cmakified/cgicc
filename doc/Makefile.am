## $Id: Makefile.am,v 1.11 2002/01/09 17:13:12 sbooth Exp $

CLEANFILES = *~

DOXYFILE = Doxyfile

docdir = $(prefix)/doc/$(PACKAGE)-$(VERSION)

TEMPLATES = index.tmpl license.tmpl lists.tmpl bugs.tmpl demos.tmpl	\
cgi-overview.tmpl tutorial.tmpl lib-overview.tmpl COPYING COPYING.LIB	\
COPYING.DOC

EXTRA_DIST = cgicc.css header.html footer.html $(TEMPLATES)

IMAGES = images/cgicc-logo.jpg
SEDCMD1 = s!<title></title>!<title>GNU cgicc $(VERSION)</title>!g 
SEDCMD2 = s/$$(VERSION)/$(VERSION)/g

dist-hook:
	test -d $(distdir)/html || mkdir $(distdir)/html || exit 1
	@for file in html/*; do \
		cp -p $(srcdir)/$$file $(distdir)/html; \
	done

all: html

install-data-local:
	$(mkinstalldirs) $(docdir)
	@for file in $(srcdir)/html/*; do \
		bn="`basename $$file`"; \
		echo " $(INSTALL_DATA) $$file $(docdir)/$$bn"; \
	 	$(INSTALL_DATA) $$file $(docdir)/$$bn; \
	done

uninstall-local:
	@for file in $(srcdir)/html/*; do \
		bn="`basename $$file`"; \
		echo " rm -f $(docdir)/$$bn"; \
		rm -f $(docdir)/$$bn; \
	done


distclean-local:
	rm -rf html

if MAINTAINER_MODE
################################################################
##
## Everything past here is useful to the maintainer, but probably not
## to anybody else (taken from libtool/Makefile.am).
##
html: $(DOXYFILE) $(EXTRA_DIST) $(srcdir)/../cgicc/*.h $(srcdir)/../demo/*.cpp
	DATE=`date '+%-d %b %Y'` VERSION=$(VERSION) $(DOXYGEN) $(DOXYFILE)
	cp $(IMAGES) html
	cp ./cgicc.css html
	mv html/index.html html/index.html.bak
	sed -e '$(SEDCMD1)' -e '$(SEDCMD2)' html/index.html.bak > html/index.html
	rm -f html/index.html.bak
endif
