#include <String> 
#include "Node.h"
#include "Statement.h"
#include "Expression.h"
#include "AssignmentExpression.h"
#include "IdentifierExpression.h"
#include "IntegerLiteralExpression.h"

using namespace std;

int yyparse();
extern FILE *yyin;
extern Statement *root;

int main(int argc, char* argv[])
{
	yyin = fopen(argv[1], "r");
	yyparse();
	root->DumpValue(1);
}