%{
	

#include <stdio.h>	
 			
int yyerror(char const *msg);	
int yylex(void);
extern int yylineno;

%}

%token Ident
%token int_type
%token boolean_type
%token string_type

%token Boolean_Literal
%token Integer_Literal
%token String_Literal

%token class_keyword
%token public_keyword
%token main_class_keyword
%token extends_keyword
%token return_keyword
%token if_keyword
%token else_keyword
%token whileloop_keyword
%token print_keyword
%token length_keyword
%token this_keyword
%token new_keyword

%token open_parenthese 
%token closed_parenthese
%token open_bracket
%token closed_bracket
%token open_brace
%token closed_brace

%token OP_AFFECT
%token OP_ADD
%token OP_SUBSTRACT
%token OP_MULTIPLY
%token OP_NOT

%token LOG_AND
%token LOG_LESS
%token LOG_EQLESS
%token LOG_MORE
%token LOG_EQMORE
%token LOG_EQ
%token LOG_DIF

%token SEMI_COLON
%token DOT
%token COMMA


%error-verbose
%start Program



%%


Program 			 : MainClass ClassDeclarationList;

MainClass 			 :class_keyword Identifier open_brace public_keyword main_class_keyword open_parenthese string_type open_bracket closed_bracket Identifier closed_parenthese open_brace Statement closed_brace closed_brace;

ClassDeclarationList     :ClassDeclaration ClassDeclarationList | ;

VarDeclarationList       : VarDeclaration VarDeclarationList | ;

MethodDeclarationList    :MethodDeclaration MethodDeclarationList | ;

extend_key_id            :extends_keyword Identifier | ;

ClassDeclaration         :class_keyword Identifier extend_key_id open_brace VarDeclarationList MethodDeclarationList closed_brace
			  |error Identifier extend_key_id open_brace VarDeclarationList MethodDeclarationList closed_brace           			{yyerror (" class attendu en ligne : "); YYABORT}
					|	class_keyword error extend_key_id open_brace VarDeclarationList MethodDeclarationList closed_brace          {yyerror (" Identifier attendu en ligne : "); YYABORT}
					|	class_keyword Identifier extend_key_id error VarDeclarationList MethodDeclarationList closed_brace           				{yyerror (" Accolade ouvrante attendu en ligne : "); YYABORT}
					|	class_keyword Identifier extend_key_id open_brace VarDeclarationList MethodDeclarationList error           				{yyerror (" Accolade fermante attendu en ligne : "); YYABORT};


VarDeclaration 		 :Type Identifier SEMI_COLON
				|error Identifier SEMI_COLON    {yyerror (" Type attendu en ligne : "); YYABORT}
				|Type error SEMI_COLON     {yyerror (" Identifier attendu en ligne : "); YYABORT}
				|Type Identifier error    {yyerror (" Point virgule attendu en ligne : "); YYABORT};

COMMATypeIdentifierList  : COMMA Type Identifier COMMATypeIdentifierList| ;



type_id                  : Type Identifier COMMATypeIdentifierList | ;

MethodDeclaration        :public_keyword Type Identifier open_parenthese type_id closed_parenthese open_brace VarDeclarationList StatementList return_keyword Expression SEMI_COLON closed_brace;

Type 				 :int_type
				|Identifier
				|boolean_type
				|int_type open_bracket closed_bracket;

StatementList            :Statement StatementList | ;


Statement			 : Identifier open_bracket Expression closed_bracket OP_AFFECT Expression SEMI_COLON
				|Identifier OP_AFFECT Expression SEMI_COLON
				|print_keyword open_parenthese Expression closed_parenthese SEMI_COLON
				|whileloop_keyword open_parenthese Expression closed_parenthese Statement
				|if_keyword open_parenthese Expression closed_parenthese Statement else_keyword Statement
				|open_brace StatementList closed_brace;

op                       :LOG_AND LOG_AND | LOG_LESS | OP_ADD | OP_SUBSTRACT | OP_MULTIPLY;

Expression			 : Identifier
				|this_keyword
				|new_keyword int_type open_bracket Expression closed_bracket
				|new_keyword Identifier open_parenthese closed_parenthese
				|open_parenthese Expression closed_parenthese
				|Boolean_Literal
				|Integer_Literal
				|Expression DOT length_keyword
				|Expression open_bracket Expression closed_bracket
				|OP_NOT Expression 
				|Expression op Expression
				|Expression DOT Identifier open_parenthese Expr closed_parenthese;

ExpressionList           :COMMA Expression ExpressionList | ;

Expr                     : Expression ExpressionList | ;

Identifier             : Ident;
                      



%%


int yyerror(char const *msg) {
       
	
	fprintf(stderr, "%s %d\n", msg,yylineno);
	return 0;
	
	
}

extern FILE *yyin;

int main()
{
 yyparse();
}

  
           
