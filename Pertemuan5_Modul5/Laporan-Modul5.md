# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Puti Afifah Fairuzzana - 103112400194</p>

## Dasar Teori
Struktur adalah kumpulan variabel yang diberi nama, yang dimana setiap variabel memiliki tipe data yang berbeda. [1]

### A. Linear Search <br/>
Linear Search merupakan algoritma yang bekerja dengan mencocokan data secara berurutan satu per satu dari satu ujung kumpulan data ke ujung lainnya. Pencarian dengan linear search tidak akan berhenti hingga data yang diinginkan ditemukan.[2]

### B. Binary Search <br/>
Binary Search merupakan algoritma pencarian yang bekerja pada data yang telah diurutkan. Algoritma ini bekerja dengan membagi data menjadi dua secara berulang. Dengan membagi dua, proses pencarian lebih cepat karena tidak mencari ke bagian yang tidak perlu.[2]

## Guided 

### 1. Soal Guided 1

```C++

file "listBuah.h"

#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; 

typedef struct node *address;

struct node{
    dataBuah isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// Materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

#endif

file "listBuah.cpp"

#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

file "main.cpp"

#include "listBuah.h"

#include <iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    //A - C - D - B - E

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}   

```
Guided 1  Program ini mengelola data buah menggunakan singly linked list. Data disimpan dalam node yang berisi nama, jumlah, dan harga buah. Melalui fungsi insert, delete, dan update, program dapat menambah, menghapus, serta memperbarui data buah. Fungsi printList() menampilkan seluruh isi list, sedangkan nbList() menghitung jumlah node. Dalam contoh, program membuat list berisi lima buah, menampilkan isinya, lalu memperbarui beberapa data sebelum menampilkan hasil akhirnya.

### 2. Soal Guided 2

```C++

#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara binary
Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) // head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size disi 0
    for (Node* current = head; current;current = current->next)size++; //current adalah pointer yan digunakan untuk menyusuri linked linked list
    Node *start = head; //start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir (null karena linked list tidak memiliki pointer ke node terakhir yang pasti)

    while(size > 0) { //selama masih ada elemen > 0
        int mid = size / 2; //bagi size jadi 2
        Node* midNode = start; //midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0 ; i< mid;i++)midNode = midNode->next; //pindah ke node tengah

        if(midNode->data == key)return midNode; //jika ditemukan data yang cocok, kembalikan node
        if(midNode->data < key) { //jika data midNode lebih kecil dari key, kita cari dibagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { //jika data midNode lebih besar dari key, kita cari dibagian kiri
            end = midNode; //Akhiri pencarian di midNode
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode; // node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30);
    append(head, 40);
    append(head, 50); //menambah node

    //mencari data 40  menggunakan binarysearch
    Node* result = binarySearch(head, 40); //result ini pointer untuk mencari data 40
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}

```
Guided 2 Program ini membuat linked list dan melakukan pencarian data dengan metode binary search. Fungsi append() digunakan untuk menambah node baru di akhir list, sedangkan binarySearch() mencari nilai tertentu dengan membagi ukuran list menjadi dua bagian secara berulang.Dalam fungsi main(), program membuat list berisi 10, 20, 30, 40, dan 50, lalu mencari nilai 40. Hasilnya, program menampilkan output "found" karena data 40 ada di dalam linked list.

### 3. Soal Guided 3

```C++

#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
Guided 3 Program ini membuat linked list dan mencari data dengan metode linear search.
Fungsi append() menambah node baru di akhir list, sedangkan linearSearch() menelusuri setiap node untuk mencari nilai yang dicari.Pada fungsi main(), program membuat list berisi 10, 20, dan 30, lalu mencari nilai 20.
Hasilnya, program menampilkan output "found" karena data 20 ada di dalam linked list.


## Unguided 

### 1. Soal Unguided 1
Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1.Membuat linked list dengan menambahkan node di akhir
2.Mengimplementasikan binary search pada linked list
3.Menampilkan detail proses pencarian dan hasil akhir
Petunjuk Tugas 1: •Gunakan struktur Node dengan data integer dan pointer next •Implementasikan fungsi append() untuk menambah node •Implementasikan fungsi binarySearch() yang mengembalikan pointer ke node yang ditemukan •Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar •Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi •Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian

```C++

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


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan5_Modul5/output-unguided1-modul5.png)

Program ini menunjukkan proses pencarian data menggunakan binary search pada linked list. Data dimasukkan secara berurutan dengan fungsi append() dan ditampilkan melalui displayList(). Fungsi utama, binarySearch(), mencari nilai dengan membagi daftar menjadi dua bagian berulang kali hingga data ditemukan atau tidak ada elemen yang tersisa. Dalam contoh, program membuat linked list berisi angka 10 hingga 60, lalu melakukan pencarian, misalnya menemukan angka 40 dan tidak menemukan angka 25.

### 2. Soal Unguided 2
Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1.Membuat linked list dengan menambahkan node di akhir
2.Mengimplementasikan linear search pada linked list
3.Menampilkan detail proses pencarian dan hasil akhir
Petunjuk Tugas 2:•Gunakan struktur Node dengan data integer dan pointer next •Implementasikan fungsi append() untuk menambah node •Implementasikan fungsi linearSearch() yang mengembalikan pointer ke node yang ditemukan •Data dalam linked list tidak perlu terurut untuk linear search •Tampilkan setiap langkah pencarian dan node yang sedang diperiksa •Program utama harus membuat linked list dengan minimal 3 elemen dan melakukan pencarian

```C++

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

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan5_Modul5/output-unguided2-modul5.png)

Program ini menunjukkan pencarian data di linked list menggunakan linear search. Data dimasukkann satu per satu lewat fungsi append(), terus ditampilin pake tampilkanList(). Fungsi linearSearch() bakal ngecek tiap node dari awal sampai nemu data yang dicari, atau sampai semua node udah dicek. Di contoh ini, program bikin linked list berisi angka 10 sampai 50, terus berhasil nemuin angka 30 dan nggak nemuin angka 25.

## Kesimpulan
Linked List adalah struktur data linier di mana setiap elemen atau node saling terhubung melalui pointer, bukan disimpan secara berurutan di memori. Dalam pencarian data pada Linked List, dapat digunakan metode Linear Search, yaitu dengan memeriksa setiap node satu per satu hingga data yang dicari ditemukan. Metode ini tidak memerlukan data yang terurut, namun memiliki kelemahan dalam hal kecepatan ketika jumlah data sangat besar. Sebaliknya, Binary Search menawarkan pencarian yang jauh lebih cepat dengan cara membagi data menjadi dua bagian secara berulang, tetapi hanya dapat diterapkan apabila data telah terurut terlebih dahulu.

## Referensi
[1] Sindar, Anita R.M.S. (2019). "STRUKTUR DATA DAN ALGORITMA DENGAN C++". Banten: CV. AA. RIZKY.<br>
[2] Adrian, N. (2022?). Algoritma Pemrograman: Linear Search & Binary Search. Medium. https://medium.com/@naufal.adrian904/algoritma-pemrograman-linear-search-binary-search-3cd4403bab88.<br>
