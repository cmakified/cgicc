## $Id: Makefile.am,v 1.3 2002/03/17 20:56:37 sbooth Exp $

CLEANFILES = *~

EXTRA_DIST = FCgiIO.h

noinst_PROGRAMS = nph-hello.cgi nph-login.cgi fcgi-test.cgi

INCLUDES = -I$(top_srcdir) -I$(top_builddir)

nph_hello_cgi_SOURCES = nph-hello.cpp
nph_hello_cgi_LDADD = ../cgicc/libcgicc.la

nph_login_cgi_SOURCES = nph-login.cpp
nph_login_cgi_LDADD = ../cgicc/libcgicc.la

fcgi_test_cgi_SOURCES = fcgi-test.cpp FCgiIO.cpp
fcgi_test_cgi_LDADD = ../cgicc/libcgicc.la @FCGI_LIBS@
