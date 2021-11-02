#include "../ADT/stack.h"
#include "../ADT/boolean.h"
#include "pick_off.h"
#include <stdio.h>
#include <stdlib.h>

void pickOff(Stack *S, char item)
{
    if (!isVIPitem(*S))
    {
        if (item == 'N')
        {
            printf("Pesanan berupa Normal Item berhasil diambil!\n");
        }
        else if (item == 'H')
        {
            printf("Pesanan berupa Heavy Item berhasil diambil!\n");
        }
        else if (item == 'P')
        {
            printf("Pesanan berupa Perishable Item berhasil diambil!\n");
            // harusnya input waktu juga
        }
        else if (item == 'V')
        { // item = 'V'
            printf("Pesanan berupa VIP Item Item berhasil diambil!\n");
        }
        else
        { //  tidak terdapat item dalam posisi tersebut
            printf("Pesanan tidak ditemukan!\n");
        }
        if (isItem(item))
        {
            push(S, item);
        }
    }
    else
    {
        printf("VIP item harus dilayani terlebih dahulu\n");
    }
}

boolean isVIPitem(Stack S)
{
    return (TOP(S) == 'V');
}

boolean isItem(char item)
{
    return (item == 'N' || item == 'H' || item == 'P' || item == 'V');
}

/////// TEST //////////
/*
int main()
{
    char item;
    Stack S;
    CreateStack(&S);
    for (int i = 0; i < 5; i++)
    {
        scanf("\n%c", &item);
        pickOff(&S, item);
    }
    ElType val;
    while (!isEmpty(S))
    {
        pop(&S, &val);
        printf("%c\n", val);
    }
    return 0;
}
*/
//gcc -o main pick_off.c ../ADT/stack.c