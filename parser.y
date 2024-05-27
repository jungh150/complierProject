%{
/*
 * parser.y - yacc source for the MiniC
 * Programmer - KIM-YEJI(2176082), SONG-CHAEWON(2076216), SHIN-JUNGHWA(2271035), YOON-HAYEONG(2071033)
 * date - 2024/5/31
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

int type_int = 0;
int type_void = 0;

void line(int);
extern printError();
extern yylex();
extern yyerror(s);
%}

%token TCONST TELSE TIF TINT TRETURN TVOID TWHILE
%token TADD TSUB TMUL TDIV TMOD 
%token TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TOR TAND TEQUAL TNOTEQU TGREAT TLESS TGREATE TLESSE
%token TINC TDEC TCOMMA TSEMICOLON
%token TLPAREN TRPAREN TLBRACE TRBRACE TLSQUARE TRSQUARE
%toekn TNUMBER, TRNUMBER, TIDENT
%token TILLCH, TILLIDENT

%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE

%%
mini_c 				: translation_unit			
					;
translation_unit 	: external_dcl				
					| translation_unit external_dcl
					;
external_dcl 		: function_def				
		  			| declaration				
					| TIDEN TSEMICOLON
					| TIDEN error
					{
						yyerrok;
						printError(wrong_st);	/* error - wrong statement */
					}
					;
function_def 		: function_header compound_st		
					| function_header TSEMICOLON
					| function_header error			/* 비정상적인 함수 정의 */
					{
						/* 에러 발생 시 type 수정을 위해 default값 0 세팅 */
						/* identifier about parse error */
						look_tmp->type = 0;
						yyerrok;
						/* error - wrong function definition */
						printError(wrong_funcdef);
					}
					;
function_header 	: dcl_spec function_name formal_param
					;
dcl_spec 			: dcl_specifiers
					;		
dcl_specifiers 		: dcl_specifier			
		 			| dcl_specifiers dcl_specifier	
					;
dcl_specifier 		: type_qualifier
					| type_specifier
					;
type_qualifier 		: TCONST
					;
type_specifier 		: TINT	{type_int=1;}	/* type: integer */
		 			| tvoid	{type_void=1;};	/* type: void */
					;
function_name 		: TIDENT					
					{
						/* identifier about parse error or not defined identifier/function */
						if(look_id->type == 0 || look_id->type == 5)
						{
							look_id->type=4;		/* function name */
							type_int=0;				/* not integer */
							type_void=0;			/* not void */
							look_tmp=look_id;		
						}
					}
					;
formal_param 		: TLPAREN opt_formal_param TRPAREN
					;
opt_formal_param 	: formal_param_list
					|
					;
formal_param_list 	: param_dcl	
		    		| formal_param_list TCOMMA param_dcl
					;

/* 아래는 참고자료에 없는 부분으로, parser_book.y에 있는 코드 semantic만 지우고 그대로 가져옴 */

param_dcl 			: dcl_spec declarator
compound_st 		: '{' opt_dcl_list opt_stat_list '}'
opt_dcl_list 		: declaration_list
					|					
declaration_list 	: declaration
					| declaration_list declaration 
declaration 		: dcl_spec init_dcl_list ';'		
init_dcl_list 		: init_declarator			
					| init_dcl_list ',' init_declarator 	
init_declarator 	: declarator					
		 			| declarator '=' tnumber		
declarator 			: tident					
	     			| tident '[' opt_number ']'		
opt_number 			: tnumber				
	     			|					
opt_stat_list 		: statement_list			
		 			|					{semantic(38);};
statement_list 		: statement				
		 			| statement_list statement 		
statement 			: compound_st			
	   				| expression_st			
	   				| if_st					
	   				| while_st				
	   				| return_st				
	   				;
expression_st 		: opt_expression ';'			
opt_expression		: expression			
		 			|					
if_st 				: tif '(' expression ')' statement 
					| tif '(' expression ')' statement telse statement 	
while_st 			: twhile '(' expression ')' statement 	
return_st 			: treturn opt_expression ';'		
expression 			: assignment_exp			
assignment_exp 		: logical_or_exp			
					| unary_exp '=' assignment_exp 		
					| unary_exp taddAssign assignment_exp 	
					| unary_exp tsubAssign assignment_exp 	
					| unary_exp tmulAssign assignment_exp 	
					| unary_exp tdivAssign assignment_exp 	
					| unary_exp tmodAssign assignment_exp 	
					;
logical_or_exp 		: logical_and_exp			
					| logical_or_exp tor logical_and_exp 	
logical_and_exp 	: equality_exp				
		 			| logical_and_exp tand equality_exp 
equality_exp 		: relational_exp			
					| equality_exp tequal relational_exp 	
					| equality_exp tnotequ relational_exp 
relational_exp	 	: additive_exp 			
					| relational_exp '>' additive_exp 
					| relational_exp '<' additive_exp 	
					| relational_exp tgreate additive_exp 
					| relational_exp tlesse additive_exp 	
additive_exp 		: multiplicative_exp			
					| additive_exp '+' multiplicative_exp 	
					| additive_exp '-' multiplicative_exp 	
multiplicative_exp 	: unary_exp				
		    		| multiplicative_exp '*' unary_exp 	
					| multiplicative_exp '/' unary_exp 
					| multiplicative_exp '%' unary_exp 	
unary_exp 			: postfix_exp				
	   				| '-' unary_exp				
	   				| '!' unary_exp				
	   				| tinc unary_exp			
	   				| tdec unary_exp			
postfix_exp 		: primary_exp				
	      			| postfix_exp '[' expression ']' 	
	      			| postfix_exp '(' opt_actual_param ')' 	
	      			| postfix_exp tinc			
	      			| postfix_exp tdec			
opt_actual_param 	: actual_param				
		  			|					
actual_param 		: actual_param_list			
actual_param_list 	: assignment_exp			
					| actual_param_list ',' assignment_exp 	
primary_exp 		: tident				
	     			| tnumber				
	     			| '(' expression ')'			
%%

void semantic(int n)
{	
	printf("reduced rule number = %d\n",n);
}
