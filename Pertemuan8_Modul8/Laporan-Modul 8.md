# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Puti Afifah Fairuzzana - 103112400194</p>

## Dasar Teori
Struktur data adalah cara untuk mengatur, menyimpan, dan mengelola data di dalam komputer agar data mudah diakses, diproses, dan diubah. Dengan struktur data, data bisa dikelola dengan lebih baik dan program berjalan lebih cepat dalam memproses informasi. Struktur data juga membantu memahami bagaimana data saling terhubung, sehingga memudahkan pencarian dan pengubahan data sesuai kebutuhan aplikasi. Menggunakan struktur data yang tepat akan membantu programmer meningkatkan kinerja aplikasi dan menghadapi masalah data yang rumit. [1]

### A. Queue <br/>
Queue adalah struktur data yang mengikuti prinsip First-In, First-Out (FIFO) elemen pertama yang masuk akan menjadi elemen pertama yang keluar. Layaknya antrian di bank atau kasir supermarket, queue memudahkan pengelolaan urutan tugas, permintaan, atau data dalam berbagai aplikasi: mulai dari print spooler, message broker, hingga job scheduling di sistem terdistribusi. [2]

## Guided 

### 1. Soal Guided 1

file queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H 
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```

file queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```

file main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enqueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}

```
Guided 1 Program ini mengimplementasikan struktur data queue dengan menggunakan linked list. Pada file queue.h, terdapat struktur node yang berisi data serta pointer ke node berikutnya, dan struktur queue yang menyimpan pointer head dan tail sebagai penanda elemen pertama dan terakhir. Di dalamnya juga dideklarasikan berbagai fungsi seperti createQueue, alokasi, dealokasi, enQueue, deQueue, updateQueue, viewQueue, dan searchData. Pada file queue.cpp, seluruh fungsi tersebut diimplementasikan. Fungsi enQueue digunakan untuk menambahkan data di bagian belakang queue, sedangkan deQueue menghapus data dari bagian depan. Fungsi updateQueue memungkinkan perubahan isi data pada posisi tertentu, viewQueue menampilkan seluruh elemen queue, dan searchData digunakan untuk mencari data tertentu beserta posisinya. Sementara itu, file main.cpp berfungsi untuk menjalankan pengujian program. Lima data awal dimasukkan ke dalam queue, kemudian dua data terdepan dihapus. Setelah itu dilakukan proses update pada beberapa posisi dan pencarian data tertentu. Secara keseluruhan, program ini menunjukkan cara kerja dasar queue—mulai dari menambah, menghapus, memperbarui, menampilkan, hingga mencari data—dengan memanfaatkan struktur linked list.

### 2. Soal Guided 2

file queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

file queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```

file main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

// Fungsi utama program
int main() {
    Queue Q;

    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 Elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    cout << "\n Dequeue 1 Elemen" << endl;
    cout << "Elemen kelur: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 1 Elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\n Dequeue 2 Elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
Guided 2 Program ini membuat antrean (queue) menggunakan array yang bekerja secara melingkar. Di queue.h ditentukan struktur antreannya, termasuk posisi awal, posisi akhir, dan jumlah data, serta fungsi untuk membuat antrean, menambah data, menghapus data, mengecek penuh atau kosong, dan menampilkan isinya. Pada queue.cpp, fungsi-fungsi tersebut dijalankan. Penambahan data dilakukan di posisi tail, lalu tail digeser maju secara melingkar. Penghapusan dilakukan dari posisi head, dan head juga ikut bergerak maju. Cara ini membuat ruang di dalam array bisa dipakai kembali.Di main.cpp, antrean diuji dengan memasukkan beberapa data, menghapus sebagian, dan menampilkan perubahan setiap kali operasi dilakukan. Program ini menunjukkan cara kerja antrean secara sederhana: data masuk dari belakang, keluar dari depan, dan indeks bergerak melingkar agar tempat tidak terbuang.

## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”: Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

file queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

typedef int infotype;

typedef struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

file queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = 0;
    Q.tail = 0;
}

bool isEmptyQueue(Queue Q){
    return (Q.tail == 0);
}

bool isFullQueue(Queue Q){
    return (Q.tail == MAX_QUEUE);
}

void enqueue(Queue &Q, infotype x){
    if (!isFullQueue(Q)) {             
        if (isEmptyQueue(Q)) {         
            Q.head = 1;
            Q.tail = 1;
            Q.info[0] = x;
        } else {
            Q.info[Q.tail] = x;        
            Q.tail++;                  
        }
    } else {
        cout << "Queue penuh" << endl;
    }
}

infotype dequeue(Queue &Q) {
    if (!isEmptyQueue(Q)) {
        infotype hasil = Q.info[0];

        for (int i = 0; i < Q.tail - 1; i++) {
            Q.info[i] = Q.info[i + 1];
        }

        Q.tail--;

        if (Q.tail == 0) {
            Q.head = 0;
        }

        return hasil;
    }

    cout << "Queue kosong" << endl;
    return -1;
}

