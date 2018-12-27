#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


typedef int infotype;

typedef struct elmqueue *address;

struct elmqueue
{
    infotype info;
    address next;
};

struct queue
{
    address head;
    address tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue &Q);
address Alokasi (infotype info);
void Add(queue &Q, address P);
int Del(queue &Q);
void printInfo(queue &Q);
void randomPelanggan (queue &Q, int n);
int layaniPelanggan(queue &Q, int n);
void simulasi(int total_menit);

#endif // QUEUE_H_INCLUDED
