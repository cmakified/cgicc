## $Id: Makefile.am,v 1.6 1999/08/17 18:33:04 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = testform.html

noinst_PROGRAMS = test.cgi dns.cgi 

INCLUDES = -I$(top_srcdir) -I$(top_builddir)

test_cgi_SOURCES = test.cpp
test_cgi_LDADD = ../cgicc/libcgicc.la

dns_cgi_SOURCES = dns.cpp
dns_cgi_LDADD = ../cgicc/libcgicc.la @LIB_NET@
