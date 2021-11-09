/* Main Mobita */

#include<stdio.h>
#include<stdlib.h>
#include"../ADT/boolean.h"
#include"../ADT/wordmachine.h"

int main(){
    char input;
    boolean exit;
    printf("Main Menu:\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("3. Exit\n");
    
    startWord();
    input = takeWord(currentWord);
    
    // while(input != 3 && input != 1 && input != 2){
    //     printf("input salah\n");
    //     advWord();
    //     input = takeWord(currentWord);
    // }
    
    // printf("%c", input);
    // fclose(tape);

    while (input != 'exit'){
        printf("ENTER COMMAND: ")
        advWord();
        input = takeWord(currentWord);
        if(){

        }else if(){

        }else if(){

        }
    }
    






    return 0;
}
