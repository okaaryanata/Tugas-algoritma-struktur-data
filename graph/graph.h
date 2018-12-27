#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define Nil NULL


typedef char infotype;

typedef struct Node *adrNode;
typedef struct Edge *adrEdge;

struct Node
{
    infotype info;
    adrNode next;
    adrEdge edge;
};

struct Edge
{
    adrNode info;
    adrEdge next;
};

struct Graph
{
    adrNode first;
};

void createGraph(Graph*);
adrNode alokasiNode(infotype);
adrEdge alokasiEdge(adrNode);
adrNode findNode(Graph, infotype);
void insertNode(Graph*, infotype);
adrEdge cekEdge(adrNode, adrNode);
void connectNode(adrNode, adrNode);
void disconnectNode(adrNode, adrNode);
void printGraph(Graph);
void connectUndirected(Graph, infotype, infotype);
void disconnectUndirected(Graph, infotype, infotype);



#endif // GRAPH_H_INCLUDED
