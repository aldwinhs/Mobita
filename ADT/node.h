#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include "tas.h"

typedef Item ElType;
typedef struct node* Address;
typedef struct node {
    ElType info; // kalo dilokalku ga eror nah udah engga, mengeleg keknya
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType val);

#endif
