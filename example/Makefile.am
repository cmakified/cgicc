## $Id: Makefile.am,v 1.4 2000/11/15 21:54:17 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = cgicc.m4

cgicc_libdir=@cgicc_libdir@
cgicc_includedir=@cgicc_includedir@

bin_PROGRAMS = example.cgi

INCLUDES = -I$(cgicc_includedir)

example_cgi_SOURCES = example.cpp
example_cgi_LDADD = $(cgicc_libdir)/libcgicc.la
