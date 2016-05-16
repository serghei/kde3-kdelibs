/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 79 "yacc.yy" /* yacc.c:1909  */

  long   _int;
  QString        *_str;
  unsigned short          _char;
  double _float;

#line 128 "yacc.hh" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_HH_INCLUDED  */
