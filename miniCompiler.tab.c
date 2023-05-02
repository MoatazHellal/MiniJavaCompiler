
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
#line 1 "miniCompiler.y"

	

#include <stdio.h>	
#include "Semantic.c"
#include "Generator.c"

extern char *yytext;
int numval;
int boolval;
char nom[256];
char codeMethod[256];
char* opCode;
int indexIf;
int indexWhile1;
int indexWhile2;
 			
int yyerror(char const *msg);	
int yylex(void);
extern int yylineno;



/* Line 189 of yacc.c  */
#line 97 "miniCompiler.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     Ident = 258,
     int_type = 259,
     boolean_type = 260,
     string_type = 261,
     Boolean_Literal = 262,
     Integer_Literal = 263,
     String_Literal = 264,
     class_keyword = 265,
     public_keyword = 266,
     main_class_keyword = 267,
     extends_keyword = 268,
     return_keyword = 269,
     if_keyword = 270,
     else_keyword = 271,
     whileloop_keyword = 272,
     print_keyword = 273,
     length_keyword = 274,
     this_keyword = 275,
     new_keyword = 276,
     open_parenthese = 277,
     closed_parenthese = 278,
     open_bracket = 279,
     closed_bracket = 280,
     open_brace = 281,
     closed_brace = 282,
     OP_AFFECT = 283,
     OP_ADD = 284,
     OP_SUBSTRACT = 285,
     OP_MULTIPLY = 286,
     OP_NOT = 287,
     LOG_AND = 288,
     LOG_LESS = 289,
     LOG_EQLESS = 290,
     LOG_MORE = 291,
     LOG_EQMORE = 292,
     LOG_EQ = 293,
     LOG_DIF = 294,
     SEMI_COLON = 295,
     DOT = 296,
     COMMA = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 181 "miniCompiler.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    40,    43,    44,    47,    48,    51,    52,    55,
      56,    57,    58,    59,    70,    71,    76,    80,    84,    88,
      89,    95,    96,    97,   102,   103,   104,   105,   106,   107,
     108,   127,   129,   131,   135,   138,   139,   140,   141,   142,
     153,   154,   155,   156,   157,   158,   168,   174,   175,   176,
     184,   185,   186,   196,   200,   203,   205,   207,   209,   211,
     212,   213,   214,   215,   216,   223,   224,   227,   233,   238,
     242,   243,   244,   248,   249,   250,   254,   255,   260,   265,
     266,   270,   274,   275,   276,   277,   287,   291,   292,   295,
     296
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    10,   108,    47,    26,    55,
      11,    12,    48,    49,    22,     6,    24,    25,   108,    50,
      23,    26,    55,    75,    27,    51,    52,    27,    53,    -1,
      58,    54,    -1,    -1,    62,    55,    -1,    -1,    68,    56,
      -1,    -1,    13,   108,    -1,    -1,    -1,    -1,    -1,    59,
      10,   108,    60,    57,    26,    55,    56,    27,    61,    -1,
      -1,    74,   108,    63,    40,    -1,     1,   108,    40,    -1,
      74,     1,    40,    -1,    74,   108,     1,    -1,    -1,    42,
      74,   108,    65,    64,    -1,    -1,    -1,    74,   108,    67,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    74,
     108,    69,    70,    22,    71,    66,    72,    23,    26,    55,
      75,    14,    90,    40,    27,    73,    -1,     4,    -1,     5,
      -1,     4,    24,    25,    -1,    76,    75,    -1,    -1,    -1,
      -1,    -1,   108,    24,    90,    25,    77,    78,    79,    28,
      90,    40,    -1,    -1,    -1,    -1,    -1,    -1,   108,    80,
      81,    82,    28,    83,    90,    84,    40,    -1,    18,    22,
      90,    23,    40,    -1,    -1,    -1,    17,    85,    22,    90,
      23,    86,    76,    -1,    -1,    -1,    15,    22,    90,    23,
      87,    76,    16,    88,    76,    -1,    26,    75,    27,    -1,
      33,    33,    -1,    34,    -1,    29,    -1,    30,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    91,    92,    93,
      94,    95,    -1,    -1,    20,    96,    -1,    21,     4,    24,
      90,    25,    -1,    21,   108,    22,    23,    -1,    22,    90,
      23,    -1,    -1,    -1,     7,    97,    98,    -1,    -1,    -1,
       8,    99,   100,    -1,    -1,    90,    41,    19,   101,    -1,
      90,    24,    90,    25,    -1,    -1,    32,    90,   102,    -1,
      90,    89,    90,    -1,    -1,    -1,    -1,    90,    41,   108,
     103,   104,    22,   107,    23,   105,    -1,    42,    90,   106,
      -1,    -1,    90,   106,    -1,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    80,    80,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    84,    84,    86,    86,    88,    88,    90,    90,
      92,    92,    92,    92,    95,    95,    96,    97,    98,   100,
     100,   100,   104,   104,   104,   106,   106,   106,   106,   106,
     106,   108,   110,   111,   113,   113,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   118,   119,   119,   119,
     120,   120,   120,   121,   123,   123,   123,   123,   123,   125,
     125,   125,   125,   125,   125,   126,   126,   127,   128,   129,
     130,   130,   130,   131,   131,   131,   132,   132,   133,   134,
     134,   135,   136,   136,   136,   136,   138,   138,   140,   140,
     142
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Ident", "int_type", "boolean_type",
  "string_type", "Boolean_Literal", "Integer_Literal", "String_Literal",
  "class_keyword", "public_keyword", "main_class_keyword",
  "extends_keyword", "return_keyword", "if_keyword", "else_keyword",
  "whileloop_keyword", "print_keyword", "length_keyword", "this_keyword",
  "new_keyword", "open_parenthese", "closed_parenthese", "open_bracket",
  "closed_bracket", "open_brace", "closed_brace", "OP_AFFECT", "OP_ADD",
  "OP_SUBSTRACT", "OP_MULTIPLY", "OP_NOT", "LOG_AND", "LOG_LESS",
  "LOG_EQLESS", "LOG_MORE", "LOG_EQMORE", "LOG_EQ", "LOG_DIF",
  "SEMI_COLON", "DOT", "COMMA", "$accept", "Program", "MainClass", "$@1",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "ClassDeclarationList",
  "VarDeclarationList", "MethodDeclarationList", "extend_key_id",
  "ClassDeclaration", "$@9", "$@10", "$@11", "VarDeclaration", "$@12",
  "COMMATypeIdentifierList", "$@13", "type_id", "$@14",
  "MethodDeclaration", "$@15", "$@16", "$@17", "$@18", "$@19", "Type",
  "StatementList", "Statement", "$@20", "$@21", "$@22", "$@23", "$@24",
  "$@25", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "op",
  "Expression", "$@32", "$@33", "$@34", "$@35", "$@36", "$@37", "$@38",
  "$@39", "$@40", "$@41", "$@42", "$@43", "$@44", "$@45", "$@46",
  "ExpressionList", "Expr", "Identifier", 0
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
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    46,    47,    48,    49,    50,    51,    52,
      53,    45,    54,    54,    55,    55,    56,    56,    57,    57,
      59,    60,    61,    58,    63,    62,    62,    62,    62,    65,
      64,    64,    67,    66,    66,    69,    70,    71,    72,    73,
      68,    74,    74,    74,    75,    75,    77,    78,    79,    76,
      80,    81,    82,    83,    84,    76,    76,    85,    86,    76,
      87,    88,    76,    76,    89,    89,    89,    89,    89,    91,
      92,    93,    94,    95,    90,    96,    90,    90,    90,    90,
      97,    98,    90,    99,   100,    90,   101,    90,    90,   102,
      90,    90,   103,   104,   105,    90,   106,   106,   107,   107,
     108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     2,     0,     2,     0,     2,     0,     2,     0,
       0,     0,     0,    10,     0,     4,     3,     3,     3,     0,
       5,     0,     0,     4,     0,     0,     0,     0,     0,     0,
      18,     1,     1,     3,     2,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     9,     5,     0,     0,     7,
       0,     0,     9,     3,     2,     1,     1,     1,     1,     0,
       0,     0,     0,     0,     6,     0,     2,     5,     4,     3,
       0,     0,     3,     0,     0,     3,     0,     4,     4,     0,
       3,     3,     0,     0,     0,     9,     3,     0,     2,     0,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    13,     0,     1,     2,    13,     0,     0,    12,
       0,   100,     4,    21,     0,    19,     0,     0,     0,     0,
      41,    42,     0,     0,     0,    18,     0,     0,     0,     0,
      14,     0,     0,    17,    26,    43,     5,    27,    28,     0,
       0,     0,    17,     6,    25,     0,    22,    16,     0,    35,
      23,     0,    36,     0,     0,     0,    37,     0,    34,     7,
      38,     0,     0,     0,    32,     0,     0,    31,     0,     0,
       0,    33,    45,    45,     0,     0,    57,     0,    45,     0,
      45,    50,     0,    29,     0,     0,     0,     0,     8,    44,
       0,    51,     0,    31,    80,    83,    75,     0,     0,     0,
       0,    69,     0,     0,    63,     9,     0,    52,     0,    30,
      81,    84,    76,     0,     0,     0,    89,    60,     0,    66,
      67,    68,     0,    65,     0,     0,    70,     0,     0,     0,
      46,     0,     0,    82,    85,     0,     0,    79,    90,     0,
       0,    64,    86,    92,    91,    71,    58,    56,    10,    47,
      53,    39,     0,    78,     0,    88,    87,    93,    72,     0,
      11,    48,     0,    40,    77,    61,     0,    73,    59,     0,
      54,     0,    99,    74,     0,     0,    62,    97,     0,     0,
      55,     0,    98,    94,    49,    97,    95,    96
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,    14,    43,    48,    62,   105,   129,
     160,     5,    22,    41,    18,     6,     7,    15,    50,    23,
      39,    71,    93,    60,    67,    42,    52,    54,    58,    63,
     163,    24,    79,    80,   149,   161,   169,    91,   107,   131,
     162,   175,    85,   159,   139,   171,   125,   100,   126,   145,
     158,   167,   173,   112,   110,   133,   111,   134,   156,   138,
     157,   166,   186,   182,   178,   101
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -133
static const yytype_int16 yypact[] =
{
    -133,    14,     7,    15,  -133,  -133,     7,    18,    30,  -133,
      30,  -133,  -133,  -133,     8,    35,    39,    30,    31,    30,
      17,  -133,    40,    92,    12,  -133,    25,    19,    29,    46,
    -133,    23,     2,    57,  -133,  -133,  -133,  -133,  -133,    37,
      16,    44,    57,  -133,  -133,    30,  -133,  -133,    56,  -133,
    -133,    74,  -133,    55,    59,    58,  -133,    30,    16,  -133,
    -133,    30,    61,    63,  -133,    72,    76,    45,   110,   129,
      16,  -133,    73,    73,    30,    78,  -133,    82,    73,    81,
      73,    88,    91,  -133,    53,    95,    53,    93,  -133,  -133,
      53,  -133,    53,    45,  -133,  -133,  -133,    28,    53,    53,
     135,  -133,    53,   148,  -133,  -133,   201,  -133,   214,  -133,
    -133,  -133,  -133,    97,   100,   161,   266,  -133,    53,  -133,
    -133,  -133,    90,  -133,     5,    53,  -133,   174,    84,    99,
    -133,   101,   108,  -133,  -133,    53,   115,  -133,  -133,    73,
     227,  -133,  -133,  -133,   266,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,   240,  -133,   123,  -133,  -133,  -133,  -133,    73,
    -133,  -133,    53,  -133,  -133,  -133,   118,  -133,  -133,   113,
     266,    73,    53,  -133,    53,   102,  -133,   187,   122,   253,
    -133,    53,  -133,  -133,  -133,   187,  -133,  -133
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,   142,   -22,   107,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,    60,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,   -35,   -11,  -132,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,   -80,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,   -33,  -133,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -25
static const yytype_int16 yytable[] =
{
      12,    30,    13,    38,    33,    45,   103,   154,    11,    25,
     106,    27,   108,    31,     4,    11,    32,   -20,   115,   116,
      20,    21,   127,    61,   142,     8,    19,   168,    10,    20,
      21,    11,   113,    11,    16,    74,   -15,    49,   140,   176,
      19,    28,   -24,    20,    21,   144,    72,    73,    17,    59,
     -15,    29,   -15,    64,    35,   152,    11,    26,    36,    34,
      94,    95,    82,    37,    81,    81,    83,    87,    40,    89,
      81,    46,    81,    96,    97,    98,    11,    44,    51,    55,
      53,    56,   170,    57,    65,    99,    66,    70,    75,   114,
      76,    77,   177,    19,   179,   -15,    20,    21,    68,    78,
      84,   185,    69,   -15,    86,    92,   -15,   -15,    88,   -15,
     -15,    19,    90,   -15,    20,    21,   143,   102,   -15,   -15,
     104,   135,   136,   141,   147,   -15,   148,   -15,   -15,   150,
      19,    81,   -15,    20,    21,   151,   -15,   -15,   153,   165,
     172,   174,   180,   -15,   -15,   183,   -15,   -15,     9,    47,
       0,    81,   187,   109,     0,   -15,     0,     0,   117,   118,
       0,     0,     0,    81,   119,   120,   121,     0,   122,   123,
       0,   128,   118,     0,     0,     0,   124,   119,   120,   121,
       0,   122,   123,     0,   137,   118,     0,     0,     0,   124,
     119,   120,   121,     0,   122,   123,     0,   146,   118,     0,
       0,     0,   124,   119,   120,   121,     0,   122,   123,     0,
       0,   118,     0,     0,     0,   124,   119,   120,   121,     0,
     122,   123,     0,     0,     0,   118,   130,     0,   124,   181,
     119,   120,   121,     0,   122,   123,     0,     0,   118,     0,
       0,     0,   124,   119,   120,   121,     0,   122,   123,     0,
       0,   118,   155,     0,   132,   124,   119,   120,   121,     0,
     122,   123,     0,     0,   118,   164,     0,     0,   124,   119,
     120,   121,     0,   122,   123,     0,     0,   118,     0,     0,
       0,   124,   119,   120,   121,     0,   122,   123,     0,     0,
     118,     0,     0,   184,   124,   119,   120,   121,     0,   122,
     123,     0,     0,     0,     0,     0,     0,   124
};

static const yytype_int16 yycheck[] =
{
       8,    23,    10,     1,    26,    40,    86,   139,     3,    17,
      90,    19,    92,     1,     0,     3,    24,    10,    98,    99,
       4,     5,   102,    58,    19,    10,     1,   159,    10,     4,
       5,     3,     4,     3,    26,    70,    11,    45,   118,   171,
       1,    24,    40,     4,     5,   125,    68,    69,    13,    57,
      11,    11,    27,    61,    25,   135,     3,    26,    12,    40,
       7,     8,    73,    40,    72,    73,    74,    78,    11,    80,
      78,    27,    80,    20,    21,    22,     3,    40,    22,    24,
       6,    22,   162,    25,    23,    32,    23,    42,    15,    97,
      17,    18,   172,     1,   174,     3,     4,     5,    26,    26,
      22,   181,    26,    11,    22,    14,    14,    15,    27,    17,
      18,     1,    24,     3,     4,     5,   124,    22,    26,    27,
      27,    24,    22,    33,    40,    15,    27,    17,    18,    28,
       1,   139,     3,     4,     5,    27,    26,    27,    23,    16,
      22,    28,    40,    14,    15,    23,    17,    18,     6,    42,
      -1,   159,   185,    93,    -1,    26,    -1,    -1,    23,    24,
      -1,    -1,    -1,   171,    29,    30,    31,    -1,    33,    34,
      -1,    23,    24,    -1,    -1,    -1,    41,    29,    30,    31,
      -1,    33,    34,    -1,    23,    24,    -1,    -1,    -1,    41,
      29,    30,    31,    -1,    33,    34,    -1,    23,    24,    -1,
      -1,    -1,    41,    29,    30,    31,    -1,    33,    34,    -1,
      -1,    24,    -1,    -1,    -1,    41,    29,    30,    31,    -1,
      33,    34,    -1,    -1,    -1,    24,    25,    -1,    41,    42,
      29,    30,    31,    -1,    33,    34,    -1,    -1,    24,    -1,
      -1,    -1,    41,    29,    30,    31,    -1,    33,    34,    -1,
      -1,    24,    25,    -1,    40,    41,    29,    30,    31,    -1,
      33,    34,    -1,    -1,    24,    25,    -1,    -1,    41,    29,
      30,    31,    -1,    33,    34,    -1,    -1,    24,    -1,    -1,
      -1,    41,    29,    30,    31,    -1,    33,    34,    -1,    -1,
      24,    -1,    -1,    40,    41,    29,    30,    31,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    45,    46,     0,    54,    58,    59,    10,    54,
      10,     3,   108,   108,    47,    60,    26,    13,    57,     1,
       4,     5,    55,    62,    74,   108,    26,   108,    24,    11,
      55,     1,   108,    55,    40,    25,    12,    40,     1,    63,
      11,    56,    68,    48,    40,    74,    27,    56,    49,   108,
      61,    22,    69,     6,    70,    24,    22,    25,    71,   108,
      66,    74,    50,    72,   108,    23,    23,    67,    26,    26,
      42,    64,    55,    55,    74,    15,    17,    18,    26,    75,
      76,   108,    75,   108,    22,    85,    22,    75,    27,    75,
      24,    80,    14,    65,     7,     8,    20,    21,    22,    32,
      90,   108,    22,    90,    27,    51,    90,    81,    90,    64,
      97,    99,    96,     4,   108,    90,    90,    23,    24,    29,
      30,    31,    33,    34,    41,    89,    91,    90,    23,    52,
      25,    82,    40,    98,   100,    24,    22,    23,   102,    87,
      90,    33,    19,   108,    90,    92,    23,    40,    27,    77,
      28,    27,    90,    23,    76,    25,   101,   103,    93,    86,
      53,    78,    83,    73,    25,    16,   104,    94,    76,    79,
      90,    88,    22,    95,    28,    84,    76,    90,   107,    90,
      40,    42,   106,    23,    40,    90,   105,   106
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
        case 3:

/* Line 1455 of yacc.c  */
#line 82 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("ENTREE",-1, NULL); indextab++;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 82 "miniCompiler.y"
    {checkIdentifier(nom, tOther ,class, yylineno);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 82 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("ENTREE",-1, "main"); indextab++;;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 82 "miniCompiler.y"
    { checkIdentifier("main", tVoid, fonction, yylineno); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 82 "miniCompiler.y"
    {checkIdentifier(nom, tString, parametre, yylineno);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 82 "miniCompiler.y"
    {fonctionEnd();;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 82 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("SORTIE",-1, "main"); indextab++;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 82 "miniCompiler.y"
    {classEnd();;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 82 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("SORTIE",-1,NULL); indextab++;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 92 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("ENTREE",-1,NULL); indextab++;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 92 "miniCompiler.y"
    {checkIdentifier(nom, tOther ,class, yylineno);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 92 "miniCompiler.y"
    {classEnd();;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 92 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("SORTIE",-1,NULL); indextab++;;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 95 "miniCompiler.y"
    {checkIdentifier(nom, type ,variable , yylineno);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 96 "miniCompiler.y"
    {yyerror (" Type attendu en ligne : "); YYABORT;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 97 "miniCompiler.y"
    {yyerror (" Identifier attendu en ligne : "); YYABORT;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 98 "miniCompiler.y"
    {yyerror (" Point virgule attendu en ligne : "); YYABORT;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 100 "miniCompiler.y"
    {checkIdentifier(nom, type ,variable , yylineno);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 104 "miniCompiler.y"
    {checkIdentifier(nom, type ,variable , yylineno);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 106 "miniCompiler.y"
    {strcpy(codeMethod, nom); tabCodeInt[indextab]=creerCode("ENTREE",-1,codeMethod); indextab++;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 106 "miniCompiler.y"
    {checkIdentifier(nom, type , fonction, yylineno);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 106 "miniCompiler.y"
    {inParam();;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 106 "miniCompiler.y"
    {outParam();;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 106 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("SORTIE",-1,codeMethod);indextab++;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 106 "miniCompiler.y"
    {fonctionEnd();;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 108 "miniCompiler.y"
    {type=tInt;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 110 "miniCompiler.y"
    {type=tBoolean;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 111 "miniCompiler.y"
    {type=tInt;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 116 "miniCompiler.y"
    {verifierVarDeclared(nom, yylineno);}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 116 "miniCompiler.y"
    {initVar(nom, yylineno);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 116 "miniCompiler.y"
    {useVar(nom);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 117 "miniCompiler.y"
    {verifierVarDeclared(nom, yylineno);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 117 "miniCompiler.y"
    {useVar(nom);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 117 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("LDV",getAddress(nom,table_total),NULL);indextab++;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 117 "miniCompiler.y"
    {initVar(nom, yylineno);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 117 "miniCompiler.y"
    {verifierTypeAffectation(nom, typeAffect, yylineno);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 117 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("STORE",getAddress(nom,table_total),NULL);indextab++;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 119 "miniCompiler.y"
    {indexWhile1=indextab;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 119 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("TANTQUEFAUX",-1,NULL);indexWhile2=indextab;indextab++;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 119 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("TANTQUE",indexWhile1,NULL);indextab++;tabCodeInt[indexWhile2].operande=indextab;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 120 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("SIFAUX",-1,NULL);indexIf=indextab;indextab++;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 120 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("SAUT",-1,NULL);indextab++;tabCodeInt[indexIf].operande=indextab;indexIf=indextab-1;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 120 "miniCompiler.y"
    {tabCodeInt[indexIf].operande=indextab+1;;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 123 "miniCompiler.y"
    {opCode="AND";;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 123 "miniCompiler.y"
    {opCode="INF";;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 123 "miniCompiler.y"
    {opCode="ADD";;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 123 "miniCompiler.y"
    {opCode="SUB";;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 123 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("MUL",-1,NULL);indextab++;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 125 "miniCompiler.y"
    {(verifierVarDeclared(nom, yylineno));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 125 "miniCompiler.y"
    {verifierVarInitialise(nom, yylineno);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 125 "miniCompiler.y"
    {useVar(nom);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 125 "miniCompiler.y"
    {fonctionCallParameter(tInt, nom, yylineno);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 125 "miniCompiler.y"
    {typeAffect = type;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 125 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("LDV",getAddress(nom,table_total),NULL);indextab++;;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 126 "miniCompiler.y"
    {fonctionCallParameter(tOther, NULL, yylineno);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 126 "miniCompiler.y"
    {typeAffect = tOther;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 128 "miniCompiler.y"
    {fonctionCallParameter(tOther, NULL, yylineno);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 130 "miniCompiler.y"
    {fonctionCallParameter(tBoolean, NULL, yylineno);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 130 "miniCompiler.y"
    {typeAffect = tBoolean;;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 130 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("LDC",boolval,NULL);indextab++;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 131 "miniCompiler.y"
    {fonctionCallParameter(tInt, NULL, yylineno);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 131 "miniCompiler.y"
    {typeAffect = tInt;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 131 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("LDC",numval,NULL);indextab++;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 132 "miniCompiler.y"
    {fonctionCallParameter(tInt, NULL, yylineno);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 132 "miniCompiler.y"
    {typeAffect = tInt;;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 134 "miniCompiler.y"
    {fonctionCallParameter(tBoolean, NULL, yylineno);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 134 "miniCompiler.y"
    {typeAffect = tBoolean;;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 135 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode(opCode,-1,NULL);indextab++;;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 136 "miniCompiler.y"
    {fonctionCallStart(nom, type, yylineno);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 136 "miniCompiler.y"
    {typeAffect = type;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 136 "miniCompiler.y"
    {verifierFonctionArguments(yylineno);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 136 "miniCompiler.y"
    {tabCodeInt[indextab]=creerCode("APPEL",getFonctionLine(nom),NULL);indextab++;;}
    break;



/* Line 1455 of yacc.c  */
#line 2083 "miniCompiler.tab.c"
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
#line 147 "miniCompiler.y"



int yyerror(char const *msg) {
       
	
	fprintf(stderr, "%s %d\n", msg,yylineno);
	exit(0);
	return 0;
	
	
}

extern FILE *yyin;

int main()
{

 	table_global = NULL;
	table_local = NULL;
	table_total = NULL;
	actual_local = NULL;
	actual_global = NULL;
	type = tOther;
	isLocal =0;
	yyparse();
	printf("\n");
	endProgram();
	printf("\n");
	DisplaySymbolsTable(table_global);
	printf("\n");
	DisplaySymbolsTable(table_local);
	printf("\n");
	genererCode();
	destructSymbolsTable(table_local);
	destructSymbolsTable(table_global);
}

  char *yyget_text(char *start) {
    size_t size =  1;
    char *text = malloc(size + 1);
    strncpy(text, start, size);
    text[size] = '\0';
    return text;
}

           

