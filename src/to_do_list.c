#include "to_do_list.h"
#include <stdio.h>
/* Stack Version */
/*
void displayToDo(CollOfItems itemsinConfig, int currTime) {
    // [TO DO] Untuk testcase aja dibuat 4, nanti 4 diganti dengan banyak item yang dibaca file konfigurasi
    int amountOfItems = 4;
    int i;
    for(i = 0; i < amountOfItems;i++) {
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
    int i;
    Stack new;
    CreateStack(&new);
    int N; // N Adalah banyak item di file konfigurasi
    for(i = 0; i < N; i++) {
        push(&new, itemsinConfig.buffer[i]);
    }
    for(i = 0; i < N; i++) {
        if(TOP(new).waktuHangus <= currTime && !(TOP(new).beenDroppedOf) && !(TOP(new).beenPickedUp)) {
            printf("%d. %s (Tujuan: %s)\n", i + 1); // LANJUT DI SINI
        }
    }

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
        printf("%d. %s (Tujuan: %s)\n", i + 1, TOP(new).lokSrc, TOP(new).lokDes); // ini print kebalik [NANTI EDIT LAGI]
        pop(&new, &throw);
    }
}