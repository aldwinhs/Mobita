
#include "list_linked.h"
#include <stdio.h>

void CreateListLL(ListLL *l){
    *l = NULL;
}

boolean isEmptyLL(ListLL l){
    return l == NULL;
}

item getElmtLL(ListLL l, int idx){
    int nomer = 0 ;
    AddressNode P = l;
    while (nomer < idx) {
        nomer += 1;
        P = NEXT(P);
    }
    return INFO(P);
}

void setElmtLL(ListLL *l, int idx, item val){
    int nomer = 0 ;
    AddressNode P = *l;
    while (nomer < idx) {
        nomer += 1;
        P = NEXT(P);
    }
    INFO(P) = val;
}

int indexOfLL(ListLL l, item val){
    int indeks = 0, hasil ;
    AddressNode P = l ;
    boolean found = false;
    while (P != NULL && !found) {
        if (INFO(P).lokSrc == val.lokSrc && INFO(P).lokDes == val.lokDes && INFO(P).jenisItem == val.jenisItem && INFO(P).waktuMasuk == val.waktuMasuk && INFO(P).waktuHangus == val.waktuHangus) {
            found = true;
        }
        else {
            indeks ++ ;
            P = NEXT(P);
        }
    }
    if (found) {
        hasil = indeks;
    }
    else {
        hasil = IDX_UNDEF;
    }
    return hasil ;
}

void insertFirstLL(ListLL *l, item val){
    AddressNode baru ;
    baru = newNode(val);
    if (baru != NULL) {
        NEXT(baru) = *l;
        *l = baru;
    }
}


void insertLastLL(ListLL *l, item val){
    AddressNode P, akhir ;
    /*if (isEmpty(&l)) {
        insertFirst(l, val);
    }*/
    if (*l == NULL) {
        insertFirstLL(l, val);
    }
    else {
        P = newNode(val) ;
        if (P != NULL) {
            akhir = *l ;
            while (NEXT(akhir) != NULL ) {
                akhir = NEXT(akhir);
            }
            NEXT(akhir) = P;
        }
    }
}

void insertAtLL(ListLL *l, item val, int idx){
    int angka;
    AddressNode P, lokasi ;
    if (idx == 0) {
        insertFirstLL(l,val);
    }
    else {
        P = newNode(val);
        if (P != NULL) {
            angka = 0;
            lokasi = *l;
            while (angka < idx - 1) {
                angka++ ;
                lokasi = NEXT(lokasi);
            }
            NEXT(P) = NEXT(lokasi);
            NEXT(lokasi) = P;
        }
    }
}

void deleteFirstLL(ListLL *l, item *val){
    AddressNode P = *l;
    *val = INFO(P) ;
    *l = NEXT(P);
    free(P) ;
}

void deleteLastLL(ListLL *l, item *val){
    AddressNode P, lokasi ;
    P = *l;
    lokasi = NULL ;
    while (NEXT(P) != NULL) {
        lokasi = P ;
        P = NEXT(P) ;
    }
    if (lokasi == NULL) {
        *l = NULL;
    }
    else {
        NEXT(lokasi) = NULL;
    }
    *val = INFO(P);
    free(P);
}

void deleteAtLL(ListLL *l, int idx, item *val){
    int angka;
    AddressNode P, lokasi ;
    if (idx == 0) {
        deleteFirstLL(l,val);
    }
    else {
        angka = 0;
        lokasi = *l;
        while (angka < idx - 1) {
            angka ++ ;
            lokasi = NEXT(lokasi) ;
        }
        P = NEXT(lokasi);
        *val= INFO(P);
        NEXT(lokasi) = NEXT(P);
        free(P);
    }
}

// void displayListt(ListLL l){
//     AddressNode P = l ;
//     printf("[");
//     if (!isEmpty(l)) {
//         while (NEXT(P) != NULL) {
//             printf("%d,", INFO(P));
//             P = NEXT(P);
//         }
//         printf("%d", INFO(P));
//     }
//     printf("]");
// }

// int length(ListLL l){
//     int panjang = 0;
//     AddressNode akhir = l;
//     while (akhir != NULL) {
//         panjang++ ;
//         akhir = NEXT(akhir);
//     }
//     return panjang;
// }

