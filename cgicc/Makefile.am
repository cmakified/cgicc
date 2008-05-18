## $Id: Makefile.am,v 1.25 2008/05/18 19:42:41 sebdiaz Exp $

CLEANFILES = *~

ACLOCAL_AMFLAGS= -I m4 -I .

INCLUDES = -I$(top_srcdir) -I$(top_builddir)

lib_LTLIBRARIES = libcgicc.la
libcgicc_la_SOURCES = CgiEnvironment.cpp CgiInput.cpp CgiUtils.cpp	\
Cgicc.cpp FormEntry.cpp FormFile.cpp HTMLAttribute.cpp			\
HTMLAttributeList.cpp HTMLDoctype.cpp HTMLElement.cpp			\
HTMLElementList.cpp HTTPContentHeader.cpp HTTPCookie.cpp		\
HTTPHTMLHeader.cpp HTTPHeader.cpp HTTPPlainHeader.cpp			\
HTTPRedirectHeader.cpp HTTPResponseHeader.cpp HTTPStatusHeader.cpp	\
MStreamable.cpp \
HTTPXHTMLHeader.cpp XHTMLDoctype.cpp XMLPI.cpp

libcgicc_la_LDFLAGS = -lstdc++  -version-info 5:2:0   

pkginclude_HEADERS = CgiDefs.h CgiEnvironment.h CgiInput.h CgiUtils.h	\
Cgicc.h FormEntry.h FormFile.h HTMLAtomicElement.h HTMLAttribute.h	\
HTMLAttributeList.h HTMLBooleanElement.h HTMLClasses.h HTMLDoctype.h	\
HTMLElement.h HTMLElementList.h HTTPContentHeader.h HTTPCookie.h	\
HTTPHTMLHeader.h HTTPHeader.h HTTPPlainHeader.h HTTPRedirectHeader.h	\
HTTPResponseHeader.h HTTPStatusHeader.h MStreamable.h \
HTTPXHTMLHeader.h XHTMLDoctype.h XMLDeclaration.h XMLPI.h

libcgicc_la_CPPFLAGS = -x c++ 
libcgicc_la_LIBADD = 
