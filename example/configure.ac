dnl -*-m4-*-
dnl $Id: configure.ac,v 1.1 2001/09/03 22:11:13 sbooth Exp $

dnl Process this file with autoconf to produce a configure script.
AC_INIT(cgicc-example, 0.2, bug-cgicc@gnu.org)
AC_CONFIG_SRCDIR(example.cpp)
AC_REVISION($Revision: 1.1 $)
AC_PREFIX_DEFAULT(/usr)
AM_INIT_AUTOMAKE(cgicc-example, 0.2)

AC_LANG_CPLUSPLUS

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL

dnl Checks for libraries.

dnl Checks for header files.

dnl Checks for typedefs, structures, and compiler characteristics.

dnl Checks for library functions.

dnl Info on installed cgicc
AC_ARG_WITH(cgicc,
  [  --with-cgicc=DIR        use cgicc installation in DIR],
  [if ! test -d "${withval}"; then
    AC_MSG_ERROR(bad value '${withval}' for --with-cgicc: not a directory)
   fi
   cgicc_prefix=${withval}])

dnl Perform some sanity checks on the cgicc installation
CGICC_CHECK_INSTALLATION($cgicc_prefix)

dnl Output files
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
