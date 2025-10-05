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

void tampilkanMatriks(int matriks[3][3]) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cout << matriks[x][y] << "\t ";
        }
        cout << endl;
    }
}

void jumlahMatriks(int A[3][3], int B[3][3]) {
    int hasil[3][3];
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            hasil[x][y] = A[x][y] + B[x][y];
        }
    } 
    cout << "Hasil penjumlahan matriks A dan B adalah:" << endl;
    tampilkanMatriks(hasil);
    cout << endl;
}

void kurangMatriks(int A[3][3], int B[3][3]) {
    int hasil[3][3];
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            hasil[x][y] = A[x][y] - B[x][y];
        }
    }
    cout << "Hasil pengurangan matriks A dan B adalah:" << endl;
    tampilkanMatriks(hasil);
    cout << endl;
}

void kaliMatriks(int A[3][3], int B[3][3]) {
    int hasil[3][3];
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            hasil[x][y] = 0;
            for (int z = 0; z < 3; z++) {
                hasil[x][y] += A[x][y] * B[x][y];
            }
        }
    }
    cout << "Hasil perkalian matriks A dan B adalah:" << endl;
    tampilkanMatriks(hasil);
    cout << endl;
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
