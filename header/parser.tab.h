
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
     EQUALS = 262,
     GE = 263,
     LE = 264,
     ET = 265,
     NEV = 266,
     NEVT = 267,
     INC = 268,
     BREAK = 269,
     CASE = 270,
     CATCH = 271,
     CLASS = 272,
     CONST = 273,
     CONTINUE = 274,
     DEBUGGER = 275,
     DEFAULT = 276,
     DELETE = 277,
     DO = 278,
     ELSE = 279,
     EXPORT = 280,
     EXTENDS = 281,
     FINALLY = 282,
     FOR = 283,
     FUNCTION = 284,
     IF = 285,
     IMPORT = 286,
     IN = 287,
     INSTANCEOF = 288,
     NEW = 289,
     RETURN = 290,
     SUPER = 291,
     SWITCH = 292,
     TRUE = 293,
     FALSE = 294,
     ENUM = 295,
     AWAIT = 296,
     NULLKEY = 297,
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
     LEFTSHIFTEQUAL = 316,
     RIGHTSHIFTEQUAL = 317,
     LOGICRIGHTSHIFTEQUAL = 318,
     BINANDEQUAL = 319,
     BINOREQUAL = 320,
     BINXOREQUAL = 321,
     SHIFTTO = 322,
     STRING = 323,
     CONSOLE = 324,
     LOG = 325,
     LOWER_THAN_ELSE = 326
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
#line 130 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


