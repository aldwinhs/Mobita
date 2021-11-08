#include "../ADT/stack.h"
#include "../ADT/boolean.h"
#include "pick_up.h"
#include "drop_off.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

void dropOffItem(Player *p, Stack *S, Item *T, ElTypeStack *item)
{
    if (isEmptyStack(*S))
    {
        printf("Tidak terdapat pesanan yang dapat diantarkan!");
    }
    else
    {
        pop(S, item);
        if (*item == 'N')
        {
            addMoney(p, 200);
            printf("Pesanan Normal Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 200\n");
        }
        else if (*item == 'H')
        {
            addMoney(p, 400);
            printf("Pesanan berupa Heavy Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 400\n");
            SPEED(*T) += 10;
            SUM_HEAVY(*T)
            --;
        }
        else if (*item == 'P')
        {
            addMoney(p, 400);
            printf("Pesanan berupa Perishable Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 400\n");
            // dapet ability Increase Capacity
        }
        else if (*item == 'V')
        {
            addMoney(p, 600);
            printf("Pesanan berupa VIP Item Item berhasil diantarkan\n");
            printf("Uang yang didapatkan: 600\n");
            // ability Return To Sender
        }
        else
        { //  tidak terdapat item dalam posisi tersebut
            printf("Tidak terdapat pesanan yang dapat diantarkan!\n");
        }
    }
}

int main()
{
    char item;
    Player P;
    // createPlayer(&P);
    MONEY(P) = 0;
    TIME(P) = 0;
    Stack S;
    Item T;
    CreateStack(&S);
    CreateItem(&T);
    for (int i = 0; i < 5; i++)
    {
        scanf("\n%c", &item);
        pickUpItem(&S, &T, item);
        heavyItemTime(T, &P);
        printf("%d\n", TIME(P));
    }
    printf("%c", TOP(S));
    ElTypeStack val;
    while (!isEmptyStack(S))
    {
        dropOffItem(&P, &S, &T, &val);
        printf("%d\n", MONEY(P));
    }
    printf("%d", SUM_HEAVY(T));
    return 0;
}
// gcc -o main pick_up.c ../ADT/stack.c player.c ../ADT/listpos.c drop_off.c