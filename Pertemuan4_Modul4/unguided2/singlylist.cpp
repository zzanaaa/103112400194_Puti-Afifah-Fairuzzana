#include "singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new Node;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
    }
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

void deleteFirst(List &L) {
    if (L.first != NULL) {
        address P = L.first;
        L.first = L.first->next;
        P->next = NULL;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            dealokasi(L.first);
            L.first = NULL;
        } else {
            address P = L.first;
            while (P->next->next != NULL) {
                P = P->next;
            }
            dealokasi(P->next);
            P->next = NULL;
        }
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
        dealokasi(P);
    } else {
        P = NULL;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != NULL) {
        deleteFirst(L);
    }
}
