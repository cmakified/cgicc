#ifndef _STYLES_H_
#define _STYLES_H_ 1

#include <string>

const std::string styles = 
"body { color: black; background: white; }\n"
"span.red { color:red; }\n"
"hr.half { width: 60%; margin-left: auto; margin-right: auto; }\n"
"div.center { text-align: center; }\n"
"div.notice { border: solid thin; padding: 1em; margin: 1em 0; background: #ddd; text-align: center; }"
"table { width: 90%; margin-left: auto; margin-right: auto; }\n"
"td.title { color: white; background: black; font-weight: bold; text-align: center; }\n"
"td.data { background: #ddd; }\n"
"td.form { background: #ddd; text-align: center; }\n"
;

/*
body { color: black; background: white; }

a:link { color: #1f00ff }
a:visited { color: #9900dd }
a:active { color: #ff0000 }
a:hover { color: #ff0000 }

hr.half { width: 60%; align: center; }
    
span.red, strong.red { color: red; } 
span.green { color: green; }
span.blue { color: blue; }

p.legal { font-size: small }
p.red { text-align: center; color: red; }
p.center { text-align: center; }

div.notice { border: solid thin; padding: 1em; margin: 1em 0; 
  background: #ddd;}

table.form { left-margin: auto; right-margin: auto; width: 90%; }

col.black, td.black, td.title, tr.title { color: white;
  background: black; font-weight: bold; text-align: center; }

col.gray, td.gray { background: #DDD; text-align: center; }

td.data, tr.data { background: #DDD; text-align: left; }
td.grayspecial { background: #DDD; text-align: left; }
td.ltgray, tr.ltgray { background: #DDD; }
td.dkgray, tr.dkgray { background: #BBB; }

div.center { text-align: center; }

div.smaller { font-size: small; }

 */

#endif /* _STYLES_H_ */
