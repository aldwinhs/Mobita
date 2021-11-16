#include "to_do_list.h"
#include <stdio.h>
/* Stack Version */
/*
void displayToDo(CollOfItems itemsinConfig, int currTime) {
    // [TO DO] Untuk testcase aja dibuat 4, nanti 4 diganti dengan banyak item yang dibaca file konfigurasi
    int amountOfItems = 4;
    int i;
    for(i = 0; i < amountOfItems;i++) { // belum di sort
        if(itemsinConfig.buffer[i].waktuMasuk <= currTime && !(itemsinConfig.buffer[i].beenDroppedOf) && !(itemsinConfig.buffer[i].beenPickedUp)) {
            printf("%d. %s -> %s (%s)\n", i + 1, itemsinConfig.buffer[i].lokSrc, itemsinConfig.buffer[i].lokDes, itemsinConfig.buffer[i].jenisItem);
        }
    }
}

void displayInProgr(Tas s) {
    int i, saveIdxTop;
    saveIdxTop = s.idxTop;

    printf("Pesanan yang sedang diantarkan:\n");
    for (i = 0; i < (saveIdxTop + 1); i++) {
        printf("%d. %s (Tujuan: %s)\n", i + 1, s.buffer[i].jenisItem, s.buffer[i].lokDes);
        s.idxTop--;
    }
    s.idxTop = saveIdxTop;
}
*/
/* Stack Linked List Version */

void displayToDo(CollOfItems itemsinConfig, int currTime) {
    List ori, copy;
    ElType minItem, throw;
    int i, N, idks, num = 1; // N adalah banyak item di file konfigurasi

    CreateList(&ori);
    CreateList(&copy);

    for(i = 0; i < N; i++) {
        insertLast(&ori, itemsinConfig.buffer[i]);
    }
    while(!isEmpty(ori)) {
        minItem = minn(ori);
        idks = indexOf(&ori, minItem);
        insertFirst(&copy, minItem);
        deleteAt(&ori, idks, &minItem);
    }
    for(i = 0; i < N; i ++) {
        if(INFO(FIRST(copy)).waktuMasuk <= currTime && !(INFO(FIRST(copy)).beenDroppedOf) && !(INFO(FIRST(copy)).beenPickedUp)) {
            if (INFO(FIRST(copy)).jenisItem == "P") {
                printf("%d. %s -> %s (%s, sisa waktu %d)\n", num, INFO(FIRST(copy)).lokSrc, INFO(FIRST(copy)).lokDes, INFO(FIRST(copy)).jenisItem, INFO(FIRST(copy)).waktuHangus);
            } else {
                printf("%d. %s -> %s (%s)\n", num, INFO(FIRST(copy)).lokSrc, INFO(FIRST(copy)).lokDes, INFO(FIRST(copy)).jenisItem);
            }
            num++;
            deleteFirst(&copy, &throw);
        }
    }
    /*
    int i, num, N; // N Adalah banyak item di file konfigurasi
    item throw;
    Stack new;
    CreateStack(&new);
    // ListPos toBeSorted;
    // CreateListPos(&toBeSorted);

    for(i = 0; i < N; i++) {
        push(&new, itemsinConfig.buffer[i]);
         // ELMT(toBeSorted, i) = itemsinConfig.buffer[i].waktuMasuk;
    }
    // sort(&toBeSorted, true);
    for (i = 0; i < N; i++) {
        if (TOPLS(new).waktuMasuk <= currTime && !(TOPLS(new).beenDroppedOf) && !(TOPLS(new).beenPickedUp)) {
            if (TOPLS(new).jenisItem == "P") {
                printf("%d. %s -> %s (%s, sisa waktu %d)\n", num, TOPLS(new).lokSrc, TOPLS(new).lokDes, TOPLS(new).jenisItem, TOPLS(new).waktuHangus);
            } else {
                printf("%d. %s -> %s (%s)\n", num, TOPLS(new).lokSrc, TOPLS(new).lokDes, TOPLS(new).jenisItem); // LANJUT DI SINI
            }
            pop(&new, &throw);
        }
    }
     */
}

void displayInProgr(Tas s) {
    int i;
    item throw;
    Stack new;
    CreateStack(&new);

    for(i = 0; i < CURRENT_CAP(s); i++) {
        push(&new, s.buffer[i]);
    }
    for(i = 0; i < CURRENT_CAP(s); i++) {
        printf("%d. %s (Tujuan: %s)\n", i + 1, TOPLS(new).jenisItem, TOPLS(new).lokDes);
        pop(&new, &throw);
    }
}