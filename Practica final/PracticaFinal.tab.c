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
#line 1 "PracticaFinal.y" /* yacc.c:339  */

    #include "TablaSimbolos.h"
#line 5 "PracticaFinal.y" /* yacc.c:339  */

    lista* tablaSim; //Declarar la estructura a usar
    char ans[1000]; //Cadena auxiliar para convertir a string y operaciones con cadenas (obtener memoria para la nueva cadena)

    //Funcion que concatena cadenas, 
    char * concat(char * a, char * b) { 
        strcpy(ans, ""); 
        strcat(ans,  a); 
        strcat(ans,  b); 
        return strdup(ans); //regresa la direccion de la memoria reservada
    }
    //Funcion que resta cadenas
    char * remstr(char * a, char * b) {
        char *  x = strstr(a, b); //Retorna un apuntador a la posicion de la cadena b en a 
        if (!x) return strdup(a); //Si no existe la cadena b en a, regresa la dir mem para a
        int k = x - a, i = 0; //Operacion con apuntadores que nos da la posicion de la cadena
        int m =    strlen(b); 
        strcpy(ans, "");
        for (i = 0; i <= k; i++) //Almacenar los caracteres a la izquierda
        ans[i]   =  a[i];
        ans[i - 1] =  '\0';
        strcat(ans, x + m); //Almacenar los caracteres a la derecha de la cadena b en la cadena a
        return strdup(ans);
    }

#line 95 "PracticaFinal.tab.c" /* yacc.c:339  */

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
   by #include "PracticaFinal.tab.h".  */
#ifndef YY_YY_PRACTICAFINAL_TAB_H_INCLUDED
# define YY_YY_PRACTICAFINAL_TAB_H_INCLUDED
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
    tipoInt = 258,
    tipoDouble = 259,
    tipoString = 260,
    valorInt = 261,
    valorDouble = 262,
    valorString = 263,
    intDeclarado = 264,
    varNoDecla = 265,
    doubleDeclarado = 266,
    stringDeclarado = 267
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "PracticaFinal.y" /* yacc.c:355  */

    int Int;
    double Double;
    char* String;

#line 154 "PracticaFinal.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PRACTICAFINAL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 171 "PracticaFinal.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  172
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  392

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   267

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      20,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    17,     2,     2,
      21,    22,    16,    13,     2,    14,     2,    15,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
       2,    19,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    64,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   118,   119,   120,
     121,   122,   125,   131,   136,   142,   147,   152,   159,   160,
     161,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   209,   210,   211,   212,   213,   214,   215,   217,
     218,   219,   220,   221,   222,   224,   225,   226,   227,   228,
     230,   231,   232,   233,   234,   236,   237,   238,   239,   240,
     241,   243,   244,   245,   246,   247,   248,   250,   251,   252,
     253,   254,   255,   257,   258,   260,   261,   262,   264,   265,
     266,   267,   270,   271,   272,   274,   275,   276,   277,   278,
     279,   281,   282,   283,   285,   286,   287,   288,   289,   290,
     292,   293,   294
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tipoInt", "tipoDouble", "tipoString",
  "valorInt", "valorDouble", "valorString", "intDeclarado", "varNoDecla",
  "doubleDeclarado", "stringDeclarado", "'+'", "'-'", "'/'", "'*'", "'%'",
  "'^'", "'='", "'\\n'", "'('", "')'", "';'", "$accept", "input", "line",
  "expInt", "expDouble", "expString", "declaracion", "asignacion",
  "errorAsignaTip", "errorOpTipo", "errorVarDefinida", "errorRedifincion", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    43,    45,    47,    42,    37,    94,    61,
      10,    40,    41,    59
};
# endif

