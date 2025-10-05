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

