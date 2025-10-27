#include <iostream>
using namespace std;

// Definisi node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menampilkan linked list
void displayList(Node* head) {
    if (!head) {
        cout << "Linked list kosong\n";
        return;
    }
    
    cout << "Linked List yang dibuat: ";
    
    Node* ptr = head;
    while (ptr) {
        cout << ptr->data;
        if (ptr->next) {
            cout << " -> ";
        }
        ptr = ptr->next;
    }
    cout << " -> NULL\n";
}

// Implementasi Binary Search pada Linked List
Node* binarySearch(Node* head, int target) {
    cout << "\nProses Pencarian:\n";
    
    // Hitung ukuran linked list
    int panjang = 0;
    for (Node* ptr = head; ptr; ptr = ptr->next) {
        panjang++;
    }
    
    Node* awal = head;
    int langkah = 1;
    
    while (panjang > 0) {
        int tengah = panjang / 2;
        Node* nodeTengah = awal;
        
        // Pindah ke node tengah
        for (int i = 0; i < tengah; i++) {
            nodeTengah = nodeTengah->next;
        }
        
        // Cek apakah data ditemukan
        if (nodeTengah->data == target) {
            cout << "Iterasi " << langkah << ": Mid = " << nodeTengah->data 
                 << " (indeks tengah) - DITEMUKAN!\n";
            return nodeTengah;
        }
        
        // Jika data nodeTengah lebih kecil dari target, cari di bagian kanan
        if (nodeTengah->data < target) {
            cout << "Iterasi " << langkah << ": Mid = " << nodeTengah->data 
                 << " (indeks tengah) -> Cari di bagian kanan\n";
            
            int ukuranBaru = panjang - tengah - 1;
            
            if (ukuranBaru == 1) {
                Node* nodeAkhir = nodeTengah->next;
                if (nodeAkhir && nodeAkhir->data == target) {
                    return nodeAkhir;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            awal = nodeTengah->next;
            panjang = ukuranBaru;
            
            if (panjang <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
        // Jika data nodeTengah lebih besar dari target, cari di bagian kiri
        else {
            cout << "Iterasi " << langkah << ": Mid = " << nodeTengah->data 
                 << " (indeks tengah) -> Cari di bagian kiri\n";
            
            if (tengah == 1) {
                if (awal->data == target) {
                    return awal;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            panjang = tengah;
            
            if (panjang <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
        
        langkah++;
    }
    
    cout << "Tidak ada elemen tersisa\n";
    return nullptr;
}

// Prosedur untuk menambah node di akhir
void append(Node*& head, int nilai) {
    Node* nodeBaru = new Node{nilai, nullptr};
    
    if (!head) {
        head = nodeBaru;
    } else {
        Node* ptr = head;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = nodeBaru;
    }
}

// Fungsi untuk membersihkan memori
void deleteList(Node*& head) {
    while (head) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
}

int main() {
    Node* head = nullptr;
    int cari;
    
    cout << "BINARY SEARCH PADA LINKED LIST\n";
    
    // Membuat linked list dengan data terurut
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    // Tampilkan isi linked list
    displayList(head);
    
    // Pencarian pertama
    cout << "Mencari nilai: ";
    cin >> cari;
    
    Node* hasil = binarySearch(head, cari);
    
    if (hasil) {
        cout << "\nHasil: Nilai " << hasil->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil << "\n";
        cout << "Data node: " << hasil->data << "\n";
        if (hasil->next) {
            cout << "Node berikutnya: " << hasil->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    // Pencarian kedua
    cout << "Mencari nilai: ";
    cin >> cari;
    
    hasil = binarySearch(head, cari);
    
    if (hasil) {
        cout << "\nHasil: Nilai " << hasil->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil << "\n";
        cout << "Data node: " << hasil->data << "\n";
        if (hasil->next) {
            cout << "Node berikutnya: " << hasil->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    deleteList(head);
    
    return 0;
}