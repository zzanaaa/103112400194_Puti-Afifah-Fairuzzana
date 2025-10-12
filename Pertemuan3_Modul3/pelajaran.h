#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran createPelajaran(string namaMapel, string kodeMapel);
void tampilPelajaran(pelajaran p);

#endif