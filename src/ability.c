#include "ability.h"
#include "pick_up.h"
#include <stdio.h>
#include <stdlib.h>

void Speed_Boost(Player *P, Item *T)
// Waktu akan bertambah 1 unit setiap Mobita berpindah 2 lokasi. Efek
// ini berlangsung hingga Mobita telah melewati 10 lokasi (berlaku selama 5
// unit waktu).Ability ini akan segera hilang bila Mobita melakukan pick up Heavy Item
// atau mendapatkan ability ketika sedang membawa Heavy Item lain.
{
    if (isHaveHeavyItem(*T))
    {
        Cancel_Speed_Bost(T);
    }
    else
    {
        if (SPEED(*T) % 2 == 0)
        {
            changeTime(P, -1); // berkurang 1 setiap ability SPEEDBOOST mod 2 == 0;
        }
        SPEED(*T)
        --;
    }
}
void Cancel_Speed_Bost(Item *T)
{
    SPEED(*T) = 0;
}

void Increase_Capacity()
// Karena bungkus Perishable Item dapat digunakan lagi dan diberikan
// kepada Mobita, maka bungkus ini digantung di luar tas dan dapat
// digunakan untuk membawa item lebih.
// ● Kapasitas tas bertambah 1
{
}

void Return_to_Sender()
{
}