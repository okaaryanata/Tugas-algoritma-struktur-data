#include "queue.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

bool isEmpty(queue &Q)
{
    if(Q.head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CreateQueue(queue &Q)
{
    Q.head = NULL;
    Q.tail = NULL;
}

address Alokasi (infotype info)
{
    address P = new elmqueue;
    if (P != NULL)
    {
        P -> info = info;
        P -> next = NULL;
    }
    else
    {
        cout << "Failed"<< endl;
    }
    return P;
}

void Add(queue &Q, address P)
{
    if (isEmpty(Q) == true)
    {
        Q.head = P;
        Q.tail = P;
    }
    else
    {
        address tmp = Q.head;
        while (tmp -> next != NULL)
        {
            tmp = tmp -> next;
        }
        tmp -> next = P;
        P -> next = NULL;
    }
}

int Del(queue &Q)
{
    address P;
    P = Q.head;
    int isi = Q.head -> info;
    cout << "Deleted: " << isi << endl;
    Q.head = Q.head -> next;
    P -> next = NULL;
    delete P;
    return isi;
}

void printInfo(queue &Q)
{
    address P;
    P = Q.head;
    while (P != NULL)
    if (isEmpty(Q) == true)
    {
        cout << "Empty" << endl;
    }
    else
    {
        while (P != NULL)
        {
            cout << P -> info << " ";
            P = P -> next;
        }
    }
    cout << endl;
}

void randomPelanggan (queue &Q, int n)
{
    int k = rand() % 4;
    if (k == 1)
    {
        address P;
        P = Alokasi(n);
        Add(Q,P);
    }
    else if (k == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            address P;
            P = Alokasi(n);
            Add(Q,P);
        }
    }
}

int layaniPelanggan(queue &Q, int n)
{
    if (isEmpty(Q) == true)
    {
        return -1;
    }
    else
    {
        int temp = Del(Q);
        return (n-temp);
    }
}

void simulasi(int total_menit)
{
    queue Q;
    CreateQueue(Q);
    int waktu_tunggu;
    int menit = 0;
    int total_dilayani = 0;
    int total_waktu_tunggu = 0;
    int waktu_tunggu_terlama = 0;
    float rata;

    while (menit < total_menit)
    {
        printInfo(Q);
        waktu_tunggu = layaniPelanggan(Q,menit);
        if (waktu_tunggu >= 0)
        {
            total_dilayani = total_dilayani + 1;
            total_waktu_tunggu = total_waktu_tunggu + waktu_tunggu;
            cout << "Total Waktu Tunggu : " << total_waktu_tunggu << endl;
            if (waktu_tunggu > waktu_tunggu_terlama)
            {
                waktu_tunggu_terlama = waktu_tunggu;
            }
        }
        randomPelanggan(Q,menit);
        menit = menit + 1;
    }
    rata = (float) total_menit/total_dilayani;
    cout << "Rata-rata Tunggu   : " << rata << " menit" << endl;
    cout << "Max Tunggu         : " << waktu_tunggu_terlama << endl;
}
