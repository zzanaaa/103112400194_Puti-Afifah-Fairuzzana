#include "singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (P != NULL) {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    if (L.first == NULL) {
        cout << "List kosong" << endl;
    } else {
        address P = L.first;
        while (P != NULL) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}
