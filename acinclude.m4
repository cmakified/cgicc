dnl $Id: acinclude.m4,v 1.6 2002/02/05 23:44:07 sbooth Exp $

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
			std::cout << "foo" << std::endl;,
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

dnl CGICC_CHECK_ACC
AC_DEFUN(CGICC_CHECK_ACC, [
	AC_CACHE_CHECK(
		[whether the C++ compiler ($CXX) is aCC],
		[cgicc_cv_acc],
		[	if echo $CXX | grep 'HP ANSI C++'> /dev/null 2>&1; then
				cgicc_cv_acc=yes
			else
				cgicc_cv_acc=no
			fi
			
	])
])




