## $Id: Makefile.am,v 1.2 2001/09/05 02:25:47 sbooth Exp $

CLEANFILES = *~

noinst_PROGRAMS = nph-hello.cgi nph-login.cgi

INCLUDES = -I$(top_srcdir) -I$(top_builddir)

nph_hello_cgi_SOURCES = nph-hello.cpp
nph_hello_cgi_LDADD = ../cgicc/libcgicc.la

nph_login_cgi_SOURCES = nph-login.cpp
nph_login_cgi_LDADD = ../cgicc/libcgicc.la
