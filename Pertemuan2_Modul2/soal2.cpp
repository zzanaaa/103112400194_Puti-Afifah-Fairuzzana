#include <iostream>
using namespace std;

int main() {
    int panjang = 10, lebar = 5, luas = 0, keliling = 0;

    int* ptrPanjang = &panjang;
    int* ptrLebar = &lebar;

    cout << "---Nilai Awal---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * (*ptrPanjang + *ptrLebar);

    cout << "---Hasil Perhitungan---" << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl;
    
    *ptrPanjang = 12;
    *ptrLebar = 6; 

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * (*ptrPanjang + *ptrLebar);

    cout << "---Nilai Setelah Diubah---" << endl;
    cout << "Panjang Baru: " << panjang << endl;
    cout << "Lebar Baru: " << lebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}