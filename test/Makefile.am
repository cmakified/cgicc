## $Id: Makefile.am,v 1.6 1999/04/26 22:49:37 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = testform.html

bin_PROGRAMS = test.cgi dns.cgi

INCLUDES = -I$(top_srcdir)/src

test_cgi_SOURCES = test.cc
test_cgi_LDADD = ../src/libcgicc.la

dns_cgi_SOURCES = dns.cc
dns_cgi_LDADD = ../src/libcgicc.la @LIB_NET@
