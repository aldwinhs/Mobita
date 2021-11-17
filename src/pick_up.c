#include "pick_up.h"
#include <stdio.h>
#include <stdlib.h>
#include "player.h"


void pickUpItem(Tas *S, Item T)
{
    if (!isTasFull(*S))
    {
        if (!isVIPitem(*S))
        {

            if (T.jenisItem== 'N')
            {
                printf("Pesanan berupa Normal Item berhasil diambil!\n");
                T.price = 200;
            }
            else if (T.jenisItem== 'H')
            {
                printf("Pesanan berupa Heavy Item berhasil diambil!\n");
                SUM_HEAVY(*S) += 1;
                T.price = 400;
            }
            else if (T.jenisItem== 'P')
            {
                printf("Pesanan berupa Perishable item berhasil diambil!\n");
                T.price = 400;
            }
            else if (T.jenisItem== 'V')
            {
                printf("Pesanan berupa VIP item berhasil diambil!\n");
                T.price = 600;
            }
            else
            { //  tidak terdapat jenisItemdalam posisi tersebut
                printf("Pesanan tidak ditemukan!\n");
            }

            if (isItem(T.jenisItem))
            {
                addToTas(S, T);
                T.beenPickedUp = true;
            }
        }
        else
        {
            printf("VIP Item harus dilayani terlebih dahulu\n");
        }
    }
    else
    {
        printf("Tas Penuh!\n");
    }
}


boolean isVIPitem(Tas S)
/* menghasilkan true jika pesanan pada top merupakan VIP ITEM sehingga tidak dapat melakukan pick_up pesanan lain */
{

    Item T = TOP(S);
    if (isTasEmpty(S))
    {
        return false;
    }
    return (T.jenisItem == 'V');
}

boolean isItem(char jenisitem)
/* menghasilkan true jika jenis pesanan valid */
{
    return (jenisitem == 'N' || jenisitem == 'H' || jenisitem == 'P' || jenisitem == 'V');
}

boolean compare(char *array1, char *array2)
// membandingkan string
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

// void pickUpItem(Tas *S, char *locSrc, char *locDes, char *jenisItem, int waktumasuk, int waktuhangus)
// /* I.S Sembarang */
// /* F.S item masuk ke dalam Tas*/
// {
//     int price;
//     if (!isTasFull(*S))
//     {
//         if (!isVIPitem(*S))
//         {
//             if (*jenisItem == 'N')
//             {
//                 printf("Pesanan berupa Normal Item berhasil diambil!\n");
//                 price = 200;
//             }
//             else if (*jenisItem == 'H')
//             {
//                 printf("Pesanan berupa Heavy Item berhasil diambil!\n");
//                 SUM_HEAVY(*S) += 1;
//                 price = 400;
//             }
//             else if (*jenisItem == 'P')
//             {
//                 printf("Pesanan berupa Perishable item berhasil diambil!\n");
//                 price = 400;
//             }
//             else if (*jenisItem == 'V')
//             {
//                 printf("Pesanan berupa VIP item berhasil diambil!\n");
//                 price = 600;
//             }
//             else
//             { //  tidak terdapat jenisItemdalam posisi tersebut
//                 printf("Pesanan tidak ditemukan!\n");
//             }

//             if (isItem(jenisItem))
//             {
//                 Item Curritem = {locSrc, locDes, jenisItem, waktumasuk, waktuhangus, price};
//                 addToTas(S, Curritem);
//             }
//         }
//         else
//         {
//             printf("VIP Item harus dilayani terlebih dahulu\n");
//         }
//     }
//     else
//     {
//         printf("Tas Penuh!\n");
//     }
// }