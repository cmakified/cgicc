# $Id: Makefile.am,v 1.1 1998/12/10 02:06:27 sbooth Exp $

CLEANFILES = *~

bin_PROGRAMS = test.cgi dns.cgi

test_cgi_SOURCES = test.cc
test_cgi_LDADD = ../src/libCgicc.la -lstdc++

dns_cgi_SOURCES = dns.cc
dns_cgi_LDADD = ../src/libCgicc.la @LIB_NET@
