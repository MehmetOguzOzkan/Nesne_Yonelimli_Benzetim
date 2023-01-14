#include "Oyun.h"

Oyun new_Oyun(Dosya dosya){
	Oyun this;
	this=(Oyun)malloc(sizeof(struct OYUN));

	this->dosya=dosya;

	this->oyunculariTanimla=&oyunculariTanimla;
	this->oyna=&oyna;
	this->yazdir=&yazdir;
	this->kazan=&kazan;
	this->kaybet=&kaybet;
	this->enZengin=&enZengin;
	this->kalanKisiSayisi=&kalanKisiSayisi;
		
	return this;
}

void oyunculariTanimla(const Oyun this) //Oyunculari olusturan fonksiyon
{
	this->masa=0.00;
	int a=0;
	while(this->dosya->adSoyadlar[a][0]!=0){
		this->kisiler[a]=new_Kisi(this->dosya->adSoyadlar[a],this->dosya->paralar[a],this->dosya->yuzdeler[a],this->dosya->oynananSayilar[a]);
		a++;
	}
}

void oyna(const Oyun this){ //Oyunu oynattiran ana fonksiyon
	int m=this->kalanKisiSayisi(this); //Kalan kisi sayisi degiskene atandi
	int a=0;
	while(m>0 && a<this->dosya->sayiSayaci){ //Dosyadaki sayilar bittiginde veya oyunda kimse kalamadiğinda oyunu bitiren  dongu
		int i=0;
		while(this->dosya->adSoyadlar[i][0]!=0){
			if(this->kisiler[i]->oynayabilirMi(this->kisiler[i])){
				if(this->dosya->sayilar[a]==this->kisiler[i]->oynadigiSayi){
					this->kazan(this,i);
				}
				else{
					this->kaybet(this,i);
				}
			}
			i++;
		}
		a++;
		m=this->kalanKisiSayisi(this);
		this->tur=a; //Kacinci tur oldugu tutuldu
		this->yazdir(this);
	}
}

void yazdir(const Oyun this){ //Erkana verilecek yaziyi düzenleyen fonksiyon
	system("CLS");
	printf("########################################\n");
	printf("##           SANSLI SAYI = %-2d         ##\n",this->dosya->sayilar[this->tur]);
	printf("########################################\n");
	printf("########################################\n");
	printf("##              TUR = %-3d             ##\n",this->tur);
	printf("##     MASA BAKIYE = %-12.2f     ##\n",this->masa);
	printf("##                                    ##\n");
	printf("##------------------------------------##\n");
	this->enZengin(this);
	if(this->kisiler[this->enZenginSira]->oynayabilirMi(this->kisiler[this->enZenginSira])&&this->tur<this->dosya->sayiSayaci){ //Oyun bitmediyse
		printf("##            EN ZENGIN KISI          ##\n");
		printf("##            %-20s    ##\n",this->kisiler[this->enZenginSira]->adSoyad);
		printf("##   BAKIYE = %-12.2f            ##\n",this->kisiler[this->enZenginSira]->para);
		printf("##                                    ##\n");
		printf("########################################\n");
	}
	else{ //Oyun bitmisse
		system("CLS");
		printf("########################################\n");
		printf("##              TUR = %-3d             ##\n",this->tur);
		printf("##     MASA BAKIYE = %-12.2f     ##\n",this->masa);
		printf("##                                    ##\n");
		printf("##------------------------------------##\n");
		printf("##            OYUN BITTI!             ##\n");
		printf("##                                    ##\n");
		printf("##                                    ##\n");
		printf("########################################\n");
	}
}

void kazan(const Oyun this,int i){ //Sansli sayiyi tutturanın parasını ve masayı guncelleyen fonksiyon
	double yatirdigiPara=(this->kisiler[i]->para)*(this->kisiler[i]->yuzde);
	this->kisiler[i]->para=this->kisiler[i]->para+(9.00*yatirdigiPara);
	this->masa=this->masa-(9.00*yatirdigiPara);
}
void kaybet(const Oyun this,int i){ //Sansli sayiyi tutturamayanin parasinin ve masayi guncelleyen fonksiyon
	double yatirdigiPara=(this->kisiler[i]->para)*(this->kisiler[i]->yuzde);
	this->kisiler[i]->para=(this->kisiler[i]->para)-(yatirdigiPara);
	this->masa=this->masa+(yatirdigiPara);
}

void enZengin(const Oyun this){ //En zengin kisiyi bulan fonksiyon
	int a=0;
	int enZengin=0;
	while(this->dosya->adSoyadlar[a][0]!=0){
		if(this->kisiler[a]->para>this->kisiler[enZengin]->para){
			enZengin=a;
		}
		a++;
	}
	this->enZenginSira=enZengin;
}

int kalanKisiSayisi(const Oyun this){ //Kalan kisi sayisini bulan fonksiyon
	int kalanKisi=0;
	int a=0;
	while(this->dosya->adSoyadlar[a][0]!=0){
		if(this->kisiler[a]->oynayabilirMi(this->kisiler[a])){
			kalanKisi++;
		}
		a++;
	}
	return kalanKisi;
}