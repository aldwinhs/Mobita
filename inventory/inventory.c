#ifndef INVENTORY_H
#define INVENTORY_H

#include "../ADT/listpos.h"
#include <stdio.h>

/* *** Menggunakan Gadget *** */
void useGadget(ListPos l, int n){
/* I.S. List sudah terdefinisi dan masukan integer dianggap valid */
/* F.S. Menuliskan bahwa nama suatu gadget berhasil digunakan ke layar. */
    if (n == 1) {
        printf("Kain Pembungkus Waktu berhasil digunakan!\n");
    }
    if (n == 2) {
        printf("Senter Pembesar berhasil digunakan!\n");
    }
    if (n == 3) {
        printf("Pintu Kemana Saja berhasil digunakan!\n");
    }
    if (n == 4) {
        printf("Mesin Waktu berhasil digunakan!\n");
    }
}

/* *** Print Informasi *** */
/* Informasi Inventory */
void printInventory(ListPos g){
/* I.S. List sudah terdefinisi dan boleh kosong */
/* F.S. Print nama gadget yang terdapat di inventory */
/*      Jika tidak memiliki gadget, akan mengeluarkan "-" */
    printf("1. ");
    if (indexOfLP(g, 1) != IDX_UNDEFLP) printf("Kain Pembungkus Waktu\n");
    else printf("-\n");
    printf("2. ");
    if (indexOfLP(g, 2) != IDX_UNDEFLP) printf("Senter Pembesar\n");
    else printf("-\n");
    printf("3. ");
    if (indexOfLP(g, 3) != IDX_UNDEFLP) printf("Pintu Kemana Saja\n");
    else printf("-\n");
    printf("4. ");
    if (indexOfLP(g, 4) != IDX_UNDEFLP) printf("Mesin Waktu\n");
    else printf("-\n");
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n\n");
}

#endif