
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 26 "parser.y"

    Statement *s;
	vector<Statement*> *stmts;
	vector<Expression*> *exprs;
	Expression *e;
	double num;
	char *name;



/* Line 1676 of yacc.c  */
#line 139 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


