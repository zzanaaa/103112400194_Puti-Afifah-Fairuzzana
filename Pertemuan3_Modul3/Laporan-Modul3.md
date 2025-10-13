# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (Bagian Ketiga)</h1>
<p align="center">Puti Afifah Fairuzzana - 103112400194</p>

## Dasar Teori
Struktur adalah kumpulan variabel yang diberi nama, yang dimana setiap variabel memiliki tipe data yang berbeda. [1]

### A. Abstract Data Type <br/>
Tipe data abstrak adalah jenis data tertentu yang didefinisikan oleh pemograman untuk kemudahan pemograman dan untuk menerima jenis data yang tidak spesifik yang dapat diterima oleh bahasa pemograman yang digunakan. Selain itu, ADT menyempurnakan tipe data dengan mengaitkannya dengan fungsi fungsi data yang relevan.[2]

## Guided 

### 1. Soal Guided 1

```C++
#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;

};

void inputMhs(mahasiswa &m){
    cout << " input nama : ";
    cin >> m.nama;
    cout << " input nilai 1 : ";
    cin >> m.nilai1;
    cout << " input nilai 2 : ";
    cin >> m.nilai2;

}

float rata2(mahasiswa m){
    return float(m.nilai1 + m.nilai2) / 2;

}

int main(){
    mahasiswa mhs;
    inputMhs(mhs);

    cout << "rata -rata nilai adalah : " << rata2(mhs) << endl;

    return 0;
}
```
Guided 1 Program ini menunjukkan penggunaan struktur data (struct), fungsi dengan parameter reference, dan fungsi pengembalian nilai untuk menghitung rata-rata nilai mahasiswa.

### 2. Soal Guided 2

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H
struct mahasiswa
{
  char nim[10];
  int nilai1, nilai2;
    /* data */
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif

#include <iostream>
#include "mahasiswa.h"

using namespace std;

//Realisasi dari Fungsi inputMhs
void inputMhs(mahasiswa &m){
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}

// Realisasi dari Fungsi rata2
float rata2(mahasiswa m){
    return (float)(m.nilai1 + m.nilai2) / 2;
}

#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs(mhs);

    cout << "Rata-rata nilai adalah : " << rata2
    (mhs) << endl;
    system("pause");

    return 0;
}
```
Guided 2 Program ini dibuat untuk menginput data seorang mahasiswa yang terdiri dari NIM, nilai pertama, dan nilai kedua, kemudian menghitung serta menampilkan rata-rata dari kedua nilai tersebut. Program ini menggunakan pendekatan modular dengan memisahkan bagian deklarasi, implementasi fungsi, dan program utama ke dalam tiga bagian berbeda. Pada file header mahasiswa.h, didefinisikan struktur mahasiswa yang berisi atribut nim, nilai1, dan nilai2, serta deklarasi fungsi inputMhs() dan rata2(). File implementasi berisi realisasi kedua fungsi tersebut, di mana inputMhs() digunakan untuk menerima input data mahasiswa melalui keyboard, sedangkan rata2() berfungsi menghitung rata-rata dari dua nilai yang dimasukkan. Pada file utama, dibuat variabel bertipe mahasiswa kemudian fungsi inputMhs() dipanggil untuk mengisi data mahasiswa dan hasil rata-ratanya dihitung dengan memanggil fungsi rata2(). Hasil akhir berupa nilai rata-rata mahasiswa ditampilkan di layar.

### 3. 

```C++
```
Guided 3

## Unguided 

### 1. Soal Unguided 1
Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama;;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main(){
    Mahasiswa mhs[10];
    int jumlah;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;
    if (jumlah > 10) jumlah = 10;

    cin.ignore();
    cout << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "Data Mahasiswa ke-" << (i + 1) << endl;
        cout << "Nama: "; getline(cin, mhs[i].nama);
        cout << "Nilai UTS: "; cin >> mhs[i].uts;
        cout << "Nilai UAS: "; cin >> mhs[i].uas;
        cout << "Nilai Tugas: "; cin >> mhs[i].tugas;
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
        cin.ignore();
        cout << endl;
    }
    cout << "\nData Mahasiswa:\n";
    cout << "No | Nama | Nilai Akhir\n";

    for (int i = 0; i < jumlah; i++) {
        cout << (i + 1) << " | " << mhs[i].nama << " | " 
             << fixed << setprecision(1) << mhs[i].nilaiAkhir << endl;
    }
    return 0;

}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan3_Modul3/output-unguided1-modul3.png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini meminta user untuk mengelola data mahasiswa dan menghitung nilai akhir nya.

### 2. Soal Unguided 2
Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h". Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp". Cobalah hasil implementasi ADT pada file "main.cpp"
```C++
pelajaran.h 
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran createPelajaran(string namaMapel, string kodeMapel);
void tampilPelajaran(pelajaran p);

