#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail < Q.head);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE -1);
}

void enqueue(Queue &Q, infotype x) {
    if(!isFullQueue(Q)) {
        Q.tail++;
        Q.info[Q.tail] = x;
    } else {
        cout << "Queue Penuh!" << endl;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if(!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        Q.head++;
        
        if (Q.head > Q.tail) {
            Q.head = 0;
            Q.tail = -1;
        }
    } else {
        cout << "Queue Kosong!" << endl;
    }
    return x;
}
void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << "\n";
}