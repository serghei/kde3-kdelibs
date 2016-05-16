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
#line 1 "yacc.yy" /* yacc.c:339  */

/*****************************************************************
Copyright (c) 1999 Torben Weis <weis@kde.org>
Copyright (c) 2000 Matthias Ettrich <ettrich@kde.org>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

******************************************************************/

#include <config.h>

// Workaround for a bison issue:
// bison.simple concludes from _GNU_SOURCE that stpcpy is available,
// while GNU string.h only exposes it if __USE_GNU is set.
#ifdef _GNU_SOURCE
#define __USE_GNU 1
#endif

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <qptrlist.h>
#include <qstring.h>


// remember allocated QStrings and delete they at exit,
// in order to avoid memory leaks
static class QStringStack : public QPtrList<QString> {
public:
    QStringStack() { setAutoDelete(true); }
    QString *push(QString *qstring) { append(qstring); return qstring; }
} qStringStack;
#define newQString(a) qStringStack.push(new QString(a))


#define AMP_ENTITY "&amp;"
#define YYERROR_VERBOSE

extern int yylex();

// extern QString idl_lexFile;
extern int idl_line_no;
extern int function_mode;

static int dcop_area = 0;
static int dcop_signal_area = 0;

static QString in_namespace( "" );

void dcopidlInitFlex( const char *_code );

void yyerror( const char *s )
{
	qDebug( "In line %i : %s", idl_line_no, s );
        exit(1);
	//   theParser->parse_error( idl_lexFile, s, idl_line_no );
}


#line 142 "yacc.cc" /* yacc.c:339  */

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
   by #include "yacc.hh".  */
#ifndef YY_YY_YACC_HH_INCLUDED
# define YY_YY_YACC_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_UNIMPORTANT = 258,
    T_CHARACTER_LITERAL = 259,
    T_DOUBLE_LITERAL = 260,
    T_IDENTIFIER = 261,
    T_INTEGER_LITERAL = 262,
    T_STRING_LITERAL = 263,
    T_INCLUDE = 264,
    T_CLASS = 265,
    T_STRUCT = 266,
    T_LEFT_CURLY_BRACKET = 267,
    T_LEFT_PARANTHESIS = 268,
    T_RIGHT_CURLY_BRACKET = 269,
    T_RIGHT_PARANTHESIS = 270,
    T_COLON = 271,
    T_SEMICOLON = 272,
    T_PUBLIC = 273,
    T_PROTECTED = 274,
    T_TRIPE_DOT = 275,
    T_PRIVATE = 276,
    T_VIRTUAL = 277,
    T_CONST = 278,
    T_INLINE = 279,
    T_FRIEND = 280,
    T_RETURN = 281,
    T_SIGNAL = 282,
    T_SLOT = 283,
    T_TYPEDEF = 284,
    T_PLUS = 285,
    T_MINUS = 286,
    T_COMMA = 287,
    T_ASTERISK = 288,
    T_TILDE = 289,
    T_LESS = 290,
    T_GREATER = 291,
    T_AMPERSAND = 292,
    T_EXTERN = 293,
    T_EXTERN_C = 294,
    T_ACCESS = 295,
    T_ENUM = 296,
    T_NAMESPACE = 297,
    T_USING = 298,
    T_UNKNOWN = 299,
    T_TRIPLE_DOT = 300,
    T_TRUE = 301,
    T_FALSE = 302,
    T_STATIC = 303,
    T_MUTABLE = 304,
    T_EQUAL = 305,
    T_SCOPE = 306,
    T_NULL = 307,
    T_INT = 308,
    T_ARRAY_OPEN = 309,
    T_ARRAY_CLOSE = 310,
    T_CHAR = 311,
    T_DCOP = 312,
    T_DCOP_AREA = 313,
    T_DCOP_SIGNAL_AREA = 314,
    T_SIGNED = 315,
    T_UNSIGNED = 316,
    T_LONG = 317,
    T_SHORT = 318,
    T_FUNOPERATOR = 319,
    T_MISCOPERATOR = 320,
    T_SHIFT = 321
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 79 "yacc.yy" /* yacc.c:355  */

  long   _int;
  QString        *_str;
  unsigned short          _char;
  double _float;

#line 256 "yacc.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 273 "yacc.cc" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   559

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  185
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  374

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   176,   176,   179,   183,   187,   191,   196,   197,   201,
     210,   219,   222,   225,   229,   228,   240,   243,   246,   249,
     252,   255,   258,   261,   264,   267,   273,   274,   277,   277,
     279,   279,   279,   281,   281,   281,   284,   289,   297,   305,
     317,   320,   328,   334,   343,   347,   354,   358,   366,   370,
     378,   380,   384,   388,   392,   396,   400,   404,   408,   412,
     416,   420,   424,   428,   432,   436,   440,   444,   448,   455,
     456,   457,   458,   462,   463,   467,   468,   472,   473,   474,
     475,   476,   480,   481,   482,   486,   496,   505,   508,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   538,
     539,   544,   547,   548,   556,   557,   558,   559,   560,   566,
     577,   581,   589,   594,   603,   608,   615,   620,   625,   632,
     637,   642,   650,   654,   661,   670,   678,   688,   690,   693,
     700,   703,   706,   709,   712,   718,   719,   723,   723,   723,
     723,   723,   727,   749,   760,   761,   762,   767,   772,   773,
     777,   781,   785,   789,   795,   801,   807,   820,   827,   828,
     829,   833,   834,   838,   842,   843,   846,   847,   848,   851,
     855,   856,   857,   858,   859,   860
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_UNIMPORTANT", "T_CHARACTER_LITERAL",
  "T_DOUBLE_LITERAL", "T_IDENTIFIER", "T_INTEGER_LITERAL",
  "T_STRING_LITERAL", "T_INCLUDE", "T_CLASS", "T_STRUCT",
  "T_LEFT_CURLY_BRACKET", "T_LEFT_PARANTHESIS", "T_RIGHT_CURLY_BRACKET",
  "T_RIGHT_PARANTHESIS", "T_COLON", "T_SEMICOLON", "T_PUBLIC",
  "T_PROTECTED", "T_TRIPE_DOT", "T_PRIVATE", "T_VIRTUAL", "T_CONST",
  "T_INLINE", "T_FRIEND", "T_RETURN", "T_SIGNAL", "T_SLOT", "T_TYPEDEF",
  "T_PLUS", "T_MINUS", "T_COMMA", "T_ASTERISK", "T_TILDE", "T_LESS",
  "T_GREATER", "T_AMPERSAND", "T_EXTERN", "T_EXTERN_C", "T_ACCESS",
  "T_ENUM", "T_NAMESPACE", "T_USING", "T_UNKNOWN", "T_TRIPLE_DOT",
  "T_TRUE", "T_FALSE", "T_STATIC", "T_MUTABLE", "T_EQUAL", "T_SCOPE",
  "T_NULL", "T_INT", "T_ARRAY_OPEN", "T_ARRAY_CLOSE", "T_CHAR", "T_DCOP",
  "T_DCOP_AREA", "T_DCOP_SIGNAL_AREA", "T_SIGNED", "T_UNSIGNED", "T_LONG",
  "T_SHORT", "T_FUNOPERATOR", "T_MISCOPERATOR", "T_SHIFT", "$accept",
  "main", "includes", "dcoptag", "declaration", "$@1", "member_list",
  "bool_value", "nodcop_area", "sigslot", "nodcop_area_begin",
  "dcop_area_begin", "dcop_signal_area_begin", "Identifier",
  "super_class_name", "super_class", "super_classes", "class_header",
  "opt_semicolon", "body", "enum", "enum_list", "enum_item", "number",
  "int_expression", "typedef", "const_qualifier", "int_type", "asterisks",
  "params", "type_name", "templ_type_list", "templ_type", "type",
  "type_list", "param", "default", "value", "virtual_qualifier",
  "operator", "function_header", "values", "init_item", "init_list",
  "function", "function_begin", "function_body", "function_lines",
  "function_line", "Identifier_list_rest", "Identifier_list_entry",
  "Identifier_list", "member", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321
};
# endif

