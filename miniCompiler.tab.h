
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


