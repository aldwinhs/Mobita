/* File : Tas.h */
/* Definisi ADT Tas dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef TAS_H
#define TAS_H

#include "boolean.h"
// [TO DO] include lokasi tempat ADT Item

#define IDX_UNDEF -1
#define CAPACITY 100

/* ADT item yang ini sekadar untuk testing, nanti dihapus */
typedef struct {
    char *lokSrc;
    char *lokDes;
    char *jenisItem;
    int waktuMasuk;
    int waktuHangus; // waktuHangus -1 jika bukan perishable item
    int price;
} Item;

typedef Item item; // [TO DO] Item soon diganti sama ADT Item
typedef struct {
  item buffer[CAPACITY]; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
} Tas;
typedef Tas CollOfItems;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Tas, maka akses elemen : */
#define IDX_TOP(s) (s).idxTop
#define     TOP(s) (s).buffer[(s).idxTop]

/* *** Konstruktor/Kreator *** */
void CreateTas(Tas *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah Tas S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isTasEmpty(Tas s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isTasFull(Tas s);
/* Mengirim true jika tabel penampung nilai s Tas penuh */

/* ************ Menambahkan sebuah elemen ke Tas ************ */
void addToTas(Tas *s, item val);
/* Menambahkan val sebagai elemen Tas s */
/* I.S. s mungkin kosong, tabel penampung elemen Tas TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Tas ************ */
void rmvFromTas(Tas *s, item *val);
/* Menghapus val dari Tas s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

void displayInProgr(Tas s);
/* Menampilkan pesanan yang sedang diantarkan */
/* I.S. s tidak mungkin kosong */
/* F.S. menampilkan pesanan yang sedang dikerjakan sesuai urutan mulai dari yang ada pada Top Stack */

void displayToDo(CollOfItems itemsinConfig, int currTime);
/* Menampilkan TO DO LIST */
/* I.S. terdapat setidaknya satu item pada file konfigurasi dengan urutan sesuai spesifikasi */
/* F.S. menampilkan setiap item yang waktu pesanan masuknya  lebih kecil atau sama dengan waktu sekarang */



#endif