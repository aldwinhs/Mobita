
#include<stdio.h>
#include<stdlib.h>
#include"readFile.h"
#include"to_do_list.h"
#include "../ADT/tas.h"

void readFile(char fileloc[], Matrix *AdjMtrx, CollOfItems *itemInConfig){
    
    int i, j, nTodo, totalLokasi;
    char inputString[50];
    char input[2];
    
    startWordFile(fileloc);
    
    

    advWordFile();
    totalLokasi = takeNum(currentWord)+1;
    CreateMatrix(totalLokasi, totalLokasi, AdjMtrx);
    //ini matriks buat hubungan antarlokasi
    //dapetinnya dari file konfig, yang isinya 0 sama 1
    for(i=0;i<totalLokasi;i++){              //pas di-run nanti copas dari yg di file spek aja
        for(j=0;j<totalLokasi;j++){
            advWordFile();
            ELMT(*AdjMtrx,i,j) = takeNum(currentWord);
        } 
    } 
    
    advWordFile();
    nTodo = takeNum(currentWord);
    
    for(i = 0; i < nTodo; i++){
        advWordFile();
        (*itemInConfig).buffer[i].waktuMasuk = takeNum(currentWord);
        advWordFile();
        takeString(currentWord, inputString);
        (*itemInConfig).buffer[i].lokSrc = inputString;
        advWordFile();
        takeString(currentWord, inputString);
        (*itemInConfig).buffer[i].lokDes = inputString;
        advWordFile();
        takeString(currentWord, inputString);
        (*itemInConfig).buffer[i].jenisItem = inputString;
        if (isWordString(currentWord, "P")){
            advWordFile();
            (*itemInConfig).buffer[i].waktuHangus = takeNum(currentWord);
        } else {
            (*itemInConfig).buffer[i].waktuHangus = -1;
        }
        (*itemInConfig).buffer[i].beenDroppedOf = false;
        (*itemInConfig).buffer[i].beenPickedUp = false;
        (*itemInConfig).buffer[i].price = 0;
        // run bang
        
    }
    



    closeFile();
}