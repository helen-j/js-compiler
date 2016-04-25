#include "Statement.h"

using namespace std;

int yyparse();
extern FILE *yyin;
extern Statement *root;

int main(int argc, char* argv[])
{
	yyin = fopen(argv[1], "r");
	//yyin = fopen("YOURPATH\testcases", "r");
	yyparse();
	root->DumpValue(0);
	//getchar();
}