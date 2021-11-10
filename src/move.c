#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/matrix.h"
#include "map.h"


Matrix daftarLokasi(Matrix m, int nRow) {
    Matrix mnew;
    CreateMatrix(nRow, 2, &mnew);
    int i, j;
    for(i=0;i<ROWS(m);i++){
        for(j=0;j<COLS(m);j++) {
            if (ELMT(m, i, j) != 56) {
                int a;
                if (ELMT(m, i, j)==56) {
                    a = 0;
                } else {
                    a = ELMT(m, i, j)-64;
                }
                ELMT(mnew, a, 0) = i;
                ELMT(mnew, a, 1) = j;
            }
        }
    }
    return mnew;

}

void printTujuan(Player p, Matrix mhub, Matrix mlok, int *val) {
    char lokasiSekarang = LOC(p);
    int intLokasi;
    if (lokasiSekarang == '8') {
        intLokasi = 0;
    } else {
        intLokasi = (int)lokasiSekarang-64;
    }
    printf("Lokasi yang dapat dicapai : \n");
    int i, count;
    for (i=0;i<COLS(mhub);i++){
        if (ELMT(mhub, intLokasi, i)==1){
            count++;
            char ch;
            if (i == 0) {
                ch = '8';
            } else {
                ch = (char)(i+64);
            }
            printf("%d. %c (%d,%d)\n", count, ch, ELMT(mlok, i, 0)+1, ELMT(mlok, i,1)+1);
        }
    }
    *val = count;
}

void MOVE(Player p, Matrix mhub, Matrix mlok) {
    int pilihan, jmlhlokasi;
    printTujuan(p, mhub, mlok, &jmlhlokasi);
    printf("jmlh pilihan : %d\n", jmlhlokasi);
    printf("Posisi yang ingin dituju? (0 jika untuk membatalkan) ");
    scanf("%d", &pilihan);
    while (pilihan<0 || pilihan>jmlhlokasi) {
        printf("Masukan tidak valid!\n");
        printf("Posisi yang ingin dituju? (0 jika untuk membatalkan) ");
        scanf("%d", &pilihan);
    }
    if (pilihan != 0) {
            // nanti disini buat pindahnya, masih belum selesai T__T
            // belum bikin buat nyimpen lokasi mana aja yg bisa dijangkau
    }
}