#ifndef ABILITY_H
#define ABILITY_H

#include "../ADT/boolean.h"
#include "../ADT/tas.h"
#include "player.h"
typedef struct
{
   int Speed_Boost; // setiap mendapat ability speedboost tambah 10
   int Return;
} Ability;

#define SPEED(t) (t).Speed_Boost
#define RETURN(t) (t).Return

void CreateAbility(Ability *A);

void Speed_Boost(Player *P, Tas *S, Ability *A);
// Waktu akan bertambah 1 unit setiap Mobita berpindah 2 lokasi. Efek
// ini berlangsung hingga Mobita telah melewati 10 lokasi (berlaku selama 5
// unit waktu).Ability ini akan segera hilang bila Mobita melakukan pick up Heavy Item
// atau mendapatkan ability ketika sedang membawa Heavy Item lain.
// implementasinya jika SPEED mod 2 == 1 maka dikurangi 1 waktu, ketika melakukan 2 move hanya dihitung 1 waktu 

void Cancel_Speed_Bost(Ability *A);
// Speed boost akan dibatalkan jika terdapat heavy item atau melakukan pick up heavy item

void Increase_Capacity(Tas *T);
// Karena bungkus Perishable Item dapat digunakan lagi dan diberikan
// kepada Mobita, maka bungkus ini digantung di luar tas dan dapat
// digunakan untuk membawa item lebih.
// ● Kapasitas tas bertambah 1

void Return_to_Sender();
// Jika ability ini digunakan dengan command RETURN, maka item di atas
// tas dikembalikan ke lokasi pick up
// Efek: Pesanan akan dikembalikan ke To Do List di urutan terakhir.
// Efek: Time limit yang terdapat pada pesanan dengan Perishable Item
// akan di-reset sebelum dikembalikan.
// Ability ini tidak dapat diaktifkan untuk pesanan VIP Item

boolean isHaveHeavyItem(Tas T);
// mengirimkan true jika terdapat heavy item di tas

void heavyItemTime(Tas T, Player *P);
// I.S sembarang
// F.S Setiap pindah ke 1 lokasi maka waktu akan bertambah 1 unit (1+1 = 2 unit). Efek ini dapat menumpuk.

void PerishableTime(Tas *T, Player P,int duration);
// I.S terdapat perishable item di tas
// F.S Perishable Item harus diantarkan ke lokasi drop off dalam waktu yang
// ditentukan. Jika waktu habis, maka item akan dikeluarkan secara otomatis
// dari tas, dan pesanan akan dihapus secara otomatis dari In Progress List

boolean compare2(char *array1, char *array2);
// menghasilkan true jika char array1 = array2

void removeitem(Tas *S, int i);
// I.S Sembarang
// F.S Perishable item dihapus dari tas
#endif
