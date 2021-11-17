#include <stdio.h>
#include "move.h"

void daftarTujuan(Player *p, Matrix mhub, ListDin mpoint, ListDin *m, int *val){
    printf("Posisi yang dapat dicapai : \n");
    int skrng;
    if (LOCC(POSISI(*p)) == '8'){
        skrng = 0;
    } else {
        skrng = (int)LOCC(POSISI(*p))-64;
    }
    int i, j, count=0;
    for(i=0;i<ROWS(mhub);i++){
        if (ELMTM(mhub, skrng, i) == 1) {
            POINT point;
            point = ELMTLD(mpoint, i);
            ELMTLD(*m, count) = point;
            count++;
            printf("%d. %c (%d,%d)\n", count, LOCC(point), Absis(point)+1, Ordinat(point)+1);
        }
    }
    *val = count;
}

void MOVE(Player *p, Matrix mhub, ListDin mpoint){
    int pilihan, jmlhlokasi;
    ListDin daftartujuan;
    CreateListDin(&daftartujuan, 27);
    daftarTujuan(p, mhub, mpoint, &daftartujuan, &jmlhlokasi);
    printf("jmlh pilihan : %d\n", jmlhlokasi);
    printf("Posisi yang ingin dituju? (0 jika ingin membatalkan) ");
    scanf("%d", &pilihan);
    while (pilihan<0 || pilihan>jmlhlokasi) {
        printf("Masukan tidak valid!\n");
        printf("Posisi yang ingin dituju? (0 jika ingin membatalkan) ");
        scanf("%d", &pilihan);
    }
    if (pilihan != 0) {
        POSISI(*p) = ELMTLD(daftartujuan, pilihan-1);
    } else {
        printf("Instruksi MOVE berhasil dibatalkan!\n");
    }
}