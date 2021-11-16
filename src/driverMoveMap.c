#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/matrix.h"
#include "../ADT/matrix.c"
// #include "../ADT/stack.h"
#include "../ADT/point.h"
#include "../ADT/point.c"
// #include "../ADT/queue.h"
#include "../pcolor/pcolor.h"
#include "player.h"
#include "mapBaru.h"
#include "mapBaru.c"


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

    Matrix m1;
    int i,j;                      //ini matriks buat hubungan antarlokasi
    CreateMatrix(18, 18, &m1);      //dapetinnya dari file konfig, yang isinya 0 sama 1
    for(i=0;i<18;i++){              //pas di-run nanti copas dari yg di file spek aja
        for(j=0;j<18;j++){
            int c;
            scanf("%d", &c);
            ELMT(m1, i, j) = c;
        } 
    }

    Player p;
    POSISI(p) = pe;
    printMap(mMap, p, m1);
}