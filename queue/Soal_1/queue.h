#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef struct data {
    string nama;
    char grade;
};

typedef struct elmqueue* address;
struct elmqueue {
    data info;
    address next;
};

struct queue{
    address head;
};

void createqueue(queue &q);
address alokasi(int d);
void add(queue &q, address p);
address del(queue &q);
void printinfo(queue *s);
void gradeinput(queue &qa, queue &qb);
void layaniantrian(queue &qa, queue &qb, char loket);
#endif // LIST_H_INCLUDED
