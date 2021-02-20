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
#line 1 "micko.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int var_type = NO_TYPE; // cuva tip kod vise istih varijabli
  int ret_val = 0; // da li postoji return u funkciji
  int pars = 0; // broj parametara u funkciji
  int args = 0; // broj argumenata u pozivu
  unsigned lvl = 1;
  int last_idx;
  int lab_num = -1;
  FILE *output;
  int reg;

#line 97 "micko.tab.c" /* yacc.c:339  */

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
   by #include "micko.tab.h".  */
#ifndef YY_YY_MICKO_TAB_H_INCLUDED
# define YY_YY_MICKO_TAB_H_INCLUDED
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
    _TYPE = 258,
    _IF = 259,
    _ELSE = 260,
    _RETURN = 261,
    _ID = 262,
    _INT_NUMBER = 263,
    _UINT_NUMBER = 264,
    _LPAREN = 265,
    _RPAREN = 266,
    _LBRACKET = 267,
    _RBRACKET = 268,
    _ASSIGN = 269,
    _SEMICOLON = 270,
    _AROP = 271,
    _RELOP = 272,
    _COMMA = 273,
    _INCR = 274,
    _DECR = 275,
    _BRANCH = 276,
    _FIRST = 277,
    _SECOND = 278,
    _THIRD = 279,
    _OTHERW = 280,
    _ARROW = 281,
    _FOR = 282,
    _COLON = 283,
    _QMARK = 284,
    ONLY_IF = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "micko.y" /* yacc.c:355  */

  int i;
  char *s;

