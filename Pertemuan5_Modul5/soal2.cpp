#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int nilai) {
    Node* nodeBaru = new Node{nilai, nullptr};
    if (!head) {
        head = nodeBaru;
    } else {
        Node* ptr = head;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = nodeBaru;
    }
}

Node* linearSearch(Node* head, int target) {
    Node* sekarang = head;
    int nomor = 1;
    cout << "\nProses Pencarian:\n";
    
    while (sekarang != nullptr) {
        cout << "Memeriksa node " << nomor << ": " << sekarang->data;
        
        if (sekarang->data == target) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return sekarang;
        } else {
            cout << " (tidak sama)\n";
        }
        
        sekarang = sekarang->next;
        nomor++;
    }
    
    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr;
}

void tampilkanList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data;
        if (ptr->next)
            cout << " -> ";
        ptr = ptr->next;
    }
    cout << " -> NULL\n";
}

int main() {
    Node* head = nullptr;
    cout << "LINEAR SEARCH PADA LINKED LIST\n";
    
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    tampilkanList(head);
    
    int nilai1;
    cout << "Mencari nilai: ";
    cin >> nilai1;
    Node* hasil1 = linearSearch(head, nilai1);
    
    if (hasil1) {
        cout << "\nHasil: Nilai " << nilai1 << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil1 << "\n";
        cout << "Data node: " << hasil1->data << "\n";
        if (hasil1->next)
            cout << "Node berikutnya: " << hasil1->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << nilai1 << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    int nilai2;
    cout << "Mencari nilai: ";
    cin >> nilai2;
    Node* hasil2 = linearSearch(head, nilai2);
    
    if (hasil2) {
        cout << "\nHasil: Nilai " << nilai2 << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil2 << "\n";
        cout << "Data node: " << hasil2->data << "\n";
        if (hasil2->next)
            cout << "Node berikutnya: " << hasil2->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << nilai2 << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    return 0;
}