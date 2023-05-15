%{
	

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

MainClass 			 :{tabCodeInt[indextab]=creerCode("ENTREE",-1, NULL); indextab++;} class_keyword Identifier {checkID(nom, tOther ,class, yylineno);} open_brace VarDeclarationList public_keyword  main_class_keyword {tabCodeInt[indextab]=creerCode("ENTREE",-1, "main"); indextab++;} { checkID("main", tVoid, fonction, yylineno); } open_parenthese string_type open_bracket closed_bracket Identifier {checkID(nom, tString, parametre, yylineno);} closed_parenthese open_brace VarDeclarationList StatementList closed_brace {fonctionEnd();} {tabCodeInt[indextab]=creerCode("SORTIE",-1, "main"); indextab++;} closed_brace {classEnd();} {tabCodeInt[indextab]=creerCode("SORTIE",-1,NULL); indextab++;};


ClassDeclarationList     :ClassDeclaration ClassDeclarationList | ;

MethodDeclarationList    :MethodDeclaration MethodDeclarationList | ;

ClassDeclaration         :{tabCodeInt[indextab]=creerCode("ENTREE",-1,NULL); indextab++;} class_keyword Identifier {checkID(nom, tOther ,class, yylineno);} extend_key_id open_brace VarDeclarationList MethodDeclarationList closed_brace {classEnd();} {tabCodeInt[indextab]=creerCode("SORTIE",-1,NULL); indextab++;}

MethodDeclaration        :public_keyword Type Identifier {strcpy(codeMethod, nom); tabCodeInt[indextab]=creerCode("ENTREE",-1,codeMethod); indextab++;} {checkID(nom, type , fonction, yylineno);} open_parenthese {inParam();} type_id {outParam();} closed_parenthese open_brace VarDeclarationList StatementList return_keyword Expression SEMI_COLON closed_brace{tabCodeInt[indextab]=creerCode("SORTIE",-1,codeMethod);indextab++;} {fonctionEnd();};



VarDeclaration 		 :Type Identifier {checkID(nom, type ,variable , yylineno);} SEMI_COLON
				|error Identifier SEMI_COLON    {yyerror (" Type attendu en ligne : "); YYABORT}
				|Type error SEMI_COLON     {yyerror (" Identifier attendu en ligne : "); YYABORT}
				|Type Identifier error    {yyerror (" Point virgule attendu en ligne : "); YYABORT};

VarDeclarationList       : VarDeclaration VarDeclarationList | ;


COMMATypeIdentifierList  : COMMA Type Identifier {checkID(nom, type ,variable , yylineno);} COMMATypeIdentifierList| ;

extend_key_id            :extends_keyword Identifier | ;


type_id                  : Type Identifier {checkID(nom, type ,variable , yylineno);} COMMATypeIdentifierList | ;

Type 				 :int_type {type=tInt}
				/*|Identifier*/
				|boolean_type {type=tBoolean}
				|int_type open_bracket closed_bracket {type=tInt};

StatementList            :Statement StatementList | ;


Statement			 : Identifier open_bracket Expression closed_bracket {CheckDeclared(nom, yylineno)} {initVar(nom, yylineno);} {useVar(nom);} OP_AFFECT Expression SEMI_COLON
				|Identifier {CheckDeclared(nom, yylineno);} {useVar(nom);} {tabCodeInt[indextab]=creerCode("LDV",getAddress(nom,table_total),NULL);indextab++;} OP_AFFECT {initVar(nom, yylineno);} Expression {CheckAffectation(nom, typeAffect, yylineno);} SEMI_COLON {tabCodeInt[indextab]=creerCode("STORE",getAddress(nom,table_total),NULL);indextab++;}
				|print_keyword open_parenthese Expression closed_parenthese SEMI_COLON
				|whileloop_keyword {indexWhile1=indextab;} open_parenthese Expression closed_parenthese {tabCodeInt[indextab]=creerCode("TANTQUEFAUX",-1,NULL);indexWhile2=indextab;indextab++;}  Statement {tabCodeInt[indextab]=creerCode("TANTQUE",indexWhile1,NULL);indextab++;tabCodeInt[indexWhile2].operande=indextab;}
				|if_keyword open_parenthese Expression closed_parenthese {tabCodeInt[indextab]=creerCode("SIFAUX",-1,NULL);indexIf=indextab;indextab++;} Statement else_keyword {tabCodeInt[indextab]=creerCode("SAUT",-1,NULL);indextab++;tabCodeInt[indexIf].operande=indextab;indexIf=indextab-1;} Statement {tabCodeInt[indexIf].operande=indextab+1;}
				|open_brace StatementList closed_brace;

op                       :LOG_AND LOG_AND {opCode="AND";} | LOG_LESS {opCode="INF";} | OP_ADD {opCode="ADD";} | OP_SUBSTRACT {opCode="SUB";} | OP_MULTIPLY {tabCodeInt[indextab]=creerCode("MUL",-1,NULL);indextab++;};

Expression			 : Identifier {(CheckDeclared(nom, yylineno));} {CheckInitialise(nom, yylineno);} {useVar(nom);} {fonctionCallParameter(tInt, nom, yylineno);} {typeAffect = type;} {tabCodeInt[indextab]=creerCode("LDV",getAddress(nom,table_total),NULL);indextab++;}
				|this_keyword {fonctionCallParameter(tOther, NULL, yylineno);} {typeAffect = tOther;}
				|new_keyword int_type open_bracket Expression closed_bracket
				|new_keyword Identifier open_parenthese closed_parenthese {fonctionCallParameter(tOther, NULL, yylineno);}
				|open_parenthese Expression closed_parenthese
				|Boolean_Literal {fonctionCallParameter(tBoolean, NULL, yylineno);} {typeAffect = tBoolean;} {tabCodeInt[indextab]=creerCode("LDC",boolval,NULL);indextab++;}
				|Integer_Literal {fonctionCallParameter(tInt, NULL, yylineno);} {typeAffect = tInt;} {tabCodeInt[indextab]=creerCode("LDC",numval,NULL);indextab++;}
				|Expression DOT length_keyword {fonctionCallParameter(tInt, NULL, yylineno);} {typeAffect = tInt;}
				|Expression open_bracket Expression closed_bracket
				|OP_NOT Expression {fonctionCallParameter(tBoolean, NULL, yylineno);} {typeAffect = tBoolean;}
				|Expression op Expression {tabCodeInt[indextab]=creerCode(opCode,-1,NULL);indextab++;}
				|Expression DOT Identifier {fonctionCallStart(nom, type, yylineno);} {typeAffect = type;} open_parenthese Expr closed_parenthese {CheckFunctionParams(yylineno);} {tabCodeInt[indextab]=creerCode("APPEL",getFonctionLine(nom),NULL);indextab++;};

ExpressionList           :COMMA Expression ExpressionList | ;

Expr                     : Expression ExpressionList | ;

Identifier             : Ident;
                      



%%


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
	printf("\n");
	printf("\n");
	genererCode();
}

  char *yyget_text(char *start) {
    size_t size =  1;
    char *text = malloc(size + 1);
    strncpy(text, start, size);
    text[size] = '\0';
    return text;
}

           
