/*
 * glob.h – global variable for the project
 * progrmmer – KIM-YEJI(2176082), SONG-CHAEWON(2076216), SHIN-JUNGHWA(2271035), YOON-HAYEONG(2071033)
 * date - 2024-05-31
 */

#ifndef GLOB_H
#define GLOB_H

int line_num; // line number
int cErrors; // number of errors

int stidx; // index of identifier in String Table

int type_int; // 1: type of identifier is integer
int type_void; // 1: type of identifier is void

unsigned long yyleng; // matched string
char* yytext; // length of matched string

/*enum identtypes {
    VSHSC, VSHARR, VINTSC, VINTARR, VLOSC, VLOARR, VLLSC, VLLARR,
    VUSSC, VUSARR, VUISC, VUIARR, VULOSC, VULOARR, VULLSC, VULLARR,
    VCSC, VCARR, VUCSC, VUCARR, VFLSC, VFLARR, VDSC, VDARR, VLDSC, VLDARR,
    FVOID, FSH, FINT, FL, FLL, FUS, FUI, FUL, FULL, FC, FUC, FF, FD, FLD,
    FPVOID, FPSH, FPINT, FPL, FPLL, FPUS, FPUI, FPUL, FPULL, FPC, FPUC, FPF, FPD, FPLD
};*/
enum identtypes {
    IINT, IVOID, IOTHER
};

/* todo : add parsing errors */
enum errortypes {
    TOOLONG, ILLIDENT, ILLCH, OVERST,
    WRONGDCL, WRONGFUNCDEF, NOSEMI, NOBRACE, NOSQUARE, NOPAREN
};

extern void symbolTable();

extern void printError(enum errortypes err);

#endif /* GLOB_H */
