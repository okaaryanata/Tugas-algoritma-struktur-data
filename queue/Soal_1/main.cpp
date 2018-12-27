#include "queue.h"

using namespace std;

int main()
{

    int pilih;
    queue qa,qb;
    char loket;

    createqueue(qa);
    createqueue(qb);
    do {
    cout << "       MENU" << endl;
    cout << "1. INPUT ANTRIAN" << endl;
    cout << "2. VIEW ANTRIAN BERDASARKAN GRADE" << endl;
    cout << "3. LAYANI ANTRIAN" << endl;
    cout << "0.EXIT" << endl;
    cout << "PILIH : "; cin>>pilih;
    switch (pilih) {
        case 1 :system("cls");
                gradeinput(qa, qb);
                getch();
                break;
        case 2 :system("cls");
                cout<<"Antrian di Loket A"<<endl;
                printinfo(&qa);
                cout<<endl;
                cout<<"Antrian di Loket B"<<endl;
                printinfo(&qb);
                getch();
                break;
        case 3 :system("cls");
                cout<<"Loket (A/B) : "; cin>>loket;
                layaniantrian(qa, qb, loket);
                getch();
                break;
    }
    system("cls");
    } while (pilih != 0);
    return 0;
}
