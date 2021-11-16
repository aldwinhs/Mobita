#ifndef MOVE_H
#define MOVE_H

#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/matrix.h"
#include "player.h"
#include "map.h"

void daftarTujuan(Player *p, Matrix mhub, MatrixMap mPoint, MatrixMap *m, int *val);
// p adalah player
// mhub adalah matriks adjacency
// mpoint adalah matriksmap dengan ukuran jumlahlokasix1, berguna untuk menyimpan semua lokasi yang ada
// I.S. p, mhub, mPoint, m, val terdefinisi
// F.S. mencetak semua lokasi yang bisa dicapai dari posisi player sekarang,
// sekaligus menambahkan lokasi yang bisa dicapai ke matriks m serta jumlahnya ke val
// m adalah matriksmap untuk menyimpan lokasi mana saja yang bisa dicapai player
// val berisi jumlah lokasi yang bisa dicapai

void MOVE(Player *p, Matrix mhub, MatrixMap mMap);
// p adalah player
// mhub adalah matrix adjacency
// mMap adalah matriksmap dengan ukuran jumlahLokasix1, berguna untuk menyimpan semua lokasi yang ada
// I.S. p, mhub, mMap terdefinisi
// F.S. memindahkan posisi player p ke posisi lain yang dituju

#endif
