# $Id: Makefile.am,v 1.4 1998/12/11 01:48:40 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = cgicc.css testform.html lmi-logo.gif

DOC_TEMP = __doc_temp

dist-hook:
	doc++ -H -j -B ./footer.inc -d $(distdir) ./cgicc.dxx > /dev/null 2>&1

install-data-local:
	@if test -f "./cgicc.dxx"; then \
		$(mkinstalldirs) @prefix@/doc; \
		rm -rf $(DOC_TEMP); \
		mkdir $(DOC_TEMP); \
		chmod 777 $(DOC_TEMP); \
		echo " doc++ -H -j -B ./footer.inc -d $(DOC_TEMP) ./cgicc.dxx > /dev/null 2>&1;"; \
		doc++ -H -j -B ./footer.inc -d $(DOC_TEMP) ./cgicc.dxx \
		 > /dev/null 2>&1; \
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
		$(mkinstalldirs) @prefix@/doc; \
		for file in *.html *.gif *.cc cgicc.css; do \
		 echo " $(INSTALL_DATA) $$file @prefix@/doc/$$file"; \
		 $(INSTALL_DATA) $$file @prefix@/doc/$$file; \
		done \
	fi
