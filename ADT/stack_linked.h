/* File: stack_linked.h */

#ifndef STACK_LINKED_H
#define STACK_LINKED_H

#include "boolean.h"
#include "tas.h"
#include <stdlib.h>

/* Stack dengan representasi berkait dengan pointer */
typedef struct node* Address;
typedef struct node {
    item info;
    Address next;
} Node;

/* Type stack dengan ciri Top: */
typedef struct {
    Address addrTop; /* alamat Top: elemen puncak */
} Stack;

/* Selektor */
#define     NEXTLS(p) (p)->next
#define     INFOLS(p) (p)->info
#define ADDR_TOPLS(s) (s).addrTop
#define      TOPLS(s) (s).addrTop->info

/* Prototype manajemen memori */
Address newNode(item x);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
   atau
   NULL jika alokasi gagal */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s);
/* Mengirim true jika Stack kosong: ADDR_TOP(s) = NULL */
void CreateStack(Stack *s);
/* I.S. sembarang */
/* F.S. Membuat sebuah stack s yang kosong */
void push(Stack *s, item x);
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
void pop(Stack *s, item *x);
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */

#endif