#include "drop_off.h"
#include <stdio.h>
#include <stdlib.h>

void dropOffItem(Player *p, Tas *S, Ability *A, Item *item)
/* I.S Sembarang */
/* F.S item dikeluarkan dari Tas*/
{
    if (isTasEmpty(*S))
    {
        printf("Tidak terdapat pesanan yang dapat diantarkan!");
    }
    else
    {
        rmvFromTas(S, item);
        if (compare2(item->jenisItem, "N"))
        {
            printf("Pesanan Normal Item berhasil diantarkan\n");
        }
        else if (compare2(item->jenisItem, "H"))
        {
            printf("Pesanan berupa Heavy Item berhasil diantarkan\n");
            SPEED(*A) += 11; // mendabatkan ability speed_boost
            if (SPEED(*A) > 11)
            {
                SPEED(*A)
                --;
            }
            SUM_HEAVY(*S) //jumlah heavy item di dalam tas berkurang
            --;
        }
        else if (compare2(item->jenisItem, "P"))
        {
            printf("Pesanan berupa Perishable Item berhasil diantarkan\n");
            Increase_Capacity(S); // mendapatkan ability increase capacity tas
        }
        else if (compare2(item->jenisItem, "V"))
        {
            printf("Pesanan berupa VIP Item Item berhasil diantarkan\n");
            // ability Return To Sender
        }
        else
        { //  tidak terdapat item dalam posisi tersebut
            printf("Tidak terdapat pesanan yang dapat diantarkan!\n");
        }
        addMoney(p, item->price);
        printf("Uang yang didapatkan: %d\n", item->price);
    }
}
