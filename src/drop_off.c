#include "drop_off.h"
#include <stdio.h>
#include <stdlib.h>

void dropOffItem(Player *p, Tas *S, Ability *A, Item *item)
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
            SPEED(*A) += 10;
            SUM_HEAVY(*S)
            --;
        }
        else if (compare2(item->jenisItem, "P"))
        {

            printf("Pesanan berupa Perishable Item berhasil diantarkan\n");
            // dapet ability Increase Capacity
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

boolean compare2(char *array1, char *array2)
{

    int i;
    boolean compare = false;
    i = 0;
    while (array1[i] == array2[i] && compare == false)
    {
        if (array1[i] == '\0' || array2[i] == '\0')
        {
            compare = true;
        }
        i++;
    }
    return compare;
}