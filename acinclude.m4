dnl $Id: acinclude.m4,v 1.5 1999/08/07 00:26:35 sbooth Exp $

dnl @TOP@

dnl CGICC_CHECK_LINK_STDCPP
AC_DEFUN(CGICC_CHECK_LINK_STDCPP, [
	AC_REQUIRE([AC_PROG_CXX])
	AC_CACHE_CHECK(	
		[whether to link against libstdc++],
		[cgicc_cv_link_libstdcpp],
		[	AC_LANG_SAVE
			AC_LANG_CPLUSPLUS
			AC_TRY_LINK([#include <iostream>],
			cout << "foo" << endl;,
			cgicc_cv_link_libstdcpp=no,
			cgicc_cv_link_libstdcpp=yes)
			AC_LANG_RESTORE
		])
	if (test "$cgicc_cv_link_libstdcpp" = yes); then 
		LIBS="$LIBS -lstdc++"
	fi
])

dnl CGICC_CHECK_CPP_STL
AC_DEFUN(CGICC_CHECK_CPP_STL, [
	AC_REQUIRE([AC_PROG_CXX])
	AC_CACHE_CHECK(	
		[whether the C++ compiler ($CXX) supports STL],
		[cgicc_cv_cpp_stl],
		[	AC_LANG_SAVE
			AC_LANG_CPLUSPLUS
			AC_TRY_CPP([#include <vector> 
std::vector<int> gInts;],
			cgicc_cv_cpp_stl=yes,
			cgicc_cv_cpp_stl=no)
			AC_LANG_RESTORE
		])
	if (test "$cgicc_cv_cpp_stl" = no); then 
		AC_MSG_ERROR([standard template library support required])
	fi
])

dnl CGICC_CHECK_CPP_NAMESPACES
AC_DEFUN(CGICC_CHECK_CPP_NAMESPACES, [
	AC_REQUIRE([AC_PROG_CXX])
	AC_CACHE_CHECK(	
		[whether the C++ compiler ($CXX) supports namespaces],
		[cgicc_cv_cpp_namespaces],
		[	AC_LANG_SAVE
			AC_LANG_CPLUSPLUS
			AC_TRY_COMPILE([namespace cgicc {void foo() {} }],
			cgicc::foo();,
			cgicc_cv_cpp_namespaces=yes,
			cgicc_cv_cpp_namespaces=no)
			AC_LANG_RESTORE
		])
])





