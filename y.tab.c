/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#define Trace(t) printf(t)
#define MAX_LINE_LENG 256
#include "symbol_table.cpp"

int yyerror(char *s);
void yyrestart  (FILE * input_file );

extern int yylex(void);
extern void yyrestart ( FILE *input_file  );
extern symbol_table* current_table;
extern struct DataItem* dummyItem;
extern struct DataItem* item;
extern symbol_table* new_table;
extern stack<symbol_table*> STstack;
extern int yylex(void);
extern bool Opt_L;
extern int linenum;
extern char buf[MAX_LINE_LENG];

int L_index=0;
int negative_num=0;   //confirm double negative sign
char* class_name=new char[MAX_LINE_LENG];//save class name
bool is_return=false; //check procedure contains return
bool is_result=false; //check function contains result
int number_function=0;//check result in function
int number_procedure=0;//check return in function
bool is_main=false;//check the main class created or not

int number_loop=0;//check exit in function
char* function_return_type=new char[10];//check return type
vector<para> current_Arguments;//use in saving input arguments when Function & Procedure Declarations
vector<para> input_Arguments;//save input Arguments
stack<symbol_table*> temp_stack;//used in search ID
stack<int> loop_stack;//save loops exit place
stack<int> if_stack;//save begin place of if 
stack<int> counter_stack;//save the index of counter in the current symbol table
int variables_count=0;//recorde variables index


#line 116 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYLAST   249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    70,    82,    85,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    99,   100,   103,   104,
     105,   106,   107,   108,   111,   112,   113,   114,   115,   116,
     129,   161,   188,   189,   190,   191,   192,   259,   299,   298,
     385,   403,   402,   419,   426,   425,   442,   441,   460,   542,
     459,   586,   668,   585,   712,   711,   722,   737,   742,   757,
     756,   842,   848,   849,   858,   868,   934,   991,  1068,  1067,
    1091,  1168,  1249,  1250,  1258,  1269,  1319,  1371,  1418,  1487,
    1508,  1544,  1569,  1626,  1662,  1663,  1683,  1703,  1727,  1769,
    1811,  1836,  1860,  1873,  1899,  1950,  2001,  2052,  2105,  2162,
    2213,  2252,  2253,  2254,  2255
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
  "'.'", "'('", "')'", "','", "'['", "']'", "$accept", "INPUT", "$@1",
  "Declarations", "Expressions", "Statements", "simple_statement",
  "Constants", "Const_values", "Array", "Function_de", "$@2", "RESULT_exp",
  "Condiction", "$@3", "Else_exp", "$@4", "Loop", "$@5", "$@6", "$@7",
  "$@8", "$@9", "Block", "$@10", "Exit", "Skip", "Procedure_de", "$@11",
  "RETURN_exp", "Arguments", "Assignment", "Get_input", "Put_output",
  "$@12", "Invocation", "P_s", "Value_expressions", "Bool_expressions",
  "Bool_expression", "Relation_exp", "Variables", "Type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
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

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-94)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     175,   -95,   -31,   -27,    -6,   -20,    -9,    73,   -95,   -95,
      -4,    73,   -95,   -95,    11,   -41,    51,   -95,   175,   -95,
       4,     4,     4,   -95,   -95,   -95,   -95,   -95,   -95,     4,
     -95,   -95,   -95,   -95,   -95,     4,   175,   -34,    73,    32,
      16,    -5,   -95,   -21,   -95,   -95,   -95,   -95,    40,    73,
      73,   -95,   -95,   194,    47,   123,   -95,   175,    73,    15,
     -95,   185,   -95,   -26,    73,    73,    73,   -95,   175,   -95,
     -95,   -95,   -95,   -95,   -95,    71,    73,    18,   -95,    30,
      73,    53,    73,    40,   -95,   -95,   166,    42,    40,    40,
      40,    40,    40,    40,    40,    40,    40,   -95,    73,    73,
     114,   114,    78,   -95,    53,    73,     7,   -95,   -95,   -18,
      37,   -95,   -95,   -95,   -95,   -95,   -95,   -95,    62,    73,
      50,    48,    -8,    44,    64,   -95,   -95,   106,   106,   106,
     106,    12,    12,   -95,   -95,   -95,   175,   -95,   -95,   -95,
     -95,    98,    -2,   -95,    73,    81,   -95,    73,    84,    73,
      68,   -95,    18,    76,    94,   -95,    57,   -95,   -95,    87,
      73,   -95,    73,   -95,   -95,   103,   -95,    18,    77,   -95,
     142,   -95,   175,   112,   -95,   -95,   116,    73,   -95,    18,
     175,   -95,   158,    73,    73,   -95,   175,   -95,   162,   141,
     155,   -95,   175,   168,   163,   -95,    18,   175,   172,   151,
     -95,   -95,   174,   181,   -95,   184,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    54,     0,    57,     0,     0,     0,    84,    46,    68,
       0,    84,    61,    58,     0,     0,     0,     2,     5,    18,
      11,    13,    14,    28,    19,    20,    21,    22,    23,    15,
      27,    24,    25,    26,    29,    12,     5,     0,    84,     0,
       0,     0,    67,    36,    35,    33,    32,    34,     0,    84,
      84,    82,    83,    93,     0,    90,    92,     5,    84,     0,
      40,    16,    17,     0,    84,    72,    84,     1,     5,     4,
       6,     8,     9,    10,     7,     0,    84,     0,    56,     0,
      84,    62,    84,     0,    80,    87,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    84,    84,
       0,     0,     0,    69,    62,    84,     0,    65,    74,     0,
       0,     3,    55,    31,   104,   101,   102,   103,     0,    84,
       0,     0,     0,     0,     0,    81,    91,    97,    94,    96,
      95,    76,    75,    77,    78,    79,     5,    86,    85,    89,
      88,     0,     0,    99,    84,   100,    71,    84,    70,    84,
       0,    48,     0,     0,     0,    70,     0,    47,    59,     0,
      84,    73,    84,    30,    51,     0,    63,     0,     0,    44,
       0,    42,     5,     0,    98,    66,     0,    84,    38,     0,
       5,    43,     0,    84,    84,    49,     5,    64,     0,     0,
       0,    52,     5,     0,     0,    60,     0,     5,     0,     0,
      45,    37,     0,     0,    39,     0,    50,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -16,   -95,    41,   -55,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
      86,   -95,   -95,   -95,   -95,     0,   -95,    49,    -3,   -17,
     -95,   -95,   -94
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    68,    17,    60,    18,    19,    20,    51,    21,
      22,   186,    23,    24,   136,   171,   180,    25,    57,   165,
     192,   176,   197,    26,    36,    27,    28,    29,   172,    30,
     122,    31,    32,    33,    58,    52,   109,    61,    62,    55,
      56,    35,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    64,    69,   103,    54,    39,    37,    38,    76,   107,
     108,   110,   145,   144,     2,   114,   105,    41,    34,    65,
      75,   113,    66,     5,    77,   120,   114,   123,    42,   115,
      10,    40,   106,    59,   116,    78,    34,    14,   117,    65,
     115,   102,    82,   146,   147,   116,    85,    87,    63,   117,
     143,    67,   111,   153,   154,    81,    53,    34,   166,   158,
     154,    70,    71,    72,   150,    94,    95,    96,    34,    79,
      73,   169,   170,   178,    80,   104,    74,    43,    44,    45,
      46,    47,    97,   139,   140,   187,   112,    53,   119,   159,
     121,    48,   161,   141,   163,   137,   138,    84,    53,    86,
      83,   148,   201,   126,   149,   174,   152,   175,   155,   151,
      43,    44,    45,    46,    47,    92,    93,    94,    95,    96,
     156,   157,   185,   160,    48,   125,   162,   164,   190,   191,
      49,   168,   124,    50,   167,   179,    34,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   173,    53,    53,    53,
      53,    43,    44,    45,    46,    47,   182,    92,    93,    94,
      95,    96,   177,   181,   188,    48,    98,    99,   100,   101,
     193,   183,    34,   189,    50,   184,   198,   194,   195,   196,
      34,   202,     1,   199,   200,     2,    34,   203,   204,   205,
     142,     3,    34,     4,     5,     6,     7,    34,     8,   206,
       9,    10,   207,    11,    12,    13,     0,     0,    14,     0,
       0,     0,    15,    88,    89,    90,    91,    92,    93,    94,
      95,    96,     0,     0,     0,     0,     0,   125,   -93,   -93,
     -93,   -93,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    88,    89,    90,    91,    92,    93,    94,    95,    96
};

