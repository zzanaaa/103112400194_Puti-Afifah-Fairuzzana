# <h1 align="center">Laporan Praktikum Modul 10 - Tree</h1>
<p align="center">Puti Afifah Fairuzzana - 103112400194</p>

## Dasar Teori
Struktur data adalah cara untuk mengatur, menyimpan, dan mengelola data di dalam komputer agar data mudah diakses, diproses, dan diubah. Dengan struktur data, data bisa dikelola dengan lebih baik dan program berjalan lebih cepat dalam memproses informasi. Struktur data juga membantu memahami bagaimana data saling terhubung, sehingga memudahkan pencarian dan pengubahan data sesuai kebutuhan aplikasi. Menggunakan struktur data yang tepat akan membantu programmer meningkatkan kinerja aplikasi dan menghadapi masalah data yang rumit. [1]

### A. Tree <br/>
Kumpulan node yang saling terhubung satu sama lain dalam suatu kesatuan yang membentuk layakya struktur sebuah pohon. Struktur pohon adalah suatu cara merepresentasikan suatu struktur hirarki (one-to-many) secara grafis yang mirip sebuah pohon, walaupun pohon tersebut hanya tampak sebagai kumpulan node-node dari atas ke bawah. Suatu struktur data yang tidak linier yang menggambarkan hubungan yang hirarkis (one-to-many) dan tidak linier antara elemen-elmennya. [2]

## Guided 

### 1. Soal Guided 1

```C++
#include<iostream>
using namespace std;

int pangkat_2(int x) {//adalah pengkatnya
    if(x == 0) {//basis
        return 1;
    } else if (x > 0) {//rekurens
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;

    int x;
    cout << "Masukkan nilai x: "; 
    cin >> x;
    cout << endl;
    cout << "2 pangkat " << x << " adalah : " << pangkat_2(x) ;

    return 0;
}

// misal x = 3
// pangkat_2(3)
// 2 * pangkat_2(2);
// 2 * (2 * pangkat_2(1));
// 2 * (2 * (2 * pangkat_2(0)));
// 2 * 2 * 2 * 1
// 8

```
Guided 1 Program ini menghitung nilai 2 pangkat x menggunakan fungsi rekursif. Pada fungsi pangkat_2, jika nilai x bernilai 0, fungsi langsung mengembalikan angka 1 sebagai kasus dasar, karena 2⁰ = 1. Jika x lebih besar dari 0, fungsi memanggil dirinya sendiri dengan mengurangi nilai x satu per satu, sambil mengalikan hasilnya dengan 2 pada setiap langkah, sehingga membentuk proses perhitungan pangkat secara rekursif. Di dalam main(), program meminta pengguna memasukkan nilai x, kemudian menampilkan hasil perhitungan 2 pangkat x yang diperoleh dari fungsi rekursif tersebut.

### 2. Soal Guided 2

file BST.h
```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data interger
typedef struct Node* address; //alias address sebagai pointer ke struct Node (Node*)

struct Node {
    infotype info; // info data yang disimpan(integer)
    address left; // pointer left
    address right; // pointer right
};

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); //function untuk membuat BST nya (root di-set sebagai NULL)

//alokasi & insert
address newNode(infotype x); //function untuk memasukkan data (infotype) kedalam node
address insertNode(address root, infotype x); //function untuk memasukkan node kedalam BST

//traversal
void preOrder(address root); //function traversal tree secara pre-order (tengah - kiri - kanan atau root - childkiri - childkanan)
void inOrder(address root); //function traversal tree secara in-order (kiri - tengah - kanan atau childkiri - root - childkanan)
void postOrder(address root); //function traversal tree secara post-order (kiri - kanan - tengah atau childkiri - childkanan - root)

//utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root); //function untuk menghitung height atau kedalaman atau level tree

#endif
```

file BST.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