#define YYPACT_NINF -191

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-191)))

#define YYTABLE_NINF -177

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,    78,    99,   342,    80,  -191,    67,  -191,   115,   159,
     205,    81,   386,   463,   153,    44,   190,    32,   205,   205,
    -191,  -191,   181,   287,   154,   161,    47,    66,  -191,  -191,
     138,    19,   185,   143,  -191,  -191,   207,   159,    21,   183,
     219,   159,   159,   194,    16,    31,   152,   205,  -191,    91,
     159,  -191,   228,   236,   233,   202,   264,    18,   143,   272,
    -191,  -191,   231,   232,  -191,  -191,   246,   248,  -191,  -191,
    -191,   445,    81,   249,   256,  -191,  -191,    85,   182,    42,
     296,   273,   290,   159,  -191,  -191,   291,  -191,  -191,  -191,
     196,  -191,   146,  -191,   262,  -191,   269,  -191,  -191,   300,
     252,  -191,  -191,  -191,   404,   311,   307,   236,   276,   319,
     302,  -191,   329,   320,    60,  -191,   289,  -191,  -191,  -191,
    -191,  -191,   114,    39,  -191,   256,   305,   310,  -191,  -191,
     507,   101,  -191,  -191,  -191,  -191,  -191,   332,   445,   339,
    -191,    62,  -191,  -191,   341,  -191,   343,   291,   262,  -191,
     321,  -191,    34,  -191,   337,  -191,   269,   159,   159,  -191,
    -191,  -191,  -191,   386,   474,  -191,  -191,   159,   352,   344,
     346,   211,   347,   269,   269,   269,   350,   269,   269,   269,
     269,   143,   205,   354,    87,   404,   404,  -191,   356,   101,
     156,   236,    80,   359,  -191,   120,   101,   360,   364,   247,
     445,   289,  -191,  -191,   331,    81,  -191,  -191,  -191,  -191,
     379,  -191,  -191,  -191,  -191,   374,    40,  -191,  -191,  -191,
     333,   445,   116,   372,   349,  -191,   378,   377,  -191,   269,
     205,  -191,   146,   159,   383,   265,   299,   269,   159,    27,
     384,   371,   361,  -191,  -191,   391,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,   407,   159,   400,  -191,
     403,   176,  -191,   401,  -191,  -191,   405,  -191,   205,  -191,
     365,  -191,  -191,   415,  -191,  -191,  -191,   159,  -191,  -191,
     445,   101,   101,   406,   132,   399,  -191,   143,  -191,   408,
     392,   390,  -191,  -191,  -191,   269,   269,   269,   269,  -191,
     411,   269,   269,   205,   425,  -191,   144,   418,   159,   419,
    -191,  -191,   420,   417,   421,   427,   409,   143,  -191,   148,
    -191,  -191,  -191,   399,  -191,  -191,  -191,  -191,   205,  -191,
    -191,   426,  -191,   428,   269,  -191,  -191,   414,   437,  -191,
     441,  -191,  -191,  -191,   507,  -191,   507,   415,  -191,  -191,
    -191,  -191,   269,   269,  -191,    25,   269,  -191,  -191,   412,
     444,  -191,  -191,  -191,   455,   446,  -191,   507,  -191,   159,
    -191,  -191,   453,  -191
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,   145,     6,     1,    40,     4,     0,     0,
     146,     0,   145,     0,     0,     0,     0,     0,     0,     0,
     101,   106,    89,    91,   102,   104,     6,   115,    25,   114,
     130,     0,     0,     0,    23,    24,     0,     0,    40,   117,
     116,     0,     0,   115,     0,     0,   126,     0,    22,     0,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
      90,   107,    95,    93,    92,   108,    99,    97,   103,   105,
       2,   111,     0,   127,   110,   129,   131,    40,     0,     0,
       0,   175,     0,     0,   167,   168,   172,   160,     5,    41,
       0,    49,   145,    11,     8,    12,    35,   117,   116,     0,
       0,   162,   125,   124,    27,   116,     0,     0,    76,     0,
      74,    14,     0,     0,    40,   166,   137,    96,    94,   100,
      98,   136,     0,   137,   112,   123,     0,   121,   128,   109,
       0,     0,   150,   149,   151,   147,   148,     0,   111,     0,
     178,     0,   179,   180,     0,   173,     0,   172,     8,   146,
      42,    45,     0,    48,     0,     7,    35,     0,     0,    52,
      32,    31,    30,   145,     0,    33,    34,     0,     0,     0,
       0,    35,     0,    35,    35,    35,     0,    35,    35,    35,
      35,     0,     0,     0,     0,    27,    27,    19,     0,     0,
       0,     0,     6,     0,    16,     0,     0,     0,     0,     0,
       0,   137,   135,   122,   118,     0,    77,   142,    78,   140,
       0,    28,    29,    80,   143,    81,    82,   141,   177,    81,
       0,   111,     0,     0,   176,   174,     0,   169,   171,    35,
       0,    46,   145,     0,     0,   117,   116,    35,     0,   115,
       0,     0,     0,    38,    39,     0,    37,    59,    58,    56,
      13,    57,    53,    55,    60,   161,     0,     0,     0,    26,
       0,     0,    75,     0,    72,    73,     0,    17,     0,   138,
       0,   182,   183,     0,   163,   113,   134,     0,   120,    79,
     111,     0,     0,     0,     0,    87,   181,     0,   170,     0,
     133,     0,    47,    44,     9,    35,    35,    35,    35,    54,
     117,    35,    35,     0,     0,    36,   137,     0,     0,     0,
      70,    71,    50,     0,     0,     0,   158,     0,   119,     0,
      83,    84,   184,    87,    88,   152,   165,    10,     0,    43,
      64,     0,    66,     0,    35,    62,    63,     0,     0,    20,
       0,    69,    51,    15,     0,   185,   156,     0,   164,   144,
     153,   132,    35,    35,    61,     0,    35,    21,   139,   154,
       0,   159,    65,    67,     0,     0,    68,   156,   157,     0,
      85,   155,     0,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -191,     9,  -191,   314,  -191,  -191,    -2,  -191,  -191,   301,
    -191,  -191,  -191,    -8,   238,  -191,   243,   -33,  -191,    77,
     473,   -91,  -191,   -72,  -111,  -191,   155,  -191,    -9,  -123,
       1,   274,  -191,    41,  -190,   277,   -97,  -124,   -78,  -191,
      22,   121,  -191,   134,     6,  -191,   -41,   335,  -191,  -191,
    -191,   348,     5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   156,    26,   192,   183,   214,   171,   172,
     173,   174,   175,    27,   151,   152,   153,    94,   343,   176,
     177,   109,   110,   216,   217,   178,   325,    29,    80,   122,
      30,   126,   127,    31,   291,   124,   197,   359,    32,   137,
      33,   360,   316,   317,   179,    86,    87,   146,   147,   142,
      81,    82,   180
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    40,    43,    43,   101,    43,   218,    96,    35,    34,
      43,    43,    46,    36,   154,   222,   188,   115,    48,   198,
     220,    76,     6,    79,   114,    77,   202,     6,    -3,    89,
      90,     6,    45,    97,    98,    70,    99,   103,    55,    43,
      58,   105,   106,    84,   301,     6,   231,    -3,    85,    99,
      52,    44,    74,    44,    50,   138,    53,   148,   139,    57,
      59,    -3,    72,    43,    43,   129,   232,     1,   224,    58,
     281,   269,    37,   125,    56,   144,   364,  -137,   262,    71,
      78,   100,    78,    78,   150,   270,     1,     6,    44,   195,
       4,    41,    42,    77,    -3,    74,    43,     6,   284,     5,
     265,    72,  -176,   104,   276,   206,   282,     6,   208,   185,
     195,    37,   123,   337,   196,   201,   203,  -176,    37,     1,
      74,    38,   215,   219,   206,   207,     6,   208,   209,   199,
      43,   285,   210,   268,    20,   130,    37,    21,   351,   131,
     255,    22,    23,    24,    25,   184,   200,   323,   200,   235,
     236,   210,     6,   213,   154,    84,   239,   319,   274,   241,
      85,    73,   263,   349,   200,     6,   211,   212,   149,   237,
      51,    74,   213,   264,    43,    75,   258,    43,    43,   123,
     200,   219,   309,   259,   260,    74,   240,   215,   219,   102,
     185,   185,    43,   310,   195,    91,    54,    43,   196,    92,
      93,   266,   296,   298,    44,    44,   125,    68,    91,   320,
     321,     6,    92,    43,    69,    41,    42,   132,   133,    83,
     358,    88,    43,   256,   150,   150,   184,   184,    11,    72,
     300,    91,   134,   234,    60,    92,    95,    61,   165,   166,
     107,   123,   108,    62,    63,   111,   326,   135,   136,   307,
     247,   248,   249,   112,   251,   252,   253,   254,    20,    84,
      43,    21,   123,   273,    85,    22,    23,    24,    25,   318,
     113,   290,    43,   219,   219,     6,   348,    91,   116,   157,
     158,    92,   295,   159,   117,   118,   128,   160,   161,    74,
     162,    10,    11,   163,   164,    43,   165,   166,   167,   119,
     340,   120,   140,  -145,   181,   141,   289,   143,   145,   313,
      15,    91,   168,   138,   299,    92,   297,    18,    19,   155,
      43,   123,    20,   186,   187,    21,   189,   169,   170,    22,
      23,    24,    25,   190,   191,   193,   215,   194,   215,   195,
      64,   204,   205,    65,   290,   221,   223,   365,     6,    66,
      67,     7,     8,     9,   226,   233,   230,   227,   242,   215,
     243,   372,   244,   246,    10,    11,    12,   250,   257,   290,
     261,    13,   330,   331,   332,   333,   267,   271,   335,   336,
      14,   272,   277,    15,    16,    17,   279,   280,   283,   286,
      18,    19,     6,   287,   288,    20,    41,    42,    21,   130,
     294,   302,    22,    23,    24,    25,   303,   305,    10,    11,
       6,   354,   304,   306,    41,    42,   139,   308,   311,   312,
     314,   315,   324,   322,   328,   327,   329,    11,   334,   362,
     363,   338,   344,   366,    47,   339,   341,   342,   345,    20,
     346,   347,    21,   352,   367,   353,    22,    23,    24,    25,
     355,     6,   182,    19,   356,    41,    42,    20,   357,   368,
      21,   369,   229,   370,    22,    23,    24,    25,    11,     6,
     373,   293,   245,    41,    49,   292,    28,   275,   350,   278,
       6,   361,   228,     0,   238,    42,    11,     0,   371,   225,
     121,     0,     0,     0,     0,     0,     0,    11,    20,     0,
       0,    21,     0,     0,     0,    22,    23,    24,    25,     0,
       0,   206,   207,     6,   208,   209,    20,     0,     0,    21,
       0,     0,     0,    22,    23,    24,    25,    20,     0,     0,
      21,     0,     0,     0,    22,    23,    24,    25,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   211,   212,     0,     0,     0,     0,   213
};

