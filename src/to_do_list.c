#include "to_do_list.h"
#include <stdio.h>
/* Stack Version */

// void displayToDo(CollOfItems itemsinConfig, int currTime, int amtItmConfig) {
//     // [TO DO] Untuk testcase aja dibuat 4, nanti 4 diganti dengan banyak item yang dibaca file konfigurasi
//     int i;
//     for(i = 0; i < amtItmConfig;i++) { // belum di sort
//         if(itemsinConfig.buffer[i].waktuMasuk <= currTime /*&& !(itemsinConfig.buffer[i].beenDroppedOf) && !(itemsinConfig.buffer[i].beenPickedUp)*/) {
//             printf("%d. %s -> %s (%s)\n", i + 1, itemsinConfig.buffer[i].lokSrc, itemsinConfig.buffer[i].lokDes, itemsinConfig.buffer[i].jenisItem);
//         }
//     }
// }
/*
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
/* Stack Linked List_MODX Version */
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

void displayInProgr(Tas s) {
    int i;
    item throw;
    Stack new;
    CreateStack(&new);

    for(i = 0; i < CURRENT_CAP(s); i++) {
        push(&new, s.buffer[i]);
    }
    if(!isTasEmpty(s)) {
        for(i = 0; i < CURRENT_CAP(s); i++) {
            printf("%d. %c (Tujuan: %c)\n", i + 1, TOPLS(new).jenisItem, TOPLS(new).lokDes);
            pop(&new, &throw);
        }
    } else {
        printf("Tas kosong, tidak ada barang yang sedang diproses\n");
    }
}

//currentToDo tidak di sorting, hanya filter ke yg pesanan masuk sudah pas
CollOfItems currentToDo(CollOfItems *stackToDo, int currTime, int amtItmConfig) {
    // sorting hanya berdasarkan pesanan masuk
    ListLL ori, copy;
    AddressNode p;
    item minItem, throw;
    CollOfItems memenuhiReq;
    int i, idks;

    CreateListLL(&ori);
    CreateListLL(&copy);
    CreateTas(&memenuhiReq);
    for(i = 0; i < amtItmConfig ; i++) {
        insertLastLL(&ori, (*stackToDo).buffer[i]);
    }
    while(!isEmptyLL(ori)) {
        minItem = minn(ori);
        idks = indexOfLL(ori, minItem);
        insertFirstLL(&copy, minItem);
        deleteAtLL(&ori, idks, &minItem);
    } // sorting tapi bentar
    // return copy;
    /* ini yg gak di sorting 
    for(i = 0; i < amtItmConfig; i++) {
        if((*stackToDo).buffer[i].waktuMasuk <= currTime && !((*stackToDo).buffer[i].beenDroppedOf) && !((*stackToDo).buffer[i].beenPickedUp)) {
            addToTas(&memenuhiReq, (*stackToDo).buffer[i]);
        }
    }
    */
    // ini yg di sorting

    p = ori;
    for(i = 0; i < amtItmConfig; i++) {
        if(INFO(p).waktuMasuk <= currTime && (INFO(p).beenDroppedOf == false) && (INFO(p).beenPickedUp == false)) {
            addToTas(&memenuhiReq, INFO(p));
        }
        p = NEXT(p);
    }
    return memenuhiReq;
}

// void displayToDo(CollOfItems T, int currTime, int amtItmConfig) {
//     int i;
//     T = currentToDo(&T, currTime, amtItmConfig);
//     for(i = 0; i < amtItmConfig; i++) {
//         if (T == 'P') {
//             printf("%d. %s -> %s (%s, sisa waktu %d)\n", num, INFO(FIRST(copy)).lokSrc, INFO(FIRST(copy)).lokDes, INFO(FIRST(copy)).jenisItem, INFO(FIRST(copy)).waktuHangus);
//         } else {
//             printf("%d. %s -> %s (%s)\n", num, INFO(FIRST(copy)).lokSrc, INFO(FIRST(copy)).lokDes, INFO(FIRST(copy)).jenisItem);
//         }
//     }
// } // oke bang
    // ListLL ori, copy;
    // item minItem, throw;
    // int i, idks, num = 1;

    // CreateListLL(&ori);
    // CreateListLL(&copy);

    // for(i = 0; i < amtItmConfig; i++) {
    //     insertLastLL(&ori, itemsinConfig.buffer[i]);
    // }
    // printf("masuk1\n");
    // while(!isEmptyLL(ori)) {
    //     minItem = minn(ori);
    //     idks = indexOfLL(ori, minItem);
    //     insertFirstLL(&copy, minItem);
    //     // printf("copy: %d\n", INFO(FIRST(copy)).waktuMasuk);
    //     deleteAtLL(&ori, idks, &minItem);
    // }
    // printf("step1\n");
    // if(isEmptyLL(copy)) {
    //     printf("To do list kosong\n");
    // } else {
    //     printf("To do list tidak kosong\n");
    //     for(i = 0; i < amtItmConfig; i ++) {
    //         if((INFO(FIRST(copy))).waktuMasuk <= currTime && !(INFO(FIRST(copy)).beenDroppedOf) && !(INFO(FIRST(copy)).beenPickedUp)) {
    //             if (INFO(FIRST(copy)).jenisItem == 'P') {
    //                 printf("%d. %s -> %s (%s, sisa waktu %d)\n", num, INFO(FIRST(copy)).lokSrc, INFO(FIRST(copy)).lokDes, INFO(FIRST(copy)).jenisItem, INFO(FIRST(copy)).waktuHangus);
    //             } else {
    //                 printf("%d. %s -> %s (%s)\n", num, INFO(FIRST(copy)).lokSrc, INFO(FIRST(copy)).lokDes, INFO(FIRST(copy)).jenisItem);
    //             }
    //             num++;
    //             deleteFirstLL(&copy, &throw);
    //         }
    //     }
    // }
    // printf("lolos\n");
