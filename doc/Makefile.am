## $Id: Makefile.am,v 1.7 2001/09/02 20:02:58 sbooth Exp $

CLEANFILES = *~

DOXYFILE = Doxyfile

TEMPLATES = index.tmpl cgi-overview.tmpl tutorial.tmpl lib-overview.tmpl \
	COPYING COPYING.LIB COPYING.DOC

EXTRA_DIST = header.html footer.html $(TEMPLATES)

IMAGES = images/cgicc-logo.jpg
SEDCMD1 = s!<title></title>!<title>GNU cgicc $(VERSION)</title>!g 
SEDCMD2 = s/$$(VERSION)/$(VERSION)/g

dist-hook:
	test -d $(distdir)/html || mkdir $(distdir)/html || exit 1
	@for file in html/*; do \
		cp -p $(srcdir)/$$file $(distdir)/html; \
	done

all: html

distclean-local:
	rm -rf html

html: $(DOXYFILE) $(EXTRA_DIST) $(srcdir)/../cgicc/*.h $(srcdir)/../demo/*.cpp
	DATE=`date '+%-d %b %Y'` VERSION=$(VERSION) $(DOXYGEN) $(DOXYFILE)
	cp $(IMAGES) html
	mv html/index.html html/index.html.bak
	sed -e '$(SEDCMD1)' -e '$(SEDCMD2)' html/index.html.bak > html/index.html
	rm -f html/index.html.bak
