%{
	#include <stdio.h>
	#include <string.h>
	#include "Node.h"
	#include "Statement.h"
	#include "Expression.h"
	#include "AssignmentExpression.h"
	#include "IdentifierExpression.h"
	#include "IntegerLiteralExpression.h"
	int yylex();
	extern FILE *yyin;
	void yyerror(char const *s) {
		fprintf(stderr, "%s\n",s);
	}
extern "C" int yywrap();
Statement *root;
%}
%union {
    Statement *s;
	Expression *e;
	int num;
	char *name;
}

%token WHILE
%token LPARAM RPARAM LBRACE RBRACE
%token <name> IDENTIFIERNAME 
%token <num> NUMBER 
%token EQUALS GE LE ET NEV NEVT INC ETT DEC
%token BREAK CASE CATCH CLASS CONST CONTINUE DEBUGGER DEFAULT DELETE DO ELSE EXPORT
%token EXTENDS FINALLY FOR FUNCTION IF IMPORT IN INSTANCEOF NEW RETURN SUPER SWITCH
%token THIS THROW TRY TYPEOF VAR VOID WITH YIELD COLON PLUSEQUALS MINUSEQUALS MULTIPLYEQUALS DIVIDEEQUALS
%token SEMICOLON QUESTIONMARK OR AND APOSTROPHE LEFTSHIFT LEFTSHIFTEQUAL RIGHTSHIFT RIGHTSHIFTEQUAL LOGICRIGHTSHIFT LOGICRIGHTSHIFTEQUAL BINANDEQUAL BINOREQUAL
%token BINXOREQUAL SHIFTTO
%token <name> STRINGLITERAL
%token <num> DecimalLiteral
%token <num> BinaryIntegerLiteral
%token <num> BOOLEANLITERAL
%token NULLLITERAL

%type <e> Identifier
%type <e> IdentifierReference PrimaryExpression MemberExpression NewExpression Expression AssignmentExpression ConditionalExpression LogicalORExpression LogicalANDExpression BitwiseORExpression BitwiseXORExpression BitwiseANDExpression EqualityExpression RelationalExpression ShiftExpression AdditiveExpression MultiplicativeExpression UnaryExpression PostfixExpression LeftHandSideExpression 
%type <s> Statement ExpressionStatement StatementList

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left '+' '-'
%left '*' '/' '%'

%%

Script : ScriptBody
	;

ScriptBody: StatementList
	;


StatementList: Statement { root = $1;}
	     | StatementList Statement
	;

BlockStatement: Block
			;
Block: LBRACE StatementList RBRACE
			;	

Statement: BlockStatement
			| ExpressionStatement {$$ = $1;}
			| VariableStatement
			| IfStatement
            | BreakableStatement
			| ContinueStatement
			| BreakStatement
			| ReturnStatement
			| WithStatement
	;

WithStatement: WITH LPARAM Expression RPARAM Statement
			   ;

ReturnStatement: RETURN SEMICOLON
				 ;

BreakStatement: BREAK SEMICOLON
				;

ContinueStatement: CONTINUE SEMICOLON
				  ;

BreakableStatement: IterationStatement
			| SwitchStatement
                        ;

SwitchStatement: SWITCH LPARAM Expression RPARAM CaseBlock;

CaseBlock: LBRACE RBRACE
			| LBRACE CaseClauses RBRACE
			| LBRACE DefaultClause RBRACE
			| LBRACE CaseClauses DefaultClause RBRACE
			| LBRACE DefaultClause CaseClauses RBRACE
			| LBRACE CaseClauses DefaultClause CaseClauses RBRACE
		;

CaseClauses: CaseClause
			| CaseClauses CaseClause
		;

CaseClause: CASE Expression COLON
			| CASE Expression COLON StatementList
		;

DefaultClause: DEFAULT COLON
			| DEFAULT COLON StatementList
		;


