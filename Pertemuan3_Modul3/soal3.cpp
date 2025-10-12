#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int data1[3][3] = {{2, 5, 7}, {3, 6, 1}, {4, 8, 9}};
    int data2[3][3] = {{1, 4, 6}, {2, 5, 3}, {7, 8, 9}};

    int *ptr1 = &data1[1][1];
    int *ptr2 = &data2[1][1];

    cout << "Sebelum ditukar: " << endl;
    cout << "Data 1: " << endl;
    tampilArray(data1);

    cout << "Data 2: " << endl;
    tampilArray(data2);
    tukarArray(data1, data2, ptr1, ptr2);

    cout << "Setelah ditukar: " << endl;
    cout << "Data 1: " << endl;
    tampilArray(data1);

    cout << "Data 2: " << endl;
    tampilArray(data2);

    return 0;

}