static const yytype_int16 yycheck[] =
{
       8,     9,    10,    11,    45,    13,   130,    40,     3,     3,
      18,    19,    11,     4,    92,   138,   107,    58,    12,   116,
     131,    30,     6,    31,     6,     6,   123,     6,     0,    37,
      38,     6,    10,    41,    42,    26,    44,    46,     6,    47,
      18,    49,    50,    12,    17,     6,    12,     0,    17,    57,
       6,    10,    33,    12,    13,    13,    12,    90,    16,    18,
      19,    14,    35,    71,    72,    74,    32,    39,     6,    47,
      30,   195,    51,    72,    42,    83,    51,    17,   189,    13,
      64,    50,    64,    64,    92,   196,    39,     6,    47,    50,
      12,    10,    11,     6,    14,    33,   104,     6,   221,     0,
     191,    35,    17,    12,   201,     4,    66,     6,     7,   104,
      50,    51,    71,   303,    54,   123,   125,    32,    51,    39,
      33,     6,   130,   131,     4,     5,     6,     7,     8,    15,
     138,    15,    31,    13,    53,    50,    51,    56,   328,    54,
     181,    60,    61,    62,    63,   104,    32,    15,    32,   157,
     158,    31,     6,    52,   232,    12,   164,   280,   199,   167,
      17,    23,     6,    15,    32,     6,    46,    47,    22,   163,
      17,    33,    52,    17,   182,    37,   184,   185,   186,   138,
      32,   189,     6,   185,   186,    33,   164,   195,   196,    37,
     185,   186,   200,    17,    50,    12,     6,   205,    54,    16,
      17,   192,   235,   236,   163,   164,   205,    53,    12,   281,
     282,     6,    16,   221,    53,    10,    11,    35,    36,    34,
     344,    14,   230,   182,   232,   233,   185,   186,    23,    35,
     238,    12,    50,   156,    53,    16,    17,    56,    27,    28,
      12,   200,     6,    62,    63,    12,   287,    65,    66,   257,
     173,   174,   175,    51,   177,   178,   179,   180,    53,    12,
     268,    56,   221,    16,    17,    60,    61,    62,    63,   277,
       6,   230,   280,   281,   282,     6,   317,    12,     6,    10,
      11,    16,    17,    14,    53,    53,    37,    18,    19,    33,
      21,    22,    23,    24,    25,   303,    27,    28,    29,    53,
     308,    53,     6,    34,    52,    32,   229,    17,    17,   268,
      41,    12,    43,    13,   237,    16,    17,    48,    49,    57,
     328,   280,    53,    12,    17,    56,    50,    58,    59,    60,
      61,    62,    63,    14,    32,     6,   344,    17,   346,    50,
      53,    36,    32,    56,   303,    13,     7,   355,     6,    62,
      63,     9,    10,    11,    13,    18,    35,    14,     6,   367,
      16,   369,    16,    16,    22,    23,    24,    17,    14,   328,
      14,    29,   295,   296,   297,   298,    17,    17,   301,   302,
      38,    17,    51,    41,    42,    43,     7,    13,    55,    17,
      48,    49,     6,    15,    17,    53,    10,    11,    56,    50,
      17,    17,    60,    61,    62,    63,    35,    16,    22,    23,
       6,   334,    51,     6,    10,    11,    16,    14,    17,    14,
      55,     6,    23,    17,    32,    17,    36,    23,    17,   352,
     353,     6,    15,   356,    48,    17,    17,    17,    17,    53,
      13,    32,    56,    17,    32,    17,    60,    61,    62,    63,
      36,     6,    48,    49,    17,    10,    11,    53,    17,    15,
      56,     6,   148,    17,    60,    61,    62,    63,    23,     6,
      17,   233,   171,    10,    11,   232,     3,   200,   323,   205,
       6,   347,   147,    -1,    10,    11,    23,    -1,   367,   141,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    23,    53,    -1,
      -1,    56,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      -1,     4,     5,     6,     7,     8,    53,    -1,    -1,    56,
      -1,    -1,    -1,    60,    61,    62,    63,    53,    -1,    -1,
      56,    -1,    -1,    -1,    60,    61,    62,    63,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    68,    69,    12,     0,     6,     9,    10,    11,
      22,    23,    24,    29,    38,    41,    42,    43,    48,    49,
      53,    56,    60,    61,    62,    63,    71,    80,    87,    94,
      97,   100,   105,   107,   111,   119,    68,    51,     6,    80,
      80,    10,    11,    80,   100,   107,    97,    48,   111,    11,
     100,    17,     6,    12,     6,     6,    42,   100,   107,   100,
      53,    56,    62,    63,    53,    56,    62,    63,    53,    53,
      68,    13,    35,    23,    33,    37,    95,     6,    64,    80,
      95,   117,   118,    34,    12,    17,   112,   113,    14,    80,
      80,    12,    16,    17,    84,    17,    84,    80,    80,    80,
      50,   113,    37,    95,    12,    80,    80,    12,     6,    88,
      89,    12,    51,     6,     6,   113,     6,    53,    53,    53,
      53,    45,    96,   100,   102,    97,    98,    99,    37,    95,
      50,    54,    35,    36,    50,    65,    66,   106,    13,    16,
       6,    32,   116,    17,    80,    17,   114,   115,    84,    22,
      80,    81,    82,    83,   105,    57,    70,    10,    11,    14,
      18,    19,    21,    24,    25,    27,    28,    29,    43,    58,
      59,    75,    76,    77,    78,    79,    86,    87,    92,   111,
     119,    52,    48,    73,   100,   119,    12,    17,    88,    50,
      14,    32,    72,     6,    17,    50,    54,   103,   103,    15,
      32,    80,   103,    95,    36,    32,     4,     5,     7,     8,
      31,    46,    47,    52,    74,    80,    90,    91,   104,    80,
      91,    13,    96,     7,     6,   118,    13,    14,   114,    70,
      35,    12,    32,    18,    86,    80,    80,   111,    10,    80,
     107,    80,     6,    16,    16,    76,    16,    86,    86,    86,
      17,    86,    86,    86,    86,   113,   100,    14,    80,    73,
      73,    14,    91,     6,    17,    88,    68,    17,    13,   104,
      91,    17,    17,    16,   113,   102,   103,    51,    98,     7,
      13,    30,    66,    55,    96,    15,    17,    15,    17,    86,
     100,   101,    83,    81,    17,    17,    84,    17,    84,    86,
      80,    17,    17,    35,    51,    16,     6,    80,    14,     6,
      17,    17,    14,   100,    55,     6,   109,   110,    80,    96,
      90,    90,    17,    15,    23,    93,   113,    17,    32,    36,
      86,    86,    86,    86,    17,    86,    86,   101,     6,    17,
      80,    17,    17,    85,    15,    17,    13,    32,   113,    15,
      93,   101,    17,    17,    86,    36,    17,    17,   104,   104,
     108,   110,    86,    86,    51,    80,    86,    32,    15,     6,
      17,   108,    80,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    69,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    72,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    73,    73,    74,    74,
      75,    75,    75,    76,    76,    76,    77,    77,    78,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    87,
      87,    87,    87,    88,    88,    89,    89,    90,    90,    90,
      90,    90,    91,    91,    91,    92,    92,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    95,
      95,    96,    96,    96,    97,    97,    97,    97,    97,    97,
      98,    98,    99,    99,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   101,   102,   102,   102,   103,   103,   103,
     104,   104,   104,   104,   104,   105,   105,   106,   106,   106,
     106,   106,   107,   107,   108,   108,   108,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   112,   113,   113,
     113,   114,   114,   115,   116,   116,   117,   117,   117,   118,
     119,   119,   119,   119,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     4,     0,     1,     0,     6,
       7,     3,     3,     5,     0,     7,     4,     5,     2,     4,
       7,     8,     2,     1,     1,     1,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     2,     2,     2,
       1,     3,     1,     4,     3,     1,     2,     3,     2,     1,
       0,     1,     1,     2,     3,     2,     2,     2,     2,     2,
       2,     5,     4,     4,     4,     6,     4,     6,     6,     7,
       6,     6,     5,     3,     1,     3,     1,     1,     1,     2,
       1,     1,     1,     3,     3,     7,     9,     0,     1,     1,
       2,     1,     2,     2,     3,     2,     3,     2,     3,     2,
       3,     1,     1,     2,     1,     2,     1,     2,     2,     2,
       1,     0,     1,     3,     1,     1,     2,     2,     4,     6,
       3,     1,     2,     1,     3,     3,     2,     2,     3,     2,
       1,     2,     3,     1,     3,     2,     1,     0,     2,     5,
       1,     1,     1,     1,     4,     0,     1,     1,     1,     1,
       1,     1,     6,     7,     1,     3,     0,     4,     1,     3,
       2,     5,     3,     5,     7,     6,     3,     1,     1,     3,
       4,     2,     0,     1,     2,     0,     1,     3,     2,     2,
       3,     5,     5,     5,     6,     7
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
#line 177 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1661 "yacc.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 184 "yacc.yy" /* yacc.c:1646  */
    {
		printf("<INCLUDE>%s</INCLUDE>\n", (yyvsp[0]._str)->latin1() );
	  }
#line 1669 "yacc.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 188 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1676 "yacc.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 191 "yacc.yy" /* yacc.c:1646  */
    {
          }
#line 1683 "yacc.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 196 "yacc.yy" /* yacc.c:1646  */
    { (yyval._int) = 1; }
#line 1689 "yacc.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 197 "yacc.yy" /* yacc.c:1646  */
    { (yyval._int) = 0; }
#line 1695 "yacc.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 202 "yacc.yy" /* yacc.c:1646  */
    {
	 	if ((yyvsp[-2]._int))
			  printf("<CLASS>\n    <NAME>%s</NAME>\n%s%s</CLASS>\n", ( in_namespace + *(yyvsp[-4]._str) ).latin1(), (yyvsp[-3]._str)->latin1(), (yyvsp[-1]._str)->latin1() );
		// default C++ visibility specifier is 'private'
		dcop_area = 0;
		dcop_signal_area = 0;

	  }
#line 1708 "yacc.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 211 "yacc.yy" /* yacc.c:1646  */
    {
	 	if ((yyvsp[-2]._int))
			  printf("<CLASS>\n    <NAME>%s</NAME>\n    <LINK_SCOPE>%s</LINK_SCOPE>\n%s%s</CLASS>\n", ( in_namespace + *(yyvsp[-4]._str) ).latin1(),(yyvsp[-5]._str)->latin1(),  (yyvsp[-3]._str)->latin1(), (yyvsp[-1]._str)->latin1() );
		// default C++ visibility specifier is 'private'
		dcop_area = 0;
		dcop_signal_area = 0;

	  }
#line 1721 "yacc.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 220 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1728 "yacc.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 223 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1735 "yacc.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 226 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1742 "yacc.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 229 "yacc.yy" /* yacc.c:1646  */
    {
                      in_namespace += *(yyvsp[-1]._str); in_namespace += "::";
                  }
#line 1750 "yacc.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 233 "yacc.yy" /* yacc.c:1646  */
    {
                      int pos = in_namespace.findRev( "::", -3 );
                      if( pos >= 0 )
                          in_namespace = in_namespace.left( pos + 2 );
                      else
                          in_namespace = "";
                  }
#line 1762 "yacc.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 241 "yacc.yy" /* yacc.c:1646  */
    {
          }
#line 1769 "yacc.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 244 "yacc.yy" /* yacc.c:1646  */
    {
          }
#line 1776 "yacc.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 247 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1783 "yacc.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 250 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1790 "yacc.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 253 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1797 "yacc.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 256 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1804 "yacc.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 259 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1811 "yacc.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 262 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1818 "yacc.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 265 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1825 "yacc.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 268 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 1832 "yacc.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 285 "yacc.yy" /* yacc.c:1646  */
    {
	  dcop_area = 0;
	  dcop_signal_area = 0;
	}
#line 1841 "yacc.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 290 "yacc.yy" /* yacc.c:1646  */
    {
	  dcop_area = 0;
	  dcop_signal_area = 0;
	}
#line 1850 "yacc.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 298 "yacc.yy" /* yacc.c:1646  */
    {
	  dcop_area = 1;
	  dcop_signal_area = 0;
	}
#line 1859 "yacc.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 306 "yacc.yy" /* yacc.c:1646  */
    {
	  /*
	  A dcop signals area needs all dcop area capabilities,
	  e.g. parsing of function parameters.
	  */
	  dcop_area = 1;
	  dcop_signal_area = 1;
	}
#line 1872 "yacc.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 317 "yacc.yy" /* yacc.c:1646  */
    {
	  (yyval._str) = (yyvsp[0]._str);
	}
#line 1880 "yacc.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 320 "yacc.yy" /* yacc.c:1646  */
    {
       QString* tmp = newQString( "%1::%2" );
           *tmp = tmp->arg(*((yyvsp[-2]._str))).arg(*((yyvsp[0]._str)));
           (yyval._str) = tmp;
	}
#line 1890 "yacc.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 329 "yacc.yy" /* yacc.c:1646  */
    {
        QString* tmp = newQString( "    <SUPER>%1</SUPER>\n" );
		*tmp = tmp->arg( *((yyvsp[0]._str)) );
		(yyval._str) = tmp;
	  }
#line 1900 "yacc.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 335 "yacc.yy" /* yacc.c:1646  */
    {
        QString* tmp = newQString( "    <SUPER>%1</SUPER>\n" );
		*tmp = tmp->arg( *((yyvsp[-3]._str)) + "&lt;" + *((yyvsp[-1]._str)) + "&gt;" );
		(yyval._str) = tmp;
	  }
#line 1910 "yacc.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 344 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[0]._str);
	  }
