dnl $Id: acinclude.m4,v 1.1 2000/11/14 05:42:03 sbooth Exp $

dnl @TOP@

dnl
dnl CGICC_CHECK_CONFIG([PREFIX])
dnl
dnl Check for the configuration script 'cgicc-config' in PATH.  Define
dnl  the macros CGICC_LIBDIR and CGICC_INCLUDEDIR to the values
dnl  obtained from 'cgicc-config'.
dnl
AC_DEFUN(CGICC_CHECK_CONFIG, [
  AC_PATH_PROG(CGICC_CONFIG, cgicc-config, no, [$1/bin])
  if test "$CGICC_CONFIG" = no; then
    AC_MSG_ERROR(cgicc-config not found in $PATH)
  fi

  CGICC_LIBDIR=`$CGICC_CONFIG --libdir`
  CGICC_INCLUDEDIR=`$CGICC_CONFIG --includedir`

  AC_SUBST(CGICC_LIBDIR)
  AC_SUBST(CGICC_INCLUDEDIR)
])

dnl
dnl CGICC_CHECK_HEADERS([INCLUDEDIR])
dnl
dnl Perform a sanity check on the cgicc installation, making sure all
dnl  headers are present.
dnl
AC_DEFUN(CGICC_CHECK_HEADERS, [
  AC_REQUIRE([CGICC_CHECK_CONFIG])
  missing=
  AC_MSG_CHECKING(whether cgicc headers look good)
  cgicc_headers_found=yes

  cgicc_includedir=ifelse([$1], ,$CGICC_INCLUDEDIR,$1)

  list="CgiDefs.h CgiEnvironment.h CgiUtils.h Cgicc.h FormEntry.h FormFile.h HTMLAttributes.h HTMLClasses.h HTMLElements.h HTMLGeneric.h HTTPHeaders.h MStreamable.h CgiEnvironment.h"
  for file in $list; do
    if ! test -e "$cgicc_includedir/cgicc/$file"; then
      cgicc_headers_found=no
      missing="$missing $file"
    fi
  done

  AC_MSG_RESULT($cgicc_headers_found)  

  if test $cgicc_headers_found = "no"; then
    AC_MSG_ERROR(missing cgicc header(s): $missing)
  fi
])

dnl
dnl CGICC_CHECK_VERSION([MINIMUM-VERSION])
dnl
dnl Verify that the installed version of cgicc is at least
dnl  MINIMUM-VERSION, if specified, otherwise 3.1
dnl
AC_DEFUN(CGICC_CHECK_VERSION, [
  AC_REQUIRE([CGICC_CHECK_CONFIG])
  cgicc_min_version=ifelse([$1], ,3.1,$1)
  AC_MSG_CHECKING(for cgicc version >= $cgicc_min_version)
  cgicc_version=
  cgicc_major_version=
  cgicc_minor_version=

  cgicc_req_major_version=`echo $cgicc_min_version | cut -d '.' -f 1`
  cgicc_req_minor_version=`echo $cgicc_min_version | cut -d '.' -f 2`

  cgicc_version=`$CGICC_CONFIG --version`

  cgicc_major_version=`echo $cgicc_version | cut -d '.' -f 1`
  cgicc_minor_version=`echo $cgicc_version | cut -d '.' -f 2`

  AC_MSG_RESULT($cgicc_version)

  if (test $cgicc_major_version -lt $cgicc_req_major_version || test $cgicc_minor_version -lt $cgicc_req_minor_version); then
    AC_MSG_ERROR(cgicc version >= $cgicc_min_version required)
  fi
])

dnl
dnl CGICC_CHECK_INSTALLATION([PREFIX[,INCLUDEDIR[,MINIMUM-VERSION]]])
dnl
dnl Check the cgicc installation for:
dnl  - Presence of the 'cgicc-config' script [in PREFIX]
dnl  - Presence of all headers [in INCLUDEDIR]
dnl  - Installed version >= 3.1 [or MINIMUM VERSION if specified]
AC_DEFUN(CGICC_CHECK_INSTALLATION,[
  CGICC_CHECK_CONFIG($1)
  CGICC_CHECK_HEADERS($2)
  CGICC_CHECK_VERSION($3)
])
