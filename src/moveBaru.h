#ifndef MOVE_H
#define MOVE_H

#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/matrix.h"
#include "player.h"
#include "mapBaru.h"

void daftarTujuan(Player *p, Matrix mhub, MatrixMap mPoint, MatrixMap *m, int *val);
// I.S. p, mhub, mPoint, m, val terdefinisi
// F.S. mencetak semua lokasi yang bisa dicapai dari posisi player sekarang,
// sekaligus menambahkan lokasi yang bisa dicapai ke matriks m serta jumlahnya ke val

void MOVE(Player *p, Matrix mhub, MatrixMap mMap);
// I.S. p, mhub, mMap terdefinisi
// F.S. memindahkan posisi player p ke posisi lain yang dituju

#endif
