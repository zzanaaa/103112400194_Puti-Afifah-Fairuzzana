#include "bst.h"

void createTree(BST &T) {
    T.root = NULL;
}

bool isEmpty(BST T) {
    return T.root == NULL;
}

Node* newNode(string nama, float berat, string tier) {
    Node *p = new Node;
    p->namaMember = nama;
    p->beratBadan = berat;
    p->tierMember = tier;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(BST &T, Node *new_node) {
    if (isEmpty(T)) {
        T.root = new_node;
    } else {
        Node *curr = T.root;
        Node *parent = NULL;

        while (curr != NULL) {
            parent = curr;
            if (new_node->beratBadan < curr->beratBadan)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (new_node->beratBadan < parent->beratBadan)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->beratBadan << " - ";
        inOrder(root->right);
    }
}

Node* mostLeft(Node *root) {
    Node *curr = root;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node* mostRight(Node *root) {
    Node *curr = root;
    while (curr->right != NULL)
        curr = curr->right;
    return curr;
}

void searchByBeratBadan(BST T, float berat) {
    Node *curr = T.root;
    Node *parent = NULL;

    while (curr != NULL && curr->beratBadan != berat) {
        parent = curr;
        if (berat < curr->beratBadan)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    cout << "Data ditemukan didalam BST!\n";
    cout << "--- Data Node Yang Dicari ---\n";
    cout << "Nama Member : " << curr->namaMember << endl;
    cout << "Berat Badan : " << curr->beratBadan << endl;
    cout << "Tier Member : " << curr->tierMember << endl;

    cout << "----------------------------\n";
    cout << "--- Data Parent ---\n";
    if (parent != NULL) {
        cout << "Nama Member : " << parent->namaMember << endl;
        cout << "Berat Badan : " << parent->beratBadan << endl;
        cout << "Tier Member : " << parent->tierMember << endl;
    } else {
        cout << "Tidak Memiliki Parent\n";
    }

    cout << "----------------------------\n";
    if (parent != NULL) {
        if ((parent->left && parent->left != curr) ||
            (parent->right && parent->right != curr)) {
            cout << "Memiliki Sibling\n";
        } else {
            cout << "Tidak Memiliki Sibling\n";
        }
    }

    cout << "----------------------------\n";
    cout << "--- Data Child Kiri ---\n";
    if (curr->left != NULL) {
        cout << "Nama Member : " << curr->left->namaMember << endl;
        cout << "Berat Badan : " << curr->left->beratBadan << endl;
        cout << "Tier Member : " << curr->left->tierMember << endl;
    } else {
        cout << "NULL\n";
    }

    cout << "----------------------------\n";
    cout << "--- Data Child Kanan ---\n";
    if (curr->right != NULL) {
        cout << "Nama Member : " << curr->right->namaMember << endl;
        cout << "Berat Badan : " << curr->right->beratBadan << endl;
        cout << "Tier Member : " << curr->right->tierMember << endl;
    } else {
        cout << "NULL\n";
    }
}