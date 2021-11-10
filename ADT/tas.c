#include "tas.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateTas(Tas *s){
/* I.S. sembarang; */
/* F.S. Membuat sebuah Tas S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
	IDX_TOP(*s) = IDX_UNDEF;
}

/* ************ Prototype ************ */
boolean isTasEmpty(Tas s){
/* Mengirim true jika s kosong: lihat definisi di atas */
	return (IDX_TOP(s) == IDX_UNDEF);
}
boolean isTasFull(Tas s){
/* Mengirim true jika tabel penampung nilai s Tas penuh */
	return (IDX_TOP(s) == CAPACITY-1);
}

/* ************ Menambahkan sebuah elemen ke Tas ************ */
void addToTas(Tas *s, item val){
/* Menambahkan val sebagai elemen Tas s */
/* I.S. s mungkin kosong, tabel penampung elemen Tas TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
	IDX_TOP(*s)++;
	TOP(*s) = val;
}

/* ************ Menghapus sebuah elemen Tas ************ */
void rmvFromTas(Tas *s, item *val){
/* Menghapus val dari Tas s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
	*val = TOP(*s);
	IDX_TOP(*s)--;	
}

void displayInProgr(Tas s) {
    int i, saveIdxTop;
    saveIdxTop = s.idxTop;

    printf("Pesanan yang sedang diantarkan:\n");
    for (i = 0; i < (saveIdxTop + 1); i++) {
        printf("%d. %s (Tujuan: %s)", i + 1, s.buffer[i].jenisItem, s.buffer[i].lokDes);
        s.idxTop--;
    }
    s.idxTop = saveIdxTop;
}

void displayToDo(CollOfItems itemsinConfig, int currTime) {
    // [TO DO] Untuk testcase aja dibuat 4, nanti 4 diganti dengan banyak item yang dibaca file konfigurasi
    int amountOfItems = 4;
    int i;
    for(i = 0; i < amountOfItems;i++) {
        if(itemsinConfig.buffer[i].waktuMasuk <= currTime) {
            printf("%d. %s -> %s (%s)\n", i + 1, itemsinConfig.buffer[i].lokSrc, itemsinConfig.buffer[i].lokDes, itemsinConfig.buffer[i].jenisItem);
        }
    }
}

// [TO DO] [Opsional] Hapus Item di TO_DO untuk item yang sudah diantarkan (sudah di DROP_OFF)
/* TEST CASE */
/*
int main() {
    Tas berisi;
    Item item1 = {"A", "G", "Superstition", 6, 9, 400};
    Item item2 = {"D", "F", "Letinga", 14, 29, 213};
    CreateTas(&berisi);
    addToTas(&berisi, item1);
    addToTas(&berisi, item2);

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