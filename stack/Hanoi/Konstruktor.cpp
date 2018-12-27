#include <iostream>
#include "Haniolist.h"
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iomanip>

using namespace std;

int pil,cak;
stk S1,S2,S3,A,B;
int lang=0;
int tow1,tow2;
bool k;

bool isEmptyStack(stk *S){
    if(S->top == 0){
        return true;
    }else{
        return false;
    }
}

void createStack(stk *S)
{
    S->top = NULL;
}

address Alokasi(infotype x)
{
    address q = new Stack();
    q->info=x;
    q->next=NULL;
    return q;
}

void push(stk *S,address p)
{
        if(isEmptyStack(S))
        {
            S->top = p;
        }
        else
        {
            p->next = S->top;
            S->top = p;
        }
}

address pop(stk *S)
{
    if (!isEmptyStack(S))
    {
        address p;
        p = S->top;
        S->top=p->next;
        p->next=NULL;
        return p;
    }
}

void printinfo(stk *S)
{
    if(isEmptyStack(S))
        cout<<"Kosong ";
    else
    {
        address p;
        p= S->top;
        while(p != NULL)
        {
            cout <<p->info<< " - ";
            p = p->next;
        }
    }
}

void createHanoi(Stack *S, int n)
{
        for(int i=n;i>=1;i--)
        {
            address p;
            p=Alokasi(i);
            push(S,p);
        }
}

bool Move (stk *A,stk *B)
{
    if ((((isEmptyStack(A)==false)&&(isEmptyStack(B)==true))) || ((isEmptyStack(A)==false) && (A->top->info < B->top->info)))
    {
        address p = pop(A);
        push(B,p);
        Sleep(200);
        return true;
    }
    else
        return false;
}

bool Isselesai(stk *S, int n)
{
    if(S->top!=NULL)
    {
        address p;
        p=S->top;
        address q;
        q=p->next;
        while ((p!=NULL)&&(q!=NULL))
        {
            if(p->info<q->info)
                return true;
            else
                return false;
            p=p->next;
            q=q->next;
        }
    }
    else
        return false;
}

void HanoiSolver(int n, char A,char B,char C)
{
    if(n==0)
    {
        cout<<"\n Move disk "<<n<<" from peg "<<A<<" to peg "<<B<<endl;
        lang++;
    }
    else
    {
        HanoiSolver(n-1, A, C,B);
        cout<<"\n Move disk "<<n<<" from peg "<<A<<" to peg "<<B<<endl;
        HanoiSolver(n-1,B,C,A);
        lang++;
    }


}

void menu()
{
    system("cls");
    cout<<"\nTower 1 : ";
    printinfo(&S1);
    cout<<"\nTower 2 : ";
    printinfo(&S2);
    cout<<"\nTower 3 : ";
    printinfo(&S3);
    cout<<"\n\n";
    cout<<setw(40)<<"Permainan Tower Hanoi"<<endl;
    cout<<setw(35)<<"Menu Utamanya"<<endl;
    cout<<setw(39)<<"1.Atur Ulang Permainan"<<endl;
    cout<<setw(32)<<"2.Pindah Cakram"<<endl;
    cout<<setw(32)<<"3.Cek Permainan"<<endl;
    cout<<setw(31)<<"4.Hanoi Solver"<<endl;
    cout<<setw(30)<<"5.Print Hanoi"<<endl;
    cout<<"\n";
    cout<<setw(30)<<"Pilih menu : ";
    cin>>pil;
    switch(pil)
    {
    case 1:
        {
            createStack(&S1);
            createStack(&S2);
            createStack(&S3);
            cout<<"Masukan Jumlah Cakram (1-5) : ";
            cin>>cak;
            createHanoi(&S1,cak);
            menu();
            break;
        }
    case 2:
        {
            cout<<"Masukan Tower  Tujuan Kalian (1-3) ke 1 : ";
            cin>>tow1;
            cout<<"Masukan Tower  Tujuan Kalian (1-3) ke 2 : ";
            cin>>tow2;
            if((tow1==1)&&(tow2==2))
                 k=Move(&S1,&S2);
            else if((tow1==1)&&(tow2==3))
                 k=Move(&S1,&S3);
            else if((tow1==2)&&(tow2==1))
                 k=Move(&S2,&S1);
            else if((tow1==2)&&(tow2==3))
                 k=Move(&S2,&S3);
            else if((tow1==3)&&(tow2==1))
                 k=Move(&S3,&S1);
            else if((tow1==3)&&(tow2==2))
                 k=Move(&S3,&S2);
            Sleep(200);
            menu();
            break;
        }
    case 3:
        {
            cout<<"cek Apakah Sudah Selesai"<<endl;
            if (!Isselesai(&S3,cak))
            {
                cout<<"Belum Selesai"<<endl;
            }
            else
                cout<<"selesai"<<endl;
            system("pause");
            menu();
            break;
        }
    case 4:
        {
            cout<<"cek Hanoi Kalian "<<endl;
            HanoiSolver(cak,'A','B','C');
            cout<<"Ada : "<<lang<<" Langkah"<<endl;
            system("pause");
            menu();
            break;
        }
    case 5:
        {
            cout<<"\nTower 1 : ";
            printinfo(&S1);
            cout<<"\nTower 2 : ";
            printinfo(&S2);
            cout<<"\nTower 3 : ";
            printinfo(&S3);
            cout<<endl;
            system("pause");
            menu();
            break;
        }
    default :
        break;
    }

}
