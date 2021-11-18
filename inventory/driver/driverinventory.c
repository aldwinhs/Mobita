#include <stdio.h>
#include "../inventory.c"
#include "../../ADT/listpos.c"

// cek dulu posisinya di headquarters apa ga klo ga gabisa dipake --> khusus buy
// ini nanti dipindahin ke main.c
int main(){
    int money, op;
    ListPos gdgt;
    CreateListPos(&gdgt);
    insertLastLP(&gdgt, 1);
    insertLastLP(&gdgt, 1);
    insertLastLP(&gdgt, 2);
    insertLastLP(&gdgt, 3);
    insertLastLP(&gdgt, 4);
    boolean keluar = false;

    printf("1. Inventory\n2. Keluar\n");
    printf("ENTER COMMAND : ");
    scanf("%d", &op);

    while (op != 2){
    // INVENTORY
        if (op == 1){
            int inv;
            printInventory(gdgt);
            printf("ENTER COMMAND : ");
            scanf("%d", &inv);
			
			if ((inv >= 1) && (inv <= 4)){
	            if (indexOfLP(gdgt, inv) != IDX_UNDEFLP){
	                int remove;
	                swapLast(&gdgt, inv); 
	                deleteLastLP(&gdgt, &remove);
	                useGadget(gdgt, inv);
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
	                    // if (TIME(p) >= 50) changeTime(&p, (-50));
	                    // else changeTime(&p, TIME(p));
	                }
	            } else {
	                printf("Tidak ada gadget yang dapat digunakan!\n");
	            }
	    	} else if (inv == 0) keluar = true;
	    	else {
	    		printf("Input yang Anda masukkan salah, silahkan ulangi kembali!\n");
            	continue;
			}
        }

        printf("Isi List Gadget :");
        displayListLP(gdgt);
        printf("\n");

        printf("1. Inventory\n2. Keluar\n");
    	printf("ENTER COMMAND : ");
    	scanf("%d", &op);
    }

}