dnl $Id: acinclude.m4,v 1.1 1998/12/11 19:42:16 sbooth Exp $

dnl CGICC_CHECK_LINK_STDCPP
AC_DEFUN(CGICC_CHECK_LINK_STDCPP, [
	AC_CACHE_CHECK(	[whether to link against libstdc++],
			[cgicc_cv_link_libstdcpp],
			[AC_TRY_LINK([#include <iostream.h>],
				cout << "foo" << endl;,
				cgicc_cv_link_libstdcpp=no,
				cgicc_cv_link_libstdcpp=yes)
			])
	if (test "$cgicc_cv_link_libstdcpp" = yes); then 
		LIBS="$LIBS -lstdc++"
	fi
])

dnl CGICC_CHECK_CPP_EXCEPTIONS
AC_DEFUN(CGICC_CHECK_CPP_EXCEPTIONS, [
	AC_CACHE_CHECK(	[for exception handling],
		[cgicc_cv_cpp_exceptions],
		[AC_TRY_COMPILE(,
			int i=0; try {++i;} catch(...) {--i;},
			cgicc_cv_cpp_exceptions=yes,
			cgicc_cv_cpp_exceptions=no)
		])
	if (test "$cgicc_cv_cpp_exceptions" = no); then 
		AC_MSG_ERROR([exception handling required])
	fi
])

dnl CGICC_CHECK_CPP_TEMPLATES
AC_DEFUN(CGICC_CHECK_CPP_TEMPLATES, [
	AC_CACHE_CHECK(	[for template support],
		[cgicc_cv_cpp_templates],
		[AC_TRY_CPP([template <class T> int foo(T arg);],
			cgicc_cv_cpp_templates=yes,
			cgicc_cv_cpp_templates=no)
		])
	if (test "$cgicc_cv_cpp_templates" = no); then 
		AC_MSG_ERROR([template support required])
	fi
])


