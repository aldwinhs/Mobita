#ifndef PLAYER_H
#define PLAYER_H

#include "../ADT/boolean.h"
#include "../ADT/listpos.h"

/* Definisi elemen */
typedef struct {
   ListPos gadget; /* untuk inventory gadget */
   int money; /* menyimpan uang player */
   int time; /* menyimpan waktu player */
   // NANTI TAMBAHIN YANG LAIN JUGA!!
} Player;

/* ********* AKSES (Selektor) ********* */
/* Jika p adalah Player, maka akses elemen : */
#define GADGET(p) (p).gadget
#define MONEY(p) (p).money
#define TIME(p) (p).time

/* *** Kreator *** */
void createPlayer (Player *p);
/* I.S. sembarang */
/* F.S. Membuat player dengan atribut sebagai berikut : */
/*      Gadget = Listpos kosong */
/*      Uang = 0 yen */
/*      Waktu = 0 satuan */

/* *** Primitif Uang *** */
/* Menambah uang */
void addMoney (Player *p, int val);
/* I.S. Player dan val sudah terdefinisi */
/* F.S. Uang player bertambah sejumlah val */

/* Menggunakan Uang */
void useMoney (Player *p, int val);
/* I.S. Player dan val sudah terdefinisi */
/* F.S. Uang player bertambah sejumlah val */

/* *** Primitif Waktu *** */
void changeTime (Player *p, int val);
/* I.S. Player dan val sudah terdefinisi */
/* F.S. Waktu player bertambah/berkurang sejumlah val */

#endif
