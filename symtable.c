/*
 * symtable.c - 각 token에 대한 출력
 * programmer - KIM-YEJI(2176082), SONG-CHAEWON(2076216), SHIN-JUNGHWA(2271035), YOON-HAYEONG(2071033)
 * date - 2024-05-31
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "glob.h"
#include "tn.h"

#define STsize 1000 // size of string table 
#define HTsize 100 // size of hash table

#define FALSE 0
#define TRUE 1

#define MAX_ID_LEN 12 // maximum length for an identifier

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index; // index of identifier in ST
    enum identtypes type; // type of identifier
    int linenum; // line number of identifier defined
    HTpointer next; // pointer to next identifier 
} HTentry;

HTpointer HT[HTsize]; // Array of list head of hashtable 
char ST[STsize]; // Array of string table

int nextid = 0; // the current identifier
int nextfree = 0; // the next available index of ST

int hashcode; // hash code of identifier
int sameid;  // first index of identifier

int found; // for the previous ocurrence of a idntifier

int stidx = 0; // index of identifier in String Table


// Get Type of Identifier - return the detailed type of identifier
/*
char* GetTypeOfIdentifier(enum identtypes it) {
    switch (it) {
    case VSHSC: return "short scalar variable";
    case VSHARR: return "short array variable";
    case VINTSC: return "integer scalar variable";
    case VINTARR: return "integer array variable";
    case VLOSC: return "long scalar variable";
    case VLOARR: return "long array variable";
    case VLLSC: return "long long scalar variable";
    case VLLARR: return "long long array variable";
    case VUSSC: return "unsigned short scalar variable";
    case VUSARR: return "unsigned short array variable";
    case VUISC: return "unsigned integer scalar variable";
    case VUIARR: return "unsigned integer array variable";
    case VULOSC: return "unsigned long scalar variable";
    case VULOARR: return "unsigned long array variable";
    case VULLSC: return "unsigned long long scalar variable";
    case VULLARR: return "unsigned long long array variable";
    case VCSC: return "char scalar variable";
    case VCARR: return "char array variable";
    case VUCSC: return "unsigned char scalar variable";
    case VUCARR: return "unsigned char array variable";
    case VFLSC: return "float scalar variable";
    case VFLARR: return "float array variable";
    case VDSC: return "double scalar variable";
    case VDARR: return "double array variable";
    case VLDSC: return "long double scalar variable";
    case VLDARR: return "long double array variable";
    case FVOID: return "function name, return type = void";
    case FSH: return "function name, return type = short";
    case FINT: return "function name, return type = int";
    case FL: return "function name, return type = long";
    case FLL: return "function name, return type = long long";
    case FUS: return "function name, return type = unsigned short";
    case FUI: return "function name, return type = unsigned int";
    case FUL: return "function name, return type = unsigned long";
    case FULL: return "function name, return type = unsigned long long";
    case FC: return "function name, return type = char";
    case FUC: return "function name, return type = unsigned char";
    case FF: return "function name, return type = float";
    case FD: return "function name, return type = double";
    case FLD: return "function name, return type = long double";
    case FPVOID: return "function name, return type = void pointer";
    case FPSH: return "function name, return type = short pointer";
    case FPINT: return "function name, return type = int pointer";
    case FPL: return "function name, return type = long pointer";
    case FPLL: return "function name, return type = long long pointer";
    case FPUS: return "function name, return type = unsigned short pointer";
    case FPUI: return "function name, return type = unsigned int pointer";
    case FPUL: return "function name, return type = unsigned long pointer";
    case FPULL: return "function name, return type = unsigned long long pointer";
    case FPC: return "function name, return type = char pointer";
    case FPUC: return "function name, return type = unsigned char pointer";
    case FPF: return "function name, return type = float pointer";
    case FPD: return "function name, return type = double pointer";
    case FPLD: return "function name, return type = long double pointer";
    }
} */

char* GetTypeOfIdentifier(enum identtypes it) {
    switch (it)
    {
    case IINT:
        return "integer type";
    case IVOID:
        return "void type";
    case IOTHER:
        return "other type";
    }
}

