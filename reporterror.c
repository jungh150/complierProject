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

extern enum errortypes err;

/*
* yyerror() - error 함수
*/
yyerror(char* s) {
    printf("%s\n", s);
}

void line() {
    printf("\t%d\t\t\t", line_num);
}


void printError(enum errortypes err)
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
    case ILLCH:
        line();
        printf("Illegal Character\n");
        break;
    case OVERST:
        line();
        printf("Over Flow\n");
        cErrors++;
        break;

        /* todo: handle parsing error */
    case WRONGDCL:
        line();
        printf("Wrong declaration\n");
        cErrors++;
        break;
    case WRONGFUNCDEF:
        line();
        printf("Over Flow\n");
        cErrors++;
        break;
    case NOSEMI:
        line();
        printf("Missing Semicolon\n");
        cErrors++;
        break;
    case NOBRACE:
        line();
        printf("Missing brace\n");
        cErrors++;
        break;
    case NOSQUARE:
        line();
        printf("Missing square bracket\n");
        cErrors++;
        break;
    case NOPAREN:
        line();
        printf("Missing parenthesis\n");
        cErrors++;
        break;
    }
}