## $Id: Makefile.am,v 1.3 2000/11/15 06:34:12 sbooth Exp $

CLEANFILES = *~

cgicc_libdir=@cgicc_libdir@
cgicc_includedir=@cgicc_includedir@

bin_PROGRAMS = example.cgi

INCLUDES = -I$(cgicc_includedir)

example_cgi_SOURCES = example.cpp
example_cgi_LDADD = $(cgicc_libdir)/libcgicc.la
