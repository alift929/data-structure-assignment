#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) (P)->info
#define firstKGroup(P) (P)->firstKGroup
#define next(P) (P)->next
#define first(C) ((C).first)

struct infotypeNegara{
    string namaNegara;
    string kota;
    int tahun;
};

struct infotypeKGroup {
    string namaGroup;
    int personel;
    string tour;
};

typedef struct Negara *adrNegara;
typedef struct KGroup *adrKGroup;

struct listNegara{
    adrNegara first;
};

struct listKGroup{
    adrKGroup first;
};

struct Negara{
    infotypeNegara info;
    listKGroup firstKGroup;
    adrNegara next;
};

struct KGroup{
    infotypeKGroup info;
    adrKGroup next;
};

void createListNegara(listNegara &L);
void createListKGroup(listKGroup &L);
adrNegara newNegara(string nama, string kota, int tahun);
adrKGroup newKGroup(string nama, int personel, string tour);
void insertNegara(listNegara &L, adrNegara n);
void showNegara(listNegara L);
void deleteNegara(listNegara &L, string nama);
adrNegara searchNegara(listNegara L, string nama);
void insertKGroup(listKGroup &L, adrKGroup k);
adrKGroup searchListKGroup(listKGroup L, string nama);
void connectKGroup(listNegara &L1, listKGroup L2, string namaNegara, string namaKGroup);
void showAll(listNegara L);
adrKGroup searchKGroup(listNegara L, string namaNegara, string namaKGroup);
void deleteKGroup(listNegara &L, string namaNegara);
int jumlahKGroup(listNegara L, string namaNegara);


#endif // TUBES_H_INCLUDED
