dnl -*-m4-*-
dnl $Id: configure.ac,v 1.2 2002/02/05 23:44:07 sbooth Exp $

dnl Process this file with autoconf to produce a configure script.
AC_INIT(cgicc, 3.2, bug-cgicc@gnu.org)
AC_CONFIG_SRCDIR(cgicc/Cgicc.cpp)
AC_REVISION([$Revision: 1.2 $])
AC_CONFIG_AUX_DIR(support)
AC_PREFIX_DEFAULT(/usr)
AM_INIT_AUTOMAKE(cgicc, 3.2)
AM_CONFIG_HEADER(cgicc/config.h)
AM_MAINTAINER_MODE

AC_LANG_CPLUSPLUS

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AM_PROG_LIBTOOL
AC_CHECK_PROG(DOXYGEN, doxygen, doxygen)

dnl Checks for libraries.

dnl setup for networking functions
AC_CHECK_LIB(nsl, gethostbyaddr, LIB_NET="-lnsl")
AC_SUBST(LIB_NET)

dnl check whether to link against libstdc++
CGICC_CHECK_LINK_STDCPP

dnl Checks for header files.
AC_CHECK_HEADERS(sys/time.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_STRUCT_TM

dnl Determine host system type
AC_CANONICAL_HOST
AC_DEFINE_UNQUOTED(HOST, "$host")

dnl Check whether we're using aCC
CGICC_CHECK_ACC
if test "$cgicc_cv_acc" = yes; then
  CXXFLAGS="-AA $CXXFLAGS"
  DEMO_LIBS="-lstd_v2 -lCsup_v2"
fi
AC_SUBST(DEMO_LIBS)

dnl verify STL support
CGICC_CHECK_CPP_STL

dnl verify namespace support
CGICC_CHECK_CPP_NAMESPACES

dnl Checks for library functions.
AC_HEADER_STDC
AC_HEADER_TIME
AC_CHECK_FUNCS(strftime gettimeofday uname)

dnl enable/disable compiler warnings (using gcc), if specified
AC_ARG_ENABLE(warnings,
  [  --disable-warnings      disable gcc warnings [default=no]],
  [case "${enableval}" in
    yes) cgicc_warnings=yes ;; 
    no)  cgicc_warnings=no ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --enable-warnings) ;;
  esac], cgicc_warnings=yes)
AC_MSG_CHECKING(whether to use gcc verbose warnings)
AC_MSG_RESULT($cgicc_warnings)
if (test "$cgicc_warnings" = yes && test "$GCC" = yes); then
  CXXFLAGS="-Wall -W -pedantic $CXXFLAGS"
fi

dnl enable/disable namespaces, if specified
AC_ARG_ENABLE(namespaces,
  [  --enable-namespaces     enable namespace support [default=yes]],
  [case "${enableval}" in
    yes) cgicc_namespaces=yes ;;
    no)  cgicc_namespaces=no ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --enable-namespaces) ;;
  esac], cgicc_namespaces=yes)
AC_MSG_CHECKING(whether to use the cgicc namespace)
AC_MSG_RESULT($cgicc_namespaces)
if (test "$cgicc_namespaces" = yes && test "$cgicc_cv_cpp_namespaces" = yes); then
  CGICC_USE_NAMESPACES=1
else
  CGICC_USE_NAMESPACES=0
fi
AC_SUBST(CGICC_USE_NAMESPACES)

dnl enable/disable debug logging, if specified
AC_ARG_ENABLE(debug-logging,
  [  --enable-debug-logging  enable debug logging [default=no]],
  [case "${enableval}" in
    yes) cgicc_debug=yes ;;
    no)  cgicc_debug=no ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --enable-debug-logging) ;;
  esac], cgicc_debug=no)
AC_MSG_CHECKING(whether to enable debug logging)
AC_MSG_RESULT($cgicc_debug)
if test "$debug" = yes; then
  AC_DEFINE(DEBUG,1)
else
  AC_DEFINE(DEBUG,0)
fi

dnl enable/disable the demos, if specified
AC_ARG_ENABLE(demos, 
  [  --enable-demos          build demos [default=yes]],
  [case "${enableval}" in
    yes) cgicc_demos=yes ;;
    no)  cgicc_demos=no ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --enable-demos) ;;
  esac], cgicc_demos=yes)
AC_MSG_CHECKING(whether to build the cgicc demos)
AC_MSG_RESULT($cgicc_demos)
AM_CONDITIONAL(DEMOS, test "$cgicc_demos" = yes)

if test "$cgicc_demos" = yes; then
  AC_CONFIG_FILES(demo/Makefile contrib/Makefile)
fi

dnl Only build HTML if maintainer mode is active
if test "$USE_MAINTAINER_MODE" = yes; then
  AC_CONFIG_FILES(html/Makefile html/cgicc.html)
fi

dnl Always output certain files
AC_CONFIG_FILES([Makefile cgicc/Makefile cgicc/CgiDefs.h 
  support/Makefile support/cgicc-config doc/Makefile doc/Doxyfile])

AC_OUTPUT

