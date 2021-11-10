#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/matrix.h"
#include "../ADT/stack.h"
#include "../ADT/queue.h"
#include "../pcolor/pcolor.h"
#include "player.h"
#include "map.h"

/* 
    mloc : matriks  buat simpen map
    p    : player
    mhub : matriks hubungan antarlokasi
    s    : stack buat dropoff
    q    : queue buat todolist
*/
void printMap(Matrix mloc, Player p, Matrix mhub, Stack s, Queue q){
    for(int a=0;a<COLS(mloc)+2;a++){
        printf("*");
    }
    printf("\n");
    for(int i=0;i<ROWS(mloc);i++){
        printf("*");
        for(int j=0;j<COLS(mloc);j++){
            int c = ELMT(mloc, i,j);
            if (c != '.') {
                if (c == LOC(p)) {
                    print_yellow((char)c); 
                
                } else if ((char)c==TOP(s)) {
                    print_blue((char)c);
                } else if ((char)c==HEAD(q)) {
                    print_red((char)c);
                }
                
                
                else if (c == '8' && ELMT(mhub, 0, (int)LOC(p)-64) == 1) {
                    print_green((char)c);
                } else if (ELMT(mhub, c-64, (int)LOC(p)-64) == 1) {
                    print_green((char)c);
                } else {
                    printf("%c", (char)c);
                }
            } else {
                printf(" ");
            }
        }
        printf("*\n");
    }
    for(int b=0;b<COLS(mloc)+2;b++){
        printf("*");
    }
    printf("\n");
}

int main() {
    Matrix m;           //matriks mapnya nanti
    ROWS(m) = 10;       //bakal diisi '.' semua (dalam int)
    COLS(m) = 15;
    int i,j;
    for(i=0;i<ROWS(m);i++){
        for(j=0;j<COLS(m);j++){
            ELMT(m, i, j) = '.';
        } 
    }
    
    ELMT(m, 0, 0) = '8';        //masukin koordinat dari lokasi
    ELMT(m, 9, 0) = 'A'; 
    ELMT(m, 0, 14) = 'B';       //ini ELMT harusnya buat matriks, tapi malah dianggep list
    ELMT(m, 0, 8) = 'C';
    ELMT(m, 0, 13) = 'D';
    ELMT(m, 1, 2) = 'E';
    ELMT(m, 2, 0) = 'F';
    ELMT(m, 2, 7) = 'G';
    ELMT(m, 2, 13) = 'H';
    ELMT(m, 3, 4) = 'I';
    ELMT(m, 4, 11) = 'J';
    ELMT(m, 5, 2) = 'K';
    ELMT(m, 6, 9) = 'L';
    ELMT(m, 7, 1) = 'M';
    ELMT(m, 7, 5) = 'N';
    ELMT(m, 7, 14) = 'O';
    ELMT(m, 8, 12) = 'P';
    ELMT(m, 9, 2) = 'Q';

    printf("\n");           //buat nunjukin isi matriks m
    displayMatrix(m);       //kan disimpen dalam int
    printf("\n");           //nanti ke-printnya bakal angka-angka 

    Player p;
    LOC(p) = 'E'; 
    Matrix m1;                      //ini matriks buat hubungan antarlokasi
    CreateMatrix(18, 18, &m1);      //dapetinnya dari file konfig, yang isinya 0 sama 1
    for(i=0;i<18;i++){              //pas di-run nanti copas dari yg di file spek aja
        for(j=0;j<18;j++){
            int c;
            scanf("%d", &c);
            ELMT(m1, i,j) = c;
        } 
    }   
    printf("\n");
    Stack s;
    printMap(m, p, m1, s);             //buat print map nya
    printf("\n");
    return 0;
}