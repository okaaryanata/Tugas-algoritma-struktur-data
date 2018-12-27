#include <iostream>
#include "graph.h"
using namespace std;

void createGraph(Graph *G)
{
    G->first = Nil;
}

adrNode alokasiNode(infotype x)
{
    adrNode p = new Node();
    p->info = x;
    p->next = Nil;
    p->edge = Nil;
    return p;
}
adrEdge alokasiEdge(adrNode N)
{
    adrEdge p = new Edge();
    p->info = N;
    p->next = Nil;
    return p;
}
adrNode findNode(Graph G, infotype x)
{
    adrNode p = G.first;
    while (p != Nil)
    {
        if (p->info == x)
        {
            return p;
        }
        p = p->next;
    }
    return Nil;

}
void insertNode(Graph *G, infotype x)
{
    adrNode p = findNode(*G,x);
    if (p == Nil)
    {
        p = alokasiNode(x);
        p->next = G->first;
        G->first = p;
    }
    else
    {
        cout<<"data sudah ada";
    }
}
adrEdge cekEdge(adrNode asal, adrNode tujuan)
{
    adrEdge p = asal->edge;
    while (p != Nil)
    {
        if (((p->info)->info) == tujuan->info)
            return p;
        p = p->next;
    }
    return Nil;
}
void connectNode(adrNode asal, adrNode tujuan)
{
    if (cekEdge(asal,tujuan) == Nil)
    {
        adrEdge p = alokasiEdge(tujuan);
        p->next = asal->edge;
        asal->edge = p;
    }
}
void disconnectNode(adrNode asal, adrNode tujuan)
{
    adrEdge p = cekEdge(asal,tujuan);
    if (p != Nil)
    {
        if (p == asal->edge)
        {
            asal->edge = p->next;
            delete p;
        }
        else
        {
            adrEdge q = asal->edge;
            while (q->next != p)
                q = q->next;
            q->next = p->next;
            delete p;
        }
    }
}
void printGraph(Graph G)
{
    adrNode p = G.first;
    while (p != Nil)
    {
        cout << p->info << " -> ";
        if (p->edge != Nil);

            adrEdge r = p->edge;

        while (r != Nil)
        {
            cout << (r->info)->info << ", ";
            r = r->next;
        }
        p = p->next;
        cout << "\b\b " << endl;

    }
}
void connectUndirected(Graph G, infotype asal, infotype tujuan)
{
    adrNode p = findNode(G,asal);
    adrNode q = findNode(G,tujuan);
    if ((p != Nil)&&(q != Nil))
    {
        if ((cekEdge(p,q) == Nil)&&(cekEdge(q,p) == Nil))
        {
            connectNode(p,q);
            connectNode(q,p);
        }
    }
}
void disconnectUndirected(Graph G, infotype asal, infotype tujuan)
{
    adrNode p = findNode(G,asal);
    adrNode q = findNode(G,tujuan);
    if ((p != Nil)&&(q != Nil))
    {
        if ((cekEdge(p,q) != Nil)&&(cekEdge(q,p) != Nil))
        {
            disconnectNode(p,q);
            disconnectNode(q,p);
        }
    }
}
