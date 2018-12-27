#ifndef ADTQUEUE_H_INCLUDED
#define ADTQUEUE_H_INCLUDED

struct queue
{
    int data[100];
    int head;
    int tail;
};

void CreateQueue(queue *q);
int kosong(queue *q);
int penuh(queue *q);
void Enqueue(queue *q, int newdata);
int Dequeue(queue *q);
void reset(queue *q);
void Tampil(queue *q);



#endif // ADTQUEUE_H_INCLUDED
