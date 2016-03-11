%{
#include <stdlib.h>
#include <stdio.h>
#include <y.tab.h>
%}

digit	[0-9]
letter [a-zA-Z]
 
%%

while						{ return WHILE; }
break						{ return BREAK; }
case						{ return CASE;	}
catch 						{ return CATCH; }
class 						{ return CLASS; }
const 						{ return CONST; }
continue 					{ return CONTINUE; }
debugger 					{ return DEBUGGER; }
default 					{ return DEFAULT; }
delete 						{ return DELETE; }
do 							{ return DO; }
else 						{ return ELSE; }
export 						{ return EXPORT; }
extends 					{ return EXTENDS; }
finally 					{ return FINALLY; }
for 						{ return FOR; }
function 					{ return FUNCTION; }
if 							{ return IF; }
import 						{ return IMPORT; }
in 							{ return IN; }
instanceof 					{ return INSTANCEOF; }
new 						{ return NEW; }
return 						{ return RETURN; }
super 						{ return SUPER; }
switch 						{ return SWITCH; }
this 						{ return THIS; }
throw 						{ return THROW; }
try 						{ return TRY; }
typeof						{ return TYPEOF; }
var 						{ return VAR; }
void 						{ return VOID; }
with						{ return WITH; }
yield 						{ return YIELD; }

{letter}({letter}|{digit})*			{ yylval.name = yytext; return IDENT; }

[+-]?({digit}*[.])?{digit}+			{ yylval.num = atoi(yytext); return NUMBER; }

,						{ return ','; }		

-						{ return '-'; }

">="						{ return GE; }

"<="						{ return LE; }

"!=="						{ return NEVT; }

"!="						{ return NEV; }

"=="						{ return ET; }	

"++"						{ return INC; }

"+"						{ return '+'; }

"%"						{ return '%'; }

"*"						{ return '*'; }

">"						{ return '>'; }	

"<"						{ return '<'; }

[ \r\n\t]					/* skip whitespace */

.						{ fprintf(stderr, "invalid character '%c'\n", *yytext); exit(0); }

%%
