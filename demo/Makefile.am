## $Id: Makefile.am,v 1.4 1999/06/04 17:24:06 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = testform.html

noinst_PROGRAMS = test.cgi dns.cgi 

INCLUDES = -I$(top_srcdir)

test_cgi_SOURCES = test.cc
test_cgi_LDADD = ../cgicc/libcgicc.la

dns_cgi_SOURCES = dns.cc
dns_cgi_LDADD = ../cgicc/libcgicc.la @LIB_NET@
