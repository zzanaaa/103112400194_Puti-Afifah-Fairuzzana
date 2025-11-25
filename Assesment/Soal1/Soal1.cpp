#include <iostream>
#include <string>
using namespace std;


struct Node {
    string namaMhs;
    Node* next;
};

Node* head = nullptr;


void insertAkhir(string namaMhs) {
    Node* baru = new Node();
    baru->namaMhs = namaMhs;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}


void deleteNama(string namaMhs) {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    
    if (head->namaMhs == namaMhs) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << namaMhs << " dihapus.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->namaMhs != namaMhs) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << namaMhs << " tidak ditemukan.\n";
    } else {
        Node* hapus = temp->next;
        temp->next = temp->next->next;
        delete hapus;
        cout << namaMhs << " dihapus.\n";
    }
}


void viewList() {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->namaMhs << " ";
        temp = temp->next;
    }
    cout << endl;
}


void hitungGenap() {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    int count = 0;


    while (temp != nullptr) {
        if (temp->namaMhs.length() % 2 == 0) {
            cout << temp->namaMhs << " ";
            count++;
        }
        temp = temp->next;
    }

    cout << "\nJumlah nama dengan hurus ganap: " << count << endl;
}


int main() {
    int pilih;
    string namaMhs;

    do {
        cout << "Menu: 1. Insert ,2 delete, 3 view, 4 hitung huruf genap\n";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> namaMhs;
                insertAkhir(namaMhs);
                break;

            case 2:
                cout << "Masukkan nama untuk delete: ";
                cin >> namaMhs;
                deleteNama(namaMhs);
                break;

            case 3:
                viewList();
                break;

            case 4:
                hitungGenap();
                break;

            case 0:
                cout << "Selesai...\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 0);

    return 0;
}