## $Id: Makefile.am,v 1.15 2001/09/05 02:06:55 sbooth Exp $

CLEANFILES = *~

INCLUDES = -I$(top_srcdir) -I$(top_builddir)

lib_LTLIBRARIES = libcgicc.la
libcgicc_la_SOURCES = CgiEnvironment.cpp CgiUtils.cpp Cgicc.cpp		\
FormEntry.cpp FormFile.cpp HTMLAttribute.cpp HTMLAttributeList.cpp	\
HTMLDoctype.cpp HTMLElement.cpp HTMLElementList.cpp			\
HTTPContentHeader.cpp HTTPCookie.cpp HTTPHTMLHeader.cpp HTTPHeader.cpp	\
HTTPPlainHeader.cpp HTTPRedirectHeader.cpp HTTPResponseHeader.cpp	\
HTTPStatusHeader.cpp MStreamable.cpp
libcgicc_la_LDFLAGS = -version-info 3:0:2

pkginclude_HEADERS = CgiDefs.h CgiEnvironment.h CgiUtils.h Cgicc.h	\
FormEntry.h FormFile.h HTMLAtomicElement.h HTMLAttribute.h		\
HTMLAttributeList.h HTMLBooleanElement.h HTMLClasses.h HTMLDoctype.h	\
HTMLElement.h HTMLElementList.h HTTPContentHeader.h HTTPCookie.h	\
HTTPHTMLHeader.h HTTPHeader.h HTTPHeaders.h HTTPPlainHeader.h		\
HTTPRedirectHeader.h HTTPResponseHeader.h HTTPStatusHeader.h		\
MStreamable.h
