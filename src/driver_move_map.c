// #include <stdio.h>
// #include "../ADT/boolean.h"
// #include "../ADT/matrix.h"
// #include "../ADT/stack.h"
// #include "../ADT/queue.h"
// #include "../pcolor/pcolor.h"
// #include "player.h"
// #include "map.h"

// int main() {
//     Matrix m;
//     ROWS(m) = 10;
//     COLS(m) = 15;
//     int i,j;
//     for(i=0;i<ROWS(m);i++){
//         for(j=0;j<COLS(m);j++){
//             ELMT(m, i, j) = '.';
//         } 
//     }
    
//     ELMT(m, 0, 0) = '8';
//     ELMT(m, 9, 0) = 'A';
//     ELMT(m, 0, 14) = 'B';
//     ELMT(m, 0, 8) = 'C';
//     ELMT(m, 0, 13) = 'D';
//     ELMT(m, 1, 2) = 'E';
//     ELMT(m, 2, 0) = 'F';
//     ELMT(m, 2, 7) = 'G';
//     ELMT(m, 2, 13) = 'H';
//     ELMT(m, 3, 4) = 'I';
//     ELMT(m, 4, 11) = 'J';
//     ELMT(m, 5, 2) = 'K';
//     ELMT(m, 6, 9) = 'L';
//     ELMT(m, 7, 1) = 'M';
//     ELMT(m, 7, 5) = 'N';
//     ELMT(m, 7, 14) = 'O';
//     ELMT(m, 8, 12) = 'P';
//     ELMT(m, 9, 2) = 'Q';

//     Matrix m2;
//     m2 = daftarLokasi(m, 17);

//     printf("\n");
//     displayMatrix(m);
//     printf("\n");

//     Player p;
//     LOC(p) = '8'; 
//     Matrix m1;
//     CreateMatrix(18, 18, &m1);
//     for(i=0;i<18;i++){
//         for(j=0;j<18;j++){
//             int c;
//             scanf("%d", &c);
//             ELMT(m1, i,j) = c;
//         } 
//     }   
//     printf("\n");
//     printMap(m, p, m1);
//     printf("\n");
//     MOVE(&p, m1, m2);
//     printMap(m, p, m1);
//     return 0;
// }