#line 173 "micko.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MICKO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "micko.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    79,    81,    85,    97,    98,   103,   102,
     129,   130,   135,   145,   160,   159,   172,   174,   178,   178,
     182,   190,   198,   211,   213,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   231,   244,   252,   230,   289,   302,
     311,   320,   330,   334,   336,   340,   342,   346,   348,   288,
     358,   382,   408,   407,   414,   427,   428,   449,   450,   456,
     461,   463,   482,   501,   522,   525,   531,   530,   552,   561,
     562,   567,   577,   590,   592,   598,   603,   597,   616,   626,
     639
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_IF", "_ELSE", "_RETURN",
  "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_LPAREN", "_RPAREN", "_LBRACKET",
  "_RBRACKET", "_ASSIGN", "_SEMICOLON", "_AROP", "_RELOP", "_COMMA",
  "_INCR", "_DECR", "_BRANCH", "_FIRST", "_SECOND", "_THIRD", "_OTHERW",
  "_ARROW", "_FOR", "_COLON", "_QMARK", "ONLY_IF", "$accept", "program",
  "global_list", "global_var", "function_list", "function", "$@1",
  "parameters", "parameter", "body", "$@2", "variable_list", "variable",
  "$@3", "vars", "statement_list", "statement", "for_statement", "@4",
  "$@5", "$@6", "branch_statement", "@7", "$@8", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "incr_statement",
  "decr_statement", "compound_statement", "@18", "assignment_statement",
  "num_exp", "exp", "literal", "function_call", "$@19", "voidf_call",
  "arguments", "argument", "if_statement", "if_part", "@20", "$@21",
  "rel_exp", "return_statement", YY_NULLPTR
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
     285
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -80,     4,    18,   -80,    44,   -80,    22,   -80,    45,    49,
     -80,   -80,    51,   -80,    56,    58,    52,    55,   -80,    69,
      67,   -80,   -80,    73,    85,   -80,   -80,   -80,   -80,    82,
       1,    76,    15,    81,    68,    -8,   -80,   -80,    83,    84,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,    80,   -80,   -80,
      87,   -80,    77,   -80,    89,   -80,     0,   -80,   -80,    77,
     -80,    19,   -80,   -80,   -80,    77,    86,    88,    90,   -80,
      91,    95,   -80,    41,    92,   -80,    77,   -80,   -80,     7,
      93,   -80,    77,    26,   -80,   -80,    77,    85,   -80,   -80,
     -80,    33,   -80,   -80,    77,    78,   -80,   -80,    92,    94,
      79,    25,    97,    96,    98,    92,    77,   -80,    77,   -80,
       8,     8,    41,    99,    92,   -80,   -80,   -80,    77,   100,
     101,   -80,     8,     8,   -80,   -80,   102,   103,     8,    41,
     -80,   -80,   104,   106,   105,   -80,    41,   -80,   107,   108,
     -80,    41,   -80,   109,   110,   -80,    41,   -80,   112,   113,
     -80,    41,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     4,     2,     6,     8,     0,
       7,     5,     0,     8,    10,     0,     0,    11,    12,     0,
       0,    16,     9,     0,    14,    13,    18,    23,    17,     0,
       0,    20,     0,     0,     0,    66,    52,    15,     0,     0,
      24,    32,    31,    29,    30,    25,    26,     0,    33,    27,
      73,    28,     0,    19,     0,    75,    58,    64,    65,     0,
      80,     0,    55,    57,    59,     0,     0,     0,     0,    16,
       0,     0,    68,     0,    22,    21,     0,    61,    62,     0,
       0,    79,     0,     0,    50,    51,    69,    23,    38,    34,
      74,     0,    76,    60,     0,     0,    56,    54,    71,     0,
      70,     0,     0,     0,     0,    78,     0,    67,     0,    53,
       0,     0,     0,     0,    72,    39,    35,    77,     0,     0,
       0,    63,     0,     0,    40,    36,     0,     0,     0,     0,
      41,    37,     0,     0,     0,    42,     0,    43,     0,     0,
      44,     0,    45,     0,     0,    46,     0,    47,     0,     0,
      48,     0,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -80,   111,   -80,   -80,   -80,   -80,
     -80,    50,   -80,   -80,   -80,    35,   -72,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -50,   -79,
     -56,   -30,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
      37,   -80
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    12,    16,    17,    22,
      27,    24,    28,    29,    32,    30,    40,    41,   103,   120,
     127,    42,   102,   119,   126,   132,   136,   138,   141,   143,
     146,   148,   151,    43,    44,    45,    69,    46,    61,    62,
      63,    64,    68,    48,    99,   100,    49,    50,    76,   104,
      80,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    90,    74,    96,     3,    33,    65,    34,    35,    79,
     -66,    66,    67,    36,    37,    83,    57,    58,    93,    77,
      78,     4,    38,    82,    94,     9,    91,   113,    39,    33,
      53,    34,    35,    54,    81,    82,    98,    36,   109,   121,
     117,    97,    82,    47,   105,    33,    38,    34,    35,    82,
      94,     8,    39,    36,   115,   116,    13,   131,   114,    15,
      11,    14,    38,    19,   137,    18,   124,   125,    39,   142,
      23,    47,   130,    20,   147,    56,    57,    58,    59,   152,
      25,    21,    47,    60,    56,    57,    58,    59,    26,    31,
      52,    55,    73,    70,    71,    72,    75,   108,    88,    47,
      86,    84,    89,    85,    95,   107,    47,   106,    82,   112,
     111,    47,   110,    92,   129,   133,    47,    10,   122,    87,
     128,    47,   101,     0,     0,     0,     0,   118,   134,   123,
     139,   135,     0,   144,   140,     0,   145,   149,     0,   150
};

