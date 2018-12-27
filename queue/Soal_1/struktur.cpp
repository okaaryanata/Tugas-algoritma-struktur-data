#include "queue.h"

using namespace std;
void createqueue(queue &q)
{
    q.head=NULL;
}

address alokasi(data d)
{
    address p=new elmqueue;
    p->info=d;
    p->next=NULL;
    return p;
}

void add(queue &q, address p)
{
    address f;
    f=q.head;
    if (q.head == NULL) {
        q.head=p;
    } else {
        while (f->next != NULL) {
            f=f->next;
        }
        f->next = p;
    }
}


void gradeinput(queue &qa, queue &qb) {
    data d;
    address p;

    cout<<"Input nama : "; cin>>d.nama;
    cout<<"Input loket (A/B) : "; cin>>d.grade;

    if ((d.grade == 'A') or (d.grade == 'a')) {
        p=alokasi(d);
        add(qa, p);
    } else if ((d.grade == 'B') or (d.grade == 'b')) {
        p=alokasi(d);
        add(qb, p);
    } else {
        cout<<"Loket tidak tersedia";
    }
}

address del(queue &q) {
    address f;
    f=q.head;
    q.head=f->next;
    f->next=NULL;
    return f;
}


void printinfo(queue *q) {
    address f;
    f=q->head;
    if (f == NULL) {
        cout<<"Tidak Ada Antrian"<<endl;
    }
    while (f != NULL) {
        cout<<"Nama  : "<<f->info.nama<<endl;
        cout<<"Grade : "<<f->info.grade<<endl;
        cout<<"-------------------------"<<endl;
        f=f->next;
    }
}

void layaniantrian(queue &qa, queue &qb, char loket) {
    address p;
    if ((loket == 'A') or (loket == 'a')) {
            if (qa.head != NULL) {
                p= del(qa);
                delete(p);
                cout<<"Loket "<<loket<<" telah dilayani!"<<endl;
            } else {
                cout<<"Tak Ada Antrian";
            }

    } else if ((loket == 'B') or (loket == 'b')) {
            if (qb.head != NULL) {
                p= del(qb);
                delete(p);
                cout<<"Loket "<<loket<<" telah dilayani!"<<endl;
            } else {
                cout<<"Tak Ada Antrian";
            }

    }

}
