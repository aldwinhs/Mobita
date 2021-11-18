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
        if ((*item).jenisItem == 'N') //bekas tadi
        {
            printf("Pesanan Normal Item berhasil diantarkan\n");
        }
        else if ((*item).jenisItem == 'H')
        {
            printf("Pesanan berupa Heavy Item berhasil diantarkan\n");
            // mendabatkan ability speed_boost
            SPEED(*A) += 11;
            SUM_HEAVY(*S) //jumlah heavy item di dalam tas berkurang
            --;
        }
        else if ((*item).jenisItem== 'P')
        {
            printf("Pesanan berupa Perishable Item berhasil diantarkan\n");
            Increase_Capacity(S); // mendapatkan ability increase capacity tas
        }
        else if ((*item).jenisItem== 'V')
        {
            printf("Pesanan berupa VIP Item Item berhasil diantarkan\n");
            RETURN(*A)++;
            // ability Return To Sender
        }
        else
        { //  tidak terdapat item dalam posisi tersebut
            printf("Tidak terdapat pesanan yang dapat diantarkan!\n");
        }
        addMoney(p, (*item).price);
        printf("Uang yang didapatkan: %d\n", (*item).price);
    }
}
