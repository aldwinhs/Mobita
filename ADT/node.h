#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include "tas.h"

typedef struct node* AddressNode;
typedef struct node {
    item info; // kalo dilokalku ga  eror nah udah engga, mengeleg keknya
    AddressNode next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

AddressNode newNode(item val);

#endif
