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
    Address alamat = l;
    while (nomer < idx) {
        nomer += 1;
        alamat = NEXT(alamat);
    }
    return INFO(alamat);
}

void setElmt(List *l, int idx, ElType val){
    ElType nomer = 0 ;
    Address alamat = *l;
    while (nomer < idx) {
        nomer += 1;
        alamat = NEXT(alamat);
    }
    INFO(alamat) = val;
}

int indexOf(List l, ElType val){
    int indeks = 0, hasil ;
    Address alamat = l ;
    boolean found = false;
    while (alamat != NULL && !found) {
        if (INFO(alamat) == val) {
            found = true;
        }
        else {
            indeks ++ ;
            alamat = NEXT(alamat);
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
    Address alamat, akhir ;
    /*if (isEmpty(&l)) {
        insertFirst(l, val);
    }*/
    if (*l == NULL) {
        insertFirst(l, val);
    }
    else {
        alamat = newNode(val) ;
        if (alamat != NULL) {
            akhir = *l ;
            while (NEXT(akhir) != NULL ) {
                akhir = NEXT(akhir);
            }
            NEXT(akhir) = alamat;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
    int angka;
    Address alamat, lokasi ;
    if (idx == 0) {
        insertFirst(l,val);
    }
    else {
        alamat = newNode(val);
        if (alamat != NULL) {
            angka = 0;
            lokasi = *l;
            while (angka < idx - 1) {
                angka++ ;
                lokasi = NEXT(lokasi);
            }
            NEXT(alamat) = NEXT(lokasi);
            NEXT(lokasi) = alamat;
        }
    }
}

void deleteFirst(List *l, ElType *val){
    Address alamat = *l;
    *val = INFO(alamat) ;
    *l = NEXT(alamat);
    free(alamat) ;
}

void deleteLast(List *l, ElType *val){
    Address alamat, lokasi ;
    alamat = *l;
    lokasi = NULL ;
    while (NEXT(alamat) != NULL) {
        lokasi = alamat ;
        alamat = NEXT(alamat) ;
    }
    if (lokasi == NULL) {
        *l = NULL;
    }
    else {
        NEXT(lokasi) = NULL;
    }
    *val = INFO(alamat);
    free(alamat);
}

void deleteAt(List *l, int idx, ElType *val){
    int angka;
    Address alamat, lokasi ;
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
        alamat = NEXT(lokasi);
        *val= INFO(alamat);
        NEXT(lokasi) = NEXT(alamat);
        free(alamat);
    }
}

void displayList(List l){
    Address alamat = l ;
    printf("[");
    if (!isEmpty(l)) {
        while (NEXT(alamat) != NULL) {
            printf("%d,", INFO(alamat));
            alamat = NEXT(alamat);
        }
        printf("%d", INFO(alamat));
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
    Address sebelum = NULL, sekarang= FIRST(L);
    boolean found= false;
    while ((sekarang != NULL) && (!found)) {
        if (INFO(sekarang) == X) {
            found = true;
        }
        else {
            sebelum = sekarang;
            sekarang = NEXT(sekarang);
        }
    }
    if (!found) {
        sebelum = NULL;
    }
    return sebelum;
}

ElType max(List l){
    Address sekarang = l;
    ElType terbesar= INFO(sekarang);
    while(sekarang != NULL) {
        if(INFO(sekarang) > terbesar) {
            terbesar = INFO(sekarang);
        }
        else {
            sekarang = NEXT(sekarang);
        }
    }
    return terbesar;
}

Address adrMax(List l){
    Address sekarang = l, addTerbesar = l;
    ElType terbesar = INFO(sekarang);
    while(sekarang != NULL) {
        if(INFO(sekarang) > terbesar) {
            terbesar = INFO(sekarang);
            addTerbesar = sekarang;
        }
        else {
            sekarang = NEXT(sekarang);
        }
    }
    return addTerbesar;
}

ElType min(List l){
    Address sekarang = l;
    ElType terkecil= INFO(sekarang);
    while(sekarang != NULL) {
        if(INFO(sekarang) < terkecil) {
            terkecil = INFO(sekarang);
        }
        else {
            sekarang = NEXT(sekarang);
        }
    }
    return terkecil;
}

Address adrMin(List l){
    Address sekarang = l, addTerkecil = l;
    ElType terkecil = INFO(sekarang);
    while(sekarang != NULL) {
        if(INFO(sekarang) < terkecil) {
            terkecil = INFO(sekarang);
            addTerkecil = sekarang;
        }
        else {
            sekarang = NEXT(sekarang);
        }
    }
    return addTerkecil;
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
    Address alamat = l1;
    List l3;
    ElType val;
    CreateList(&l3);
    while (alamat != NULL) {
        insertLast(&l3, INFO(alamat));
        alamat = NEXT(alamat);
    }
    alamat = l2;
    while (alamat != NULL) {
        insertLast(&l3, INFO(alamat));
        alamat = NEXT(alamat);
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
    Address sekarang = *l, awal=NULL, akhir;
    while(sekarang != NULL) {
        akhir = sekarang;
        sekarang = NEXT(sekarang);
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
    Address sekarang = l, baru;
    boolean gagal = false;
    CreateList(&kopian);
    while(sekarang != NULL && !gagal) {
        baru = newNode(INFO(sekarang));
        if(baru != NULL) {
            insertLast(&kopian, INFO(sekarang));
        } 
        else {
            delAll(&kopian);
            gagal = true;
        }
        sekarang = NEXT(sekarang);
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
    Address sekarang;
    sekarang = l;
    indeks = 0;
    while(sekarang != NULL) {
        if(panjang > indeks) {
            insertLast(l1,INFO(sekarang));
        } else {
            insertLast(l2,INFO(sekarang));
        }
        sekarang = NEXT(sekarang);
        indeks += 1;
    }
}