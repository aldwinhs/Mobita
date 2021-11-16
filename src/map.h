#ifndef MAPBARU_H
#define MAPBARU_H

#include "../ADT/boolean.h"
#include "../ADT/matrix.h"
#include "../ADT/tas.h"
#include "../pcolor/pcolor.h"
#include "player.h"

#define ROWSMAP_CAP 20
#define COLSMAP_CAP 30


typedef POINT ElTypeMap;
typedef int Index;
typedef struct{
    ElTypeMap contents[ROWSMAP_CAP][COLSMAP_CAP];
    int rowEff;
    int colEff; 
} MatrixMap;

#define ROWSMAP(M) (M).rowEff
#define COLSMAP(M) (M).colEff
#define ELMTMAP(M, i, j) (M).contents[(i)][(j)]

void CreateMatrixMap(int nRow, int nCol, MatrixMap *m);
// Membentuk sebuah MatrixMap "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori
// I.S. nRow, nCol valid, m terdefinisi
// F.S. terbentuk matriks baru sesuai dengan definisi di atas

void mapKosong(MatrixMap *m);
// I.S. m terdefinisi dan siap diisi
// F.S. mengisi semua elemen m dengan point kosong

void printMap(MatrixMap m, Player p, Matrix mhub, Tas pickup, Tas dropoff);
// m adalah matriks map
// p adalah player
// mhub adalah matriks adjacency
// pickup adalah tas untuk todolist
// dropoff adalah tas untuk pesanan sekarang
// I.F. m, p, mhub, pickup, dropoff terdefinisi
// F.S. MAP tercetak pada layar dengan ketentuan-ketentuan warna tertentu

#endif
