enum yytokentype 
{
     WHILE = 258,
     NUMBER = 259,
	 IDENT = 260,
	 GE = 261
};

typedef union YYSTYPE
{
  char* name;
  int num;
} YYSTYPE;

extern YYSTYPE yylval;