## $Id: Makefile.am,v 1.5 1999/08/09 18:21:53 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = testform.html

noinst_PROGRAMS = test.cgi dns.cgi 

INCLUDES = -I$(top_srcdir)

test_cgi_SOURCES = test.cpp
test_cgi_LDADD = ../cgicc/libcgicc.la

dns_cgi_SOURCES = dns.cpp
dns_cgi_LDADD = ../cgicc/libcgicc.la @LIB_NET@
