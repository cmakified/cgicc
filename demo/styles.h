/*
 *  $Id: styles.h,v 1.2 2004/06/29 04:23:36 sbooth Exp $
 *
 *  Copyright (C) 1996 - 2004 Stephen F. Booth
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef _STYLES_H_
#define _STYLES_H_ 1

#include <string>

const std::string styles = 
"body { color: black; background: white; }\n"
"span.red { color:red; }\n"
"hr.half { width: 60%; margin-left: auto; margin-right: auto; }\n"
"div.center { text-align: center; }\n"
"div.notice { border: solid thin; padding: 1em; margin: 1em 0; "
"background: #ddd; text-align: center; }"
"table { width: 90%; margin-left: auto; margin-right: auto; }\n"
"tr.title, td.title { color: white; background: black; font-weight: bold; "
"text-align: center; }\n"
"tr.data, td.data { background: #ddd; }\n"
"td.form { background: #ddd; text-align: center; }\n"
;

#endif /* _STYLES_H_ */
