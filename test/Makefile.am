# $Id: Makefile.am,v 1.4 1998/12/19 01:53:26 sbooth Exp $

CLEANFILES = *~
DISTCLEANFILES = .deps/*

bin_PROGRAMS = test.cgi dns.cgi

test_cgi_SOURCES = test.cc
test_cgi_LDADD = ../src/libCgicc.la
test_cgi_INCLUDES = ../src

dns_cgi_SOURCES = dns.cc
dns_cgi_LDADD = ../src/libCgicc.la @LIB_NET@
dns_cgi_INCLUDES = ../src
