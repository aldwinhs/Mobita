#include <stdio.h>
#include "move.h"
#include "../ADT/wordmachine.h"

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

void MOVE(Player *p, Matrix mhub, ListDin mpoint, boolean *move){
    int pilihan, jmlhlokasi;
    ListDin daftartujuan;
    CreateListDin(&daftartujuan, 27);
    posisiMobita(p);
    daftarTujuan(p, mhub, mpoint, &daftartujuan, &jmlhlokasi);
    // printf("jumlh pilihan : %d\n", jmlhlokasi);
    printf("Posisi yang ingin dituju? (0 jika ingin membatalkan)\n");
    printf("ENTER COMMAND FOR MOVE : ");
    // scanf("%d", &pilihan);
    advWord();
    pilihan = takeNum(currentWord);
    while (pilihan<0 || pilihan>jmlhlokasi) {
        printf("\nMasukan tidak valid!\n");
        printf("Posisi yang ingin dituju? (0 jika ingin membatalkan)\n");
        printf("ENTER COMMAND FOR MOVE : ");
        // scanf("%d", &pilihan);
        advWord();
        pilihan = takeNum(currentWord);
    }
    if (pilihan != 0) {
        POSISI(*p) = ELMTLD(daftartujuan, pilihan-1);
        posisiMobita(p);
        *move = true;
    } else {
        printf("Instruksi MOVE berhasil dibatalkan!\n");
        *move = false;
        
    }
}

void posisiMobita(Player *p){
    POINT pnt = POSISI(*p);
    printf("Posisi Mobita saat ini : %c (%d,%d)\n", LOCC(pnt), Absis(pnt)+1, Ordinat(pnt)+1);
}