
#include<stdio.h>
#include<stdlib.h>
#include"readFile.h"


void readFile(char fileloc[], Matrix *AdjMtrx, MatrixMap *map, MatrixMap *daftarlokasi, CollOfItems *itemInConfig){
    
    int i, j, nTodo, barisMap, kolomMap,totalLokasi,x,y;
    char inputString[50];
    char input[2];
    char temp;
    POINT Koordinat;
    
    startWordFile(fileloc);
    barisMap = takeNum(currentWord);
    advWordFile();
    kolomMap = takeNum(currentWord);
    CreateMatrixMap(barisMap, kolomMap, map);
    mapKosong(map);
    advWordFile();
    x = takeNum(currentWord)-1;
    advWordFile();
    y = takeNum(currentWord)-1;
    Koordinat = MakePOINT('8',x,y);
    
    advWordFile();
    totalLokasi = takeNum(currentWord)+1;
    CreateMatrixMap(totalLokasi, 1, daftarlokasi);

    ELMTMAP(*daftarlokasi,0,0) = Koordinat;
    ELMTMAP(*map, x, y) = Koordinat;

    for(i = 0; i < totalLokasi-1 ; i++){
        advWordFile();
        temp = currentWord.contents[0];
        advWordFile();
        x = takeNum(currentWord)-1;
        advWordFile();
        y = takeNum(currentWord)-1;
        Koordinat = MakePOINT(temp,x,y);
        ELMTMAP(*daftarlokasi,i+1,0) = Koordinat;
        ELMTMAP(*map, x, y) = Koordinat;
    }

    CreateMatrix(totalLokasi, totalLokasi, AdjMtrx);
    //ini matriks buat hubungan antarlokasi
    //dapetinnya dari file konfig, yang isinya 0 sama 1
    for(i=0;i<totalLokasi;i++){              //pas di-run nanti copas dari yg di file spek aja
        for(j=0;j<totalLokasi;j++){
            advWordFile();
            ELMTMAP(*AdjMtrx,i,j) = takeNum(currentWord);
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