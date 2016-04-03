%{
#include <stdlib.h>
#include <stdio.h>
#include <parser.tab.h>
int yylex();
YYSTYPE yylval;
%}

NonZeroDigit [1-9]   
DecimalDigit [0-9]
letter [a-zA-Z]
DecimalIntegerLiteral (0|({NonZeroDigit}({DecimalDigit})*))	
SignedInteger {DecimalDigit}+|([+-]({DecimalDigit})+)

%%

		/* Keywords */
break							{ return BREAK; }
case							{ return CASE;}
catch 							{ return CATCH; }
class 							{ return CLASS; }
const 							{ return CONST; }
continue 						{ return CONTINUE; }
debugger 						{ return DEBUGGER; }
default 						{ return DEFAULT; }
delete 							{ return DELETE; }
do 								{ return DO; }
else 							{ return ELSE; }
export 							{ return EXPORT; }
extends 						{ return EXTENDS; }
finally 						{ return FINALLY; }
for 							{ return FOR; }
function 						{ return FUNCTION; }
if 								{ return IF; }
import 							{ return IMPORT; }
in 								{ return IN; }
instanceof 						{ return INSTANCEOF; }
new 							{ return NEW; }
return 							{ return RETURN; }
super 							{ return SUPER; }
switch 							{ return SWITCH; }
this 							{ return THIS; }
throw 							{ return THROW; }
try 							{ return TRY; }
typeof							{ return TYPEOF; }
var 							{ return VAR; }
void 							{ return VOID; }
while							{ return WHILE; }
with							{ return WITH; }
yield 							{ return YIELD; }

		/* NullLiteral and BooleanLiteral */
null						{ return NULLLITERAL; }   
false						{ yylval.num = 0; return BOOLEANLITERAL; }  
true						{ yylval.num = 1; return BOOLEANLITERAL; }  

		/* FutureReservedWord */
enum
							

({letter}|\$|\_)({letter}|\$|\_|0|{NonZeroDigit})*	{ yylval.name = yytext; return IDENTIFIERNAME; }  



		/* Numeric Literal and Subtypes */


{DecimalIntegerLiteral}([eE]{SignedInteger})? {yylval.num=atoi(yytext); return DecimalLiteral;}  //eg 5e10 or 5012 
\.{DecimalDigit}+([eE]{SignedInteger})?  {yylval.num=atoi(yytext); return DecimalLiteral;} //eg .1 or .1e10
{DecimalIntegerLiteral}\.{DecimalDigit}*([eE]{SignedInteger})?  {yylval.num=atoi(yytext); return DecimalLiteral;} //eg 1.11 or 1.11e10 or 1.e10


\"(\\.|[^"\n\t\r])*\" 				{ yylval.name = yytext; return STRINGLITERAL; }  

\'(\\.|[^'\n\t\r])*\'				{ yylval.name = yytext; return STRINGLITERAL; }  


		/* Punctuators */
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

		/* Operators */


		/* Misc */

[ \r\n\t]*					/* skip whitespace */

<<EOF>>						{ return EOF; }

.						{ fprintf(stderr, "invalid character '%c'\n", *yytext); exit(0); }

%%

int yywrap(void) {
	return 1;
}