static const yytype_int16 yycheck[] =
{
       0,    42,    18,    58,     7,    11,    37,    34,    42,    64,
      65,    66,   106,     6,    10,     8,    42,    37,    18,    60,
      36,    76,    63,    19,    58,    80,     8,    82,    37,    22,
      26,    37,    58,    37,    27,    38,    36,    33,    31,    60,
      22,    57,    63,    61,    62,    27,    49,    50,    37,    31,
     105,     0,    68,    61,    62,    60,     7,    57,   152,    61,
      62,    20,    21,    22,   119,    53,    54,    55,    68,    37,
      29,    14,    15,   167,    58,    60,    35,    37,    38,    39,
      40,    41,    35,   100,   101,   179,    15,    38,    58,   144,
      37,    51,   147,    15,   149,    98,    99,    48,    49,    50,
      60,    64,   196,    61,    42,   160,    58,   162,    64,    59,
      37,    38,    39,    40,    41,    51,    52,    53,    54,    55,
     136,    23,   177,    42,    51,    61,    42,    59,   183,   184,
      57,    37,    83,    60,    58,    58,   136,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    59,    98,    99,   100,
     101,    37,    38,    39,    40,    41,   172,    51,    52,    53,
      54,    55,    59,    21,   180,    51,    43,    44,    45,    46,
     186,    59,   172,    15,    60,    59,   192,    15,    37,    24,
     180,   197,     7,    15,    21,    10,   186,    15,    37,    15,
     104,    16,   192,    18,    19,    20,    21,   197,    23,    18,
      25,    26,    18,    28,    29,    30,    -1,    -1,    33,    -1,
      -1,    -1,    37,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    61,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    47,    48,    49,    50,    51,    52,    53,    54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    10,    16,    18,    19,    20,    21,    23,    25,
      26,    28,    29,    30,    33,    37,    66,    68,    70,    71,
      72,    74,    75,    77,    78,    82,    88,    90,    91,    92,
      94,    96,    97,    98,   100,   106,    89,    37,    34,    11,
      37,    37,    37,    37,    38,    39,    40,    41,    51,    57,
      60,    73,   100,   102,   103,   104,   105,    83,    99,    37,
      69,   102,   103,    37,    42,    60,    63,     0,    67,    66,
      68,    68,    68,    68,    68,    66,    42,    58,   103,    37,
      58,    60,    63,    60,   102,   103,   102,   103,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    35,    43,    44,
      45,    46,    66,    69,    60,    42,    58,    69,    69,   101,
      69,    66,    15,    69,     8,    22,    27,    31,   107,    58,
      69,    37,    95,    69,   102,    61,    61,   102,   102,   102,
     102,   102,   102,   102,   102,   102,    79,   103,   103,   104,
     104,    15,    95,    69,     6,   107,    61,    62,    64,    42,
      69,    59,    58,    61,    62,    64,    66,    23,    61,    69,
      42,    69,    42,    69,    59,    84,   107,    58,    37,    14,
      15,    80,    93,    59,    69,    69,    86,    59,   107,    58,
      81,    21,    66,    59,    59,    69,    76,   107,    66,    15,
      69,    69,    85,    66,    15,    37,    24,    87,    66,    15,
      21,   107,    66,    15,    37,    15,    18,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    67,    66,    66,    66,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    73,    73,    73,    74,    76,    75,
      77,    79,    78,    80,    81,    80,    83,    82,    84,    85,
      82,    86,    87,    82,    89,    88,    90,    90,    91,    93,
      92,    94,    95,    95,    95,    96,    96,    97,    99,    98,
     100,   100,   101,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   104,   105,   105,   105,   105,   106,   106,
     106,   107,   107,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     0,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     4,     1,     1,     1,     1,     1,    10,     0,    11,
       2,     0,     6,     2,     0,     5,     0,     5,     0,     0,
      12,     0,     0,    13,     0,     4,     3,     1,     1,     0,
       9,     1,     0,     3,     5,     3,     6,     2,     0,     3,
       4,     4,     0,     3,     1,     3,     3,     3,     3,     3,
       2,     3,     1,     1,     0,     3,     3,     2,     3,     3,
       1,     3,     1,     1,     3,     3,     3,     3,     6,     4,
       4,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 71 "yacc.y"
{
  if((is_main==false)&&(number_function==0)&&(number_procedure==0))
  {
    printf("\tmethod public static void main(java.lang.String[])\n");
    printf("\tmax_stack 15\n");
    printf("\tmax_locals 15\n");
    printf("\t{\n");
    is_main=true;
    variables_count=0;
  }
}
#line 1600 "y.tab.c"
    break;

  case 29:
#line 117 "yacc.y"
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
#line 1615 "y.tab.c"
    break;

  case 30:
#line 129 "yacc.y"
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
#line 1652 "y.tab.c"
    break;

  case 31:
#line 161 "yacc.y"
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
#line 1682 "y.tab.c"
    break;

  case 32:
#line 188 "yacc.y"
                      { yyval.is_var=0;yyval.type="INT";yyval.v.int_number = yyvsp[0].v.int_number; }
#line 1688 "y.tab.c"
    break;

  case 33:
#line 189 "yacc.y"
           { yyval.is_var=0;yyval.type="REAL";yyval.v.real_number = yyvsp[0].v.real_number;}
#line 1694 "y.tab.c"
    break;

  case 34:
#line 190 "yacc.y"
           { yyval.is_var=0;yyval.type="BOOL";yyval.v.bool_value = yyvsp[0].v.bool_value;}
#line 1700 "y.tab.c"
    break;

  case 35:
#line 191 "yacc.y"
           { yyval.is_var=0;yyval.type="STRING";strcpy(yyval.v.Str,yyvsp[0].v.Str);}
#line 1706 "y.tab.c"
    break;

  case 36:
#line 192 "yacc.y"
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
      if(current_table->hashArray[temp_index]->c_v==0)
      {
        if (current_table->hashArray[temp_index]->type_name=="INT"){ yyval.type="INT";yyval.v.int_number = current_table->hashArray[temp_index]->value.i;}
        else if(current_table->hashArray[temp_index]->type_name=="REAL"){ yyval.type="REAL";yyval.v.real_number = current_table->hashArray[temp_index]->value.f;}
        else if(current_table->hashArray[temp_index]->type_name=="BOOL"){ yyval.type="BOOL";yyval.v.bool_value = current_table->hashArray[temp_index]->value.b;}
        else if(current_table->hashArray[temp_index]->type_name=="STRING"){ yyval.type="STRING";strcpy(yyval.v.Str,current_table->hashArray[temp_index]->value.s);}
        else {yyerror("ID expression get wrong(const)"); }
      }
      else if(current_table->hashArray[temp_index]->c_v==1)
      {
        yyval.G_L=current_table->hashArray[temp_index]->G_L;
        strcpy(yyval.name,temp_name);
        if (current_table->hashArray[temp_index]->type_name=="INT"){ yyval.type="INT";yyval.v.int_number = current_table->hashArray[temp_index]->value.i;}
        else if(current_table->hashArray[temp_index]->type_name=="REAL"){ yyval.type="REAL";yyval.v.int_number = current_table->hashArray[temp_index]->value.i;}
        else if(current_table->hashArray[temp_index]->type_name=="BOOL"){ yyval.type="BOOL";yyval.v.int_number = current_table->hashArray[temp_index]->value.i;}
        else if(current_table->hashArray[temp_index]->type_name=="STRING"){ yyval.type="STRING";yyval.v.int_number = current_table->hashArray[temp_index]->value.i;}
        else {yyerror("ID expression get wrong(const)"); }
      }
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
#line 1777 "y.tab.c"
    break;

  case 37:
#line 260 "yacc.y"
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
#line 1819 "y.tab.c"
    break;

  case 38:
#line 299 "yacc.y"
  {
    char* ID_name=(yyvsp[-5].v.Str);
    strcpy(function_return_type,yyvsp[0].type);
    if(current_table->lookup(ID_name)==-1)
    {
      int index=0;
      variables_count=0;
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
      printf("\tmethod public static int %s(",ID_name);
      for(i=0;i<current_Arguments.size(); i++)
      {
        para temp=current_Arguments[i];
        if(current_table->lookup(temp.p_name)==-1)
        {
           int temp_index=0;
           temp_index=current_table->insert(temp.p_name);
           current_table->hashArray[temp_index]->c_v=1;
           current_table->hashArray[temp_index]->G_L=true;
           current_table->hashArray[temp_index]->special=0;
           if(strcmp(temp.p_type_name,"INT")==0){current_table->hashArray[temp_index]->type_name="INT";printf("int");}
           else if(strcmp(temp.p_type_name,"REAL")==0){current_table->hashArray[temp_index]->type_name="REAL";}
           else if(strcmp(temp.p_type_name,"STRING")==0){current_table->hashArray[temp_index]->type_name="STRING";printf("string");}
           else if(strcmp(temp.p_type_name,"BOOL")==0){current_table->hashArray[temp_index]->type_name="BOOL";printf("int");}
           current_table->hashArray[temp_index]->value.i=variables_count;
           variables_count=variables_count+1;
           if(i<current_Arguments.size()-1){printf(", ");}
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
      printf(")\n");
      printf("\tmax_stack 15\n");
      printf("\tmax_locals 15\n");
      printf("\t{\n");
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
#line 1888 "y.tab.c"
    break;

  case 39:
#line 364 "yacc.y"
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
    printf("\treturn\n");
    printf("\t}\n");
  }
#line 1913 "y.tab.c"
    break;

  case 40:
#line 386 "yacc.y"
{
  if(number_function>0)
  {
    if(strcmp(function_return_type,yyvsp[0].type)!=0)
    {
      yyerror("The return type of the function is wrong.");
    }
    is_result=true;
    printf("\tireturn\n");
  }
  else
  {
    yyerror("The result is not in a function.");
  }
}
#line 1933 "y.tab.c"
    break;

  case 41:
#line 403 "yacc.y"
{
  printf("\tifeq L%d\n",L_index);
  L_index=L_index+1;
  if_stack.push(L_index);
  L_index=L_index+1;
  symbol_table* If_table=creat("If_table");
  current_table=STstack.top();
  if(strcmp(yyvsp[-1].type,"BOOL")!=0)
  {
    yyerror("the type of Bool_expressions in condiction is wrong.");
  }
  
}
#line 1951 "y.tab.c"
    break;

  case 43:
#line 420 "yacc.y"
{  
  printf("\tL%d:\n",if_stack.top()-1);
  if_stack.pop();
  dump(current_table);
}
#line 1961 "y.tab.c"
    break;

  case 44:
#line 426 "yacc.y"
{
  printf("\tgoto L%d\n",if_stack.top());
  printf("\tL%d:\n",if_stack.top()-1);
  dump(current_table);
  symbol_table* Else_table=creat("Else_table");
  current_table=STstack.top();
}
#line 1973 "y.tab.c"
    break;

  case 45:
#line 434 "yacc.y"
{
  printf("\tL%d:\n",if_stack.top());
  if_stack.pop();
  dump(current_table);
}
#line 1983 "y.tab.c"
    break;

  case 46:
#line 442 "yacc.y"
{
  printf("\tL%d:\n",L_index);
  symbol_table* Loop_table=creat("Loop_table");
  current_table=STstack.top();
  number_loop= number_loop+1;
  L_index=L_index+1;
  loop_stack.push(L_index);
  L_index=L_index+1;
}
#line 1997 "y.tab.c"
    break;

  case 47:
#line 452 "yacc.y"
{
  printf("\tgoto L%d\n",loop_stack.top()-1);
  number_loop= number_loop-1;
  dump(current_table);
  printf("\tL%d:\n",loop_stack.top());
  loop_stack.pop();
}
#line 2009 "y.tab.c"
    break;

  case 48:
#line 460 "yacc.y"
{
  int ID_index=0;
  bool ID_G_L=false;
  char* temp_name=(yyvsp[-3].v.Str);
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  //find the index of the counter
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
      ID_index=current_table->hashArray[temp_index]->value.i;
      ID_G_L=current_table->hashArray[temp_index]->G_L;
    }
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
    
 
  symbol_table* For_table=creat(temp_name);
  current_table=STstack.top();
  number_loop= number_loop+1;

  if(current_table->lookup(temp_name)==-1)
  {
    int index=0;
    index=current_table->insert(temp_name);
    current_table->hashArray[index]->special=0;
    current_table->hashArray[index]->c_v=1;
    current_table->hashArray[index]->type_name="INT";
    current_table->hashArray[index]->value.i=ID_index;
    current_table->hashArray[index]->G_L=ID_G_L;
    counter_stack.push(index);
  }
  else if(current_table->lookup(temp_name)==-2)
  {
    yyerror("simbol table full.(function)\n");
    exit(-1);
  }
  else
  {
     yyerror("The name already used.(for loop)");
  }
  if(ID_G_L==true)//local
  {
    printf("\tistore %d\n",ID_index);
    printf("\tL%d:\n",L_index);
    printf("\tiload %d\n",ID_index);
    L_index=L_index+1;
    loop_stack.push(L_index);
    L_index=L_index+1;
  }
  else if (ID_G_L==false)//global
  {
    printf("\tputstatic int %s.%s\n",class_name,temp_name);
    printf("\tL%d:\n",L_index);
    printf("\tgetstatic int %s.%s\n",class_name,temp_name);
    L_index=L_index+1;
    loop_stack.push(L_index);
    L_index=L_index+1;
  }
}
#line 2095 "y.tab.c"
    break;

  case 49:
#line 542 "yacc.y"
{
  
  //exit when (ID > maix)  
  printf("\tisub\n");
  printf("\tifgt L%d\n",L_index);
  L_index=L_index+1;
  printf("\ticonst_0\n");
  printf("\tgoto L%d\n",L_index);
  printf("\tL%d: iconst_1\n",L_index-1);
  printf("\tL%d:\n",L_index);
  L_index=L_index+1;
   
  printf("\tifne L%d\n",loop_stack.top());
  //pop the index of counter in hash table
  
}
#line 2116 "y.tab.c"
    break;

  case 50:
#line 559 "yacc.y"
{
  //counter++
  if(current_table->hashArray[counter_stack.top()]->G_L==true)//local
  {
    printf("\tiload %d\n",current_table->hashArray[counter_stack.top()]->value.i);
    printf("\tsipush 1\n");
    printf("\tiadd\n");
    printf("\tistore %d\n",current_table->hashArray[counter_stack.top()]->value.i);
    counter_stack.pop();
  }
  else if(current_table->hashArray[counter_stack.top()]->G_L==false)//global
  {
    printf("\tgetstatic int %s.%s\n",class_name,current_table->hashArray[counter_stack.top()]->name);
    printf("\tsipush 1\n");
    printf("\tiadd\n");
    printf("\tputstatic int %s.%s\n",class_name,current_table->hashArray[counter_stack.top()]->name);
    counter_stack.pop();
  }

  //
  printf("\tgoto L%d\n",loop_stack.top()-1);
  number_loop= number_loop-1;
  dump(current_table);
  printf("\tL%d:\n",loop_stack.top());
  loop_stack.pop();
}
#line 2147 "y.tab.c"
    break;

  case 51:
#line 586 "yacc.y"
{
  int ID_index=0;
  bool ID_G_L=false;
  char* temp_name=(yyvsp[-3].v.Str);
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  //find the index of the counter
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
      ID_index=current_table->hashArray[temp_index]->value.i;
      ID_G_L=current_table->hashArray[temp_index]->G_L;
    }
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
    
 
  symbol_table* For_table=creat(temp_name);
  current_table=STstack.top();
  number_loop= number_loop+1;

  if(current_table->lookup(temp_name)==-1)
  {
    int index=0;
    index=current_table->insert(temp_name);
    current_table->hashArray[index]->special=0;
    current_table->hashArray[index]->c_v=1;
    current_table->hashArray[index]->type_name="INT";
    current_table->hashArray[index]->value.i=ID_index;
    current_table->hashArray[index]->G_L=ID_G_L;
    counter_stack.push(index);
  }
  else if(current_table->lookup(temp_name)==-2)
  {
    yyerror("simbol table full.(function)\n");
    exit(-1);
  }
  else
  {
     yyerror("The name already used.(for loop)");
  }
  if(ID_G_L==true)//local
  {
    printf("\tistore %d\n",ID_index);
    printf("\tL%d:\n",L_index);
    printf("\tiload %d\n",ID_index);
    L_index=L_index+1;
    loop_stack.push(L_index);
    L_index=L_index+1;
  }
  else if (ID_G_L==false)//global
  {
    printf("\tputstatic int %s.%s\n",class_name,temp_name);
    printf("\tL%d:\n",L_index);
    printf("\tgetstatic int %s.%s\n",class_name,temp_name);
    L_index=L_index+1;
    loop_stack.push(L_index);
    L_index=L_index+1;
  }
}
#line 2233 "y.tab.c"
    break;

  case 52:
#line 668 "yacc.y"
{
    
  //exit when (ID < maix)  
  printf("\tisub\n");
  printf("\tiflt L%d\n",L_index);
  L_index=L_index+1;
  printf("\ticonst_0\n");
  printf("\tgoto L%d\n",L_index);
  printf("\tL%d: iconst_1\n",L_index-1);
  printf("\tL%d:\n",L_index);
  L_index=L_index+1;
   
  printf("\tifne L%d\n",loop_stack.top());
  //pop the index of counter in hash table
}
#line 2253 "y.tab.c"
    break;

  case 53:
#line 684 "yacc.y"
{
  if(current_table->hashArray[counter_stack.top()]->G_L==true)//local
  {
    printf("\tiload %d\n",current_table->hashArray[counter_stack.top()]->value.i);
    printf("\tsipush 1\n");
    printf("\tisub\n");
    printf("\tistore %d\n",current_table->hashArray[counter_stack.top()]->value.i);
    counter_stack.pop();
  }
  else if(current_table->hashArray[counter_stack.top()]->G_L==false)//global
  {
    printf("\tgetstatic int %s.%s\n",class_name,current_table->hashArray[counter_stack.top()]->name);
    printf("\tsipush 1\n");
     printf("\tisub\n");
    printf("\tputstatic int %s.%s\n",class_name,current_table->hashArray[counter_stack.top()]->name);
    counter_stack.pop();
  }
  
  //
  printf("\tgoto L%d\n",loop_stack.top()-1);
  number_loop= number_loop-1;
  dump(current_table);
  printf("\tL%d:\n",loop_stack.top());
  loop_stack.pop();
}
#line 2283 "y.tab.c"
    break;

  case 54:
#line 712 "yacc.y"
{
  char* temp_name="block";
  symbol_table* block=creat(temp_name);
  current_table=STstack.top();
}
#line 2293 "y.tab.c"
    break;

  case 55:
#line 718 "yacc.y"
{
  dump(current_table);
}
#line 2301 "y.tab.c"
    break;

  case 56:
#line 723 "yacc.y"
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
    printf("\tifne L%d\n",loop_stack.top());
  }
}
#line 2320 "y.tab.c"
    break;

  case 57:
