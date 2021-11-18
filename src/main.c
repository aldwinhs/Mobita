/* Main Mobita */

/* Importing Functions */
#include<stdio.h>
#include<stdlib.h>
#include"../file-reader/readFile.h"
#include"ability.h"
#include"../buy/buy.h"
#include"../inventory/inventory.h"
#include"map.h"
#include"player.h"
#include"pick_up.h"
#include"move.h"
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
    Item items;
    CollOfItems itemInConfig;
    MatrixMap map;
    ListDin daftarlokasi;
    Queue daftaritem;
    ListLL l;
    boolean moves;
    boolean foundP;
    Item buang;
    int nToDo;
    int duration;
    boolean founditem;
    int indeksitem;
    int indeksgadget;
    indeksitem =0;
    
    // Create
    createPlayer(&player);
    CreateTas(&tas);
    CreateTas(&itemInConfig);
    CreateAbility(&ability);
    mobitastart();
    printf("Main Menu:\n");
    printf("1. Play Game\n");
    // printf("2. Load Game\n");
    printf("2. Exit\n");
    printf("ENTER CHOICE : ");
    startWord();
    while(!isWordString(currentWord,"1") && !isWordString(currentWord,"2")){
        printf("input salah\n");
        advWord();
    }

    if(isWordString(currentWord,"1")){
        printf("Masukan nama konfigurasi level: ");
        advWord();
        char fileloc[50] = "./config/";
        char fileName[50];
        takeString(currentWord, fileName);
        stringCat(fileloc,fileName);
        readFile(fileloc,&AdjMtrx, &map, &daftarlokasi, &itemInConfig, &nToDo);
    }else{
        exit = true;
    }
    int i;
    IDX_TOP(itemInConfig) = nToDo - 1;
    itemInConfig.currCapacity = nToDo;
    itemInConfig.maxCapacity = nToDo;
    // QUEUE daftar item
    daftaritem = sortedqueue(itemInConfig, nToDo);
    for (i=0;i<nToDo;i++){
		daftaritem.buffer[i].beenPickedUp = false;
		daftaritem.buffer[i].beenDroppedOf = false;
	}
    // for (int k = 0; k<nToDo;k++){
    //     printf("waktu = %d\n", daftaritem.buffer[k].waktuMasuk);
    //     printf("jenisItem = %c\n", daftaritem.buffer[k].jenisItem);
    // }
    ///// COMMAND ////
    while (!exit){  
        printf("ENTER COMMAND : ");
        advWord();
        if (isWordString(currentWord, "MOVE")){

            MOVE(&player, AdjMtrx, daftarlokasi, &moves);
            /// WAKTU PLAYER
            if (moves){
                duration = TIME(player); //ini buat pengurangaan durasi perishable item
                TIME(player)++; //waktu normal nambah 1
                heavyItemTime(tas, &player); // efek heavy item
                Speed_Boost(&player,&tas, &ability);
                duration = TIME(player) - duration;
                //Hapus Item Perishable yang hangus
                PerishableTime(&tas, player, duration); //fungsi buat ngurangin waktu hangus + hapus kalo waktu hangus 0
            }
            printf("Waktu saat ini: %d\n\n", TIME(player));
        }
        else if (isWordString(currentWord, "PICK_UP")){
            if (!isEmptyQ(daftaritem) && daftaritem.buffer[IDX_HEAD(daftaritem)].lokSrc == LOCC(POSISI(player))){
                dequeue(&daftaritem, &buang);
                pickUpItem(&tas, buang);
                printf("\n");
            }
            else {
                printf("Pesanan tidak ditemukan!\n\n");
            }
        }
        else if (isWordString(currentWord, "DROP_OFF")){
            // cek lokasi apakah tempat drop_off benar
            // if (POSISI(*player).C == TOP(tas).lokDes[0]){
            if (LOCC(POSISI(player)) == TOP(tas).lokDes){
                dropOffItem(&player, &tas, &ability, &items); 
                printf("\n");
            }   
            else {
                printf("Tidak ada pesanan yang dapat diantarkan!\n\n");
            }
            // sudah ada mekanisme mendapat ability, price , efek heavy dll
        }
        else if (isWordString(currentWord, "MAP")){
            // printf("%d", nToDo);
            printMap(map, player, AdjMtrx, daftaritem, tas);
            printf("\n");
            //printMap(map, player, AdjMtrx, currentToDo(&itemInConfig, TIME(player), nToDo), tas);
            // printf("Map berhasil \n");
            
            //ini buat nyoba
            // Tas berisi1;
            // Item item1 = {'A', 'G', 'H', 6, 9, 400};
            // CreateTas(&berisi1);
            // addToTas(&berisi1, item1);
            // printMap(map, player, AdjMtrx, berisi1, tas);
            // printf("jumlah row : %d\n", ROWSMAP(map));
            // printf("jumlah col : %d\n", COLSMAP(map));
        }
        else if (isWordString(currentWord, "TO_DO")){
            // displayToDo(itemInConfig, TIME(player), nToDo);
            // TIME(player) =2;//nyoba
            // moveToDo(&daftaritem, &l, TIME(player));
            // displayl
            // printf("%c -> %c", INFO(l))
            // printf("%c", )
            displayToDo(daftaritem, TIME(player));
            printf("\n");
            // printf("To Do berhasil \n");
        }
        else if (isWordString(currentWord, "IN_PROGRESS")){
            displayInProgr(tas);
            printf("\n");
        }
        else if (isWordString(currentWord, "BUY")){
            if (LOCC(ELMTLD(daftarlokasi, 0)) != LOCC(POSISI(player))) {
                printf("Command ini hanya dapat dipanggil ketika Anda berada di Headquarter!\n\n");
                continue;
            }

            int buy;
            boolean keluar = false;
            printf("Uang yang tersedia : %i Yen\n", MONEY(player));
            printGadget();
            printf("ENTER COMMAND FOR BUY: ");
            advWord();
            buy = takeNum(currentWord);
            
            if (buy == 0) continue;
            else if ((buy >= 1) && (buy <= 4)){
                if (MONEY(player) < gadgetPrice(buy)) printf("Uang tidak cukup untuk membeli gadget.\n\n");
                else{
                    if (!isFullListLP(GADGET(player))) { 
                        insertLastLP(&GADGET(player), buy);
                        MONEY(player) -= gadgetPrice(buy);
                		buyGadget(GADGET(player), buy);
                        printf("\n");
                    }
                    else printf("Inventory telah penuh! Gunakan gadget yang Anda miliki terlebih dahulu sebelum membeli gadget lain.\n\n");
                }
            } else {
                printf("Input yang Anda masukkan salah, silahkan ulangi kembali!\n\n");
            	continue;
            }
        }
        else if (isWordString(currentWord, "INVENTORY")){
            int inv;
            boolean keluar = false;
            printInventory(GADGET(player));
            printf("ENTER COMMAND FOR INVENTORY: ");
            advWord();
            inv = takeNum(currentWord);

            if (inv == 0) continue;
            else if ((inv >= 1) && (inv <= 4)){
                if (indexOfLP(GADGET(player), inv) != IDX_UNDEFLP){
                    ElType remove;
                    swapLast(&GADGET(player), inv); 
                    deleteLastLP(&GADGET(player), &remove);
                    if (inv != 1) useGadget(GADGET(player), inv);
                    // printf("\n");

                    // Implementasi Gadget
                    // Kain Pembungkus Waktu
                    if (inv == 1){
                        // asumsi di taas ada perishable item 
                        foundP = false; //udah kudefine diatas //salah nama tyt HAHAHA GPP
                        indeksgadget = CURRENT_CAP(tas)-1;
                        // Mengembalikan waktu dari perishable item ke durasi semula
                        // tas itemInConfig 
                        while (foundP == false && indeksgadget !=-1){ 
                            if (tas.buffer[indeksgadget].jenisItem = 'P'){
                                for (int i = 0; i<nToDo; i++){
                                    if (tas.buffer[indeksgadget].jenisItem == itemInConfig.buffer[i].jenisItem && tas.buffer[indeksgadget].lokSrc == itemInConfig.buffer[i].lokSrc && tas.buffer[indeksgadget].lokDes == itemInConfig.buffer[i].lokDes && tas.buffer[indeksgadget].waktuMasuk == itemInConfig.buffer[i].waktuMasuk){
                                        tas.buffer[indeksgadget].waktuHangus =  itemInConfig.buffer[i].waktuHangus;
                                        foundP = true;
                                    }
                                }
                            }    
                            else {
                                indeksgadget = indeksgadget -1; 
                            }
                        }

                        if (foundP == false) {
                            insertLastLP(&GADGET(player), 1);
                            printf("Tidak ada perishable item, silahkan gunakan di lain waktu!\n");
                        } else useGadget(GADGET(player), inv);
                    }
                    // Senter Pembesar
                    else if (inv == 2){
                        // Meningkatkan kapasitas tas sebesar dua kali lipat
                        // Ini ada fungsi buat ganti kapasitas tas ga yaa?
                        if (tas.currCapacity * 2 <= CAPACITY_TAS) addCapTas(&tas, tas.currCapacity * 2);
                        else addCapTas(&tas, 100);
                        printf("Kapasitas tas sekarang adalah %d\n", tas.currCapacity);
                    }
                    // Pintu Kemana Saja
                    else if (inv == 3){
                        // Move tanpa menambah unit waktu
                        // OPSI 1
                        // changeTime(&player, (-1));
                        // OPSI 2
                        // bikin boolean PKSactive = false di awal
                        // disini PKSactive = true
                        // di mekanisme waktu, if PKSactive, berarti ganambah waktu
                        // OPSI 3
                        MOVE(&player, AdjMtrx, daftarlokasi, &moves);
                    } 
                    // Mesin Waktu
                    else if (inv == 4){
                        // Mengurangi unit waktu sebanyak 50
                        if (TIME(player) >= 50) changeTime(&player, (-50));
                        else changeTime(&player, -(TIME(player)));
                        printf("Waktu saat ini: %d\n", TIME(player));
                    }
                    printf("\n");
                } else {
                    printf("Tidak ada gadget yang dapat digunakan!\n\n");
                }
            } else {
                printf("Input yang Anda masukkan salah, silahkan ulangi kembali!\n\n");
            	continue;
            }
        }
        else if (isWordString(currentWord, "HELP")){
            help();
            printf("\n");
        }else if (isWordString(currentWord, "EXIT")){
            printf("Apakah kamu yakin ingin keluar? (Y/N)\n");
            advWord();
            if (isWordString(currentWord, "Y")){
                exit = true;
            } 
        }
        else{
            printf("Masukan Perintah Yang benar\n");
        }

        if((LOCC(ELMTLD(daftarlokasi, 0)) == LOCC(POSISI(player))) &&  isEmptyQ(daftaritem) && isTasEmpty(tas)){
            congratulations();
            printf("Jumlah item yang berhasil diantarkan : %d\n", nToDo);
            printf("Lama waktu permainan : %d\n", TIME(player));
            exit = true;
        }

    }


    close();
    return 0;
}
