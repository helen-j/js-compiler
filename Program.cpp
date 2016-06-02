#include "Statement.h"
#include "WhileStatement.h"

using namespace std;

int yylex();
int yyparse();
extern FILE *yyin;
extern Statement *root;

int LastLabel = 0;
int WhileStatement::WhileObject = 0;

void CodeGeneration(char* inputfile, Statement* root)
{
	char* outputFilename = (char*)malloc(strlen(inputfile) + 4);
	sprintf(outputFilename, "%s.cpp", inputfile);
	FILE* outputFile = fopen(outputFilename, "w");
	//include header files
	root->emit(outputFile, "#include \"jsValue.h\"");
	root->emit(outputFile, "#include \"jsObject.h\"");
	root->emit(outputFile, "#include \"jsFunction.h\"");
	root->emit(outputFile, "#include \"jsReference.h\"");
	//main function
	root->emit(outputFile, "int main(int argc, char* argv[])");
	root->emit(outputFile, "{");
	//global environment
	root->emit(outputFile, "jsObject* global = new jsObject();");
	root->emit(outputFile, "jsObject* env = global;");
	root->GenCode(outputFile);
	root->emit(outputFile, "consolelog(GetValue(r%d));", LastLabel-1);
	root->emit(outputFile, "}"); // end of Main
}


int main(int argc, char* argv[])
{
	yyin = fopen(argv[1], "r");
	//yyin = fopen("c:\qut\projectfiles\test_ast.js","r");
	yyparse();
	root->DumpValue(0);
	CodeGeneration(argv[1], root);
}