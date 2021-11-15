
#include "list_linked.h"
#include <stdio.h>

void CreateList(List *l){
    *l = NULL;
}

boolean isEmpty(List l){
    return l == NULL;
}

ElType getElmt(List l, int idx){
    ElType nomer = 0 ;
    Address P = l;
    while (nomer < idx) {
        nomer += 1;
        P = NEXT(P);
    }
    return INFO(P);
}

void setElmt(List *l, int idx, ElType val){
    ElType nomer = 0 ;
    Address P = *l;
    while (nomer < idx) {
        nomer += 1;
        P = NEXT(P);
    }
    INFO(P) = val;
}

int indexOf(List l, ElType val){
    int indeks = 0, hasil ;
    Address P = l ;
    boolean found = false;
    while (P != NULL && !found) {
        if (INFO(P) == val) {
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

void insertFirst(List *l, ElType val){
    Address baru ;
    baru = newNode(val);
    if (baru != NULL) {
        NEXT(baru) = *l;
        *l = baru;
    }
}


void insertLast(List *l, ElType val){
    Address P, akhir ;
    /*if (isEmpty(&l)) {
        insertFirst(l, val);
    }*/
    if (*l == NULL) {
        insertFirst(l, val);
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

void insertAt(List *l, ElType val, int idx){
    int angka;
    Address P, lokasi ;
    if (idx == 0) {
        insertFirst(l,val);
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

void deleteFirst(List *l, ElType *val){
    Address P = *l;
    *val = INFO(P) ;
    *l = NEXT(P);
    free(P) ;
}

void deleteLast(List *l, ElType *val){
    Address P, lokasi ;
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

void deleteAt(List *l, int idx, ElType *val){
    int angka;
    Address P, lokasi ;
    if (idx == 0) {
        deleteFirst(l,val);
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

void displayList(List l){
    Address P = l ;
    printf("[");
    if (!isEmpty(l)) {
        while (NEXT(P) != NULL) {
            printf("%d,", INFO(P));
            P = NEXT(P);
        }
        printf("%d", INFO(P));
    }
    printf("]");
}

int length(List l){
    int panjang = 0;
    Address akhir = l;
    while (akhir != NULL) {
        panjang++ ;
        akhir = NEXT(akhir);
    }
    return panjang;
}

boolean fSearch(List L, Address P){
    Address awal;
    boolean ketemu = false;
    awal = FIRST(L);
    while(awal != NULL && !ketemu) {
        if(awal == P) {
            ketemu = true;
        }
        else{
            awal = NEXT(awal);
        }
    }
    return ketemu;
}

Address searchPrec(List L, ElType X){
    Address Q = NULL, P= FIRST(L);
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

ElType max(List l){
    Address P = l;
    ElType maxnum= INFO(P);
    while(P != NULL) {
        if(INFO(P) > maxnum) {
            maxnum = INFO(P);
        }
        else {
            P = NEXT(P);
        }
    }
    return maxnum;
}

Address adrMax(List l){
    Address P = l, addmaxnum = l;
    ElType maxnum = INFO(P);
    while(P != NULL) {
        if(INFO(P) > maxnum) {
            maxnum = INFO(P);
            addmaxnum = P;
        }
        else {
            P = NEXT(P);
        }
    }
    return addmaxnum;
}

ElType min(List l){
    Address P = l;
    ElType minnum= INFO(P);
    while(P != NULL) {
        if(INFO(P) < minnum) {
            minnum = INFO(P);
        }
        else {
            P = NEXT(P);
        }
    }
    return minnum;
}

Address adrMin(List l){
    Address P = l, addminnum = l;
    ElType minnum = INFO(P);
    while(P != NULL) {
        if(INFO(P) < minnum) {
            minnum = INFO(P);
            addminnum = P;
        }
        else {
            P = NEXT(P);
        }
    }
    return addminnum;
}

float average(List l){
    int panjang = length(l);
    float total = 0;
    Address p = l;
    while(p != NULL) {
        total += INFO(p);
        p = NEXT(p);
    }
    return total / panjang;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    Address P = l1;
    List l3;
    ElType val;
    CreateList(&l3);
    while (P != NULL) {
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }
    P = l2;
    while (P != NULL) {
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }
    return l3;
}

void delAll(List *l){
    ElType buangan;
    while(!isEmpty(*l)) {
        deleteFirst(l, &buangan);
    }
}

void inverseList(List *l){
    Address P = *l, awal=NULL, akhir;
    while(P != NULL) {
        akhir = P;
        P = NEXT(P);
        NEXT(akhir) = awal;
        awal = akhir;
    }
    *l = akhir;
}

List fInverseList(List l)
{
    List sementara;
    CreateList(&sementara);
    if(isEmpty(l)) {
        sementara = NULL;
    }
    else {
        cpAllocList(l, &sementara);
        inverseList(&sementara);
    }
    return sementara;
}

void copyList(List *l1, List *l2){
    *l2 = *l1;
}

List fCopyList(List l){
    List kopian;
    Address P = l, baru;
    boolean gagal = false;
    CreateList(&kopian);
    while(P != NULL && !gagal) {
        baru = newNode(INFO(P));
        if(baru != NULL) {
            insertLast(&kopian, INFO(P));
        } 
        else {
            delAll(&kopian);
            gagal = true;
        }
        P = NEXT(P);
    }
    return kopian;
}

void cpAllocList(List lin, List *lout){
    *lout = fCopyList(lin);
}

void splitList(List *l1, List *l2, List l){
    int indeks, panjang = length(l) / 2;;
    CreateList(l1);
    CreateList(l2);
    Address P;
    P = l;
    indeks = 0;
    while(P != NULL) {
        if(panjang > indeks) {
            insertLast(l1,INFO(P));
        } else {
            insertLast(l2,INFO(P));
        }
        P = NEXT(P);
        indeks += 1;
    }
}