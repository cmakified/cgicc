## $Id: Makefile.am,v 1.5 1999/08/07 00:16:34 sbooth Exp $

CLEANFILES = *~

INCLUDES = -I$(top_srcdir)

lib_LTLIBRARIES = libcgicc.la
libcgicc_la_SOURCES = CgiEnvironment.cc CgiUtils.cc Cgicc.cc	\
FormEntry.cc FormFile.cc HTMLAttributes.cc HTMLElements.cc	\
HTTPHeaders.cc MStreamable.cc
libcgicc_la_LDFLAGS = -version-info 1:0:0

pkginclude_HEADERS = CgiDefs.hh CgiEnvironment.hh CgiUtils.hh Cgicc.hh	\
FormEntry.hh FormFile.hh HTMLAttributes.hh HTMLClasses.hh		\
HTMLElements.hh HTMLGeneric.hh HTTPHeaders.hh MStreamable.hh config.h
