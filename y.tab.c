/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#define Trace(t) printf(t)
#define MAX_LINE_LENG 256
#include "symbol_table.cpp"

int yyerror(char *s);

extern int yylex(void);
extern symbol_table* current_table;
extern struct DataItem* dummyItem;
extern struct DataItem* item;
extern symbol_table* new_table;
extern stack<symbol_table*> STstack;
int negative_num=0;   //confirm double negative sign

bool is_return=false; //check procedure contains return
bool is_result=false; //check function contains result
int number_function=0;//check result in function
int number_procedure=0;//check return in function

int number_loop=0;//check exit in function
char* function_return_type=new char[10];//check return type
vector<para> current_Arguments;//use in saving input arguments when Function & Procedure Declarations
vector<para> input_Arguments;//save input Arguments
stack<symbol_table*> temp_stack;//used in search ID


#line 99 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 245 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      60,    61,    53,    52,    62,    51,    59,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,     2,
      47,    46,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     2,     2,     2,     2,     2,     2,
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
      45,    49,    50,    55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    58,    59,    60,    61,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    75,    76,    79,
      80,    81,    82,    83,    84,    87,    88,    89,    90,    91,
      92,   105,   137,   164,   165,   166,   167,   168,   222,   262,
     261,   336,   353,   352,   364,   369,   368,   381,   380,   392,
     391,   435,   434,   480,   479,   490,   504,   508,   512,   511,
     585,   590,   591,   600,   610,   665,   722,   798,   802,   879,
     960,   961,   969,   981,  1020,  1062,  1100,  1158,  1170,  1197,
    1222,  1247,  1283,  1284,  1296,  1308,  1320,  1353,  1386,  1411,
    1435,  1448,  1474,  1517,  1559,  1601,  1645,  1670,  1691,  1713,
    1714,  1715,  1716
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "Int", "Real", "ARRAY",
  "Begin", "BOOL", "CHAR", "CONST", "DECREASING", "DEFAULT", "DO", "ELSE",
  "END", "EXIT", "FALSE", "FOR", "FUNCTION", "GET", "IF", "INT", "LOOP",
  "OF", "PUT", "PROCEDURE", "REAL", "RESULT", "RETURN", "SKIP", "STRING",
  "TRUE", "VAR", "WHEN", "THEN", "TYPE", "ID", "String", "R_NUMBER",
  "I_NUMBER", "B_VALUE", "ASSIGN", "OR", "AND", "NE", "'='", "'<'", "'>'",
  "RE", "LE", "'-'", "'+'", "'*'", "'/'", "MOD", "UMINUS", "NOT", "':'",
  "'.'", "'('", "')'", "','", "'['", "']'", "$accept", "INPUT",
  "Declarations", "Expressions", "Statements", "simple_statement",
  "Constants", "Const_values", "Array", "Function_de", "$@1", "RESULT_exp",
  "Condiction", "$@2", "Else_exp", "$@3", "Loop", "$@4", "$@5", "$@6",
  "Block", "$@7", "Exit", "Skip", "Procedure_de", "$@8", "RETURN_exp",
  "Arguments", "Assignment", "Get_input", "Put_output", "Invocation",
  "P_s", "Value_expressions", "Bool_expressions", "Bool_expression",
  "Relation_exp", "Variables", "Type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    61,    60,    62,   301,
     302,    45,    43,    42,    47,   303,   304,   305,    58,    46,
      40,    41,    44,    91,    93
};
# endif

#define YYPACT_NINF -100

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define YYTABLE_NINF -92

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      94,  -100,   -18,     3,     1,    -9,    10,   151,  -100,   151,
      12,   151,  -100,  -100,    13,   -34,    61,    94,    94,  -100,
     111,   111,   111,  -100,  -100,  -100,  -100,  -100,  -100,   111,
    -100,  -100,  -100,  -100,  -100,   111,    94,   -31,   151,    26,
       6,     9,  -100,   -50,  -100,  -100,  -100,  -100,   156,   180,
     151,  -100,  -100,   218,    31,    37,  -100,    94,  -100,   198,
    -100,    15,  -100,   -27,   151,   151,   151,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,    53,   151,    40,  -100,    14,
     151,    36,   151,   156,  -100,  -100,   175,    16,   156,   156,
     156,   156,   156,   156,   156,   156,   156,  -100,   180,   180,
     180,   180,    84,    36,   151,     8,  -100,  -100,   -29,    38,
    -100,  -100,  -100,  -100,  -100,  -100,    58,   151,    44,    50,
      48,    62,   203,  -100,  -100,   -30,   -30,   -30,   -30,    52,
      52,  -100,  -100,  -100,    94,  -100,  -100,  -100,  -100,    93,
      64,  -100,   151,    86,  -100,   151,    87,   151,    73,    74,
      40,    77,  -100,    28,  -100,  -100,    79,   151,  -100,   151,
    -100,    81,   151,    80,    40,  -100,   122,  -100,    94,    90,
    -100,  -100,   151,  -100,    36,  -100,    94,  -100,   130,   151,
    -100,    94,  -100,    94,   135,   117,   133,    94,   143,   144,
     141,  -100,    40,   148,   146,   132,  -100,  -100,   152,  -100,
    -100,  -100
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    53,     0,    56,     0,     0,     0,    82,    47,    82,
       0,    82,    60,    57,     0,     0,     0,     4,     5,    19,
      12,    14,    15,    29,    20,    21,    22,    23,    24,    16,
      28,    25,    26,    27,    30,    13,     6,     0,    82,     0,
       0,     0,    66,    37,    36,    34,    33,    35,     0,     0,
      82,    80,    81,    91,     0,    88,    90,     6,    67,    17,
      18,     0,    41,     0,    82,    70,    82,     1,     2,     3,
       7,     9,    10,    11,     8,     0,    82,     0,    55,     0,
      82,    61,    82,     0,    78,    85,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,     0,     0,    61,    82,     0,    64,    72,     0,     0,
      54,    32,   102,    99,   100,   101,     0,    82,     0,     0,
       0,     0,     0,    79,    89,    95,    92,    94,    93,    74,
      73,    75,    76,    77,     6,    84,    83,    87,    86,     0,
       0,    97,    82,    98,    69,    82,    68,    82,     0,     0,
       0,     0,    68,     0,    48,    58,     0,    82,    71,    82,
      31,     0,    82,    63,     0,    45,     0,    43,     6,     0,
      96,    65,    82,    49,    61,    39,     6,    44,     0,    82,
      51,     6,    62,     6,     0,     0,     0,     6,     0,     0,
       0,    59,     0,     0,     0,     0,    46,    38,     0,    50,
      40,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,   -16,   126,    -6,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,   -96,  -100,  -100,
    -100,     0,  -100,    -4,     2,   -45,  -100,  -100,   -99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    58,    18,    19,    20,    51,    21,    22,
     183,    23,    24,   134,   167,   176,    25,    57,   181,   187,
      26,    36,    27,    28,    29,   168,    30,   120,    31,    32,
      33,    52,   108,    59,    60,    55,    56,    35,   116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    68,    69,    53,    85,    62,   143,   140,    64,    54,
      65,    76,    39,    82,   142,   104,   112,    34,    34,    37,
      75,    92,    93,    94,    95,    96,    65,    77,    41,    66,
     113,   105,   144,   145,    53,   114,    34,    38,    40,   115,
      78,   102,   165,   166,    84,    53,    86,    42,   112,    61,
      63,   163,    87,   135,   136,   137,   138,    34,   106,   107,
     109,    67,   113,    79,    80,   175,    97,   114,   110,    81,
     111,   115,   117,   119,   118,   103,   121,   124,   182,   122,
      98,    99,   100,   101,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   197,    53,    53,    53,    53,   141,   139,
     147,     1,   146,   149,     2,    94,    95,    96,   150,   151,
       3,   148,     4,     5,     6,     7,   154,     8,   153,     9,
      10,     2,    11,    12,    13,   155,   152,    14,   157,   159,
       5,    15,   161,   162,    34,   164,   156,    10,   169,   158,
     172,   160,   174,   177,    14,   185,    70,    71,    72,   179,
     190,   170,   178,   171,   191,    73,   173,   192,   194,   195,
     184,    74,   196,   198,   199,   188,   180,   189,    34,   200,
     201,   193,     0,   186,     0,     0,    34,     0,     0,     0,
       0,    34,     0,    34,     0,     0,     0,    34,    43,    44,
      45,    46,    47,    43,    44,    45,    46,    47,     0,     0,
       0,     0,    48,     0,     0,     0,     0,    48,    49,     0,
       0,    50,     0,     0,     0,     0,    83,    43,    44,    45,
      46,    47,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    48,     0,     0,     0,     0,   123,     0,     0,     0,
      50,   -91,   -91,   -91,   -91,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,   123,    88,    89,    90,    91,    92,
      93,    94,    95,    96
};

