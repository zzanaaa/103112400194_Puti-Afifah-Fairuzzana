# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Puti Afifah Fairuzzana - 103112400194</p>

## Dasar Teori
Struktur adalah kumpulan variabel yang diberi nama, yang dimana setiap variabel memiliki tipe data yang berbeda. [1]

### A. Array <br/>
... 
#### 1. Array 
Struktur yang terdiri dari sebuah elemen yang memiliki tipe data yang sama.[2]
#### 2. Pointer 
Variabel penunjuk yang berisi alamat pada suatu lokasi tertentu.[3]

## Guided 

### 1. ...

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "masukkan value indeks ke-" << 1 << " : "; 
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5){
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Guided 1 membahas tentang array

### 2. ...

```C++
include <iostream>
using namespace std;

int main() {
    int arr[] = {10,20,30,40,50};
    int* ptr = arr; // pointer yang menunjuk ke elemen pertama array

    // mengakses elemen array menggunakan pointer 
    for (int i = 0 ; i < 5; ++i){
        cout << "Elemen array ke-" << i << "menggunakan pointer :" << *(ptr + i) << endl;
    }
    // mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; ++i){
        cout << "Elemen array ke-" << i + 1 << "menggunakan indeks: " << arr[i] << endl;
    }
    return 0;
}
```
Guided 2 membahas tentang array pointer

### 3. ...

```C++
#include <iostream>
using namespace std;

void ubahNilai(int* ptr){
    *ptr = 20; // mengubah nilai yang ditunjuk oleh pointer
}

int main(){
    int x = 10;
    cout << "Nilai sebelum diubah:" << x << endl; 

    ubahNilai(&x); // mengirimkan alamat memori x ke fungsi
    cout << "Nilai setelah diubah:" << x << endl;

    return 0;
}
```
Guided 3 membahas call by pointer

## Unguided 

### 1. Soal Unguided 1
Diketahui 2 buah matriks 3x3 seperti dibawah ini :
MatriksA = [7 12 22 31 6 41 15 19 36] MatriksB = [11 34 7 3 25 41 5 18 33]
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case seperti berikut ini :
--- Menu Program Matriks ---
1. Penjumlahan matriks
2. Pengurangan matriks
3. Perkalian matriks
4. Keluar

```C++
#include <iostream>
using namespace std;

int A[3][3] = {
    {7, 12, 22},
    {31, 6, 41},
    {15, 19, 36}
};

int B[3][3] = {
    {11, 34, 7},
    {3, 25, 41},
    {5, 18, 33}
};

void tampilkanMatriks(int M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void jumlahMatriks(int A[3][3], int B[3][3]) {
    int hasil[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    } 
    cout << "Hasil penjumlahan:\n";
    tampilkanMatriks(hasil);
}

void kurangMatriks(int A[3][3], int B[3][3]) {
    int hasil[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
    cout << "Hasil pengurangan:\n";
    tampilkanMatriks(hasil);
}

void kaliMatriks(int A[3][3], int B[3][3]) {
    int hasil[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "Hasil perkalian:\n";
    tampilkanMatriks(hasil);
}

int main() {
    int pilihan; 
    do {   

        cout << "Menu Operasi Matriks" << endl;
        cout << "1. Penjumlahan Matriks\n";
        cout << "2. Pengurangan Matriks\n";
        cout << "3. Perkalian Matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlahMatriks(A, B);
                break;
            case 2: 
                kurangMatriks(A, B);
                break; 
            case 3: 
                kaliMatriks(A, B);
                break;
            case 4: 
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);
    
    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan2_Modul2/output-unguided1-modul2.png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program meminta user untuk membuat program yang dapat melakukan operasi penjumlahan, pengurangan dan perkalian matriks 3x3. Prosedur untuk masing - masing operasi dilakukan jumlahMatriks() untuk penjumlahan, kurangMatriks() untuk pengurangan dan kaliMatriks() untuk perkalian.

### 2. Soal Unguided 2
Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer, seperti berikut:
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan luas (beri nilai 0).
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar yang menunjuk ke variabel lebar.
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas. Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.
4) Cetak nilai luas ke layar.
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui pointer ptrPanjang dan ptrLebar.
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa nilainya telah berubah.
```C++
#include <iostream>
using namespace std;

int main() {
    int p = 10, l = 5, luas = 0, kel = 0;

    int* ptrPanjang = &p;
    int* ptrLebar = &l;

    cout << "---Nilai Awal---" << endl;
    cout << "Panjang: " << p << endl;
    cout << "Lebar: " << l << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    kel = 2 * (*ptrPanjang + *ptrLebar);

    cout << "---Hasil Perhitungan---" << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << kel << endl;
    
    *ptrPanjang = 12;
    *ptrLebar = 6; 

    luas = (*ptrPanjang) * (*ptrLebar);
    kel = 2 * (*ptrPanjang + *ptrLebar);

    cout << "---Nilai Setelah Diubah---" << endl;
    cout << "Panjang Baru: " << p << endl;
    cout << "Lebar Baru: " << l << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << kel << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/Pertemuan2_Modul2/output-unguided2-modul2.png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini meminta untuk menghitung luas dan keliling persegi panjang yang proses perhitungannya dan perubahannya menggunakan pointer. 3 variabel di fungsi main(): panjang dengan nilai 10, lebar dengan nilai 5, dan luas dengan nilai 0. Deklarasi dua pointer: ptrPanjang dan ptrLebar. Mengubah nilai menjadi 12 untuk panjang dan 6 untuk lebar dan cetakk nilai panjang dan lebar.

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
Struktur adalah konsep yang memungkinkan pengelompokan beberapa variabel dengan berbagai jenis tipe data yang berbeda menjadi satu kesatuan. Dengan adanya struktur, data yang saling terkait dapat dikelola dengan cara yang lebih teratur dan efisien.

## Referensi
[1] Sindar, Anita R.M.S. (2019). "STRUKTUR DATA DAN ALGORITMA DENGAN C++". Banten: CV. AA. RIZKY.<br>
[2] Pratama, M. A. (2020, March 29). STRUKTUR DATA ARRAY DUA DIMENSI  PADA PEMROGRAMAN C++. https://doi.org/10.31219/osf.io/vyech.<br>
[3] Muhammad, T. D. P., Munawir, M., & Yuniarti, A. R. (2023). Belajar Pemograman Lanjut Dengan C++. Penerbit Widina.<br>
