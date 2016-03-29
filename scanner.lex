%{
#include <stdlib.h>
#include <stdio.h>
#include <parser.tab.h>
int yylex();
YYSTYPE yylval;
%}


digit [0-9]
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
yield 	 					{ return YIELD; }
console 					{ return CONSOLE;}
log							{ return LOG;}
true						{ return TRUE;}
false						{ return FALSE;}
null						{ return NULLKEY;}
enum 						{ return ENUM;}
await						{ return AWAIT;}

{letter}({letter}|{digit})*		{ yylval.name = yytext; return IDENT; }

\"([^"])*\" 					{ yylval.name = yytext; return STRING; }

0						{ return '0'; }
1						{ return '1'; }
2						{ return '2'; }
3						{ return '3'; }
4						{ return '4'; }
5						{ return '5'; }
6						{ return '6'; }
7						{ return '7'; }
8						{ return '8'; }
9						{ return '9'; }


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

:						{ return COLON ;}

=						{ return EQUALS ;} 

"+="						{ return PLUSEQUALS ;}

"-="						{ return MINUSEQUALS ;}

"*="						{ return MULTIPLYEQUALS ;}

"/="						{ return DIVIDEEQUALS ;}

\;						{ return SEMICOLON; }

"?"						{ return QUESTIONMARK; }

"||"						{ return OR; } 

"&&"						{ return AND; }

"'"						{ return APOSTROPHE; }

[ \r\n\t]*					/* skip whitespace */

<<EOF>>						{ return EOF; }

.						{ fprintf(stderr, "invalid character '%c'\n", *yytext); exit(0); }

%%

int yywrap(void) {
	return 1;
}