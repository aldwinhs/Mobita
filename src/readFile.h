
#ifndef READFILE_H
#define READFILE_H

#include "../ADT/wordmachine.h"
#include"map.h"
#include"move.h"
#include"to_do_list.h"

void readFile(char fileloc[], Matrix *AdjMtrx, MatrixMap *map, ListDin *daftarlokasi, CollOfItems *itemInConfig, int *nTodo);

#endif