/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include <stdio.h>
	#include <stdarg.h>
	#include "symTab_new.h"
    #include "tac.h"

	int yylex();
	void yyerror(const char *msg);
    extern int yylineno; 

    int count = 0;

    //char val_temp[200];
    char func_name[100];

    char identifier[100];

    int op_count = 0;

    char func_call_name[100];

    int arg_count = 0;
    int param_count = 0;
    char param_count_str[10];
    
    int func_line_no;

	void finish()
	{
		printf("\n------------------->valid python syntax<--------------------\n\n\n\n");
        print_symbol_table();
        print_quads();
        dead_code_elim();
        loop_inv();
        const_prop();
        print_quads_opt();
		exit(0);
	}


#line 112 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 266 "y.tab.c"

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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_identifier = 3,               /* T_identifier  */
  YYSYMBOL_T_False = 4,                    /* T_False  */
  YYSYMBOL_T_True = 5,                     /* T_True  */
  YYSYMBOL_T_number = 6,                   /* T_number  */
  YYSYMBOL_Indent = 7,                     /* Indent  */
  YYSYMBOL_Nodent = 8,                     /* Nodent  */
  YYSYMBOL_Dedent = 9,                     /* Dedent  */
  YYSYMBOL_T_string = 10,                  /* T_string  */
  YYSYMBOL_T_print = 11,                   /* T_print  */
  YYSYMBOL_T_colon = 12,                   /* T_colon  */
  YYSYMBOL_T_newLine = 13,                 /* T_newLine  */
  YYSYMBOL_T_lesserThan = 14,              /* T_lesserThan  */
  YYSYMBOL_T_greaterThanEqualTo = 15,      /* T_greaterThanEqualTo  */
  YYSYMBOL_T_lesserThanEqualTo = 16,       /* T_lesserThanEqualTo  */
  YYSYMBOL_T_or = 17,                      /* T_or  */
  YYSYMBOL_T_and = 18,                     /* T_and  */
  YYSYMBOL_T_not = 19,                     /* T_not  */
  YYSYMBOL_T_assignOP = 20,                /* T_assignOP  */
  YYSYMBOL_T_notEqualOP = 21,              /* T_notEqualOP  */
  YYSYMBOL_T_equalOP = 22,                 /* T_equalOP  */
  YYSYMBOL_T_greaterThan = 23,             /* T_greaterThan  */
  YYSYMBOL_T_in = 24,                      /* T_in  */
  YYSYMBOL_T_if = 25,                      /* T_if  */
  YYSYMBOL_T_elif = 26,                    /* T_elif  */
  YYSYMBOL_T_while = 27,                   /* T_while  */
  YYSYMBOL_T_else = 28,                    /* T_else  */
  YYSYMBOL_T_import = 29,                  /* T_import  */
  YYSYMBOL_T_break = 30,                   /* T_break  */
  YYSYMBOL_T_pass = 31,                    /* T_pass  */
  YYSYMBOL_T_minus = 32,                   /* T_minus  */
  YYSYMBOL_T_plus = 33,                    /* T_plus  */
  YYSYMBOL_T_division = 34,                /* T_division  */
  YYSYMBOL_T_multiply = 35,                /* T_multiply  */
  YYSYMBOL_T_openParanthesis = 36,         /* T_openParanthesis  */
  YYSYMBOL_T_closeParanthesis = 37,        /* T_closeParanthesis  */
  YYSYMBOL_T_EOF = 38,                     /* T_EOF  */
  YYSYMBOL_T_return = 39,                  /* T_return  */
  YYSYMBOL_T_openBracket = 40,             /* T_openBracket  */
  YYSYMBOL_T_closeBracket = 41,            /* T_closeBracket  */
  YYSYMBOL_T_def = 42,                     /* T_def  */
  YYSYMBOL_T_comma = 43,                   /* T_comma  */
  YYSYMBOL_T_List = 44,                    /* T_List  */
  YYSYMBOL_T_range = 45,                   /* T_range  */
  YYSYMBOL_T_None = 46,                    /* T_None  */
  YYSYMBOL_T_continue = 47,                /* T_continue  */
  YYSYMBOL_T_len = 48,                     /* T_len  */
  YYSYMBOL_T_input = 49,                   /* T_input  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_Start = 51,                     /* Start  */
  YYSYMBOL_constant = 52,                  /* constant  */
  YYSYMBOL_term = 53,                      /* term  */
  YYSYMBOL_list_index = 54,                /* list_index  */
  YYSYMBOL_StartParse = 55,                /* StartParse  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_basic_stmt = 57,                /* basic_stmt  */
  YYSYMBOL_arith_exp = 58,                 /* arith_exp  */
  YYSYMBOL_59_2 = 59,                      /* $@2  */
  YYSYMBOL_60_3 = 60,                      /* $@3  */
  YYSYMBOL_61_4 = 61,                      /* $@4  */
  YYSYMBOL_62_5 = 62,                      /* $@5  */
  YYSYMBOL_bool_exp = 63,                  /* bool_exp  */
  YYSYMBOL_64_6 = 64,                      /* $@6  */
  YYSYMBOL_65_7 = 65,                      /* $@7  */
  YYSYMBOL_66_8 = 66,                      /* $@8  */
  YYSYMBOL_67_9 = 67,                      /* $@9  */
  YYSYMBOL_68_10 = 68,                     /* $@10  */
  YYSYMBOL_bool_term = 69,                 /* bool_term  */
  YYSYMBOL_bool_factor = 70,               /* bool_factor  */
  YYSYMBOL_import_stmt = 71,               /* import_stmt  */
  YYSYMBOL_pass_stmt = 72,                 /* pass_stmt  */
  YYSYMBOL_continue_stmt = 73,             /* continue_stmt  */
  YYSYMBOL_break_stmt = 74,                /* break_stmt  */
  YYSYMBOL_return_stmt = 75,               /* return_stmt  */
  YYSYMBOL_assign_stmt = 76,               /* assign_stmt  */
  YYSYMBOL_77_11 = 77,                     /* $@11  */
  YYSYMBOL_78_12 = 78,                     /* $@12  */
  YYSYMBOL_79_13 = 79,                     /* $@13  */
  YYSYMBOL_assign = 80,                    /* assign  */
  YYSYMBOL_print_stmt = 81,                /* print_stmt  */
  YYSYMBOL_print_values = 82,              /* print_values  */
  YYSYMBOL_finalStatements = 83,           /* finalStatements  */
  YYSYMBOL_cmpd_stmt = 84,                 /* cmpd_stmt  */
  YYSYMBOL_if_stmt = 85,                   /* if_stmt  */
  YYSYMBOL_86_14 = 86,                     /* $@14  */
  YYSYMBOL_if_opt = 87,                    /* if_opt  */
  YYSYMBOL_elif_stmts = 88,                /* elif_stmts  */
  YYSYMBOL_89_15 = 89,                     /* $@15  */
  YYSYMBOL_90_16 = 90,                     /* $@16  */
  YYSYMBOL_91_17 = 91,                     /* $@17  */
  YYSYMBOL_else_stmt = 92,                 /* else_stmt  */
  YYSYMBOL_93_18 = 93,                     /* $@18  */
  YYSYMBOL_func_def = 94,                  /* func_def  */
  YYSYMBOL_95_19 = 95,                     /* $@19  */
  YYSYMBOL_96_20 = 96,                     /* $@20  */
  YYSYMBOL_97_21 = 97,                     /* $@21  */
  YYSYMBOL_func_call = 98,                 /* func_call  */
  YYSYMBOL_99_22 = 99,                     /* $@22  */
  YYSYMBOL_100_23 = 100,                   /* $@23  */
  YYSYMBOL_while_stmt = 101,               /* while_stmt  */
  YYSYMBOL_102_24 = 102,                   /* $@24  */
  YYSYMBOL_103_25 = 103,                   /* $@25  */
  YYSYMBOL_start_suite_while = 104,        /* start_suite_while  */
  YYSYMBOL_suite_while = 105,              /* suite_while  */
  YYSYMBOL_end_suite_while = 106,          /* end_suite_while  */
  YYSYMBOL_107_26 = 107,                   /* $@26  */
  YYSYMBOL_start_suite_func = 108,         /* start_suite_func  */
  YYSYMBOL_suite_func = 109,               /* suite_func  */
  YYSYMBOL_end_suite_func = 110,           /* end_suite_func  */
  YYSYMBOL_111_27 = 111,                   /* $@27  */
  YYSYMBOL_start_suite = 112,              /* start_suite  */
  YYSYMBOL_suite = 113,                    /* suite  */
  YYSYMBOL_114_28 = 114,                   /* $@28  */
  YYSYMBOL_end_suite = 115,                /* end_suite  */
  YYSYMBOL_116_29 = 116,                   /* $@29  */
  YYSYMBOL_117_30 = 117,                   /* $@30  */
  YYSYMBOL_param = 118,                    /* param  */
  YYSYMBOL_119_31 = 119,                   /* $@31  */
  YYSYMBOL_params = 120,                   /* params  */
  YYSYMBOL_121_32 = 121,                   /* $@32  */
  YYSYMBOL_list_element = 122,             /* list_element  */
  YYSYMBOL_123_33 = 123,                   /* $@33  */
  YYSYMBOL_list_elements = 124,            /* list_elements  */
  YYSYMBOL_125_34 = 125,                   /* $@34  */
  YYSYMBOL_126_35 = 126,                   /* $@35  */
  YYSYMBOL_127_36 = 127                    /* $@36  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   675

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    59,    62,    63,    65,    74,    75,    76,
      77,    78,    81,    83,    83,    83,    83,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    95,    96,    96,   101,
     101,   106,   106,   111,   111,   116,   121,   122,   122,   123,
     124,   124,   125,   125,   126,   126,   127,   127,   128,   130,
     131,   132,   133,   134,   136,   137,   139,   140,   141,   142,
     143,   144,   145,   146,   149,   149,   149,   150,   150,   153,
     161,   171,   172,   173,   175,   176,   177,   178,   179,   180,
     181,   183,   184,   185,   186,   187,   189,   190,   192,   192,
     194,   195,   197,   198,   198,   198,   198,   200,   200,   202,
     202,   202,   202,   204,   204,   204,   206,   206,   206,   208,
     209,   211,   212,   214,   215,   216,   216,   217,   219,   220,
     222,   223,   225,   226,   227,   227,   228,   230,   231,   233,
     234,   235,   235,   237,   238,   239,   239,   240,   240,   242,
     242,   242,   244,   244,   244,   246,   246,   246,   248,   248,
     248,   248,   248,   248,   248
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_identifier",
  "T_False", "T_True", "T_number", "Indent", "Nodent", "Dedent",
  "T_string", "T_print", "T_colon", "T_newLine", "T_lesserThan",
  "T_greaterThanEqualTo", "T_lesserThanEqualTo", "T_or", "T_and", "T_not",
  "T_assignOP", "T_notEqualOP", "T_equalOP", "T_greaterThan", "T_in",
  "T_if", "T_elif", "T_while", "T_else", "T_import", "T_break", "T_pass",
  "T_minus", "T_plus", "T_division", "T_multiply", "T_openParanthesis",
  "T_closeParanthesis", "T_EOF", "T_return", "T_openBracket",
  "T_closeBracket", "T_def", "T_comma", "T_List", "T_range", "T_None",
  "T_continue", "T_len", "T_input", "$accept", "Start", "constant", "term",
  "list_index", "StartParse", "$@1", "basic_stmt", "arith_exp", "$@2",
  "$@3", "$@4", "$@5", "bool_exp", "$@6", "$@7", "$@8", "$@9", "$@10",
  "bool_term", "bool_factor", "import_stmt", "pass_stmt", "continue_stmt",
  "break_stmt", "return_stmt", "assign_stmt", "$@11", "$@12", "$@13",
  "assign", "print_stmt", "print_values", "finalStatements", "cmpd_stmt",
  "if_stmt", "$@14", "if_opt", "elif_stmts", "$@15", "$@16", "$@17",
  "else_stmt", "$@18", "func_def", "$@19", "$@20", "$@21", "func_call",
  "$@22", "$@23", "while_stmt", "$@24", "$@25", "start_suite_while",
  "suite_while", "end_suite_while", "$@26", "start_suite_func",
  "suite_func", "end_suite_func", "$@27", "start_suite", "suite", "$@28",
  "end_suite", "$@29", "$@30", "param", "$@31", "params", "$@32",
  "list_element", "$@33", "list_elements", "$@34", "$@35", "$@36", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-189)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-138)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     370,     1,    40,  -189,  -189,  -189,  -189,     2,   370,   -12,
      22,  -189,    44,  -189,  -189,    22,   553,    54,  -189,  -189,
      23,    25,    83,  -189,  -189,    69,    64,  -189,   640,  -189,
      70,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,    95,
    -189,  -189,  -189,  -189,  -189,  -189,    36,    90,    79,   587,
    -189,    22,  -189,    77,  -189,   640,  -189,    22,  -189,   616,
      85,    36,   640,  -189,  -189,   117,    -4,  -189,  -189,  -189,
    -189,  -189,  -189,   160,  -189,  -189,  -189,  -189,  -189,  -189,
      22,    22,  -189,    36,    59,  -189,    13,    12,   594,    84,
      94,   104,   136,  -189,  -189,  -189,   101,   113,   114,   115,
    -189,    36,    36,    36,    36,    36,   101,    36,   152,    36,
      36,    36,    36,    31,  -189,  -189,   370,   255,  -189,   140,
    -189,  -189,  -189,   120,   587,   587,  -189,   587,   466,   146,
    -189,  -189,  -189,   101,   101,   101,   101,   101,   101,  -189,
      91,    91,  -189,  -189,  -189,    36,    13,   640,  -189,  -189,
    -189,   118,   118,   118,  -189,  -189,  -189,  -189,    10,   161,
    -189,     3,   488,   170,   101,   137,    36,  -189,  -189,  -189,
    -189,   419,  -189,  -189,  -189,  -189,  -189,   174,  -189,  -189,
    -189,   148,  -189,   101,   178,    22,   171,   419,   154,   187,
     118,     9,  -189,     3,  -189,   466,   190,   197,  -189,  -189,
    -189,   419,   223,  -189,   419,  -189,  -189,   193,  -189,   156,
    -189,  -189,   535,   178,  -189,  -189,   466,   419,   272,  -189,
     419,   154,   200,  -189,  -189,  -189,  -189,   190,  -189,  -189,
    -189,   419,     3,  -189,   201,  -189,   185,  -189,   419,   321,
    -189,   419,   201,  -189,  -189,  -189
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     6,    53,    52,     3,     4,     0,     0,     0,
       0,   106,     0,    59,    57,     0,    60,     0,     5,    58,
       0,     0,     0,     7,    26,     8,     0,    81,    22,    23,
      48,    49,    20,    17,    19,    18,    25,    21,    24,     0,
      82,    86,    83,    84,    87,    85,     0,     0,     0,     0,
      13,     0,    54,     6,     8,     0,    88,     0,    56,     0,
       0,     0,    61,    63,    99,     0,     0,     1,    67,     2,
      37,    44,    42,     0,    40,    46,    29,    27,    33,    31,
       0,     0,    14,     0,     0,    65,   154,     6,    76,    78,
       0,    80,     0,   107,    35,    55,    62,     0,     0,     0,
      11,     0,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,    36,    39,     0,     0,    12,     0,
     148,   150,   152,     0,     0,     0,    74,     0,     0,     0,
     100,     9,    10,    68,    38,    45,    43,    51,    41,    47,
      30,    28,    34,    32,    15,     0,   154,    69,    71,    66,
      72,   147,   147,   147,   104,    75,    77,    79,     6,     0,
     127,    91,     0,   141,    70,     0,     0,   149,   151,   153,
     105,     0,    93,    97,    89,    90,    92,     0,   109,   108,
     139,     0,    73,   145,   131,     0,     0,     0,   144,     0,
     147,   135,   128,     0,    94,     0,     0,     0,   140,   101,
     146,     0,     0,   130,     0,   138,   132,     0,    98,   115,
     110,   142,     0,   131,   133,   136,     0,     0,     0,   112,
       0,   144,     0,   118,   102,   129,    95,     0,   113,   116,
     143,     0,     0,   111,     0,    96,   124,   119,     0,     0,
     121,     0,     0,   122,   125,   120
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,  -189,  -189,  -189,     0,    -7,  -189,  -126,    -6,  -189,
    -189,  -189,  -189,     5,  -189,  -189,  -189,  -189,  -189,    61,
     206,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,   -13,   -64,  -189,  -189,  -189,  -189,  -188,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,   -46,  -189,
    -189,  -189,  -189,  -189,  -189,   -17,  -189,  -189,  -189,   -23,
    -189,  -189,  -182,     8,  -189,  -189,  -189,  -189,  -189,  -189,
       4,  -189,  -141,  -189,    76,  -189,  -189,  -189
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    22,    23,    24,    54,    26,   116,    27,    28,   110,
     109,   112,   111,    29,   102,   107,   104,   103,   108,    30,
      31,    32,    33,    34,    35,    36,    37,    47,   119,   101,
     149,    38,    90,    39,    40,    41,    92,   174,   175,   185,
     207,   232,   176,   186,    42,    97,   163,   212,    43,    48,
     170,    44,    57,   129,   179,   210,   219,   220,   224,   237,
     240,   241,   161,   192,   193,   203,   204,   205,   181,   188,
     198,   221,   167,   190,   123,   151,   152,   153
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    50,   160,    91,    55,   206,    99,     9,    25,    59,
      62,   168,   169,   208,    45,    56,   120,   201,   202,   121,
      60,    63,  -137,   122,    51,    53,     3,     4,     5,   172,
     -64,   173,     6,   100,   226,  -137,   178,  -137,    49,    53,
      84,     9,     5,    88,   235,    55,     6,    58,  -103,   200,
      46,    55,    46,    73,    89,    96,    60,    64,    15,    65,
     -64,    66,    93,    76,    77,    78,    79,   106,    18,   160,
      20,    21,    83,   150,   113,   113,  -103,   117,    91,    91,
      46,    91,    18,    67,    20,    21,   223,    80,    81,    68,
     160,    76,    77,    78,    79,   133,   134,   135,   136,   137,
     118,   138,    69,   140,   141,   142,   143,   184,    82,   144,
      85,   155,   156,   147,   157,    86,    25,    46,    88,    88,
      98,    88,    95,   196,   148,    78,    79,   125,    25,    89,
      89,   126,    89,    76,    77,    78,    79,   213,   214,   164,
     215,   114,   115,    87,     3,     4,     5,   127,   128,   130,
       6,   131,   132,   227,   228,   139,   229,   154,   162,     9,
     183,   166,    25,    53,   217,   218,     5,   234,   171,  -117,
       6,    25,   145,   180,   242,   243,    15,   244,   182,    55,
     146,   187,  -117,   195,  -117,   189,    18,    25,    20,    21,
     194,   191,   105,   238,   239,    25,    83,   197,  -126,   199,
     211,    25,    25,   209,    25,   216,    18,   231,    20,    21,
     233,  -126,    25,  -126,   236,    52,    25,    25,    25,   245,
      25,   225,   165,     0,     1,   230,     2,     3,     4,     5,
       0,    25,     0,     6,     7,     0,  -134,     0,    25,    25,
       0,    25,     9,     0,     0,     0,     0,     0,    10,  -134,
      11,  -134,    12,    13,    14,     0,     0,     0,     0,    15,
       0,     0,    16,     0,     0,    17,     0,     0,     0,    18,
      19,    20,    21,     1,     0,     2,     3,     4,     5,     0,
       0,     0,     6,     7,     0,  -114,     0,    76,    77,    78,
      79,     9,    94,     0,     0,     0,     0,    10,  -114,    11,
    -114,    12,    13,    14,     0,     0,     0,     0,    15,     0,
       0,    16,     0,     0,    17,     0,     0,     0,    18,    19,
      20,    21,     1,     0,     2,     3,     4,     5,     0,     0,
       0,     6,     7,     0,  -123,     0,     0,     0,     0,     0,
       9,     0,     0,     0,     0,     0,    10,  -123,    11,  -123,
      12,    13,    14,     0,     0,     0,     0,    15,     0,     0,
      16,     0,     0,    17,     0,     0,     0,    18,    19,    20,
      21,     1,     0,     2,     3,     4,     5,     0,     0,     0,
       6,     7,     0,     8,     0,     0,     0,     0,     0,     9,
       0,     0,     0,     0,     0,    10,     0,    11,     0,    12,
      13,    14,     0,     0,     0,     0,    15,     0,   -16,    16,
       0,     0,    17,     0,     0,     0,    18,    19,    20,    21,
       1,     0,     2,     3,     4,     5,     0,     0,     0,     6,
       7,     0,     0,     0,     0,     0,     0,     0,     9,     0,
       0,     0,     0,     0,    10,     0,    11,     0,    12,    13,
      14,     0,     0,     0,     0,    15,     0,     0,    16,     0,
       0,    17,     0,     0,     0,    18,    19,    20,    21,   158,
       3,     4,     5,     0,     0,     0,     6,     7,     0,   159,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,   158,     3,     4,     5,    12,    13,    14,     6,     7,
       0,   177,    15,     0,     0,    16,     0,     9,     0,     0,
       0,     0,    18,    19,    20,    21,     0,    12,    13,    14,
       0,     0,     0,     0,    15,     0,     0,    16,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,   158,     3,
       4,     5,     0,     0,     0,     6,     7,     0,   222,     0,
       0,     0,     0,     0,     9,     0,    53,     3,     4,     5,
       0,     0,     0,     6,    12,    13,    14,     0,     0,     0,
       0,    15,     9,     0,    16,     0,     0,     0,     0,     0,
       0,    18,    19,    20,    21,    61,     0,     0,     0,    15,
      87,     3,     4,     5,     0,     0,     0,     6,     0,    18,
       0,    20,    21,     0,     0,     0,     9,     0,    70,    71,
      72,     0,     0,     0,     0,     0,    73,    74,    75,     0,
       0,     0,     0,    15,     0,     0,    76,    77,    78,    79,
      70,    71,    72,    18,     0,    20,    21,   124,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,    76,    77,
      78,    79,     0,    94,    70,    71,    72,     0,     0,     0,
       0,     0,    73,    74,    75,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    78,    79
};

static const yytype_int16 yycheck[] =
{
       0,     8,   128,    49,    10,   193,    10,    19,     8,    15,
      16,   152,   153,   195,    13,    10,     3,     8,     9,     6,
      15,    16,    13,    10,    36,     3,     4,     5,     6,    26,
      20,    28,    10,    37,   216,    26,   162,    28,    36,     3,
      46,    19,     6,    49,   232,    51,    10,     3,    36,   190,
      40,    57,    40,    22,    49,    61,    51,     3,    36,    36,
      20,    36,    57,    32,    33,    34,    35,    73,    46,   195,
      48,    49,    36,   119,    80,    81,    36,    83,   124,   125,
      40,   127,    46,     0,    48,    49,   212,    17,    18,    20,
     216,    32,    33,    34,    35,   101,   102,   103,   104,   105,
      41,   107,    38,   109,   110,   111,   112,   171,    13,   116,
      20,   124,   125,   119,   127,    36,   116,    40,   124,   125,
       3,   127,    37,   187,   119,    34,    35,    43,   128,   124,
     125,    37,   127,    32,    33,    34,    35,   201,   202,   145,
     204,    80,    81,     3,     4,     5,     6,    43,    12,    36,
      10,    37,    37,   217,   218,     3,   220,    37,    12,    19,
     166,    43,   162,     3,     8,     9,     6,   231,     7,    13,
      10,   171,    32,     3,   238,   239,    36,   241,    41,   185,
      40,     7,    26,    12,    28,    37,    46,   187,    48,    49,
     185,    13,    32,     8,     9,   195,    36,    43,    13,    12,
       3,   201,   202,    13,   204,    12,    46,     7,    48,    49,
     227,    26,   212,    28,    13,     9,   216,   217,   218,   242,
     220,   213,   146,    -1,     1,   221,     3,     4,     5,     6,
      -1,   231,    -1,    10,    11,    -1,    13,    -1,   238,   239,
      -1,   241,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    49,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    -1,    13,    -1,    32,    33,    34,
      35,    19,    37,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,
      48,    49,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      39,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,    48,
      49,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    -1,    29,
      30,    31,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    -1,    29,    30,
      31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    -1,
      -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    29,    30,    31,    10,    11,
      -1,    13,    36,    -1,    -1,    39,    -1,    19,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    29,    30,    31,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    19,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    29,    30,    31,    -1,    -1,    -1,
      -1,    36,    19,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    32,    -1,    -1,    -1,    36,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,    46,
      -1,    48,    49,    -1,    -1,    -1,    19,    -1,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    32,    33,    34,    35,
      14,    15,    16,    46,    -1,    48,    49,    43,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    -1,    37,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,    10,    11,    13,    19,
      25,    27,    29,    30,    31,    36,    39,    42,    46,    47,
      48,    49,    51,    52,    53,    54,    55,    57,    58,    63,
      69,    70,    71,    72,    73,    74,    75,    76,    81,    83,
      84,    85,    94,    98,   101,    13,    40,    77,    99,    36,
      55,    36,    70,     3,    54,    58,    63,   102,     3,    58,
      63,    32,    58,    63,     3,    36,    36,     0,    20,    38,
      14,    15,    16,    22,    23,    24,    32,    33,    34,    35,
      17,    18,    13,    36,    58,    20,    36,     3,    58,    63,
      82,    98,    86,    63,    37,    37,    58,    95,     3,    10,
      37,    79,    64,    67,    66,    32,    58,    65,    68,    60,
      59,    62,    61,    58,    69,    69,    56,    58,    41,    78,
       3,     6,    10,   124,    43,    43,    37,    43,    12,   103,
      36,    37,    37,    58,    58,    58,    58,    58,    58,     3,
      58,    58,    58,    58,    55,    32,    40,    58,    63,    80,
      98,   125,   126,   127,    37,    82,    82,    82,     3,    13,
      57,   112,    12,    96,    58,   124,    43,   122,   122,   122,
     100,     7,    26,    28,    87,    88,    92,    13,    57,   104,
       3,   118,    41,    58,    83,    89,    93,     7,   119,    37,
     123,    13,   113,   114,    63,    12,    83,    43,   120,    12,
     122,     8,     9,   115,   116,   117,    88,    90,   112,    13,
     105,     3,    97,    83,    83,    83,    12,     8,     9,   106,
     107,   121,    13,    57,   108,   113,   112,    83,    83,    83,
     120,     7,    91,   105,    83,    88,    13,   109,     8,     9,
     110,   111,    83,    83,    83,   109
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    54,    55,    56,    55,    55,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    59,    58,    60,
      58,    61,    58,    62,    58,    58,    63,    64,    63,    63,
      65,    63,    66,    63,    67,    63,    68,    63,    63,    69,
      69,    69,    69,    69,    70,    70,    71,    72,    73,    74,
      75,    75,    75,    75,    77,    78,    76,    79,    76,    80,
      80,    80,    80,    80,    81,    82,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    83,    84,    84,    86,    85,
      87,    87,    88,    89,    90,    91,    88,    93,    92,    95,
      96,    97,    94,    99,   100,    98,   102,   103,   101,   104,
     104,   105,   105,   106,   106,   107,   106,   106,   108,   108,
     109,   109,   110,   110,   111,   110,   110,   112,   112,   113,
     113,   114,   113,   115,   115,   116,   115,   117,   115,   119,
     118,   118,   121,   120,   120,   123,   122,   122,   125,   124,
     126,   124,   127,   124,   124
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       4,     3,     4,     2,     0,     4,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     0,     4,     3,     3,     0,     4,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     1,     1,
       3,     4,     1,     1,     2,     3,     2,     1,     1,     1,
       1,     2,     3,     2,     0,     0,     5,     0,     4,     1,
       2,     1,     1,     3,     4,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     1,     0,     6,
       1,     0,     1,     0,     0,     0,     8,     0,     4,     0,
       0,     0,    10,     0,     0,     6,     0,     0,     6,     1,
       4,     4,     2,     2,     1,     0,     2,     0,     1,     4,
       4,     2,     2,     1,     0,     2,     0,     1,     4,     4,
       2,     0,     2,     2,     1,     0,     2,     0,     1,     0,
       3,     0,     0,     4,     0,     0,     4,     0,     0,     3,
       0,     3,     0,     3,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Start: StartParse T_EOF  */
