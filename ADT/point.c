/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include "boolean.h"
#include "point.h"
#include <math.h>
#include <stdio.h>
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (char C, int X, int Y){
	/* Membentuk sebuah POINT dari komponen-komponennya */
	POINT P;
	LOCC(P) = C;
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
};
