/*
 * main.c – parse the syntax, print errors, and print Hash Table
 * progrmmer – SHIN-JUNGHWA(2271035), KIM-YEJI(2176082), SONG-CHAEWON(2076216), YOON-HAYEONG(2071033)
 * date - 2024-05-30
 */

#include <stdio.h>
#include "tn.h"
#include "glob.h"

extern int yyparse();
extern void printHT();
int line_num = 1;
int cErrors = 0;

void main()
{
	printf("*** MiniC Parsing begins\n");
	yyparse();
	printf("Parsing ends. ***\n");
	printf("\n%d error(s) detected\n", cErrors);

	printHT();
  
	printf("2071033 YOON-HAYEONG\n");
	printf("2076216 SONG-CHAEWON\n");
	printf("2176082 KIM-YEJI\n");
	printf("2271035 SHIN-JUNGHWA\n");
}
