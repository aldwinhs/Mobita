#include <stdio.h>
#include <stdlib.h>
#include "player.h"

/* Inisialisasi Player */
void createPlayer (Player *p){
/* I.S. Nama player terdefinisi */
/* F.S. Membuat player dengan atribut gadget, money, time, dan ... */
    
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