#define YYPACT_NINF -10

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-10)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,    14,   -10,   165,   180,   205,   -10,   -10,   -10,    -9,
      -8,    -7,    10,    85,    -5,   -10,    -5,   -10,  1084,  1092,
    1100,    11,    31,    51,    58,  1108,    73,     7,    13,    30,
      72,    79,    33,    93,   107,    81,    91,   124,   125,    -5,
      -5,    -5,    -5,   -10,    85,    85,   214,    99,   122,   127,
      -5,   245,   270,   505,   285,  1014,  1024,  1034,  1044,    -5,
      -5,    -5,    -5,    -5,    -5,   -10,    -5,    -5,    -5,    -5,
      36,    -5,   -10,    -5,    -5,    -5,    -5,    -5,    -5,   -10,
     -10,   -10,   -10,   -10,    -5,    -5,    -5,    -5,    -5,    -5,
     -10,   -10,   -10,    36,   -10,   -10,   -10,   -10,    36,   -10,
     -10,   -10,    -5,   -10,    36,   -10,    -5,   -10,    -5,   -10,
     108,   195,   236,   302,   318,   343,   354,   366,   377,   388,
     413,   424,   439,   487,   523,   552,   214,  1054,    85,    85,
      85,    85,    85,    85,    -5,    -5,    -5,   505,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,   106,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,   -10,   -10,   -10,   -10,
     245,   270,   563,   285,   245,   270,   574,   285,   133,   134,
     585,   135,   133,   134,   596,   135,   133,   134,   607,   135,
     -10,   -10,   618,   -10,   245,   270,   629,   285,   245,   270,
     640,   285,   133,   134,   651,   135,   133,   134,   662,   135,
     -10,   -10,   106,    36,   142,   149,    41,   -10,   -10,   673,
     -10,   684,   695,   306,   285,   706,   717,   306,   285,   728,
     739,   505,   135,   750,   761,   505,   135,   772,   783,   505,
     135,   794,   805,   505,   -10,   245,   270,   306,   285,   245,
     270,   306,   285,   133,   134,   160,   135,   133,   134,   160,
     135,   133,  1116,   160,   135,   -10,   -10,   -10,   -10,   816,
     827,    66,   838,   849,   115,   860,   871,   882,   893,   904,
     915,   119,   926,   937,   948,   959,   970,   981,   992,  1003,
     -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,   -10,   -10,   -10,   214,   214,   167,   167,
     167,   -10,  1122,   106,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,   -10,   322,   347,  1064,  1074,    68,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
      25,    25,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,   -10,   -10,   -10,   -10,   322,   347,   322,
     347,   142,   149,   142,   149,   142,   149,   -10,   -10,   322,
     347,   322,   347,   142,   149,   142,   149,   -10,   -10,    25,
     -10,   -10
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,    14,    25,    47,    24,
     102,    46,    51,     0,     0,     4,     0,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,     0,    23,    24,    46,    51,
       0,    22,    45,    97,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,    10,    11,     0,     0,     0,     0,     0,     0,
      12,    13,   154,     0,    55,   160,   159,   158,     0,    56,
     153,   157,     0,   156,     0,    57,     0,   155,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    44,    50,   144,
      15,    34,     0,   103,    16,    35,     0,   104,    19,    37,
       0,   106,    17,    36,     0,   105,    18,    33,     0,   107,
      20,    32,     0,   108,    38,    26,     0,   115,    39,    27,
       0,   116,    41,    29,     0,   118,    40,    28,     0,   117,
      46,    51,     0,     0,    42,    30,     0,    43,    31,     0,
     119,     0,     0,    48,   125,     0,     0,    49,   126,     0,
       0,    99,   128,     0,     0,    98,   127,     0,     0,   100,
     129,     0,     0,   101,   130,   109,   120,   131,   137,   110,
     121,   132,   138,   112,   123,   134,   140,   111,   122,   133,
     139,   113,     0,   135,   141,   114,   124,   136,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    64,    63,   148,   145,   146,   147,   151,    66,    60,
      65,   149,    61,    62,    58,   150,    15,    16,    19,    17,
      18,    20,     0,     0,    85,    86,    88,    87,    89,    90,
      91,    92,    94,    93,    22,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,    73,    79,    74,    80,    76,    82,
      75,    81,    77,    83,    78,    84,    52,    70,    69,    71,
      54,    72,   162,   166,   167,   172,    67,    68,    53,   168,
     163,   169,   171,   161,   164,   165,   170,    15,    34,    16,
      35,    19,    37,    17,    36,    18,    33,    20,    32,    38,
      26,    39,    27,    41,    29,    40,    28,    43,    31,     0,
      48,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -10,   -10,   -10,    95,   206,    -1,   -10,   -10,   -10,   -10,
     409,   -10
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    17,   302,   252,   137,    21,    22,    23,    24,
      54,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      20,     6,     7,     8,    47,    10,    48,    49,    13,    50,
      39,    40,    41,    53,     2,    57,    16,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    42,
      92,    80,    93,     8,    15,    16,    94,   201,   112,   116,
     120,   124,     6,     7,     8,    43,   389,   200,   201,    13,
     202,    81,    98,    95,   330,   331,    99,   203,   162,   166,
     170,   174,   178,   182,   332,   186,   190,   194,   198,   206,
     209,    82,   213,   217,   221,   225,   229,   233,    83,   330,
     331,   330,   331,   237,   241,   245,   249,   253,   257,   348,
     158,     6,   261,    91,    43,    96,    18,   264,    13,    44,
     102,   267,    97,   271,   103,   274,    45,   278,    46,    51,
     104,    55,     6,     7,   105,    43,   100,   200,   134,    13,
     202,   138,   139,   140,   141,   142,   143,   303,   330,   331,
     101,   280,   330,   331,   110,   114,   118,   122,   351,   126,
     127,   135,   358,   106,   108,    51,   136,   107,   109,   213,
     217,   143,   149,    89,   160,   164,   168,   172,   176,   180,
     324,   184,   188,   192,   196,   204,   207,   329,   211,   215,
     219,   223,   227,   231,    27,    28,    29,    30,   155,   235,
     239,   243,   247,   251,   255,   133,     0,     0,   259,    31,
      32,    33,    34,   262,     0,     0,     0,   265,     0,   269,
       0,   272,   318,   276,     0,     0,     0,    19,   144,   145,
     146,   147,   148,   149,    35,    36,    37,    38,   281,     0,
      52,     0,    56,   296,   297,   298,   299,   300,   301,   130,
     131,   132,   133,   160,   164,   168,   172,   176,   180,   184,
     188,   192,   196,   204,   207,   111,   115,   119,   123,   150,
     151,   152,   153,   154,   155,     0,    52,     0,     0,   282,
     140,   141,   142,   143,     0,   161,   165,   169,   173,   177,
     181,     0,   185,   189,   193,   197,   205,   208,     0,   212,
     216,   220,   224,   228,   232,   146,   147,   148,   149,     0,
     236,   240,   244,   248,     0,   256,     0,   314,   316,   260,
      86,    87,    88,    89,   263,     0,     0,     0,   266,     0,
     270,     0,   273,     0,   277,    84,    85,    86,    87,    88,
      89,   152,   153,   154,   155,   283,     0,     0,     0,   390,
     391,   138,   139,   140,   141,   142,   143,   321,   322,   323,
     324,   284,     0,     0,   161,   165,   169,   173,   177,   181,
     185,   189,   193,   197,   205,   208,   144,   145,   146,   147,
     148,   149,   327,   328,   148,   329,   285,   150,   151,   152,
     153,   154,   155,     0,     0,     0,     0,   286,     0,    84,
      85,    86,    87,    88,    89,     0,     0,     0,   318,   287,
     138,   139,   140,   141,   142,   143,     0,     0,   316,     0,
     288,   144,   145,   146,   147,   148,   149,     0,   315,   317,
      25,   289,     0,     0,   367,   369,   371,   373,   375,   377,
     379,   381,   383,   385,   387,    58,   150,   151,   152,   153,
     154,   155,     0,     0,     0,     0,   290,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,   291,   113,   117,
     121,   125,   138,   139,   140,   141,   142,   143,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,   163,   167,
     171,   175,   179,   183,     0,   187,   191,   195,   199,     0,
     210,     0,   214,   218,   222,   226,   230,   234,     0,     0,
       0,     0,     0,   238,   242,   246,   250,   254,   258,     0,
     144,   145,   146,   147,   148,   149,     0,     0,     0,   317,
     293,   268,     0,     0,     0,   275,     0,   279,   150,   151,
     152,   153,   154,   155,     0,   368,   370,   372,   374,   376,
     378,   380,   382,   384,   386,   388,   150,   151,   152,   153,
     154,   155,     0,   113,   121,   125,   294,   163,   167,   171,
     175,   179,   183,   187,   191,   195,   199,     0,   210,   214,
     218,   222,   226,   230,   234,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,   295,   150,   151,   152,   153,
     154,   155,     0,     0,     0,     0,   304,   150,   151,   152,
     153,   154,   155,     0,     0,     0,     0,   305,   150,   151,
     152,   153,   154,   155,     0,     0,     0,     0,   306,   150,
     151,   152,   153,   154,   155,     0,     0,     0,     0,   307,
     150,   151,   152,   153,   154,   155,     0,     0,     0,     0,
     308,   150,   151,   152,   153,   154,   155,     0,     0,     0,
       0,   309,   150,   151,   152,   153,   154,   155,     0,     0,
       0,     0,   310,   150,   151,   152,   153,   154,   155,     0,
       0,     0,     0,   311,   150,   151,   152,   153,   154,   155,
       0,     0,     0,     0,   312,   150,   151,   152,   153,   154,
     155,     0,     0,     0,     0,   313,   150,   151,   152,   153,
     154,   155,     0,     0,     0,     0,   333,   138,   139,   140,
     141,   142,   143,     0,     0,     0,     0,   334,   144,   145,
     146,   147,   148,   149,     0,     0,     0,     0,   335,   138,
     139,   140,   141,   142,   143,     0,     0,     0,     0,   336,
     144,   145,   146,   147,   148,   149,     0,     0,     0,     0,
     337,   138,   139,   140,   141,   142,   143,     0,     0,     0,
       0,   338,   144,   145,   146,   147,   148,   149,     0,     0,
       0,     0,   339,   138,   139,   140,   141,   142,   143,     0,
       0,     0,     0,   340,   144,   145,   146,   147,   148,   149,
       0,     0,     0,     0,   341,   138,   139,   140,   141,   142,
     143,     0,     0,     0,     0,   342,   144,   145,   146,   147,
     148,   149,     0,     0,     0,     0,   343,   138,   139,   140,
     141,   142,   143,     0,     0,     0,     0,   344,   144,   145,
     146,   147,   148,   149,     0,     0,     0,     0,   345,   319,
     320,   321,   322,   323,   324,     0,     0,     0,     0,   346,
     325,   326,   327,   328,   148,   329,     0,     0,     0,     0,
     347,   319,   320,   321,   322,   323,   324,     0,     0,     0,
       0,   349,   325,   326,   327,   328,   148,   329,     0,     0,
       0,     0,   350,   138,   139,   140,   141,   142,   143,     0,
       0,     0,     0,   352,   144,   145,   146,   147,   148,   149,
       0,     0,     0,     0,   353,   150,   151,   152,   153,   154,
     155,     0,     0,     0,     0,   354,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,   355,   319,   320,   321,
     322,   323,   324,     0,     0,     0,     0,   356,   325,   326,
     327,   328,   148,   329,     0,     0,     0,     0,   357,   138,
     139,   140,   141,   142,   143,     0,     0,     0,     0,   359,
     144,   145,   146,   147,   148,   149,     0,     0,     0,     0,
     360,   150,   151,   152,   153,   154,   155,     0,     0,     0,
       0,   361,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,   362,   138,   139,   140,   141,   142,   143,     0,
       0,     0,     0,   363,   144,   145,   146,   147,   148,   149,
       0,     0,     0,     0,   364,   150,   151,   152,   153,   154,
     155,     0,     0,     0,     0,   365,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,   366,   138,   139,   140,
     141,   142,   143,     0,     0,     0,   156,   144,   145,   146,
     147,   148,   149,     0,     0,     0,   157,   150,   151,   152,
     153,   154,   155,     0,     0,     0,   158,    84,    85,    86,
      87,    88,    89,     0,     0,     0,   159,   128,   129,   130,
     131,   132,   133,     0,     0,     0,   156,   319,   320,   321,
     322,   323,   324,     0,     0,     0,   156,   325,   326,   327,
     328,   148,   329,     0,     0,     0,   157,    59,    60,    61,
      62,    63,    64,     0,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,    77,    78,     0,
      79,    84,    85,    86,    87,    88,    89,     0,    90,   144,
     145,   146,   147,   148,   149,   138,   139,   140,   141,   142,
     143
};

