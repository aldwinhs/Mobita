#ifndef MOBITA_TO_DO_LIST_H
#define MOBITA_TO_DO_LIST_H

#include "../ADT/tas.h"
#include "../ADT/stack_linked.h"
#include <stdio.h>

void displayInProgr(Tas s);
/* Menampilkan pesanan yang sedang diantarkan */
/* I.S. s tidak mungkin kosong */
/* F.S. menampilkan pesanan yang sedang dikerjakan sesuai urutan mulai dari yang ada pada Top Stack */

void displayToDo(CollOfItems itemsinConfig, int currTime);
/* Menampilkan TO DO LIST */
/* I.S. terdapat setidaknya satu item pada file konfigurasi dengan urutan sesuai spesifikasi */
/* F.S. menampilkan setiap item yang waktu pesanan masuknya  lebih kecil atau sama dengan waktu sekarang */

#endif //MOBITA_TO_DO_LIST_H