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
abstract						{ return ABSTRACT; }
arguments					{ return ARGUMENTS; }
boolean						{ return BOOLEAN; }
byte						{ return BYTE; }
char						{ return CHAR; }
double						{ return DOUBLE; }
float						{ return FLOAT; }
int						{ return INT; }
long						{ return LONG; }

{letter}({letter}|{digit})*			{ yylval.name = yytext; return IDENT; }

["]([^"])*["] 					{ yylval.name = yytext; return STRING; }

[+-]?({digit}*[.])?{digit}+			{ yylval.num = atoi(yytext); return NUMBER; }

,						{ return ','; }		

-						{ return '-'; }

"."						{ return '.'; }

"("						{ return LPARAM; }

")"						{ return RPARAM; }

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

"<<="						{ return LEFTSHIFTEQUAL; }

">>="						{ return RIGHTSHIFTEQUAL; }

">>>="						{ return LOGICRIGHTSHIFTEQUAL; }

"&="						{ return BINANDEQUAL; }

"|="						{ return BINOREQUAL; }

"^="						{ return BINXOREQUAL; }

"=>"						{ return SHIFTTO; }

:							{ return COLON ;}

=							{ return EQUALS ;} 

"+="						{ return PLUSEQUALS ;}

"-="						{ return MINUSEQUALS ;}

"*="						{ return MULTIPLYEQUALS ;}

"/="						{ return DIVIDEEQUALS ;}

\;							{ return SEMICOLON; }

"?"							{ return QUESTIONMARK; }

"||"						{ return OR; } 

"&&"						{ return AND; }

"'"							{ return APOSTROPHE; }

[ \r\n\t]*					/* skip whitespace */

<<EOF>>						{ return EOF; }

.						{ fprintf(stderr, "invalid character '%c'\n", *yytext); exit(0); }

%%
