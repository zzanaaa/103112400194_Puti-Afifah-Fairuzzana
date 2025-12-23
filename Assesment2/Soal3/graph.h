#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoType;
struct Node;
struct Edge;
typedef Node* adrNode;
typedef Edge* adrEdge;
struct Edge {
    adrNode tujuan;
    adrEdge next;
};

struct Node {
    infoType info;
    bool aktif;          
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode createNode(infoType x);
void addNode(Graph &G, adrNode p);
void addEdge(Graph &G, infoType from, infoType to);
adrNode findNode(Graph G, infoType x);
void resetVisited(Graph &G);
void DFS(adrNode p);
bool isGraphConnectedAfterIgnore(Graph G, infoType ignoreNode);
void printGraph(Graph G);

#endif