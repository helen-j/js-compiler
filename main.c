#include <stdio.h>
#include "y.tab.h"

YYSTYPE yylval;

int yywrap(void) 
{
 return 1;
}

int yylex();

int main(int argc, char* argv[])
{
	//yyin = fopen(argv[1], "r");

	int token;
	do
	{
		token = yylex();
		printf("next token: ");
		switch (token)
		{
		case NUMBER: 
			printf("NUMBER (%d)\n", yylval.num);
			break;
		case IDENT: 
			printf("IDENTIFIER (%d)\n", yylval.name);
			break;
		case WHILE: 
			printf("WHILE\n");
			break;
		case GE: 
			printf("GE\n");
			break;
		default: 
			printf("'%c'\n", token);
			break;
		}
	}
	while (token != EOF);

	return 0;
}
