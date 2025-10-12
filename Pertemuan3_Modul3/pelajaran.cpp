#include "pelajaran.h"
#include <iostream>

pelajaran createPelajaran(string namaMapel, string kodeMapel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodeMapel;
    return p;
}

void tampilPelajaran(pelajaran p) {
    cout << "nama pelajaran: " << p.namaMapel << endl;
    cout << "kode pelajaran: " << p.kodeMapel << endl;
}