static const yytype_int16 yycheck[] =
{
       1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      19,    19,    19,    14,     0,    16,    21,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    19,
      23,    20,    19,     8,    20,    21,    23,    12,    39,    40,
      41,    42,     6,     7,     8,     9,    21,    11,    12,    13,
      14,    20,    19,    23,    13,    14,    23,    21,    59,    60,
      61,    62,    63,    64,    23,    66,    67,    68,    69,    70,
      71,    20,    73,    74,    75,    76,    77,    78,    20,    13,
      14,    13,    14,    84,    85,    86,    87,    88,    89,    23,
      22,     6,    93,    20,     9,    23,     1,    98,    13,    14,
      19,   102,    23,   104,    23,   106,    21,   108,    13,    14,
      19,    16,     6,     7,    23,     9,    23,    11,    19,    13,
      14,    13,    14,    15,    16,    17,    18,    21,    13,    14,
      23,    23,    13,    14,    39,    40,    41,    42,    23,    44,
      45,    19,    23,    19,    19,    50,    19,    23,    23,   150,
     151,    18,    18,    18,    59,    60,    61,    62,    63,    64,
      18,    66,    67,    68,    69,    70,    71,    18,    73,    74,
      75,    76,    77,    78,     9,    10,    11,    12,    18,    84,
      85,    86,    87,    88,    89,    18,    -1,    -1,    93,     9,
      10,    11,    12,    98,    -1,    -1,    -1,   102,    -1,   104,
      -1,   106,   203,   108,    -1,    -1,    -1,     1,    13,    14,
      15,    16,    17,    18,     9,    10,    11,    12,    23,    -1,
      14,    -1,    16,   128,   129,   130,   131,   132,   133,    15,
      16,    17,    18,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    39,    40,    41,    42,    13,
      14,    15,    16,    17,    18,    -1,    50,    -1,    -1,    23,
      15,    16,    17,    18,    -1,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    71,    -1,    73,
      74,    75,    76,    77,    78,    15,    16,    17,    18,    -1,
      84,    85,    86,    87,    -1,    89,    -1,   202,   203,    93,
      15,    16,    17,    18,    98,    -1,    -1,    -1,   102,    -1,
     104,    -1,   106,    -1,   108,    13,    14,    15,    16,    17,
      18,    15,    16,    17,    18,    23,    -1,    -1,    -1,   330,
     331,    13,    14,    15,    16,    17,    18,    15,    16,    17,
      18,    23,    -1,    -1,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    13,    14,    15,    16,
      17,    18,    15,    16,    17,    18,    23,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    -1,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,   389,    23,
      13,    14,    15,    16,    17,    18,    -1,    -1,   303,    -1,
      23,    13,    14,    15,    16,    17,    18,    -1,   202,   203,
       1,    23,    -1,    -1,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    16,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    39,    40,
      41,    42,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    -1,
      71,    -1,    73,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    -1,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,   303,
      23,   102,    -1,    -1,    -1,   106,    -1,   108,    13,    14,
      15,    16,    17,    18,    -1,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,    13,    14,    15,    16,
      17,    18,    -1,   134,   135,   136,    23,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,   149,   150,
     151,   152,   153,   154,   155,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    23,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    23,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    23,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    23,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,    13,    14,    15,
      16,    17,    18,    -1,    20,    13,    14,    15,    16,    17,
      18,    -1,    20,    13,    14,    15,    16,    17,    18,    -1,
      20,    13,    14,    15,    16,    17,    18,    -1,    20,    13,
      14,    15,    16,    17,    18,    13,    14,    15,    16,    17,
      18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    20,    21,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     9,    10,    11,
      12,     9,    10,    11,    12,     9,    10,    11,    12,    19,
      19,    19,    19,     9,    14,    21,    27,     9,    11,    12,
      14,    27,    28,    29,    34,    27,    28,    29,    34,    13,
      14,    15,    16,    17,    18,    20,    13,    14,    15,    16,
      17,    18,    20,    13,    14,    15,    16,    17,    18,    20,
      20,    20,    20,    20,    13,    14,    15,    16,    17,    18,
      20,    20,    23,    19,    23,    23,    23,    23,    19,    23,
      23,    23,    19,    23,    19,    23,    19,    23,    19,    23,
      27,    28,    29,    34,    27,    28,    29,    34,    27,    28,
      29,    34,    27,    28,    29,    34,    27,    27,    13,    14,
      15,    16,    17,    18,    19,    19,    19,    29,    13,    14,
      15,    16,    17,    18,    13,    14,    15,    16,    17,    18,
      13,    14,    15,    16,    17,    18,    22,    22,    22,    22,
      27,    28,    29,    34,    27,    28,    29,    34,    27,    28,
      29,    34,    27,    28,    29,    34,    27,    28,    29,    34,
      27,    28,    29,    34,    27,    28,    29,    34,    27,    28,
      29,    34,    27,    28,    29,    34,    27,    28,    29,    34,
      11,    12,    14,    21,    27,    28,    29,    27,    28,    29,
      34,    27,    28,    29,    34,    27,    28,    29,    34,    27,
      28,    29,    34,    27,    28,    29,    34,    27,    28,    29,
      34,    27,    28,    29,    34,    27,    28,    29,    34,    27,
      28,    29,    34,    27,    28,    29,    34,    27,    28,    29,
      34,    27,    28,    29,    34,    27,    28,    29,    34,    27,
      28,    29,    27,    28,    29,    27,    28,    29,    34,    27,
      28,    29,    27,    28,    29,    34,    27,    28,    29,    34,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    27,    27,    27,    27,
      27,    27,    27,    21,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    27,    28,    27,    28,    29,    13,
      14,    15,    16,    17,    18,    13,    14,    15,    16,    18,
      13,    14,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    27,    28,    27,
      28,    27,    28,    27,    28,    27,    28,    27,    28,    27,
      28,    27,    28,    27,    28,    27,    28,    27,    28,    21,
      29,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    25,    25,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    29,    29,    29,
      29,    29,    30,    30,    30,    30,    30,    30,    31,    31,
      31,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     3,     3,
       3,     1,     5,     5,     5,     3,     3,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     5,     5,
       5,     5,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     2,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     4,     4,     4,     4,     4,
       4,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5
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
        case 5:
#line 68 "PracticaFinal.y" /* yacc.c:1646  */
    { printf ("\t\tResultado: %d\n", (yyvsp[-1].Int)); }
#line 1641 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 69 "PracticaFinal.y" /* yacc.c:1646  */
    { printf ("\t\tResultado: %f\n", (yyvsp[-1].Double)); }
#line 1647 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 70 "PracticaFinal.y" /* yacc.c:1646  */
    { printf ("\t\tResultado: %s\n", (yyvsp[-1].String)); }
#line 1653 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 71 "PracticaFinal.y" /* yacc.c:1646  */
    { printf ("\t\t%s \n",(yyvsp[-1].String)); }
#line 1659 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 72 "PracticaFinal.y" /* yacc.c:1646  */
    { printf ("\t\tAsignacion \n"); }
#line 1665 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 73 "PracticaFinal.y" /* yacc.c:1646  */
    { printf ("\t\tError: Asignacion de tipos \n"); }
#line 1671 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 74 "PracticaFinal.y" /* yacc.c:1646  */
    { printf ("\t\tError: Tipos incompatibles \n"); }
#line 1677 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 75 "PracticaFinal.y" /* yacc.c:1646  */
    { printf ("\t\tError: Variable no definida\n"); }
#line 1683 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 76 "PracticaFinal.y" /* yacc.c:1646  */
    { printf ("\t\tError: Redifinicion no permitida\n"); }
#line 1689 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 79 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Int) = (yyvsp[0].Int); }
#line 1695 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 80 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Int) = (yyvsp[-2].Int) + (yyvsp[0].Int); }
#line 1701 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 81 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Int) = (yyvsp[-2].Int) - (yyvsp[0].Int); }
#line 1707 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 82 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Int) = (yyvsp[-2].Int) * (yyvsp[0].Int); }
#line 1713 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 83 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Int) = (yyvsp[-2].Int) % (yyvsp[0].Int); }
#line 1719 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 84 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Int) = (yyvsp[-2].Int) / (yyvsp[0].Int); }
#line 1725 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 85 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Int) = pow((yyvsp[-2].Int),(yyvsp[0].Int)); }
#line 1731 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 86 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Int) = (yyvsp[-1].Int); }
#line 1737 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 87 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Int) = -(yyvsp[0].Int);}
#line 1743 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 88 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Int) = (yyvsp[0].Int);}
#line 1749 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 89 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Int) =  atoi(search(tablaSim, (yyvsp[0].String))->valor); }
#line 1755 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 93 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[0].Double); }
#line 1761 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 94 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Double) + (yyvsp[0].Double); }
#line 1767 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 95 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Double) - (yyvsp[0].Double); }
#line 1773 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 96 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Double) * (yyvsp[0].Double); }
#line 1779 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 97 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Double) / (yyvsp[0].Double); }
#line 1785 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 98 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = fmodf((yyvsp[-2].Double),(yyvsp[0].Double)); }
#line 1791 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 99 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = pow((yyvsp[-2].Double), (yyvsp[0].Double)); }
#line 1797 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 100 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = pow((yyvsp[-2].Int), (yyvsp[0].Double)); }
#line 1803 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 101 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = fmodf((yyvsp[-2].Int),(yyvsp[0].Double)); }
#line 1809 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 102 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Int) + (yyvsp[0].Double); }
#line 1815 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 103 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Int) - (yyvsp[0].Double); }
#line 1821 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 104 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Int) * (yyvsp[0].Double); }
#line 1827 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 105 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Int) / (yyvsp[0].Double); }
#line 1833 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 106 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Double) + (yyvsp[0].Int); }
#line 1839 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 107 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Double) - (yyvsp[0].Int); }
#line 1845 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 108 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Double) * (yyvsp[0].Int); }
#line 1851 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 109 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-2].Double) / (yyvsp[0].Int); }
#line 1857 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 110 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = fmodf((yyvsp[-2].Double),(yyvsp[0].Int)); }
#line 1863 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 111 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = pow((yyvsp[-2].Double), (yyvsp[0].Int)); }
#line 1869 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 112 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = (yyvsp[-1].Double); }
#line 1875 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 113 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) = -(yyvsp[0].Double);}
#line 1881 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 114 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.Double) =  atof(search(tablaSim, (yyvsp[0].String))->valor); }
#line 1887 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 118 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.String) = (yyvsp[0].String);             }
#line 1893 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 119 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.String) = concat((yyvsp[-2].String), (yyvsp[0].String)); }
#line 1899 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 120 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.String) = remstr((yyvsp[-2].String), (yyvsp[0].String)); }
#line 1905 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 121 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.String) = (yyvsp[-1].String);             }
#line 1911 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 122 "PracticaFinal.y" /* yacc.c:1646  */
    { (yyval.String) = search(tablaSim,  (yyvsp[0].String))->valor; }
#line 1917 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 125 "PracticaFinal.y" /* yacc.c:1646  */
    {    
                                                            sprintf(ans,  "%d", (yyvsp[-1].Int)); 
                                                            insert(tablaSim, "Int", (yyvsp[-3].String), ans);
                                                            sprintf(ans,"Tipo de declaracion: tipo entero / nombre de variable / = / expresionInt / ;\n");
                                                            (yyval.String) = ans;
                                                       }
#line 1928 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 131 "PracticaFinal.y" /* yacc.c:1646  */
    {    
                                                            insert(tablaSim, "string",  (yyvsp[-3].String),   (yyvsp[-1].String)); 
                                                            sprintf(ans,"Tipo de declaracion: tipo string / nombre de variable / = / expresionStr / ;\n");
                                                            (yyval.String) = ans;
                                                       }
#line 1938 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 136 "PracticaFinal.y" /* yacc.c:1646  */
    {    
                                                            sprintf(ans,  "%f", (yyvsp[-1].Double)); 
                                                            insert(tablaSim, "double", (yyvsp[-3].String), ans);
                                                            sprintf(ans,"Tipo de declaracion: tipo double / nombre de variable / = / expresionDouble / ;\n");
                                                            (yyval.String) = ans;
                                                       }
#line 1949 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 142 "PracticaFinal.y" /* yacc.c:1646  */
    {    
                                                            insert(tablaSim, "Int", (yyvsp[-1].String),  "0"); 
                                                            sprintf(ans,"Tipo de declaracion: tipo entero / nombre de variable / ; \n");
                                                            (yyval.String) = ans;   
                                                       }
#line 1959 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 147 "PracticaFinal.y" /* yacc.c:1646  */
    {   
                                                            insert(tablaSim, "double", (yyvsp[-1].String),  "0");
                                                            sprintf(ans,"Tipo de declaracion: tipo double / nombre de variable / ; \n");
                                                            (yyval.String) = ans;   
                                                       }
#line 1969 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 152 "PracticaFinal.y" /* yacc.c:1646  */
    {    
                                                            insert(tablaSim, "string", (yyvsp[-1].String),  "");
                                                            sprintf(ans,"Tipo de declaracion: tipo string / nombre de variable / ;\n");
                                                            (yyval.String) = ans;
                                                       }
#line 1979 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 159 "PracticaFinal.y" /* yacc.c:1646  */
    { update(tablaSim, (yyvsp[-3].String),  (yyvsp[-1].String));                        }
#line 1985 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 160 "PracticaFinal.y" /* yacc.c:1646  */
    { sprintf(ans, "%d", (yyvsp[-1].Int));update(tablaSim, (yyvsp[-3].String), ans); }
#line 1991 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 161 "PracticaFinal.y" /* yacc.c:1646  */
    { sprintf(ans, "%f", (yyvsp[-1].Double));update(tablaSim, (yyvsp[-3].String), ans); }
#line 1997 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 164 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2003 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 165 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2009 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 166 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2015 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 167 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2021 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 168 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2027 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 169 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2033 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 170 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2039 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 171 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2045 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 172 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2051 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 173 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2057 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 174 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2063 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 175 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2069 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 178 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2075 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 179 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2081 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 180 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2087 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 181 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2093 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 182 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2099 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 183 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2105 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 184 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2111 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 185 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2117 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 186 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2123 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 187 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2129 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 188 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2135 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 189 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2141 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 190 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2147 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 191 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2153 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 192 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2159 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 193 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2165 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 194 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2171 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 195 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2177 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 196 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2183 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 197 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2189 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 198 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2195 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 199 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2201 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 200 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2207 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 201 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2213 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 202 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2219 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 203 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2225 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 204 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2231 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 205 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2237 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 206 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2243 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 209 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2249 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 210 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2255 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 211 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2261 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 212 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2267 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 213 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2273 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 214 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2279 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 215 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2285 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 217 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2291 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 218 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2297 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 219 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2303 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 220 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2309 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 221 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2315 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 222 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2321 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 224 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2327 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 225 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2333 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 226 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2339 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 227 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2345 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 228 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2351 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 230 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2357 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 231 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2363 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 232 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2369 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 233 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2375 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 234 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2381 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 236 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2387 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 237 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2393 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 238 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2399 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 239 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2405 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 240 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2411 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 241 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2417 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 243 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2423 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 244 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2429 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 245 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2435 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 246 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2441 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 247 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2447 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 248 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2453 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 250 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2459 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 251 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2465 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 252 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2471 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 253 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2477 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 254 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2483 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 255 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2489 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 257 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2495 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 258 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2501 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 260 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2507 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 261 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2513 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 262 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2519 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 264 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2525 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 265 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2531 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 266 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2537 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 267 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2543 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 270 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2549 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 271 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2555 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 272 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2561 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 274 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2567 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 275 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2573 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 276 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2579 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 277 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2585 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 278 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2591 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 279 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2597 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 281 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2603 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 282 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2609 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 283 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2615 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 285 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2621 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 286 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2627 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 287 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2633 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 288 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2639 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 289 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2645 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 290 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2651 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 292 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2657 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 293 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2663 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 294 "PracticaFinal.y" /* yacc.c:1646  */
    {  }
#line 2669 "PracticaFinal.tab.c" /* yacc.c:1646  */
    break;


#line 2673 "PracticaFinal.tab.c" /* yacc.c:1646  */
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
#line 297 "PracticaFinal.y" /* yacc.c:1906  */


int yyerror(char * s) {
  printf("YYERROR: %s \n", s);
}

int main() {
  tablaSim = (lista*) malloc(sizeof(lista));
  yyparse();
}

