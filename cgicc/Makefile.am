## $Id: Makefile.am,v 1.13 2001/09/03 16:16:10 sbooth Exp $

CLEANFILES = *~

INCLUDES = -I$(top_srcdir) -I$(top_builddir)

lib_LTLIBRARIES = libcgicc.la
libcgicc_la_SOURCES = CgiEnvironment.cpp CgiUtils.cpp Cgicc.cpp	\
FormEntry.cpp FormFile.cpp HTMLAttributes.cpp HTMLElements.cpp	\
HTTPCookie.cpp HTTPHeaders.cpp MStreamable.cpp
libcgicc_la_LDFLAGS = -version-info 3:0:2

pkginclude_HEADERS = CgiDefs.h CgiEnvironment.h CgiUtils.h Cgicc.h	\
FormEntry.h FormFile.h HTMLAttributes.h HTMLClasses.h HTMLElements.h	\
HTMLGeneric.h HTTPHeaders.h HTTPCookie.h MStreamable.h
