#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/matrix.h"
#include "../ADT/matrix.c"
#include "../ADT/tas.h"
#include "../ADT/tas.c"
#include "../ADT/point.h"
#include "../ADT/point.c"
#include "../pcolor/pcolor.h"
#include "../pcolor/pcolor.c"
#include "player.h"
#include "mapBaru.h"
#include "mapBaru.c"
#include "moveBaru.h"
#include "moveBaru.c"


int main() {
    MatrixMap mMap;
    CreateMatrixMap(10, 15, &mMap);
    mapKosong(&mMap);

    // buat point di lokasi tertentu
    POINT p8, pa, pb, pc, pd, pe, pf, pg, ph, pi, pj, pk, pl, pm, pn, pp, po, pq;
    p8 = MakePOINT('8', 0,0);
    pa = MakePOINT('A', 9,0);
    pb = MakePOINT('B', 0,14);
    pc = MakePOINT('C', 0,8);
    pd = MakePOINT('D', 0,13);
    pe = MakePOINT('E', 1,2);
    pf = MakePOINT('F', 2,0);
    pg = MakePOINT('G', 2,7);
    ph = MakePOINT('H', 2,13);
    pi = MakePOINT('I', 3,4);
    pj = MakePOINT('J', 4,11);
    pk = MakePOINT('K', 5,2);
    pl = MakePOINT('L', 6,9);
    pm = MakePOINT('M', 7,1);
    pn = MakePOINT('N', 7,5);
    po = MakePOINT('O', 7,14);
    pp = MakePOINT('P', 8,12);
    pq = MakePOINT('Q', 9,2);

    // masukin ke matrixmap nya
    ELMTMAP(mMap, 0,0) = p8;
    ELMTMAP(mMap, 9,0) = pa;
    ELMTMAP(mMap, 0,14) = pb;
    ELMTMAP(mMap, 0,8) = pc;
    ELMTMAP(mMap, 0,13) = pd;
    ELMTMAP(mMap, 1,2) = pe;
    ELMTMAP(mMap, 2,0) = pf;
    ELMTMAP(mMap, 2,7) = pg;
    ELMTMAP(mMap, 2,13) = ph;
    ELMTMAP(mMap, 3,4) = pi;
    ELMTMAP(mMap, 4,11) = pj;
    ELMTMAP(mMap, 5,2) = pk;
    ELMTMAP(mMap, 6,9) = pl;
    ELMTMAP(mMap, 7,1) = pm;
    ELMTMAP(mMap, 7,5) = pn;
    ELMTMAP(mMap, 7,14) = po;
    ELMTMAP(mMap, 8,12) = pp;
    ELMTMAP(mMap, 9,2) = pq;

    
    Tas berisi1, berisi2;
    Item item1 = {"A", "G", "heavy_item", 6, 9, 400};
    Item item2 = {"D", "F", "Letinga", 14, 29, 213};
    Item item3 = {"P", "T", "Tolikan", 15, 89, 613};
    CreateTas(&berisi1);
    CreateTas(&berisi2);
    addToTas(&berisi1, item1);
    addToTas(&berisi2, item2);
    addToTas(&berisi2, item3);

    Matrix m1;
    int i,j;                      //ini matriks buat hubungan antarlokasi
    CreateMatrix(18, 18, &m1);      //dapetinnya dari file konfig, yang isinya 0 sama 1
    for(i=0;i<18;i++){              //pas di-run nanti copas dari yg di file spek aja
        for(j=0;j<18;j++){
            int c;
            scanf("%d", &c);
            ELMTM(m1, i, j) = c;
        } 
    }

    Player p;
    POSISI(p) = pe;
    printf("\n");
    printMap(mMap, p, m1, berisi1, berisi2);

    MatrixMap mpoint;
    CreateMatrixMap(18, 1, &mpoint);
    // masukin semua point
    // int count=0;
    // for(i=0;i<ROWSMAP(mMap);i++){
    //     for(j=0;j<COLSMAP(mMap);j++){
    //         if (LOCC(ELMTMAP(mMap, i, j)) != '0') {
    //             ELMTMAP(mpoint, count, 0) = ELMTMAP(mMap, i, j);
    //             count++;
    //         }
    //     }
    // }
    
    ELMTMAP(mpoint, 0,0) = p8;
    ELMTMAP(mpoint, 1,0) = pa;
    ELMTMAP(mpoint, 2,0) = pb;
    ELMTMAP(mpoint, 3,0) = pc;
    ELMTMAP(mpoint, 4,0) = pd;
    ELMTMAP(mpoint, 5,0) = pe;
    ELMTMAP(mpoint, 6,0) = pf;
    ELMTMAP(mpoint, 7,0) = pg;
    ELMTMAP(mpoint, 8,0) = ph;
    ELMTMAP(mpoint, 9,0) = pi;
    ELMTMAP(mpoint, 10,0) = pj;
    ELMTMAP(mpoint, 11,0) = pk;
    ELMTMAP(mpoint, 12,0) = pl;
    ELMTMAP(mpoint, 13,0) = pm;
    ELMTMAP(mpoint, 14,0) = pn;
    ELMTMAP(mpoint, 15,0) = po;
    ELMTMAP(mpoint, 16,0) = pp;
    ELMTMAP(mpoint, 17,0) = pq;

    // printf("\n");
    // for(i=0;i<ROWSMAP(mpoint);i++) {
    //     POINT temp;
    //     temp = ELMTMAP(mpoint, i, 0);
    //     printf("%c (%d,%d)\n", LOCC(temp), Absis(temp)+1, Ordinat(temp)+1);
    // }

    printf("\n");
    MOVE(&p, m1, mpoint);

    printf("\n");
    printMap(mMap, p, m1, berisi1, berisi2);

    printf("\n");
    MOVE(&p, m1, mpoint);

    printf("\n");
    printMap(mMap, p, m1, berisi1, berisi2);
}