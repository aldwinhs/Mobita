

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ADT/wordmachine.h"

int main(){
    Word inputfile;
    char fileloc[] = "./test/";
    startWord();
    inputfile = takeWord(currentWord);
    char fileName[50];
    strcpy(fileName,inputfile.contents);
    strcat(fileloc,fileName);
    startWordFile(fileloc);
    inputfile = takeWord(currentWord);
    printf("%s", inputfile.contents);
    advWordFile();
    inputfile = takeWord(currentWord);
    printf("%s", inputfile.contents);
    advWordFile();
    printf("%d", takeNum(currentWord)+1);
    closeFile();
    close();
}