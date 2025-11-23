#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = 0;
    Q.tail = 0;
}

bool isEmptyQueue(Queue Q){
    return (Q.tail == 0);
}

bool isFullQueue(Queue Q){
    return (Q.tail == MAX_QUEUE);
}

void enqueue(Queue &Q, infotype x){
    if (!isFullQueue(Q)) {             
        if (isEmptyQueue(Q)) {         
            Q.head = 1;
            Q.tail = 1;
            Q.info[0] = x;
        } else {
            Q.info[Q.tail] = x;        
            Q.tail++;                  
        }
    } else {
        cout << "Queue penuh" << endl;
    }
}

infotype dequeue(Queue &Q) {
    if (!isEmptyQueue(Q)) {
        infotype hasil = Q.info[0];

        for (int i = 0; i < Q.tail - 1; i++) {
            Q.info[i] = Q.info[i + 1];
        }

        Q.tail--;

        if (Q.tail == 0) {
            Q.head = 0;
        }

        return hasil;
    }

    cout << "Queue kosong" << endl;
    return -1;
}

void printInfo(Queue Q) {
    int H, T;

    if (isEmptyQueue(Q)) {
        H = -1;
        T = -1;
    } else {
        H = Q.head - 1;   
        T = Q.tail - 1;  
    }

    cout << H << "  -  " << T << "  |  ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = 0; i < Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}
