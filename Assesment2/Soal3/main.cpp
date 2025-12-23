#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    addNode(G, createNode('A'));
    addNode(G, createNode('B'));
    addNode(G, createNode('C'));
    addNode(G, createNode('D'));
    addNode(G, createNode('E'));

    addEdge(G, 'B', 'A'); 
    addEdge(G, 'B', 'C'); 
    addEdge(G, 'B', 'E'); 

    addEdge(G, 'A', 'B');
    addEdge(G, 'E', 'B');
    addEdge(G, 'C', 'B');
    addEdge(G, 'C', 'D');
    addEdge(G, 'D', 'C');

    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    printGraph(G);
    cout << endl;

    cout << "Analisis Kota Kritis (Single Point of Failure)" << endl;
    
    adrNode p = G.first;
    while (p != NULL) {
        if (!isGraphConnectedAfterIgnore(G, p->info)) {
            cout << "[PERINGATAN] Kota " << p->info << " adalah KOTA KRITIS!" << endl;
            cout << "-> Jika " << p->info << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "Kota " << p->info << " aman (redundansi oke)." << endl;
        }
        p = p->next;
    }

    return 0;
}