#line 1918 "yacc.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 348 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[0]._str);
	  }
#line 1926 "yacc.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 355 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[-1]._str);
	  }
#line 1934 "yacc.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 359 "yacc.yy" /* yacc.c:1646  */
    {
		/* $$ = $1; */
        (yyval._str) = newQString( *((yyvsp[-2]._str)) + *((yyvsp[0]._str)) );
	  }
#line 1943 "yacc.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 367 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[0]._str);
	  }
#line 1951 "yacc.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 371 "yacc.yy" /* yacc.c:1646  */
    {
        (yyval._str) = newQString( "" );
	  }
#line 1959 "yacc.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 378 "yacc.yy" /* yacc.c:1646  */
    {
          }
#line 1966 "yacc.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 385 "yacc.yy" /* yacc.c:1646  */
    {
        (yyval._str) = newQString( "" );
	  }
#line 1974 "yacc.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 389 "yacc.yy" /* yacc.c:1646  */
    {
        (yyval._str) = newQString( *((yyvsp[-1]._str)) + *((yyvsp[0]._str)) );
	  }
#line 1982 "yacc.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 393 "yacc.yy" /* yacc.c:1646  */
    {
        (yyval._str) = newQString( *((yyvsp[-1]._str)) + *((yyvsp[0]._str)) );
	  }
