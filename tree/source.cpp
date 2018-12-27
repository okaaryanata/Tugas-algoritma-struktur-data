#include <iostream>
#include "tree.h"
using namespace std;
void createtree(tree &t)
{
    t = NULL;
}
address alokasi(int x)
{
    elmtree *data= new elmtree();
    data->info = x;
    data->left= NULL;
    data->right= NULL;
    return data;
}
void tambah(tree &t,int x)
{
    if (t == NULL)
    {
        t = alokasi(x);
        cout<<"Data Added!\n";
    }
    else
    {
        if (x < (t)->info)
            tambah(t->left,x);
        else
        {
            if (x > (t)->info)
                tambah(t->right,x);
            else
            {
                if (x == (t)->info)
                    cout<<"Invalid Data!\n";
            }
        }
    }
}
address FindElm(tree &t,int x)
{
    if (t == NULL || t->info==x)
    {
        return t;
    }
    else
    {
        if(t->info>x)
        {
            FindElm(t->left,x);
        }
        else
        {
            FindElm(t->right,x);
        }
    }
}
void printinfo(tree &t)
{
    if (t!=NULL)
    {
        printinfo(t->left);
        cout <<t->info<<endl;
        printinfo(t->right);
    }
}
address detree(address p, int x)
{
    if(x < p->info)
    {
        p->left=detree(p->left,x);
    }
    else if(x>p->info)
    {
        p->right=detree(p->right,x);
    }
    else
    {
        if(p->left!=NULL)
        {
            p=deright(p,p->left);
        }
        else if(p->right!=NULL)
        {
            p=deleft(p,p->right);
        }
        else
        {
            delete(p);
            return NULL;
        }
    }
    return p;
}
address deright(address p, address q)
{
    while (q->right!=NULL)
    {
        q=q->right;
    }
    p->info=q->info;
    p->left=detree(p->left,q->info);
    return p;
}

address deleft(address p, address q)
{
    while (q->left!=NULL)
    {
        q=q->left;
    }
    p->info=q->info;
    p->right=detree(p->right,q->info);
    return p;
}
