#ifndef MOBITA_TO_DO_LIST_H
#define MOBITA_TO_DO_LIST_H

#include "../ADT/stack_linked.h"
#include "../ADT/list_linked.h"
#include "../ADT/queue.h"
#include "../ADT/tas.h"
#include <stdio.h>

void displayInProgr(Tas s);
/* Menampilkan pesanan yang sedang diantarkan */
/* I.S. s tidak mungkin kosong */
/* F.S. menampilkan pesanan yang sedang dikerjakan sesuai urutan mulai dari yang ada pada Top Stack */

// ListLL LLofSortedItemInConfig(CollOfItems *stackToDo, int currTime, int amtItmConfig);

void displayToDo(Queue q, int currTime);
/* Menampilkan TO DO LIST */
/* I.S. terdapat setidaknya satu item pada file konfigurasi dengan urutan sesuai spesifikasi */
/* F.S. menampilkan setiap item yang waktu pesanan masuknya  lebih kecil atau sama dengan waktu sekarang */

CollOfItems currentToDo(CollOfItems *stackToDo, int currTime, int amtItmConfig);

Queue sortedqueue(CollOfItems T,int N);
// Queue sortedqueue2(CollOfItems *T,int N);
void removeitemm(CollOfItems *S, int i);

boolean isFinished(CollOfItems U, int amountIteminConfig);

void moveToDo(Queue *q, ListLL *l, int waktumasuk);
#endif //MOBITA_TO_DO_LIST_H