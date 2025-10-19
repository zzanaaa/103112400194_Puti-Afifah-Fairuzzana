# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Puti Afifah Fairuzzana - 103112400194</p>

## Dasar Teori
Struktur adalah kumpulan variabel yang diberi nama, yang dimana setiap variabel memiliki tipe data yang berbeda. [1]

### A. Singly Linked List <br/>
Single Linked List merupakan struktur data yang setiap elemennya (node) memiliki satu pointer yang mengarah ke node berikutnya, sehingga alirannya hanya satu arah. Setiap node terdiri dari dua bagian utama: satu field untuk menyimpan data dan satu field pointer yang menunjuk ke node selanjutnya. Node terakhir tidak memiliki penerus, sehingga pointer-nya bernilai NULL sebagai penanda akhir dari rangkaian linked list tersebut.[2]

## Guided 

### 1. Soal Guided 1

```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 
typedef struct node *address;

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}
void createList(linkedlist &List) {
    List.first = Nil;
}
address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}
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
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}
void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Guided 1  Program ini menunjukkan cara membuat Linked List dinamis yang berisi data mahasiswa, menambahkan data menggunakan berbagai jenis operasi insert, serta menampilkan hasil akhir list secara berurutan.

### 2. Soal Guided 2

```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 
typedef struct node *address;

struct node{ 
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
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

#endif

#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}
void createList(linkedlist &List) {

    List.first = Nil;
}
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}
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
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
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
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
} 

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Guided 2 Program ini membuat dan mengelola Single Linked List berisi data mahasiswa seperti nama, NIM, dan umur. Program menambahkan beberapa data menggunakan berbagai jenis operasi insert (di awal, di tengah, dan di akhir), kemudian menampilkan isi list beserta jumlah nodenya. Setelah itu, program melakukan penghapusan data dari awal, akhir, dan tengah list, lalu menampilkan hasilnya. Terakhir, program menghapus seluruh isi list dan menampilkan bahwa list sudah kosong.

### 3. 

```C++
```
Guided 3

## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”. Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”. Kemudian buat program utama didalam file “main.cpp”.

```C++
singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif

singlylist.cpp
#include "singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (P != NULL) {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    if (L.first == NULL) {
        cout << "List kosong" << endl;
    } else {
        address P = L.first;
        while (P != NULL) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

main.cpp
#include "singlylist.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    address p1, p2, p3, p4, p5 = NULL;
    createList(L);

    p1 = alokasi(2);
    insertFirst(L, p1);

    p2 = alokasi(0);
    insertFirst(L, p2);

    p3 = alokasi(8);
    insertFirst(L, p3);

    p4 = alokasi(12);
    insertFirst(L, p4);

    p5 = alokasi(9);
    insertFirst(L, p5);

    printList(L);
    return 0;

}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan4_Modul4/unguided1/output-unguided1-modul4.png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini membuat Singly Linked List yang berisi data bertipe integer. Program menambahkan beberapa elemen ke dalam list menggunakan fungsi insertFirst, sehingga setiap data baru dimasukkan di bagian depan. Setelah semua elemen ditambahkan, program menampilkan isi list secara berurutan dari depan ke belakang. Karena proses penambahan dilakukan di awal, hasil akhirnya menunjukkan data dalam urutan terbalik dari saat dimasukkan, yaitu 9 12 8 0 2.

### 2. Soal Unguided 2
Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h". Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp". Cobalah hasil implementasi ADT pada file "main.cpp"
```C++
"singlylist.h"
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);
#endif

"singlylist.cpp"
#include "singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new Node;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (P != NULL) {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    if (L.first == NULL) {
        cout << "List kosong" << endl;
    } else {
        address P = L.first;
        while (P != NULL) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

void deleteFirst(List &L) {
    if (L.first != NULL) {
        address P = L.first;
        L.first = L.first->next;
        P->next = NULL;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            dealokasi(L.first);
            L.first = NULL;
        } else {
            address P = L.first;
            while (P->next->next != NULL) {
                P = P->next;
            }
            dealokasi(P->next);
            P->next = NULL;
        }
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
        dealokasi(P);
    } else {
        P = NULL;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != NULL) {
        deleteFirst(L);
    }
}

"main.cpp"
#include "singlylist.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    address p1, p2, p3, p4, p5 = NULL;
    createList(L);

    p1 = alokasi(2);
    insertFirst(L, p1);

    p2 = alokasi(0);
    insertFirst(L, p2);

    p3 = alokasi(8);
    insertFirst(L, p3);

    p4 = alokasi(12);
    insertFirst(L, p4);

    p5 = alokasi(9);
    insertFirst(L, p5);

    deleteFirst(L); 
    deleteLast(L); 

    address P;
    deleteAfter(L, L.first, P);

    printInfo(L);
    cout << "Jumlah node: " << nbList(L) << endl;
    deleteList(L);
    cout << "List Berhasil Terhapus " << endl;
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;

}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan4_Modul4/unguided2/output-unguided2-modul4.png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini membuat Single Linked List yang berisi data bertipe integer. Program menambahkan lima elemen ke dalam list menggunakan fungsi insertFirst, sehingga urutan datanya menjadi 9 → 12 → 8 → 0 → 2. Setelah itu, program menghapus elemen pertama (9), elemen terakhir (2), dan elemen setelah 12 (yaitu 8), sehingga list tersisa 12 → 0. Terakhir, program menampilkan jumlah node, lalu menghapus seluruh isi list hingga kosong.

### 3. Soal Unguided 3

```C++

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main//.png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

## Kesimpulan
Praktikum Modul 

## Referensi
[1] Sindar, Anita R.M.S. (2019). "STRUKTUR DATA DAN ALGORITMA DENGAN C++". Banten: CV. AA. RIZKY.<br>
[2] DAISMA Bali. (n.d.). Mengenal Single Linked List dalam Struktur Data. Diakses pada 19 Oktober 2025, dari https://daismabali.com/artikel_detail/54/1/Mengenal-Single-Linked-List-dalam-Struktur-Data.html.<br>
