
#include<stdio.h>
#include<stdlib.h>
#include"readFile.h"
#include<string.h>

void readFile(char fileloc[], Matrix *AdjMtrx){
    
    int i,j;

    startWordFile(fileloc);
    


    //ini matriks buat hubungan antarlokasi
    //dapetinnya dari file konfig, yang isinya 0 sama 1
    for(i=0;i<18;i++){              //pas di-run nanti copas dari yg di file spek aja
        for(j=0;j<18;j++){
            advWordFile();
            ELMT(*AdjMtrx,i,j) = takeNum(currentWord);
        } 
    }
}