#include <stdio.h>
#include "../buy.c"
#include "../../ADT/listpos.c"

// cek dulu posisinya di headquarters apa ga klo ga gabisa dipake --> khusus buy
// ini nanti dipindahin ke main.c
int main(){
    int money, op;
    ListPos gdgt;
    CreateListPos(&gdgt);
    money = 10000; //inisialisasi uang 
    boolean keluar = false;

    printf("1. Buy\n2. Keluar\n");
    printf("ENTER COMMAND : ");
    scanf("%d", &op);

    while (op != 2){
        if (op == 1){
            int buy;
            printf("Uang yang tersedia : %i Yen\n", money);
            printGadget();
            printf("ENTER COMMAND : ");
            scanf("%d", &buy);
            
            if ((buy >= 1) && (buy <= 4)) {
                if (money < gadgetPrice(buy)) printf("Uang tidak cukup untuk membeli gadget.\n");
                else{
                    if (!isFullListLP(gdgt)) { 
                        insertLastLP(&gdgt, buy);
                        money -= gadgetPrice(buy);
                		printf("\n");
                    }
                    else printf("Inventory telah penuh! Gunakan gadget yang Anda miliki terlebih dahulu sebelum membeli gadget lain.\n");
                }
            } else if (buy == 0) keluar = true;
            else {
            	printf("Input yang Anda masukkan salah, silahkan ulangi kembali!\n");
            	continue;
			}
        }

        printf("Isi List Gadget : ");
        displayListLP(gdgt);
        printf("\n");
        
        printf("1. Buy\n2. Keluar\n");
    	printf("ENTER COMMAND : ");
    	scanf("%d", &op);
    }
}
