## $Id: Makefile.am,v 1.7 2000/10/17 00:22:35 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = testform.html upload.html

noinst_PROGRAMS = test.cgi dns.cgi upload.cgi

INCLUDES = -I$(top_srcdir) -I$(top_builddir)

test_cgi_SOURCES = test.cpp
test_cgi_LDADD = ../cgicc/libcgicc.la

dns_cgi_SOURCES = dns.cpp
dns_cgi_LDADD = ../cgicc/libcgicc.la @LIB_NET@

upload_cgi_SOURCES = upload.cpp
upload_cgi_LDADD = ../cgicc/libcgicc.la
