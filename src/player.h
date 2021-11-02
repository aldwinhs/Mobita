#ifndef PLAYER_H
#define PLAYER_H

#include "../ADT/boolean.h"
#include "../ADT/listpos.h"

typedef struct {
   ListPos gadget; /* untuk inventory gadget */
   int money; /* menyimpan uang player */
   // NANTI TAMBAHIN YANG LAIN JUGA!!
} Player;

#define GADGET(p) (p).gadget
#define MONEY(p) (p).money

/* *** Primitif Uang *** */
/* Menambah uang */
void addMoney (Player *p, int val);
/* I.S. Player dan val sudah terdefinisi */
/* F.S. Uang player bertambah sejumlah val */

/* Menggunakan Uang */
void useMoney (Player *p, int val);
/* I.S. Player dan val sudah terdefinisi */
/* F.S. Uang player bertambah sejumlah val */

#endif
