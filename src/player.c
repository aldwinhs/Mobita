#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include "player.h"

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

#endif
