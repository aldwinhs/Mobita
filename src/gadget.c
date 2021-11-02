#include <stdio.h>
#include "gadget.h"
#include "../ADT/listpos.h"

/* *** Menyimpan Harga Gadget *** */
int gadgetPrice(int n){
/* Mengembalikan harga dari sebuah gadget */
    if (n==1) return 800;
    if (n==2) return 1200;
    if (n==3) return 1500;
    if (n==4) return 3000;
}

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
    if (indexOf(g, 1) != IDX_UNDEF) printf("Kain Pembungkus Waktu\n");
    else printf("-\n");
    printf("2. ");
    if (indexOf(g, 2) != IDX_UNDEF) printf("Senter Pembesar\n");
    else printf("-\n");
    printf("3. ");
    if (indexOf(g, 3) != IDX_UNDEF) printf("Pintu Kemana Saja\n");
    else printf("-\n");
    printf("4. ");
    if (indexOf(g, 4) != IDX_UNDEF) printf("Mesin Waktu\n");
    else printf("-\n");
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n\n");
}

/* Informasi Gadget */
void printGadget(){
/* I.S. Data gadget sudah tersedia */
/* F.S. Menuliskan nama-nama gadget beserta harganya ke layar */
    printf("Gadget yang tersedia :\n");
    printf("1. Kain Pembungkus Waktu (800 yen)\n");
    printf("2. Senter Pembesar (1200 yen)\n");
    printf("3. Pintu Kemana Saja (1500 yen)\n");
    printf("4. Mesin Waktu (3000 yen)\n");
    printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n\n");
}
