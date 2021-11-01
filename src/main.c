/* Main Mobita */

#include<stdio.h>
#include<stdlib.h>
#include"ADT/boolean.h"

int main(){
    int mainmenu;
    boolean exit;
    printf("Main Menu:\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("3. Exit\n");
    do{
        scanf("%d", &mainmenu);

        if (!((mainmenu==1) || (mainmenu==2) || (mainmenu==3))){
            printf("Input Tidak Valid");
        }
        

    } while (!((mainmenu==1) || (mainmenu==2) || (mainmenu==3)));
    
    exit = false;

    if (mainmenu==1){
        
    }
    else if (mainmenu==2){
        
    }
    else{
        exit = true;
    }

    
    






    return 0;
}
