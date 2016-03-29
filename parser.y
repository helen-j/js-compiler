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
%token <name> IDENT 
%token EQUALS GE LE ET NEV NEVT INC
%token BREAK CASE CATCH CLASS CONST CONTINUE DEBUGGER DEFAULT DELETE DO ELSE EXPORT
%token EXTENDS FINALLY FOR FUNCTION IF IMPORT IN INSTANCEOF NEW RETURN SUPER SWITCH TRUE FALSE ENUM AWAIT NULLKEY
%token THIS THROW TRY TYPEOF VAR VOID WITH YIELD COLON PLUSEQUALS MINUSEQUALS MULTIPLYEQUALS DIVIDEEQUALS
%token SEMICOLON QUESTIONMARK OR AND APOSTROPHE LEFTSHIFTEQUAL RIGHTSHIFTEQUAL LOGICRIGHTSHIFTEQUAL BINANDEQUAL BINOREQUAL
%token BINXOREQUAL SHIFTTO
%token <name> STRING
%token CONSOLE LOG LOWER_THAN_ELSE

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left '+' '-'
%left '*' '/' '%'

%%

Script : ScriptBody
	;

ScriptBody: StatementList
	;

StatementList: StatementListItem
			| StatementList StatementListItem
			;

StatementListItem: Statement
	;

Statement:    ExpressionStatement
			| IfStatement
			;

IfStatement: IF '('Expression')' Statement ELSE Statement
			| IF '('Expression')' Statement %prec LOWER_THAN_ELSE
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
			| RelationalExpression '<' ShiftExpression
			| RelationalExpression '>' ShiftExpression
			| RelationalExpression LE ShiftExpression
			| RelationalExpression GE ShiftExpression
		    ;

ShiftExpression: AdditiveExpression
		;

AdditiveExpression: MultiplicativeExpression
			| AdditiveExpression '+' MultiplicativeExpression
			| AdditiveExpression '-' MultiplicativeExpression
			;

MultiplicativeExpression: UnaryExpression
			| MultiplicativeExpression MultiplicativeOperator UnaryExpression
			;

UnaryExpression: PostfixExpression
			| '+' UnaryExpression
			| '-' UnaryExpression
			;

PostfixExpression: LeftHandSideExpression
		 ;

LeftHandSideExpression: NewExpression
		      ;

NewExpression: MemberExpression
	      ;

MemberExpression: PrimaryExpression
		;

PrimaryExpression: THIS
			| IdentifierReference
			| Literal
			;

IdentifierReference: Identifier
		   ;

Identifier: IdentifierName
	  ;

IdentifierName: IDENT
			;

Literal: NumericLiteral
			| StringLiteral
			| NullLiteral
			| BooleanLiteral
			;

NumericLiteral: DecimalLiteral
			;

DecimalLiteral: DecimalIntegerLiteral '.' DecimalDigits
			| '.' DecimalDigits
			| DecimalIntegerLiteral
			;
		  
DecimalIntegerLiteral: NonZeroDigit DecimalDigits
			| NonZeroDigit 
			| '0'
			;

DecimalDigits:DecimalDigits DecimalDigit
			| DecimalDigit
		    ;
DecimalDigit: '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
			;
NonZeroDigit:  '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
			;
			

BooleanLiteral: TRUE
			| FALSE
			;
NullLiteral: NULLKEY
			;

StringLiteral: STRING
			;
			 
MultiplicativeOperator: '*'
			| '/'
			| '%'
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

