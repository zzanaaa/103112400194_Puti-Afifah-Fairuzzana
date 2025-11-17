# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Puti Afifah Fairuzzana - 103112400194</p>

## Dasar Teori
Struktur adalah kumpulan variabel yang diberi nama, yang dimana setiap variabel memiliki tipe data yang berbeda. [1]

### A. Stack <br/>
Stack adalah sebuah kumpulan data dimana data yang diletakkan di atas data  yang lain. Dengan demikian stack adalah struktur data yang menggunakan konsep LIFO(Last In First Out). Dengan demikian, elemen terakhir yang disimpan dalam stack menjadi elemen pertama yang diambil. Dalam proses komputasi, untuk meletakkan sebuah elemen pada bagian atas dari stack, maka dilakukan operasi push. Dan untuk memindahkan dari tempat yang atas tersebut, maka dilakukan operasi pop. [2]

## Guided 

### 1. Soal Guided 1

file stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

file stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

file main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}

```
Guided 1 Program ini mengimplementasikan stack menggunakan linked list, di mana setiap node menyimpan data dan pointer ke node berikutnya, sedangkan stack hanya menyimpan pointer top ke elemen teratas. Program menyediakan operasi push() untuk menambah elemen, pop() untuk menghapus elemen teratas, update() untuk mengubah nilai pada posisi tertentu, view() untuk menampilkan seluruh isi stack, dan searchData() untuk mencari nilai tertentu. Di bagian utama, program membuat lima node, menambahkannya ke stack, melakukan beberapa pop dan update, menampilkan stack setelah setiap operasi, serta melakukan pencarian data tertentu. Program ini menunjukkan cara kerja dasar stack dengan manipulasi data menggunakan linked list.

### 2. Soal Guided 2

file stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //Array untuk menyimpan eleman stack
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // Menambahkan elemen ke dalam stack
infotype pop(Stack &S); // Mengambil elemen teratas dari stack
void printInfo(Stack S);
void balikStack(Stack &S); // Membalik urutan elemen dalam stack

#endif
```

file stack.cpp
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```

file main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
Guided 2 Program ini mengimplementasikan stack menggunakan array dengan ukuran maksimum 20 elemen. Stack disimpan dalam struktur Stack yang memiliki array info untuk menyimpan data dan variabel top untuk menandai posisi elemen teratas. Fungsi CreateStack() digunakan untuk menginisialisasi stack kosong, isEmpty() untuk mengecek apakah stack kosong, dan isFull() untuk mengecek apakah stack penuh. Elemen ditambahkan ke stack melalui push() dan diambil dari atas stack menggunakan pop(). Fungsi printInfo() menampilkan semua elemen dari atas ke bawah, sedangkan balikStack() membalik urutan elemen stack dengan memanfaatkan dua stack sementara. Di (main.cpp), program membuat stack S, menambahkan beberapa elemen, melakukan operasi pop beberapa kali, menampilkan isi stack, membalik urutan stack, dan menampilkan hasil akhirnya. Program ini menunjukkan operasi dasar stack seperti push, pop, tampil, dan membalik urutan elemen menggunakan metode array.

## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”. Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer). Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekantombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

file Stack.h
```C++
#ifndef STACK_H
#define STACK_H

#define MaxEl 20
#define Nil -1

typedef int infotype;

typedef struct {
    infotype info[MaxEl];
    int top;
} Stack;

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// Prosedur untuk pushAscending
void pushAscending(Stack &S, int x);
// Prosedur untuk getInputStream
void getInputStream(Stack &S);

#endif
```

file Stack.cpp
```C++
#include "Stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return (S.top == Nil);
}

bool isFull(Stack S) {
    return (S.top == MaxEl - 1);
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack Kosong!" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {  
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);  

        while (!isEmpty(S)) { push(temp1, pop(S)); } 

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  
    }
}

void pushAscending(Stack &S, int x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}


void getInputStream(Stack &S) {
    char c;
    
    cout << "Masukkan deretan angka (akhiri dengan ENTER): ";
    cin.get(c);

    while (c != '\n'){
        push(S, c - '0');
        cin.get(c);
    }
}

```

file main.cpp
```C++
#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    cout << "Hello world!" << endl;
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);

    cout << "Balik Stack :" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    // pushAscending
    cout << "Hello world!" << endl;
    CreateStack(S);

    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);

    printInfo(S);

    cout<<"balik stack"<<endl;

    balikStack(S);
    printInfo(S);
    cout << endl;

    // getInputStream
    cout << "Hello world!" << endl;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);

    cout << "Balik Stack :" << endl;
    
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan7_Modul7//output1-unguided1-modul7.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan7_Modul7//output2-unguided1-modul7.png)

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan7_Modul7//output3-unguided1-modul7.png)

Program ini mengimplementasikan struktur data Stack (tumpukan) menggunakan array dengan kapasitas maksimal 20 elemen. Stack bekerja dengan prinsip LIFO (Last In First Out). Operasi dasar yang tersedia meliputi CreateStack() untuk membuat stack kosong, push() untuk menambah elemen ke bagian atas stack, pop() untuk menghapus elemen teratas, isEmpty() untuk mengecek apakah stack kosong, isFull() untuk mengecek apakah stack penuh, dan printInfo() untuk menampilkan isi stack dari atas ke bawah. Program juga menyediakan fitur tambahan yaitu balikStack() untuk membalik urutan elemen stack menggunakan dua stack sementara, serta pushAscending() yang menambahkan elemen ke stack dalam urutan terurut naik dengan memindahkan sementara elemen yang lebih besar. Selain itu terdapat getInputStream() yang membaca input karakter angka dari pengguna satu per satu dan memasukkannya ke stack hingga pengguna menekan Enter. Pada fungsi main(), program mendemonstrasikan seluruh operasi tersebut melalui percobaan push, pop, mencetak isi stack, membalik stack, memasukkan elemen secara ascending, dan membaca input stream.

## Kesimpulan
Stack adalah struktur data yang bekerja dengan prinsip LIFO (Last In First Out), di mana elemen yang terakhir masuk akan menjadi yang pertama keluar. Operasi utamanya adalah Push (menambah elemen ke TOP) dan Pop (mengambil elemen dari TOP). Stack dapat diimplementasikan menggunakan pointer (linked list) maupun array (tabel). Pada kedua representasi, akses hanya dilakukan pada bagian TOP. Modul juga membahas primitif dasar stack seperti createStack, isEmpty, push, pop, serta latihan pengembangan seperti balikStack, pushAscending, dan getInputStream.

## Referensi
[1] Sindar, Anita R.M.S. (2019). "STRUKTUR DATA DAN ALGORITMA DENGAN C++". Banten: CV. AA. RIZKY. <br>
[2] Unknown. (2014, April 26). Stack pada C++. NBLOGNLIFE. https://www.nblognlife.com/2014/04/stack-pada-c.html <br>
