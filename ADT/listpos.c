#include <stdio.h>
#include "listpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEFLP */
	int i = 0;
	while (i<100 && i >= 0){
		ELMTLP(*l, i) = VAL_UNDEFLP;
		i++;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthLP(ListPos l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
	int i = 0;
	while (i < CAPACITYLP && ELMTLP(l,i) != VAL_UNDEFLP){
		i++;
	}
	return i;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidLP(ListPos l, int i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
	return (i >= 0 && i <= (CAPACITYLP - 1));
}
boolean isIdxEffLP(ListPos l, int i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..lengthLP(l)-1 */
	return (i >=0 && i <= (lengthLP(l)-1));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyLP(ListPos l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
	return (lengthLP(l)== 0);
}
/* *** Test List penuh *** */
boolean isFullListLP(ListPos l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
	return (lengthLP(l) == CAPACITYLP);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListLP(ListPos *l){
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
	while (n<0 || n>CAPACITYLP){
		scanf("%d", &n);
	}
	for (i=0; i<n; i++){
		scanf("%d", &ELMTLP(*l, i));
		while (ELMTLP(*l,i)<0){
			scanf("%d", &ELMTLP(*l, i));
		}
	}
}
void displayListLP(ListPos l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
	printf("[");
	if (isEmptyLP(l)){
		printf("]");
	} else {
		int i;
		for (i=0; i<lengthLP(l); i++){
			if (i<(lengthLP(l)-1)){
				printf("%d,", ELMTLP(l,i));
			} else {
				printf("%d]", ELMTLP(l,i));
			}
		}
	}
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTabLP(ListPos l1, ListPos l2, boolean plus){
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
	ListPos l3;
	int i;
	CreateListPos(&l3);
	if (plus){
		for (i = 0; i<lengthLP(l1) ; i++){
			ELMTLP(l3, i) = ELMTLP(l1, i) + ELMTLP(l2, i);
		}
	} else {
		for (i = 0; i<lengthLP(l1) ; i++){
			ELMTLP(l3, i) = ELMTLP(l1, i) - ELMTLP(l2, i);
	}
	}
	return (l3);
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqualLP(ListPos l1, ListPos l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
	if (lengthLP(l1)==lengthLP(l2)){
		boolean eq = true;
		int i = 0;
		for (i>0 ; i < lengthLP(l1)-1 ; i++){
			if (ELMTLP(l1,i) != ELMTLP(l2,i)){
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
int indexOfLP(ListPos l, int val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMTLP(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEFLP */
/* Skema Searching yang digunakan bebas */
	int i = 0;
	if (!isEmptyLP(l)){
		while (i < lengthLP(l)){
			if (ELMTLP(l, i) == val){
				return (i);
			}
			i++;
		}
		return (IDX_UNDEFLP);
	} else {
		return (IDX_UNDEFLP);
	}
}

/* ********** NILAI EKSTREM ********** */
void extremesLP(ListPos l, int *max, int *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
	int i = 0;
	*max = ELMTLP(l, i);
	*min = ELMTLP(l, i);
	while (i < lengthLP(l)){
		if (ELMTLP(l,i) < *min){
			*min = ELMTLP(l,i);
		} 
		if (ELMTLP(l,i) > *max){
			*max = ELMTLP(l,i);
		}	
		i++;
	}
}

/* ********** OPERASI LAIN ********** */
boolean isAllEvenLP(ListPos l){
/* Menghasilkan true jika semua elemen l genap */
	int i = 0;
	boolean even = true;
	while (i < lengthLP(l)){
		if (ELMTLP(l,i)%2 != 0){
			even = false;
		}
		i++;
	}
	return (even);
}

/* ********** SORTING ********** */
void sortLP(ListPos *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
	int i = 0, j = 0;
	int store;
    int unsortLP_idx = lengthLP(*l)-1;
    boolean sortLP = false;
	if (asc){
        while (sortLP == false){
        sortLP = true;
        for(i= 0; i<unsortLP_idx; i++){
            if (ELMTLP(*l,i) > ELMTLP(*l,i+1)){
                store = ELMTLP(*l,i+1);
                ELMTLP(*l,i+1) = ELMTLP(*l,i);
                ELMTLP(*l,i) = store;
                sortLP = false;
                }
            }
        }
        unsortLP_idx--;
    }else{
        while (sortLP == false){
        sortLP = true; 
        for(i= 0; i<unsortLP_idx; i++){
            if (ELMTLP(*l,i) < ELMTLP(*l,i+1)){
                store = ELMTLP(*l,i+1);
                ELMTLP(*l,i+1) = ELMTLP(*l,i);
                ELMTLP(*l,i) = store;
                sortLP = false;
                }
            }
        }
        unsortLP_idx--;
	}
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastLP(ListPos *l, int val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN DI AKHIR ********** */
	ELMTLP(*l, lengthLP(*l)) = val;
}
void deleteLastLP(ListPos *l, int *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
	*val = ELMTLP(*l, lengthLP(*l)-1);
	ELMTLP(*l, lengthLP(*l)-1) = VAL_UNDEFLP; 
}

void swapLast(ListPos *l, int val){
/* I.S. List l tidak kosong dan val asumsi valid */
/* F.S. val menjadi elemen terakhir pada list, */
/*      Pada indeks elemen yang tadinya berisi val, nilainya menjadi nilai dari elemen terakhir */
	int temp;

	temp = ELMTLP(*l, lengthLP(*l)-1);
	ELMTLP(*l, lengthLP(*l)-1) = ELMTLP(*l, indexOfLP(*l, val));
	ELMTLP(*l, indexOfLP(*l, val)) = temp;
}