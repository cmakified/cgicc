# $Id: Makefile.am,v 1.5 1998/12/11 18:06:25 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = cgicc.css testform.html lmi-logo.gif

DOC_TEMP = __doc_temp

dist-hook:
	-sed -e s/\@VERSION\@/@VERSION@/g < cgicc.dxx.in > cgicc.dxx
	-doc++ -H -j -B footer.inc -d $(distdir) cgicc.dxx > /dev/null 2>&1
	-rm -f cgicc.dxx

install-data-local:
	$(mkinstalldirs) @prefix@/doc
	@if test -f "cgicc.dxx.in"; then \
		sed -e s/\@VERSION\@/@VERSION@/g < cgicc.dxx.in > cgicc.dxx; \
		rm -rf $(DOC_TEMP); \
		mkdir $(DOC_TEMP); \
		chmod 777 $(DOC_TEMP); \
		doc++ -H -j -B footer.inc -d $(DOC_TEMP) cgicc.dxx \
		 > /dev/null 2>&1; \
		rm -f cgicc.dxx; \
		cd $(DOC_TEMP); \
		for file in *; do \
		 echo " $(INSTALL_DATA) $$file @prefix@/doc/$$file"; \
		 $(INSTALL_DATA) $$file @prefix@/doc/$$file; \
		done; \
		cd ..; \
		rm -rf $(DOC_TEMP); \
		list='$(EXTRA_DIST)'; for file in $$list; do \
		 echo " $(INSTALL_DATA) $$file @prefix@/doc/$$file"; \
		 $(INSTALL_DATA) $$file @prefix@/doc/$$file; \
		done \
	else \
		for file in *.html *.gif *.cc cgicc.css; do \
		 echo " $(INSTALL_DATA) $$file @prefix@/doc/$$file"; \
		 $(INSTALL_DATA) $$file @prefix@/doc/$$file; \
		done \
	fi
