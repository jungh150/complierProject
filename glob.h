#ifndef GLOB_H
#define GLOB_H

#include <stdio.h>

// 전역 변수
extern int line_number; // 라인 번호
extern int cErrors; // 오류 수
extern int cLine;
extern int nextid; // 심볼 테이블 인덱스
extern int nextfree; // 심볼 테이블에서의 다음 빈 공간
extern int yyleng;
char* yytext;

// 심볼 테이블 크기 정의
#define STsize 1000
#define HTsize 100

// 심볼 테이블 항목 구조체 정의
typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index; // 심볼 테이블에서의 인덱스
    HTpointer next; // 다음 항목을 가리키는 포인터
} HTentry;

// 전역 심볼 테이블 및 문자열 테이블
extern HTpointer HT[HTsize];
extern char ST[STsize];

// 심볼 테이블 관리 함수 선언
void ComputeHS(int nid, int nfree);
void LookupHS(int nid, int nfree);
void AddHT(int hscode);
void PrintHT();

enum errorTypes { wrong_st, wrong_funcdef, nosemi, nobrace, nobracket, tlong, toverflow };
typedef enum errorTypes ERRORtypes;
ERRORtypes err;

#endif // GLOB_H
