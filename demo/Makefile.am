## $Id: Makefile.am,v 1.10 2002/01/19 17:20:58 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = test.html upload.html cookie.html cgicc.css

noinst_PROGRAMS = test.cgi dns.cgi upload.cgi cookie.cgi

INCLUDES = -I$(top_srcdir) -I$(top_builddir)

test_cgi_SOURCES = test.cpp
test_cgi_LDADD = ../cgicc/libcgicc.la

dns_cgi_SOURCES = dns.cpp
dns_cgi_LDADD = ../cgicc/libcgicc.la @LIB_NET@

upload_cgi_SOURCES = upload.cpp
upload_cgi_LDADD = ../cgicc/libcgicc.la

cookie_cgi_SOURCES = cookie.cpp
cookie_cgi_LDADD = ../cgicc/libcgicc.la
