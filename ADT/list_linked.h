/* File : list_linked.h */
/* contoh ADT ListLL berkait dengan representasi fisik pointer  */
/* Representasi Address dengan pointer */
/* item adalah integer */

#ifndef LIST_H
#define LIST_H

#include "boolean.h"
#include "node.h"

typedef AddressNode ListLL;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/* Definisi ListLL : */
/* ListLL kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir ListLL: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN ListLL KOSONG ******************/
void CreateListLL(ListLL *l);
/* I.S. sembarang             */
/* F.S. Terbentuk ListLL kosong */

/****************** TEST ListLL KOSONG ******************/
boolean isEmptyLL(ListLL l);
/* Mengirim true jika ListLL kosong */

/****************** GETTER SETTER ******************/
item getElmtLL(ListLL l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtLL(ListLL *l, int idx, item val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOfLL(ListLL l, item val);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen ListLL l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstLL(ListLL *l, item val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastLL(ListLL *l, item val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListLL di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtLL(ListLL *l, item val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam ListLL pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstLL(ListLL *l, item *val);
/* I.S. ListLL l tidak kosong  */
/* F.S. Elemen pertama ListLL dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastLL(ListLL *l, item *val);
/* I.S. ListLL tidak kosong */
/* F.S. Elemen terakhir ListLL dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtLL(ListLL *l, int idx, item *val);
/* I.S. ListLL tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN ListLL ******************/
// void displayListt(ListLL l);
// // void printInfo(ListLL l);
// /* I.S. ListLL mungkin kosong */
// /* F.S. Jika ListLL tidak kosong, iai ListLL dicetak ke kanan: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika ListLL kosong : menulis [] */
// /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int lengthLL(ListLL l);
/* Mengirimkan banyaknya elemen ListLL; mengirimkan 0 jika ListLL kosong */

/****************** PROSES TERHADAP ListLL ******************/
// ListLL concatLL(ListLL l1, ListLL l2) ;
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah ListLL : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen ListLL l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

// boolean fSearch(ListLL L, AddressNode P);

item maxx(ListLL l);

// AddressNode adrMax(ListLL l);

item minn(ListLL l);

// AddressNode adrMin(ListLL l);

// void delAll(ListLL *l);

// void inverseList(ListLL *l);

// ListLL fCopyList(ListLL l);

// void cpAllocList(ListLL lin, ListLL *lout);

// ListLL fInverseList(ListLL l);

// void splitList(ListLL *l1, ListLL *l2, ListLL l);

#endif