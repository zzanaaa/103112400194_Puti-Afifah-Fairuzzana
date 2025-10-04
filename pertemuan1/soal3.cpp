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
