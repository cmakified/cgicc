## $Id: Makefile.am,v 1.9 1999/05/31 17:04:35 sbooth Exp $

CLEANFILES = *~

lib_LTLIBRARIES = libcgicc.la
libcgicc_la_SOURCES = CgiEnvironment.cc CgiUtils.cc Cgicc.cc		\
FormEntry.cc FormFile.cc HTMLAttributes.cc HTMLDirLang.cc		\
HTMLElements.cc HTMLForms.cc HTMLFrames.cc HTMLGlobal.cc		\
HTMLGraphics.cc HTMLLinks.cc HTMLLists.cc HTMLObjects.cc		\
HTMLScripts.cc HTMLStyles.cc HTMLTables.cc HTMLText.cc HTTPHeaders.cc	\
MStreamable.cc
libcgicc_la_LDFLAGS = -version-info 0:1:0

pkginclude_HEADERS = Cgicc.hh CgiDefs.hh CgiEnvironment.hh CgiUtils.hh	\
FormEntry.hh FormFile.hh HTMLAttributes.hh HTMLClasses.hh		\
HTMLDirLang.hh HTMLElements.hh HTMLForms.hh HTMLFrameClasses.hh		\
HTMLFrames.hh HTMLGlobal.hh HTMLGraphics.hh HTMLLinks.hh HTMLLists.hh	\
HTMLObjects.hh HTMLScripts.hh HTMLStyles.hh HTMLTables.hh HTMLText.hh	\
HTTPHeaders.hh MStreamable.hh config.h
