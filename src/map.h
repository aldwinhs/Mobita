#ifndef MAP_H
#define MAP_H

#include "../ADT/boolean.h"
#include "../ADT/matrix.h"
#include "../ADT/stack.h"
#include "../ADT/queue.h"
#include "../pcolor/pcolor.h"
#include "player.h"

void printMap(Matrix mloc, Player p, Matrix mhub, Stack s, Queue q);
// mencetak map yang ada

void lokasiSekarang(Player p, Matrix m);
// menampilkan posisi mobita saat ini


#endif
