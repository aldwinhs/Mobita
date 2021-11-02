#ifndef PLAYER_H
#define PLAYER_H

#include "../ADT/boolean.h"
#include "../ADT/listpos.h"

typedef struct {
   ListPos gadget; /* untuk inventory gadget */
   int money; /* menyimpan uang player */
   int time; /* menyimpan waktu player */
   // NANTI TAMBAHIN YANG LAIN JUGA!!
} Player;

#define GADGET(p) (p).gadget
#define MONEY(p) (p).money
#define TIME(p) (p).time

/* Inisialisasi Player */
void createPlayer (Player *p);
/* I.S. Nama player terdefinisi */
/* F.S. Membuat player dengan atribut gadget, money, time, dan ... */

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
