# $Id: Makefile.am,v 1.2 1998/12/11 01:40:31 sbooth Exp $

CLEANFILES = *~

bin_PROGRAMS = test.cgi dns.cgi

test_cgi_SOURCES = test.cc
test_cgi_LDADD = ../src/libCgicc.la

dns_cgi_SOURCES = dns.cc
dns_cgi_LDADD = ../src/libCgicc.la @LIB_NET@
