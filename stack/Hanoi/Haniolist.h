#ifndef HANIOLIST_H_INCLUDED
#define HANIOLIST_H_INCLUDED

typedef int infotype;
typedef struct Stack *address;
typedef struct Stack
{
    infotype info;
    address next;
};

struct stk
{
    address top;
};

bool isEmptyStack(stk S);
void createStack(stk *S);
void push(stk *S,address p);
address pop(stk *S);
void printinfo(stk *S);
void createHanoi(stk *S, int n);
bool Move (stk *A,stk *B);
bool Isselesai(stk *S, int n);
void HanoiSolver(int n, stk *A,stk *B,stk *C);
address Alokasi(infotype x);
void menu();

#endif // HANIOLIST_H_INCLUDED