static const yytype_int16 yycheck[] =
{
      30,    73,    52,    82,     0,     4,    14,     6,     7,    59,
      10,    19,    20,    12,    13,    65,     8,     9,    11,    19,
      20,     3,    21,    16,    17,     3,    76,   106,    27,     4,
      15,     6,     7,    18,    15,    16,    86,    12,    13,   118,
     112,    15,    16,    73,    94,     4,    21,     6,     7,    16,
      17,     7,    27,    12,   110,   111,     7,   129,   108,     3,
      15,    10,    21,    11,   136,     7,   122,   123,    27,   141,
       3,   101,   128,    18,   146,     7,     8,     9,    10,   151,
       7,    12,   112,    15,     7,     8,     9,    10,     3,     7,
      14,    10,     5,    10,    10,    15,     7,    18,     7,   129,
      10,    15,     7,    15,    11,    11,   136,    29,    16,    11,
      14,   141,    15,    76,    11,    11,   146,     6,    18,    69,
      18,   151,    87,    -1,    -1,    -1,    -1,    28,    22,    28,
      23,    26,    -1,    24,    26,    -1,    26,    25,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,     0,     3,    34,    35,    36,     7,     3,
      36,    15,    37,     7,    10,     3,    38,    39,     7,    11,
      18,    12,    40,     3,    42,     7,     3,    41,    43,    44,
      46,     7,    45,     4,     6,     7,    12,    13,    21,    27,
      47,    48,    52,    64,    65,    66,    68,    72,    74,    77,
      78,    82,    14,    15,    18,    10,     7,     8,     9,    10,
      15,    69,    70,    71,    72,    14,    19,    20,    73,    67,
      10,    10,    15,     5,    69,     7,    79,    19,    20,    69,
      81,    15,    16,    69,    15,    15,    10,    42,     7,     7,
      47,    69,    81,    11,    17,    11,    70,    15,    69,    75,
      76,    46,    53,    49,    80,    69,    29,    11,    18,    13,
      15,    14,    11,    70,    69,    71,    71,    47,    28,    54,
      50,    70,    18,    28,    71,    71,    55,    51,    18,    11,
      71,    47,    56,    11,    22,    26,    57,    47,    58,    23,
      26,    59,    47,    60,    24,    26,    61,    47,    62,    25,
      26,    63,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    35,    35,    37,    36,
      38,    38,    39,    39,    41,    40,    42,    42,    44,    43,
      45,    45,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    49,    50,    51,    48,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    52,
      64,    65,    67,    66,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    71,    71,    73,    72,    74,    75,
      75,    76,    76,    77,    77,    79,    80,    78,    81,    82,
      82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     1,     2,     0,     7,
       0,     1,     2,     4,     0,     5,     0,     2,     0,     4,
       1,     3,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       3,     3,     0,     5,     4,     1,     3,     1,     1,     1,
       3,     2,     2,     7,     1,     1,     0,     5,     2,     0,
       1,     1,     3,     1,     3,     0,     0,     7,     3,     3,
       2
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
        case 2:
#line 74 "micko.y" /* yacc.c:1646  */
    {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
       }
#line 1381 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "micko.y" /* yacc.c:1646  */
    { 
	
     if( lookup_symbol((yyvsp[-1].s), GVAR) == NO_INDEX)
	insert_symbol((yyvsp[-1].s), GVAR, (yyvsp[-2].i), NO_ATR, NO_ATR);
     else 
           err("redefinition of '%s'", (yyvsp[-1].s));

    code("\n%s:\n\t\tWORD\t1", (yyvsp[-1].s));	
}
#line 1395 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "micko.y" /* yacc.c:1646  */
    {
        fun_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", (yyvsp[0].s));

 	code("\n%s:", (yyvsp[0].s));
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
#line 1411 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 115 "micko.y" /* yacc.c:1646  */
    {
        clear_symbols(fun_idx + pars + 1);
        var_num = 0;
	pars = 0;

 	code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1426 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 129 "micko.y" /* yacc.c:1646  */
    { set_atr1(fun_idx, pars); }
#line 1432 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 131 "micko.y" /* yacc.c:1646  */
    { set_atr1(fun_idx, pars); }
#line 1438 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 136 "micko.y" /* yacc.c:1646  */
    {
	if((yyvsp[-1].i) == VOID) err("parameter type can not be void"); 

	if(lookup_symbol((yyvsp[0].s), PAR|VAR) == NO_INDEX || lookup_symbol((yyvsp[0].s), PAR|VAR) < fun_idx){
           insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++pars, fun_idx); // drugi atribut parametra cuva kojoj funkciji pripada
    	}
	else
	 err("redefinition of function '%s'", (yyvsp[0].s));
      }
#line 1452 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 146 "micko.y" /* yacc.c:1646  */
    {
	if((yyvsp[-1].i) == VOID) err("parameter type can not be void");
 
	if(lookup_symbol((yyvsp[0].s), PAR|VAR) == NO_INDEX || lookup_symbol((yyvsp[0].s), PAR|VAR) < fun_idx){
          insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++pars, fun_idx);
	}
	else
	 err("redefinition of function '%s'", (yyvsp[0].s));
	}
#line 1466 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 160 "micko.y" /* yacc.c:1646  */
    { 
	if(var_num)
        code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
  }
#line 1476 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 166 "micko.y" /* yacc.c:1646  */
    {
	if (ret_val == 0 && get_type(fun_idx) != VOID)
	  warn("non void function must have a return");
  }
#line 1485 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 178 "micko.y" /* yacc.c:1646  */
    { if((yyvsp[0].i) == VOID) err("variable type can not be void"); var_type = (yyvsp[0].i); }
#line 1491 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 183 "micko.y" /* yacc.c:1646  */
    {
	int idx = lookup_symbol((yyvsp[0].s), VAR|PAR);
        if( idx == NO_INDEX || idx < fun_idx || get_atr2(idx) != lvl)
           insert_symbol((yyvsp[0].s), VAR, var_type, ++var_num, lvl);
        else 
           err("redefinition of '%s'", (yyvsp[0].s));
      }
#line 1503 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 191 "micko.y" /* yacc.c:1646  */
    {
       int idx = lookup_symbol((yyvsp[0].s), VAR|PAR);
        if( idx == NO_INDEX || idx < fun_idx || get_atr2(idx) != lvl)
           insert_symbol((yyvsp[0].s), VAR, var_type, ++var_num, lvl);
        else 
           err("redefinition of '%s'", (yyvsp[0].s));
      }
#line 1515 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 199 "micko.y" /* yacc.c:1646  */
    {
	int idx = lookup_symbol((yyvsp[-2].s), VAR|PAR);
	int reg;
        if( idx == NO_INDEX || idx < fun_idx || get_atr2(idx) != lvl)
           reg = insert_symbol((yyvsp[-2].s), VAR, var_type, ++var_num, lvl);
        else 
           err("redefinition of '%s'", (yyvsp[-2].s));

	gen_mov((yyvsp[0].i), reg);
  }
#line 1530 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 231 "micko.y" /* yacc.c:1646  */
    {
	int index = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
	if( index == NO_INDEX)
	  err("variable %s not defined", (yyvsp[0].s));
	if(get_kind(index) == PAR){
		if(index < fun_idx)
		  err("not defined for this f");
	}
 	(yyval.i) = ++lab_num;
        code("\n@for%d:", (yyval.i));
   
  }
#line 1547 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 244 "micko.y" /* yacc.c:1646  */
    {
	int index = lookup_symbol((yyvsp[-3].s), VAR|PAR|GVAR);
	if(get_type(index) != get_type((yyvsp[0].i)))
	  err("incompatible types in assignment");

	gen_mov((yyvsp[0].i), index);
  }
#line 1559 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 252 "micko.y" /* yacc.c:1646  */
    {
	int index = lookup_symbol((yyvsp[-6].s), VAR|PAR|GVAR);
 	if(get_type(index) != get_type((yyvsp[0].i)))
	  err("incompatible types in assignment");
	if(atoi(get_name((yyvsp[-3].i))) > atoi(get_name((yyvsp[0].i))))
	  err("first literal must be smaller");

	code("\n@check%d:", (yyvsp[-5].i));
	gen_cmp(index, (yyvsp[0].i));
	if(get_type((yyvsp[0].i)) == UINT)
	  code("\n\t\tJLTU\t@true%d", (yyvsp[-5].i));
	else
	  code("\n\t\tJLTS\t@true%d", (yyvsp[-5].i));

 	code("\n@false%d:", (yyvsp[-5].i));
	code("\n\t\tJMP\t@exit%d", (yyvsp[-5].i));
 	code("\n@true%d:", (yyvsp[-5].i));

  }
#line 1583 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 272 "micko.y" /* yacc.c:1646  */
    {
	int index = lookup_symbol((yyvsp[-9].s), VAR|PAR|GVAR);
	if(get_type((yyvsp[-3].i)) == UINT)
	  code("\n\t\tADDU\t");
	else
	  code("\n\t\tADDS\t");
	  gen_sym_name(index);
          code(", $1, ");
          gen_sym_name(index);

	code("\n\t\tJMP\t@check%d", (yyvsp[-8].i));
 	code("\n@exit%d:", (yyvsp[-8].i));
  }
#line 1601 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 289 "micko.y" /* yacc.c:1646  */
    {
	int index = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR); 
	if(index == -1)
	  err("variable %s not defined", (yyvsp[0].s));
	if(get_kind(index) == PAR){
		if(index < fun_idx)
		  err("not defined for this f");
	}

	(yyval.i) = ++lab_num;
        code("\n@branch%d:", (yyval.i));
  }
