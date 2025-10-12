#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodeMapel = "STD";
    pelajaran p = createPelajaran(namaMapel, kodeMapel);
    tampilPelajaran(p);
    return 0;
}