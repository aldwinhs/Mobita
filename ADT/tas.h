/* File : Tas.h */
/* Definisi ADT Tas dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef TAS_H
#define TAS_H

#include "boolean.h"
// [TO DO] include lokasi tempat ADT Item

#define IDX_UNDEF_MOD -1
#define CAPACITY_TAS 100

/* ADT item yang ini sekadar untuk testing, nanti dihapus */
typedef struct
{
  char lokSrc;
  char lokDes;
  char jenisItem;
  int waktuMasuk;
  int waktuHangus; // waktuHangus -1 jika bukan perishable item
  int price;
  boolean beenPickedUp; // asumsi initialnya False, tapi default di C bukan False, belum tau cara handle [TO DO]
  boolean beenDroppedOf; // initialnya False
  // [TO DO] Perlu ditambahkan apa lagi?
} Item;

typedef Item item; // [TO DO] Item soon diganti sama ADT Item
typedef struct
{
  item buffer[CAPACITY_TAS]; /* tabel penyimpan elemen */
  int idxTop;                /* alamat TOP: elemen puncak */
  int heavyItem;             // amount of heavyItem in Tas
  int currCapacity;          // currCapacity tidak lain dan tidak bukan adalah idxTop + 1;
  int maxCapacity;           // maxCapacity bisa berubah
} Tas;
typedef Tas CollOfItems;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Tas, maka akses elemen : */
#define IDX_TOP(s) (s).idxTop
#define TOP(s) (s).buffer[(s).idxTop]
#define SUM_HEAVY(s) (s).heavyItem
#define MAX_TAS(s) (s).maxCapacity
#define CURRENT_CAP(s) (s).currCapacity
/* *** Konstruktor/Kreator *** */
void CreateTas(Tas *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah Tas S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isTasEmpty(Tas s);
/* Mengirim true jika s kosong: lihat definisi di atas */

boolean isTasLiterallyFull(Tas s);
/* Mengirim true jika tabel penampung nilai s Tas penuh */

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

/* ************ Meningkatkan kapasitas Tas ************** */
void addCapTas(Tas *s, int val);
/* Menambah kapasitas tas */
/* I.S. s dan val terdefinisi */
/* F.S. max capacity tas bertambah sesuai val */

#endif