#line 1618 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 302 "micko.y" /* yacc.c:1646  */
    {
	int index = lookup_symbol((yyvsp[-3].s), VAR|PAR|GVAR); 
	if(get_type(index) != get_type((yyvsp[0].i)))
            err("incompatible types in assignment");

	gen_cmp(index, (yyvsp[0].i));
	code("\n\t\tJEQ\t@first%d", (yyvsp[-2].i));
  }
#line 1631 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 311 "micko.y" /* yacc.c:1646  */
    {
	int index = lookup_symbol((yyvsp[-6].s), VAR|PAR|GVAR); 
	if(get_type(index) != get_type((yyvsp[0].i)))
            err("incompatible types in assignment");

	gen_cmp(index, (yyvsp[0].i));
	code("\n\t\tJEQ\t@second%d", (yyvsp[-5].i));
  }
#line 1644 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 320 "micko.y" /* yacc.c:1646  */
    {
	int index = lookup_symbol((yyvsp[-9].s), VAR|PAR|GVAR); 
	if(get_type(index) != get_type((yyvsp[0].i)))
            err("incompatible types in assignment");

	gen_cmp(index, (yyvsp[0].i));
	code("\n\t\tJEQ\t@third%d", (yyvsp[-8].i));
	code("\n\t\tJMP\t@otherwise%d", (yyvsp[-8].i));
  }
