%{
/*
 * scanner.l - lexical analyzer for MiniC
 * progrmmer – SHIN-JUNGHWA(2271035), KIM-YEJI(2176082), SONG-CHAEWON(2076216), YOON-HAYEONG(2071033)
 * date - 2024-05-30
 */

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern printError(ERRORtypes err);
extern yyerror(char *s);
%}
L		[A-Za-z_]
D		[0-9]
%s CMT

%%
"const"		return(TCONST);
"else"		return(TELSE);
"if"		return(TIF);
"int"		return(TINT);
"float"		return(TFLOAT);
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

{L}({L}|{D})*		{
						if(yyleng > 12) return(TTOOLONG);
						else {
							symbolTable();
							return(TIDENT);
						}
					}

{D}+{L}({L}|{D})*   return(TSTARTWD);

{D}+				return(TNUMBER);
{D}+"."{D}+			return(TRNUMBER);

.			return(TILLCH);
%%

int yywrap() {
	return 1;
}
