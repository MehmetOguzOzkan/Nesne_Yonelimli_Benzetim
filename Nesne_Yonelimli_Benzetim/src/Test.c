#include <conio.h>
#include "Kisi.h"
#include "Dosya.h"
#include "Oyun.h"

int main(){
	Dosya dosya1=new_Dosya();
	FILE* belge1=fopen(".//doc//Kisiler.txt","r");
	FILE* belge2=fopen(".//doc//Sayilar.txt","r");
	dosya1->kisileriOku(dosya1,belge1);
	dosya1->sayilariOku(dosya1,belge2);
	Oyun oyun1=new_Oyun(dosya1);
	oyun1->oyunculariTanimla(oyun1);
	oyun1->oyna(oyun1);	
	getch();
}