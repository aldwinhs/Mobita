/* Main Mobita */

#include<stdio.h>
#include<stdlib.h>
#include"ADT/boolean.h"
#include "ADT/charmachine.h"
#include"ADT/wordmachine.h"

int main(){
    char input;
    boolean exit;
    printf("Main Menu:\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("3. Exit\n");
    
    startWord();
    takeWord(currentWord, &input);
    
    while(input != 3 && input != 1 && input != 2){
        printf("input salah\n");
        advWord();
        takeWord(currentWord, &input);

        currentWord.content[0]
    }

    






    return 0;
}
