/*
 * glob.h – global variable for the project
 * progrmmer – SHIN-JUNGHWA(2271035), KIM-YEJI(2176082), SONG-CHAEWON(2076216), YOON-HAYEONG(2071033)
 * date - 2024-05-30
 */

#ifndef GLOB_H
#define GLOB_H

#define STsize 1000 // size of string table 
#define HTsize 100 // size of hash table

extern int returntp; // 0:void, 1:int, 2:float
extern int type; // 0:int scalar, 1:int array, 2:float scalar, 3:float array, 4:function
extern int paramidx; // index of parameter array

extern int line_num; // line number
extern int cErrors; // number of errors

extern int stidx; // index of identifier in String Table

extern unsigned long yyleng; // matched string
extern char* yytext; // length of matched string

enum errorTypes { wrong_st, wrong_dcl, wrong_funcdef, nosemi, nobrace, nosquare, noparen,
				  illch, startwd, toolong, overst, wrong_op, wrong_cmp, wrong_asgn };
typedef enum errorTypes ERRORtypes;

typedef struct HTentry {
    int index; // index of identifier in ST
    struct HTentry* next; // pointer to next identifier
    int linenum;
    int tp;
    int rtp;
    int paramnum;
    int param[4];
} HTentry;

HTentry* HT[HTsize]; // Array of list head of hashtable 
char ST[STsize]; // Array of string table

extern void symbolTable();
extern void printHT();

HTentry* curid; // current identifier pointer
HTentry* preid; // previous identifier pointer

#endif /* GLOB_H */
