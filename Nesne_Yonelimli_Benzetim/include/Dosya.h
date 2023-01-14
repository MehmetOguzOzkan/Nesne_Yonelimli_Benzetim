#ifndef DOSYA_H
#define DOSYA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct DOSYA{
	char adSoyadlar[100000][100]; //Okudugumuz ad soyad bilgilerini tutacak dizi
	double paralar[100000]; //Okudugumuz para bilgilerini tutacak dizi
	float yuzdeler[100000]; //Okudugumuz yuzde bilgilerini tutacak dizi
	int oynananSayilar[100000]; //Okudugumuz oynanan sayi bilgilerini tutacak dizi
	
	int sayilar[10000]; //Okudugumuz sansli sayilari tutacak dizi
	int sayiSayaci; //Kac adet sansli sayi oldugunu tatan integer
	
	void (*kisileriOku)(struct DOSYA*,FILE*);
	void (*sayilariOku)(struct DOSYA*,FILE*);
};

typedef struct DOSYA* Dosya;
Dosya new_Dosya();
void kisileriOku(const Dosya,FILE*);
void sayilariOku(const Dosya,FILE*);

#endif