// boolean fSearch(ListLL L, AddressNode P){
//     AddressNode awal;
//     boolean ketemu = false;
//     awal = FIRST(L);
//     while(awal != NULL && !ketemu) {
//         if(awal == P) {
//             ketemu = true;
//         }
//         else{
//             awal = NEXT(awal);
//         }
//     }
//     return ketemu;
// }
/*
AddressNode searchPrec(ListLL L, item X){
    AddressNode Q = NULL, P= FIRST(L);
    boolean found= false;
    while ((P != NULL) && (!found)) {
        if (INFO(P) == X) {
            found = true;
        }
        else {
            Q = P;
            P = NEXT(P);
        }
    }
    if (!found) {
        Q = NULL;
    }
    return Q;
}
*/

item maxx(ListLL l){
    AddressNode P = l;
    int maxnum = INFO(P).waktuMasuk;
    item save;
    while(P != NULL) {
        if(INFO(P).waktuMasuk > maxnum) {
            save = INFO(P);
        }
        else {
            P = NEXT(P);
        }
    }
    return save;
}

// AddressNode adrMax(ListLL l){
//     AddressNode P = l, addmaxnum = l;
//     int maxnum = INFO(P).waktuMasuk;
//     while(P != NULL) {
//         if(INFO(P).waktuMasuk > maxnum) {
//             maxnum = INFO(P).waktuMasuk;
//             addmaxnum = P;
//         }
//         else {
//             P = NEXT(P);
//         }
//     }
//     return addmaxnum;
// }

item minn(ListLL l){
    AddressNode P = l;
    int minnum= INFO(P).waktuMasuk;
    while(P != NULL) {
        if(INFO(P).waktuMasuk < minnum) {
            minnum = INFO(P).waktuMasuk;
        }
        else {
            P = NEXT(P);
        }
    }
    return INFO(P);
}

// AddressNode adrMin(ListLL l){
//     AddressNode P = l, addminnum = l;
//     int minnum = INFO(P).waktuMasuk;
//     while(P != NULL) {
//         if(INFO(P).waktuMasuk < minnum) {
//             minnum = INFO(P).waktuMasuk;
//             addminnum = P;
//         }
//         else {
//             P = NEXT(P);
//         }
//     }
//     return addminnum;
// }

/****************** PROSES TERHADAP LIST ******************/
// ListLL concatLL(ListLL l1, ListLL l2) {
//     AddressNode P = l1;
//     ListLL l3;
//     item val;
//     CreateListLL(&l3);
//     while (P != NULL) {
//         insertLastLL(&l3, INFO(P));
//         P = NEXT(P);
//     }
//     P = l2;
//     while (P != NULL) {
//         insertLastLL(&l3, INFO(P));
//         P = NEXT(P);
//     }
//     return l3;
// }

// void delAll(ListLL *l){
//     item buangan;
//     while(!isEmpty(*l)) {
//         deleteFirst(l, &buangan);
//     }
// }

// void inverseList(ListLL *l){
//     AddressNode P = *l, awal=NULL, akhir;
//     while(P != NULL) {
//         akhir = P;
//         P = NEXT(P);
//         NEXT(akhir) = awal;
//         awal = akhir;
//     }
//     *l = akhir;
// }

// ListLL fCopyList(ListLL l){
//     ListLL kopian;
//     AddressNode P = l, baru;
//     boolean gagal = false;
//     CreateListLL(&kopian);
//     while(P != NULL && !gagal) {
//         baru = newNode(INFO(P));
//         if(baru != NULL) {
//             insertLast(&kopian, INFO(P));
//         }
//         else {
//             delAll(&kopian);
//             gagal = true;
//         }
//         P = NEXT(P);
//     }
//     return kopian;
// }

// void cpAllocList(ListLL lin, ListLL *lout){
//     *lout = fCopyList(lin);
// }

// ListLL fInverseList(ListLL l)
// {
//     ListLL sementara;
//     CreateListLL(&sementara);
//     if(isEmpty(l)) {
//         sementara = NULL;
//     }
//     else {
//         cpAllocList(l, &sementara);
//         inverseList(&sementara);
//     }
//     return sementara;
// }

// void copyList(ListLL *l1, ListLL *l2){
//     *l2 = *l1;
// }

// void splitList(ListLL *l1, ListLL *l2, ListLL l){
//     int indeks, panjang = length(l) / 2;
//     CreateListLLl1);
//     CreateListLL(l2);
//     AddressNode P;
//     P = l;
//     indeks = 0;
//     while(P != NULL) {
//         if(panjang > indeks) {
//             insertLastLL(l1,INFO(P));
//         } else {
//             insertLastLL(l2,INFO(P));
//         }
//         P = NEXT(P);
//         indeks += 1;
//     }
// }