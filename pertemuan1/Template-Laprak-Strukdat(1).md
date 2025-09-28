# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Puti Afifah Fairuzzana - 103112400194</p>

## Dasar Teori
Struktur adalah kumpulan variabel yang diberi nama, yang dimana setiap variabel memiliki tipe data yang berbeda. [1]

### A. Dasar pemrogaman <br/>
...
#### 1. Struktur C++ 
Program yang diawali dengan #include <iostrem> dan diakhiri dengan return 0; [2]
#### 2. Tipe Data
Data yang disimpan di dalam satu variabel. [3]
#### 3. Variabel
Tempat penyimpanan sementara yang memiliki nama dan bisa diisi data dengan dimodifikasi. [3]
#### 4. Konstanta
Konstanta dipakai untuk menyimpan data tetap. [3]

### B. Input dan output <br/>
...
#### 1. Fungsi cout 
Perintah untuk menampilkan teks di layar. [3]
#### 2. Fungsi Cin
Proses input atau menerima data masukan. [5]
#### 3. Fungsi getchar
Membaca sebuah karakter dengan sifat karakter yang dimasukkan tidak perlu diakhiri [4]

#### C. Operator 
...
#### 1. Aritmetika 
Operator aritmetika terdiri dari penjumlahan, pengurangan, perkalian, dan pembagian. [6]
#### 2. Operator Logika 
Operator yang hanya memberikan hasil benar atau salah. Operator && mengahsilkan nilai benar, jika nilai kebenaran dari seluruh ekpresi relasi dikombinasikan adalah benar, operator || jika nilai kebenaran dari satu eksprei, operator ! menghasilkan nilai kebalikkan, jika nilai awal bernilai benar maka hasilnya salah. [6]
#### 3. Operator Unary 
Operator yang digunakan untuk melakukan operasi terhadap satu operand. Operator + berfungsi untuk membuat variabel bernilai positif, operator - berfungsi untuk variabel yang bernilai negatif, ++ untuk menaikkan satu nilai variabel dan -- untuk menurunkan satu nilai variable. [6]
#### 4. Perulangan 
Perulangan memiliki tiga jenis utama, yaitu FOR TO DO yang berfungsi untuk urutan perintah yang telah ditentukan secara jelas, WHILE DO berfungsi untuk pernyataan yang akan dijalankan berulang kali selama kondisi ditetapkan bernilai benar dan DO WHILE berfungsi memeriksa kondisi yang sudah dijalankan sehingga minimal dieksekusi sekali.[6]
#### 5. Percabangan 
Metode yang digunakan untuk menentukan langkah yang harus dijalankan, sesuai kondisi yang berlaku.[7]

## Guided 

### 1. ...

```C++
#include <iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian :" << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;

    return 0;
}
```
Guided 1 membahas tentang operasi aritmetika 

### 2. ...

```C++
#include <iostream>
using namespace std;

int main(){
    int angka1;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    
    for (int i = 0; i < angka1; i++){
        cout << i << " - ";
    }

    int j = 10;
    while (j > angka1){
        cout << j << " - ";
        j--; 
    }

cout << endl;
int k = 10;
do{
    cout << k << " - ";
} while (k < angka1);
return 0;
}
```
Guided 2 membahas perulangan

### 3. ...

```C++
#include <iostream>
using namespace std;

int main() {
    const int MAX = 5;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukan nama siswa : ";
        cin >> siswa[i].nama;
        
        cout << "masukan nilai siswa : ";
        cin >> siswa[i].nilai;
        cout << endl;
    }
    int j = 0;
    while(j < MAX ){
        cout << "nama siswa" << siswa[j].nama << ", nilai" << siswa[j].nilai << endl;
        j++;
    }
    return 0;
}
```
Guided 3 membahas struct

## Unguided 

