#include <stdio.h>
#include "../../ADT/boolean.h"
#include "../../ADT/matrix.h"
#include "../../ADT/matrix.c"
#include "../../ADT/listdin.h"
#include "../../ADT/listdin.c"
#include "../../ADT/tas.h"
#include "../../ADT/tas.c"
#include "../../ADT/point.h"
#include "../../ADT/point.c"
#include "../../ADT/queue.h"
#include "../../ADT/queue.c"
#include "../../pcolor/pcolor.h"
#include "../../pcolor/pcolor.c"
#include "../../ADT/player.h"
#include "../../map/map.h"
#include "../../map/map.c"
#include "../move.h"
#include "../move.c"


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

    
    Tas berisi2;
    Queue q;
    // Item item1 = {'A', 'G', 'heavy_item', 6, 9, 400};
    // Item item2 = {'D', 'F', 'Letinga', 14, 29, 213};
    // Item item3 = {'A', 'J', 'Tolikan', 15, 89, 613};
    Item item3, item2;
    item2.lokSrc = 'J';
    item2.lokDes = 'A';
    item3.lokSrc = 'B';
    item3.lokDes = 'P';
    CreateTas(&berisi2);
    addToTas(&berisi2, item3);
    CreateQueue(&q);
    enqueue(&q, item2);


    Matrix m1;
    int i,j;                      //ini matriks buat hubungan antarlokasi
    CreateMatrix(18, 18, &m1);      //dapetinnya dari file konfig, yang isinya 0 sama 1
    for(i=0;i<18;i++){              //pas di-run nanti copas dari yg di file spek
        for(j=0;j<18;j++){
            int c;
            scanf("%d", &c);
            ELMTM(m1, i, j) = c;
        } 
    }

    Player p;
    POSISI(p) = pe;
    printf("\n");
    printMap(mMap, p, m1, q, berisi2);

    ListDin mpoint;
    CreateListDin(&mpoint, 27);
    
    ELMTLD(mpoint, 0) = p8;
    ELMTLD(mpoint, 1) = pa;
    ELMTLD(mpoint, 2) = pb;
    ELMTLD(mpoint, 3) = pc;
    ELMTLD(mpoint, 4) = pd;
    ELMTLD(mpoint, 5) = pe;
    ELMTLD(mpoint, 6) = pf;
    ELMTLD(mpoint, 7) = pg;
    ELMTLD(mpoint, 8) = ph;
    ELMTLD(mpoint, 9) = pi;
    ELMTLD(mpoint, 10) = pj;
    ELMTLD(mpoint, 11) = pk;
    ELMTLD(mpoint, 12) = pl;
    ELMTLD(mpoint, 13) = pm;
    ELMTLD(mpoint, 14) = pn;
    ELMTLD(mpoint, 15) = po;
    ELMTLD(mpoint, 16) = pp;
    ELMTLD(mpoint, 17) = pq;

    boolean move=false;

    printf("\n");
    printMap(mMap, p, m1, q, berisi2);

    printf("\n");
    MOVE(&p, m1, mpoint, &move);

    printf("\n");
    printMap(mMap, p, m1, q, berisi2);

    printf("\n");
    MOVE(&p, m1, mpoint, &move);

    printf("\n");
    printMap(mMap, p, m1, q, berisi2);
}

// cara pakai :
// gcc driverMove.c
// masukin matriks adjacency (copas dari spek)