/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_identifier = 258,            /* T_identifier  */
    T_False = 259,                 /* T_False  */
    T_True = 260,                  /* T_True  */
    T_number = 261,                /* T_number  */
    Indent = 262,                  /* Indent  */
    Nodent = 263,                  /* Nodent  */
    Dedent = 264,                  /* Dedent  */
    T_string = 265,                /* T_string  */
    T_print = 266,                 /* T_print  */
    T_colon = 267,                 /* T_colon  */
    T_newLine = 268,               /* T_newLine  */
    T_lesserThan = 269,            /* T_lesserThan  */
    T_greaterThanEqualTo = 270,    /* T_greaterThanEqualTo  */
    T_lesserThanEqualTo = 271,     /* T_lesserThanEqualTo  */
    T_or = 272,                    /* T_or  */
    T_and = 273,                   /* T_and  */
    T_not = 274,                   /* T_not  */
    T_assignOP = 275,              /* T_assignOP  */
    T_notEqualOP = 276,            /* T_notEqualOP  */
    T_equalOP = 277,               /* T_equalOP  */
    T_greaterThan = 278,           /* T_greaterThan  */
    T_in = 279,                    /* T_in  */
    T_if = 280,                    /* T_if  */
    T_elif = 281,                  /* T_elif  */
    T_while = 282,                 /* T_while  */
    T_else = 283,                  /* T_else  */
    T_import = 284,                /* T_import  */
    T_break = 285,                 /* T_break  */
    T_pass = 286,                  /* T_pass  */
    T_minus = 287,                 /* T_minus  */
    T_plus = 288,                  /* T_plus  */
    T_division = 289,              /* T_division  */
    T_multiply = 290,              /* T_multiply  */
    T_openParanthesis = 291,       /* T_openParanthesis  */
    T_closeParanthesis = 292,      /* T_closeParanthesis  */
    T_EOF = 293,                   /* T_EOF  */
    T_return = 294,                /* T_return  */
    T_openBracket = 295,           /* T_openBracket  */
    T_closeBracket = 296,          /* T_closeBracket  */
    T_def = 297,                   /* T_def  */
    T_comma = 298,                 /* T_comma  */
    T_List = 299,                  /* T_List  */
    T_range = 300,                 /* T_range  */
    T_None = 301,                  /* T_None  */
    T_continue = 302,              /* T_continue  */
    T_len = 303,                   /* T_len  */
    T_input = 304                  /* T_input  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_identifier 258
#define T_False 259
#define T_True 260
#define T_number 261
#define Indent 262
#define Nodent 263
#define Dedent 264
#define T_string 265
#define T_print 266
#define T_colon 267
#define T_newLine 268
#define T_lesserThan 269
#define T_greaterThanEqualTo 270
#define T_lesserThanEqualTo 271
#define T_or 272
#define T_and 273
#define T_not 274
#define T_assignOP 275
#define T_notEqualOP 276
#define T_equalOP 277
#define T_greaterThan 278
#define T_in 279
#define T_if 280
#define T_elif 281
#define T_while 282
#define T_else 283
#define T_import 284
#define T_break 285
#define T_pass 286
#define T_minus 287
#define T_plus 288
#define T_division 289
#define T_multiply 290
#define T_openParanthesis 291
#define T_closeParanthesis 292
#define T_EOF 293
#define T_return 294
#define T_openBracket 295
#define T_closeBracket 296
#define T_def 297
#define T_comma 298
#define T_List 299
#define T_range 300
#define T_None 301
#define T_continue 302
#define T_len 303
#define T_input 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "parser.y"
char *data; int indent_depth;

#line 168 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
