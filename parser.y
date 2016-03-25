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
%token DECIMALINTEGER

%%

Script : ScriptBody
	;

ScriptBody: StatementList
	;

StatementList: StatementListItem
	;

StatementListItem: Statement
	;

Statement: ExpressionStatement
	;

ExpressionStatement: Expression SEMICOLON
	;

Expression: AssignmentExpression
	;

AssignmentExpression: LeftHandSideExpression EQUALS AssignmentExpression
		    | ConditionalExpression
		    ;

ConditionalExpression: LogicalORExpression
		     ;

LogicalORExpression: LogicalANDExpression
		   ;

LogicalANDExpression: BitwiseORExpression
		    ;

BitwiseORExpression: BitwiseXORExpression
		   ;

BitwiseXORExpression: BitwiseANDExpression
		    ;

BitwiseANDExpression: EqualityExpression
		    ;

EqualityExpression: RelationalExpression
		 ;

RelationalExpression: ShiftExpression
		    ;

ShiftExpression: AdditiveExpression
		;

AdditiveExpression: MultiplicativeExpression
		  ;

MultiplicativeExpression: UnaryExpression
			;

UnaryExpression: PostfixExpression
		;

PostfixExpression: LeftHandSideExpression
		 ;

LeftHandSideExpression: NewExpression
		      ;

NewExpression: MemberExpression
	      ;

MemberExpression: PrimaryExpression
		;

PrimaryExpression: Identifier
		 | Literal
		 ;

Identifier: IdentifierName
	  ;

IdentifierName: IDENT
	  ;

Literal: NumericLiteral
	;

NumericLiteral: DecimalLiteral
	      ;
	
DecimalLiteral: DecimalIntegerLiteral
	      ;

DecimalIntegerLiteral: DECIMALINTEGER
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

