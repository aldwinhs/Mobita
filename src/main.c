/* Main Mobita */

#include<stdio.h>
#include<stdlib.h>
#include"../ADT/boolean.h"
#include"../ADT/wordmachine.h"

int main(){
    const char* input;
    boolean exit;
    printf("Main Menu:\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("3. Exit\n");
    
    startWord();
    // input = takeWord(currentWord);

    input = myName();
    
    // while(input != 3 && input != 1 && input != 2){
    //     printf("input salah\n");
    //     advWord();
    //     input = takeWord(currentWord);
    // }
    if(input == "anjay") printf("kunti");
    printf("%s", input);

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

const char* myName() {
  char name[6] = "Flavio";
  return name;
}