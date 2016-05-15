
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

	#include <stdio.h>
	#include "Node.h"
	#include "Statement.h"
	#include "VariableStatement.h"
	#include "IfStatement.h"
	#include "Expression.h"
	#include "ExpressionStatement.h"
	#include "IdentifierExpression.h"
	#include "AssignmentExpression.h"
	#include "AdditiveExpression.h"
	#include "MultiplicativeExpression.h"
	#include "NumericLiteralExpression.h"
	#include "ForInStatement.h"
	#include "StringLiteral.h"
	//#include "BooleanLiteral.h"
	#include "WhileStatement.h"
	//#include "DoWhileStatement.h"
	#include "WithStatement.h"
	int yylex();
	extern FILE *yyin;
	void yyerror(char*);
	extern "C" int yywrap();
	Statement *root;


/* Line 189 of yacc.c  */
#line 100 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     WHILE = 258,
     LPARAM = 259,
     RPARAM = 260,
     LBRACE = 261,
     RBRACE = 262,
     IDENTIFIERNAME = 263,
     NUMBER = 264,
     EQUALS = 265,
     GE = 266,
     LE = 267,
     ET = 268,
     NEV = 269,
     NEVT = 270,
     INC = 271,
     ETT = 272,
     DEC = 273,
     BREAK = 274,
     CASE = 275,
     CATCH = 276,
     CLASS = 277,
     CONST = 278,
     CONTINUE = 279,
     DEBUGGER = 280,
     DEFAULT = 281,
     DELETE = 282,
     DO = 283,
     ELSE = 284,
     EXPORT = 285,
     EXTENDS = 286,
     FINALLY = 287,
     FOR = 288,
     FUNCTION = 289,
     IF = 290,
     IMPORT = 291,
     IN = 292,
     INSTANCEOF = 293,
     NEW = 294,
     RETURN = 295,
     SUPER = 296,
     SWITCH = 297,
     THIS = 298,
     THROW = 299,
     TRY = 300,
     TYPEOF = 301,
     VAR = 302,
     VOID = 303,
     WITH = 304,
     YIELD = 305,
     COLON = 306,
     PLUSEQUALS = 307,
     MINUSEQUALS = 308,
     MULTIPLYEQUALS = 309,
     DIVIDEEQUALS = 310,
     SEMICOLON = 311,
     QUESTIONMARK = 312,
     OR = 313,
     AND = 314,
     APOSTROPHE = 315,
     LEFTSHIFT = 316,
     LEFTSHIFTEQUAL = 317,
     RIGHTSHIFT = 318,
     RIGHTSHIFTEQUAL = 319,
     LOGICRIGHTSHIFT = 320,
     LOGICRIGHTSHIFTEQUAL = 321,
     BINANDEQUAL = 322,
     BINOREQUAL = 323,
     BINXOREQUAL = 324,
     SHIFTTO = 325,
     STRINGLITERAL = 326,
     DECIMALLITERAL = 327,
     BINARYINTEGERLITERAL = 328,
     BOOLEANLITERAL = 329,
     NULLLITERAL = 330,
     LOWER_THAN_ELSE = 331
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 26 "parser.y"

    Statement *s;
	vector<Statement*> *stmts;
	vector<Expression*> *exprs;
	Expression *e;
	double num;
	char *name;