#line 1990 "yacc.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 397 "yacc.yy" /* yacc.c:1646  */
    {
        (yyval._str) = newQString( *((yyvsp[-1]._str)) + *((yyvsp[0]._str)) );
	  }
#line 1998 "yacc.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 401 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[0]._str);
	  }
#line 2006 "yacc.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 405 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[0]._str);
	  }
#line 2014 "yacc.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 409 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[0]._str);
	  }
#line 2022 "yacc.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 413 "yacc.yy" /* yacc.c:1646  */
    {	
	        (yyval._str) = (yyvsp[0]._str);
	  }
#line 2030 "yacc.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 417 "yacc.yy" /* yacc.c:1646  */
    {
 	        (yyval._str) = (yyvsp[0]._str);
	  }
#line 2038 "yacc.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 421 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[0]._str);
	  }
#line 2046 "yacc.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 425 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[0]._str);
	  }
#line 2054 "yacc.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 429 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[0]._str);
	  }
#line 2062 "yacc.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 433 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[0]._str);
	  }
#line 2070 "yacc.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 437 "yacc.yy" /* yacc.c:1646  */
    {
                (yyval._str) = (yyvsp[0]._str);
          }
#line 2078 "yacc.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 441 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[0]._str);
	  }
#line 2086 "yacc.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 445 "yacc.yy" /* yacc.c:1646  */
    {
                (yyval._str) = (yyvsp[0]._str);
          }
