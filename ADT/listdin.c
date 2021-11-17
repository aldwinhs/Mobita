
#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
	NEFFLD(*l) = 0;
	CAPACITYLD(*l) = capacity;
	BUFFERLD(*l) = (POINT *)malloc(capacity* sizeof (POINT));
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateLD(ListDin *l){
	CAPACITYLD(*l) = 0;
	NEFFLD(*l) = 0;
	free(BUFFERLD(*l));
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITYLD(l)=0; NEFFLD(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthLD(ListDin l){
	return (l.nEff);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

// /* *** Selektor INDEKS *** */
// IdxType getLastIdx(ListDin l){
// 	return (length(l)-1);
// }
// /* Prekondisi : List l tidak kosong */
// /* Mengirimkan indeks elemen l terakhir */

// /* ********** Test Indeks yang valid ********** */
// boolean isIdxValid(ListDin l, int i){
// 	return ((i < l.capacity) && (i >= 0));
// }
// /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
// /* yaitu antara indeks yang terdefinisi utk container*/
// boolean isIdxEff(ListDin l, IdxType i){
// 	return ((i>=0) && (i <= l.nEff));
// }
// /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
// /* yaitu antara 0..NEFFLD(l) */

// /* ********** TEST KOSONG/PENUH ********** */
// /* *** Test list kosong *** */
// boolean isEmpty(ListDin l){
// 	return (l.nEff == 0);
// }
// /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
// /* *** Test list penuh *** */
// boolean isFull(ListDin l){
// 	return (l.nEff == l.capacity);
// }
// /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

// /* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
// /* *** Mendefinisikan isi list dari pembacaan *** */
// void readList(ListDin *l){
// 	int N, i;
// 	scanf("%d", &N);
// 	while ((N<0) || (N>CAPACITYLD(*l))){
// 		scanf("%d", &N);
// 	}
// 	NEFFLD(*l) = N;
// 	for (i=0; i<N; i++){
// 		scanf("%d", &ELMTLD(*l, i));
// 	}
// }
// /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
// /* F.S. List l terdefinisi */
// /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
// /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
// /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITYLD(l) */
// /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
// /* 2. Jika 0 < N <= CAPACITYLD(l); Lakukan N kali: Baca elemen mulai dari indeks
//       0 satu per satu diakhiri enter */
// /*    Jika N = 0; hanya terbentuk l kosong */
// void displayList(ListDin l){
// 	printf("[");
// 	if (isEmpty(l)){
// 		printf("]");
// 	} else {
// 		int i;
// 		for (i=0; i<length(l); i++){
// 			if (i<length(l)-1){
// 				printf("%d,", ELMTLD(l,i));
// 			} else {
// 				printf("%d]", ELMTLD(l,i));
// 			}
// 		}
// 	}
// }
// /* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
//    antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
//    di tengah, atau di belakang, termasuk spasi dan enter */
// /* I.S. l boleh kosong */
// /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika list kosong : menulis [] */

// /* ********** OPERATOR ARITMATIKA ********** */
// /* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
// ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
// 	ListDin l3;
// 	int i;
// 	CreateListDin(&l3, length(l1));
// 	NEFFLD(l3) = NEFFLD(l1);
// 	if (plus){
// 		for (i = 0; i<length(l1) ; i++){
// 			ELMTLD(l3, i) = ELMTLD(l1, i) + ELMTLD(l2, i);
// 		}
// 	} else {
// 		for (i = 0; i<length(l1) ; i++){
// 			ELMTLD(l3, i) = ELMTLD(l1, i) - ELMTLD(l2, i);
// 		}
// 	}
// 	return (l3);
// }
// /* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
// /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
// /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

// /* ********** OPERATOR RELASIONAL ********** */
// /* *** Operasi pembandingan list : < =, > *** */
// boolean isListEqual(ListDin l1, ListDin l2){
// 	if (l1.nEff==l2.nEff){
// 		boolean eq = true;
// 		int i = 0;
// 		for (i>0 ; i < length(l1)-1 ; i++){
// 			if (ELMTLD(l1,i) != ELMTLD(l2,i)){
// 				eq = false;
// 			}
// 		}
// 		return eq;
// 	}
//     else{
//         return false;
//     }
// }
// /* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

// /* ********** SEARCHING ********** */
// /* ***  Perhatian : list boleh kosong!! *** */
// IdxType indexOf(ListDin l, ElType val){
// 	int i = 0;
// 	if (!isEmpty(l)){
// 		while (i < length(l)){
// 			if (ELMTLD(l, i) == val){
// 				return (i);
// 			}
// 			i++;
// 		}
// 		return (IDX_UNDEF);
// 	} else {
// 		return (IDX_UNDEF);
// 	}
// }
// /* Search apakah ada elemen List l yang bernilai val */
// /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
// /* Jika tidak ada, mengirimkan IDX_UNDEF */
// /* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
// /* Skema Searching yang digunakan bebas */

// /* ********** NILAI EKSTREM ********** */
// void extremes(ListDin l, ElType *max, ElType *min){
// 	int i = 0;
// 	*max = ELMTLD(l, i);
// 	*min = ELMTLD(l, i);
// 	while (i < l.nEff){
// 		if (ELMTLD(l,i) < *min){
// 			*min = ELMTLD(l,i);
// 		} 
// 		if (ELMTLD(l,i) > *max){
// 			*max = ELMTLD(l,i);
// 		}	
// 		i++;
// 	}
// }
// /* I.S. List l tidak kosong */
// /* F.S. max berisi nilai maksimum l;
//         min berisi nilai minimum l */

// /* ********** OPERASI LAIN ********** */
// void copyList(ListDin lIn, ListDin *lOut){
// 	ListDin lCopy;
// 	CreateListDin(&lCopy, lIn.capacity);
// 	lCopy.nEff = lIn.nEff;
// 	int i;
// 	for (i=0 ; i < length(lIn); i++){
// 		ELMTLD(lCopy, i) = ELMTLD(lIn, i);
// 	}
// 	*lOut = lCopy;
// }
// /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
// /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
// /* Proses : Menyalin isi lIn ke lOut */
// ElType sumList(ListDin l){
// 	int i;
// 	ElType sum = 0;
// 	for (i=0 ; i < length(l) ; i++){
// 		sum += ELMTLD(l, i);
// 	}
// 	return sum;
// }
// /* Menghasilkan hasil penjumlahan semua elemen l */
// /* Jika l kosong menghasilkan 0 */
// int countVal(ListDin l, ElType val){
// 	int count = 0;
// 	int i;
// 	for (i=0 ; i < length(l) ; i++){
// 		if (val == ELMTLD(l,i)){
// 			count++;
// 		}
// 	}
// 	return count;
// }
// /* Menghasilkan berapa banyak kemunculan val di l */
// /* Jika l kosong menghasilkan 0 */
// boolean isAllEven(ListDin l){
// 	boolean even = true;
// 	int i = 0;
// 	while (even && i < length(l)){
// 		if (ELMTLD(l, i)%2 != 0){
// 			even = false;
// 		}
// 		i++;
// 	}
// 	return even;
// }
// /* Menghasilkan true jika semua elemen l genap. l boleh kosong */

// /* ********** SORTING ********** */
// void sort(ListDin *l, boolean asc){
// 	int i = 0, j = 0;
// 	int store;
//     int unsort_idx = length(*l)-1;
//     boolean sort = false;
// 	if (asc){
//         while (sort == false){
//         sort = true;
//         for(i= 0; i<unsort_idx; i++){
//             if (ELMTLD(*l,i) > ELMTLD(*l,i+1)){
//                 store = ELMTLD(*l,i+1);
//                 ELMTLD(*l,i+1) = ELMTLD(*l,i);
//                 ELMTLD(*l,i) = store;
//                 sort = false;
//                 }
//             }
//         }
//         unsort_idx--;
//     }else{
//         while (sort == false){
//         sort = true; 
//         for(i= 0; i<unsort_idx; i++){
//             if (ELMTLD(*l,i) < ELMTLD(*l,i+1)){
//                 store = ELMTLD(*l,i+1);
//                 ELMTLD(*l,i+1) = ELMTLD(*l,i);
//                 ELMTLD(*l,i) = store;
//                 sort = false;
//                 }
//             }
//         }
//         unsort_idx--;
// 	}
// }
// /* I.S. l boleh kosong */
// /* F.S. Jika asc = true, l terurut membesar */
// /*      Jika asc = false, l terurut mengecil */
// /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
//    algoritma bebas */

// /* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
// /* *** Menambahkan elemen terakhir *** */
// void insertLast(ListDin *l, ElType val){
// 	ELMTLD(*l, getLastIdx(*l)+1) = val;
// 	NEFFLD(*l)++;
// }
// /* Proses: Menambahkan val sebagai elemen terakhir list */
// /* I.S. List l boleh kosong, tetapi tidak penuh */
// /* F.S. val adalah elemen terakhir l yang baru */
// /* ********** MENGHAPUS ELEMEN ********** */
// void deleteLast(ListDin *l, ElType *val){
// 	*val = ELMTLD(*l, getLastIdx(*l));
// 	NEFFLD(*l)--;
// }
// /* Proses : Menghapus elemen terakhir list */
// /* I.S. List tidak kosong */
// /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
// /*      Banyaknya elemen list berkurang satu */
// /*      List l mungkin menjadi kosong */

// /* ********* MENGUBAH UKURAN ARRAY ********* */
// void growList(ListDin *l, int num){
// 	ListDin lOut;
// 	int i=0;
// 	CreateListDin(&lOut, CAPACITYLD(*l) + num);
// 	lOut.nEff = NEFFLD(*l);
	
// 	while (i < length(lOut)){
// 		ELMTLD(lOut, i) = ELMTLD(*l, i);
// 		i++;
// 	}
// 	dealocate(l);
// 	*l = lOut;
// }
// /* Proses : Menambahkan capacity l sebanyak num */
// /* I.S. List sudah terdefinisi */
// /* F.S. Ukuran list bertambah sebanyak num */

// void shrinkList(ListDin *l, int num){
// 	ListDin lOut;
// 	int i=0;
// 	CreateListDin(&lOut, CAPACITYLD(*l) - num);
// 	lOut.nEff = NEFFLD(*l);
	
// 	while (i < length(lOut)){
// 		ELMTLD(lOut, i) = ELMTLD(*l, i);
// 		i++;
// 	}
// 	dealocate(l);
// 	*l = lOut;
// }
// /* Proses : Mengurangi capacity sebanyak num */
// /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
// /* F.S. Ukuran list berkurang sebanyak num. */

// void compactList(ListDin *l){
// 	ListDin lOut;
// 	int i=0;
// 	CreateListDin(&lOut, NEFFLD(*l));
// 	lOut.nEff = NEFFLD(*l);
	
// 	while (i < length(lOut)){
// 		ELMTLD(lOut, i) = ELMTLD(*l, i);
// 		i++;
// 	}
// 	dealocate(l);
// 	*l = lOut;
// }
// /* Proses : Mengurangi capacity sehingga nEff = capacity */
// /* I.S. List lidak kosong */
// /* F.S. Ukuran nEff = capacity */