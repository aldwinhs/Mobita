#include <stdio.h>
#include <stdlib.h>
#include "player.h"

/* *** Kreator *** */
void createPlayer (Player *p){
/* I.S. sembarang */
/* F.S. Membuat player dengan atribut sebagai berikut : */
/*      Gadget = Listpos kosong */
/*      Uang = 0 yen */
/*      Waktu = 0 satuan */
    
    // Membentuk penyimpanan sementara untuk listpos gadget
    ListPos g;
    CreateListPos(&g);

    // Assign data ke masing-masing atribut
    GADGET(*p) = g;
    MONEY(*p) = 0;
    TIME(*p) = 0;
}

/* *** Primitif Uang *** */
/* Menambah uang */
void addMoney (Player *p, int val){
/* I.S. Player dan val sudah terdefinisi */
/* F.S. Uang player bertambah sejumlah val */
    MONEY(*p) += val;
}

/* Menggunakan Uang */
void useMoney (Player *p, int val){
/* I.S. Player dan val sudah terdefinisi */
/* F.S. Uang player bertambah sejumlah val */
    MONEY(*p) -= val;
}

/* *** Primitif Waktu *** */
void changeTime (Player *p, int val){
/* I.S. Player dan val sudah terdefinisi */
/* F.S. Waktu player bertambah/berkurang(apabila val berupa bilangan negatif) sejumlah val */
    TIME(*p) += val;
}
