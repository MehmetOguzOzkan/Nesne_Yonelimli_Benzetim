#ifndef KISI_H
#define KISI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } boolean; //Boolean veri tipi oluşturuldu

struct KISI{
	char* adSoyad;
	double para;
	float yuzde;
	int oynadigiSayi;
	
	boolean (*oynayabilirMi)(struct KISI*);
};

typedef struct KISI* Kisi;
Kisi new_Kisi(char*,double,float,int);
boolean oynayabilirMi(const Kisi);

#endif