#line 737 "yacc.y"
      {
  if (number_loop<=0) {yyerror("exit not in the loop");}
  printf("\tifne L%d\n",loop_stack.top());
}
#line 2329 "y.tab.c"
    break;

  case 58:
#line 742 "yacc.y"
          { 
  if((is_main==false)&&(number_function==0)&&(number_procedure==0))
  {
    printf("\tmethod public static void main(java.lang.String[])\n");
    printf("\tmax_stack 15\n");
    printf("\tmax_locals 15\n");
    printf("\t{\n");
    is_main=true;
    variables_count=0;
  } 
printf("\tgetstatic java.io.PrintStream java.lang.System.out\n");
printf("\tinvokevirtual void java.io.PrintStream.println()\n");
}
#line 2347 "y.tab.c"
    break;

  case 59:
#line 757 "yacc.y"
  {
    char* ID_name=(yyvsp[-3].v.Str);
    variables_count=0;
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
      printf("\tmethod public static void %s(",ID_name);
      for(i=0;i<current_Arguments.size(); i++)
      {
        para temp=current_Arguments[i];
        if(current_table->lookup(temp.p_name)==-1)
        {
           int temp_index=0;
           temp_index=current_table->insert(temp.p_name);
           current_table->hashArray[temp_index]->c_v=1;
           current_table->hashArray[temp_index]->G_L=true;
           current_table->hashArray[temp_index]->special=0;
           if(strcmp(temp.p_type_name,"INT")==0){current_table->hashArray[temp_index]->type_name="INT";printf("int");}
           else if(strcmp(temp.p_type_name,"REAL")==0){current_table->hashArray[temp_index]->type_name="REAL";}
           else if(strcmp(temp.p_type_name,"STRING")==0){current_table->hashArray[temp_index]->type_name="STRING";printf("string");}
           else if(strcmp(temp.p_type_name,"BOOL")==0){current_table->hashArray[temp_index]->type_name="BOOL";printf("int");}
           current_table->hashArray[temp_index]->value.i=variables_count;
           variables_count=variables_count+1;
           if(i<current_Arguments.size()-1){printf(", ");}
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
      printf(")\n");
      printf("\tmax_stack 15\n");
      printf("\tmax_locals 15\n");
      printf("\t{\n");
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
#line 2415 "y.tab.c"
    break;

  case 60:
#line 821 "yacc.y"
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
    printf("\treturn\n");
    printf("\t}\n");
  }
#line 2440 "y.tab.c"
    break;

  case 61:
#line 842 "yacc.y"
                 {
  if (number_procedure>0) {is_return=true;}
  else {yyerror("RETURN not in the procedure");}
  printf("\treturn\n");
}
#line 2450 "y.tab.c"
    break;

  case 63:
#line 850 "yacc.y"
{
  para temp_Argument;
  char* temp_name=(yyvsp[-2].v.Str);
  char* temp_type_name=yyvsp[0].type;
  strcpy(temp_Argument.p_name,temp_name);
  strcpy(temp_Argument.p_type_name,temp_type_name);
  current_Arguments.push_back(temp_Argument);
}
#line 2463 "y.tab.c"
    break;

  case 64:
#line 859 "yacc.y"
{
  para temp_Argument;
  char* temp_name=(yyvsp[-2].v.Str);
  char* temp_type_name=yyvsp[0].type;
  strcpy(temp_Argument.p_name,temp_name);
  strcpy(temp_Argument.p_type_name,temp_type_name);
  current_Arguments.push_back(temp_Argument);
}
#line 2476 "y.tab.c"
    break;

  case 65:
#line 869 "yacc.y"
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
        else
        {
          if(current_table->hashArray[temp_index]->G_L==false)//global
          {
            printf("\tputstatic int %s.%s\n", class_name,temp_name);
          }
          else if(current_table->hashArray[temp_index]->G_L==true)//local
          {
            printf("\tistore %d\n",current_table->hashArray[temp_index]->value.i);
          }
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
#line 2546 "y.tab.c"
    break;

  case 66:
#line 935 "yacc.y"
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
#line 2606 "y.tab.c"
    break;

  case 67:
#line 991 "yacc.y"
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
#line 2686 "y.tab.c"
    break;

  case 68:
#line 1068 "yacc.y"
{
  if((is_main==false)&&(number_function==0)&&(number_procedure==0))
  {
    printf("\tmethod public static void main(java.lang.String[])\n");
    printf("\tmax_stack 15\n");
    printf("\tmax_locals 15\n");
    printf("\t{\n");
    is_main=true;
    variables_count=0;
  }
  printf("\tgetstatic java.io.PrintStream java.lang.System.out\n");
}
#line 2703 "y.tab.c"
    break;

  case 69:
#line 1080 "yacc.y"
           {
  if(strcmp(yyvsp[0].type,"STRING")==0)
  {
      printf("\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n");
  }
  else if((strcmp(yyvsp[0].type,"INT")==0)||(strcmp(yyvsp[0].type,"BOOL")==0))
  {
     printf("\tinvokevirtual void java.io.PrintStream.print(int)\n");
  }
}
#line 2718 "y.tab.c"
    break;

  case 70:
#line 1092 "yacc.y"
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
#line 2799 "y.tab.c"
    break;

  case 71:
#line 1169 "yacc.y"
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
          printf("\tinvokestatic int %s.%s(",class_name,temp_name);
        }
        else if(current_table->hashArray[temp_index]->special==3)
        {
          yyval.special=3;
          printf("\tinvokestatic void %s.%s(",class_name,temp_name);
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
            if((strcmp(current_table->hashArray[temp_index]->para_array[j].p_type_name,"INT")==0)||(strcmp(current_table->hashArray[temp_index]->para_array[j].p_type_name,"BOOL")==0))
            {
              printf("int");
            }    
            if(j<current_table->hashArray[temp_index]->para_array.size()-1){printf(", ");}
          }
          printf(")\n");

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
#line 2882 "y.tab.c"
    break;

  case 73:
#line 1251 "yacc.y"
{
  para temp_Argument;
  char* temp_type_name=yyvsp[0].type;
  strcpy(temp_Argument.p_type_name,temp_type_name);
  input_Arguments.push_back(temp_Argument);
 
}
#line 2894 "y.tab.c"
    break;

  case 74:
#line 1259 "yacc.y"
{
  para temp_Argument;
  char* temp_type_name=yyvsp[0].type;
  strcpy(temp_Argument.p_type_name,temp_type_name);
   yyval.is_var=yyvsp[0].is_var;
  input_Arguments.push_back(temp_Argument);
}
#line 2906 "y.tab.c"
    break;

  case 75:
#line 1270 "yacc.y"
{
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    yyval.G_L=(yyvsp[0].G_L || yyvsp[-2].G_L);
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
      //check const/var
      if(yyvsp[0].is_var==false && yyvsp[-2].is_var==false)//both const
      {
        yyval.is_var=false;
        yyval.v.int_number = yyvsp[0].v.int_number+yyvsp[-2].v.int_number;
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\tiadd\n");}
    }
    else {yyerror("addtion something wrong.");} 
}
#line 2960 "y.tab.c"
    break;

  case 76:
#line 1319 "yacc.y"
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
      //check const/var
      if(yyvsp[0].is_var==false && yyvsp[-2].is_var==false)//both const
      {
        yyval.is_var=false;
        yyval.v.int_number = yyvsp[-2].v.int_number-yyvsp[0].v.int_number;  
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\tisub\n");}
    }
    else {yyerror("subtraction something wrong.");}
}
#line 3017 "y.tab.c"
    break;

  case 77:
#line 1371 "yacc.y"
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
      if(yyvsp[0].is_var==false && yyvsp[-2].is_var==false)//both const
      {
        yyval.is_var=false;
        yyval.v.int_number = yyvsp[0].v.int_number*yyvsp[-2].v.int_number;  
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\timul\n");}
    }
    else {yyerror("multiplication something wrong.");}
}
#line 3069 "y.tab.c"
    break;

  case 78:
