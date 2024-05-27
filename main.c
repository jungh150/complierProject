#include <stdio.h>
#include tn.h
#include "global.h"

extern int yyparse();
void main()
{
	printf("start of parser\n");
	yyparse();
	printf("end of parser\n");

	//printHT();

	printf("2071033 YOON-HAYEONG\n");
	printf("2076216 SONG-CHAEWON\n");
	printf("2176082 KIM-YEJI\n");
	printf("2271035 SHIN-JUNGHWA\n");
}