# $Id: Makefile.am,v 1.3 1998/12/11 21:53:21 sbooth Exp $

CLEANFILES = *~

bin_PROGRAMS = test.cgi dns.cgi

test_cgi_SOURCES = test.cc
test_cgi_LDADD = ../src/libCgicc.la
test_cgi_INCLUDES = ../src

dns_cgi_SOURCES = dns.cc
dns_cgi_LDADD = ../src/libCgicc.la @LIB_NET@
dns_cgi_INCLUDES = ../src