#endif

pelajaran.cpp
#include "pelajaran.h"
#include <iostream>

pelajaran createPelajaran(string namaMapel, string kodeMapel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodeMapel;
    return p;
}

void tampilPelajaran(pelajaran p) {
    cout << "nama pelajaran: " << p.namaMapel << endl;
    cout << "kode pelajaran: " << p.kodeMapel << endl;
}

main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodeMapel = "STD";
    pelajaran p = createPelajaran(namaMapel, kodeMapel);
    tampilPelajaran(p);
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan3_Modul3/output-unguided2-modul3.png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

pelajaran.h berisi pendefinisian struktur data bernama pelajaran dengan dua atribut, yaitu namaMapel untuk menyimpan nama mata pelajaran dan kodeMapel untuk menyimpan kode mata pelajaran. pelajaran.cpp berisi implementasi dari fungsi-fungsi yang dideklarasikan dalam file header. main.cpp berisi program utama yang memanfaatkan fungsi-fungsi dari file sebelumnya. Program ini mendefinisikan dua variabel string, yaitu namaMapel dan kodeMapel, kemudian membuat objek pelajaran dengan memanggil fungsi createPelajaran(). 

### 3. Soal Unguided 3
Buatlah program dengan ketentuan:
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer 
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int data1[3][3] = {{2, 5, 7}, {3, 6, 1}, {4, 8, 9}};
    int data2[3][3] = {{1, 4, 6}, {2, 5, 3}, {7, 8, 9}};

    int *ptr1 = &data1[1][1];
    int *ptr2 = &data2[1][1];

    cout << "Sebelum ditukar: " << endl;
    cout << "Data 1: " << endl;
    tampilArray(data1);

    cout << "Data 2: " << endl;
    tampilArray(data2);
    tukarArray(data1, data2, ptr1, ptr2);

    cout << "Setelah ditukar: " << endl;
    cout << "Data 1: " << endl;
    tampilArray(data1);

    cout << "Data 2: " << endl;
    tampilArray(data2);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan3_Modul3/output-unguided3-modul3.png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program di atas menampilkan dan menukar elemen tertentu dari dua array dua dimensi (3x3) menggunakan pointer.

## Kesimpulan
Praktikum Modul 3 mengenalkan tipe data abstrak merupakan konsep penting dalam pemrograman yang memisahkan antara definisi logis suatu data dengan implementasinya secara fisik. Melalui ADT, programmer dapat mendeskripsikan apa yang dilakukan suatu struktur data tanpa harus memikirkan bagaimana cara kerjanya secara internal. Pendekatan ini dapat membantu menciptakan program yang lebih terstruktur, mudah dipahami, serta mudah dimodifikasi.

## Referensi
[1] Sindar, Anita R.M.S. (2019). "STRUKTUR DATA DAN ALGORITMA DENGAN C++". Banten: CV. AA. RIZKY.<br>
[2] Triase, T. (2020). Struktur Data: Diktat Edisi Revisi.<br>