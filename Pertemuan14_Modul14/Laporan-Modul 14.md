# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH</h1>
<p align="center">Puti Afifah Fairuzzana - 103112400194</p>

## Dasar Teori
Linked  listadalahsuatu  bentuk  struktur data  yang berupa  sekumpulan  elemen data yang bertipe sama dimana tiap elemen saling berkaitan atau dihubungkan dengan elemen lain melalui suatu pointer. [1]

### A. Graph <br/>
Graph adalah jenis struktur data umum yang data dalam graph tidak terletak secara berdekatan satu sama lain, artinya data disusun secara non-linier. Graph terdiri dari sekelompok simpul yang digunakan untuk menyimpan data, dan antara dua simpul terdapat hubungan yang saling terkait. Berdasarkan arah penjelajahan, graph dibagi menjadi dua jenis yaitu graph tak berarah dan graph berarah [2]

## Guided 

### 1. Soal Guided 1

file graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
  adrNode first;
};
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);
#endif
```

file graph_edge.cpp
```C++
#include "graph.h"
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while(P != NULL){
        if(P->info == X){
            P = P -> next;
        }
        return NULL;
    }
}
void connectNode(Graph &G, infoGraph start, infoGraph end){
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);
    if(pStart != NULL && pEnd != NULL){
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;//insert first di list edge
        pStart->firstEdge = newEdge;
    }
    
}
```

file graph_init.cpp
```C++
#include "graph.h"
void createGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void insertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;

    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
```
file graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node" << P->info << "Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

```

file main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;
int main(){
    Graph G;
    createGraph(G);

    insertNode(G, 'A');//nambah node A,B,C,D
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    //hubungkan node g edge
    connectNode(G,'A','B'); // A ke B
    connectNode(G,'A','C'); // A ke C
    connectNode(G, 'B','D'); // B ke D
    connectNode(G, 'C','D'); // C ke D

    cout << "Isi graph :" << endl;
    printGraph(G);

}
```
Guided 1 Program ini membuat graph berarah menggunakan linked list sebagai adjacency list. Node disimpan dalam graph, sedangkan edge menyatakan hubungan antar node. Program menginisialisasi graph, menambahkan node A, B, C, dan D, menghubungkannya sesuai relasi yang ditentukan, lalu menampilkan isi graph.

## Unguided 

### 1. Soal Unguided 1

file graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;

typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode AllocateNode(infoGraph X);
adrNode FindNode(Graph G, infoGraph X);

// DFS & BFS
void PrintDFS(Graph &G, adrNode N);
void PrintBFS(Graph &G, adrNode N);
void Visited(Graph &G);

#endif
```

file graph.cpp
```C++
#include "graph.h"
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q -> next = P;
    }
}    

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node" << P->info << " ke : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void Visited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

// DFS
void PrintDFS(Graph &G, adrNode N) {
    if (N != NULL && N->visited == 1)
        return;

    cout << N->info << " ";
    N->visited = 1;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->node);
        E = E->next;
    }
}


// BFS
void PrintBFS(Graph &G, adrNode N) {
    queue<adrNode> Q;

    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}
```

file main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    PrintInfoGraph(G);

    cout << endl << "Hasil penelusuran DFS : ";
    Visited(G);
    PrintDFS(G, A);

    cout << endl << "Hasil penelusuran BFS : ";
    Visited(G);
    PrintBFS(G, A);

    return 0;
}
```
### Output Unguided 1 :

##### Menampilkan setiap node beserta node-node lain yang terhubung (PrintInfoGraph)
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan14_Modul14//output1-unguided-modul14.png)

##### Hasil penelusuran DFS.
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan14_Modul14//output2-unguided-modul14.png)

##### Hasil penelusuran BFS.
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan14_Modul14//output3-unguided-modul14.png)

Program ini mengimplementasikan struktur data graph tak berarah menggunakan linked list sebagai adjacency list. Graph diawali dengan pembuatan graph kosong, kemudian ditambahkan node A sampai H. Setiap node dihubungkan satu sama lain sesuai relasi yang telah ditentukan sehingga membentuk sebuah graph. Program menampilkan hubungan antar node untuk menunjukkan struktur graph yang terbentuk. Setelah itu, program melakukan penelusuran Depth First Search (DFS) yang menelusuri graph secara mendalam dan Breadth First Search (BFS) yang menelusuri graph secara melebar menggunakan antrian, dengan status kunjungan node direset sebelum setiap proses penelusuran.

## Kesimpulan
Modul ini membahas struktur data Graph yang terdiri dari node dan edge, baik graph berarah maupun tidak berarah. Representasi graph dijelaskan melalui matriks ketetanggaan dan multilist berbasis pointer. Modul ini juga membahas Topological Sort serta algoritma penelusuran BFS dan DFS, dan membimbing implementasi ADT graph secara dinamis menggunakan pointer.

## Referensi
[1] Johnson Sihombing. (2019). Penerapan stack dan queue pada array dan linked list dalam Java. INFOKOM (Informatika & Komputer), 7(2), 15–24. Diambil dari: https://journal.piksi.ac.id/index.php/INFOKOM/article/view/160 <br>
[2] Trivusi. (2022, September 16). Struktur data graph: Pengertian, jenis, dan kegunaannya. Trivusi <br>
