/* File: wordmachine.c */

#include "wordmachine.h"
#include <stdio.h>
boolean endWord;
Word currentWord;

void ignoreBlank(){
	while (currentChar == BLANK){
		adv();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = MARK */

void startWord(){
	start();
	ignoreBlank();
	if (currentChar != MARK){
		endWord = false;
		copyWord();
	} else endWord = true;
}
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advWord(){
	copyWord();
	ignoreBlank();
	if (currentChar == MARK) endWord = true;
	else endWord = false;
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWord(){
	ignoreBlank();
	currentWord.length = 0;
	while((currentChar != BLANK) && (currentChar!= MARK) && (currentWord.length < CAPACITY)){
		currentWord.contents[currentWord.length] = currentChar;
		adv();
		currentWord.length++;
	}
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */


