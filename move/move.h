#ifndef MOVE_H
#define MOVE_H

#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/listdin.h"
#include "../ADT/matrix.h"
#include "../ADT/player.h"
#include "../map/map.h"

void daftarTujuan(Player *p, Matrix mhub, ListDin mPoint, ListDin *m, int *val);
// p adalah player
// mhub adalah matriks adjacency
// mpoint adalah listdin dengan ukuran jumlahlokasix1, berguna untuk menyimpan semua lokasi yang ada
// I.S. p, mhub, mPoint, m, val terdefinisi
// F.S. mencetak semua lokasi yang bisa dicapai dari posisi player sekarang,
// sekaligus menambahkan lokasi yang bisa dicapai ke matriks m serta jumlahnya ke val
// m adalah listdin untuk menyimpan lokasi mana saja yang bisa dicapai player
// val berisi jumlah lokasi yang bisa dicapai

void MOVE(Player *p, Matrix mhub, ListDin mMap, boolean *move);
// p adalah player
// mhub adalah matrix adjacency
// mMap adalah listdin dengan ukuran jumlahLokasix1, berguna untuk menyimpan semua lokasi yang ada
// I.S. p, mhub, mMap terdefinisi
// F.S. memindahkan posisi player p ke posisi lain yang dituju

void posisiMobita(Player *p);
// I.S. p terdefinisi
// F.S. menampilkan posisi mobita saat ini

#endif
