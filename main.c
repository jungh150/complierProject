/*
 * main.c - parse the syntax, print errors, and print HT
 * programmer – KIM-YEJI(2176082), SONG-CHAEWON(2076216), SHIN-JUNGHWA(2271035), YOON-HAYEONG(2071033)
 * date – 2024-05-31
 */

#include <stdio.h>
#include "tn.h"

extern int yyparse();
extern void PrintHStable();

void main()
{
	printf("*** MiniC parsing beigns\n");
	yyparse();
	printf("Parsing ends. ***\n");

	PrintHStable();

	printf("2071033 YOON-HAYEONG\n");
	printf("2076216 SONG-CHAEWON\n");
	printf("2176082 KIM-YEJI\n");
	printf("2271035 SHIN-JUNGHWA\n");
}