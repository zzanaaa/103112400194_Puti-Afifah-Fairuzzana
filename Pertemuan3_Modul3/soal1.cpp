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