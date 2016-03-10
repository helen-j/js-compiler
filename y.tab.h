enum yytokentype 
{
     	WHILE = 258,
     	NUMBER = 259,
	IDENT = 260,
	GE = 261,
	LE = 262,
	ET = 263,
	NEV = 264,
	NEVT = 265,
	INC = 266
};

typedef union YYSTYPE
{
  char* name;
  int num;
} YYSTYPE;

extern YYSTYPE yylval;