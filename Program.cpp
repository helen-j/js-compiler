#include "Statement.h"

using namespace std;

int yyparse();
extern FILE *yyin;
extern Statement *root;

int main(int argc, char* argv[])
{
	//yyin = fopen(argv[1], "r");
	//yyin = fopen("C:\\Users\\2cody_000\\Documents\\IFN660\\js-compiler\\testcases\\test_ast.js", "r");
	//yyin = fopen("f:\\git\\testcases\\test_ast.js", "r"); 
	yyparse();
	root->DumpValue(0);
	getchar();
}