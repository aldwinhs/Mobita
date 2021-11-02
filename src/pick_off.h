#ifndef PICK_OFF_H
#define PICK_OFF_H

#include "../ADT/stack.h"
#include "../ADT/boolean.h"

void pickOff(Stack *S, char item);
/* I.S Sembarang */
/* F.S item masuk ke dalam stack */

boolean isVIPitem(Stack S);
/* menghasilkan true jika pesanan pada top merupakan VIP ITEM sehingga tidak dapat melakukan pick_off pesanan lain */

boolean isItem(char item);
#endif