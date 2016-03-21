enum yytokentype {
	WHILE = 258,
	LPARAM = 259,
	RPARAM = 260,
	IDENT = 261,
	NUMBER = 262,
	EQUALS = 263,
	GE = 264,
	LE = 265,
	ET = 266,
	NEV = 267,
	NEVT = 268,
	INC = 269,
	BREAK = 270,
	CASE = 271,
	CATCH = 272,
	CLASS = 273,
	CONST = 274,
	CONTINUE = 275,
	DEBUGGER = 276,
	DEFAULT = 277,
	DELETE = 278,
	DO = 279,
	ELSE = 280,
	EXPORT = 281,
	EXTENDS = 282,
	FINALLY = 283,
	FOR = 284,
	FUNCTION = 285,
	IF = 286,
	IMPORT = 287,
	IN = 288,
	INSTANCEOF = 289,
	NEW = 290,
	RETURN = 291,
	SUPER = 292,
	SWITCH = 293,
	THIS = 294,
	THROW = 295,
	TRY = 296,
	TYPEOF = 297,
	VAR = 298,
	VOID = 299,
	WITH = 300,
	YIELD = 301,
	COLON = 302,
	PLUSEQUALS = 303,
	MINUSEQUALS = 304,
	MULTIPLYEQUALS = 305,
	DIVIDEEQUALS = 306,
	SEMICOLON = 307,
	QUESTIONMARK = 308,
	OR = 309,
	AND = 310,
	APOSTROPHE = 311,
	LEFTSHIFTEQUAL = 312,
	RIGHTSHIFTEQUAL = 313,
	LOGICRIGHTSHIFTEQUAL = 314,
	BINANDEQUAL = 315,
	BINOREQUAL = 316,
	BINXOREQUAL = 317,
	SHIFTTO = 318,
	STRING = 319,
	CONSOLE = 320,
	LOG = 321
};

typedef union YYSTYPE
{
  char* name;
  int num;
} YYSTYPE;

extern YYSTYPE yylval;
