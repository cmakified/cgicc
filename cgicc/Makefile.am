## $Id: Makefile.am,v 1.7 1999/08/17 18:10:39 sbooth Exp $

CLEANFILES = *~

INCLUDES = -I$(top_srcdir) -I$(top_builddir)

lib_LTLIBRARIES = libcgicc.la
libcgicc_la_SOURCES = CgiEnvironment.cpp CgiUtils.cpp Cgicc.cpp	\
FormEntry.cpp FormFile.cpp HTMLAttributes.cpp HTMLElements.cpp	\
HTTPHeaders.cpp MStreamable.cpp
libcgicc_la_LDFLAGS = -version-info 1:0:0

pkginclude_HEADERS = CgiDefs.h CgiEnvironment.h CgiUtils.h Cgicc.h	\
FormEntry.h FormFile.h HTMLAttributes.h HTMLClasses.h HTMLElements.h	\
HTMLGeneric.h HTTPHeaders.h MStreamable.h
