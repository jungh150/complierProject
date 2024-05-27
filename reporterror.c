/*
* reporterror.c - print error
* Progammer - KIM-YEJI(2176082), SONG-CHAEWON(2076216), SHIN-JUNGHWA(2271035), YOON-HAYEONG(2071033)
* date - 2024-05-31
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern int yylex();
int cErrors = 0;

/*
* yyerror() - error 함수
*/
void yyerror(char* s) {
    printf("%s\n", s);
}

void line() {
    printf("\t%d\t\t\t", line_num);
}


void printError(ERRORtypes err)
{
    switch (err) {
    case TOOLONG:
        line();
        printf("Too long identifier: The maximum length of an identifier is 12\n");
        cErrors++;
        break;
    case ILLIDENT:
        line();
        printf("Illegal Identifier: Start with Digit\n");
        cErrors++;
        break;
    case TILLCH:
        line();
        printf("Illegal Character\n");
        break;
    case OVERST:
        line();
        printf("Over Flow\n");
        cErrors++;
        break;
    case wrong_st:
        break;
    case wrong_funcdef:
        break;
    default:
        break;

    /* todo: handle parsing error */
    }
}