#line 1418 "yacc.y"
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
        else{
          if(yyvsp[0].is_var==false && yyvsp[-2].is_var==false)//both const
          {
            yyval.is_var=false;
            yyval.v.int_number = yyvsp[-2].v.int_number/yyvsp[0].v.int_number; 
          }
          else
          {
            yyval.is_var=true;
          }
          if(is_main||number_function||number_procedure){printf("\tidiv\n");}
        }      
    }
    else {yyerror("division something wrong.");}
}
#line 3143 "y.tab.c"
    break;

  case 79:
#line 1487 "yacc.y"
                                         {  
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
    {
      yyval.type="INT";
      if(yyvsp[0].is_var==false && yyvsp[-2].is_var==false)//both const
      {
        yyval.is_var=false;
        yyval.v.int_number=yyvsp[-2].v.int_number % yyvsp[0].v.int_number; 
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\tirem\n");}
    }
    else
    {
      yyerror("type != int, can not mod.");
    }
}
#line 3169 "y.tab.c"
    break;

  case 80:
#line 1508 "yacc.y"
                                     {
    yyval.is_var=yyvsp[0].is_var; 
    if(yyvsp[0].is_var==false)
    {
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
        if(is_main||number_function||number_procedure){printf("\tineg\n");}   
      }
    }
    else if(yyvsp[0].is_var==true)
    {
      yyval.is_var=true;
      if(is_main||number_function||number_procedure){printf("\tineg\n");}
    }
}
#line 3210 "y.tab.c"
    break;

  case 81:
