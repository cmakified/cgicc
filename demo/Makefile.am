## $Id: Makefile.am,v 1.3 1999/06/03 23:07:02 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = testform.html

noinst_PROGRAMS = test.cgi dns.cgi 
##c_test.cgi

INCLUDES = -I$(top_srcdir)

test_cgi_SOURCES = test.cc
test_cgi_LDADD = ../cgicc/libcgicc.la

dns_cgi_SOURCES = dns.cc
dns_cgi_LDADD = ../cgicc/libcgicc.la @LIB_NET@

##c_test_cgi_SOURCES = c_test.c
##c_test_cgi_LDADD = ../cgicc/libcgicc.la
