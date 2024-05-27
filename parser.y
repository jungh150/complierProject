%{
/*
 * parser.y - yacc source for the MiniC
 * 
 * Programmer - 김예지(2176082), 송채원(2076216), 신정화(2271035), 윤하영(2071033)
 *
 * date - 2024/5/31
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "glob.h"

int type_int = 0;
int type_void = 0;
enum identtypes type;

void line(int);
extern void printError();
extern int yylex();
extern void yyerror(const char *s);


%}

%token TIDENT TNUMBER TCONST TELSE TIF TINT TRETURN TVOID TWHILE
%token TADD TSUB TMUL TDIV TMOD 
%token TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TOR TAND TEQUAL TNOTEQU TGREAT TLESS TGREATE TLESSE
%token TINC TDEC TCOMMA TSEMICOLON
%token TLPAREN TRPAREN TLBRACKET TRBRACKET TLBRACE TRBRACE
%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE

%%
mini_c              : translation_unit            
                    ;
translation_unit    : external_dcl                
                    | translation_unit external_dcl
                    ;
external_dcl        : function_def                
                    | declaration                
                    | TIDENT TSEMICOLON
                    | TIDENT error
                    {
                        yyerrok;
                        /*printError(wrong_st);*/    /* error - wrong statement */
                    }
                    ;
function_def        : function_header compound_st        
                    | function_header TSEMICOLON
                    | function_header error         /* 비정상적인 함수 정의 */
                    {
                        /* 에러 발생 시 type 수정을 위해 default값 0 세팅 */
                        /* identifier about parse error */
                        yyerrok;
                        /* error - wrong function definition */
                        /* printError(wrong_funcdef);*/
                    }
                    ;
function_header     : dcl_spec function_name formal_param
                    ;
dcl_spec            : dcl_specifiers
                    ;        
dcl_specifiers      : dcl_specifier            
                    | dcl_specifiers dcl_specifier    
                    ;
dcl_specifier       : type_qualifier
                    | type_specifier
                    ;
type_qualifier      : TCONST { type = 1; }
                    ;
type_specifier      : TINT  {type_int=1;}    /* type: integer */
                    | TVOID {type_void=1;}   /* type: void */
function_name       : TIDENT                    
                    ;
formal_param        : TLPAREN opt_formal_param TRPAREN
                    ;
opt_formal_param    : formal_param_list
                    |
                    ;
formal_param_list   : param_dcl    
                    | formal_param_list TCOMMA param_dcl
                    ;

/* 아래는 참고자료에 없는 부분으로, parser_book.y에 있는 코드 semantic만 지우고 그대로 가져옴 */

param_dcl           : dcl_spec declarator
                    ;
compound_st         : TLBRACE opt_dcl_list opt_stat_list TRBRACE
                    ;
opt_dcl_list        : declaration_list
                    |                    
                    ;
declaration_list    : declaration
                    | declaration_list declaration 
                    ;
declaration         : dcl_spec init_dcl_list TSEMICOLON   
                    ;     
init_dcl_list       : init_declarator            
                    | init_dcl_list TCOMMA init_declarator  
                    ;   
init_declarator     : declarator                    
                    | declarator TASSIGN TNUMBER      
                    ;  
declarator          : TIDENT                    
                    | TIDENT TLBRACKET opt_number TRBRACKET    
                    ;    
opt_number          : TNUMBER  {type = 3}              
                    |                    
                    ;
opt_stat_list       : statement_list            
                    |
                    ;
statement_list      : statement                
                    | statement_list statement  
                    ;   
statement           : compound_st            
                    | expression_st            
                    | if_st                    
                    | while_st                
                    | return_st                
                    ;
expression_st       : opt_expression TSEMICOLON   
                    ;         
opt_expression      : expression            
                    |                   
                    ; 
if_st               : TIF TLPAREN expression TRPAREN statement %prec LOWER_THAN_ELSE
                    | TIF TLPAREN expression TRPAREN statement TELSE statement     
                    ;  
while_st            : TWHILE TLPAREN expression TRPAREN statement     
                    ;
return_st           : TRETURN opt_expression TSEMICOLON 
                    ;       
expression          : assignment_exp            
                    ;
assignment_exp      : logical_or_exp            
                    | unary_exp TASSIGN assignment_exp         
                    | unary_exp TADDASSIGN assignment_exp     
                    | unary_exp TSUBASSIGN assignment_exp     
                    | unary_exp TMULASSIGN assignment_exp     
                    | unary_exp TDIVASSIGN assignment_exp     
                    | unary_exp TMODASSIGN assignment_exp     
                    ;
logical_or_exp      : logical_and_exp            
                    | logical_or_exp TOR logical_and_exp 
                    ;    
logical_and_exp     : equality_exp                
                    | logical_and_exp TAND equality_exp 
                    ;
equality_exp        : relational_exp            
                    | equality_exp TEQUAL relational_exp     
                    | equality_exp TNOTEQU relational_exp
                    ; 
relational_exp      : additive_exp             
                    | relational_exp TGREAT additive_exp 
                    | relational_exp TLESS additive_exp     
                    | relational_exp TGREATE additive_exp 
                    | relational_exp TLESSE additive_exp   
                    ;  
additive_exp        : multiplicative_exp            
                    | additive_exp TADD multiplicative_exp     
                    | additive_exp TSUB multiplicative_exp    
                    ; 
multiplicative_exp  : unary_exp                
                    | multiplicative_exp TMUL unary_exp     
                    | multiplicative_exp TDIV unary_exp 
                    | multiplicative_exp TMOD unary_exp    
                    ; 
unary_exp           : postfix_exp                
                    | TSUB unary_exp                
                    | TNOT unary_exp                
                    | TINC unary_exp            
                    | TDEC unary_exp           
                    ; 
postfix_exp         : primary_exp                
                    | postfix_exp TLBRACKET expression TRBRACKET     
                    | postfix_exp TLPAREN opt_actual_param TRPAREN     
                    | postfix_exp TINC            
                    | postfix_exp TDEC       
                    ;     
opt_actual_param    : actual_param                
                    |                
                    ;    
actual_param        : actual_param_list   
                    ;         
actual_param_list   : assignment_exp            
                    | actual_param_list TCOMMA assignment_exp  
                    ;   
primary_exp         : TIDENT                
                    | TNUMBER                
                    | TLPAREN expression TRPAREN     
                    ;       
%%
