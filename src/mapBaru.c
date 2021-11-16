#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/matrix.h"
// #include "../ADT/stack.h"
#include "../ADT/point.h"
// #include "../ADT/queue.h"
#include "../pcolor/pcolor.h"
#include "mapBaru.h"


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


void printMap(MatrixMap m, Player p, Matrix mhub){
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
                printf(" ");
            } else {
                // nentuin warna
                if (ch == LOCC(POSISI(p))) {
                    print_yellow(ch);
                    printf(" ");
                } else if (ch == '8' && (ELMTM(mhub, 0, (int)ch-64)==1)) {
                    print_green(ch);
                    printf(" ");
                } else if (ELMT(mhub, (int)ch-64, (int)LOCC(POSISI(p))-64)==1){
                    print_green(ch);
                    printf(" ");
                } else {
                    printf("%c", ch);
                    printf(" ");
                }
            }
        }
        printf("*\n");
    }
    for(d=0; d<COLSMAP(m)+2 ;d++){
        printf("* ");
    }
}