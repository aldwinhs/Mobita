#ifndef ABILITY_H
#define ABILITY_H

#include "../ADT/boolean.h"
#include "../ADT/tas.h"
#include "player.h"
typedef struct
{
   int Speed_Boost; // setiap mendapat ability speedboost tambah 10
   int time;
} Ability;

#define SPEED(t) (t).Speed_Boost
void Speed_Boost(Player *P, Tas *S, Ability *A);

void Cancel_Speed_Bost(Ability *A);

void Increase_Capacity(Tas *T);

void Return_to_Sender();

boolean isHaveHeavyItem(Tas T);

void heavyItemTime(Tas T, Player *P);

void PerishableTime(Tas *T, Player P);

boolean compare3(char *array1, char *array2);

void removeitem(Tas *S, int i);
#endif
