#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "tree.h"
using namespace std;

int main()
{
    tree t;
    address p;
    createtree(t);
    int pil;
    int bil;
    do
    {
        cout<<"Data : "<<endl;
        printinfo(t);
        cout<<"\n    MENU     "<<endl;
        cout<<"============="<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Find Element"<<endl;
        cout<<"3.Delete"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter : ";
        cin>>pil;
        switch (pil)
        {
        case 1 :
            system("cls");
            cout <<"Enter Data : ";
            cin >> bil;
            p=FindElm(t,bil);
            tambah(t,bil);
            getch();
            break;
        case 2 :
            system("cls");
            cout<< "Enter Data : ";
            cin >> bil;
            p=FindElm(t,bil);
            if (p==nil)
            {
                cout <<"Invalid Data"<< endl;
            }
            else if (p->info==bil)
            {
                cout << "Data Found ! " << endl;
                cout <<p->info << endl;
            }
            getch();
            break;
        case 3 :
            system("cls");
            cout<< "Enter Data : ";
            cin >> bil;
            p=FindElm(t,bil);
            if (p==nil)
            {
                cout << "No Data Found \n";
            }
            else if(p->info == bil)
            {
                detree(t,bil);
                cout << "Data Deleted\n";
            }
            getch();
            break;
        }
    }
    while (pil != 4);
    return 0;
}