#line 1544 "yacc.y"
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
#line 3240 "y.tab.c"
    break;

  case 82:
#line 1570 "yacc.y"
{
  yyval.is_var=yyvsp[0].is_var;
  if(yyvsp[0].is_var==false)
  {
   if(strcmp(yyvsp[0].type,"REAL")==0)
      {
        yyval.type="REAL";
        yyval.v.real_number=yyvsp[0].v.real_number;
      }
    else if(strcmp(yyvsp[0].type,"INT")==0)
      {
        yyval.type="INT";
        yyval.v.int_number=yyvsp[0].v.int_number;
        //const int
        if(is_main||number_function||number_procedure){printf("\tsipush %d\n",yyvsp[0].v.int_number);}
      }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
      {
        yyval.type="BOOL";
        yyval.v.bool_value=yyvsp[0].v.bool_value;
        //const bool
        if(is_main||number_function||number_procedure){printf("\t%s\n",yyvsp[0].v.bool_value? "iconst_1" : "iconst_0");}
      } 
    else if(strcmp(yyvsp[0].type,"STRING")==0)
      {
        yyval.type="STRING";
        strcpy(yyval.v.Str,yyvsp[0].v.Str);
        //const string
        if(is_main||number_function||number_procedure){printf("\tldc \"%s\"\n",yyval.v.Str);}
      }
    else {yyerror("Const_values something wrong.(const)");}
  }
  else
  {
    if(strcmp(yyvsp[0].type,"REAL")==0){yyval.type="REAL";}
    else if(strcmp(yyvsp[0].type,"INT")==0){yyval.type="INT";}
    else if(strcmp(yyvsp[0].type,"BOOL")==0){yyval.type="BOOL";} 
    else if(strcmp(yyvsp[0].type,"STRING")==0){yyval.type="STRING";}
    else {yyerror("Const_values something wrong.(var)");}
    yyval.v.int_number=yyvsp[0].v.int_number;
    strcpy(yyval.name,yyvsp[0].name);
    yyval.G_L=yyvsp[0].G_L;
    yyval.is_var=true;
    if((strcmp(yyvsp[0].type,"INT")==0)||(strcmp(yyvsp[0].type,"BOOL")==0))
    {
      if(yyvsp[0].G_L==false)//global
      {
        if(is_main||number_function||number_procedure){printf("\tgetstatic int %s.%s\n",class_name,yyvsp[0].name);}
      }
      else if(yyvsp[0].G_L==true)//local
      {
        if(is_main||number_function||number_procedure){printf("\tiload %d\n",yyvsp[0].v.int_number);}
      }
    }
  }
}
#line 3301 "y.tab.c"
    break;

  case 83:
