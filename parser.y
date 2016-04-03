%{
	#include <stdio.h>
	#include <string.h>
	int yylex();
	FILE *yyin;
	void yyerror(char const *s) {
		fprintf(stderr, "%s\n",s);
	}
%}
%union {
	int num;
	char *name;
}

%token WHILE
%token LPARAM RPARAM
%token <name> IDENTIFIERNAME 
%token <num> NUMBER 
%token EQUALS GE LE ET NEV NEVT INC
%token BREAK CASE CATCH CLASS CONST CONTINUE DEBUGGER DEFAULT DELETE DO ELSE EXPORT
%token EXTENDS FINALLY FOR FUNCTION IF IMPORT IN INSTANCEOF NEW RETURN SUPER SWITCH
%token THIS THROW TRY TYPEOF VAR VOID WITH YIELD COLON PLUSEQUALS MINUSEQUALS MULTIPLYEQUALS DIVIDEEQUALS
%token SEMICOLON QUESTIONMARK OR AND APOSTROPHE LEFTSHIFTEQUAL RIGHTSHIFTEQUAL LOGICRIGHTSHIFTEQUAL BINANDEQUAL BINOREQUAL
%token BINXOREQUAL SHIFTTO
%token <name> STRINGLITERAL
%token <num> DecimalLiteral
%token <num> BOOLEANLITERAL
%token NULLLITERAL

%%

Script : ScriptBody
	;

ScriptBody: StatementList
	;

StatementList: StatementListItem
	;

StatementListItem: Statement
		 | StatementList Statement
	;

Statement: ExpressionStatement
	 | VariableStatement
	;

VariableStatement: VAR VariableDeclarationList SEMICOLON
		 ;

VariableDeclarationList: VariableDeclaration
			| VariableDeclarationList ',' VariableDeclaration
			;

VariableDeclaration: Identifier Initialiser
		   | Identifier
		   ;

Initialiser: EQUALS AssignmentExpression
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

PrimaryExpression: IdentifierReference
		 | Literal
		 ;

IdentifierReference: Identifier
		   ;

Identifier: IDENTIFIERNAME
	  ;

Literal: NumericLiteral
	|STRINGLITERAL
	|NULLLITERAL
	|BOOLEANLITERAL
	;

NumericLiteral: DecimalLiteral
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

