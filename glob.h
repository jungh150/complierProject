/*
 * glob.h – global variable for the project
 * progrmmer – 김예지(2176082), 송채원(2076216), 신정화(2271035), 윤하영(2071033)
 * date - 2024-04-29
 */

#ifndef GLOB_H
#define GLOB_H

extern int line_num; // line number
extern int cErrors; // number of errors

extern int stidx; // index of identifier in String Table

extern unsigned long yyleng; // matched string
extern char* yytext; // length of matched string

enum errorTypes { wrong_dcl, wrong_funcdef, nosemi, nobrace, nosquare, noparen,
				  illsp, illid, overst, toolong, noerror };
typedef enum errorTypes ERRORtypes;

extern void symbolTable();
extern void printHT();

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index; // index of identifier in ST
    HTpointer next; // pointer to next identifier 
    int linenum; // line number of identifier defined
    int type;
} HTentry;


HTpointer look_id;
HTpointer look_tmp;


#endif /* GLOB_H */