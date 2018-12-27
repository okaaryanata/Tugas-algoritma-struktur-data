#include <iostream>
#include "adtqueue.h"
#include <cstdio>
#include <cstdlib>
#include <conio.h>
using namespace std;

int main()
{
    int pil;
    int newdata;
    queue q;

    CreateQueue(&q);

    do
    {
        system("cls");
        cout << "======== MENU ========"<<endl;
        cout << "  1. Enqueue" << endl;
        cout << "  2. Dequeue" << endl;
        cout << "  3. Tampil" << endl;
        cout << "  4. Reset" << endl;
        cout << "  5. Keluar" << endl;
        cout << "======================" << endl;
        cout << "Masukkan Pilihan Anda : ";
        cin>>pil;

        switch(pil)
        {
        case 1:
        {
            cout<< endl << "Masukan Data : ";
            cin >> newdata;
            Enqueue(&q, newdata);
            cout << endl;
            system("pause");
            break;
        }

        case 2:
        {
            cout << endl;
            Dequeue(&q);
            cout << endl << endl;
            system("pause");
            break;
        }

        case 3:
        {
            cout << endl;
            Tampil(&q);
            cout << endl << endl;
            system("pause");
            break;
        }

        case 4:
        {
            cout << endl;
            reset(&q);
            cout << endl << endl;
            system("pause");
            break;
        }

        case 5:
        {
            system("cls");
            system("pause");
            break;
        }

        }
    }
    while(pil!=5);
}
