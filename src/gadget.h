#ifndef GADGET_H
#define GADGET_H

#include "../ADT/listpos.h"
#include <stdio.h>

/* *** Menyimpan Harga Gadget *** */
int gadgetPrice(int n);
/* Mengembalikan harga dari sebuah gadget */

/* *** Menggunakan Gadget *** */
void useGadget(ListPos l, int n);
/* I.S. List sudah terdefinisi dan masukan integer dianggap valid */
/* F.S. Menuliskan bahwa nama suatu gadget berhasil digunakan ke layar. */

/* *** Membeli Gadget *** */
void buyGadget(ListPos l, int n);
/* I.S. List sudah terdefinisi dan masukan integer dianggap valid */
/* F.S. Menuliskan bahwa nama suatu gadget berhasil dibeli ke layar. */

/* *** Print Informasi *** */
/* Informasi Inventory */
void printInventory(ListPos G);
/* I.S. List sudah terdefinisi dan boleh kosong */
/* F.S. Print nama gadget yang terdapat di inventory */
/*      Jika tidak memiliki gadget, akan mengeluarkan "-" */

/* Informasi Gadget */
void printGadget();
/* I.S. Data gadget sudah tersedia */
/* F.S. Menuliskan nama-nama gadget beserta harganya ke layar */

#endif