file main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Guided 2 Program ini membuat sebuah Binary Search Tree (BST) dan menyediakan fungsi untuk menambah data, menelusuri tree, serta menghitung informasi dasar. Struktur node dan deklarasi fungsinya ditulis di BST.h, sedangkan logika insert, traversal, dan perhitungan node serta kedalaman tree ada di BST.cpp. Di main.cpp, program membuat tree kosong, lalu memasukkan beberapa angka sehingga terbentuk BST. Setelah itu, program menampilkan isi tree menggunakan traversal In-Order, Pre-Order, dan Post-Order, serta menghitung jumlah node dan kedalaman tree. Program ini menunjukkan bagaimana BST bekerja dalam menyimpan dan membaca data secara terstruktur.

### 3. Soal Guided 3

file BST2.h
```C++
#ifndef BST2_H
#define BST2_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data interger
typedef struct Node* address; //alias address sebagai pointer ke struct Node (Node*)

struct Node {
    infotype info; // info data yang disimpan(integer)
    address left; // pointer left
    address right; // pointer right
};

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); //function untuk membuat BST nya (root di-set sebagai NULL)

//alokasi & insert
address newNode(infotype x); //function untuk memasukkan data (infotype) kedalam node
address insertNode(address root, infotype x); //function untuk memasukkan node kedalam BST

//traversal
void preOrder(address root); //function traversal tree secara pre-order (tengah - kiri - kanan atau root - childkiri - childkanan)
void inOrder(address root); //function traversal tree secara in-order (kiri - tengah - kanan atau childkiri - root - childkanan)
void postOrder(address root); //function traversal tree secara post-order (kiri - kanan - tengah atau childkiri - childkanan - root)

//utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root); //function untuk menghitung height atau kedalaman atau level tree

//FUNCTION & PEOSEDUR BARU
//search
void searchByData(address root, infotype x); //function untuk melakukan searching data tertentu

//mostleft & mostright
address mostLeft(address root); //function untuk menampilkan mostleft atau node paling kiri
                                // (node dengan nilai terkecil) didalam BST
address mostRight(address root); //function untuk menampilkan mostright atau node paling kanan
                                 // (node dengan nilai terbesar) didalam BST

//delete
bool deleteNode(address &root, infotype x); //function untuk menghapus node tertentu didalam BST
                                            //(menghapus berdasarkan parameter infotype)
void deleteTree(address &root); //procedur untuk menghapus BST (menghapus seluruh node BST)

#endif
```

file BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```

file main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
Guided 3 Program ini membuat Binary Search Tree (BST). Struktur node berisi data serta pointer ke anak kiri dan kanan. Program menyediakan fungsi untuk membuat tree, menambah node baru secara terurut, menelusuri tree (Pre-Order, In-Order, Post-Order), menghitung jumlah node, dan menentukan kedalaman tree. fungsi pencarian yang menampilkan informasi lengkap node yang dicari, dan fungsi untuk mendapatkan nilai terkecil dan terbesar. Program mendukung penghapusan node dengan berbagai kondisi (tanpa child, satu child, atau dua child). Di main.cpp, program membuat BST, memasukkan beberapa data, menampilkan hasil traversal, menghitung size dan depth, mencari nilai tertentu, menampilkan nilai minimum dan maksimum, lalu menghapus nilai yang dimasukkan pengguna. Terakhir, seluruh tree dihapus dan program memastikan BST kosong.

## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”, implementasi ADT Binary Search Tree pada file “bstree.cpp”, dan hasil implementasi ADT pada file “main.cpp”.

file bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL
typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

typedef address BinTree;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);

#endif
```

file bstree.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P -> info = x;
        P -> left = Nil;
        P -> right = Nil;
    }
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        }
        else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    }
    
    if (x == root->info) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left); 
    } else {
        return findNode(x, root->right);
    }
}

