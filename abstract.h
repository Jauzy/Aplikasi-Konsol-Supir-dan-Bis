#ifndef ABSTRACT_H_INCLUDED
#define ABSTRACT_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <cstring>
using namespace std;

#define name(X) X->name
#define slot(B) B->slot
#define his(X) X->his
#define bis(S) S->bis
#define next(X) X->next
#define prev(X) X->prev
#define firstB(B) B.first
#define supirBis(B) B->supir
#define firstS(S) S.first
#define bisDikendarai(S) S->dikendarai
#define historyBis(S) S->history

typedef struct elmBis *Baddr;
typedef struct elmSupir *Saddr;
struct Bis{
    Baddr first;
};
struct Supir{
    Saddr first;
};
struct elmSupir{
    string name;
    int his,bis;
    Bis dikendarai,history;
    Saddr next,prev;
};
struct elmBis{
    string name;
    int slot;
    Supir supir;
    Baddr next,prev;
};
//BASICS
Baddr createElmBis(string name);
Saddr createElmSupir(string name);
void createListBis(Bis &B);
void createListSupir(Supir &S);
bool isEmptyBis(Bis B);
bool isEmptySupir(Supir S);
void tambahSupir(Supir &S);
void tambahBis(Bis &B);
//SOALSOAL
void addSupir(Supir &S,Saddr SPO);//1
void addBis(Bis &B,Baddr BSO);//2
void createHubungan(Bis &B,Supir &S,string nameSupir,string nameBis);//3
void deleteSupir(Supir &S,Bis &B,string nameSupir);//4
void deleteBis(Supir &S,Bis &B,string nameBis);//5
void tampilkanHistorySemuaSupir(Supir S);//6
void tampilkanSupirBis(Bis B,string nameBis);//7
void tampilkanSupirDenganBisTerbanyak(Supir S);//8
void tampilkanSupirDenganBisTerdikit(Supir S);//9
//ADDITION
void tampilkanSupirDanBisDikendarai(Supir S);
void printAllBis(Bis B);
void printAllSupir(Supir S);
void printBisTersedia(Bis B);
Baddr cariBis(Bis B,string nameBis);
Baddr cariBisDalamSupir(Supir S,Bis B,string nameSupir,string nameBis);
Saddr cariSupir(Supir S,string nameSupir);
int kuantitasBis(Supir S,string mode);
void deleteBisBasic(Bis &B,string nameBis);
void deleteSupirBasic(Supir &S,string nameSupir);
void hapusHubungan(Supir S,Bis B,string nameSupir, string nameBis);

/*
    Kelebihan Dari Program
1. Input Supir Tidak Boleh Sama.
2. Input Bis Tidak Boleh Sama.
3. Error Handle pada saat menghubungkan supir dan bis ( mencegah adanya duplikat ).
4. error handle jika bis sudah memiliki 2 supir maka tidak akan menerima lagi.
5. bis yang sudah memiliki 2 supir tidak akan muncul pada tampilan Bis yang tersedia.
6. pilihan Main Menu Menggunakan type char, mencegah adanya error "TypeError".
7. Menggunakan mode dalam mencari min maks, mempersingkat penulisan kode.
8. method tambahan khusus untuk menghapus hubungan
*/



#endif // ABSTRACT_H_INCLUDED
