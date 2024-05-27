/*
 * glob.h – global variable for the project
 * progrmmer – KIM-YEJI(2176082), SONG-CHAEWON(2076216), SHIN-JUNGHWA(2271035), YOON-HAYEONG(2071033)
 * date - 2024-05-31
 */

#ifndef GLOB_H
#define GLOB_H

extern int line_num; // line number
extern int cErrors; // number of errors

extern int stidx; // index of identifier in String Table

extern unsigned long yyleng; // matched string
extern char* yytext; // length of matched string

enum identtypes {
    VSHSC, VSHARR, VINTSC, VINTARR, VLOSC, VLOARR, VLLSC, VLLARR,
    VUSSC, VUSARR, VUISC, VUIARR, VULOSC, VULOARR, VULLSC, VULLARR,
    VCSC, VCARR, VUCSC, VUCARR, VFLSC, VFLARR, VDSC, VDARR, VLDSC, VLDARR,
    FVOID, FSH, FINT, FL, FLL, FUS, FUI, FUL, FULL, FC, FUC, FF, FD, FLD,
    FPVOID, FPSH, FPINT, FPL, FPLL, FPUS, FPUI, FPUL, FPULL, FPC, FPUC, FPF, FPD, FPLD
};

void symbolTable();

#endif /* GLOB_H */