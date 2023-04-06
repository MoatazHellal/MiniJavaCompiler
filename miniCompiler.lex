%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "miniCompiler.tab.h"
%}

%option yylineno

delimiter    [ \t]
bl        {delimiter}+
number   [0-9]
letter 	[a-zA-Z]
parenthese_open                 (\()
parenthese_close                (\))
bracket_open                    (\[)
bracket_close                   (\])
brace_open                      (\{)
brace_close                     (\})
integer_literal 		{number}+
boolean_literal 		true|false
comment_block                   "/*"([^*]|\*+[^*/])*\*+"/"
comment_line                    "//".*
error_comment                   \/\*([^(\*\/)]|\n)*
identifier           [a-zA-Z_][a-zA-Z0-9_]*
error_identifier                {number}({letter}|{number}|"_")*


%%

{integer_literal}  {return Integer_Literal;}
{boolean_literal}   {return Boolean_Literal;}
{parenthese_open}	  {return open_parenthese ;}
{parenthese_close}  {return closed_parenthese;}
{bracket_open}	{return open_bracket;}
{bracket_close}	{return closed_bracket;}
{brace_open}	{return open_brace;}
{brace_close}	{return closed_brace;}
{comment_block}	/* no actions */
{comment_line}	  /* no actions */


"class"                               return class_keyword;
"public"                              return public_keyword;
"static void main"                    return main_class_keyword;
"extends"                             return extends_keyword;
"{return"                             return return_keyword;
"if"                                  return if_keyword;
"else"                                return else_keyword;
"while"                               return whileloop_keyword;
"System.out.println"                  return print_keyword;
"length"                              return length_keyword;
"this"                                return this_keyword;
"new"                                 return new_keyword;
"int"                                 return int_type;
"boolean"                             return boolean_type;
"String"                              return string_type;

"="	                               return OP_AFFECT;
"+"                                   return OP_ADD;
"-"                                   return OP_SUBSTRACT;
"*"                                   return OP_MULTIPLY;
"!"						  return OP_NOT;
"&&"                                  return LOG_AND;
"<"                                   return LOG_LESS;
"<="                                  return LOG_EQLESS;
">"                                   return LOG_MORE;
">="                                  return LOG_EQMORE;
"=="                                  return LOG_EQ;
"!="                                  return LOG_DIF;
";"                                   return SEMI_COLON;
"."                                   return DOT;
","                                   return COMMA;
{identifier}	  			return Ident ;

%%


int yywrap()
{
	return(1);
}