/* Line 214 of yacc.c  */
#line 223 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 235 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  83
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   340

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    81,    85,     2,
       2,     2,    79,    77,    82,    78,     2,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      86,     2,    87,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    83,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    14,    18,    20,
      22,    24,    26,    28,    30,    32,    34,    36,    42,    45,
      48,    51,    53,    55,    61,    64,    68,    72,    77,    82,
      88,    90,    93,    97,   102,   105,   109,   111,   113,   121,
     127,   135,   143,   149,   153,   155,   159,   162,   164,   167,
     170,   172,   176,   178,   180,   186,   188,   192,   194,   198,
     200,   204,   206,   210,   212,   216,   218,   222,   226,   230,
     234,   236,   240,   244,   248,   252,   256,   260,   262,   266,
     270,   274,   276,   280,   284,   286,   290,   294,   298,   300,
     303,   306,   309,   312,   315,   317,   319,   321,   323,   325,
     327,   329,   331,   333,   335,   337,   339,   341
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      89,     0,    -1,    90,    -1,    91,    -1,    94,    -1,    91,
      94,    -1,    93,    -1,     6,    91,     7,    -1,    92,    -1,
     113,    -1,   109,    -1,   108,    -1,    99,    -1,    98,    -1,
      97,    -1,    96,    -1,    95,    -1,    49,     4,   114,     5,
      94,    -1,    40,    56,    -1,    19,    56,    -1,    24,    56,
      -1,   105,    -1,   100,    -1,    42,     4,   114,     5,   101,
      -1,     6,     7,    -1,     6,   102,     7,    -1,     6,   104,
       7,    -1,     6,   102,   104,     7,    -1,     6,   104,   102,
       7,    -1,     6,   102,   104,   102,     7,    -1,   103,    -1,
     102,   103,    -1,    20,   114,    51,    -1,    20,   114,    51,
      91,    -1,    26,    51,    -1,    26,    51,    91,    -1,   106,
      -1,   107,    -1,    33,     4,   129,    37,   114,     5,    94,
      -1,     3,     4,   114,     5,    94,    -1,    28,    94,     3,
       4,   114,     5,    56,    -1,    35,     4,   114,     5,    94,
      29,    94,    -1,    35,     4,   114,     5,    94,    -1,    47,
     110,    56,    -1,   111,    -1,   110,    82,   111,    -1,   134,
     112,    -1,   134,    -1,    10,   115,    -1,   114,    56,    -1,
     115,    -1,   129,    10,   115,    -1,   116,    -1,   117,    -1,
     117,    57,   115,    51,   115,    -1,   118,    -1,   118,    58,
     119,    -1,   119,    -1,   118,    59,   119,    -1,   120,    -1,
     119,    83,   120,    -1,   121,    -1,   120,    84,   121,    -1,
     122,    -1,   121,    85,   122,    -1,   123,    -1,   122,    13,
     123,    -1,   122,    14,   123,    -1,   122,    15,   123,    -1,
     122,    17,   123,    -1,   124,    -1,   123,    86,   124,    -1,
     123,    87,   124,    -1,   123,    12,   124,    -1,   123,    11,
     124,    -1,   123,    38,   124,    -1,   123,    37,   124,    -1,
     125,    -1,   124,    61,   125,    -1,   124,    63,   125,    -1,
     124,    65,   125,    -1,   126,    -1,   125,    77,   126,    -1,
     125,    78,   126,    -1,   127,    -1,   126,    79,   127,    -1,
     126,    80,   127,    -1,   126,    81,   127,    -1,   128,    -1,
      27,   127,    -1,    77,   127,    -1,    78,   127,    -1,    16,
     127,    -1,    18,   127,    -1,   129,    -1,   130,    -1,   131,
      -1,   132,    -1,   133,    -1,   135,    -1,   134,    -1,     8,
      -1,   136,    -1,    71,    -1,    75,    -1,    74,    -1,    72,
      -1,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    67,    71,    72,    75,    77,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    91,    94,    97,
     100,   103,   104,   107,   109,   110,   111,   112,   113,   114,
     117,   118,   121,   122,   125,   126,   130,   131,   132,   134,
     136,   139,   140,   143,   146,   147,   150,   151,   154,   157,
     160,   163,   164,   167,   168,   171,   172,   175,   176,   179,
     180,   183,   184,   187,   188,   191,   192,   193,   194,   195,
     198,   199,   200,   201,   202,   203,   204,   207,   208,   209,
     210,   214,   215,   216,   219,   220,   221,   222,   225,   226,
     227,   228,   229,   230,   233,   236,   239,   242,   245,   246,
     249,   252,   255,   256,   257,   258,   261,   262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "LPARAM", "RPARAM", "LBRACE",
  "RBRACE", "IDENTIFIERNAME", "NUMBER", "EQUALS", "GE", "LE", "ET", "NEV",
  "NEVT", "INC", "ETT", "DEC", "BREAK", "CASE", "CATCH", "CLASS", "CONST",
  "CONTINUE", "DEBUGGER", "DEFAULT", "DELETE", "DO", "ELSE", "EXPORT",
  "EXTENDS", "FINALLY", "FOR", "FUNCTION", "IF", "IMPORT", "IN",
  "INSTANCEOF", "NEW", "RETURN", "SUPER", "SWITCH", "THIS", "THROW", "TRY",
  "TYPEOF", "VAR", "VOID", "WITH", "YIELD", "COLON", "PLUSEQUALS",
  "MINUSEQUALS", "MULTIPLYEQUALS", "DIVIDEEQUALS", "SEMICOLON",
  "QUESTIONMARK", "OR", "AND", "APOSTROPHE", "LEFTSHIFT", "LEFTSHIFTEQUAL",
  "RIGHTSHIFT", "RIGHTSHIFTEQUAL", "LOGICRIGHTSHIFT",
  "LOGICRIGHTSHIFTEQUAL", "BINANDEQUAL", "BINOREQUAL", "BINXOREQUAL",
  "SHIFTTO", "STRINGLITERAL", "DECIMALLITERAL", "BINARYINTEGERLITERAL",
  "BOOLEANLITERAL", "NULLLITERAL", "LOWER_THAN_ELSE", "'+'", "'-'", "'*'",
  "'/'", "'%'", "','", "'|'", "'^'", "'&'", "'<'", "'>'", "$accept",
  "Script", "ScriptBody", "StatementList", "BlockStatement", "Block",
  "Statement", "WithStatement", "ReturnStatement", "BreakStatement",
  "ContinueStatement", "BreakableStatement", "SwitchStatement",
  "CaseBlock", "CaseClauses", "CaseClause", "DefaultClause",
  "IterationStatement", "WhileStatement", "DoWhileStatement",
  "IfStatement", "VariableStatement", "VariableDeclarationList",
  "VariableDeclaration", "Initialiser", "ExpressionStatement",
  "Expression", "AssignmentExpression", "ConditionalExpression",
  "LogicalORExpression", "LogicalANDExpression", "BitwiseORExpression",
  "BitwiseXORExpression", "BitwiseANDExpression", "EqualityExpression",
  "RelationalExpression", "ShiftExpression", "AdditiveExpression",
  "MultiplicativeExpression", "UnaryExpression", "PostfixExpression",
  "LeftHandSideExpression", "NewExpression", "MemberExpression",
  "PrimaryExpression", "IdentifierReference", "Identifier", "Literal",
  "NumericLiteral", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,    43,    45,    42,
      47,    37,    44,   124,    94,    38,    60,    62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    91,    91,    92,    93,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    95,    96,    97,
      98,    99,    99,   100,   101,   101,   101,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   105,   106,
     107,   108,   108,   109,   110,   110,   111,   111,   112,   113,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   122,   122,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     124,   125,   125,   125,   126,   126,   126,   126,   127,   127,
     127,   127,   127,   127,   128,   129,   130,   131,   132,   132,
     133,   134,   135,   135,   135,   135,   136,   136
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     2,     2,
       2,     1,     1,     5,     2,     3,     3,     4,     4,     5,
       1,     2,     3,     4,     2,     3,     1,     1,     7,     5,
       7,     7,     5,     3,     1,     3,     2,     1,     2,     2,
       1,     3,     1,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   106,   107,   105,
     104,     0,     0,     0,     2,     3,     8,     6,     4,    16,
      15,    14,    13,    12,    22,    21,    36,    37,    11,    10,
       9,     0,    50,    52,    53,    55,    57,    59,    61,    63,
      65,    70,    77,    81,    84,    88,    94,    95,    96,    97,
      98,   100,    99,   102,     0,     0,    92,    94,    93,    19,
      20,    89,     0,     0,     0,    18,     0,     0,    44,    47,
       0,    90,    91,     1,     5,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     0,    43,     0,     0,
      46,     0,     0,    56,    58,    60,    62,    64,    66,    67,
      68,    69,    74,    73,    76,    75,    71,    72,    78,    79,
      80,    82,    83,    85,    86,    87,    51,     0,     0,     0,
       0,     0,    45,    48,     0,     0,    39,     0,     0,    42,
       0,    23,    17,    54,     0,     0,     0,    24,     0,     0,
       0,    30,     0,    40,    38,    41,     0,    34,    25,    31,
       0,    26,     0,    32,    35,    27,     0,    28,    33,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   161,   170,   171,   172,    35,    36,    37,
      38,    39,    77,    78,   120,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    67,    57,    58,    59,    60,    61,    62,    63
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -132
static const yytype_int16 yypact[] =
{
     262,    18,   262,  -132,    10,    10,   -18,    -7,    10,   262,
      48,    65,    16,    71,    95,   101,  -132,  -132,  -132,  -132,
    -132,    10,    10,    45,  -132,   262,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,    56,  -132,  -132,    57,    20,    30,    34,    35,    53,
       9,    41,    12,   -75,  -132,  -132,   118,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,    10,   189,  -132,  -132,  -132,  -132,
    -132,  -132,   126,    26,    10,  -132,    10,   -46,  -132,   120,
      10,  -132,  -132,  -132,  -132,  -132,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,   127,  -132,   129,    94,   130,   131,  -132,    95,    10,
    -132,   132,    83,    30,    30,    34,    35,    53,     9,     9,
       9,     9,    41,    41,    41,    41,    41,    41,    12,    12,
      12,   -75,   -75,  -132,  -132,  -132,  -132,   262,    10,    10,
     262,   133,  -132,  -132,   262,    10,  -132,   135,   136,   109,
       7,  -132,  -132,  -132,    86,   262,   262,  -132,    10,    92,
      28,  -132,     4,  -132,  -132,  -132,    93,   262,  -132,  -132,
      33,  -132,    36,   262,   262,  -132,    37,  -132,   262,  -132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,    -1,  -132,  -132,     6,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -130,  -131,   -25,  -132,  -132,  -132,
    -132,  -132,  -132,    39,  -132,  -132,   -57,   -78,  -132,  -132,
    -132,    21,    62,    68,    55,    29,   -38,    23,   -12,     8,
    -132,     0,  -132,  -132,  -132,  -132,   -11,  -132,  -132
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      56,    65,    56,    79,   107,   108,   109,   111,   122,    56,
     117,   181,    66,    68,   167,    72,    71,   115,     3,   116,
      96,    97,    64,   121,   168,    56,     4,   168,     5,    81,
      82,    84,   146,   169,     3,   178,   118,     8,    69,   179,
     185,   153,   182,   187,   189,    83,    98,    99,   168,    70,
     186,   179,    73,   168,   169,   179,   168,   168,   132,   133,
     134,   135,   136,   137,    56,    56,    92,    93,    94,    74,
      95,    84,    75,   114,    56,    76,    56,   163,    87,    88,
      56,    16,    17,    18,    19,    20,    56,    21,    22,   105,
     106,   157,   158,   141,   142,   100,   101,    16,    17,    18,
      19,    20,   102,     3,   103,    80,   104,    79,   123,   124,
      56,   176,    85,    89,    86,   143,   144,   145,    90,    56,
      91,   128,   129,   130,   131,   138,   139,   140,   110,   113,
     119,   149,   147,   148,   155,   150,   151,   154,   166,   160,
     164,   165,   173,   177,   183,   180,   127,    56,    56,    56,
      56,   125,     0,   156,    56,    56,   159,   152,   126,     0,
     162,     0,     0,     0,     0,    56,    56,     0,    56,     0,
       0,   174,   175,     0,     0,     0,   184,    56,     0,     0,
       0,     0,   188,    56,    56,     0,     0,     0,    56,     0,
      84,     0,     1,     0,    84,     2,   112,     3,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     5,     6,     0,
       0,     0,     0,     7,     0,     0,     8,     9,     0,     0,
       0,     0,    10,     0,    11,     0,     0,     0,     0,    12,
       0,    13,     0,     0,     0,     0,    14,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,    18,    19,    20,     1,    21,    22,     2,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       5,     6,     0,     0,     0,     0,     7,     0,     0,     8,
       9,     0,     0,     0,     0,    10,     0,    11,     0,     0,
       0,     0,    12,     0,    13,     0,     0,     0,     0,    14,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,    20,     0,    21,
      22
};

