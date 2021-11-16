/* 
Nama    : Aldwin Hardi Swastia
NIM     : 13520167 
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m){
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    COLS(*m) = nCol;
    ROWS(*m) = nRow;
}

/* *** Selektor "DUNIA Matrix" *** */
// boolean isIdxValid(int i, int j){
// /* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
//     return ((i>=0) && (i<ROW_CAP) && (j>=0) && (j<COL_CAP));
// }

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m){
/* Mengirimkan Index baris terbesar m */
    return ROWS(m)-1;
}

Index getLastIdxCol(Matrix m){
/* Mengirimkan Index kolom terbesar m */
    return COLS(m)-1;
}
// boolean isIdxEff(Matrix m, Index i, Index j){
// /* Mengirimkan true jika i, j adalah Index efektif bagi m */
//     return ((i>=0) && (i<ROWS(m)) && (j>=0) && (j<COLS(m)));
// }
ElType getElmtDiagonal(Matrix m, Index i){
/* Mengirimkan elemen m(i,i) */
    return ELMTM(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes){
/* Melakukan assignment MRes = MIn */
    *mRes = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
    int i,j;
    CreateMatrix(nRow, nCol, m);
    for ( i = 0; i < nRow; i++)
    {
        for ( j = 0; j < nCol; j++)
        {
            scanf("%d", &ELMTM(*m, i, j));
        }
    }
    
    
}
void displayMatrix(Matrix m){
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
    int i,j;
    for ( i = 0; i < ROWS(m); i++)
    {
        for ( j = 0; j < COLS(m); j++)
        {
            if (j != getLastIdxCol(m))
            {
                printf("%d ", ELMTM(m, i, j));
            }
            else
            {
                printf("%d", ELMTM(m, i, j));
            }
                
        }
        if (i != getLastIdxRow(m))
        {
            printf("\n");
        }
        ;
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
    Matrix m; int i,j;
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    for ( i = 0; i < ROWS(m1); i++)
    {
        for ( j = 0; j < COLS(m1); j++)
        {
            ELMTM(m,i,j) = ELMTM(m1,i,j) + ELMTM(m2,i,j);
        }
        
    }
    return m;
}
Matrix subtractMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    Matrix m; int i,j;
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    for ( i = 0; i < ROWS(m1); i++)
    {
        for ( j = 0; j < COLS(m1); j++)
        {
            ELMTM(m,i,j) = ELMTM(m1,i,j) - ELMTM(m2,i,j);
        }
        
    }
    return m;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2){
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    Matrix m; int i,j,k,sum;
    CreateMatrix(ROWS(m1), COLS(m2), &m);
    for ( i = 0; i < ROWS(m); i++)
    {
        for ( j = 0; j < COLS(m); j++)
        {
            sum = 0;
            for ( k = 0; k < COLS(m1) ; k++)
            {
                sum += ELMTM(m1,i,k) * ELMTM(m2,k,j);
            }
            ELMTM(m,i,j) = sum;
        }
        
    }
    return m;
}
Matrix multiplyConst(Matrix m, ElType x){
/* Mengirim hasil perkalian setiap elemen m dengan x */
    Matrix m2; int i,j;
    CreateMatrix(ROWS(m), COLS(m), &m2);
    for ( i = 0; i < ROWS(m); i++)
    {
        for ( j = 0; j < COLS(m); j++)
        {
            ELMTM(m2,i,j) = ELMTM(m,i,j) * x;
        }
        
    }
    return m2;
}
void pMultiplyConst(Matrix *m, ElType k){
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    int i,j;
    for ( i = 0; i < ROWS(*m); i++)
    {
        for ( j = 0; j < COLS(*m); j++)
        {
            ELMTM(*m,i,j) = ELMTM(*m,i,j) * k;
        }
        
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    int i,j;
    if (count(m1)!=count(m2))
    {
        return false;
    }

    if (!isSizeEqual(m1,m2))
    {
        return false;
    }
    else
    {
        for ( i = 0; i < ROWS(m1); i++)
        {
            for ( j = 0; j < COLS(m1); j++)
            {
                if (ELMTM(m1,i,j)!=ELMTM(m2,i,j))
                {
                    return false;
                }
                
            }
            
        }
    }
    return true;
}
boolean isNotEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    return (!isEqual(m1,m2));
}
boolean isSizeEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    return ((ROWS(m1)==ROWS(m2)) && (COLS(m1)==COLS(m2)));
}

/* ********** Operasi lain ********** */
int count(Matrix m){
/* Mengirimkan banyaknya elemen m */
    return (ROWS(m)*COLS(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return (ROWS(m)==COLS(m));
}
boolean isSymmetric(Matrix m){
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
    if (!isSquare(m))
    {
        return false;
    }
    else
    {
        int i,j;
        for ( i = 0; i < ROWS(m); i++)
        {
            for ( j = 0; j < COLS(m); j++)
            {
                if (ELMTM(m,i,j)!=ELMTM(m,j,i))
                {
                    return false;
                }
                
            }
            
        }
        
    }
    return true;
}
boolean isIdentity(Matrix m){
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    if (!isSquare(m))
    {
        return false;
    }
    else
    {
        int i,j;
        for ( i = 0; i < ROWS(m); i++)
        {
            for ( j = 0; j < COLS(m); j++)
            {
                if (i==j)
                {
                    if (ELMTM(m,i,j)!=1)
                    {
                        return false;
                    }
                    
                }
                else
                {
                    if (ELMTM(m,i,j)!=0)
                    {
                        return false;
                    }
                    
                }
                
                
            }
            
        }
        
    }
    return true;
}
boolean isSparse(Matrix m){
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    int i,j; float jml = 0;
    for ( i = 0; i < ROWS(m); i++)
    {
        for ( j = 0; j < COLS(m); j++)
        {
            if (ELMTM(m,i,j)!=0)
            {
                jml++;
            }
            
        }
        
    }
    return ((jml/count(m))<=0.05);
}
Matrix inverse1(Matrix m){
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    return multiplyConst(m, -1);
}
void pInverse1(Matrix *m){
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    pMultiplyConst(m, -1);
}
float determinant(Matrix m){
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
    if (ROWS(m)==1)
    {
        return (ELMTM(m,0,0));
    }
    else
    {
        int i,j,x,y,t; float det; Matrix tmp; det = 0;
        CreateMatrix(ROWS(m)-1, COLS(m)-1, &tmp);
        for ( i = 0; i < ROWS(m); i++)
        {
            x = 0;
            for ( j = 1; j < COLS(m); j++)
            {
                y = 0;
                for ( t = 0; t < ROWS(m); t++)
                {
                    if (i!=t)
                    {
                        ELMTM(tmp,x,y) = ELMTM(m,t,j);y++;
                    }
                    
                }
                x++;
            }
            if (i%2==0)
            {
                det += ELMTM(m,i,0) * determinant(tmp);
            }
            else
            {
                det -= ELMTM(m,i,0) * determinant(tmp); 
            }
            
        }
        return det;
    }
    
}
void transpose(Matrix *m){
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    Matrix tmp; int i,j;
    tmp = *m;
    for ( i = 0; i < ROWS(*m); i++)
    {
        for ( j = 0; j < COLS(*m); j++)
        {
            ELMTM(tmp,i,j) = ELMTM(*m,j,i); 
        }
        
    }
    copyMatrix(tmp,m);
}