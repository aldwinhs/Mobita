
#ifndef READFILE_H
#define READFILE_H

#include "../ADT/wordmachine.h"
#include"../map/map.h"
#include"../move/move.h"
#include"../to-do-list/to_do_list.h"

void readFile(char fileloc[], Matrix *AdjMtrx, MatrixMap *map, ListDin *daftarlokasi, CollOfItems *itemInConfig, int *nTodo);

#endif