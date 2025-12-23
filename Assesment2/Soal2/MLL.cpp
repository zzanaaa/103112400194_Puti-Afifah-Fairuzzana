#include "mll.h"

void createListParent(listParent &LP) {
    LP.first = NULL;
    LP.last = NULL;
}

void createListChild(listChild &LC) {
    LC.first = NULL;
    LC.last = NULL;
}

parent* alokasiNodeParent(string id, string nama) {
    parent *p = new parent;
    p->IDGenre = id;
    p->namaGenre = nama;
    p->next = p->prev = NULL;
    createListChild(p->childList);
    return p;
}

child* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    child *c = new child;
    c->IDFilm = id;
    c->judulFilm = judul;
    c->durasiFilm = durasi;
    c->tahunTayang = tahun;
    c->ratingFilm = rating;
    c->next = c->prev = NULL;
    return c;
}

void dealokasiNodeParent(parent *p) {
    delete p;
}

void dealokasiNodeChild(child *c) {
    delete c;
}

void insertFirstParent(listParent &LP, parent *p) {
    if (LP.first == NULL) {
        LP.first = LP.last = p;
    } else {
        p->next = LP.first;
        LP.first->prev = p;
        LP.first = p;
    }
}

void insertLastChild(listChild &LC, child *c) {
    if (LC.first == NULL) {
        LC.first = LC.last = c;
    } else {
        LC.last->next = c;
        c->prev = LC.last;
        LC.last = c;
    }
}

void hapusListChild(listChild &LC) {
    child *c = LC.first;
    while (c != NULL) {
        child *temp = c;
        c = c->next;
        dealokasiNodeChild(temp);
    }
    LC.first = LC.last = NULL;
}

void deleteAfterParent(listParent &LP, string idParent) {
    parent *p = LP.first;
    while (p != NULL && p->IDGenre != idParent)
        p = p->next;

    if (p != NULL && p->next != NULL) {
        parent *hapus = p->next;

        hapusListChild(hapus->childList);

        p->next = hapus->next;
        if (hapus->next != NULL)
            hapus->next->prev = p;
        else
            LP.last = p;

        dealokasiNodeParent(hapus);
    }
}

void printStrukturMLL(listParent LP) {
    parent *p = LP.first;
    int i = 1;

    while (p != NULL) {
        cout << "=== Parent " << i++ << " ===\n";
        cout << "ID Genre : " << p->IDGenre << endl;
        cout << "Nama Genre : " << p->namaGenre << endl;

        child *c = p->childList.first;
        int j = 1;
        while (c != NULL) {
            cout << "- Child " << j++ << " :\n";
            cout << "  ID Film : " << c->IDFilm << endl;
            cout << "  Judul Film : " << c->judulFilm << endl;
            cout << "  Durasi Film : " << c->durasiFilm << " menit\n";
            cout << "  Tahun Tayang : " << c->tahunTayang << endl;
            cout << "  Rating Film : " << c->ratingFilm << endl;
            c = c->next;
        }
        cout << "--------------------------\n";
        p = p->next;
    }
}

void searchFilmByRatingRange(listParent LP, float min, float max) {
    parent *p = LP.first;
    int posParent = 1;

    while (p != NULL) {
        child *c = p->childList.first;
        int posChild = 1;

        while (c != NULL) {
            if (c->ratingFilm >= min && c->ratingFilm <= max) {
                cout << "Data Film ditemukan pada list child dari node parent "
                    << p->namaGenre << " pada posisi ke-" << posChild << endl;

                cout << "--- Data Film (Child) ---\n";
                cout << "Judul Film : " << c->judulFilm << endl;
                cout << "ID Film : " << c->IDFilm << endl;
                cout << "Durasi Film : " << c->durasiFilm << " menit\n";
                cout << "Tahun Tayang : " << c->tahunTayang << endl;
                cout << "Rating Film : " << c->ratingFilm << endl;

                cout << "--- Data Genre (Parent) ---\n";
                cout << "ID Genre : " << p->IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << posParent << endl;
                cout << "Nama Genre : " << p->namaGenre << endl;
                cout << "===============================\n";
            }
            c = c->next;
            posChild++;
        }
        p = p->next;
        posParent++;
    }
}