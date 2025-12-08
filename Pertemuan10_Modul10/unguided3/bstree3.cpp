#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

typedef Node* address;

// Membuat node
address alokasi(int x) {
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}

// Pre-order: Root, Left, Right
void preOrder(address root) {
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order: Left, Right, Root
void postOrder(address root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

int main() {
    address root = NULL;
    root = alokasi(6);                 // root

    root->left = alokasi(4);           // 6 -> left  = 4
    root->right = alokasi(7);          // 6 -> right = 7

    root->left->left = alokasi(2);     // 4 -> left  = 2
    root->left->right = alokasi(5);    // 4 -> right = 5

    root->left->left->left = alokasi(1); // 2 -> left  = 1
    root->left->left->right = alokasi(3); // 2 -> right = 3

    cout << "Pre-Order traversal  : ";
    preOrder(root);
    cout << endl;

    cout << "Post-Order traversal : ";
    postOrder(root);
    cout << endl;

    return 0;
}