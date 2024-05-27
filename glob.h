#ifndef GLOB_H
#define GLOB_H

#include <stdio.h>

// ���� ����
extern int line_number; // ���� ��ȣ
extern int cErrors; // ���� ��
extern int cLine;
extern int nextid; // �ɺ� ���̺� �ε���
extern int nextfree; // �ɺ� ���̺����� ���� �� ����

// �ɺ� ���̺� ũ�� ����
#define STsize 1000
#define HTsize 100

// �ɺ� ���̺� �׸� ����ü ����
typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index; // �ɺ� ���̺����� �ε���
    HTpointer next; // ���� �׸��� ����Ű�� ������
} HTentry;

// ���� �ɺ� ���̺� �� ���ڿ� ���̺�
extern HTpointer HT[HTsize];
extern char ST[STsize];

// �ɺ� ���̺� ���� �Լ� ����
void ComputeHS(int nid, int nfree);
void LookupHS(int nid, int nfree);
void AddHT(int hscode);
void PrintHT();

enum errorTypes { wrong_st, wrong_funcdef, nosemi, nobrace, nobracket, tlong, toverflow };
typedef enum errorTypes ERRORtypes;
ERRORtypes err;

#endif // GLOB_H
