# $Id: Makefile.am,v 1.3 1998/12/19 01:52:48 sbooth Exp $

CLEANFILES = *~
DISTCLEANFILES = .deps/*

lib_LTLIBRARIES = libCgicc.la
libCgicc_la_SOURCES = CgiDefs.cc CgiEnvironment.cc Cgicc.cc Exception.cc \
FormEntry.cc FormFile.cc HTMLAttributes.cc HTMLDirLang.cc HTMLElements.cc \
HTMLForms.cc HTMLFrames.cc HTMLGlobal.cc HTMLGraphics.cc HTMLLinks.cc \
HTMLLists.cc HTMLObjects.cc HTMLScripts.cc HTMLStyles.cc HTMLTables.cc \
HTMLText.cc HTTPHeaders.cc MStreamable.cc
libCgicc_la_LDFLAGS = -version-info 0:0:0

include_HEADERS = CgiDefs.hh CgiEnvironment.hh Cgicc.hh Exception.hh \
FormEntry.hh FormFile.hh HTMLAttributes.hh HTMLClasses.hh HTMLDirLang.hh \
HTMLElements.hh HTMLForms.hh HTMLFrameClasses.hh HTMLFrames.hh HTMLGlobal.hh \
HTMLGraphics.hh HTMLLinks.hh HTMLLists.hh HTMLObjects.hh HTMLScripts.hh \
HTMLStyles.hh HTMLTables.hh HTMLText.hh HTTPHeaders.hh LinkedList.hh \
MStreamable.hh Node.hh
