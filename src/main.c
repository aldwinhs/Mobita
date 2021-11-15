/* Main Mobita */

/* Importing Functions */
#include<stdio.h>
#include<stdlib.h>
#include"readFile.h"
#include"ability.h"
#include"gadget.h"
#include"map.h"
#include"player.h"
#include"pick_up.h"
#include"help.h"
#include"drop_off.h"

int main(){
    Word input;
    boolean exit;
    printf("Main Menu:\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("3. Exit\n");
    
    startWord();
    
    while(!isWordString(currentWord,"1") && !isWordString(currentWord,"2") && !isWordString(currentWord,"3")){
        printf("input salah\n");
        advWord();
    }

    if(isWordString(currentWord,"1")){
        printf("Masukan nama konfigurasi level: ");
        advWord();
        input = takeWord(currentWord);
        char fileloc[] = input.contents;
        readFile(fileloc);
        

    }else if (isWordString(currentWord,"2")){

    }


    // while (input.contents != 'exit'){
    //     printf("ENTER COMMAND: ");
    //     advWord();
    //     input = takeWord(currentWord);
    //     if(){

    //     }else if(){

    //     }else if(){

    //     }
    // }







    return 0;
}