void printInfo(Queue Q) {
    int H, T;

    if (isEmptyQueue(Q)) {
        H = -1;
        T = -1;
    } else {
        H = Q.head - 1;   
        T = Q.tail - 1;  
    }

    cout << H << "  -  " << T << "  |  ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = 0; i < Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}
```

file main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan8_Modul8//output-unguided1-modul8.png)

Program ini membuat struktur data queue berbasis array berukuran lima elemen dengan aturan FIFO. Queue dianggap kosong jika tail == 0 dan penuh jika tail == MAX_QUEUE. Operasi enqueue menambah elemen ke belakang antrian; jika antrian masih kosong, elemen pertama ditempatkan di indeks 0 dan head–tail diset ke 1. Operasi dequeue mengambil elemen terdepan dengan menghapus info[0] lalu menggeser seluruh elemen ke kiri, kemudian menurunkan tail. Fungsi printInfo menampilkan posisi head–tail serta isi antrian. Program utama menjalankan beberapa operasi enqueue dan dequeue untuk memperlihatkan perubahan isi queue setiap langkahnya.

### 2. Soal Unguided 2
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
queue Alternatif 2 (head bergerak, tail bergerak).

file queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

typedef int infotype;

typedef struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

file queue.cpp 
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail < Q.head);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE -1);
}

void enqueue(Queue &Q, infotype x) {
    if(!isFullQueue(Q)) {
        Q.tail++;
        Q.info[Q.tail] = x;
    } else {
        cout << "Queue Penuh!" << endl;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if(!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        Q.head++;
        
        if (Q.head > Q.tail) {
            Q.head = 0;
            Q.tail = -1;
        }
    } else {
        cout << "Queue Kosong!" << endl;
    }
    return x;
}
void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << "\n";
}
```

file main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan8_Modul8//output-unguided2-modul8.png)

Program ini mengimplementasikan struktur data Queue berbasis array dengan kapasitas lima elemen dan menggunakan prinsip FIFO (First In First Out). Antrian dikelola menggunakan dua indeks: head untuk elemen terdepan dan tail untuk elemen terakhir. Saat queue dibuat, head di-set ke 0 dan tail ke –1 sebagai tanda bahwa antrian kosong. Fungsi enqueue menambah data ke belakang antrian selama belum penuh, sedangkan dequeue mengambil elemen paling depan dan memajukan head. Jika setelah penghapusan head melewati tail, queue di-reset kembali ke kondisi kosong. Program utama memperlihatkan bagaimana elemen ditambahkan, dihapus, dan bagaimana perubahan posisi head, tail, serta isi queue ditampilkan setelah setiap operasi.

### 3. Soal Unguided 3
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
queue Alternatif 3 (head dan tail berputar).

file queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

typedef int infotype;

typedef struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

file queue.cpp 
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;

}
bool isEmptyQueue(Queue Q){
    return(Q.head == -1 && Q.tail == -1);
}
bool isFullQueue(Queue Q){
    return((Q.tail + 1) % MAX_QUEUE == Q.head);
}
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue penuh" << endl;
        return;
    }
    if(isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;

    }else{
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
    }
    Q.info[Q.tail] = x;
}
infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        return -1;
    }
    infotype temp = Q.info[Q.head];
    if(Q.head == Q.tail){
        Q.head = -1;
        Q.tail = -1;
    }else{
        Q.head = (Q.head + 1) % MAX_QUEUE;
    }
    return temp;
}
void printInfo(Queue Q){
    cout << " " << Q.head << " - " << Q.tail << "\t | ";

    if(isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return;
    }

    int i = Q.head;
    while(true){
        cout << Q.info[i] << " ";
        if(i == Q.tail) break;
        i = (i + 1) % MAX_QUEUE;
    }
    cout << endl;
}
```

file main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan8_Modul8//output-unguided3-modul8.png)

Program ini mengimplementasikan struktur data Antrian Sirkular (Circular Queue) menggunakan array statis dengan ukuran maksimum 5 elemen. Konsep utamanya adalah FIFO (First-In, First-Out), di mana elemen yang masuk pertama akan keluar pertama. Implementasi ini memanfaatkan dua penunjuk integer, head (penunjuk elemen depan/awal) dan tail (penunjuk elemen belakang/akhir), yang diinisialisasi ke -1 saat antrian kosong. Operasi penting dalam antrian sirkular adalah penggunaan operator modulo (MAX_QUEUE) saat menggeser head atau tail. Hal ini memungkinkan penunjuk untuk melingkar kembali ke indeks 0 setelah mencapai akhir array, sehingga memanfaatkan ruang array secara efisien. Fungsi-fungsi utama yang disediakan meliputi CreateQueue untuk inisialisasi, isEmptyQueue dan isFullQueue untuk pemeriksaan kondisi, enqueue untuk menambahkan elemen di posisi tail, dan dequeue untuk mengeluarkan elemen dari posisi head. Eksekusi program utama mendemonstrasikan serangkaian operasi tambah dan hapus, menunjukkan bagaimana nilai head dan tail bergerak maju dan bagaimana elemen yang pertama masuk akan selalu dikeluarkan terlebih dahulu.

## Kesimpulan
Modul 8 membahas tentang struktur data Queue, yaitu antrean data yang bekerja dengan prinsip FIFO (First In, First Out). Artinya, data yang pertama kali masuk akan menjadi data yang pertama kali keluar, seperti antrean pada loket atau kasir. Dalam modul ini dijelaskan bahwa queue bisa diimplementasikan dengan linked list maupun array, dan keduanya memiliki konsep dasar yang sama: proses penambahan data (enqueue) selalu dilakukan dari bagian belakang, sedangkan penghapusan data (dequeue) selalu dilakukan dari bagian depan. Modul ini juga memperkenalkan tiga cara atau alternatif dalam mengelola queue berbasis array.Modul 8 membantu mahasiswa memahami cara kerja queue, cara mengimplementasikannya dalam berbagai bentuk, serta bagaimana memilih mekanisme yang paling efisien sesuai kebutuhan program.

## Referensi
[1] Anaraindyah, R. (2024). Struktur data: Pengertian, fungsi, dan penerapannya. Universitas Negeri Surabaya.https://share.google/kfvAZsEHXwWWO9ZVc <br>
[2] Firmansyah, I. (2025, Maret 10). Queue adalah: Pengertian, tipe, dan contoh implementasi. SoftwareSeni. Diakses dari https://www.softwareseni.co.id/blog/queue-adalah-pengertian-tipe-dan-contoh-implementasi <br>
