## $Id: Makefile.am,v 1.1 2000/11/14 05:42:03 sbooth Exp $

CLEANFILES = *~

AUTOMAKE_OPTIONS = check-news

CGICC_LIBDIR=@CGICC_LIBDIR@
CGICC_INCLUDEDIR=@CGICC_INCLUDEDIR@

bin_PROGRAMS = example.cgi

INCLUDES = -I$(CGICC_INCLUDEDIR)

example_cgi_SOURCES = example.cpp
example_cgi_LDADD = $(CGICC_LIBDIR)/libcgicc.la