#line 2094 "yacc.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 449 "yacc.yy" /* yacc.c:1646  */
    {
                (yyval._str) = (yyvsp[0]._str);
          }
#line 2102 "yacc.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 467 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2108 "yacc.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 468 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2114 "yacc.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 472 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2120 "yacc.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 473 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2126 "yacc.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 474 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2132 "yacc.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 475 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2138 "yacc.cc" /* yacc.c:1646  */
    break;

  case 81:
#line 476 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2144 "yacc.cc" /* yacc.c:1646  */
    break;

  case 82:
#line 480 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2150 "yacc.cc" /* yacc.c:1646  */
    break;

  case 83:
#line 481 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2156 "yacc.cc" /* yacc.c:1646  */
    break;

  case 84:
#line 482 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2162 "yacc.cc" /* yacc.c:1646  */
    break;

  case 85:
#line 487 "yacc.yy" /* yacc.c:1646  */
    {
		if (dcop_area) {
          QString* tmp = newQString("<TYPEDEF name=\"%1\" template=\"%2\"><PARAM %3</TYPEDEF>\n");
		  *tmp = tmp->arg( *((yyvsp[-1]._str)) ).arg( *((yyvsp[-5]._str)) ).arg( *((yyvsp[-3]._str)) );
		  (yyval._str) = tmp;
		} else {
          (yyval._str) = newQString("");
		}
	  }
#line 2176 "yacc.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 497 "yacc.yy" /* yacc.c:1646  */
    {
		if (dcop_area)
		  yyerror("scoped template typedefs are not supported in dcop areas!");
	  }
#line 2185 "yacc.cc" /* yacc.c:1646  */
    break;

  case 87:
#line 505 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._int) = 0;
	  }
#line 2193 "yacc.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 509 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._int) = 1;
	  }
#line 2201 "yacc.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 515 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("signed int"); }
#line 2207 "yacc.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 516 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("signed int"); }
#line 2213 "yacc.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 517 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("unsigned int"); }
#line 2219 "yacc.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 518 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("unsigned int"); }
#line 2225 "yacc.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 519 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("signed short int"); }
#line 2231 "yacc.cc" /* yacc.c:1646  */
    break;

  case 94:
#line 520 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("signed short int"); }
#line 2237 "yacc.cc" /* yacc.c:1646  */
    break;

  case 95:
#line 521 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("signed long int"); }
#line 2243 "yacc.cc" /* yacc.c:1646  */
    break;

  case 96:
#line 522 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("signed long int"); }
#line 2249 "yacc.cc" /* yacc.c:1646  */
    break;

  case 97:
#line 523 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("unsigned short int"); }
#line 2255 "yacc.cc" /* yacc.c:1646  */
    break;

  case 98:
#line 524 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("unsigned short int"); }
#line 2261 "yacc.cc" /* yacc.c:1646  */
    break;

  case 99:
