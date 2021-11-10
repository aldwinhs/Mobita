#include "ability.h"
#include <stdio.h>
#include <stdlib.h>

void Speed_Boost(Player *P, Tas *S, Ability *A)
// Waktu akan bertambah 1 unit setiap Mobita berpindah 2 lokasi. Efek
// ini berlangsung hingga Mobita telah melewati 10 lokasi (berlaku selama 5
// unit waktu).Ability ini akan segera hilang bila Mobita melakukan pick up Heavy Item
// atau mendapatkan ability ketika sedang membawa Heavy Item lain.
{
    if (isHaveHeavyItem(*S))
    {
        Cancel_Speed_Bost(A);
    }
    else
    {
        if (SPEED(*A) != 0)
        {
            SPEED(*A)
            --;
            if (SPEED(*A) % 2 != 0)
            {
                changeTime(P, -1); // berkurang 1 setiap ability SPEEDBOOST mod 2 == 0;
            }
        }
    }
}
void Cancel_Speed_Bost(Ability *A)
// Speed boost akan dibatalkan jika terdapat heavy item atau melakukan pick up heavy item
{
    SPEED(*A) = 0;
}

void Increase_Capacity(Tas *T)
// Karena bungkus Perishable Item dapat digunakan lagi dan diberikan
// kepada Mobita, maka bungkus ini digantung di luar tas dan dapat
// digunakan untuk membawa item lebih.
// ● Kapasitas tas bertambah 1
{
    MAX_TAS(*T)
    ++;
}

void Return_to_Sender(Tas *S)
// Jika ability ini digunakan dengan command RETURN, maka item di atas
// tas dikembalikan ke lokasi pick up
// Efek: Pesanan akan dikembalikan ke To Do List di urutan terakhir.
// Efek: Time limit yang terdapat pada pesanan dengan Perishable Item
// akan di-reset sebelum dikembalikan.
// Ability ini tidak dapat diaktifkan untuk pesanan VIP Item
{
    item item;
    rmvFromTas(S, &item);
    if (compare2(item.jenisItem, "P"))
    {
    }
    //insertlastdi todo list
}

boolean isHaveHeavyItem(Tas T)
// mengirimkan true jika terdapat heavy item di tas
{
    return (SUM_HEAVY(T) > 0);
}

void heavyItemTime(Tas T, Player *P)
// I.S waktu terdefinisi
// F.S Setiap pindah ke 1 lokasi maka waktu akan bertambah 1 unit (1+1 =
// 2 unit). Efek ini dapat menumpuk.
{
    if (isHaveHeavyItem(T))
    {
        changeTime(P, SUM_HEAVY(T));
    }
}
void PerishableTime(Tas *T, Player P)
{
    int i;
    Item item;
    for (i = 0; i < CURRENT_CAP(*T); i++)
    {
        item = (*T).buffer[i];
        int duration;
        if (compare2(item.jenisItem, "P"))
        {
            duration = TIME(P) - item.waktuMasuk;
            (*T).buffer[i].waktuHangus -= duration;
            if ((*T).buffer[i].waktuHangus == 0)
            {
                removeitem(T, i);
            }
        }
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

void removeitem(Tas *S, int i)
{
    Tas S2;
    Item item;
    CreateTas(&S2);
    MAX_TAS(S2) = MAX_TAS(*S);
    int j;
    for (j = 0; j <= i; j++)
    {
        rmvFromTas(S, &item);
        addToTas(&S2, item);
    }
    rmvFromTas(S, &item);
    for (j = 0; j < CURRENT_CAP(S2); j++)
    {
        rmvFromTas(S, &item);
        addToTas(&S2, item);
    }
    free(&S2);
}