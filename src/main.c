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
#include "to_do_list.h"

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
    CollOfItems itemInConfig;
    MatrixMap map, daftarlokasi;
    
    // Create
    createPlayer(&player);
    
    
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
        char fileName[50];
        takeString(currentWord, fileName);
        stringCat(fileloc,fileName);
        readFile(fileloc,&AdjMtrx, &map, &daftarlokasi, &itemInConfig);
        

    }else if (isWordString(currentWord,"2")){

    }else{
        exit = true;
    }
    ///// COMMAND ////
    while (!exit){  
        printf("ENTER COMMAND : ");
        advWord();
        if (isWordString(currentWord, "MOVE")){


            /// WAKTU PLAYER
            int duration = TIME(player); //ini buat pengurangaan durasi perishable item
            TIME(player)++; //waktu normal nambah 1
            heavyItemTime(tas, &player); // efek heavy item
            Speed_Boost(&player,&tas, &ability);
            duration = TIME(player) - duration;
            //Hapus Item Perishable yang hangus
            PerishableTime(&tas, player, duration); //fungsi buat ngurangin waktu hangus + hapus kalo waktu hangus 0
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
            displayToDo(itemInConfig, TIME(player));
        }
        else if (isWordString(currentWord, "IN_PROGRESS")){
            displayInProgr(tas);
        }
        else if (isWordString(currentWord, "BUY")){
            int buy;
            boolean keluar = false;
            printf("Uang yang tersedia : %i Yen\n", MONEY(player));
            printGadget();
            printf("ENTER COMMAND : ");
            advWord();
            buy = takeNum(currentWord);
            
            if (buy == 0) keluar = true;
            else if ((buy >= 1) && (buy <= 4)){
                if (MONEY(player) < gadgetPrice(buy)) printf("Uang tidak cukup untuk membeli gadget.\n");
                else{
                    if (!isFullListLP(GADGET(player))) { 
                        insertLastLP(&GADGET(player), buy);
                        MONEY(player) -= gadgetPrice(buy);
                		printf("\n");
                    }
                    else printf("Inventory telah penuh! Gunakan gadget yang Anda miliki terlebih dahulu sebelum membeli gadget lain.\n");
                }
            } else {
                printf("Input yang Anda masukkan salah, silahkan ulangi kembali!\n");
            	continue;
            }
        }
        else if (isWordString(currentWord, "INVENTORY")){
            int inv;
            boolean keluar = false;
            printInventory(GADGET(player));
            printf("ENTER COMMAND : ");
            advWord();
            inv = takeNum(currentWord);

            if (inv == 0) keluar = true;
            else if ((inv >= 1) && (inv <= 4)){
                if (indexOfLP(GADGET(player), inv) != IDX_UNDEFLP){
                    ElType remove;
                    swapLast(&GADGET(player), inv); 
                    deleteLastLP(&GADGET(player), &remove);
                    useGadget(GADGET(player), inv);
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
            } else {
                printf("Input yang Anda masukkan salah, silahkan ulangi kembali!\n");
            	continue;
            }
        }
        else if (isWordString(currentWord, "HELP")){
            help();
        }
        else{
            printf("Masukan Perintah Yang benar");
        }



        // isHeadQuarter
        // isTodoList NULL
        // exit = true
        // BONUS : SAVE GAME
    }








    close();
    return 0;
}
// Adt yang dibutuhin di pick_up drop_off sama ability
// pick_up.c drop_off.c ability.c ../ADT/tas.c 