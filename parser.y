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

extern enum errortypes err;
extern void printError(enum errortypes err);

extern int yylex();
extern yyerror(char* s);

extern int type_int = 0; // 1: type of identifier is integer
extern int type_void = 0; // 1: type of identifier is void
%}

%token TIDENT TNUMBER TCONST TELSE TIF TINT TRETURN TVOID TWHILE
%token TADD TSUB TMUL TDIV TMOD 
%token TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TOR TAND TEQUAL TNOTEQU TGREAT TLESS TGREATE TLESSE
%token TINC TDEC TCOMMA TSEMICOLON
%token TLPAREN TRPAREN TLBRACE TRBRACE TLSQUARE TRSQUARE
%nonassoc TLOWERTHANELSE
%nonassoc TELSE

%%
mini_c 				: translation_unit
					;
translation_unit 	: external_dcl
					| translation_unit external_dcl
					;
external_dcl 		: function_def
		  			| declaration
					;
function_def 		: function_header compound_st
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
type_specifier 		: TINT	{type_int=1; type_void=0;}	/* type: integer */
		 			| TVOID	{type_void=1; type_int=0;}	/* type: void */
					;
function_name 		: identifier
					;
formal_param 		: TLPAREN opt_formal_param TRPAREN
					| TLPAREN opt_formal_param error
					{
						yyerrok;
						printError(NOPAREN);	/* error - Missing paren */
					}
					;
opt_formal_param 	: formal_param_list
					|
					;
formal_param_list 	: param_dcl
		    		| formal_param_list TCOMMA param_dcl
					;
param_dcl 			: dcl_spec declarator
					;
compound_st 		: TLBRACE opt_dcl_list opt_stat_list TRBRACE
					| TLBRACE opt_dcl_list opt_stat_list error
					{
						yyerrok;
						printError(NOBRACE);	/* error - Missing brace */
					}
					;
opt_dcl_list 		: declaration_list
					|
					;
declaration_list 	: declaration
					| declaration_list declaration
					;
declaration 		: dcl_spec init_dcl_list TSEMICOLON
					| dcl_spec init_dcl_list error
					{
						yyerrok;
						printError(NOSEMI);	/* error - Missing semicolon */
					}
					| dcl_spec error
					{
						yyerrok;
						printError(WRONGDCL);	/* error - wrong declaration */
					}
					;
init_dcl_list 		: init_declarator
					| init_dcl_list TCOMMA init_declarator
					;
init_declarator 	: declarator
		 			| declarator TASSIGN TNUMBER
					;
declarator 			: identifier
	     			| identifier TLSQUARE opt_number TRSQUARE
					| identifier TLSQUARE opt_number error
					{
						yyerrok;
						printError(NOSQUARE);	/* error - Missing square */
					}
					;
opt_number 			: TNUMBER
	     			|
					;
opt_stat_list 		: statement_list
		 			|
					;
statement_list 		: statement
		 			| statement_list statement
					;
statement 			: compound_st
	   				| expression_st
	   				| if_st
	   				| while_st
	   				| return_st
	   				;
expression_st 		: opt_expression TSEMICOLON
					;
opt_expression		: expression
		 			|
					;
if_st 				: TIF TLPAREN expression TRPAREN statement %prec TLOWERTHANELSE
					| TIF TLPAREN expression TRPAREN statement TELSE statement
					;
while_st 			: TWHILE TLPAREN expression TRPAREN statement
					;
return_st 			: TRETURN opt_expression TSEMICOLON
					| TRETURN opt_expression error
					{
						yyerrok;
						printError(NOSEMI);	/* error - Missing semicolon */
					}
					;
expression 			: assignment_exp
					;
assignment_exp 		: logical_or_exp
					| unary_exp TASSIGN assignment_exp
					| unary_exp TADDASSIGN assignment_exp
					| unary_exp TSUBASSIGN assignment_exp
					| unary_exp TMULASSIGN assignment_exp
					| unary_exp TDIVASSIGN assignment_exp
					| unary_exp TMODASSIGN assignment_exp
					;
logical_or_exp 		: logical_and_exp
					| logical_or_exp TOR logical_and_exp
					;
logical_and_exp 	: equality_exp
		 			| logical_and_exp TAND equality_exp
					;
equality_exp 		: relational_exp
					| equality_exp TEQUAL relational_exp
					| equality_exp TNOTEQU relational_exp
					;
relational_exp	 	: additive_exp
					| relational_exp TGREAT additive_exp
					| relational_exp TLESS additive_exp
					| relational_exp TGREATE additive_exp
					| relational_exp TLESSE additive_exp
					;
additive_exp 		: multiplicative_exp
					| additive_exp TADD multiplicative_exp
					| additive_exp TSUB multiplicative_exp
					;
multiplicative_exp 	: unary_exp
		    		| multiplicative_exp TMUL unary_exp
					| multiplicative_exp TDIV unary_exp
					| multiplicative_exp TMOD unary_exp
					;
unary_exp 			: postfix_exp
	   				| TSUB unary_exp
	   				| TNOT unary_exp
	   				| TINC unary_exp
	   				| TDEC unary_exp
					;
postfix_exp 		: primary_exp
	      			| postfix_exp TLSQUARE expression TRSQUARE
	      			| postfix_exp TLPAREN opt_actual_param TRPAREN
	      			| postfix_exp TINC
	      			| postfix_exp TDEC
					;
opt_actual_param 	: actual_param
		  			|
					;
actual_param 		: actual_param_list
					;
actual_param_list 	: assignment_exp
					| actual_param_list TCOMMA assignment_exp
					;
primary_exp 		: identifier
	     			| TNUMBER
	     			| TLPAREN expression TRPAREN
					;
identifier			: TIDENT
					;
%%

