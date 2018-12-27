#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#define nil NULL
typedef int infotype;

typedef struct elmtree* address;
struct elmtree
{
    infotype info;
    address right;
    address left;
};
typedef address tree;
void createtree(tree &t);
address alokasi(int x);
void tambah(tree &t,int x);
address FindElm(tree &t,int x);
void printinfo(tree &t);
address detree(address p,int x);
address deleft(address p,address q);
address deright(address p,address q);

#endif // TREE_H_INCLUDED
