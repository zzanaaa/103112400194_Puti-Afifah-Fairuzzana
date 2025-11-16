#ifndef STACK_H
#define STACK_H

#define MaxEl 20
#define Nil -1

typedef int infotype;

typedef struct {
    infotype info[MaxEl];
    int top;
} Stack;

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// Prosedur untuk pushAscending
void pushAscending(Stack &S, int x);
// Prosedur untuk getInputStream
void getInputStream(Stack &S);

#endif