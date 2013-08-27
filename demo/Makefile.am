## $Id: Makefile.am,v 1.14 2007/07/08 20:06:58 sebdiaz Exp $

CLEANFILES = *~

EXTRA_DIST = styles.h

noinst_PROGRAMS = test.cgi dns.cgi upload.cgi cookie.cgi cardgame.cgi

INCLUDES = -I$(top_srcdir) -I$(top_builddir)

test_cgi_SOURCES = test.cpp
test_cgi_LDADD = ../cgicc/libcgicc.la @DEMO_LIBS@

dns_cgi_SOURCES = dns.cpp
dns_cgi_LDADD = ../cgicc/libcgicc.la @DEMO_LIBS@ @LIB_NET@

upload_cgi_SOURCES = upload.cpp
upload_cgi_LDADD = ../cgicc/libcgicc.la @DEMO_LIBS@

cookie_cgi_SOURCES = cookie.cpp
cookie_cgi_LDADD = ../cgicc/libcgicc.la @DEMO_LIBS@

cardgame_cgi_SOURCES = cardgame.cpp
cardgame_cgi_LDADD = ../cgicc/libcgicc.la @DEMO_LIBS@
