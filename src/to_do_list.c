#include "to_do_list.h"
#include <stdio.h>

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