// 

// ngurutin QUEUE

Queue sortedqueue(CollOfItems T,int N){
    Queue q;
    Item minitem;
    int min;
    CreateQueue(&q);
    min = (T).buffer[0].waktuMasuk;
    minitem = (T).buffer[0];
    int indeks = 0; 
    int j = 0;
    while(j < N){
        for (int i = 1; i < CURRENT_CAP(T); i++){
            if (min > (T).buffer[i].waktuMasuk) {
                min = (T).buffer[i].waktuMasuk;
                minitem = (T).buffer[i];
                indeks = i; //ini dah bener blum?
            }
        }
        enqueue(&q, minitem);
        // removeitemm(T, indeks);
        (T).buffer[indeks].waktuMasuk = 999;
        // printf("%d\n", (*T).currCapacity);
        // printf("lewat2\n");
        min = 999;
        // if (!isTasEmpty(*T)){
        //     min = (*T).buffer[0].waktuMasuk;
        //     minitem = (*T).buffer[0];
        // }
        j++;
    }
    return q;
}

// void removeitemm(CollOfItems *S, int i) {
//     Tas S2;
//     Item item;
//     CreateTas(&S2);
//     int j;
//     MAX_TAS(S2) = MAX_TAS(*S);
//     int N = CURRENT_CAP(*S) - i;
//     if (IDX_TOP(*S) == i)
//     {
//         rmvFromTas(S, &item);
//     }
//     else
//     {
//         for (j = 1; j < N; j++)
//         {
//             rmvFromTas(S, &item);
//             printf("yang dipindah: %c\n", item.jenisItem);
//             addToTas(&S2, item);
//         }
//         rmvFromTas(S, &item);
//         printf("yang keluar: %c\n", item.jenisItem);
//         while(!isTasEmpty(S2))
//         {
//             rmvFromTas(&S2, &item);
//             printf("yang dimasukin: %c\n", item.jenisItem);
//             addToTas(S, item);
//         }
//     }
// }

void displayToDo(Queue q, int currTime) {
    int i, iter = 1;
    item throw;
    int N = length(q); //kalo langsung length(q) kalo lu dequeu bakal keganti lengthnya 
    for(i = 0; i < N; i++) {
        if (HEAD(q).waktuMasuk <= currTime && !(HEAD(q).beenDroppedOf) && (HEAD(q).beenPickedUp == false)) {
            if (HEAD(q).jenisItem == 'P') {
                printf("%d. %c -> %c ", iter, HEAD(q).lokSrc, HEAD(q).lokDes);
                printf("(Perishable Item, sisa waktu %d)\n", HEAD(q).waktuHangus);
            } else {
                printf("%d. %c -> %c (%c)\n", iter, HEAD(q).lokSrc, HEAD(q).lokDes, HEAD(q).jenisItem);
            }
            dequeue(&q, &throw);
            iter++;
        }
    }
}


void moveToDo(Queue *q, ListLL *l, int waktumasuk) {
    boolean sort =true;
    int i =0;
    Item val;
    while (sort ==true && !isEmptyQ(*q)){
        if ((*q).buffer[i].waktuMasuk >= waktumasuk){
            dequeue(q, &val);
            insertFirstLL(l, val);
        }
        else{
            sort =false;
        }
    }
}

boolean isFinished(CollOfItems U, int amountIteminConfig) {
    int i;
    boolean condition = true;
    for(i = 0; i < amountIteminConfig; i++) {
        if(TOP(U).beenDroppedOf == false && TOP(U).beenPickedUp == false) {
            return false;
        } 
    }
    return condition;
}
