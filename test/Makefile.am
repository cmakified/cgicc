# $Id: Makefile.am,v 1.5 1999/01/06 22:19:46 sbooth Exp $

CLEANFILES = *~

bin_PROGRAMS = test.cgi dns.cgi

test_cgi_SOURCES = test.cc
test_cgi_LDADD = ../src/libCgicc.la
test_cgi_INCLUDES = ../src

dns_cgi_SOURCES = dns.cc
dns_cgi_LDADD = ../src/libCgicc.la @LIB_NET@
dns_cgi_INCLUDES = ../src
