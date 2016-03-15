%token Number

%%

program : Number
	;

%%

int main(int argc, char* argv[])
{
	yyparse();
}