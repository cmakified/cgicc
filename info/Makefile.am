## $Id: Makefile.am,v 1.5 2000/11/07 06:00:05 sbooth Exp $

CLEANFILES = $(HTMLS) *~
MAINTAINERCLEANFILES = cgicc-doc-texi.tar.gz cgicc-doc-info.tar.gz	\
cgicc-doc-dvi.tar.gz cgicc-doc-html.tar.gz

info_TEXINFOS = cgicc.texinfo
cgicc_TEXINFOS = gpl.texinfo cgi-overview.texinfo tutorial.texinfo	\
library-overview.texinfo cgi-classes.texinfo http-classes.texinfo	\
html-classes.texinfo class-cgicc.texinfo class-cgienv.texinfo		\
class-formentry.texinfo class-formfile.texinfo classes-http.texinfo	\
classes-html.texinfo reporting-bugs.texinfo concept-index.texinfo	\
function-index.texinfo datatype-index.texinfo fdl.texinfo 		\
support.texinfo

##
## HTML documentation
##
HTMLS = cgicc.html
html: $(HTMLS)

##
## New rules to handle HTML file generation (texinfo-4.0 and up)
##
SUFFIXES = .html

.texi.html:
	cd $(srcdir) && $(MAKEINFO) --html $<

.texinfo.html:
	cd $(srcdir) && $(MAKEINFO) --html $<

if MAINTAINER_MODE
################################################################
##
## Everything past here is useful to the maintainer, but probably not
## to anybody else.
##

doc-gz: doc-texi-gz doc-info-gz doc-dvi-gz doc-html-gz

doc-texi-gz: 
	-rm -f cgicc-doc-texi.tar.gz
	GZIP=$(GZIP_ENV) $(TAR) chozf cgicc-doc-texi.tar.gz *.texi*

doc-info-gz: info
	-rm -f cgicc-doc-info.tar.gz
	GZIP=$(GZIP_ENV) $(TAR) chozf cgicc-doc-info.tar.gz *.info*

doc-dvi-gz: dvi
	-rm -f cgicc-doc-dvi.tar.gz
	GZIP=$(GZIP_ENV) $(TAR) chozf cgicc-doc-dvi.tar.gz $(DVIS)

doc-html-gz: html
	-rm -f cgicc-doc-html.tar.gz
	GZIP=$(GZIP_ENV) $(TAR) chozf cgicc-doc-html.tar.gz $(HTMLS)
endif
