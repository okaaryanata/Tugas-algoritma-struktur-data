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

    cout<<"Input Nama Pesawat: "; cin>>d.nama;
    cout<<"Input Jalur " << endl;
    cout << "A untuk Landing" << endl;
    cout << "B untuk Take OFF" << endl;
    cout << "pilihan         : "; cin>>d.kategori;

    if ((d.kategori == 'A') or (d.kategori == 'a')) {
        p=alokasi(d);
        add(qa, p);
    } else if ((d.kategori == 'B') or (d.kategori == 'b')) {
        p=alokasi(d);
        add(qb, p);
    } else {
        cout<<"pilihan tidak tersedia";
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
        cout<<"-------------------------"<<endl;
        f=f->next;
    }
}

void layaniantrian(queue &qa, queue &qb, char jalur) {
    address p;
    if ((jalur == 'A') or (jalur == 'a')) {
            if (qa.head != NULL) {
                p= del(qa);
                delete(p);
                cout<<"jalur "<<jalur<<" telah dilayani!"<<endl;
            } else {
                cout<<"Tak Ada Antrian";
            }

    } else if ((jalur == 'B') or (jalur == 'b')) {
            if (qb.head != NULL) {
                p= del(qb);
                delete(p);
                cout<<"jalur "<<jalur<<" telah dilayani!"<<endl;
            } else {
                cout<<"Tak Ada Antrian";
            }
    }
}
