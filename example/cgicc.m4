dnl
dnl $Id: cgicc.m4,v 1.7 2002/03/17 20:56:37 sbooth Exp $
dnl
dnl Copyright (C) 2000 - 2002 Stephen F. Booth
dnl
dnl This program is free software; you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 2 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program; if not, write to the Free Software
dnl Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
dnl


dnl
dnl CGICC_CHECK_CONFIG([PREFIX])
dnl
dnl Check for the configuration script 'cgicc-config' in PATH.  Define
dnl  the macros cgicc_libdir and cgicc_includedir to the values
dnl  obtained from 'cgicc-config'.
dnl
AC_DEFUN(CGICC_CHECK_CONFIG, [
  AC_PATH_PROG(CGICC_CONFIG, cgicc-config, no, [$1/bin $PATH])
  if test "$CGICC_CONFIG" = no; then
    AC_MSG_ERROR(cgicc-config not found in $1/bin:$PATH)
  fi

  cgicc_libdir=`$CGICC_CONFIG --libdir`
  cgicc_includedir=`$CGICC_CONFIG --includedir`

  AC_SUBST(cgicc_libdir)
  AC_SUBST(cgicc_includedir)
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

  cgicc_include_dir=ifelse([$1], ,$cgicc_includedir,$1)

  list="CgiDefs.h CgiEnvironment.h CgiInput.h CgiUtils.h Cgicc.h FormEntry.h FormFile.h HTMLAtomicElement.h HTMLAttribute.h HTMLAttributeList.h HTMLBooleanElement.h HTMLClasses.h HTMLDoctype.h HTMLElement.h HTMLElementList.h HTTPContentHeader.h HTTPCookie.h HTTPHTMLHeader.h HTTPHeader.h HTTPPlainHeader.h HTTPRedirectHeader.h HTTPResponseHeader.h HTTPStatusHeader.h MStreamable.h"
  for file in $list; do
    if ! test -e "$cgicc_include_dir/cgicc/$file"; then
      cgicc_headers_found=no
      missing="$missing $file"
    fi
  done

  AC_MSG_RESULT($cgicc_headers_found)  

  if test "$cgicc_headers_found" = no; then
    AC_MSG_ERROR(missing cgicc header(s): $missing)
  fi
])

dnl
dnl CGICC_CHECK_VERSION([MINIMUM-VERSION])
dnl
dnl Verify that the installed version of cgicc is at least
dnl  MINIMUM-VERSION, if specified, otherwise 3.2.1
dnl
AC_DEFUN(CGICC_CHECK_VERSION, [
  AC_REQUIRE([CGICC_CHECK_CONFIG])
  cgicc_min_version=ifelse([$1], ,3.2.1,$1)
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
dnl  - Installed version >= 3.1 [or MINIMUM-VERSION if specified]
AC_DEFUN(CGICC_CHECK_INSTALLATION,[
  CGICC_CHECK_CONFIG($1)
  CGICC_CHECK_HEADERS($2)
  CGICC_CHECK_VERSION($3)
])
