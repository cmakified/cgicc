## $Id: Makefile.am,v 1.2 2000/11/14 05:44:07 sbooth Exp $

CLEANFILES = *~

CGICC_LIBDIR=@CGICC_LIBDIR@
CGICC_INCLUDEDIR=@CGICC_INCLUDEDIR@

bin_PROGRAMS = example.cgi

INCLUDES = -I$(CGICC_INCLUDEDIR)

example_cgi_SOURCES = example.cpp
example_cgi_LDADD = $(CGICC_LIBDIR)/libcgicc.la
