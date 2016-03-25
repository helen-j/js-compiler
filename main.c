#include <stdio.h>
#include "y.tab.h"

YYSTYPE yylval;

FILE *yyin;

int main(int argc, char* argv[])
{
	++argv, --argc;  /* skip over program name */
	if (argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;

	int token;
	do
	{
		token = yylex();
		printf("next token: ");
		switch (token)
		{
		case STRING:
			printf("STRING (%s)\n", yylval.name);
			break;
		case NUMBER: 
			printf("NUMBER (%d)\n", yylval.num);
			break;
		case DECIMALINTEGER:
			printf("INTEGER (%d)\n", yylval.num);
			break;
		case IDENT: 
			printf("IDENTIFIER (%s)\n", yylval.name);
			break;
		case WHILE: 
			printf("WHILE\n");
			break;
		case GE: 
			printf("GE\n");
			break;
		case LE:
			printf("LE\n");
			break;
		case ET:
			printf("ET\n");
			break;
		case NEV:
			printf("NEV\n");
			break;
		case NEVT:
			printf("NEVT\n");
			break;
		case INC:
			printf("INC\n");
			break;
		case BREAK:
			printf("BREAK\n");		
			break;
		case CASE:	
			printf("CASE\n");		
			break;
		case CATCH:	
			printf("CATCH\n");		
			break;
		case CLASS:	
			printf("CLASS\n");		
			break;
		case CONST:	
			printf("CONST\n");		
			break;
		case CONTINUE:	
			printf("CONTINUE\n");		
			break;
		case DEBUGGER:	
			printf("DEBUGGER\n");		
			break;
		case DEFAULT:	
			printf("DEFAULT\n");		
			break;
		case DELETE:	
			printf("DELETE\n");		
			break;
		case DO:	
			printf("DO\n");		
			break;
		case ELSE:	
			printf("ELSE\n");		
			break;
		case EXPORT:	
			printf("EXPORT\n");		
			break;
		case EXTENDS:	
			printf("EXTENDS\n");		
			break;
		case FINALLY:	
			printf("FINALLY\n");		
			break;
		case FOR:	
			printf("FOR\n");		
			break;
		case FUNCTION:	
			printf("FUNCTION\n");		
			break;
		case IF:	
			printf("IF\n");		
			break;
		case IMPORT:	
			printf("IMPORT\n");		
			break;
		case IN:	
			printf("IN\n");		
			break;
		case INSTANCEOF:	
			printf("INSTANCEOF\n");		
			break;
		case NEW:	
			printf("NEW\n");		
			break;
		case RETURN:	
			printf("RETURN\n");		
			break;
		case SUPER:	
			printf("SUPER\n");		
			break;
		case SWITCH:	
			printf("SWITCH\n");		
			break;
		case THIS:	
			printf("THIS\n");		
			break;
		case THROW:	
			printf("THROW\n");		
			break;
		case TRY:	
			printf("TRY\n");		
			break;
		case TYPEOF:	
			printf("TYPEOF\n");		
			break;
		case VAR:	
			printf("VAR\n");		
			break;
		case VOID:	
			printf("VOID\n");		
			break;
		case WITH:	
			printf("WITH\n");		
			break;
		case YIELD:	
			printf("YIELD\n");		
			break;
		case QUESTIONMARK: 
			printf("QUESTIONMARK\n");
			break;
		case OR:
			printf("OR\n");
			break;
		case AND:
			printf("AND\n");
			break;
		case APOSTROPHE:
			printf("APOSTROPHE\n");
			break;		
		case LPARAM:
			printf("LPARAM\n");
			break;
		case RPARAM:
			printf("RPARAM\n");
			break;
		case SEMICOLON:
			printf("SEMICOLON\n");
			break;
		case LEFTSHIFTEQUAL:
			printf("LEFTSHIFTEQUAL\n");
			break;
		case RIGHTSHIFTEQUAL:
			printf("RIGHTSHIFTEQUAL\n");
			break;
		case LOGICRIGHTSHIFTEQUAL:
			printf("LOGICRIGHTSHIFTEQUAL\n");
			break;
		case BINANDEQUAL:
			printf("BINANDEQUAL\n");
			break;
		case BINOREQUAL:
			printf("BINOREQUAL\n");
			break;
		case BINXOREQUAL:
			printf("BINXOREQUAL\n");
			break;
		case SHIFTTO:
			printf("SHIFTTO\n");
			break;
		case EQUALS:
			printf("EQUAL\n");
			break;
		case COLON:
			printf("COLON\n");
		case PLUSEQUALS:
			printf("PLUSEQUALS\n");
		case MINUSEQUALS:
			printf("MINUSEQUALS\n");
		case MULTIPLYEQUALS:
			printf("MULTIPLYEQUALS\n");
		case DIVIDEEQUALS:
			printf("DIVIDEEQUALS\n"); 
		case CONSOLE:
			printf("CONSOLE\n");
		default: 
			printf("'%c'\n", token);
			break;
		}
	}
	while (token != EOF);
	yylex();
	return 0;
}
