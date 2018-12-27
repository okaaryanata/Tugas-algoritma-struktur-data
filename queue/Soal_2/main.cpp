#include "queue.h"

using namespace std;

int main()
{

    int pilih;
    queue qa,qb;
    char jalur;

    createqueue(qa);
    createqueue(qb);
    do {
    cout << "MENU" << endl;
    cout << "1. Input Data" << endl;
    cout << "2. View Data" << endl;
    cout << "3. Layani" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilih : "; cin>>pilih;
    switch (pilih) {
        case 1 :system("cls");
                gradeinput(qa, qb);
                getch();
                break;
        case 2 :system("cls");
                cout<<"Antrian Landing"<<endl;
                printinfo(&qa);
                cout<<endl;
                cout<<"Antrian Take off"<<endl;
                printinfo(&qb);
                getch();
                break;
        case 3 :system("cls");
                cout<<"Pilihan layanan antrian" << endl;
                cout<<"A untuk Landing" << endl;
                cout<<"B untuk Take Off" << endl;
                cout<<"Pilihan : "; cin>>jalur;
                layaniantrian(qa, qb, jalur);
                getch();
                break;
    }
    system("cls");
    } while (pilih != 0);
    return 0;
}
