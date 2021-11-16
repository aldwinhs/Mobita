#include "tas.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateTas(Tas *s){
/* I.S. sembarang; */
/* F.S. Membuat sebuah Tas S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF_MOD */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
	IDX_TOP(*s) = IDX_UNDEF_MOD;
    (*s).heavyItem = 0;
    (*s).maxCapacity = 3;
    (*s).currCapacity = 0;
}

/* ************ Prototype ************ */
boolean isTasEmpty(Tas s){
/* Mengirim true jika s kosong: lihat definisi di atas */
	return (IDX_TOP(s) == IDX_UNDEF_MOD);
}
boolean isTasLiterallyFull(Tas s){
/* Mengirim true jika tabel penampung nilai s Tas penuh */
	return (IDX_TOP(s) == CAPACITY_TAS - 1);
}

boolean isTasFull(Tas s){
/* Mengirim true jika tabel penampung nilai s Tas penuh */
    return (IDX_TOP(s) == (s.maxCapacity - 1));
}

/* ************ Menambahkan sebuah elemen ke Tas ************ */
void addToTas(Tas *s, item val){
/* Menambahkan val sebagai elemen Tas s */
/* I.S. s mungkin kosong, tabel penampung elemen Tas TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
	if(!isTasFull(*s) && !isTasLiterallyFull(*s)) {
        IDX_TOP(*s)++;
        TOP(*s) = val;
        TOP(*s).beenPickedUp = true;
        (*s).currCapacity++;
        if(val.jenisItem == "H") { // [TO DO] heavy_item nanti disesuain lagi sama nama heavy_item yg dibuat Mahesa
            (*s).heavyItem++;
        }
    } // Else do nothing [TO DO] (Apakah perlu ditambahkan pesan bahwa tas sudah penuh?)
    // Kalau item dilakukan pick up dan dimasukan ke dalam tas,
}

/* ************ Menghapus sebuah elemen Tas ************ */
void rmvFromTas(Tas *s, item *val){
/* Menghapus val dari Tas s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
	if(!isTasEmpty(*s)) {
        *val = TOP(*s);
        IDX_TOP(*s)--;
        TOP(*s).beenDroppedOf = true;
        (*s).currCapacity--;
        if((*val).jenisItem == "H") { // [TO DO] heavy_item nanti disesuain lagi sama nama heavy_item yg dibuat Mahesa
            (*s).heavyItem--;
        }

    } // Else do nothing [TO DO] (Apakah perlu ditambahkan pesan bahwa tas sudah kosong?)
}

/* ************ Meningkatkan kapasitas Tas ************** */
void addCapTas(Tas *s, int val){
/* Menambah kapasitas tas */
/* I.S. s dan val terdefinisi */
/* F.S. max capacity tas bertambah sesuai val */
    if (val < 100) (*s).maxCapacity = (*s).maxCapacity + val;
    else (*s).maxCapacity = CAPACITY_TAS;
}
// [TO DO] Apakah perlu hapus Item di TO_DO untuk item yang sudah diantarkan (sudah di DROP_OFF)
/* BROKEN TEST CASE */
/*
int main() {
    Tas berisi;
    Item item1 = {"A", "G", "heavy_item", 6, 9, 400};
    Item item2 = {"D", "F", "Letinga", 14, 29, 213};
    Item item3 = {"D", "T", "Tolikan", 15, 89, 613};
    CreateTas(&berisi);
    addToTas(&berisi, item1);
    addToTas(&berisi, item2);
    addToTas(&berisi, item3);
    rmvFromTas(&berisi, &item3);

    printf("%d\n", berisi.idxTop);
    printf("%d\n", berisi.buffer[0].price);
    printf("%d\n", berisi.buffer[0].waktuHangus);
    printf("%d\n", item1.price);

    printf("%d\n", berisi.buffer[1].price);
    printf("%d\n", berisi.buffer[1].waktuHangus);
    printf("%d\n", item2.price);

    displayInProgr(berisi);
    return 0;
}
*/