#line 1658 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 330 "micko.y" /* yacc.c:1646  */
    {
        code("\n@first%d:", (yyvsp[-12].i));
  }
#line 1666 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 334 "micko.y" /* yacc.c:1646  */
    { code("\n\t\tJMP\t@exit%d", (yyvsp[-14].i));}
#line 1672 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 336 "micko.y" /* yacc.c:1646  */
    {
        code("\n@second%d:", (yyvsp[-17].i));
  }
#line 1680 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 340 "micko.y" /* yacc.c:1646  */
    { code("\n\t\tJMP\t@exit%d", (yyvsp[-19].i)); }
#line 1686 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 342 "micko.y" /* yacc.c:1646  */
    {
        code("\n@third%d:", (yyvsp[-22].i));
  }
#line 1694 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 346 "micko.y" /* yacc.c:1646  */
    { code("\n\t\tJMP\t@exit%d", (yyvsp[-24].i)); }
#line 1700 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 348 "micko.y" /* yacc.c:1646  */
    {
        code("\n@otherwise%d:", (yyvsp[-27].i));
  }
#line 1708 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 352 "micko.y" /* yacc.c:1646  */
    {
	code("\n@exit%d:", (yyvsp[-29].i));
  }
#line 1716 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 359 "micko.y" /* yacc.c:1646  */
    {
	if(lookup_symbol((yyvsp[-2].s), FUN) != -1)
	  err("function cannot be incremented");

	int idx = lookup_symbol((yyvsp[-2].s), VAR|PAR|GVAR); 
	if(idx == NO_INDEX || idx < fun_idx)
	  {
	  idx = lookup_symbol((yyvsp[-2].s), GVAR); 
	  if(idx == NO_INDEX)	
	    err("variable %s not defined", (yyvsp[-2].s));
         }

	if(get_type(idx) == INT)
	  code("\n\t\tADDS\t");
	else
	  code("\n\t\tADDU\t");
	gen_sym_name(idx);
 	code(", $1, ");
        gen_sym_name(idx);
    }
