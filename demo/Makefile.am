## $Id: Makefile.am,v 1.2 1999/05/05 18:31:05 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = testform.html

noinst_PROGRAMS = test.cgi dns.cgi

INCLUDES = -I$(top_srcdir)/src

test_cgi_SOURCES = test.cc
test_cgi_LDADD = ../src/libcgicc.la

dns_cgi_SOURCES = dns.cc
dns_cgi_LDADD = ../src/libcgicc.la @LIB_NET@