#line 1627 "yacc.y"
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
#line 3339 "y.tab.c"
    break;

  case 85:
#line 1663 "yacc.y"
                                        {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if((strcmp(yyvsp[0].type,"BOOL")!=0)||(strcmp(yyvsp[-2].type,"BOOL")!=0)){
    yyerror("type wrong, can not AND, use false instead");
    yyval.v.bool_value=false;
  }
  else
  {
      if(yyval.is_var==false)
      {
        yyval.v.bool_value=(yyvsp[0].v.bool_value)&&(yyvsp[-2].v.bool_value);
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\tiand\n");}
  }
}
#line 3364 "y.tab.c"
    break;

  case 86:
#line 1683 "yacc.y"
                                       {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if((strcmp(yyvsp[0].type,"BOOL")!=0)||(strcmp(yyvsp[-2].type,"BOOL")!=0)){
    yyerror("type wrong, can not OR, use false instead");
    yyval.v.bool_value=false;
  }
  else
  {
      if(yyval.is_var==false)
      {
        yyval.v.bool_value=(yyvsp[0].v.bool_value)||(yyvsp[-2].v.bool_value);
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\tior\n");}
  }
}
#line 3389 "y.tab.c"
    break;

  case 87:
#line 1703 "yacc.y"
                       {
   yyval.type="BOOL";
   yyval.is_var=yyvsp[0].is_var;
  if(strcmp(yyvsp[0].type,"BOOL")!=0){
    yyerror("type wrong, can not NOT, use false instead");
    yyval.v.bool_value=false;
  }
  else
  {
      if(yyval.is_var==false)
      {
        yyval.v.bool_value=!(yyvsp[0].v.bool_value);
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure)
      {
        printf("\tsipush 1\n");
        printf("\tixor\n");
      }
  }
}
#line 3418 "y.tab.c"
    break;

  case 88:
#line 1727 "yacc.y"
                                      {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if(strcmp(yyvsp[0].type,yyvsp[-2].type)==0)
  {
    if(strcmp(yyvsp[0].type,"INT")==0)
    {
      if((yyvsp[0].v.int_number)==(yyvsp[-2].v.int_number)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}
      
      printf("\tisub\n");
      printf("\tifeq L%d\n",L_index);
      L_index=L_index+1;
      printf("\ticonst_0\n");
      printf("\tgoto L%d\n",L_index);
      printf("\tL%d: iconst_1\n",L_index-1);
      printf("\tL%d:\n",L_index);
      L_index=L_index+1;
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
#line 3465 "y.tab.c"
    break;

  case 89:
#line 1769 "yacc.y"
                                     {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if(strcmp(yyvsp[0].type,yyvsp[-2].type)==0)
  {
    if(strcmp(yyvsp[0].type,"INT")==0)
    {
      if((yyvsp[0].v.int_number)!=(yyvsp[-2].v.int_number)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}
      
      printf("\tisub\n");
      printf("\tifne L%d\n",L_index);
      L_index=L_index+1;
      printf("\ticonst_0\n");
      printf("\tgoto L%d\n",L_index);
      printf("\tL%d: iconst_1\n",L_index-1);
      printf("\tL%d:\n",L_index);
      L_index=L_index+1;
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
#line 3512 "y.tab.c"
    break;

  case 90:
#line 1811 "yacc.y"
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
#line 3541 "y.tab.c"
    break;

  case 91:
#line 1836 "yacc.y"
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
#line 3570 "y.tab.c"
    break;

  case 92:
#line 1860 "yacc.y"
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
#line 3588 "y.tab.c"
    break;

  case 93:
#line 1873 "yacc.y"
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
#line 3617 "y.tab.c"
    break;

  case 94:
#line 1900 "yacc.y"
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
        printf("\tisub\n");
        printf("\tifgt L%d\n",L_index);
        L_index=L_index+1;
        printf("\ticonst_0\n");
        printf("\tgoto L%d\n",L_index);
        printf("\tL%d: iconst_1\n",L_index-1);
        printf("\tL%d:\n",L_index);
        L_index=L_index+1;
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
#line 3672 "y.tab.c"
    break;

  case 95:
#line 1950 "yacc.y"
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
        
        printf("\tisub\n");
        printf("\tifge L%d\n",L_index);
        L_index=L_index+1;
        printf("\ticonst_0\n");
        printf("\tgoto L%d\n",L_index);
        printf("\tL%d: iconst_1\n",L_index-1);
        printf("\tL%d:\n",L_index);
        L_index=L_index+1;
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
#line 3728 "y.tab.c"
    break;

  case 96:
#line 2001 "yacc.y"
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
        
        printf("\tisub\n");
        printf("\tifle L%d\n",L_index);
        L_index=L_index+1;
        printf("\ticonst_0\n");
        printf("\tgoto L%d\n",L_index);
        printf("\tL%d: iconst_1\n",L_index-1);
        printf("\tL%d:\n",L_index);
        L_index=L_index+1;
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
#line 3784 "y.tab.c"
    break;

  case 97:
#line 2052 "yacc.y"
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
        
        printf("\tisub\n");
        printf("\tiflt L%d\n",L_index);
        L_index=L_index+1;
        printf("\ticonst_0\n");
        printf("\tgoto L%d\n",L_index);
        printf("\tL%d: iconst_1\n",L_index-1);
        printf("\tL%d:\n",L_index);
        L_index=L_index+1;
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
#line 3840 "y.tab.c"
    break;

  case 98:
#line 2105 "yacc.y"
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
      if((is_main==false)&&(STstack.size()==1))//Global Variables
      {
        if(strcmp(yyvsp[-2].type,"INT")==0)
        {
          printf("\tfield static int %s = %d\n",ID_name,yyvsp[0].v.int_number);
          current_table->hashArray[index]->G_L=false;
        }
        else if(strcmp(yyvsp[-2].type,"BOOL")==0)
        {
          printf("\tfield static int %s = %d\n",ID_name,yyvsp[0].v.bool_value? 1 : 0);
          current_table->hashArray[index]->G_L=false;
        }
      }
      else//local Variables
      {
        if((strcmp(yyvsp[0].type,"INT")==0))
        {
          current_table->hashArray[index]->value.i=variables_count;
          current_table->hashArray[index]->G_L=true;

          printf("\tistore %d\n",variables_count);
          variables_count=variables_count+1;
        }
        else if (strcmp(yyvsp[0].type,"BOOL")==0)
        {
          current_table->hashArray[index]->value.i=variables_count;
          current_table->hashArray[index]->G_L=true;

          printf("\tistore %d\n",variables_count);
          variables_count=variables_count+1;
        }
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
#line 3902 "y.tab.c"
    break;

  case 99:
#line 2162 "yacc.y"
                            {
    char* ID_name=(yyvsp[-2].v.Str);
    int index=0;

    if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[0].type;
      current_table->hashArray[index]->c_v=1;
      current_table->hashArray[index]->special=0;
      if((is_main==false)&&(STstack.size()==1))//Global Variables
      {
        if((strcmp(yyvsp[0].type,"INT")==0))
        {
          printf("\tfield static int %s = %d\n",ID_name,yyvsp[0].v.int_number);
          current_table->hashArray[index]->G_L=false;
        }
        else if(strcmp(yyvsp[-2].type,"BOOL")==0)
        {
          printf("\tfield static int %s = %d\n",ID_name,yyvsp[0].v.bool_value? 1 : 0);
          current_table->hashArray[index]->G_L=false;
        }
      }
      else//local Variables
      {
        if((strcmp(yyvsp[0].type,"INT")==0))
        {
          current_table->hashArray[index]->value.i=variables_count;
          current_table->hashArray[index]->G_L=true;
          printf("\tistore %d\n",variables_count);
          variables_count=variables_count+1;
        }
        else if (strcmp(yyvsp[0].type,"BOOL")==0)
        {
          current_table->hashArray[index]->value.i=variables_count;
          current_table->hashArray[index]->G_L=true;
          printf("\tistore %d\n",variables_count);
          variables_count=variables_count+1;
        }
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
#line 3958 "y.tab.c"
    break;

  case 100:
#line 2213 "yacc.y"
                  {
  char* ID_name=(yyvsp[-2].v.Str);
  int index=0;
  if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[0].type;
      current_table->hashArray[index]->c_v=1;
      current_table->hashArray[index]->special=0;
      if((is_main==false)&&(STstack.size()==1))//Global Variables
      {
        if((strcmp(yyvsp[0].type,"INT")==0)||(strcmp(yyvsp[0].type,"BOOL")==0))
        {
          printf("\tfield static int %s\n",ID_name);
          current_table->hashArray[index]->G_L=false;
        }
      }
      else//local Variables
      {
        if((strcmp(yyvsp[0].type,"INT")==0)||(strcmp(yyvsp[0].type,"BOOL")==0))
        {
          current_table->hashArray[index]->value.i=variables_count;
          current_table->hashArray[index]->G_L=true;
          variables_count=variables_count+1;
        }
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
#line 4000 "y.tab.c"
    break;

  case 101:
#line 2252 "yacc.y"
         {yyval.type="INT";}
#line 4006 "y.tab.c"
    break;

  case 102:
#line 2253 "yacc.y"
       {yyval.type="REAL";}
#line 4012 "y.tab.c"
    break;

  case 103:
#line 2254 "yacc.y"
         {yyval.type="STRING";}
#line 4018 "y.tab.c"
    break;

  case 104:
#line 2255 "yacc.y"
       {yyval.type="BOOL";}
#line 4024 "y.tab.c"
    break;


#line 4028 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 2258 "yacc.y"


int yyerror(char *s)//output warning message
{
fprintf(stderr, "%s\n", s);
return 0;
}

int main(int argc, char *argv[])
{
  FILE *yyin;
  
  int input_type=0;
  char* buffer=new char[MAX_LINE_LENG];
	if ( argc > 1 )
  {
    yyin = fopen( argv[1], "r" );
    if(yyin==NULL)
    {
      printf("input file is null.\n");
    }
    memcpy(class_name,argv[1],strlen(argv[1])-3);
    printf("class %s\n",class_name);
    printf("{\n",class_name);
    input_type=1;    
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
  yyrestart(yyin);
  if (yyparse() == 1) /* parsing */
    {yyerror("Parsing error !"); }/* syntax error */
  if(is_main==false)
  {
    printf("\tmethod public static void main(java.lang.String[])\n");
    printf("\tmax_stack 15\n");
    printf("\tmax_locals 15\n");
    printf("\t{\n");
    is_main=true;
    variables_count=0;
  }
  printf("\treturn\n");
  printf("\t}\n");
  printf("}\n");
  main=dump(main);
  if(input_type==1){fclose(yyin);}
  return 0;
}
