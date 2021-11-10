#ifndef MAP_H
#define MAP_H

#include "../ADT/boolean.h"
#include "../ADT/matrix.h"
#include "../ADT/stack.h"
#include "../ADT/queue.h"
#include "../pcolor/pcolor.h"
#include "player.h"

typedef struct {
    char loc;
} Player;  //sementara pake ini, sebelum ditambahin ke ADT Player

#define LOC(P) (P).loc

void printMap(Matrix mloc, Player p, Matrix mhub, Stack s, Queue q);

#endif
