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