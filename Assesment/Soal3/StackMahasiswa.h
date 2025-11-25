#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

const int MAX = 6;

struct Mahasiswa {
    string Name;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top = -1;
};


bool isEmpty(StackMahasiswa& S);
bool isFull(StackMahasiswa& S);
void createStack(StackMahasiswa& S);
void push(StackMahasiswa& S, Mahasiswa m);
void pop(StackMahasiswa& S);
void view(StackMahasiswa& S);
void update(StackMahasiswa& S, int pos, Mahasiswa m);
void searchNilaiAkhir(StackMahasiswa& S, float min, float max);

#endif