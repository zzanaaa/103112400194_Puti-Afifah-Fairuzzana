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
