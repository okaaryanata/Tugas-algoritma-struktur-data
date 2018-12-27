#include "adtqueue.h"
#include <iostream>
using namespace std;

void CreateQueue(queue *q)
{
    q->head=q->tail=-1;
}

int kosong(queue *q)
{
    if ((q->head==-1)&&(q->tail==-1))
        return 1;
    else
        return 0;
}

int penuh(queue *q)
{
    if(q->tail==100-1)
        return 1;
    else
        return 0;
}

void Enqueue(queue *q, int newdata)
{
    if(kosong(q)==1)
    {
        q->head=q->tail=0;
        q->data[q->tail]=newdata;
    }
    else if(penuh(q)==0)
    {
        q->tail++;
        q->data[q->tail]=newdata;
    }
    else
    {
        cout << "Queue Penuh" << endl;
    }
}

int Dequeue(queue *q)
{
    int i;
    int e=q->data[q->head];

    if(kosong(q)==1)
    {
        cout << "Queue Kosong" << endl;
        return 0;
    }
    else
    {
        for(i=q->head; i<=(q->tail)-1; i++)
        {
            q->data[i]=q->data[i+1];
        }
        cout<<"Elemen yang keluar : "<< e;
        q->tail--;
        return e;
    }
}
void reset(queue *q)
{
    CreateQueue(q);
    cout<<"Data Sudah di Reset";
}

void Tampil(queue *q)
{
    if (kosong(q)==0)
    {
        cout << "HEAD=";
        for (int i=q->head; i<=q->tail; i++)
        {
            cout<<q->data[i]<<" -> ";
        }
        cout << "\b\b\b\b=TAIL";
    }
    else
    {
        cout<<"Queue Kosong"<<endl;
    }
}
