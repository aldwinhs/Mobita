#include "buy.h"
#include <stdio.h>
#include "../ADT/listpos.h"

/* *** Menyimpan Harga Gadget *** */
int gadgetPrice(int n){
/* Mengembalikan harga dari sebuah gadget */
    if (n==1) return 800;
    if (n==2) return 1200;
    if (n==3) return 1500;
    if (n==4) return 3000;
}

/* *** Membeli Gadget *** */
void buyGadget(ListPos l, int n){
/* I.S. List sudah terdefinisi dan masukan integer dianggap valid */
/* F.S. Menuliskan bahwa nama suatu gadget berhasil dibeli ke layar. */
    if (n == 1) {
        printf("Kain Pembungkus Waktu berhasil dibeli!\n");
    }
    if (n == 2) {
        printf("Senter Pembesar berhasil dibeli!\n");
    }
    if (n == 3) {
        printf("Pintu Kemana Saja berhasil dibeli!\n");
    }
    if (n == 4) {
        printf("Mesin Waktu berhasil dibeli!\n");
    }
}

/* *** Informasi Gadget *** */
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