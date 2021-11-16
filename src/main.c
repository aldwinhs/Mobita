/* Main Mobita */

/* Importing Functions */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"readFile.h"
#include"ability.h"
#include"gadget.h"
#include"map.h"
#include"player.h"
#include"pick_up.h"
#include"help.h"
#include"drop_off.h"

int main(){
    
    /* ----- inisialisasi variabel ----- */
    Word input;
    boolean exit = false;
    Matrix AdjMtrx;
    // ADT yang dipakai
    Tas tas;
    Ability ability;
    Player player;
    Item item;
    
    // Create
    createPlayer(&player);
    CreateMatrix(18,18,&AdjMtrx);
    
    
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
        char fileloc[] = "./test/";
        input = takeWord(currentWord);
        char fileName[50];
        strcpy(fileName,input.contents);
        strcat(fileloc,fileName);
        readFile(fileloc,&AdjMtrx);
        

    }else if (isWordString(currentWord,"2")){

    }else{
        exit = true;
    }
    ///// COMAND ////
    while (!exit){  
        printf("ENTER COMMAND : ");
        advWord();
        if (isWordString(currentWord, "MOVE")){

        }
        else if (isWordString(currentWord, "PICK_UP")){
            // remove dari to do list baru di pick_up
            pickUpItem(&tas, item);
        }
        else if (isWordString(currentWord, "DROP_OFF")){
            dropOffItem(&player, &tas, &ability, &item); 
            // sudah ada mekanisme mendapat ability, price , efek heavy dll
        }
        else if (isWordString(currentWord, "MAP")){

        }
        else if (isWordString(currentWord, "TO_DO")){

        }
        else if (isWordString(currentWord, "IN_PROGRESS")){
           displayInProgr(tas);
        }
        else if (isWordString(currentWord, "BUY")){
            int buy;
            printf("Uang yang tersedia : %i Yen\n", MONEY(player));
            printGadget();
            printf("ENTER COMMAND : ");
            advWord();
            buy = takeNum(currentWord);
            
            if (buy == 0) printf("break");
            else {
                if (MONEY(player) < gadgetPrice(buy)) printf("Uang tidak cukup untuk membeli gadget.\n");
                else{
                    if (!isFullList(GADGET(player))) { 
                        insertLast(&GADGET(player), buy);
                        MONEY(player) -= gadgetPrice(buy);
                        displayList(GADGET(player));
                		printf("\n");
                    }
                    else printf("Inventory telah penuh! Gunakan gadget yang Anda miliki terlebih dahulu sebelum membeli gadget lain.\n");
                }
            }
        }
        else if (isWordString(currentWord, "INVENTORY")){
            int inv;
            printInventory(GADGET(player));
            printf("ENTER COMMAND : ");
            advWord();
            inv = takeNum(currentWord);

            if (indexOf(GADGET(player), inv) != IDX_UNDEF){
                ElType remove;
                swapLast(&GADGET(player), inv); 
                deleteLast(&GADGET(player), &remove);
                useGadget(GADGET(player), inv);
                displayList(GADGET(player));
                printf("\n");

                // Implementasi Gadget
                // Kain Pembungkus Waktu
                if (inv == 1){
                    // Mengembalikan waktu dari perishable item ke durasi semula
                }
                // Senter Pembesar
                else if (inv == 2){
                    // Meningkatkan kapasitas tas sebesar dua kali lipat
                    // Ini ada fungsi buat ganti kapasitas tas ga yaa?
                    if (tas.currCapacity * 2 <= CAPACITY_TAS) addCapTas(&tas, tas.currCapacity * 2);
                    else addCapTas(&tas, 100);
                }
                // Pintu Kemana Saja
                else if (inv == 3){
                    // Move tanpa menambah unit waktu
                    // OPSI 1
                    changeTime(&player, (-1));
                    // OPSI 2
                    // bikin boolean PKSactive = false di awal
                    // disini PKSactive = true
                    // di mekanisme waktu, if PKSactive, berarti ganambah waktu
                    // OPSI 3
                    // panggil cara kerja move.. 
                } 
                // Mesin Waktu
                else if (inv == 4){
                    // Mengurangi unit waktu sebanyak 50
                    if (TIME(player) >= 50) changeTime(&player, (-50));
                    else changeTime(&player, TIME(player));
                }
            } else {
                printf("Tidak ada gadget yang dapat digunakan!\n");
            }
        }
        else if (isWordString(currentWord, "HELP")){
            help();
        }
        else{
            printf("Masukan Perintah Yang benar");
        }

        /// WAKTU PLAYER
        int duration = TIME(player); //ini buat pengurangaan durasi perishable item
        TIME(player)++; //waktu normal nambah 1
        heavyItemTime(tas, &player); // efek heavy item
        Speed_Boost(&player,&tas, &ability);
        duration = TIME(player) - duration;
        //Hapus Item Perishable yang hangus
        PerishableTime(&tas, player, duration); //fungsi buat ngurangin waktu hangus + hapus kalo waktu hangus 0

        // isHeadQuarter
        // isTodoList NULL
        // exit = true
        // BONUS : SAVE GAME
    }









    return 0;
}
// Adt yang dibutuhin di pick_up drop_off sama ability
// pick_up.c drop_off.c ability.c ../ADT/tas.c 