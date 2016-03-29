
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
     TRUE = 294,
     FALSE = 295,
     ENUM = 296,
     AWAIT = 297,
     NULLKEY = 298,
     THIS = 299,
     THROW = 300,
     TRY = 301,
     TYPEOF = 302,
     VAR = 303,
     VOID = 304,
     WITH = 305,
     YIELD = 306,
     COLON = 307,
     PLUSEQUALS = 308,
     MINUSEQUALS = 309,
     MULTIPLYEQUALS = 310,
     DIVIDEEQUALS = 311,
     SEMICOLON = 312,
     QUESTIONMARK = 313,
     OR = 314,
     AND = 315,
     APOSTROPHE = 316,
     LEFTSHIFTEQUAL = 317,
     RIGHTSHIFTEQUAL = 318,
     LOGICRIGHTSHIFTEQUAL = 319,
     BINANDEQUAL = 320,
     BINOREQUAL = 321,
     BINXOREQUAL = 322,
     SHIFTTO = 323,
     STRING = 324,
     CONSOLE = 325,
     LOG = 326,
     DECIMALINTEGER = 327
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 10 "parser.y"

	int num;
	char *name;



/* Line 1676 of yacc.c  */
#line 131 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


