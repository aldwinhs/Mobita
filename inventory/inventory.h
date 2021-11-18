#ifndef INVENTORY_H
#define INVENTORY_H

#include "../ADT/listpos.h"
#include <stdio.h>

/* *** Menggunakan Gadget *** */
void useGadget(ListPos l, int n);
/* I.S. List sudah terdefinisi dan masukan integer dianggap valid */
/* F.S. Menuliskan bahwa nama suatu gadget berhasil digunakan ke layar. */

/* *** Print Informasi *** */
/* Informasi Inventory */
void printInventory(ListPos g);
/* I.S. List sudah terdefinisi dan boleh kosong */
/* F.S. Print nama gadget yang terdapat di inventory */
/*      Jika tidak memiliki gadget, akan mengeluarkan "-" */

#endif