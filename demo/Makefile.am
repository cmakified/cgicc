## $Id: Makefile.am,v 1.11 2002/02/05 23:44:26 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = test.html upload.html cookie.html cgicc.css

noinst_PROGRAMS = test.cgi dns.cgi upload.cgi cookie.cgi

INCLUDES = -I$(top_srcdir) -I$(top_builddir)

test_cgi_SOURCES = test.cpp
test_cgi_LDADD = ../cgicc/libcgicc.la @DEMO_LIBS@

dns_cgi_SOURCES = dns.cpp
dns_cgi_LDADD = ../cgicc/libcgicc.la @DEMO_LIBS@ @LIB_NET@

upload_cgi_SOURCES = upload.cpp
upload_cgi_LDADD = ../cgicc/libcgicc.la @DEMO_LIBS@

cookie_cgi_SOURCES = cookie.cpp
cookie_cgi_LDADD = ../cgicc/libcgicc.la @DEMO_LIBS@