static const yytype_int16 yycheck[] =
{
       0,     2,     2,    14,    79,    80,    81,    64,    86,     9,
      56,     7,     4,     5,     7,     9,     8,    74,     8,    76,
      11,    12,     4,    80,    20,    25,    16,    20,    18,    21,
      22,    25,   110,    26,     8,     7,    82,    27,    56,   170,
       7,   119,   172,     7,     7,     0,    37,    38,    20,    56,
     180,   182,     4,    20,    26,   186,    20,    20,    96,    97,
      98,    99,   100,   101,    64,    65,    13,    14,    15,     4,
      17,    65,    56,    73,    74,     4,    76,   155,    58,    59,
      80,    71,    72,    73,    74,    75,    86,    77,    78,    77,
      78,   148,   149,   105,   106,    86,    87,    71,    72,    73,
      74,    75,    61,     8,    63,     4,    65,   118,    87,    88,
     110,   168,    56,    83,    57,   107,   108,   109,    84,   119,
      85,    92,    93,    94,    95,   102,   103,   104,    10,     3,
      10,    37,     5,     4,    51,     5,     5,     5,    29,     6,
       5,     5,    56,    51,    51,   170,    91,   147,   148,   149,
     150,    89,    -1,   147,   154,   155,   150,   118,    90,    -1,
     154,    -1,    -1,    -1,    -1,   165,   166,    -1,   168,    -1,
      -1,   165,   166,    -1,    -1,    -1,   177,   177,    -1,    -1,
      -1,    -1,   183,   183,   184,    -1,    -1,    -1,   188,    -1,
     184,    -1,     3,    -1,   188,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    18,    19,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    33,    -1,    35,    -1,    -1,    -1,    -1,    40,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,     3,    77,    78,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      18,    19,    -1,    -1,    -1,    -1,    24,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    -1,
      -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,    77,
      78
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     8,    16,    18,    19,    24,    27,    28,
      33,    35,    40,    42,    47,    49,    71,    72,    73,    74,
      75,    77,    78,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   105,   106,   107,   108,   109,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     4,    91,   127,   129,   127,    56,
      56,   127,    94,     4,     4,    56,     4,   110,   111,   134,
       4,   127,   127,     0,    94,    56,    57,    58,    59,    83,
      84,    85,    13,    14,    15,    17,    11,    12,    37,    38,
      86,    87,    61,    63,    65,    77,    78,    79,    80,    81,
      10,   114,     7,     3,   129,   114,   114,    56,    82,    10,
     112,   114,   115,   119,   119,   120,   121,   122,   123,   123,
     123,   123,   124,   124,   124,   124,   124,   124,   125,   125,
     125,   126,   126,   127,   127,   127,   115,     5,     4,    37,
       5,     5,   111,   115,     5,    51,    94,   114,   114,    94,
       6,   101,    94,   115,     5,     5,    29,     7,    20,    26,
     102,   103,   104,    56,    94,    94,   114,    51,     7,   103,
     104,     7,   102,    51,    91,     7,   102,     7,    91,     7
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    {root = (yyvsp[(1) - (1)].s);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 67 "parser.y"
    {(yyval.s)=new CompoundStatement((yyvsp[(1) - (1)].stmts));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    {(yyval.stmts)=new vector<Statement*>(); (yyval.stmts)->push_back((yyvsp[(1) - (1)].s));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    { (yyval.stmts) = (yyvsp[(1) - (2)].stmts); (yyval.stmts)->push_back((yyvsp[(2) - (2)].s));    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    {(yyval.s)=(yyvsp[(1) - (1)].s);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    {(yyval.s)=new CompoundStatement((yyvsp[(2) - (3)].stmts));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    {(yyval.s)= new WithStatement((yyvsp[(3) - (5)].e),(yyvsp[(5) - (5)].s));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    {(yyval.s)=(yyvsp[(1) - (1)].s);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    {(yyval.s)=new ForInStatement((yyvsp[(3) - (7)].e),(yyvsp[(5) - (7)].e),(yyvsp[(7) - (7)].s));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {(yyval.s)=new WhileStatement((yyvsp[(3) - (5)].e),(yyvsp[(5) - (5)].s));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {(yyval.s)=new IfStatement((yyvsp[(3) - (7)].e),(yyvsp[(5) - (7)].s),(yyvsp[(7) - (7)].s));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {(yyval.s)=new IfStatement((yyvsp[(3) - (5)].e),(yyvsp[(5) - (5)].s),NULL);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {(yyval.s)=new VariableStatement((yyvsp[(2) - (3)].exprs));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    {(yyval.exprs)=new vector<Expression*>(); (yyval.exprs)->push_back((yyvsp[(1) - (1)].e));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {(yyval.exprs)=(yyvsp[(1) - (3)].exprs); (yyval.exprs)->push_back((yyvsp[(3) - (3)].e));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {(yyval.e) = new VariableExpression((yyvsp[(1) - (2)].e),(yyvsp[(2) - (2)].e));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    {(yyval.e)=(yyvsp[(1) - (1)].e);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {(yyval.e)=(yyvsp[(2) - (2)].e);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {(yyval.s) = new ExpressionStatement((yyvsp[(1) - (2)].e));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {(yyval.e) = new AssignmentExpression((yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    {(yyval.e) = new AdditiveExpression("+",(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e));}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {(yyval.e) = new AdditiveExpression("-",(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e));}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {(yyval.e) = new MultiplicativeExpression("*",(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e));}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    {(yyval.e) = new MultiplicativeExpression("/",(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e));}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {(yyval.e) = new MultiplicativeExpression("%",(yyvsp[(1) - (3)].e),(yyvsp[(3) - (3)].e));}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    { (yyval.e) = new IdentifierExpression((yyvsp[(1) - (1)].name)); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    {(yyval.e) = (yyvsp[(1) - (1)].e);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    {(yyval.e)=new StringLiteral((yyvsp[(1) - (1)].name));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
    {(yyval.e) = new NumericLiteralExpression((yyvsp[(1) - (1)].num));;}
    break;



/* Line 1455 of yacc.c  */
#line 2058 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 266 "parser.y"


int yywrap()
{
    return 1;
}

/*
int main(int argc, char* argv[])
{
	if (argc >1)
		yyin = fopen(argv[1], "r");
	else
		yyin = stdin;
	yyparse();
}

*/