#line 1741 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 383 "micko.y" /* yacc.c:1646  */
    {
	if(lookup_symbol((yyvsp[-2].s), FUN) != -1)
	  err("function cannot be decremented");

	int idx = lookup_symbol((yyvsp[-2].s), VAR|PAR|GVAR); 
	if(idx == NO_INDEX || idx < fun_idx)
	  {
	  idx = lookup_symbol((yyvsp[-2].s), GVAR); 
	  if(idx == NO_INDEX)	
	    err("variable %s not defined", (yyvsp[-2].s));
         }

	if(get_type(idx) == INT)
	  code("\n\t\tSUBS\t");
	else
	  code("\n\t\tSUBU\t");
	gen_sym_name(idx);
 	code(", $1, ");
        gen_sym_name(idx);
    }
#line 1766 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 408 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = get_last_element(); lvl++; }
#line 1772 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 410 "micko.y" /* yacc.c:1646  */
    { lvl--; clear_symbols( (yyvsp[-3].i) + 1); }
#line 1778 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 415 "micko.y" /* yacc.c:1646  */
    {
        int idx = lookup_symbol((yyvsp[-3].s), VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", (yyvsp[-3].s));
       
        if(get_type(idx) != get_type((yyvsp[-1].i)))
            err("incompatible types in assignment");
        gen_mov((yyvsp[-1].i), idx);
      }
#line 1792 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 429 "micko.y" /* yacc.c:1646  */
    {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: arithmetic operation");
	else{
	int t1 = get_type((yyvsp[-2].i));    
        code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (t1 - 1) * AROP_NUMBER]);
        gen_sym_name((yyvsp[-2].i));
        code(",");
        gen_sym_name((yyvsp[0].i));
        code(",");
        free_if_reg((yyvsp[0].i));
        free_if_reg((yyvsp[-2].i));
        (yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), t1);
	}
      }
#line 1814 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 451 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
      }
#line 1824 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 457 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = take_reg();
        gen_mov(FUN_REG, (yyval.i));
  }
#line 1833 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 462 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 1839 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 464 "micko.y" /* yacc.c:1646  */
    {
	 int idx = lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("'%s' undeclared", (yyvsp[-1].s));

	if(lookup_symbol((yyvsp[-1].s), FUN) != NO_INDEX)
	  err("function cannot be incremented"); 
	(yyval.i) = take_reg();
	gen_mov(idx, (yyval.i));

	if(get_type(idx) == INT)
	  code("\n\t\tADDS\t");
	else
	  code("\n\t\tADDU\t");
	gen_sym_name(idx);
 	code(", $1, ");
        gen_sym_name(idx);
     }
#line 1862 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 483 "micko.y" /* yacc.c:1646  */
    {
	 int idx = lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("'%s' undeclared", (yyvsp[-1].s));

	if(lookup_symbol((yyvsp[-1].s), FUN) != NO_INDEX)
	  err("function cannot be incremented"); 
	(yyval.i) = take_reg();
	gen_mov(idx, (yyval.i));

	if(get_type(idx) == INT)
	  code("\n\t\tSUBS\t");
	else
	  code("\n\t\tSUBU\t");
	gen_sym_name(idx);
 	code(", $1, ");
        gen_sym_name(idx);
     }
