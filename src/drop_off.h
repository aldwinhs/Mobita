#ifndef DROP_OFF_H
#define DROP_OFF_H

#include "../ADT/tas.h"
#include "../ADT/boolean.h"
#include "player.h"
#include "ability.h"

void dropOffItem(Player *p, Tas *S, Ability *T, Item *item);

boolean compare2(char *array1, char *array2);

#endif