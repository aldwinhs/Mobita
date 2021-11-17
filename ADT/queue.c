/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#include "queue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEFF */
/* - Index tail bernilai IDX_UNDEFF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
	IDX_HEAD(*q) = IDX_UNDEFF;
	IDX_TAIL(*q) = IDX_UNDEFF;
	int i;
}

/* ********* Prototype ********* */
boolean isEmptyQ(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
	return (IDX_HEAD(q)==IDX_UNDEFF && IDX_TAIL(q)==IDX_UNDEFF);
	
}
boolean isFull(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITYQUEUE-1 */
	return (IDX_HEAD(q)==0 && IDX_TAIL(q)==CAPACITYQUEUE-1);
}
int length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
	if (isEmptyQ(q)) return 0;
	else {
		return (IDX_TAIL(q) - IDX_HEAD(q) + 1);	
	}
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElTypequeue val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
	if (!isEmptyQ(*q)){
		if (IDX_TAIL(*q)==(CAPACITYQUEUE-1)){
			int i = IDX_HEAD(*q);
			while (i<=IDX_TAIL(*q)){
				(*q).buffer[i-IDX_HEAD(*q)] = (*q).buffer[i];
				i++;
			}
			IDX_TAIL(*q) -= IDX_HEAD(*q);
			IDX_HEAD(*q) = 0;
		}
		IDX_TAIL(*q)++;
	} else {
		IDX_HEAD(*q) = 0;
		IDX_TAIL(*q) = 0;
	}
	TAIL(*q) = val;
}

void dequeue(Queue *q, ElTypequeue *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
	*val = HEAD(*q);
	if (IDX_HEAD(*q) != IDX_TAIL(*q)) IDX_HEAD(*q)++;
	else {
		IDX_HEAD(*q)=IDX_UNDEFF;
		IDX_TAIL(*q)=IDX_UNDEFF;
	}
}

/* *** Display Queue *** */
// void displayQueue(Queue q){
// /* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
//    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
//    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
// /* I.S. q boleh kosong */
// /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika Queue kosong : menulis [] */	
// 	if (isEmptyQ(q)) printf("[]");
// 	else {
// 		printf("[");
// 		int i = IDX_HEAD(q);
// 		while (i<=IDX_TAIL(q)){
// 			printf("%d", (q).buffer[i]);
// 			if (i!=IDX_TAIL(q)) printf(",");
// 			i++;
// 		}
// 		printf("]");
// 	}
// }

