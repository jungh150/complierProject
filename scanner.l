%{
/* scanner.l - lexical analyzer for MiniC
 * 
 * Programmer - 김예지(2176082), 송채원(2076216), 신정화(2271035), 윤하영(2071033)
 * 
 * data - 2024-05-22
 */

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

%}

%s CMT

%%
"const"		return(TCONST);
"else"		return(TELSE);
"if"		return(TIF);
"int"		return(TINT);
"return"	return(TRETURN);
"void"		return(TVOID);
"while"		return(TWHILE);

"+"			return(TADD);
"-"			return(TSUB);
"*"			return(TMUL);
"/"			return(TDIV);
"%"			return(TMOD);

"="			return(TASSIGN);
"+="		return(TADDASSIGN);
"-="		return(TSUBASSIGN);
"*="		return(TMULASSIGN);
"/="		return(TDIVASSIGN);
"%="		return(TMODASSIGN);

"!"			return(TNOT);
"&&"		return(TAND);
"||"		return(TOR);

"=="		return(TEQUAL);
"!="		return(TNOTEQU);
"<"			return(TLESS);
">"			return(TGREAT);
"<="		return(TLESSE);
">="		return(TGREATE);

"++"		return(TINC);
"--"		return(TDEC);

"("			return(TLPAREN);
")"			return(TRPAREN);
"{"			return(TLBRACE);
"}"			return(TRBRACE);

","			return(TCOMMA);
";"			return(TSEMICOLON);

[A-Za-z_][A-Za-z0-9_]*		{
								if(yyleng > 12)  ;
								else {
									symbolTable();
									return(TIDENT);
								}
							}
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TNUMBER);
"/*"([^*]|\*+[^*/])*\**"*"	;
"//".*	;      
[ \t]   ;
[\n]    {line_num++;}
.	return(yytext[0]);
%%

int yywrap() {
	return 1;
}