#line 525 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("unsigned long int"); }
#line 2267 "yacc.cc" /* yacc.c:1646  */
    break;

  case 100:
#line 526 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("unsigned long int"); }
#line 2273 "yacc.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 527 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("int"); }
#line 2279 "yacc.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 528 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("long int"); }
#line 2285 "yacc.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 529 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("long int"); }
#line 2291 "yacc.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 530 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("short int"); }
#line 2297 "yacc.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 531 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("short int"); }
#line 2303 "yacc.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 532 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("char"); }
#line 2309 "yacc.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 533 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("signed char"); }
#line 2315 "yacc.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 534 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = newQString("unsigned char"); }
#line 2321 "yacc.cc" /* yacc.c:1646  */
    break;

  case 111:
#line 544 "yacc.yy" /* yacc.c:1646  */
    {
        (yyval._str) = newQString( "" );
	  }
#line 2329 "yacc.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 549 "yacc.yy" /* yacc.c:1646  */
    {
        (yyval._str) = newQString( *((yyvsp[-2]._str)) + *((yyvsp[0]._str)) );
	  }
#line 2337 "yacc.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 557 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = (yyvsp[0]._str); }
#line 2343 "yacc.cc" /* yacc.c:1646  */
    break;

  case 116:
#line 558 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = (yyvsp[0]._str); }
#line 2349 "yacc.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 559 "yacc.yy" /* yacc.c:1646  */
    { (yyval._str) = (yyvsp[0]._str); }
#line 2355 "yacc.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 560 "yacc.yy" /* yacc.c:1646  */
    {
        QString *tmp = newQString("%1&lt;%2&gt;");
		*tmp = tmp->arg(*((yyvsp[-3]._str)));
		*tmp = tmp->arg(*((yyvsp[-1]._str)));
		(yyval._str) = tmp;
	 }
#line 2366 "yacc.cc" /* yacc.c:1646  */
    break;

  case 119:
#line 566 "yacc.yy" /* yacc.c:1646  */
    {
        QString *tmp = newQString("%1&lt;%2&gt;::%3");
		*tmp = tmp->arg(*((yyvsp[-5]._str)));
		*tmp = tmp->arg(*((yyvsp[-3]._str)));
		*tmp = tmp->arg(*((yyvsp[0]._str)));
		(yyval._str) = tmp;
	 }
#line 2378 "yacc.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 578 "yacc.yy" /* yacc.c:1646  */
    {
        (yyval._str) = newQString(*((yyvsp[-2]._str)) + "," + *((yyvsp[0]._str)));
	  }
#line 2386 "yacc.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 582 "yacc.yy" /* yacc.c:1646  */
    {
 	    (yyval._str) = (yyvsp[0]._str);
	  }
#line 2394 "yacc.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 590 "yacc.yy" /* yacc.c:1646  */
    {
	    if (dcop_area)
	      yyerror("in dcop areas are no pointers allowed");
	  }
#line 2403 "yacc.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 595 "yacc.yy" /* yacc.c:1646  */
    {
 	    (yyval._str) = (yyvsp[0]._str);
	  }
#line 2411 "yacc.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 604 "yacc.yy" /* yacc.c:1646  */
    {
	    if (dcop_area)
	      yyerror("in dcop areas are no pointers allowed");
	  }
#line 2420 "yacc.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 608 "yacc.yy" /* yacc.c:1646  */
    {
	     if (dcop_area) {
        QString* tmp = newQString("<TYPE  qleft=\"const\" qright=\"" AMP_ENTITY "\">%1</TYPE>");
		*tmp = tmp->arg( *((yyvsp[-1]._str)) );
		(yyval._str) = tmp;
	     }
	  }
#line 2432 "yacc.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 615 "yacc.yy" /* yacc.c:1646  */
    {
        QString* tmp = newQString("<TYPE>%1</TYPE>");
		*tmp = tmp->arg( *((yyvsp[0]._str)) );
		(yyval._str) = tmp;
	}
#line 2442 "yacc.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 620 "yacc.yy" /* yacc.c:1646  */
    {
        QString* tmp = newQString("<TYPE>%1</TYPE>");
        *tmp = tmp->arg( *((yyvsp[-1]._str)) );
        (yyval._str) = tmp;
    }
#line 2452 "yacc.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 625 "yacc.yy" /* yacc.c:1646  */
    { 
        if (dcop_area) { 
           QString* tmp = newQString("<TYPE  qleft=\"const\" qright=\"" AMP_ENTITY "\">%1</TYPE>");
           *tmp = tmp->arg( *((yyvsp[-2]._str)) ); 
           (yyval._str) = tmp; 
        } 
    }
#line 2464 "yacc.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 632 "yacc.yy" /* yacc.c:1646  */
    {
	     if (dcop_area)
		yyerror("in dcop areas are only const references allowed!");
	  }
#line 2473 "yacc.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 637 "yacc.yy" /* yacc.c:1646  */
    {
        QString* tmp = newQString("<TYPE>%1</TYPE>");
		*tmp = tmp->arg( *((yyvsp[0]._str)) );
		(yyval._str) = tmp;
	}
#line 2483 "yacc.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 643 "yacc.yy" /* yacc.c:1646  */
    {
	    if (dcop_area)
	      yyerror("in dcop areas are no pointers allowed");
	  }
#line 2492 "yacc.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 651 "yacc.yy" /* yacc.c:1646  */
    {
        (yyval._str) = newQString(*((yyvsp[-2]._str)) + "," + *((yyvsp[0]._str)));
	  }
#line 2500 "yacc.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 655 "yacc.yy" /* yacc.c:1646  */
    {
 	    (yyval._str) = (yyvsp[0]._str);
	  }
#line 2508 "yacc.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 662 "yacc.yy" /* yacc.c:1646  */
    {
		if (dcop_area) {
           QString* tmp = newQString("\n        <ARG>%1<NAME>%2</NAME></ARG>");
  		   *tmp = tmp->arg( *((yyvsp[-2]._str)) );
  		   *tmp = tmp->arg( *((yyvsp[-1]._str)) );
		   (yyval._str) = tmp;		
        } else (yyval._str) = newQString();
	  }
#line 2521 "yacc.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 671 "yacc.yy" /* yacc.c:1646  */
    {
		if (dcop_area) {
           QString* tmp = newQString("\n        <ARG>%1</ARG>");
  		   *tmp = tmp->arg( *((yyvsp[-1]._str)) );
		   (yyval._str) = tmp;		
        } else (yyval._str) = newQString();
	  }
