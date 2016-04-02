%{
#include <stdlib.h>
#include <stdio.h>
#include <parser.tab.h>
int yylex();
YYSTYPE yylval;
%}

nonzerodigit [1-9]   
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
do 						{ return DO; }
else 						{ return ELSE; }
export 						{ return EXPORT; }
extends 					{ return EXTENDS; }
finally 					{ return FINALLY; }
for 						{ return FOR; }
function 					{ return FUNCTION; }
if 						{ return IF; }
import 						{ return IMPORT; }
in 						{ return IN; }
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
null						{ return NULLLITERAL; }   /*Lina*/
false						{ yylval.num = 0; return BOOLEANLITERAL; }  /*Lina*/
true						{ yylval.num = 0; return BOOLEANLITERAL; }  /*Lina*/
  
enum						/*Future reserved words - Lina*/			

({letter}|\$|\_)({letter}|\$|\_|0|{nonzerodigit})*	{ yylval.name = yytext; return IDENTIFIERNAME; }  /*Lina*/

\"(\\.|[^"\n\t\r])*\" 				{ yylval.name = yytext; return STRINGLITERAL; }  /*Lina*/

\'(\\.|[^'\n\t\r])*\'				{ yylval.name = yytext; return STRINGLITERAL; }  /*Lina*/

{nonzerodigit}(0|{nonzerodigit})*	        { yylval.num = atoi(yytext); return DECIMALINTEGERLITERAL; } /*Lina*/

[+-]?({nonzerodigit}[.])?({nonzerodigit})+	{ yylval.num = atoi(yytext); return NUMBER; }

0						{ yylval.num = atoi(yytext); return DECIMALINTEGERLITERAL; } /*Lina*/

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

[ \r\n\t]*					/* skip whitespace */

<<EOF>>						{ return EOF; }

.						{ fprintf(stderr, "invalid character '%c'\n", *yytext); exit(0); }

%%

int yywrap(void) {
	return 1;
}