%{
/* scanner.l - lexical analyzer for MiniC
 * 
 * Programmer - 
 * 
 * data - 2024-05-22
 */

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern ComputeHS(int nid, int nfree);
extern LookupHS(int nid, int nfree);
extern AddHT(int hscode);
extern PrintHT();
extern yyerror(char *s);

int i;
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

[A-Za-z_][A-Za-z0-9_]*		{
								if (nextfree >= STsize) {
									printf("\tError>> \tOVERFLOW!\n");
									PrintHT();
									exit(1);
								}
								nextid = nextfree;
								nextfree += (yyleng + 1);
								for (i = 0; i < yyleng; i++) {
									ST[nextid + i] = yytext[i];
								}

								ComputeHS(nextid, nextfree);
								LookupHS(nextid, hashcode);

								if (!found) {
									AddHT(hashcode);
								}
								else {
									for (i = nextid; i < nextfree - 1; i++) {
										ST[i] = '\0';
									}
									nextfree = nextid;
								}
								return(TIDEN);
}
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TNUMBER);
"/*"([^*]|\*+[^*/])*\**"*"	;
"//".*	;
[ \t\n] ;
.	return(yytext[0]);
%%

int yywrap() {
	return 1;
}