#line 2533 "yacc.cc" /* yacc.c:1646  */
    break;

  case 136:
#line 679 "yacc.yy" /* yacc.c:1646  */
    {
		if (dcop_area)
			yyerror("variable arguments not supported in dcop area.");
        (yyval._str) = newQString("");
	  }
#line 2543 "yacc.cc" /* yacc.c:1646  */
    break;

  case 137:
#line 688 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 2550 "yacc.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 691 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 2557 "yacc.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 694 "yacc.yy" /* yacc.c:1646  */
    {
	  }
#line 2564 "yacc.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 701 "yacc.yy" /* yacc.c:1646  */
    {
          }
#line 2571 "yacc.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 704 "yacc.yy" /* yacc.c:1646  */
    {
          }
#line 2578 "yacc.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 707 "yacc.yy" /* yacc.c:1646  */
    {
          }
#line 2585 "yacc.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 710 "yacc.yy" /* yacc.c:1646  */
    {
          }
#line 2592 "yacc.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 713 "yacc.yy" /* yacc.c:1646  */
    {
          }
#line 2599 "yacc.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 718 "yacc.yy" /* yacc.c:1646  */
    { (yyval._int) = 0; }
#line 2605 "yacc.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 719 "yacc.yy" /* yacc.c:1646  */
    { (yyval._int) = 1; }
#line 2611 "yacc.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 728 "yacc.yy" /* yacc.c:1646  */
    {
	     if (dcop_area || dcop_signal_area) {
        QString* tmp = 0;
                tmp = newQString(
                        "    <%4>\n"
                        "        %2\n"
                        "        <NAME>%1</NAME>"
                        "%3\n"
                        "     </%5>\n");
		*tmp = tmp->arg( *((yyvsp[-4]._str)) );
		*tmp = tmp->arg( *((yyvsp[-5]._str)) );
                *tmp = tmp->arg( *((yyvsp[-2]._str)) );
                
                QString tagname = (dcop_signal_area) ? "SIGNAL" : "FUNC";
                QString attr = ((yyvsp[0]._int)) ? " qual=\"const\"" : "";
                *tmp = tmp->arg( QString("%1%2").arg(tagname).arg(attr) );
                *tmp = tmp->arg( QString("%1").arg(tagname) );
		(yyval._str) = tmp;
   	     } else
            (yyval._str) = newQString("");
	  }
#line 2637 "yacc.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 750 "yacc.yy" /* yacc.c:1646  */
    {
	     if (dcop_area)
		yyerror("operators aren't allowed in dcop areas!");
         (yyval._str) = newQString("");
	  }
#line 2647 "yacc.cc" /* yacc.c:1646  */
    break;

  case 154:
#line 760 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2653 "yacc.cc" /* yacc.c:1646  */
    break;

  case 155:
#line 761 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2659 "yacc.cc" /* yacc.c:1646  */
    break;

  case 156:
#line 762 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2665 "yacc.cc" /* yacc.c:1646  */
    break;

  case 157:
#line 767 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2671 "yacc.cc" /* yacc.c:1646  */
    break;

  case 158:
#line 772 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2677 "yacc.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 773 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2683 "yacc.cc" /* yacc.c:1646  */
    break;

  case 160:
#line 778 "yacc.yy" /* yacc.c:1646  */
    {
	        (yyval._str) = (yyvsp[-1]._str);
	  }
#line 2691 "yacc.cc" /* yacc.c:1646  */
    break;

  case 161:
#line 782 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[-3]._str);
	  }
#line 2699 "yacc.cc" /* yacc.c:1646  */
    break;

  case 162:
#line 786 "yacc.yy" /* yacc.c:1646  */
    {
		(yyval._str) = (yyvsp[-1]._str);
	  }
#line 2707 "yacc.cc" /* yacc.c:1646  */
    break;

  case 163:
#line 790 "yacc.yy" /* yacc.c:1646  */
    {
	      /* The constructor */
	      assert(!dcop_area);
              (yyval._str) = newQString("");
	  }
#line 2717 "yacc.cc" /* yacc.c:1646  */
    break;

  case 164:
#line 796 "yacc.yy" /* yacc.c:1646  */
    {
	      /* The constructor */
	      assert(!dcop_area);
              (yyval._str) = newQString("");
	  }
#line 2727 "yacc.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 802 "yacc.yy" /* yacc.c:1646  */
    {
	      /* The destructor */
  	      assert(!dcop_area);
              (yyval._str) = newQString("");
	  }
#line 2737 "yacc.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 808 "yacc.yy" /* yacc.c:1646  */
    {
              if (dcop_area) {
                 if (dcop_signal_area)
                     yyerror("DCOP signals cannot be static");
                 else
                     yyerror("DCOP functions cannot be static");
              } else {
                 (yyval._str) = newQString();
              }  
	  }
#line 2752 "yacc.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 821 "yacc.yy" /* yacc.c:1646  */
    {
		function_mode = 1;
	}
#line 2760 "yacc.cc" /* yacc.c:1646  */
    break;

  case 171:
#line 833 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2766 "yacc.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 834 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2772 "yacc.cc" /* yacc.c:1646  */
    break;

  case 176:
#line 846 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2778 "yacc.cc" /* yacc.c:1646  */
    break;

  case 177:
#line 847 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2784 "yacc.cc" /* yacc.c:1646  */
    break;

  case 178:
#line 848 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2790 "yacc.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 851 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2796 "yacc.cc" /* yacc.c:1646  */
    break;

  case 180:
#line 855 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2802 "yacc.cc" /* yacc.c:1646  */
    break;

  case 181:
#line 856 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2808 "yacc.cc" /* yacc.c:1646  */
    break;

  case 182:
#line 857 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2814 "yacc.cc" /* yacc.c:1646  */
    break;

  case 183:
#line 858 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2820 "yacc.cc" /* yacc.c:1646  */
    break;

  case 184:
#line 859 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2826 "yacc.cc" /* yacc.c:1646  */
    break;

  case 185:
#line 860 "yacc.yy" /* yacc.c:1646  */
    {}
#line 2832 "yacc.cc" /* yacc.c:1646  */
    break;


#line 2836 "yacc.cc" /* yacc.c:1646  */
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
#line 863 "yacc.yy" /* yacc.c:1906  */


void dcopidlParse( const char *_code )
{
    dcopidlInitFlex( _code );
    yyparse();
}
