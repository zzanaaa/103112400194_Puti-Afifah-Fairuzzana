#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama, nim;
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
        cout << "NIM: "; getline(cin, mhs[i].nim);
        cout << "Nilai UTS: "; cin >> mhs[i].uts;
        cout << "Nilai UAS: "; cin >> mhs[i].uas;
        cout << "Nilai Tugas: "; cin >> mhs[i].tugas;
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
        cin.ignore();
        cout << endl;
    }
    cout << "\nData Mahasiswa:\n";
    cout << left << setw(5) << "No"
         << setw(15) << "Nama"
         << setw(15) << "NIM"
         << setw(15) << "Nilai Akhir" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(5) << (i + 1)
             << setw(15) << mhs[i].nama
             << setw(15) << mhs[i].nim
             << setw(15) << fixed << setprecision(1) << mhs[i].nilaiAkhir
             << endl;
    }
    return 0;

}