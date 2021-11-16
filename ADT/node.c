/* File: node.c */
/* Implementasi Node */

#include "node.h"
#include <stdlib.h>

AddressNode newNode(item val) {
    AddressNode p = (AddressNode) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}