static const yytype_int16 yycheck[] =
{
       0,    17,    18,     7,    49,    11,   105,   103,    42,     7,
      60,    42,    11,    63,     6,    42,     8,    17,    18,    37,
      36,    51,    52,    53,    54,    55,    60,    58,    37,    63,
      22,    58,    61,    62,    38,    27,    36,    34,    37,    31,
      38,    57,    14,    15,    48,    49,    50,    37,     8,    37,
      37,   150,    50,    98,    99,   100,   101,    57,    64,    65,
      66,     0,    22,    37,    58,   164,    35,    27,    15,    60,
      76,    31,    58,    37,    80,    60,    82,    61,   174,    83,
      43,    44,    45,    46,    88,    89,    90,    91,    92,    93,
      94,    95,    96,   192,    98,    99,   100,   101,   104,    15,
      42,     7,    64,    59,    10,    53,    54,    55,    58,    61,
      16,   117,    18,    19,    20,    21,    23,    23,   134,    25,
      26,    10,    28,    29,    30,    61,    64,    33,    42,    42,
      19,    37,    59,    59,   134,    58,   142,    26,    59,   145,
      59,   147,    62,    21,    33,    15,    20,    21,    22,    59,
      15,   157,   168,   159,    37,    29,   162,    24,    15,    15,
     176,    35,    21,    15,    18,   181,   172,   183,   168,    37,
      18,   187,    -1,   179,    -1,    -1,   176,    -1,    -1,    -1,
      -1,   181,    -1,   183,    -1,    -1,    -1,   187,    37,    38,
      39,    40,    41,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    51,    57,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    60,    37,    38,    39,
      40,    41,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    51,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      60,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    61,    47,    48,    49,    50,    51,
      52,    53,    54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    10,    16,    18,    19,    20,    21,    23,    25,
      26,    28,    29,    30,    33,    37,    66,    67,    69,    70,
      71,    73,    74,    76,    77,    81,    85,    87,    88,    89,
      91,    93,    94,    95,    96,   102,    86,    37,    34,    11,
      37,    37,    37,    37,    38,    39,    40,    41,    51,    57,
      60,    72,    96,    98,    99,   100,   101,    82,    68,    98,
      99,    37,    68,    37,    42,    60,    63,     0,    66,    66,
      67,    67,    67,    67,    67,    66,    42,    58,    99,    37,
      58,    60,    63,    60,    98,   100,    98,    99,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    35,    43,    44,
      45,    46,    66,    60,    42,    58,    68,    68,    97,    68,
      15,    68,     8,    22,    27,    31,   103,    58,    68,    37,
      92,    68,    98,    61,    61,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    78,   100,   100,   100,   100,    15,
      92,    68,     6,   103,    61,    62,    64,    42,    68,    59,
      58,    61,    64,    66,    23,    61,    68,    42,    68,    42,
      68,    59,    59,   103,    58,    14,    15,    79,    90,    59,
      68,    68,    59,    68,    62,   103,    80,    21,    66,    59,
      68,    83,    92,    75,    66,    15,    68,    84,    66,    66,
      15,    37,    24,    66,    15,    15,    21,   103,    15,    18,
      37,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    73,    75,
      74,    76,    78,    77,    79,    80,    79,    82,    81,    83,
      81,    84,    81,    86,    85,    87,    87,    88,    90,    89,
      91,    92,    92,    92,    93,    93,    94,    95,    96,    96,
      97,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,    99,    99,    99,    99,    99,   100,
     100,   100,   101,   101,   101,   101,   102,   102,   102,   103,
     103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     0,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     4,     1,     1,     1,     1,     1,    10,     0,
      11,     2,     0,     6,     2,     0,     5,     0,     5,     0,
      11,     0,    12,     0,     4,     3,     1,     1,     0,     9,
       1,     0,     5,     3,     3,     6,     2,     2,     4,     4,
       0,     3,     1,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     0,     3,     3,     2,     3,     3,     1,     3,
       1,     1,     3,     3,     3,     3,     6,     4,     4,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 30:
#line 93 "yacc.y" /* yacc.c:1646  */
    {
  if(yyvsp[0].special==1)
  {
    yyerror("Need some variable to save the value.(array)");
  }
  else if(yyvsp[0].special==2)
  {
     yyerror("Need some variable to save the value.(function)");
  }
}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 105 "yacc.y" /* yacc.c:1646  */
    {  
    char* ID_name=(yyvsp[-4].v.Str);
    int index=0;
    if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[-2].type;
      current_table->hashArray[index]->c_v=0;
      current_table->hashArray[index]->special=0;
      if(strcmp(yyvsp[-2].type,yyvsp[0].type)==0)
      {
        if(strcmp(yyvsp[0].type,"INT")==0){current_table->hashArray[index]->value.i=yyvsp[0].v.int_number;}
        else if(strcmp(yyvsp[0].type,"REAL")==0){current_table->hashArray[index]->value.f=yyvsp[0].v.real_number;}
        else if(strcmp(yyvsp[0].type,"STRING")==0){strcpy(current_table->hashArray[index]->value.s,yyvsp[0].v.Str);}
        else if(strcmp(yyvsp[0].type,"BOOL")==0){current_table->hashArray[index]->value.b=yyvsp[0].v.bool_value;}
        else {yyerror("const assignment wrong!!set value=0"); current_table->hashArray[index]->value.i=0;}  
      }
      else
      {
      yyerror("assignment type wrong!");
      }
    }
    else if(current_table->lookup(ID_name)==-2)
    {
       yyerror("simbol table full.");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.");
    }
  }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 137 "yacc.y" /* yacc.c:1646  */
    {
    char* ID_name=(yyvsp[-2].v.Str);
    int index=0;
    if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[0].type;
      current_table->hashArray[index]->c_v=0;
      current_table->hashArray[index]->special=0;
      if(strcmp(yyvsp[0].type,"INT")==0){current_table->hashArray[index]->value.i=yyvsp[0].v.int_number;}
      else if(strcmp(yyvsp[0].type,"REAL")==0){current_table->hashArray[index]->value.f=yyvsp[0].v.real_number;}
      else if(strcmp(yyvsp[0].type,"STRING")==0){strcpy(current_table->hashArray[index]->value.s,yyvsp[0].v.Str);}
      else if(strcmp(yyvsp[0].type,"BOOL")==0){current_table->hashArray[index]->value.b=yyvsp[0].v.bool_value;}
      else {yyerror("const assignment wrong!!set value=0"); current_table->hashArray[index]->value.i=0;  }  
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.");
    }
  }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 164 "yacc.y" /* yacc.c:1646  */
    { yyval.is_var=0;yyval.type="INT";yyval.v.int_number = yyvsp[0].v.int_number; }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 165 "yacc.y" /* yacc.c:1646  */
    { yyval.is_var=0;yyval.type="REAL";yyval.v.real_number = yyvsp[0].v.real_number;}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 166 "yacc.y" /* yacc.c:1646  */
    { yyval.is_var=0;yyval.type="BOOL";yyval.v.bool_value = yyvsp[0].v.bool_value;}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 167 "yacc.y" /* yacc.c:1646  */
    { yyval.is_var=0;yyval.type="STRING";strcpy(yyval.v.Str,yyvsp[0].v.Str);}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 168 "yacc.y" /* yacc.c:1646  */
    {
  char* temp_name=(yyvsp[0].v.Str);
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    if(current_table->hashArray[temp_index]->special==0)
    {
      yyval.special=0;
      yyval.is_var=current_table->hashArray[temp_index]->c_v;
      if (current_table->hashArray[temp_index]->type_name=="INT"){ yyval.type="INT";yyval.v.int_number = current_table->hashArray[temp_index]->value.i;}
      else if(current_table->hashArray[temp_index]->type_name=="REAL"){ yyval.type="REAL";yyval.v.real_number = current_table->hashArray[temp_index]->value.f;}
      else if(current_table->hashArray[temp_index]->type_name=="BOOL"){ yyval.type="BOOL";yyval.v.bool_value = current_table->hashArray[temp_index]->value.b;}
      else if(current_table->hashArray[temp_index]->type_name=="STRING"){ yyval.type="STRING";strcpy(yyval.v.Str,current_table->hashArray[temp_index]->value.s);}
      else {yyerror("ID expression get wrong"); }
    }
    else
    {
      yyerror("ID expression get wrong(not constant/variable)");
    }
  }
  else
  {
    printf("Const_values, ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 223 "yacc.y" /* yacc.c:1646  */
    {   
    char* ID_name=(yyvsp[-8].v.Str);
    int index=0;
    if((yyvsp[-2].is_var)||(yyvsp[-5].is_var))
    {
    yyerror("Expressions not all const.");
    }
    if(current_table->lookup(ID_name)==-1)
    {
      if((strcmp(yyvsp[-2].type,"INT")!=0)||(strcmp(yyvsp[-5].type,"INT")!=0))
      {
        yyerror("Array index type wrong!\n");
      }
      else if ((yyvsp[-5].v.int_number<0)||(yyvsp[-2].v.int_number<yyvsp[-5].v.int_number))
      {
        yyerror("Array index value wrong!\n");
      }
      else
      {
        index=current_table->insert(ID_name);
        current_table->hashArray[index]->type_name=yyvsp[0].type;
        current_table->hashArray[index]->c_v=1;
        current_table->hashArray[index]->special=1;
        current_table->hashArray[index]->start_number=yyvsp[-5].v.int_number;
        current_table->hashArray[index]->end_number=yyvsp[-2].v.int_number;
        }
    }
    else if(current_table->lookup(ID_name)==-2)
    {
       yyerror("Array: simbol table full.");
      exit(-1);
    }
    else
    {
       yyerror("Array:The name already used.");
    }
}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 262 "yacc.y" /* yacc.c:1646  */
    {
    char* ID_name=(yyvsp[-5].v.Str);
    strcat(function_return_type,yyvsp[0].type);
    if(current_table->lookup(ID_name)==-1)
    {
      int index=0;
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->special=2;
      current_table->hashArray[index]->type_name=yyvsp[0].type;
      int i=0;
      for(i=0;i<current_Arguments.size(); i++)
      {
        para temp=current_Arguments[i];
        current_table->hashArray[index]->para_array.push_back(temp);
      }
      symbol_table* Function=creat(ID_name);
      current_table=STstack.top();      
      number_function= number_function+1; 
      for(i=0;i<current_Arguments.size(); i++)
      {
        para temp=current_Arguments[i];
        if(current_table->lookup(temp.p_name)==-1)
        {
           int temp_index=0;
           temp_index=current_table->insert(temp.p_name);
           current_table->hashArray[temp_index]->c_v=1;
           current_table->hashArray[temp_index]->special=0;
           if(strcmp(temp.p_type_name,"INT")==0)current_table->hashArray[temp_index]->type_name="INT";
           else if(strcmp(temp.p_type_name,"REAL")==0)current_table->hashArray[temp_index]->type_name="REAL";
           else if(strcmp(temp.p_type_name,"STRING")==0)current_table->hashArray[temp_index]->type_name="STRING";
           else if(strcmp(temp.p_type_name,"BOOL")==0)current_table->hashArray[temp_index]->type_name="BOOL";
        }
        else if(current_table->lookup(ID_name)==-2)
        {
          yyerror("simbol table full.(function)");
          exit(-1);
        }
        else
        {
           yyerror("The name already used.(function)");
        }
      }
      current_Arguments.clear();
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.(function)");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.(function)");
    }
  }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 317 "yacc.y" /* yacc.c:1646  */
    {
    char* ID_name=(yyvsp[-9].v.Str);
    char* ID_name_2=(yyvsp[0].v.Str);
    if(strcmp(ID_name,ID_name_2)!=0)
    {
      yyerror("the start name is different to final name.(function)");
    }
    dump(current_table);
    if(!is_result)
    {
      yyerror("The function does not contain result.");
    }
    else
    {
      is_result=false;
    }
    number_function=number_function-1;
  }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 337 "yacc.y" /* yacc.c:1646  */
    {
  if(number_function>0)
  {
    if(strcmp(function_return_type,yyvsp[0].type)!=0)
    {
      yyerror("The return type of the function is wrong.");
    }
    is_result=true;
  }
  else
  {
    yyerror("The result is not in a function.");
  }
}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 353 "yacc.y" /* yacc.c:1646  */
    {
  symbol_table* If_table=creat("If_table");
  current_table=STstack.top();
  if(strcmp(yyvsp[-1].type,"BOOL")!=0)
  {
    yyerror("the type of Bool_expressions in condiction is wrong.");
  }
}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 365 "yacc.y" /* yacc.c:1646  */
    {
  dump(current_table);
}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 369 "yacc.y" /* yacc.c:1646  */
    {
  dump(current_table);
  symbol_table* Else_table=creat("Else_table");
  current_table=STstack.top();
}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 375 "yacc.y" /* yacc.c:1646  */
    {
  dump(current_table);
}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 381 "yacc.y" /* yacc.c:1646  */
    {
  symbol_table* Loop_table=creat("Loop_table");
  current_table=STstack.top();
  number_loop= number_loop+1;
}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 387 "yacc.y" /* yacc.c:1646  */
    {
  number_loop= number_loop-1;
  dump(current_table);
}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 392 "yacc.y" /* yacc.c:1646  */
    {
  char* temp_name=(yyvsp[-5].v.Str);
  symbol_table* For_table=creat(temp_name);
  current_table=STstack.top();
  number_loop= number_loop+1;
  if((strcmp(yyvsp[0].type,"INT")!=0)||(strcmp(yyvsp[-3].type,"INT")!=0))
  {
    yyerror("the type of Expressions in for loop is wrong.");
  }
  else if((yyvsp[0].is_var)||(yyvsp[-3].is_var))
  {
    yyerror("Expressions not all const.");
  }
  else if((yyvsp[-3].v.int_number<0)||(yyvsp[0].v.int_number<yyvsp[-3].v.int_number))
  {
    yyerror("the range of Expressions in for loop is wrong.");
  }

  if(current_table->lookup(temp_name)==-1)
  {
    int index=0;
    index=current_table->insert(temp_name);
    current_table->hashArray[index]->special=0;
    current_table->hashArray[index]->c_v=1;
    current_table->hashArray[index]->type_name="INT";
  }
  else if(current_table->lookup(temp_name)==-2)
  {
    yyerror("simbol table full.(function)\n");
    exit(-1);
  }
  else
  {
     yyerror("The name already used.(function)");
  }

}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 430 "yacc.y" /* yacc.c:1646  */
    {
  number_loop= number_loop-1;
  dump(current_table);
}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 435 "yacc.y" /* yacc.c:1646  */
    {
  char* temp_name=(yyvsp[-5].v.Str);
  symbol_table* For_table=creat(temp_name);
  current_table=STstack.top();
  
  number_loop= number_loop+1;
  if((strcmp(yyvsp[0].type,"INT")!=0)||(strcmp(yyvsp[-3].type,"INT")!=0))
  {
    yyerror("the type of Expressions in for loop is wrong.");
  }
  else if((yyvsp[0].is_var)||(yyvsp[-3].is_var))
  {
    yyerror("Expressions not all const(decreasing).");
  }
  else if((yyvsp[0].v.int_number<0)||(yyvsp[-3].v.int_number<yyvsp[0].v.int_number))
  {
    yyerror("the range of Expressions in for loop is wrong(decreasing).");
  }

  if(current_table->lookup(temp_name)==-1)
  {
    int index=0;
    index=current_table->insert(temp_name);
    current_table->hashArray[index]->special=0;
    current_table->hashArray[index]->c_v=1;
    current_table->hashArray[index]->type_name="INT";
  }
  else if(current_table->lookup(temp_name)==-2)
  {
    yyerror("simbol table full.(function)");
    exit(-1);
  }
  else
  {
     yyerror("The name already used.(function)");
  }
}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 473 "yacc.y" /* yacc.c:1646  */
    {
  number_loop= number_loop-1;
  dump(current_table);
}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 480 "yacc.y" /* yacc.c:1646  */
    {
  char* temp_name="block";
  symbol_table* block=creat(temp_name);
  current_table=STstack.top();
}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 486 "yacc.y" /* yacc.c:1646  */
    {
  dump(current_table);
}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 491 "yacc.y" /* yacc.c:1646  */
    {
  if(strcmp(yyvsp[0].type,"BOOL")!=0)
  {
    yyerror("expressions type wrong\n");
  }
  else
  {
    if(yyvsp[0].v.bool_value==true)
    {
      if (number_loop<=0) {yyerror("exit not in the loop");}
    }
  }
}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 504 "yacc.y" /* yacc.c:1646  */
    {
  if (number_loop<=0) {yyerror("exit not in the loop");}
}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 508 "yacc.y" /* yacc.c:1646  */
    { 
}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 512 "yacc.y" /* yacc.c:1646  */
    {
    char* ID_name=(yyvsp[-3].v.Str);
    if(current_table->lookup(ID_name)==-1)
    {
      int index=0;
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->c_v=1;
      current_table->hashArray[index]->special=3;
      int i=0;
      for(i=0;i<current_Arguments.size(); i++)
      {
        para temp=current_Arguments[i];
        current_table->hashArray[index]->para_array.push_back(temp);
      }
      symbol_table* Procedure=creat(ID_name);
      current_table=STstack.top();
      number_procedure= number_procedure+1;
      for(i=0;i<current_Arguments.size(); i++)
      {
        para temp=current_Arguments[i];
        if(current_table->lookup(temp.p_name)==-1)
        {
           int temp_index=0;
           temp_index=current_table->insert(temp.p_name);
           current_table->hashArray[temp_index]->c_v=1;
           current_table->hashArray[temp_index]->special=0;
           if(strcmp(temp.p_type_name,"INT")==0)current_table->hashArray[temp_index]->type_name="INT";
           else if(strcmp(temp.p_type_name,"REAL")==0)current_table->hashArray[temp_index]->type_name="REAL";
           else if(strcmp(temp.p_type_name,"STRING")==0)current_table->hashArray[temp_index]->type_name="STRING";
           else if(strcmp(temp.p_type_name,"BOOL")==0)current_table->hashArray[temp_index]->type_name="BOOL";
        }
        else if(current_table->lookup(ID_name)==-2)
        {
          yyerror("simbol table full.(Procedure)");
          exit(-1);
        }
        else
        {
           yyerror("The name already used.(Procedure)");
        }
      }
      current_Arguments.clear();   
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.\n");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.\n");
    }
  }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 566 "yacc.y" /* yacc.c:1646  */
    {
    char* ID_name=(yyvsp[-7].v.Str);
    char* ID_name_2=(yyvsp[0].v.Str);
    if(strcmp(ID_name,ID_name_2)!=0)
    {
      yyerror("the start name is different to final name.(Procedure)");
    }
    dump(current_table);
    if(!is_return)
    {
      yyerror("The procedure does not contain return.");
    }
    else
    {
      is_return=false;
    }
    number_procedure=number_procedure-1;
  }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 585 "yacc.y" /* yacc.c:1646  */
    {
  if (number_procedure>0) {is_return=true;}
  else {yyerror("RETURN not in the procedure");}
}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 592 "yacc.y" /* yacc.c:1646  */
    {
  para temp_Argument;
  char* temp_name=(yyvsp[-4].v.Str);
  char* temp_type_name=yyvsp[-2].type;
  strcpy(temp_Argument.p_name,temp_name);
  strcpy(temp_Argument.p_type_name,temp_type_name);
  current_Arguments.push_back(temp_Argument);
}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 601 "yacc.y" /* yacc.c:1646  */
    {
  para temp_Argument;
  char* temp_name=(yyvsp[-2].v.Str);
  char* temp_type_name=yyvsp[0].type;
  strcpy(temp_Argument.p_name,temp_name);
  strcpy(temp_Argument.p_type_name,temp_type_name);
  current_Arguments.push_back(temp_Argument);
}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 611 "yacc.y" /* yacc.c:1646  */
    {
  char* temp_name=(yyvsp[-2].v.Str);
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    if(current_table->hashArray[temp_index]->special==0)
    {
      if(current_table->hashArray[temp_index]->c_v==0){yyerror("const can not assignment!!");}
      else
      {
        if(strcmp(current_table->hashArray[temp_index]->type_name,yyvsp[0].type)!=0)
        {
          yyerror("assignment type different!");
        }
      }
    }
    else
    {
      printf("Assign wrong, id:%s not constant/variable.\n",temp_name);
    }
  }
  else
  {
    printf("Assign wrong: ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 666 "yacc.y" /* yacc.c:1646  */
    {
  char* temp_name=(yyvsp[-5].v.Str);
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    if(current_table->hashArray[temp_index]->special==1)
    {
      if(current_table->hashArray[temp_index]->c_v==0){yyerror("const can not assignment!!");}
      else if(strcmp(current_table->hashArray[temp_index]->type_name,yyvsp[0].type)!=0)
      {
        yyerror("assignment type different!");
      }
      else if((yyvsp[-3].v.int_number<current_table->hashArray[temp_index]->start_number)||(yyvsp[-3].v.int_number>current_table->hashArray[temp_index]->end_number))
      {
        printf("Array, index value from expressions not correct.\n",temp_name);
      }
    }
    else
    {
      printf("Assign wrong, id:%s not array.\n",temp_name);
    }
  }
  else
  {
    printf("Assign wrong: ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 722 "yacc.y" /* yacc.c:1646  */
    {
  char* temp_name=(yyvsp[0].v.Str);
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    if(current_table->hashArray[temp_index]->special==0)
    {
      if(current_table->hashArray[temp_index]->c_v!=0)
      {
        yyval.special=0;
        yyval.is_var=current_table->hashArray[temp_index]->c_v;
        if(strcmp(current_table->hashArray[temp_index]->type_name,"REAL")==0)
        {
          yyval.type="REAL";
          yyval.v.real_number=current_table->hashArray[temp_index]->value.f;
        }
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"INT")==0)
        {
          yyval.type="INT";
          yyval.v.int_number=current_table->hashArray[temp_index]->value.i;
        }
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"BOOL")==0)
        {
          yyval.type="BOOL";
          yyval.v.bool_value=current_table->hashArray[temp_index]->value.b;
        } 
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"STRING")==0)
        {
          yyval.type="STRING";
          strcpy(yyval.v.Str,current_table->hashArray[temp_index]->value.s); 
        }
      }
      else
      {
        printf("Get wrong, id:%s is constant.\n",temp_name);
      }
    }
    else
    {
      printf("Get wrong, id:%s not constant/variable.\n",temp_name);
    }
  }
  else
  {
    printf("Get wrong: ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
}
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 798 "yacc.y" /* yacc.c:1646  */
    {
  
}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 803 "yacc.y" /* yacc.c:1646  */
    {
  char* temp_name=(yyvsp[-3].v.Str);
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    if(current_table->hashArray[temp_index]->special==1)
    {
      yyval.special=1;
      if((current_table->hashArray[temp_index]->special !=1)||(strcmp(yyvsp[-1].type,"INT")!=0))
      {
        printf("Array: id:%s not array, or value of expressions not int.\n",temp_name);
      }
      else if((yyvsp[-1].v.int_number<current_table->hashArray[temp_index]->start_number)||(yyvsp[-1].v.int_number>current_table->hashArray[temp_index]->end_number))
      {
        printf("Array: index value from expressions not correct.\n",temp_name);
      }
      else if(yyvsp[-1].is_var!=0)
      {
        printf("Array: index value from expressions not const.\n",temp_name);
      }
             
        if(strcmp(current_table->hashArray[temp_index]->type_name,"REAL")==0)
        {
          yyval.type="REAL";
        }
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"INT")==0)
        {
          yyval.type="INT";
        }
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"BOOL")==0)
        {
          yyval.type="BOOL";
        } 
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"STRING")==0)
        {
          yyval.type="STRING";
        }
    }
    else
    {
      printf("Invocation wrong, id:%s not array.\n",temp_name);
    }
  }
  else
  {
    printf("Invocation wrong(array): ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 880 "yacc.y" /* yacc.c:1646  */
    {
  char* temp_name=(yyvsp[-3].v.Str);
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    int j=0;
    bool check_input_Argu=true;
    if((current_table->hashArray[temp_index]->special==2)||(current_table->hashArray[temp_index]->special==3))
    {
        if(current_table->hashArray[temp_index]->special==2)
        {
          yyval.special=2;
        }
        else if(current_table->hashArray[temp_index]->special==3)
        {
          yyval.special=3;
        }
        yyval.type=current_table->hashArray[temp_index]->type_name;
        if(current_table->hashArray[temp_index]->para_array.size()!=input_Arguments.size())
        {
          yyerror("argument of function/procedure is wrong(different quantity).");
        }
        else
        {
          for(j=0;j<current_table->hashArray[temp_index]->para_array.size();j++)
          {
            if(strcmp(current_table->hashArray[temp_index]->para_array[j].p_type_name,input_Arguments[j].p_type_name)!=0)
            {
              check_input_Argu=false;
              break;
            }
          }
          if(!check_input_Argu)
          {
            yyerror("arguments of function/procedure are wrong type.");
          }
        }
        input_Arguments.clear();
    }
    else
    {
      yyerror("ID expression get wrong(not function/procedure)\n");
    }
  }
  else
  {
    printf("Invocation wrong(function/procedure): ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
  
}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 962 "yacc.y" /* yacc.c:1646  */
    {
  para temp_Argument;
  char* temp_type_name=yyvsp[0].type;
  strcpy(temp_Argument.p_type_name,temp_type_name);
  input_Arguments.push_back(temp_Argument);
 
}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 970 "yacc.y" /* yacc.c:1646  */
    {
  para temp_Argument;
  char* temp_type_name=yyvsp[0].type;
  strcpy(temp_Argument.p_type_name,temp_type_name);
   yyval.is_var=yyvsp[0].is_var;
  input_Arguments.push_back(temp_Argument);

}
#line 2508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 982 "yacc.y" /* yacc.c:1646  */
    {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
    {
      yyerror("string can not addition.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0))
    {
      yyerror("bool can not addition.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"REAL")==0)||(strcmp(yyvsp[-2].type,"REAL")==0))
    {
      yyval.type="REAL";
      if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.v.real_number = yyvsp[0].v.real_number+yyvsp[-2].v.real_number;
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.v.real_number = yyvsp[0].v.real_number+yyvsp[-2].v.int_number;
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.v.real_number = yyvsp[0].v.int_number+yyvsp[-2].v.real_number;
      }
      else {yyerror("real addtion something wrong.");}
    }
    else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
    {
      yyval.type="INT";
      yyval.v.int_number = yyvsp[0].v.int_number+yyvsp[-2].v.int_number;
    }
    else {yyerror("addtion something wrong.");} 
}
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1020 "yacc.y" /* yacc.c:1646  */
    {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
    {
      yyerror("string can not subtraction.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0))
    {
      yyerror("bool can not subtraction.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"REAL")==0)||(strcmp(yyvsp[-2].type,"REAL")==0))
    {
      yyval.type="REAL";
      if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        if(yyvsp[0].v.real_number<0 && negative_num > 0 ){yyerror("sub+minus");}
        yyval.v.real_number = yyvsp[-2].v.real_number-yyvsp[0].v.real_number;
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        if(yyvsp[0].v.real_number<0 && negative_num > 0 ){yyerror("sub+minus");}
        yyval.v.real_number = yyvsp[-2].v.int_number-yyvsp[0].v.real_number;
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        if(yyvsp[0].v.int_number<0 && negative_num > 0 ){yyerror("sub+minus");}
        yyval.v.real_number = yyvsp[-2].v.real_number-yyvsp[0].v.int_number;
      }
      else {yyerror("real subtraction something wrong.");}
    }
    else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
    {
      yyval.type="INT";
      if(yyvsp[0].v.int_number<0 && negative_num > 0 ){yyerror("sub+minus");}
      yyval.v.int_number = yyvsp[-2].v.int_number-yyvsp[0].v.int_number;  
    }
    else {yyerror("subtraction something wrong.");}
}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1062 "yacc.y" /* yacc.c:1646  */
    {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
    {
      yyerror("string can not multiplication.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0))
    {
      yyerror("bool can not multiplication.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"REAL")==0)||(strcmp(yyvsp[-2].type,"REAL")==0))
    {
      yyval.type="REAL";
      if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.v.real_number = yyvsp[0].v.real_number*yyvsp[-2].v.real_number;
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.v.real_number = yyvsp[0].v.real_number*yyvsp[-2].v.int_number;
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.v.real_number = yyvsp[0].v.int_number*yyvsp[-2].v.real_number;
      }
      else {yyerror("real multiplication something wrong.\n");}
    }
    else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
    {
      yyval.type="INT";
      yyval.v.int_number = yyvsp[0].v.int_number*yyvsp[-2].v.int_number;
    }
    else {yyerror("multiplication something wrong.");}
}
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1100 "yacc.y" /* yacc.c:1646  */
    { 
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
    {
      yyerror("string can not division.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0))
    {
      yyerror("bool can not division.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"REAL")==0)||(strcmp(yyvsp[-2].type,"REAL")==0))
    {
      yyval.type="REAL";
      if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        if(yyvsp[0].v.real_number==0.0)
        {
          yyerror("divide by zero");
          yyval.v.real_number=0.0;
        }
        else{yyval.v.real_number = yyvsp[-2].v.real_number/yyvsp[0].v.real_number;}  
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        if(yyvsp[0].v.real_number==0.0)
        {
          yyerror("divide by zero");
          yyval.v.real_number=0.0;
        }
        else{yyval.v.real_number = yyvsp[-2].v.int_number/yyvsp[0].v.real_number;}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        if(yyvsp[0].v.int_number==0)
        {
          yyerror("divide by zero");
          yyval.v.real_number=0.0;
        }
        else{yyval.v.real_number = yyvsp[-2].v.real_number/yyvsp[0].v.int_number;}
      }
      else {yyerror("real division something wrong.\n");}
    }
    else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
    {
      yyval.type="INT";
       if(yyvsp[0].v.int_number==0)
        {
        yyerror("divide by zero");
        yyval.v.int_number=0;
        }
        else{yyval.v.int_number = yyvsp[-2].v.int_number/yyvsp[0].v.int_number;}
    }
    else {yyerror("division something wrong.");}
}
#line 2704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1158 "yacc.y" /* yacc.c:1646  */
    {  
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
    {
      yyval.type="INT";
      yyval.v.int_number=yyvsp[-2].v.int_number % yyvsp[0].v.int_number;
    }
    else
    {
      yyerror("type != int, can not mod.");
    }
}
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1170 "yacc.y" /* yacc.c:1646  */
    {
    yyval.is_var=yyvsp[0].is_var; 
    if(strcmp(yyvsp[0].type,"STRING")==0)
    {
      yyerror("string can not negative.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
    {
      yyerror("bool can not negative.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"REAL")==0))
    {
      yyval.type="REAL";
      if(yyvsp[0].v.real_number<0 && negative_num > 0 ){yyerror("sub+minus");}
      else{ yyval.v.real_number = yyvsp[0].v.real_number*(-1);negative_num=negative_num+1;}
    }
    else if((strcmp(yyvsp[0].type,"INT")==0))
    {
      yyval.type="INT";
      if(yyvsp[0].v.int_number<0 && negative_num > 0){yyerror("sub+minus");}
      else{ yyval.v.int_number = yyvsp[0].v.int_number*(-1);negative_num=negative_num+1;}   
    }
}
#line 2753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1197 "yacc.y" /* yacc.c:1646  */
    {
  negative_num=0 ; 
  yyval.is_var=yyvsp[-1].is_var;
    if(strcmp(yyvsp[-1].type,"REAL")==0)
      {
        yyval.type="REAL";
        yyval.v.real_number=yyvsp[-1].v.real_number;
      }
    else if(strcmp(yyvsp[-1].type,"INT")==0)
      {
        yyval.type="INT";
        yyval.v.int_number=yyvsp[-1].v.int_number;
      }
    else if(strcmp(yyvsp[-1].type,"BOOL")==0)
      {
        yyval.type="BOOL";
        yyval.v.bool_value=yyvsp[-1].v.bool_value;
      } 
    else if(strcmp(yyvsp[-1].type,"STRING")==0)
      {
        yyval.type="STRING";
        strcpy(yyval.v.Str,yyvsp[-1].v.Str);
      }
    else {yyerror("() assign something wrong.");}
 }
#line 2783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1223 "yacc.y" /* yacc.c:1646  */
    {
  yyval.is_var=yyvsp[0].is_var;
   if(strcmp(yyvsp[0].type,"REAL")==0)
      {
        yyval.type="REAL";
        yyval.v.real_number=yyvsp[0].v.real_number;
      }
    else if(strcmp(yyvsp[0].type,"INT")==0)
      {
        yyval.type="INT";
        yyval.v.int_number=yyvsp[0].v.int_number;
      }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
      {
        yyval.type="BOOL";
        yyval.v.bool_value=yyvsp[0].v.bool_value;
      } 
    else if(strcmp(yyvsp[0].type,"STRING")==0)
      {
        yyval.type="STRING";
        strcpy(yyval.v.Str,yyvsp[0].v.Str);
      }
    else {yyerror("Const_values something wrong.");}
}
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1248 "yacc.y" /* yacc.c:1646  */
    {
   if(yyvsp[0].special==3)
   {
     yyerror("The procedure cannot be calculated, so it returns 0 instead.");
     yyval.type="INT";
     yyval.v.int_number=0;
   }
   else
   {
     yyval.is_var=yyvsp[0].is_var;
     if(strcmp(yyvsp[0].type,"REAL")==0)
        {
          yyval.type="REAL";
          yyval.v.real_number=yyvsp[0].v.real_number;
        }
      else if(strcmp(yyvsp[0].type,"INT")==0)
        {
          yyval.type="INT";
          yyval.v.int_number=yyvsp[0].v.int_number;
        }
      else if(strcmp(yyvsp[0].type,"BOOL")==0)
        {
          yyval.type="BOOL";
          yyval.v.bool_value=yyvsp[0].v.bool_value;
        } 
      else if(strcmp(yyvsp[0].type,"STRING")==0)
        {
          yyval.type="STRING";
          strcpy(yyval.v.Str,yyvsp[0].v.Str);
        }
      else {yyerror("Invocation something wrong.");}
    }
}
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1284 "yacc.y" /* yacc.c:1646  */
    {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if((strcmp(yyvsp[0].type,"BOOL")!=0)||(strcmp(yyvsp[-2].type,"BOOL")!=0)){
    yyerror("type wrong, can not AND, use false instead");
    yyval.v.bool_value=false;
  }
  else
  {
    yyval.v.bool_value=(yyvsp[0].v.bool_value)&&(yyvsp[-2].v.bool_value);
  }
}
#line 2867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1296 "yacc.y" /* yacc.c:1646  */
    {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if((strcmp(yyvsp[0].type,"BOOL")!=0)||(strcmp(yyvsp[-2].type,"BOOL")!=0)){
    yyerror("type wrong, can not OR, use false instead");
    yyval.v.bool_value=false;
  }
  else
  {
    yyval.v.bool_value=(yyvsp[0].v.bool_value)||(yyvsp[-2].v.bool_value);
  }
}
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1308 "yacc.y" /* yacc.c:1646  */
    {
   yyval.type="BOOL";
   yyval.is_var=yyvsp[0].is_var;
  if(strcmp(yyvsp[0].type,"BOOL")!=0){
    yyerror("type wrong, can not NOT, use false instead");
    yyval.v.bool_value=false;
  }
  else
  {
    yyval.v.bool_value=!(yyvsp[0].v.bool_value);
  }
  }
#line 2901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1320 "yacc.y" /* yacc.c:1646  */
    {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if(strcmp(yyvsp[0].type,yyvsp[-2].type)==0)
  {
    if(strcmp(yyvsp[0].type,"INT")==0)
    {
      if((yyvsp[0].v.int_number)==(yyvsp[-2].v.int_number)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}
    }
    else if(strcmp(yyvsp[0].type,"REAL")==0)
    {
      if((yyvsp[0].v.real_number)==(yyvsp[-2].v.real_number)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}
    }
    else if(strcmp(yyvsp[0].type,"STRING")==0)
    {
      if(strcmp(yyvsp[0].v.Str,yyvsp[-2].v.Str)==0){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}    
    }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
    {
      if((yyvsp[0].v.bool_value)==(yyvsp[-2].v.bool_value)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}    
    }
    else {yyerror("Bool_expressions '=' Bool_expressions, wrong");}
  }
  else
  {
    printf("%s, %s can not be compare,use false instead\n",yyvsp[0].type,yyvsp[-2].type);
    yyval.v.bool_value=false;
  }
}
#line 2939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1353 "yacc.y" /* yacc.c:1646  */
    {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if(strcmp(yyvsp[0].type,yyvsp[-2].type)==0)
  {
    if(strcmp(yyvsp[0].type,"INT")==0)
    {
      if((yyvsp[0].v.int_number)!=(yyvsp[-2].v.int_number)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}
    }
    else if(strcmp(yyvsp[0].type,"REAL")==0)
    {
      if((yyvsp[0].v.real_number)!=(yyvsp[-2].v.real_number)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}    
    }
    else if(strcmp(yyvsp[0].type,"STRING")==0)
    {
      if(strcmp(yyvsp[0].v.Str,yyvsp[-2].v.Str)!=0){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}    
    }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
    {
      if((yyvsp[0].v.bool_value)!=(yyvsp[-2].v.bool_value)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}    
    }
    else {yyerror("Bool_expressions '=' Bool_expressions, wrong");}
  }
  else
  {
    printf("%s, %s can not be compare,use false instead\n",yyvsp[0].type,yyvsp[-2].type);
    yyval.v.bool_value=false;
  }
}
#line 2977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1386 "yacc.y" /* yacc.c:1646  */
    {
    yyval.is_var=yyvsp[0].is_var;
    if(strcmp(yyvsp[0].type,"REAL")==0)
      {
        yyval.type="REAL";
        yyval.v.real_number=yyvsp[0].v.real_number;
      }
    else if(strcmp(yyvsp[0].type,"INT")==0)
      {
        yyval.type="INT";
        yyval.v.int_number=yyvsp[0].v.int_number;
      }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
      {
        yyval.type="BOOL";
        yyval.v.bool_value=yyvsp[0].v.bool_value;
      } 
    else if(strcmp(yyvsp[0].type,"STRING")==0)
      {
        yyval.type="STRING";
        strcpy(yyval.v.Str,yyvsp[0].v.Str);
      }
    else {yyerror("Bool_expression:something wrong.");}
}
#line 3006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1411 "yacc.y" /* yacc.c:1646  */
    {
    yyval.is_var=yyvsp[-1].is_var;
    if(strcmp(yyvsp[-1].type,"REAL")==0)
      {
        yyval.type="REAL";
        yyval.v.real_number=yyvsp[-1].v.real_number;
      }
    else if(strcmp(yyvsp[-1].type,"INT")==0)
      {
        yyval.type="INT";
        yyval.v.int_number=yyvsp[-1].v.int_number;
      }
    else if(strcmp(yyvsp[-1].type,"BOOL")==0)
      {
        yyval.type="BOOL";
        yyval.v.bool_value=yyvsp[-1].v.bool_value;
      } 
    else if(strcmp(yyvsp[-1].type,"STRING")==0)
      {
        yyval.type="STRING";
        strcpy(yyval.v.Str,yyvsp[-1].v.Str);
      }
    else {yyerror("Bool_expression:()something wrong.");}
 }
#line 3035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1435 "yacc.y" /* yacc.c:1646  */
    {
    yyval.type="BOOL";
    yyval.is_var=yyvsp[0].is_var;
    if(strcmp(yyvsp[0].type,"BOOL")==0)
    {
      yyval.v.bool_value=yyvsp[0].v.bool_value;
    }
    else
    {
      printf("Relation_exp type wrong, use false instead\n");
      yyval.v.bool_value=false;
    }
}
#line 3053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1448 "yacc.y" /* yacc.c:1646  */
    {
   yyval.is_var=yyvsp[0].is_var;
   if(strcmp(yyvsp[0].type,"REAL")==0)
      {
        yyval.type="REAL";
        yyval.v.real_number=yyvsp[0].v.real_number;
      }
    else if(strcmp(yyvsp[0].type,"INT")==0)
      {
        yyval.type="INT";
        yyval.v.int_number=yyvsp[0].v.int_number;
      }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
      {
        yyval.type="BOOL";
        yyval.v.bool_value=yyvsp[0].v.bool_value;
      } 
    else if(strcmp(yyvsp[0].type,"STRING")==0)
      {
        yyval.type="STRING";
        strcpy(yyval.v.Str,yyvsp[0].v.Str);
      }
    else {yyerror("Bool_expression、Value_expressions something wrong.");}
}
#line 3082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1475 "yacc.y" /* yacc.c:1646  */
    {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0)){ yyval.type="BOOL";yyval.v.bool_value =false; yyerror("bool can not be compared:>, will return the default value: false ");}
    else
    {
      if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
      {
        if(yyvsp[0].type==yyvsp[-2].type)
        {
          
          if((strcmp(yyvsp[-2].v.Str,yyvsp[0].v.Str))>0){yyval.type="BOOL";yyval.v.bool_value =true;}
          else {yyval.type="BOOL";yyval.v.bool_value =false;}
        }
        else{yyval.type="BOOL";yyval.v.bool_value =false; yyerror("string can not be compared:>, will return the default value: false ");}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number>yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number>yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number>yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number>yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else { yyval.type="BOOL";yyerror("Relation_item > Relation_item : wrong ");}
    } 
 }
#line 3129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1517 "yacc.y" /* yacc.c:1646  */
    {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0)){ yyval.type="BOOL";yyval.v.bool_value =false; yyerror("bool can not be compared:>=, will return the default value: false");}
    else
    {
      if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
      {
        if(yyvsp[0].type==yyvsp[-2].type)
        {
          yyval.type="BOOL";
          if((strcmp(yyvsp[-2].v.Str,yyvsp[0].v.Str))>=0){yyval.type="BOOL";yyval.v.bool_value =true;}
          else {yyval.type="BOOL";yyval.v.bool_value =false;}
        }
        else{yyval.type="BOOL";yyval.v.bool_value =false; yyerror("string can not be compared:>=, will return the default value: false");}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number>=yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number>=yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number>=yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number>=yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else {yyerror("Relation_item >= Relation_item : wrong");}
    }  
}
#line 3176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1559 "yacc.y" /* yacc.c:1646  */
    {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0)){ yyval.type="BOOL";yyval.v.bool_value =false; yyerror("bool can not be compared:<=, will return the default value: false");}
    else
    {
      if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
      {
        if(yyvsp[0].type==yyvsp[-2].type)
        {
          yyval.type="BOOL";
          if((strcmp(yyvsp[-2].v.Str,yyvsp[0].v.Str))<=0){yyval.type="BOOL";yyval.v.bool_value =true;}
          else {yyval.type="BOOL";yyval.v.bool_value =false;}
        }
        else{yyval.type="BOOL";yyval.v.bool_value =false; yyerror("string can not be compared:<=, will return the default value: false");}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number<=yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number<=yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number<=yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number<=yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else { yyerror("Relation_item > Relation_item : wrong");}
    }  
  }
#line 3223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1601 "yacc.y" /* yacc.c:1646  */
    {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0)){ yyval.type="BOOL";yyval.v.bool_value =false; yyerror("bool can not be compared:<, will return the default value: false");}
    else
    {
      if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
      {
        if(yyvsp[0].type==yyvsp[-2].type)
        {
          yyval.type="BOOL";
          if((strcmp(yyvsp[-2].v.Str,yyvsp[0].v.Str))<0){yyval.type="BOOL";yyval.v.bool_value =true;}
          else {yyval.type="BOOL";yyval.v.bool_value =false;}
        }
        else{yyval.type="BOOL";yyval.v.bool_value =false; yyerror("string can not be compared:>, will return the default value: false");}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number<yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number<yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number<yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number<yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else { yyerror("Relation_item > Relation_item : wrong");}
    } 
}
#line 3270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1645 "yacc.y" /* yacc.c:1646  */
    {
    char* ID_name=(yyvsp[-4].v.Str);
    int index=0;

    if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[-2].type;
      current_table->hashArray[index]->c_v=1;
      current_table->hashArray[index]->special=0;
      if(strcmp(yyvsp[-2].type,yyvsp[0].type)!=0)
      {
         yyerror("assignment type wrong!"); 
      } 
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.\n");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.");
    }
  }
#line 3300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1670 "yacc.y" /* yacc.c:1646  */
    {
    char* ID_name=(yyvsp[-2].v.Str);
    int index=0;

    if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[0].type;
      current_table->hashArray[index]->c_v=1;
      current_table->hashArray[index]->special=0;
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.");
    }
  }
#line 3326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1691 "yacc.y" /* yacc.c:1646  */
    {
  char* ID_name=(yyvsp[-2].v.Str);
  int index=0;
  if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[0].type;
      current_table->hashArray[index]->c_v=1;
      current_table->hashArray[index]->special=0;
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.");
    }
  }
#line 3351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1713 "yacc.y" /* yacc.c:1646  */
    {yyval.type="INT";}
#line 3357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1714 "yacc.y" /* yacc.c:1646  */
    {yyval.type="REAL";}
#line 3363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1715 "yacc.y" /* yacc.c:1646  */
    {yyval.type="STRING";}
#line 3369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1716 "yacc.y" /* yacc.c:1646  */
    {yyval.type="BOOL";}
#line 3375 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3379 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1719 "yacc.y" /* yacc.c:1906  */


int yyerror(char *s)//output warning message
{
fprintf(stderr, "%s\n", s);
return 0;
}

int main(int argc, char *argv[])
{
  FILE *yyin;

	if ( argc > 0 )
  {
  yyin = fopen( argv[1], "r" );
  }
	else
   {
      printf("input file fail\n");
		  yyin = stdin;
   }

  dummyItem = (struct DataItem*)malloc(sizeof(struct DataItem));
  strcpy(dummyItem->name,"\0");
  
  symbol_table* main=creat("main_table");
  current_table=STstack.top();
/* perform parsing */

  if (yyparse() == 1) /* parsing */
    {yyerror("Parsing error !"); }/* syntax error */

  main=dump(main);
  return 0;
}
