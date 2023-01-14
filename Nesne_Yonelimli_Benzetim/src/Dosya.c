#include "Dosya.h"

Dosya new_Dosya(){
	Dosya this;
	this=(Dosya)malloc(sizeof(struct DOSYA));
	
	this->kisileriOku=&kisileriOku;
	this->sayilariOku=&sayilariOku;

	return this;
}

void kisileriOku(const Dosya this,FILE* belge){  //Kisileri okuyan ve dizilere atayan fonksiyon
	char metin[100];
	int sayac=0;
	int sayac2=0;
	while (fgets(metin,99,belge)){
		char* satir;
		satir=strtok(metin,"\n");
		while(satir!=NULL){
			satir=strtok(satir,"#");  //# isaretine gore metni parcalayan komut
			while(satir!=NULL){
				int mod=sayac%4;
				if(mod==0){
					int uzunluk=strlen(satir);
					for(int i=0;i<uzunluk;i++){
						this->adSoyadlar[sayac2][i]=satir[i];
					}
				}
				else if(mod==1){
					this->paralar[sayac2]=atof(satir);
				}
				else if(mod==2){
					this->yuzdeler[sayac2]=atof(satir);
				}
				else if(mod==3){
					this->oynananSayilar[sayac2]=atoi(satir);
					sayac2++;
				}
				sayac++;
				free(satir);
				satir=strtok(NULL,"#");
			}
		}
	}
	fclose(belge);
}

void sayilariOku(const Dosya this,FILE* belge){  //Sansli sayilari okuyan ve diziye atayan fonksiyon
	char metin[4];
	this->sayiSayaci=0;
	while(fgets(metin,4,belge)){  //Belgeyi satir satir okuyor
		this->sayilar[this->sayiSayaci]=atoi(metin);
		this->sayiSayaci++;
	}
}