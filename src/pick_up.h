#ifndef PICK_UP_H
#define PICK_UP_H

#include "../ADT/tas.h"
#include "../ADT/boolean.h"
#include "player.h"

void pickUpItem(Tas *S, char *lokSrc, char *locDes, char *jenisItem, int waktumasuk, int waktuhangus);
/* I.S Sembarang */
/* F.S item masuk ke dalam Tas*/

boolean isVIPitem(Tas S);
/* menghasilkan true jika pesanan pada top merupakan VIP ITEM sehingga tidak dapat melakukan pick_up pesanan lain */

boolean isItem(char *jenisitem);
/* menghasilkan true jika jenis pesanan valid */

boolean compare(char *array1, char *array2);
// membandingkan string
#endif