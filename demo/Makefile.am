## $Id: Makefile.am,v 1.12 2004/06/28 06:40:09 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = styles.h test.html cookie.html

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
