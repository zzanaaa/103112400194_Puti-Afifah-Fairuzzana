#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode createNode(infoType x) {
    adrNode p = new Node;
    p->info = x;
    p->aktif = true;
    p->visited = false;
    p->firstEdge = NULL;
    p->next = NULL;
    return p;
}

void addNode(Graph &G, adrNode p) {
    if (G.first == NULL) {
        G.first = p;
    } else {
        adrNode q = G.first;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

adrNode findNode(Graph G, infoType x) {
    adrNode p = G.first;
    while (p != NULL) {
        if (p->info == x)
            return p;
        p = p->next;
    }
    return NULL;
}

void addEdge(Graph &G, infoType from, infoType to) {
    adrNode pFrom = findNode(G, from);
    adrNode pTo   = findNode(G, to);
    if (pFrom != NULL && pTo != NULL) {
        adrEdge e = new Edge;
        e->tujuan = pTo;
        e->next = pFrom->firstEdge;
        pFrom->firstEdge = e;
    }
}

void resetVisited(Graph &G) {
    adrNode p = G.first;
    while (p != NULL) {
        p->visited = false;
        p = p->next;
    }
}

void DFS(adrNode p) {
    if (p == NULL || !p->aktif || p->visited)
        return;
    p->visited = true;
    adrEdge e = p->firstEdge;
    while (e != NULL) {
        DFS(e->tujuan);
        e = e->next;
    }
}

bool isGraphConnectedAfterIgnore(Graph G, infoType ignoreNode) {
    adrNode p = G.first;
    while (p != NULL) {
        if (p->info == ignoreNode)
            p->aktif = false;
        p = p->next;
    }
    resetVisited(G);
    adrNode start = NULL;
    p = G.first;
    while (p != NULL && start == NULL) {
        if (p->aktif)
            start = p;
        p = p->next;
    }
    DFS(start);
    bool connected = true;
    p = G.first;
    while (p != NULL) {
        if (p->aktif && !p->visited) {
            connected = false;
            break;
        }
        p = p->next;
    }

    p = G.first;
    while (p != NULL) {
        p->aktif = true;
        p = p->next;
    }

    return connected;
}

void printGraph(Graph G) {
    adrNode p = G.first;
    while (p != NULL) {
        cout << "Node " << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->tujuan->info << " ";
            e = e->next;
        }
        cout << endl;
        p = p->next;
    }
}