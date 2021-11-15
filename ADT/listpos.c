#include <stdio.h>
#include "listpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
	int i = 0;
	while (i<100 && i >= 0){
		ELMT(*l, i) = VAL_UNDEF;
		i++;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
	int i = 0;
	while (i < CAPACITY && ELMT(l,i) != VAL_UNDEF){
		i++;
	}
	return i;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
	return (i >= 0 && i <= (CAPACITY - 1));
}
boolean isIdxEff(ListPos l, int i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
	return (i >=0 && i <= (length(l)-1));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
	return (length(l)== 0);
}
/* *** Test List penuh *** */
boolean isFullList(ListPos l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
	return (length(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l){
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
	int n,i;
	CreateListPos(l);
	scanf("%d", &n);
	while (n<0 || n>CAPACITY){
		scanf("%d", &n);
	}
	for (i=0; i<n; i++){
		scanf("%d", &ELMT(*l, i));
		while (ELMT(*l,i)<0){
			scanf("%d", &ELMT(*l, i));
		}
	}
}
void displayList(ListPos l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
	printf("[");
	if (isEmpty(l)){
		printf("]");
	} else {
		int i;
		for (i=0; i<length(l); i++){
			if (i<(length(l)-1)){
				printf("%d,", ELMT(l,i));
			} else {
				printf("%d]", ELMT(l,i));
			}
		}
	}
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus){
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
	ListPos l3;
	int i;
	CreateListPos(&l3);
	if (plus){
		for (i = 0; i<length(l1) ; i++){
			ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
		}
	} else {
		for (i = 0; i<length(l1) ; i++){
			ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
	}
	}
	return (l3);
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
	if (length(l1)==length(l2)){
		boolean eq = true;
		int i = 0;
		for (i>0 ; i < length(l1)-1 ; i++){
			if (ELMT(l1,i) != ELMT(l2,i)){
				eq = false;
			}
		}
		return eq;
	}
    else{
        return false;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
	int i = 0;
	if (!isEmpty(l)){
		while (i < length(l)){
			if (ELMT(l, i) == val){
				return (i);
			}
			i++;
		}
		return (IDX_UNDEF);
	} else {
		return (IDX_UNDEF);
	}
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
	int i = 0;
	*max = ELMT(l, i);
	*min = ELMT(l, i);
	while (i < length(l)){
		if (ELMT(l,i) < *min){
			*min = ELMT(l,i);
		} 
		if (ELMT(l,i) > *max){
			*max = ELMT(l,i);
		}	
		i++;
	}
}

/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l){
/* Menghasilkan true jika semua elemen l genap */
	int i = 0;
	boolean even = true;
	while (i < length(l)){
		if (ELMT(l,i)%2 != 0){
			even = false;
		}
		i++;
	}
	return (even);
}

/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
	int i = 0, j = 0;
	int store;
    int unsort_idx = length(*l)-1;
    boolean sort = false;
	if (asc){
        while (sort == false){
        sort = true;
        for(i= 0; i<unsort_idx; i++){
            if (ELMT(*l,i) > ELMT(*l,i+1)){
                store = ELMT(*l,i+1);
                ELMT(*l,i+1) = ELMT(*l,i);
                ELMT(*l,i) = store;
                sort = false;
                }
            }
        }
        unsort_idx--;
    }else{
        while (sort == false){
        sort = true; 
        for(i= 0; i<unsort_idx; i++){
            if (ELMT(*l,i) < ELMT(*l,i+1)){
                store = ELMT(*l,i+1);
                ELMT(*l,i+1) = ELMT(*l,i);
                ELMT(*l,i) = store;
                sort = false;
                }
            }
        }
        unsort_idx--;
	}
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN DI AKHIR ********** */
	ELMT(*l, length(*l)) = val;
}
void deleteLast(ListPos *l, ElType *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
	*val = ELMT(*l, length(*l)-1);
	ELMT(*l, length(*l)-1) = VAL_UNDEF; 
}

void swapLast(ListPos *l, ElType val){
/* I.S. List l tidak kosong dan val asumsi valid */
/* F.S. val menjadi elemen terakhir pada list, */
/*      Pada indeks elemen yang tadinya berisi val, nilainya menjadi nilai dari elemen terakhir */
	ElType temp;

	temp = ELMT(*l, length(*l)-1);
	ELMT(*l, length(*l)-1) = ELMT(*l, indexOf(*l, val));
	ELMT(*l, indexOf(*l, val)) = temp;
}