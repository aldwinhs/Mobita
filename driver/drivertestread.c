
#include<stdlib.h>
#include<stdio.h>
#include"../ADT/wordmachine.h"



int main(){
    Word inputfile;
    char inputStr[50];
    char *replacementstr;
    char fileloc[] = "./test/";
    startWord();
    inputfile = takeWord(currentWord);
    char fileName[50];
    takeString(inputfile, fileName);
    printf("%s\n", fileName);
    // printf("%d\n",strlen(fileName));
    stringCat(fileloc,fileName);
    startWordFile(fileloc);
    inputfile = takeWord(currentWord);
    printf("%s\n", inputfile.contents);
    takeString(currentWord, inputStr);
    printf("%s\n", inputStr);
    // printf("%d\n",strlen(inputStr));
    replacementstr = inputStr;
    printf("%s\n", replacementstr);
    advWordFile();
    inputfile = takeWord(currentWord);
    printf("%s\n", inputfile.contents);
    takeString(currentWord, inputStr);
    printf("%s\n", inputStr);
    // printf("%d\n",strlen(inputStr));
    advWordFile();
    printf("%d\n", takeNum(currentWord)+1);
    closeFile();
    close();
}