#line 1885 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 503 "micko.y" /* yacc.c:1646  */
    {
	if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
	  err("Incompatible types");

	reg = take_reg();
	(yyval.i) = ++lab_num;
	code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[-5].i)], (yyval.i));
	code("\n@true%d:", (yyval.i));
	gen_mov((yyvsp[-2].i),reg);
	code("\n\t\tJMP\t@exit%d", (yyval.i));
	code("\n@false%d:", (yyval.i));
	gen_mov((yyvsp[0].i), reg);
	code("\n@exit%d:", (yyval.i));
	(yyval.i) = reg;
	
  }
#line 1906 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 523 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = insert_literal((yyvsp[0].s), INT); }
#line 1912 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 526 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = insert_literal((yyvsp[0].s), UINT); }
#line 1918 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 531 "micko.y" /* yacc.c:1646  */
    {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));
      }
#line 1928 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 537 "micko.y" /* yacc.c:1646  */
    {
        if(get_atr1(fcall_idx) != (yyvsp[-1].i))
          err("wrong number of args to function '%s'", 
              get_name(fcall_idx));

 	code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if((yyvsp[-1].i) > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", (yyvsp[-1].i) * 4);
        set_type(FUN_REG, get_type(fcall_idx));
	args = 0;
        (yyval.i) = FUN_REG;
      }
#line 1945 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 553 "micko.y" /* yacc.c:1646  */
    {
	if(get_type(fcall_idx) != VOID)
           err("void function cannot be assigned");
   }
#line 1954 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 561 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = args; }
#line 1960 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 563 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = args; }
#line 1966 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 568 "micko.y" /* yacc.c:1646  */
    { 
      if(get_type(fcall_idx + args + 1) != get_type((yyvsp[0].i)))
        err("incompatible type for argument in '%s'",
            get_name(fcall_idx));
      args++;
      free_if_reg((yyvsp[0].i));
      code("\n\t\t\tPUSH\t");
      gen_sym_name((yyvsp[0].i));
    }
#line 1980 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 578 "micko.y" /* yacc.c:1646  */
    {
      if(get_type(fcall_idx + args + 1) != get_type((yyvsp[0].i)))
        err("incompatible type for argument in '%s'",
            get_name(fcall_idx));
	args++;
      free_if_reg((yyvsp[0].i));
      code("\n\t\t\tPUSH\t");
      gen_sym_name((yyvsp[0].i));
     }
#line 1994 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 591 "micko.y" /* yacc.c:1646  */
    { code("\n@exit%d:", (yyvsp[0].i)); }
#line 2000 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 593 "micko.y" /* yacc.c:1646  */
    { code("\n@exit%d:", (yyvsp[-2].i)); }
#line 2006 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 598 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
      }
#line 2015 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 603 "micko.y" /* yacc.c:1646  */
    {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i));
        code("\n@true%d:", (yyvsp[-1].i));
      }
#line 2024 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 608 "micko.y" /* yacc.c:1646  */
    {
        code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
        code("\n@false%d:", (yyvsp[-4].i));
        (yyval.i) = (yyvsp[-4].i);
      }
#line 2034 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 617 "micko.y" /* yacc.c:1646  */
    {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: relational operator");
 	(yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[-2].i), (yyvsp[0].i));
      }
#line 2045 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 627 "micko.y" /* yacc.c:1646  */
    {
	ret_val = 1;
	if(get_type(fun_idx) == VOID)
          err("void function cannot have return expression");

        if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
          err("incompatible types in return");

 	gen_mov((yyvsp[-1].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));   
      }
#line 2061 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 640 "micko.y" /* yacc.c:1646  */
    {
	ret_val = 1;
        if(get_type(fun_idx) != VOID)
          warn("non void function must have return expression");
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));   
  }
#line 2072 "micko.tab.c" /* yacc.c:1646  */
    break;


#line 2076 "micko.tab.c" /* yacc.c:1646  */
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
#line 650 "micko.y" /* yacc.c:1906  */


int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