void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}
```

file main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    InOrder(root);
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan10_Modul10//output-unguided1-modul10.png)

Program ini membuat sebuah Binary Search Tree (BST), yaitu struktur data berbentuk pohon yang menyimpan nilai secara terurut. Pada file bstree.h, didefinisikan struktur node yang memiliki nilai data serta pointer menuju anak kiri dan kanan, dan juga deklarasi fungsi untuk membuat node baru, memasukkan data, mencari data, dan mencetak isi pohon. Pada bstree.cpp, setiap fungsi diimplementasikan: alokasi membuat node baru, insertNode menempatkan nilai ke posisi yang sesuai dalam BST, findNode mencari nilai menggunakan aturan BST, dan InOrder mencetak seluruh nilai dari yang terkecil sampai terbesar. Di file main.cpp, program membuat root kosong, lalu memasukkan beberapa angka ke BST, kemudian mencetak hasilnya menggunakan traversal In-Order sehingga angka-angka muncul dalam urutan naik.

### 2. Soal Unguided 2
Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut. fungsi hitungJumlahNode( root:address ) : integer /* fungsi mengembalikan integer banyak node yang ada di dalam BST*/ fungsi hitungTotalInfo( root:address, start:integer ) : integer /* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/, fungsi hitungKedalaman( root:address, start:integer ) : integer /* fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */

file bstree2.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL
typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

typedef address BinTree;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);
int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int start);

#endif
```

file bstree2.cpp
```C++
#include <iostream>
#include "bstree2.h"
using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P -> info = x;
        P -> left = Nil;
        P -> right = Nil;
    }
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else
            insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    }
    
    if (x == root->info) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    } else {
    int leftDepth = hitungKedalaman(root->left, start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);
    
    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
    }
}
```

file main.cpp
```C++
#include <iostream>
#include "bstree2.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    
    address root = Nil;
    
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    
    InOrder(root);
    cout << "\n";
    
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;
    
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan10_Modul10//output-unguided2-modul10.png)

Program ini membuat Binary Search Tree (BST) dan menyediakan beberapa fungsi tambahan untuk menghitung informasi dari pohon tersebut. Pada bstree2.h, didefinisikan struktur node yang menyimpan nilai serta pointer ke anak kiri dan kanan, beserta deklarasi fungsi untuk membuat node, menyisipkan data, mencari data, melakukan traversal In-Order, menghitung jumlah node, menghitung total nilai semua node, dan menentukan kedalaman maksimal pohon. Di file bstree2.cpp, fungsi insertNode menempatkan nilai ke dalam BST sesuai aturan, InOrder mencetak nilai dari yang paling kecil sampai terbesar, hitungNode menghitung total node dalam pohon, hitungTotal menjumlahkan semua nilai pada node, dan hitungKedalaman menentukan seberapa dalam pohon dari root sampai level paling bawah. Pada main.cpp, program membuat BST dengan memasukkan beberapa angka, kemudian mencetak isi pohon secara terurut. Setelah itu, program menampilkan kedalaman pohon, jumlah node yang ada, serta total keseluruhan nilai dari node-node tersebut.

### 3. Soal Unguided 3
Print tree secara pre-order dan post-order.

file bstree3.cpp
```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan10_Modul10//output-unguided3-modul10.png)

Program ini membuat sebuah Binary Tree secara manual dengan node bernilai 6 sebagai root. Tiap node memiliki anak kiri dan kanan. Setelah tree terbentuk, program menampilkan isi tree dengan dua cara penelusuran: Pre-Order: mencetak root dulu, lalu anak kiri dan kanan. Post-Order: mencetak anak kiri dan kanan dulu, lalu root. Hasilnya adalah urutan data sesuai metode traversal yang digunakan.

## Kesimpulan
Rekursif adalah teknik fungsi yang memanggil dirinya sendiri untuk menyelesaikan masalah berulang. Tree adalah struktur data non-linear dengan hubungan parent–child, dan yang paling penting adalah Binary Search Tree (BST) yang mengatur data secara terurut (kiri lebih kecil, kanan lebih besar). Operasi utama BST meliputi insert, search, delete, serta traversal (pre-order, in-order, post-order). Materi juga melatih pembuatan BST menggunakan linked list dan perhitungan jumlah node, total nilai, serta kedalaman tree.

## Referensi
[1] Anaraindyah, R. (2024). Struktur data: Pengertian, fungsi, dan penerapannya. Universitas Negeri Surabaya.https://share.google/kfvAZsEHXwWWO9ZVc <br>
[2] Santoso, R. (2014, Desember 17). Tree pada C++ (Tree Awal). NBLOGNLIFE. https://www.nblognlife.com/2014/12/tree-pada-c-tree-awal.html <br>