#line 57 "parser.y"
                         {printf("Start => StartParse EOF\n\n"); finish();}
#line 1778 "y.tab.c"
    break;

  case 3: /* constant: T_number  */
#line 59 "parser.y"
                    {printf("constant => number\n\n");
                    insert("Constant", (yyvsp[0].data), (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");
                    }
#line 1786 "y.tab.c"
    break;

  case 4: /* constant: T_string  */
#line 62 "parser.y"
                    {printf("constant => string\n\n"); insert("Constant", (yyvsp[0].data), (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");}
#line 1792 "y.tab.c"
    break;

  case 5: /* constant: T_None  */
#line 63 "parser.y"
                          {printf("constant => none\n\n");insert("Constant", "None", (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");}
#line 1798 "y.tab.c"
    break;

  case 6: /* term: T_identifier  */
#line 65 "parser.y"
                    {	printf("term => id\n\n");
                        push_0((yyvsp[0].data));
                        check_scope((yyvsp[0].data), (yylsp[0]).first_line);
                        if((strcmp(identifier, (yyvsp[0].data)) != 0) && (li_s)){ li_flag ++; }
                        else li_flag -- ;
                        insert("Identifier", (yyvsp[0].data), (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");
                        //memset(lookup($<data>1)->value, 0, sizeof(lookup($<data>1)->value));
                        strncpy((yyval.data), lookup((yyvsp[0].data))->value, strlen(lookup((yyvsp[0].data))->value));
                    }
#line 1812 "y.tab.c"
    break;

  case 7: /* term: constant  */
#line 74 "parser.y"
                {printf("term => constant\n\n"); if((strcmp(identifier, (yyvsp[0].data)) != 0) && (li_s)) li_flag ++ ; (yyval.data) = (yyvsp[0].data); push_0((yyvsp[0].data));}
#line 1818 "y.tab.c"
    break;

  case 8: /* term: list_index  */
#line 75 "parser.y"
                  {printf("term => list_index\n\n");}
#line 1824 "y.tab.c"
    break;

  case 9: /* term: T_len T_openParanthesis T_identifier T_closeParanthesis  */
#line 76 "parser.y"
                                                               {printf("term => len ( array )\n\n");}
#line 1830 "y.tab.c"
    break;

  case 10: /* term: T_input T_openParanthesis T_string T_closeParanthesis  */
#line 77 "parser.y"
                                                             {printf("term => input ( string )\n\n");}
#line 1836 "y.tab.c"
    break;

  case 11: /* term: T_input T_openParanthesis T_closeParanthesis  */
#line 78 "parser.y"
                                                    {printf("term => input ( )\n\n");}
#line 1842 "y.tab.c"
    break;

  case 12: /* list_index: T_identifier T_openBracket arith_exp T_closeBracket  */
#line 81 "parser.y"
                                                                 { printf("list_index => id ( constant )\n\n"); check_scope((yyvsp[-3].data), (yylsp[-3]).first_line); is_iter((yyvsp[-3].data), (yylsp[-3]).first_line);}
#line 1848 "y.tab.c"
    break;

  case 13: /* StartParse: T_newLine StartParse  */
#line 83 "parser.y"
                                  {printf("StartParse => \\n StartParse\n\n");}
#line 1854 "y.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 83 "parser.y"
                                                                                                            {reset_depth();}
#line 1860 "y.tab.c"
    break;

  case 15: /* StartParse: finalStatements T_newLine $@1 StartParse  */
#line 83 "parser.y"
                                                                                                                                        {printf("StartParse => finalStatements \\n StartParse\n\n");}
#line 1866 "y.tab.c"
    break;

  case 16: /* StartParse: %empty  */
#line 83 "parser.y"
                                                                                                                                                                                                        {printf("StartParse => epsilon\n\n");}
#line 1872 "y.tab.c"
    break;

  case 17: /* basic_stmt: pass_stmt  */
#line 85 "parser.y"
                       {printf("basic_stmt => pass_stmt\n\n");}
#line 1878 "y.tab.c"
    break;

  case 18: /* basic_stmt: break_stmt  */
#line 86 "parser.y"
                        {printf("basic_stmt => break_stmt\n\n");}
#line 1884 "y.tab.c"
    break;

  case 19: /* basic_stmt: continue_stmt  */
#line 87 "parser.y"
                                   {printf("basic_stmt => continue_stmt\n\n");}
#line 1890 "y.tab.c"
    break;

  case 20: /* basic_stmt: import_stmt  */
#line 88 "parser.y"
                         {printf("basic_stmt => import_stmt\n\n");}
#line 1896 "y.tab.c"
    break;

  case 21: /* basic_stmt: assign_stmt  */
#line 89 "parser.y"
                         {printf("basic_stmt => assign_stmt\n\n");}
#line 1902 "y.tab.c"
    break;

  case 22: /* basic_stmt: arith_exp  */
#line 90 "parser.y"
                       {printf("basic_stmt => arith_exp\n\n");}
#line 1908 "y.tab.c"
    break;

  case 23: /* basic_stmt: bool_exp  */
#line 91 "parser.y"
                      {printf("basic_stmt => bool_exp\n\n");}
#line 1914 "y.tab.c"
    break;

  case 24: /* basic_stmt: print_stmt  */
#line 92 "parser.y"
                        {printf("basic_stmt => print_stmt\n\n");}
#line 1920 "y.tab.c"
    break;

  case 25: /* basic_stmt: return_stmt  */
#line 93 "parser.y"
                         {printf("basic_stmt => return_stmt\n\n");}
#line 1926 "y.tab.c"
    break;

  case 26: /* arith_exp: term  */
#line 95 "parser.y"
                 {printf("arith_exp => term\n\n"); if(li_s) op_count++;(yyval.data)=(yyvsp[0].data);}
#line 1932 "y.tab.c"
    break;

  case 27: /* $@2: %empty  */
#line 96 "parser.y"
                             {push_0("+");}
#line 1938 "y.tab.c"
    break;

  case 28: /* arith_exp: arith_exp T_plus $@2 arith_exp  */
#line 96 "parser.y"
                                                       {printf("arith_exp => arith_exp + arith_exp\n\n");
                                            int val = atoi((yyvsp[-3].data)) + atoi((yyvsp[0].data));
                                            sprintf((yyval.data), "%d", val);
                                            codegen2((yyval.data), (yylsp[-3]).first_line);
                                          }
#line 1948 "y.tab.c"
    break;

  case 29: /* $@3: %empty  */
#line 101 "parser.y"
                              {push_0("-");}
#line 1954 "y.tab.c"
    break;

  case 30: /* arith_exp: arith_exp T_minus $@3 arith_exp  */
#line 101 "parser.y"
                                                        { printf("arith_exp => arith_exp - arith_exp\n\n");
                                            int val = atoi((yyvsp[-3].data)) - atoi((yyvsp[0].data));
                                            sprintf((yyval.data), "%d", val);
                                            codegen2((yyval.data), (yylsp[-3]).first_line);
                                        }
#line 1964 "y.tab.c"
    break;

  case 31: /* $@4: %empty  */
#line 106 "parser.y"
                                 {push_0("*");}
#line 1970 "y.tab.c"
    break;

  case 32: /* arith_exp: arith_exp T_multiply $@4 arith_exp  */
#line 106 "parser.y"
                                                           { printf("arith_exp => arith_exp * arith_exp\n\n");
                                            int val = atoi((yyvsp[-3].data)) * atoi((yyvsp[0].data));
                                            sprintf((yyval.data), "%d", val);
                                            codegen2((yyval.data), (yylsp[-3]).first_line);
                                        }
#line 1980 "y.tab.c"
    break;

  case 33: /* $@5: %empty  */
#line 111 "parser.y"
                                 {push_0("/");}
#line 1986 "y.tab.c"
    break;

  case 34: /* arith_exp: arith_exp T_division $@5 arith_exp  */
#line 111 "parser.y"
                                                          { printf("arith_exp => arith_exp / arith_exp\n\n");
                                            int val = atoi((yyvsp[-3].data)) / atoi((yyvsp[0].data));
                                            sprintf((yyval.data), "%d", val);
                                            codegen2((yyval.data), (yylsp[-3]).first_line);
                                        }
#line 1996 "y.tab.c"
    break;

  case 35: /* arith_exp: T_openParanthesis arith_exp T_closeParanthesis  */
#line 116 "parser.y"
                                                          { printf("arith_exp => ( arith_exp )\n\n");
                                            (yyval.data) = (yyvsp[-1].data);
                                        }
#line 2004 "y.tab.c"
    break;

  case 36: /* bool_exp: bool_term T_or bool_term  */
#line 121 "parser.y"
                                    {printf("bool_exp => bool_term or bool_term\n\n");}
#line 2010 "y.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 122 "parser.y"
                                  { push_0("<");}
#line 2016 "y.tab.c"
    break;

  case 38: /* bool_exp: arith_exp T_lesserThan $@6 arith_exp  */
#line 122 "parser.y"
                                                            {printf("bool_exp => arith_exp < arith_exp\n\n");int val = atoi((yyvsp[-3].data)) < atoi((yyvsp[0].data)); cond_code_gen(val, (yylsp[-3]).first_line);}
#line 2022 "y.tab.c"
    break;

  case 39: /* bool_exp: bool_term T_and bool_term  */
#line 123 "parser.y"
                                     {printf("bool_exp => bool_term and bool_term\n\n");}
#line 2028 "y.tab.c"
    break;

  case 40: /* $@7: %empty  */
#line 124 "parser.y"
                                   {push_0(">");}
#line 2034 "y.tab.c"
    break;

  case 41: /* bool_exp: arith_exp T_greaterThan $@7 arith_exp  */
#line 124 "parser.y"
                                                            {printf("bool_exp => arith_exp > arith_exp\n\n"); int val = atoi((yyvsp[-3].data)) > atoi((yyvsp[0].data)); cond_code_gen(val, (yylsp[-3]).first_line);}
#line 2040 "y.tab.c"
    break;

  case 42: /* $@8: %empty  */
#line 125 "parser.y"
                                         {push_0("<=");}
#line 2046 "y.tab.c"
    break;

  case 43: /* bool_exp: arith_exp T_lesserThanEqualTo $@8 arith_exp  */
#line 125 "parser.y"
                                                                   {printf("bool_exp => arith_exp <= arith_exp\n\n"); int val = atoi((yyvsp[-3].data)) <= atoi((yyvsp[0].data)); cond_code_gen(val, (yylsp[-3]).first_line);}
#line 2052 "y.tab.c"
    break;

  case 44: /* $@9: %empty  */
#line 126 "parser.y"
                                          {push_0(">=");}
#line 2058 "y.tab.c"
    break;

  case 45: /* bool_exp: arith_exp T_greaterThanEqualTo $@9 arith_exp  */
#line 126 "parser.y"
                                                                    {printf("bool_exp => arith_exp >= arith_exp\n\n"); int val = atoi((yyvsp[-3].data)) >= atoi((yyvsp[0].data)); cond_code_gen(val, (yylsp[-3]).first_line);}
#line 2064 "y.tab.c"
    break;

  case 46: /* $@10: %empty  */
#line 127 "parser.y"
                          {push_0("in"); printf("bool_exp => arith_exp in id\n\n");}
#line 2070 "y.tab.c"
    break;

  case 48: /* bool_exp: bool_term  */
#line 128 "parser.y"
                     {printf("bool_exp => bool_term\n\n");}
#line 2076 "y.tab.c"
    break;

  case 49: /* bool_term: bool_factor  */
#line 130 "parser.y"
                        {printf("bool_term => bool_factor\n\n");}
#line 2082 "y.tab.c"
    break;

  case 50: /* bool_term: arith_exp T_equalOP arith_exp  */
#line 131 "parser.y"
                                          {printf("bool_term => arith_exp == arith_exp\n\n");}
#line 2088 "y.tab.c"
    break;

  case 51: /* bool_term: arith_exp T_equalOP T_minus arith_exp  */
#line 132 "parser.y"
                                                  {printf("bool_term => arith_exp == arith_exp\n\n");}
#line 2094 "y.tab.c"
    break;

  case 52: /* bool_term: T_True  */
#line 133 "parser.y"
                   {insert("Constant", "True", (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");printf("bool_term => True\n\n");}
#line 2100 "y.tab.c"
    break;

  case 53: /* bool_term: T_False  */
#line 134 "parser.y"
                    {insert("Constant", "False", (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");printf("bool_term => False\n\n");}
#line 2106 "y.tab.c"
    break;

  case 54: /* bool_factor: T_not bool_factor  */
#line 136 "parser.y"
                                {printf("bool_factor => not bool_factor\n\n");}
#line 2112 "y.tab.c"
    break;

  case 55: /* bool_factor: T_openParanthesis bool_exp T_closeParanthesis  */
#line 137 "parser.y"
                                                            {printf("bool_factor => ( bool_exp )\n\n");}
#line 2118 "y.tab.c"
    break;

  case 56: /* import_stmt: T_import T_identifier  */
#line 139 "parser.y"
                                    {insert("Package name", (yyvsp[0].data), (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null"); printf("import_stmt => import id\n\n");}
#line 2124 "y.tab.c"
    break;

  case 57: /* pass_stmt: T_pass  */
#line 140 "parser.y"
                   {printf("pass_stmt => pass\n\n");}
#line 2130 "y.tab.c"
    break;

  case 58: /* continue_stmt: T_continue  */
#line 141 "parser.y"
                           {printf("continue_stmt => continue\n\n");}
#line 2136 "y.tab.c"
    break;

  case 59: /* break_stmt: T_break  */
#line 142 "parser.y"
                     {printf("break_stmt => break\n\n");}
#line 2142 "y.tab.c"
    break;

  case 60: /* return_stmt: T_return  */
#line 143 "parser.y"
                       {dc_flag = 1; printf("return_stmt => return\n\n");}
#line 2148 "y.tab.c"
    break;

  case 61: /* return_stmt: T_return arith_exp  */
#line 144 "parser.y"
                                             {dc_flag = 1; printf("return_stmt => return arith_exp\n\n");}
#line 2154 "y.tab.c"
    break;

  case 62: /* return_stmt: T_return T_minus arith_exp  */
#line 145 "parser.y"
                                                     {dc_flag = 1; printf("return_stmt => return - arith_exp\n\n");}
#line 2160 "y.tab.c"
    break;

  case 63: /* return_stmt: T_return bool_exp  */
#line 146 "parser.y"
                                    {dc_flag = 1; printf("return_stmt => return bool_exp\n\n");}
#line 2166 "y.tab.c"
    break;

  case 64: /* $@11: %empty  */
#line 149 "parser.y"
                           {memset(identifier,0,sizeof(identifier));strncpy(identifier, (yyvsp[0].data), strlen((yyvsp[0].data)));push_0((yyvsp[0].data));}
#line 2172 "y.tab.c"
    break;

  case 65: /* $@12: %empty  */
#line 149 "parser.y"
                                                                                                                                                  {push_0("=");}
#line 2178 "y.tab.c"
    break;

  case 66: /* assign_stmt: T_identifier $@11 T_assignOP $@12 assign  */
#line 149 "parser.y"
                                                                                                                                                                       {printf("assign_stmt => id = assign\n\n");}
#line 2184 "y.tab.c"
    break;

  case 67: /* $@13: %empty  */
#line 150 "parser.y"
                                                {push_0("=");}
#line 2190 "y.tab.c"
    break;

  case 69: /* assign: arith_exp  */
#line 153 "parser.y"
                 {
					printf("assign => arith_exp\n\n");
                    insert("Identifier", identifier, (yylsp[0]).first_line, strlen(identifier), (yyvsp[0].data));
                    if(op_count==1) li_flag = 1;
                    codegen_assign();
                    li_flag = 0;
                    op_count = 0;
                }
#line 2203 "y.tab.c"
    break;

  case 70: /* assign: T_minus arith_exp  */
#line 161 "parser.y"
                        {
      						printf("assign => - arith_exp\n\n");
                            char temp[100] = "-";
                            strcat(temp, (yyvsp[0].data));
                            insert("Identifier", identifier, (yylsp[-1]).first_line, strlen(identifier), temp);
                            if(op_count==1) li_flag = 1;
                            codegen_umin();
                            li_flag = 0;
                            op_count = 0;
                        }
#line 2218 "y.tab.c"
    break;

  case 71: /* assign: bool_exp  */
#line 171 "parser.y"
                 {printf("assign => bool_exp\n\n");insert("Identifier", (yyvsp[0].data), (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");}
#line 2224 "y.tab.c"
    break;

  case 72: /* assign: func_call  */
#line 172 "parser.y"
                  {printf("assign => func_call\n\n");insert("Identifier", identifier, (yylsp[0]).first_line, strlen(identifier), "null");insert("Func call", (yyvsp[0].data), (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");}
#line 2230 "y.tab.c"
    break;

  case 73: /* assign: T_openBracket list_elements T_closeBracket  */
#line 173 "parser.y"
                                                   {printf("assign => ( list_elements )\n\n");insert("List identifier", (yyvsp[-2].data), (yylsp[-2]).first_line, strlen((yyvsp[-2].data)), "null");}
#line 2236 "y.tab.c"
    break;

  case 74: /* print_stmt: T_print T_openParanthesis print_values T_closeParanthesis  */
#line 175 "parser.y"
                                                                       {printf("print_stmt => print ( print_values )\n\n"); }
#line 2242 "y.tab.c"
    break;

  case 75: /* print_values: arith_exp T_comma print_values  */
#line 176 "parser.y"
                                             {printf("print_values => arith_exp , print_values\n\n"); }
#line 2248 "y.tab.c"
    break;

  case 76: /* print_values: arith_exp  */
#line 177 "parser.y"
                                    {printf("print_values => arith_exp\n\n"); }
#line 2254 "y.tab.c"
    break;

  case 77: /* print_values: bool_exp T_comma print_values  */
#line 178 "parser.y"
                                                        {printf("print_values => bool_exp , print_values\n\n"); }
#line 2260 "y.tab.c"
    break;

  case 78: /* print_values: bool_exp  */
#line 179 "parser.y"
                                   {printf("print_values => bool_exp\n\n"); }
#line 2266 "y.tab.c"
    break;

  case 79: /* print_values: func_call T_comma print_values  */
#line 180 "parser.y"
                                                         {printf("print_values => func_call , print_values\n\n"); }
#line 2272 "y.tab.c"
    break;

  case 80: /* print_values: func_call  */
#line 181 "parser.y"
                                    {printf("print_values => func_call\n\n"); }
#line 2278 "y.tab.c"
    break;

  case 81: /* finalStatements: basic_stmt  */
#line 183 "parser.y"
                             {printf("finalStatements => basic_stmt\n\n"); }
#line 2284 "y.tab.c"
    break;

  case 82: /* finalStatements: cmpd_stmt  */
#line 184 "parser.y"
                            {printf("finalStatements => cmpd_stmt\n\n"); }
#line 2290 "y.tab.c"
    break;

  case 83: /* finalStatements: func_def  */
#line 185 "parser.y"
                           {printf("finalStatements => func_def\n\n"); }
#line 2296 "y.tab.c"
    break;

  case 84: /* finalStatements: func_call  */
#line 186 "parser.y"
                            {printf("finalStatements => func_call\n\n"); }
#line 2302 "y.tab.c"
    break;

  case 85: /* finalStatements: error T_newLine  */
#line 187 "parser.y"
                                  {printf("finalStatements => error \\n\n\n"); yyerrok; yyclearin;}
#line 2308 "y.tab.c"
    break;

  case 86: /* cmpd_stmt: if_stmt  */
#line 189 "parser.y"
                    {printf("cmpd_stmt => if_stmt\n\n"); }
#line 2314 "y.tab.c"
    break;

  case 87: /* cmpd_stmt: while_stmt  */
#line 190 "parser.y"
                       {printf("cmpd_stmt => while_stmt\n\n"); }
#line 2320 "y.tab.c"
    break;

  case 88: /* $@14: %empty  */
#line 192 "parser.y"
                        {if_code_1();}
#line 2326 "y.tab.c"
    break;

  case 89: /* if_stmt: T_if bool_exp $@14 T_colon start_suite if_opt  */
#line 192 "parser.y"
                                                                  {printf("if_stmt => if bool_exp : start_suite if_opt\n\n"); }
#line 2332 "y.tab.c"
    break;

  case 90: /* if_opt: elif_stmts  */
#line 194 "parser.y"
                   {printf("if_opt => elif_stmts");}
#line 2338 "y.tab.c"
    break;

  case 91: /* if_opt: %empty  */
#line 195 "parser.y"
                   {printf("if_opt => T_if");}
#line 2344 "y.tab.c"
    break;

  case 92: /* elif_stmts: else_stmt  */
#line 197 "parser.y"
                       {printf("elif_stmts => else_stmt\n\n"); }
#line 2350 "y.tab.c"
    break;

  case 93: /* $@15: %empty  */
#line 198 "parser.y"
                    {elif1();count++;}
#line 2356 "y.tab.c"
    break;

  case 94: /* $@16: %empty  */
#line 198 "parser.y"
                                                {if_code_1();}
#line 2362 "y.tab.c"
    break;

  case 95: /* $@17: %empty  */
#line 198 "parser.y"
                                                                                   {if_code_2();}
#line 2368 "y.tab.c"
    break;

  case 96: /* elif_stmts: T_elif $@15 bool_exp $@16 T_colon start_suite $@17 elif_stmts  */
#line 198 "parser.y"
                                                                                                             {printf("elif_stmts => elif bool_exp : start_suite elif_stmts\n\n"); }
#line 2374 "y.tab.c"
    break;

  case 97: /* $@18: %empty  */
#line 200 "parser.y"
                   {if(count == 0){ count = 0; if_code_2();}}
#line 2380 "y.tab.c"
    break;

  case 98: /* else_stmt: T_else $@18 T_colon start_suite  */
#line 200 "parser.y"
                                                                                  {printf("else_stmt => else : start_suite\n\n"); }
#line 2386 "y.tab.c"
    break;

  case 99: /* $@19: %empty  */
#line 202 "parser.y"
                              {memset(func_name,0,sizeof(func_name)); strncpy(func_name,(yyvsp[0].data),strlen((yyvsp[0].data))); func_begin((yyvsp[0].data)); func_line_no=(yylsp[0]).first_line;}
#line 2392 "y.tab.c"
    break;

  case 100: /* $@20: %empty  */
#line 202 "parser.y"
                                                                                                                                                                                        {flag = 1; func_no++;}
#line 2398 "y.tab.c"
    break;

  case 101: /* $@21: %empty  */
#line 202 "parser.y"
                                                                                                                                                                                                                                                {sprintf(param_count_str, "%d", param_count); insert("Func_Name", func_name, func_line_no, strlen(func_name), param_count_str);}
#line 2404 "y.tab.c"
    break;

  case 102: /* func_def: T_def T_identifier $@19 T_openParanthesis $@20 param T_closeParanthesis T_colon $@21 start_suite_func  */
#line 202 "parser.y"
                                                                                                                                                                                                                                                                                                                                                                                                  {printf("func_def => def id ( param ) : start_suite_func\n\n"); }
#line 2410 "y.tab.c"
    break;

  case 103: /* $@22: %empty  */
#line 204 "parser.y"
                         {memset(func_call_name,0,sizeof(func_call_name)); strncpy(func_call_name,(yyvsp[0].data),strlen((yyvsp[0].data))); arg_count=0;}
#line 2416 "y.tab.c"
    break;

  case 104: /* $@23: %empty  */
#line 204 "parser.y"
                                                                                                                                                                                               {func_call(func_call_name, arg_count);arg_count=0;}
#line 2422 "y.tab.c"
    break;

  case 105: /* func_call: T_identifier $@22 T_openParanthesis list_elements T_closeParanthesis $@23  */
#line 204 "parser.y"
                                                                                                                                                                                                                                                   {printf("func_call => id ( list_elements )\n\n"); }
#line 2428 "y.tab.c"
    break;

  case 106: /* $@24: %empty  */
#line 206 "parser.y"
                     {while_code_1();}
#line 2434 "y.tab.c"
    break;

  case 107: /* $@25: %empty  */
#line 206 "parser.y"
                                                {li_s = 1; while_code_2();}
#line 2440 "y.tab.c"
    break;

  case 108: /* while_stmt: T_while $@24 bool_exp $@25 T_colon start_suite_while  */
#line 206 "parser.y"
                                                                                                      {printf("while_stmt => while bool_exp : start_suite\n\n");}
#line 2446 "y.tab.c"
    break;

  case 109: /* start_suite_while: basic_stmt  */
#line 208 "parser.y"
                               {printf("start_suite_while => basic_stmt\n\n");}
#line 2452 "y.tab.c"
    break;

  case 110: /* start_suite_while: T_newLine Indent finalStatements suite_while  */
#line 209 "parser.y"
                                                           {printf("start_suite_while => \\n Indent finalStatements suite_while\n\n");}
#line 2458 "y.tab.c"
    break;

  case 111: /* suite_while: T_newLine Nodent finalStatements suite_while  */
#line 211 "parser.y"
                                                           {printf("suite_while => \\n Nodent finalStatements suite_while\n\n");}
#line 2464 "y.tab.c"
    break;

  case 112: /* suite_while: T_newLine end_suite_while  */
#line 212 "parser.y"
                                  {printf("suite_while => \\n end_suite_while\n\n");}
#line 2470 "y.tab.c"
    break;

  case 113: /* end_suite_while: Dedent finalStatements  */
#line 214 "parser.y"
                                         {printf("end_suite => Dedent finalStatements\n\n"); li_s = 0; while_code_3();}
#line 2476 "y.tab.c"
    break;

  case 114: /* end_suite_while: Dedent  */
#line 215 "parser.y"
                   {printf("end_suite => Dedent\n\n"); li_s = 0; while_code_3();}
#line 2482 "y.tab.c"
    break;

  case 115: /* $@26: %empty  */
#line 216 "parser.y"
            {li_s = 0; while_code_3();reset_depth();}
#line 2488 "y.tab.c"
    break;

  case 116: /* end_suite_while: $@26 finalStatements  */
#line 216 "parser.y"
                                                                      {printf("end_suite => finalStatements\n\n");}
#line 2494 "y.tab.c"
    break;

  case 117: /* end_suite_while: %empty  */
#line 217 "parser.y"
            {printf("end_suite => epsilon\n\n"); li_s = 0; while_code_3(); reset_depth();}
#line 2500 "y.tab.c"
    break;

  case 118: /* start_suite_func: basic_stmt  */
#line 219 "parser.y"
                              {printf("start_suite_func => basic_stmt\n\n");}
#line 2506 "y.tab.c"
    break;

  case 119: /* start_suite_func: T_newLine Indent finalStatements suite_func  */
#line 220 "parser.y"
                                                          {printf("start_suite_func => \\n Indent finalStatements suite_func\n\n");}
#line 2512 "y.tab.c"
    break;

  case 120: /* suite_func: T_newLine Nodent finalStatements suite_func  */
#line 222 "parser.y"
                                                         {printf("suite_func => \\n Nodent finalStatements suite_func\n\n");}
#line 2518 "y.tab.c"
    break;

  case 121: /* suite_func: T_newLine end_suite_func  */
#line 223 "parser.y"
                                 {printf("suite_func => \\n end_suite_func\n\n");}
#line 2524 "y.tab.c"
    break;

  case 122: /* end_suite_func: Dedent finalStatements  */
#line 225 "parser.y"
                                        {printf("end_suite_func => Dedent finalStatements\n\n");}
#line 2530 "y.tab.c"
    break;

  case 123: /* end_suite_func: Dedent  */
#line 226 "parser.y"
                   {printf("end_suite_func => Dedent\n\n");}
#line 2536 "y.tab.c"
    break;

  case 124: /* $@27: %empty  */
#line 227 "parser.y"
            {dc_flag = 0;func_end(func_name); flag = 0; cur_scope = 0;reset_depth();param_count=0;}
#line 2542 "y.tab.c"
    break;

  case 125: /* end_suite_func: $@27 finalStatements  */
#line 227 "parser.y"
                                                                                                                    {printf("end_suite_func => finalStatements\n\n");}
#line 2548 "y.tab.c"
    break;

  case 126: /* end_suite_func: %empty  */
#line 228 "parser.y"
            {dc_flag = 0;func_end(func_name); reset_depth();param_count=0; printf("end_suite_func => epsilon\n\n");}
#line 2554 "y.tab.c"
    break;

  case 127: /* start_suite: basic_stmt  */
#line 230 "parser.y"
                         {printf("start_suite => basic_stmt\n\n");}
#line 2560 "y.tab.c"
    break;

  case 128: /* start_suite: T_newLine Indent finalStatements suite  */
#line 231 "parser.y"
                                                    {printf("start_suite => \\n Indent finalStatements\n\n");}
#line 2566 "y.tab.c"
    break;

  case 129: /* suite: T_newLine Nodent finalStatements suite  */
#line 233 "parser.y"
                                               {printf("suite => \\n Nodent finalStatements suite\n\n");}
#line 2572 "y.tab.c"
    break;

  case 130: /* suite: T_newLine end_suite  */
#line 234 "parser.y"
                            {printf("suite => \\n end_suite\n\n");}
#line 2578 "y.tab.c"
    break;

  case 131: /* $@28: %empty  */
#line 235 "parser.y"
        {reset_depth();}
#line 2584 "y.tab.c"
    break;

  case 132: /* suite: $@28 elif_stmts  */
#line 235 "parser.y"
                                    {printf("suite => elif_stmts\n\n");}
#line 2590 "y.tab.c"
    break;

  case 133: /* end_suite: Dedent finalStatements  */
#line 237 "parser.y"
                                   {if_code_3(); printf("end_suite => Dedent finalStatements\n\n");}
#line 2596 "y.tab.c"
    break;

  case 134: /* end_suite: Dedent  */
#line 238 "parser.y"
                   {if_code_3(); printf("end_suite => Dedent\n\n");}
#line 2602 "y.tab.c"
    break;

  case 135: /* $@29: %empty  */
#line 239 "parser.y"
            { if_code_3();reset_depth();}
#line 2608 "y.tab.c"
    break;

  case 136: /* end_suite: $@29 finalStatements  */
#line 239 "parser.y"
                                                          {printf("end_suite => finalStatements\n\n");}
#line 2614 "y.tab.c"
    break;

  case 137: /* $@30: %empty  */
#line 240 "parser.y"
            {if_code_3();reset_depth();}
#line 2620 "y.tab.c"
    break;

  case 138: /* end_suite: $@30  */
#line 240 "parser.y"
                                         {printf("end_suite => epsilon\n\n");}
#line 2626 "y.tab.c"
    break;

  case 139: /* $@31: %empty  */
#line 242 "parser.y"
                     {param_arg((yyvsp[0].data), 0); insert("Identifier", (yyvsp[0].data), (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");param_count++; }
#line 2632 "y.tab.c"
    break;

  case 140: /* param: T_identifier $@31 params  */
#line 242 "parser.y"
                                                                                                                                              {printf("params => id params\n\n");}
#line 2638 "y.tab.c"
    break;

  case 141: /* param: %empty  */
#line 242 "parser.y"
                                                                                                                                                                                     {printf("param => epsilon\n\n");}
#line 2644 "y.tab.c"
    break;

  case 142: /* $@32: %empty  */
#line 244 "parser.y"
                              {param_arg((yyvsp[0].data), 0); insert("Identifier", (yyvsp[0].data), (yylsp[-1]).first_line, strlen((yyvsp[0].data)), "null");param_count++;}
#line 2650 "y.tab.c"
    break;

  case 143: /* params: T_comma T_identifier $@32 params  */
#line 244 "parser.y"
                                                                                                                                                      {printf("params => , id params\n\n");}
#line 2656 "y.tab.c"
    break;

  case 144: /* params: %empty  */
#line 244 "parser.y"
                                                                                                                                                                                               {printf("params => epsilon\n\n");}
#line 2662 "y.tab.c"
    break;

  case 145: /* $@33: %empty  */
#line 246 "parser.y"
                                 {param_arg((yyvsp[0].data), 1);arg_count++;}
#line 2668 "y.tab.c"
    break;

  case 148: /* $@34: %empty  */
#line 248 "parser.y"
                             {param_arg((yyvsp[0].data), 1);arg_count++ ;insert("Identifier", (yyvsp[0].data), (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");}
#line 2674 "y.tab.c"
    break;

  case 149: /* list_elements: T_identifier $@34 list_element  */
#line 248 "parser.y"
                                                                                                                                                         {printf("list_elements => id list_element\n\n");}
#line 2680 "y.tab.c"
    break;

  case 150: /* $@35: %empty  */
#line 248 "parser.y"
                                                                                                                                                                                                                      {param_arg((yyvsp[0].data), 1); insert("Constant", (yyvsp[0].data), (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");arg_count++;}
#line 2686 "y.tab.c"
    break;

  case 152: /* $@36: %empty  */
#line 248 "parser.y"
                                                                                                                                                                                                                                                                                                                                                           {param_arg((yyvsp[0].data), 1); insert("Constant", (yyvsp[0].data), (yylsp[0]).first_line, strlen((yyvsp[0].data)), "null");arg_count++;}
#line 2692 "y.tab.c"
    break;

  case 153: /* list_elements: T_string $@36 list_element  */
#line 248 "parser.y"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     {printf("list_elements => string list_element\n\n");}
#line 2698 "y.tab.c"
    break;

  case 154: /* list_elements: %empty  */
#line 248 "parser.y"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             {printf("list_elements => epsilon\n\n");}
#line 2704 "y.tab.c"
    break;


#line 2708 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 251 "parser.y"


void yyerror(const char *msg)
{
	printf("\nSyntax Error at Line %d, Column : %d\n",  yylineno, yylloc.last_column);
	print_symbol_table();
	exit(0);
}

int main()
{
    init_hash_table();
	yyparse();
	return 0;
}
