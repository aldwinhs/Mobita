#ifndef DROP_OFF_H
#define DROP_OFF_H

#include "../ADT/tas.h"
#include "../ADT/boolean.h"
#include "../ADT/player.h"
#include "ability.h"

void dropOffItem(Player *p, Tas *S, Ability *T, Item *item);

#endif