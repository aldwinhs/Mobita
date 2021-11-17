#include <stdio.h>
#include "map.h"


void CreateMatrixMap(int nRow, int nCol, MatrixMap *m){
    COLSMAP(*m) = nCol;
    ROWSMAP(*m) = nRow;
}

void mapKosong(MatrixMap *m){
    POINT ptemp;
    int i, j;
    for(i=0;i<ROWSMAP(*m);i++){
        for(j=0;j<COLSMAP(*m);j++){
            ptemp = MakePOINT('0', i, j);
            ELMTMAP(*m, i, j) = ptemp;
        }
    }
}

void printMap(MatrixMap m, Player p, Matrix mhub, Queue pickup, Tas dropoff){
    int a, b, c, d;
    for(a=0; a<COLSMAP(m)+2 ;a++){
        printf("* ");
    }
    printf("\n");
    for(b=0; b<ROWSMAP(m); b++) {
        printf("*");
        for(c=0; c<COLSMAP(m); c++) {
            char ch = LOCC(ELMTMAP(m, b, c));
            if(ch =='0'){
                printf("  ");
            } else {
                // nentuin warna
                if (ch == LOCC(POSISI(p))) {
                    printf(" ");
                    print_yellow(ch);
                    // PICK_UP  coba dirun aja
                } else if ((!isEmptyQ(pickup)) && (ch == HEAD(pickup).lokSrc)){
                    printf(" ");
                    print_red(ch);
                } else if ((!isTasEmpty(dropoff)) && (ch == (TOP(dropoff)).lokDes)) {
                    printf(" ");
                    print_blue(ch);
                }else if (ch == '8' && (ELMTM(mhub, 0, (int)LOCC(POSISI(p))-64)==1)) {
                    printf(" ");
                    print_green(ch);
                } else if (LOCC(POSISI(p))=='8' && ELMTM(mhub, 0, (int)ch-64)==1) {
                    printf(" ");
                    print_green(ch);
                } else if (ELMTM(mhub, (int)ch-64, (int)LOCC(POSISI(p))-64)==1){
                    printf(" ");
                    print_green(ch);
                } else {
                    printf(" ");
                    print_black(ch);
                }
            }
        }
        printf(" *\n");
    }
    for(d=0; d<COLSMAP(m)+2 ;d++){
        printf("* ");
    }
    printf("\n");
}