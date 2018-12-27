#include "graph.h"
#include <iostream>
using namespace std;

int main()
{
    Graph G;

    createGraph(&G);

    insertNode(&G, 'd');
    insertNode(&G, 'c');
    insertNode(&G, 'e');
    insertNode(&G, 'a');
    printGraph(G);

    adrNode N1, N2;
    N1 = findNode(G, 'a');
    cout << N1->info << endl;
    N2 = findNode(G, 'b');
    cout << N2 << endl;

    N1 = findNode(G, 'a');
    N2 = findNode(G, 'e');
    connectNode(N1, N2);
    printGraph(G);

    N1 = findNode(G, 'a');
    N2 = findNode(G, 'c');
    connectNode(N1, N2);
    N1 = findNode(G, 'd');
    N2 = findNode(G, 'e');
    connectNode(N1, N2);
    printGraph(G);

    N1 = findNode(G, 'a');
    N2 = findNode(G, 'e');
    disconnectNode(N1, N2);
    printGraph(G);

    createGraph(&G);

    insertNode(&G, 'd');
    insertNode(&G, 'c');
    insertNode(&G, 'e');
    insertNode(&G, 'a');

    printGraph(G);

    connectUndirected(G,'a','e');
    connectUndirected(G,'a','d');
    connectUndirected(G,'d','c');
    connectUndirected(G,'e','d');
    printGraph(G);

    disconnectUndirected( G,'a','d');
    printGraph(G);

    return 0;
}
