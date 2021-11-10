/* Main Mobita */

#include<stdio.h>
#include<stdlib.h>
#include"../ADT/boolean.h"
#include"../ADT/wordmachine.h"
#include<string.h>

int main(){
    Word input;
    boolean exit;
    printf("Main Menu:\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("3. Exit\n");
    
    startWord();
    input = takeWord(currentWord);
    if(isWordString(input, "anja")){
        printf("mantap");
    }
    
    // while(input != 3 && input != 1 && input != 2){
    //     printf("input salah\n");
    //     advWord();
    //     input = takeWord(currentWord);
    // }


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