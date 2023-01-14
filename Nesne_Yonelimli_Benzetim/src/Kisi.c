#include "Kisi.h"

Kisi new_Kisi(char* adSoyad,double para,float yuzde,int oynadigiSayi){
	Kisi this;
	this=(Kisi)malloc(sizeof(struct KISI));
	
	this->adSoyad=adSoyad;
	this->para=para;
	this->yuzde=yuzde;
	this->oynadigiSayi=oynadigiSayi;
	
	this->oynayabilirMi=&oynayabilirMi;
	
	return this;
}

boolean oynayabilirMi(const Kisi this){ //Oyuncunun oynamaya parasının yetip yetmedigini kontrol eden fonksiyon
	if(this->para>=1000.0){
		return true;
	}
	else{
		return false;
	}
}