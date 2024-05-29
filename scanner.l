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

extern void ComputeHS(int nid, int nfree);
extern void LookupHS(int nid, int nfree);
extern void AddHT(int hscode);
extern void PrintHT();
extern void yyerror(char *s);
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
"["			return(TLSQUARE);
"]"			return(TRSQUARE);
","			return(TCOMMA);
";"			return(TSEMICOLON);

\n      	line_num++;
[ \t]		;
"//".*		;
"/*"([^*]|\*+[^*/])*\**"*"	;

[A-Za-z_][A-Za-z0-9_]*		{
								if(yyleng > 12) return(TTOOLONG);
								else {
									symbolTable();
									return(TIDENT);
								}
							}

[0-9][A-Za-z_][A-Za-z0-9_]*	return(TILLIDENT);

[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TNUMBER);

.			return(TILLCH); //<- 이건 여기서 error 처리
%%

int yywrap() {
	return 1;
}