### 1. Soal Unguided 1
Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main(){
    float bil1, bil2;

    cout << "Masukkan bilangan pertama: ";
    cin >> bil1;
    cout << "Masukkan bilangan kedua: ";
    cin >> bil2;

    cout << "Penjumlahan: ";
    cout << bil1 + bil2 << endl;
    cout << "Pengurangan: ";
    cout << bil1 - bil2 << endl;
    cout << "Perkalian: ";
    cout << bil1 * bil2 << endl;
    cout << "Pembagian: ";
    cout << bil1 / bil2 << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/pertemuan1/output-unguided1-modul1.png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Penjelasan Unguided 1 
Di fungsi main(), program mendeklarasikan dua variabel yang bertipe float, yaitu bil1 dan bil2. Kemudian meminta untuk memasukkan bilangan pertama dan kedua melalui cin. Program melakukan empat operasi aritmatika yaitu penjumlahan, pengurangan, perkalian dan pembagian. Hasil dari masing masing operasi di tampilkan menggunakan cout. Dan diakhiri dengan return 0;.

### 2. Soal Unguided 2
Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
#include <iostream>
using namespace std;

string ubahKeTulisan(int n){
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (n == 0) {
        return "nol";
    } else if (n == 100) {
        return "seratus";
    } else if (n < 10) {
        return satuan[n];
    } else if (n < 20) {
        return belasan[n - 10];
    } else {
        int puluh = n / 10;
        int satu = n % 10;
        if (satu == 0) {
            return puluhan[puluh];
        } else {
            return puluhan[puluh] + " " + satuan[satu];
        }
    }
}
int main() {
    int x;
    cout << "Masukkan angka: ";
    cin >> x;

    if (x < 0 || x > 100) {
        cout << "Angka di luar jangkauan!" << endl;
    } else {
        cout << ubahKeTulisan(x) << endl;
    }
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/pertemuan1/output-unguided2-modul1.png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Penjelasan Unguided 2
Tiga array dibuat untuk mempermudah konversi angka ke kata yang terdiri dari satuan, belasan dan puluhan. Fungsi ubahKeTulisan untuk mengubah angka menjadi kata. Di fungsi main() program meminta untuk memasukkan angka melalui cin, dan program memeriksa apakah angka berada dalam jangkaun 0-100, jika angka di luar jangkauan maka menampilkan kata angka di luar jangkauan.

### 3. Soal Unguided 3
Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka: ";
    cin >> n;

    for (int i = 0; i <= n; i++) {
        for (int s = 0; s < i; s++) {
            cout << "  ";
        }

    
        for (int k = n - i; k >= 1; k--) {
            cout << k << " ";
        }

        cout << "* ";

        
        for (int k = 1; k <= n - i; k++) {
            cout << k << " ";
        }

        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/zzanaaa/103112400194_Puti-Afifah-Fairuzzana/blob/main/pertemuan1/output-unguided3-modul3.png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Penjelasan Unguided 3
Program meminta untuk memasukkan sebuah angka n melalui cin. Angka tersebut yang akan menentukan jumlah baris dan panjang pola yang akan ditampilkan. Program ini mencetak pola perulangan luar (for i = 0; i <= n; i++) yang mengontrol baris pola, perulangan pertama (int s = 0; s < i; s++) untuk mencetak spasi, perulangan kedua (for (int k = n - i; k >= 1; k--)) untuk mencetak angka menurun, perulangan ketiga (int k = 1; k <= n - i; k++) unruk angka naik dan program mencetak tanda bintang * untuk titik tengah. cout << endl; untuk membuat baris baru. 

## Kesimpulan
Struktur adalah konsep yang memungkinkan pengelompokan beberapa variabel dengan berbagai jenis tipe data yang berbeda menjadi satu kesatuan. Dengan adanya struktur, data yang saling terkait dapat dikelola dengan cara yang lebih teratur dan efisien.

## Referensi
[1] Sindar, Anita R.M.S. (2019). "STRUKTUR DATA DAN ALGORITMA DENGAN C++". Banten: CV. AA. RIZKY.
<br>[2] Sianipar, Rismon Hasiholan. (2014). "Pemrograman C++ untuk Pemula". Bandung: Penerbit Informatika. 
<br>[3] Hanief, S., & Jepriana, I. (2020). "Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++". Yogyakarta: Penerbit Andi.
[4] Hasibuan, A., Kembuan, D. R. E., & Tinambunan, M. H. (2023). Buku ajar algoritma dan pemrograman menggunakan bahasa pemrograman C++. Tahta Media.
[5] Petani Kode. (2019, 20 Desember). Belajar C++ #04: Mengenal fungsi input dan output pada C++. Petani Kode. https://www.petanikode.com/cpp-input-output/ 
[6] Anam, S., Yanti, I., Fitriah, Z., & Habibah, U. (2021). Cara mudah belajar bahasa pemrograman C++. Universitas Brawijaya Press.
[7] Pasaribu, Sutrisno Arianto. (2023). Algoritma dan Pemrograman dalam Bahasa Pascal dan C++. Deepublish
