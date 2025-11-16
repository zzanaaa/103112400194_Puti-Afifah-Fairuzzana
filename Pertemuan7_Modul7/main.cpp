#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    cout << "Hello world!" << endl;
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);

    cout << "Balik Stack :" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    // pushAscending
    cout << "Hello world!" << endl;
    CreateStack(S);

    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);

    printInfo(S);
    cout<<"balik stack"<<endl;

    balikStack(S);
    printInfo(S);
    cout << endl;

    // getInputStream
    cout << "Hello world!" << endl;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);

    cout << "Balik Stack :" << endl;
    
    balikStack(S);
    printInfo(S);

    return 0;
}