// Print HStable - Print the hash table. Write out the hashcode and the list of identifiers
//                 associated with each hashcode, but only for non-empty list.
//                 Print out the number of characters used up in ST.
void PrintHStable() {
    int i, j;
    HTpointer here;

    printf("\n\n\n [[ HASH TABLE ]] \n\n");

    for (i = 0; i < HTsize; i++) {
        if (HT[i] != NULL) {
            printf("Hash Code %3d : ", i);
            for (here = HT[i]; here != NULL; here = here->next) {
                j = here->index;
                printf("(");
                while (ST[j] != '\0' && j < STsize) {
                    printf("%c", ST[j++]);
                }
                printf(": %s, line%d\n", GetTypeOfIdentifier(here->type), here->linenum);
                printf("                "); // if it has the same hash code then make blank
            }
            for (int k = 0; k < 16; k++) { // if it has the different has code then remove blank
                printf("\b");
            }
        }
    }
}

// Read ID - Read identifier from fileInput file and append it into the string table ST.
//           An identifier is a string of letters and digits, starting with a letter.
//           If first letter is digit, print out error message.
void ReadID() {
    // Check if the identifier fits within the string table
    if (nextfree + yyleng < STsize) {
        // Update indices
        nextid = nextfree;
        // Copy the identifier to the string table
        for (int i = 0; i < yyleng; i++) {
            ST[nextfree++] = yytext[i];
        }
    }
    else {
        isOverst = 1;
    }
}

// Compute HS - Compute the hash code of identifier by summing the ordinal values
//              of its characters and the taking the sum modulo the size of HT.
void ComputeHS(int nid, int nfree) {
    int code, i;
    code = 0; // sum of the ASCII codes of identifier
    for (i = nid; i < nfree - 1; i++) {
        code += (int)ST[i];
    }
    hashcode = code % HTsize; // (sum of ASCII codes) mod (hash table size) -> hashcode
}

// Lookup HS - For each identifier, look it up in the hash table for previous occurrence of
//             the identifier. If find a match, set the found flag as true. Otherwise false.
//             If find a match, save the starting index of ST in same id.
void LookupHS(int nid, int hscode) {
    HTpointer here;
    int i, j;
    found = FALSE; // if it already exists inf HT then TRUE, else FALSE

    // if the index of HT is not empty
    if (HT[hscode] != NULL) {
        here = HT[hscode];
        // check if the identifier already exists
        while (here != NULL && found == FALSE) {
            found = TRUE;
            i = here->index;
            j = nid; // first index of identifier
            sameid = i;
            // check if it is the same as identifier
            while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) { // compare each character
                if (ST[i] != ST[j])
                    found = FALSE;
                else {
                    i++;
                    j++;
                }
            }
            here = here->next; // move to next
        }
    }
}

// Add HT - Add a new identifier to the hash table.
//          If list head HT[hashcode] is null, simply add a list element with
//          starting index of the identifier in ST.
//          If list head HT[hashcode] is not null, add a new identifier to the head of the chain.
void AddHT(int hscode, enum identtypes it) {
    HTpointer ptr;

    ptr = (HTpointer)malloc(sizeof(ptr));
    ptr->index = nextid;
    ptr->linenum = line_num;
    ptr->type = it;
    ptr->next = HT[hscode];
    HT[hscode] = ptr;
}

// symbolTable - Read the identifier from the file and directly append it into ST.
//               Compute its hash code and look up the identifier in hash table HT[hashcode].
//               Update stidx(index in String Table).
void symbolTable() {
    ReadID(); // read identifier 
    ST[nextfree++] = '\0';

    ComputeHS(nextid, nextfree); // compute the hashcode of identifier -> hscode
    LookupHS(nextid, hashcode); // check if it already exists in hash table -> found, sameid

    if (!found) { // not already exist
        stidx = nextid;
        if (type_int) {
            AddHT(hashcode, IINT);
        }
        else if (type_void) {
            AddHT(hashcode, IVOID);
        }
        else {
            AddHT(hashcode, IOTHER);
        }
        
    }
    else { // already exist
        stidx = sameid;
        nextfree = nextid;
    }
}