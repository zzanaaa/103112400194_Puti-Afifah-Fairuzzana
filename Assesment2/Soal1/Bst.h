#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left;
    Node *right;
};

struct BST {
    Node *root;
};

void createTree(BST &T);
bool isEmpty(BST T);
Node* newNode(string nama, float berat, string tier);
void insertNode(BST &T, Node *new_node);
void inOrder(Node *root);
Node* mostLeft(Node *root);
Node* mostRight(Node *root);
void searchByBeratBadan(BST T, float berat);

#endif