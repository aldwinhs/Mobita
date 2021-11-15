#include <stdio.h>
#include "gadget.c"
#include "../ADT/listpos.c"
#include "player.h"

// cek dulu posisinya di headquarters apa ga klo ga gabisa dipake --> khusus buy
// ini nanti dipindahin ke main.c
int main(){
    int money, op;
    ListPos gdgt;
    CreateListPos(&gdgt);
    money = 10000; //inisialisasi uang 

    printf("1. Buy\n2. Inventory\n3. Keluar\n");
    printf("ENTER COMMAND : ");
    scanf("%d", &op);

    while (op != 3){
        // BUY!!
        if (op == 1){
            int buy;
            printf("Uang yang tersedia : %i Yen\n", money); //Money nanti diganti jadi MONEY(p)
            printGadget();
            printf("ENTER COMMAND : ");
            scanf("%d", &buy);

            if (buy == 0) printf("break");
            else {
                if (money < gadgetPrice(buy)) printf("Uang tidak cukup untuk membeli gadget.\n");
                else{
                    if (!isFull(gdgt)) {
                        insertLast(&gdgt, buy);
                        money -= gadgetPrice(buy);
                        displayList(gdgt);
                		printf("\n");
                    }
                    else printf("Inventory telah penuh! Gunakan gadget yang Anda miliki terlebih dahulu sebelum membeli gadget lain.\n");
                }
            }
        }

    // INVENTORY
        if (op == 2){
            int inv;
            printInventory(gdgt);
            printf("ENTER COMMAND : ");
            scanf("%d", &inv);

            if (indexOf(gdgt, inv) != IDX_UNDEF){
                //GDGT DIGANTI JADI GADGET(p);
                ElType remove;
                swapLast(&gdgt, inv); 
                deleteLast(&gdgt, &remove);
                useGadget(gdgt, inv);
                displayList(gdgt);
                printf("\n");
                // Kain Pembungkus Waktu
                if (inv == 1){
                    // Mengembalikan waktu dari perishable item ke durasi semula
                }
                // Senter Pembesar
                else if (inv == 2){
                    // Meningkatkan kapasitas tas sebesar dua kali lipat
                }
                // Pintu Kemana Saja
                else if (inv == 3){
                    // Move tanpa menambah unit waktu
                } 
                // Mesin Waktu
                else if (inv == 4){
                    // Mengurangi unit waktu sebanyak 50
                    if (TIME(p) >= 50) changeTime(&p, (-50));
                    else changeTime(&p, TIME(p));
                }
            } else {
                printf("Tidak ada gadget yang dapat digunakan!\n");
            }
        }
        
        printf("1. Buy\n2. Inventory\n3. Keluar\n");
    	printf("ENTER COMMAND : ");
    	scanf("%d", &op);
    }

}
