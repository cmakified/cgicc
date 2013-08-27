#
# cgicc 3.2.10 cmakified
# by Michal Papierski <michal@papierski.net>
#
cmake_minimum_required (VERSION 2.8.7)
project (cgicc)

set (VERSION "3.2.10")
execute_process (COMMAND "(hostname || uname -n) 2>/dev/null | sed 1q"
	RESULT_VARIABLE HOST)
# Platform checks
include (CheckIncludeFiles)
check_include_files (dlfcn.h HAVE_DLFCN_H)
include(CheckSymbolExists)
check_symbol_exists(gettimeofday sys/time.h HAVE_GETTIMEOFDAY)
check_include_files (inttypes.h HAVE_INTTYPES_H)
check_include_files (memory.h HAVE_MEMORY_H)
include (CheckCXXSourceCompiles)
check_cxx_source_compiles ("
	namespace test { }
	int main(int, char**) {
		using namespace ::test;
	}" HAVE_NAMESPACES)
check_include_files (stdint.h HAVE_STDINT_H)
check_include_files (stdlib.h HAVE_STDLIB_H)
set (CMAKE_REQUIRED_FLAGS "-DHAVE_NAMESPACES")
check_cxx_source_compiles ("
	#include <list>
	#include <deque>
	#ifdef HAVE_NAMESPACES
	using namespace std;
	#endif
	int
	main ()
	{
	list<int> x; x.push_back(5);
	list<int>::iterator iter = x.begin(); if (iter != x.end()) ++iter; return 0;
	  ;
	  return 0;
	}" HAVE_STL)
check_include_files (strings.h HAVE_STRINGS_H)
check_include_files (string.h HAVE_STRING_H)
check_include_files (sys/stat.h HAVE_SYS_STAT_H)
check_include_files (sys/time.h HAVE_SYS_TIME_H)
check_include_files (sys/types.h HAVE_SYS_TYPES_H)
check_include_files (sys/utsname.h HAVE_SYS_UTSNAME_H)
check_symbol_exists (uname sys/utsname.h HAVE_UNAME)
check_include_files (unistd.h HAVE_UNISTD_H)
include_directories (
	.
	${CMAKE_CURRENT_BINARY_DIR})
add_custom_command (
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/cgicc/CgiDefs.h
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/cgicc
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cgicc/CgiDefs.h.in ${CMAKE_CURRENT_BINARY_DIR}/cgicc/CgiDefs.h)
configure_file (
	${CMAKE_CURRENT_SOURCE_DIR}/cgicc/config.h.in
	${CMAKE_CURRENT_BINARY_DIR}/config.h)
add_definitions (-DHAVE_CONFIG_H)
set (cgicc_SOURCES
	cgicc/CgiEnvironment.cpp
	cgicc/CgiInput.cpp
	cgicc/CgiUtils.cpp
	cgicc/Cgicc.cpp
	cgicc/FormEntry.cpp
	cgicc/FormFile.cpp
	cgicc/HTMLAttribute.cpp
	cgicc/HTMLAttributeList.cpp
	cgicc/HTMLDoctype.cpp
	cgicc/HTMLElement.cpp
	cgicc/HTMLElementList.cpp
	cgicc/HTTPContentHeader.cpp
	cgicc/HTTPCookie.cpp
	cgicc/HTTPHTMLHeader.cpp
	cgicc/HTTPHeader.cpp
	cgicc/HTTPPlainHeader.cpp
	cgicc/HTTPRedirectHeader.cpp
	cgicc/HTTPResponseHeader.cpp
	cgicc/HTTPStatusHeader.cpp
	cgicc/HTTPXHTMLHeader.cpp
	cgicc/MStreamable.cpp
	cgicc/XHTMLDoctype.cpp
	cgicc/XMLPI.cpp)
set (cgicc_HEADERS
	cgicc/Cgicc.h
	cgicc/CgiEnvironment.h
	cgicc/CgiInput.h
	cgicc/CgiUtils.h
	cgicc/FormEntry.h
	cgicc/FormFile.h
	cgicc/HTMLAtomicElement.h
	cgicc/HTMLAttribute.h
	cgicc/HTMLAttributeList.h
	cgicc/HTMLBooleanElement.h
	cgicc/HTMLClasses.h
	cgicc/HTMLDoctype.h
	cgicc/HTMLElement.h
	cgicc/HTMLElementList.h
	cgicc/HTTPContentHeader.h
	cgicc/HTTPCookie.h
	cgicc/HTTPHeader.h
	cgicc/HTTPHTMLHeader.h
	cgicc/HTTPPlainHeader.h
	cgicc/HTTPRedirectHeader.h
	cgicc/HTTPResponseHeader.h
	cgicc/HTTPStatusHeader.h
	cgicc/HTTPXHTMLHeader.h
	cgicc/MStreamable.h
	cgicc/XHTMLDoctype.h
	cgicc/XMLDeclaration.h
	cgicc/XMLPI.h
	${CMAKE_CURRENT_BINARY_DIR}/cgicc/CgiDefs.h
	${CMAKE_CURRENT_BINARY_DIR}/config.h)
source_group ("Header Files"
	FILES ${cgicc_HEADERS})
add_library (cgicc
	${cgicc_SOURCES}
	${cgicc_HEADERS})