IterationStatement: WHILE LPARAM Expression RPARAM Statement
		  | DO Statement WHILE LPARAM Expression RPARAM SEMICOLON
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

ExpressionStatement: Expression SEMICOLON {$$ = new ExpressionStatement($1);}
	;

Expression: AssignmentExpression {$$ = $1;}
	;

AssignmentExpression: LeftHandSideExpression EQUALS AssignmentExpression {$$ = new AssignmentExpression($1, $3);}
		    | ConditionalExpression
		    ;

ConditionalExpression: LogicalORExpression {$$ = $1;}
			| LogicalORExpression QUESTIONMARK AssignmentExpression COLON AssignmentExpression
		     ;

LogicalORExpression: LogicalANDExpression {$$ = $1;}
			| LogicalANDExpression OR BitwiseORExpression
		   ;

LogicalANDExpression: BitwiseORExpression {$$ = $1;}
			| LogicalANDExpression AND BitwiseORExpression
		    ;

BitwiseORExpression: BitwiseXORExpression {$$ = $1;}
			| BitwiseORExpression '|' BitwiseXORExpression
		    ;

BitwiseXORExpression: BitwiseANDExpression {$$ = $1;}
			| BitwiseXORExpression '^' BitwiseANDExpression
		    ;
			
BitwiseANDExpression: EqualityExpression {$$ = $1;}
			| BitwiseANDExpression '&' EqualityExpression
		    ;

EqualityExpression: RelationalExpression {$$ = $1;}
			| EqualityExpression ET RelationalExpression
			| EqualityExpression NEV RelationalExpression
			| EqualityExpression NEVT RelationalExpression
			| EqualityExpression ETT RelationalExpression

		 ;

RelationalExpression: ShiftExpression {$$ = $1;}
			| RelationalExpression '<' ShiftExpression
			| RelationalExpression '>' ShiftExpression
			| RelationalExpression LE ShiftExpression
			| RelationalExpression GE ShiftExpression
			| RelationalExpression INSTANCEOF ShiftExpression
			| RelationalExpression IN ShiftExpression
		    ;

ShiftExpression: AdditiveExpression {$$ = $1;}
			| ShiftExpression LEFTSHIFT AdditiveExpression
			| ShiftExpression RIGHTSHIFT AdditiveExpression
			| ShiftExpression LOGICRIGHTSHIFT AdditiveExpression
			;


AdditiveExpression: MultiplicativeExpression {$$ = $1;}
			| AdditiveExpression '+' MultiplicativeExpression
			| AdditiveExpression '-' MultiplicativeExpression
			;

MultiplicativeExpression: UnaryExpression {$$ = $1;}
			| MultiplicativeExpression MultiplicativeOperator UnaryExpression
			;

UnaryExpression: PostfixExpression {$$ = $1;}
			| DELETE UnaryExpression
			| '+' UnaryExpression
			| '-' UnaryExpression
			| INC UnaryExpression
			| DEC UnaryExpression
			;

PostfixExpression: LeftHandSideExpression {$$ = $1;}
		 ;

LeftHandSideExpression: NewExpression {$$ = $1;}
		      ;

NewExpression: MemberExpression {$$ = $1;}
	      ;

MemberExpression: PrimaryExpression {$$ = $1;}
		;

PrimaryExpression: IdentifierReference {$$ = $1;}
		 | Literal
		 ;

IdentifierReference: Identifier {$$ = $1;}
		   ;

Identifier: IDENTIFIERNAME     { $$ = new IdentifierExpression($1); }
	  ;

Literal: NumericLiteral
	|STRINGLITERAL
	|NULLLITERAL
	|BOOLEANLITERAL
	;

NumericLiteral: DecimalLiteral
		| BinaryIntegerLiteral
	      ;
		  
MultiplicativeOperator: '*' | '/' | '%'
			;


%%

/*
int main(int argc, char* argv[])
{
	if (argc >1)
		yyin = fopen(argv[1], "r");
	else
		yyin = stdin;
	yyparse();
}

*/