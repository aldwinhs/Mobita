#ifndef MOVE_H
#define MOVE_H

#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/matrix.h"
#include "player.h"

Matrix daftarLokasi(Matrix m, int nRow);
// menerima matriks m, matriks MAP yang sudah ada
// nRow adalah banyaknya lokasi yang ada di MAP
// menggembalikan matriks dengan ukuran nRow x 2

void printTujuan(Player *p, Matrix mhub, Matrix mlok, int *val, Matrix *mtujuan);
// I.S. Player, mhub, mlok, val, mtujuan terdefinisi
// F.S. menampilkan lokasi mana saja yang bisa dicapai dari lokasi saat ini

void MOVE(Player *p, Matrix mhub, Matrix mlok);
// I.S. Player, mhub, mlok terdefinisi
// F.S. posisi player berubah

#endif