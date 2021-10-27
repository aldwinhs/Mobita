/* File : list_linked.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi Address dengan pointer */
/* ElType adalah integer */

#include "list_linked.h"
#include <stdio.h>
#include <stdlib.h>

typedef Address List;

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
	FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
	return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
	Address P = FIRST(l);
	int i = 0;
	while (i<idx){
		P = NEXT(P);
		i++;
	}
	return INFO(P);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
	Address P = FIRST(*l);
	int i = 0;
	while (i<idx){
		P = NEXT(P);
		i++;
	}
	INFO(P) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
	Address P = FIRST(l);
	boolean found = false;
	int idx = 0;
	while ((P != NULL) && (!found)){
		if (INFO(P) == val) found = true;
		else {
			idx++;
			P = NEXT(P);
		}
	}
	if (found) return idx ;
	else return IDX_UNDEF ;
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
	Address P = newNode(val);
	if (P != NULL){
		NEXT(P) = FIRST(*l);
		FIRST(*l) = P;
	}
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
	if (!isEmpty(*l)){
		Address P = newNode(val);
		if (P != NULL){
			Address last = FIRST(*l);
			while (NEXT(last) != NULL){
				last = NEXT(last);
			}
			NEXT(last) = P;
		}
	} else insertFirst(l, val);
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
	if (idx == 0) insertFirst(l, val);
	else {
		Address P = newNode(val);
		if (P != NULL){
			int count = 0;
			Address loc = FIRST(*l);
			while (count < idx-1){
				count++;
				loc = NEXT(loc);
			}
			NEXT(P) = NEXT(loc);
			NEXT(loc) = P;
		}
	}
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
	Address P = FIRST(*l);
	*val = INFO(P);
	FIRST(*l) = NEXT(P);
	free(P);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
	Address P = FIRST(*l);
	Address loc = NULL;
	while (NEXT(P) != NULL){
		loc = P;
		P = NEXT(P);
	}
	if (loc == NULL) FIRST(*l) = NULL;
	else NEXT(loc) = NULL;
	*val = INFO(P);
	free(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
	int count;
	if (idx == 0) deleteFirst(l, val);
	else {
		count = 0;
		Address loc = FIRST(*l);
		while (count < idx-1){
			count++;
			loc = NEXT(loc);
		}
		Address P = NEXT(loc);
		*val = INFO(P);
		NEXT(loc) = NEXT(P);
		free(P);
	}
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
	if (isEmpty(l)){
		printf("[]");
	} else {
		printf("[");
		Address P = FIRST(l);
		while (P != NULL){
			printf("%d", INFO(P));
			P = NEXT(P);
			
			if (P != NULL) printf(",");
		}
		printf("]");
	}
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
	int count = 0;
	if (isEmpty(l)) return 0;
	else {
		Address P = FIRST(l);
		while (P != NULL){
			P = NEXT(P);
			count++;
		}
		return count;
	}
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
	Address P = FIRST(l1);
	List l3;
	CreateList(&l3);
	while (P != NULL){
		insertLast(&l3, INFO(P));
		P = NEXT(P);
	}
	P = FIRST(l2);
	while (P != NULL){
		insertLast(&l3, INFO(P));
		P = NEXT(P);
	}
	return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

