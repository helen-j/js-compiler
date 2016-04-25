%{
	#include <stdio.h>
	#include "Node.h"
	#include "Statement.h"
	#include "VariableStatement.h"
	#include "IfStatement.h"
	#include "Expression.h"
	#include "ExpressionStatement.h"
	#include "IdentifierExpression.h"
	#include "AssignmentExpression.h"
	#include "AdditiveExpression.h"
	#include "MultiplicativeExpression.h"
	#include "NumericLiteralExpression.h"
	#include "StringLiteral.h"
	#include "BooleanLiteral.h"
	#include "WhileStatement.h"
	#include "DoWhileStatement.h"
	int yylex();
	extern FILE *yyin;
	void yyerror(char*);
	extern "C" int yywrap();
	Statement *root;
%}
%union {
    Statement *s;
	vector<Statement*> *stmts;
	vector<Expression*> *exprs;
	Expression *e;
	double num;
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
%token <num> DECIMALLITERAL
%token <num> BINARYINTEGERLITERAL
%token <num> BOOLEANLITERAL
%token NULLLITERAL

%type <e> Identifier IdentifierReference VariableDeclaration Initialiser
%type <e> NumericLiteral Literal PrimaryExpression MemberExpression NewExpression Expression AssignmentExpression ConditionalExpression LogicalORExpression LogicalANDExpression BitwiseORExpression BitwiseXORExpression BitwiseANDExpression EqualityExpression RelationalExpression ShiftExpression AdditiveExpression MultiplicativeExpression UnaryExpression PostfixExpression LeftHandSideExpression 
%type <s> Statement ExpressionStatement IfStatement IterationStatement BlockStatement Block VariableStatement ScriptBody Script WhileStatement DoWhileStatement BreakableStatement
%type <exprs> VariableDeclarationList
%type <stmts> StatementList 

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left '+' '-'
%left '*' '/' '%'

%%

Script : ScriptBody			{root = $1;}
	;

ScriptBody: StatementList	{$$=new CompoundStatement($1);}
	;


StatementList: Statement	 {$$=new vector<Statement*>(); $$->push_back($1);}
	     | StatementList Statement   { $$ = $1; $$->push_back($2);    }
	;

BlockStatement: Block			 {$$=$1;}
			;
Block: LBRACE StatementList RBRACE	{$$=new CompoundStatement($2);}
			;	

Statement:  BlockStatement		  {$$ = $1;}
			| ExpressionStatement {$$ = $1;}
			| VariableStatement   {$$ = $1;}
			| IfStatement		  {$$ = $1;}
            | BreakableStatement  {$$ = $1;}
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

BreakableStatement: IterationStatement {$$=$1;}
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


IterationStatement: WhileStatement {$$ = $1;}
		  	| DoWhileStatement {$$ = $1;}
                        ;
WhileStatement: WHILE LPARAM Expression RPARAM Statement {$$=new WhileStatement($3,$5);}
			;
DoWhileStatement: DO Statement WHILE LPARAM Expression RPARAM SEMICOLON {$$=new DoWhileStatement($2,$5);}
			;

IfStatement: IF LPARAM Expression RPARAM Statement ELSE Statement	{$$=new IfStatement($3,$5,$7);}
			| IF LPARAM Expression RPARAM Statement %prec LOWER_THAN_ELSE {$$=new IfStatement($3,$5,NULL);}
			;

VariableStatement: VAR VariableDeclarationList SEMICOLON  {$$=new VariableStatement($2);}
		 ;

VariableDeclarationList: VariableDeclaration  {$$=new vector<Expression*>(); $$->push_back($1);}
			| VariableDeclarationList ',' VariableDeclaration {$$=$1; $$->push_back($3);}
			;

VariableDeclaration: Identifier Initialiser  {$$ = new VariableExpression($1,$2);}
		   | Identifier {$$=$1;}
		   ;

Initialiser: EQUALS AssignmentExpression  {$$=$2;}
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
			| AdditiveExpression '+' MultiplicativeExpression	{$$ = new AdditiveExpression("+",$1,$3)}
			| AdditiveExpression '-' MultiplicativeExpression	{$$ = new AdditiveExpression("-",$1,$3)}
			;

MultiplicativeExpression: UnaryExpression {$$ = $1;}
			| MultiplicativeExpression '*' UnaryExpression {$$ = new MultiplicativeExpression("*",$1,$3)}
			| MultiplicativeExpression '/' UnaryExpression {$$ = new MultiplicativeExpression("/",$1,$3)}
			| MultiplicativeExpression '%' UnaryExpression {$$ = new MultiplicativeExpression("%",$1,$3)}
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
		 | Literal {$$ = $1;}
		 ;

IdentifierReference: Identifier {$$ = $1;}
		   ;

Identifier: IDENTIFIERNAME     { $$ = new IdentifierExpression($1); }
	  ;

Literal: NumericLiteral  {$$ = $1;}
	|STRINGLITERAL {$$=new StringLiteral($1);}
	|NULLLITERAL   
	|BOOLEANLITERAL {$$=new BooleanLiteral($1);}
	;

NumericLiteral: DECIMALLITERAL {$$ = new NumericLiteralExpression($1);}
		| BINARYINTEGERLITERAL
	      ;
		  

%%

int yywrap()
{
    return 1;
}

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