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