#include "bst.h"

int main() {
    BST T;
    createTree(T);

    insertNode(T, newNode("Rizkina Azizah", 60, "Basic"));
    insertNode(T, newNode("Hakan Ismail", 50, "Bronze"));
    insertNode(T, newNode("Olivia Saevali", 65, "Silver"));
    insertNode(T, newNode("Felix Pedrosa", 47, "Gold"));
    insertNode(T, newNode("Gamel Al Ghifari", 56, "Platinum"));
    insertNode(T, newNode("Hanif Al Faiz", 70, "Basic"));
    insertNode(T, newNode("Mutiara Fauziah", 52, "Bronze"));
    insertNode(T, newNode("Davi Ilyas", 68, "Silver"));
    insertNode(T, newNode("Abdad Mubarok", 81, "Gold"));

    cout << "=== Traversal InOrder ===\n";
    inOrder(T.root);
    cout << endl << endl;

    cout << "Node MostLeft : " << mostLeft(T.root)->beratBadan << endl;
    cout << "Node MostRight : " << mostRight(T.root)->beratBadan << endl << endl;

    searchByBeratBadan(T, 70);

    return 0;
}