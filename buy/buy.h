#ifndef BUY_H
#define BUY_H

#include "../ADT/listpos.h"
#include <stdio.h>

/* *** Menyimpan Harga Gadget *** */
int gadgetPrice(int n);
/* Mengembalikan harga dari sebuah gadget */

/* *** Membeli Gadget *** */
void buyGadget(ListPos l, int n);
/* I.S. List sudah terdefinisi dan masukan integer dianggap valid */
/* F.S. Menuliskan bahwa nama suatu gadget berhasil dibeli ke layar. */

/* *** Informasi Gadget *** */
void printGadget();
/* I.S. Data gadget sudah tersedia */
/* F.S. Menuliskan nama-nama gadget beserta harganya ke layar */

#endif