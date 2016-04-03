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
%token LPARAM RPARAM LBRACE RBRACE
%token <name> IDENTIFIERNAME 
%token <num> NUMBER 
%token EQUALS GE LE ET NEV NEVT INC ETT
%token BREAK CASE CATCH CLASS CONST CONTINUE DEBUGGER DEFAULT DELETE DO ELSE EXPORT
%token EXTENDS FINALLY FOR FUNCTION IF IMPORT IN INSTANCEOF NEW RETURN SUPER SWITCH
%token THIS THROW TRY TYPEOF VAR VOID WITH YIELD COLON PLUSEQUALS MINUSEQUALS MULTIPLYEQUALS DIVIDEEQUALS
%token SEMICOLON QUESTIONMARK OR AND APOSTROPHE LEFTSHIFTEQUAL RIGHTSHIFTEQUAL LOGICRIGHTSHIFTEQUAL BINANDEQUAL BINOREQUAL
%token BINXOREQUAL SHIFTTO
%token <name> STRINGLITERAL
%token <num> DecimalLiteral
%token <num> BinaryIntegerLiteral
%token <num> BOOLEANLITERAL
%token NULLLITERAL

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
	;

StatementListItem: Statement
		 | StatementList Statement
	;

BlockStatement: Block
			;
Block: LBRACE StatementList RBRACE
			;	

Statement: BlockStatement
			| ExpressionStatement
			| VariableStatement
			| IfStatement
	;
	
IfStatement: IF LPARAM Expression RPARAM Statement ELSE Statement
			| IF LPARAM Expression RPARAM Statement %prec LOWER_THAN_ELSE
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
			| EqualityExpression ET RelationalExpression
			| EqualityExpression NEV RelationalExpression
			| EqualityExpression NEVT RelationalExpression
			| EqualityExpression ETT RelationalExpression

		 ;

RelationalExpression: ShiftExpression
			| RelationalExpression '<' ShiftExpression
			| RelationalExpression '>' ShiftExpression
			| RelationalExpression LE ShiftExpression
			| RelationalExpression GE ShiftExpression
			| RelationalExpression INSTANCEOF ShiftExpression
			| RelationalExpression IN ShiftExpression
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
		| BinaryIntegerLiteral
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

