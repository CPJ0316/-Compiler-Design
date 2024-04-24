/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    Int = 259,
    Real = 260,
    ARRAY = 261,
    Begin = 262,
    BOOL = 263,
    CHAR = 264,
    CONST = 265,
    DECREASING = 266,
    DEFAULT = 267,
    DO = 268,
    ELSE = 269,
    END = 270,
    EXIT = 271,
    FALSE = 272,
    FOR = 273,
    FUNCTION = 274,
    GET = 275,
    IF = 276,
    INT = 277,
    LOOP = 278,
    OF = 279,
    PUT = 280,
    PROCEDURE = 281,
    REAL = 282,
    RESULT = 283,
    RETURN = 284,
    SKIP = 285,
    STRING = 286,
    TRUE = 287,
    VAR = 288,
    WHEN = 289,
    THEN = 290,
    TYPE = 291,
    ID = 292,
    String = 293,
    R_NUMBER = 294,
    I_NUMBER = 295,
    B_VALUE = 296,
    ASSIGN = 297,
    OR = 298,
    AND = 299,
    NE = 300,
    RE = 301,
    LE = 302,
    MOD = 303,
    UMINUS = 304,
    NOT = 305
  };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define Int 259
#define Real 260
#define ARRAY 261
#define Begin 262
#define BOOL 263
#define CHAR 264
#define CONST 265
#define DECREASING 266
#define DEFAULT 267
#define DO 268
#define ELSE 269
#define END 270
#define EXIT 271
#define FALSE 272
#define FOR 273
#define FUNCTION 274
#define GET 275
#define IF 276
#define INT 277
#define LOOP 278
#define OF 279
#define PUT 280
#define PROCEDURE 281
#define REAL 282
#define RESULT 283
#define RETURN 284
#define SKIP 285
#define STRING 286
#define TRUE 287
#define VAR 288
#define WHEN 289
#define THEN 290
#define TYPE 291
#define ID 292
#define String 293
#define R_NUMBER 294
#define I_NUMBER 295
#define B_VALUE 296
#define ASSIGN 297
#define OR 298
#define AND 299
#define NE 300
#define RE 301
#define LE 302
#define MOD 303
#define UMINUS 304
#define NOT 305

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
