
#include<stdio.h>
#include<stdlib.h>
#include"readFile.h"


void readFile(char fileloc[], Matrix *AdjMtrx, MatrixMap *map, ListDin *daftarlokasi, CollOfItems *itemInConfig, int *nToDo){
    
    int i, j, barisMap, kolomMap,totalLokasi,x,y;
    char inputString[50];
    char input[2];
    char temp;
    POINT Koordinat;
    int a;
    
    printf("Loading...\n");
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
    CreateListDin(daftarlokasi,totalLokasi);

    ELMTLD(*daftarlokasi,0) = Koordinat;
    ELMTMAP(*map, x, y) = Koordinat;

    for(i = 0; i < totalLokasi-1 ; i++){
        advWordFile();
        temp = currentWord.contents[0];
        advWordFile();
        x = takeNum(currentWord)-1;
        advWordFile();
        y = takeNum(currentWord)-1;
        Koordinat = MakePOINT(temp,x,y);
        ELMTLD(*daftarlokasi,i+1) = Koordinat;
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
    *nToDo = takeNum(currentWord);
    
    for(i = 0; i < *nToDo; i++){
        advWordFile();
        (*itemInConfig).buffer[i].waktuMasuk = takeNum(currentWord);
        advWordFile();
        // takeString(currentWord, inputString);
        (*itemInConfig).buffer[i].lokSrc = currentWord.contents[0];
        advWordFile();
        // takeString(currentWord, inputString);
        (*itemInConfig).buffer[i].lokDes = currentWord.contents[0];
        advWordFile();
        // takeString(currentWord, inputString);
        (*itemInConfig).buffer[i].jenisItem = currentWord.contents[0];
        if (isWordString(currentWord, "P")){
            advWordFile();
            (*itemInConfig).buffer[i].waktuHangus = takeNum(currentWord);
        } else {
            (*itemInConfig).buffer[i].waktuHangus = -1;
        }
        (*itemInConfig).buffer[i].beenDroppedOf = false;
        (*itemInConfig).buffer[i].beenPickedUp = false;
        (*itemInConfig).buffer[i].price = 0;
    }
    // for (int i = 0; i<*nToDo;i++){

    //     printf("jenis item : %c\n", (*itemInConfig).buffer[i].jenisItem);
    // }
    // for (int i = 0; i<*nToDo;i++){
    //     printf("tempat tujuan: %c\n", (*itemInConfig).buffer[i].lokSrc);
    // }



    closeFile();
    printf("Done\n");
}