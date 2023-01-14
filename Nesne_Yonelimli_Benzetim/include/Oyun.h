#ifndef OYUN_H
#define OYUN_H

#include "Kisi.h"
#include "Dosya.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct OYUN{
	
	double masa;
	int tur;
	int enZenginSira;

	Kisi kisiler[100000]; //Kisi sinifindan olusturulan nesne dizisi
	Dosya dosya; //Dosya sinifindna olusturulan nesne

	void (*oyunculariTanimla)(struct OYUN*);
	void (*oyna)(struct OYUN*);
	void (*yazdir)(struct OYUN*);
	void (*kazan)(struct OYUN*,int);
	void (*kaybet)(struct OYUN*,int);
	void (*enZengin)(struct OYUN*);
	int (*kalanKisiSayisi)(struct OYUN*);
};

typedef struct OYUN* Oyun;
Oyun new_Oyun();
void oyunculariTanimla(const Oyun);
void oyna(const Oyun);
void yazdir(const Oyun);
void kazan(const Oyun,int);
void kaybet(const Oyun,int);
void enZengin(const Oyun);
int kalanKisiSayisi(const Oyun);

#endif