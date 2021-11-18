
#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
	NEFFLD(*l) = 0;
	CAPACITYLD(*l) = capacity;
	BUFFERLD(*l) = (POINT *)malloc(capacity* sizeof (POINT));
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthLD(ListDin l){
	return (l.nEff);
}