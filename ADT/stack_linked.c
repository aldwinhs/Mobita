#include <stdlib.h>
#include "stack_linked.h"

/* Prototype manajemen memori */

/* Mengembalikan alamat sebuah Nodee hasil alokasi dengan info = x,
   atau
   NULL jika alokasi gagal */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmptyDif(Stack s) {
    return(ADDR_TOPLS(s) == NULL);
}
/* Mengirim true jika Stack kosong: ADDR_TOP(s) = NULL */
void CreateStack(Stack *s) {
    ADDR_TOPLS(*s) = NULL;
}
/* I.S. sembarang */
/* F.S. Membuat sebuah stack s yang kosong */
void push(Stack *s, item x) {
    AddressNode q;
    q = newNode(x);

    if(q != NULL) {
        if(isEmptyDif(*s)) {
            ADDR_TOPLS(*s) = q;
        } else {
            NEXTLS(q) = ADDR_TOPLS(*s);
            ADDR_TOPLS(*s) = q;
        }
    }
}
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
void pop(Stack *s, item *x) {
    *x = TOPLS(*s);
    AddressNode p = ADDR_TOPLS(*s);
    ADDR_TOPLS(*s) = NEXTLS(p);
    NEXTLS(p) = NULL;
    free(p);
}
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */