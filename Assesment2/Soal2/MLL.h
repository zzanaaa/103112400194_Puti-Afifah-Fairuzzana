#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

struct child {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    child *next;
    child *prev;
};

struct listChild {
    child *first;
    child *last;
};

struct parent {
    string IDGenre;
    string namaGenre;
    parent *next;
    parent *prev;
    listChild childList;
};

struct listParent {
    parent *first;
    parent *last;
};

void createListParent(listParent &LP);
void createListChild(listChild &LC);
parent* alokasiNodeParent(string id, string nama);
child* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void dealokasiNodeParent(parent *p);
void dealokasiNodeChild(child *c);
void insertFirstParent(listParent &LP, parent *p);
void insertLastChild(listChild &LC, child *c);
void deleteAfterParent(listParent &LP, string idParent);
void hapusListChild(listChild &LC);
void printStrukturMLL(listParent LP);
void searchFilmByRatingRange(listParent LP, float min, float max);

#endif