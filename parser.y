%{
	#include <stdio.h>
	#include <string.h>
	int yylex();
	FILE *yyin;
	void yyerror(char const *s) {
		fprintf(stderr, "%s\n",s);
	}
%}
%token WHILE
%token LPARAM RPARAM
%token IDENT 
%token NUMBER 
%token EQUALS GE LE ET NEV NEVT INC
%token BREAK CASE CATCH CLASS CONST CONTINUE DEBUGGER DEFAULT DELETE DO ELSE EXPORT
%token EXTENDS FINALLY FOR FUNCTION IF IMPORT IN INSTANCEOF NEW RETURN SUPER SWITCH
%token THIS THROW TRY TYPEOF VAR VOID WITH YIELD COLON PLUSEQUALS MINUSEQUALS MULTIPLYEQUALS DIVIDEEQUALS
%token SEMICOLON QUESTIONMARK OR AND APOSTROPHE LEFTSHIFTEQUAL RIGHTSHIFTEQUAL LOGICRIGHTSHIFTEQUAL BINANDEQUAL BINOREQUAL
%token BINXOREQUAL SHIFTTO
%token STRING
%token CONSOLE LOG

%%

program : program statement
	| statement
	;
	
statement: IDENT EQUALS IDENT SEMICOLON 
	 | IDENT EQUALS STRING SEMICOLON
 	 | IDENT EQUALS NUMBER SEMICOLON
	 | CONSOLE '.' LOG LPARAM expr RPARAM SEMICOLON
	 ;

expr:    STRING 
	| NUMBER
	| IDENT
	;
%%

int main(int argc, char* argv[])
{
	if (argc >1)
		yyin = fopen(argv[1], "r");
	else
		yyin = stdin;
	yyparse();
}

