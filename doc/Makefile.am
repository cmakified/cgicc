## $Id: Makefile.am,v 1.16 2003/07/17 05:14:39 sbooth Exp $

CLEANFILES = *~

DOXYFILE = Doxyfile

docdir = $(prefix)/doc/$(PACKAGE)-$(VERSION)

TEMPLATES = index.tmpl license.tmpl lists.tmpl bugs.tmpl demos.tmpl	\
cgi-overview.tmpl tutorial.tmpl lib-overview.tmpl COPYING COPYING.LIB	\
COPYING.DOC header.html footer.html cgicc-doc.css

EXTRA_DIST = html

IMAGES = cgicc.png
SEDCMD1 = s/$$title/GNU cgicc documentation version $(VERSION)/g
SEDCMD2 = s/$$(VERSION)/$(VERSION)/g

all: html

install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(docdir)
	@for file in $(srcdir)/html/*; do \
		bn="`basename $$file`"; \
		echo " $(INSTALL_DATA) $$file $(DESTDIR)$(docdir)/$$bn"; \
	 	$(INSTALL_DATA) $$file $(DESTDIR)$(docdir)/$$bn; \
	done

uninstall-local:
	@for file in $(srcdir)/html/*; do \
		bn="`basename $$file`"; \
		echo " rm -f $(DESTDIR)$(docdir)/$$bn"; \
		rm -f $(DESTDIR)$(docdir)/$$bn; \
	done

if MAINTAINER_MODE
################################################################
##
## Everything past here is useful to the maintainer, but probably not
## to anybody else (taken from libtool/Makefile.am).
##
html: $(DOXYFILE) $(TEMPLATES) $(srcdir)/../cgicc/*.h $(srcdir)/../demo/*.cpp
	DATE=`date '+%-d %b %Y'` VERSION=$(VERSION) $(DOXYGEN) $(DOXYFILE)
	cp $(IMAGES) html
	cp ./cgicc-doc.css html
	mv html/index.html html/index.html.bak
	sed -e '$(SEDCMD1)' -e '$(SEDCMD2)' html/index.html.bak > html/index.html
	rm -f html/index.html.bak
else
html:
	@if test ! -d html; then \
	echo "HTML documenation not present"; \
	fi
endif
