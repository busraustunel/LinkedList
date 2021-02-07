//181213042 BÜÞRA ÜSTÜNEL

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct liste{
int musteri_no;
char ad[20],soyad[20];
}Musteri;

Musteri *veri_liste[10];
int hash_tablo[10][2];


int HASH(int no)
{
	int hash_index;
	hash_index = no % 10;
	return hash_index;
}

//1)EKLEME ÝÞLEMÝ
veriEkleme(int no, char ad[20], char soyad[20]){
	int hash_index = HASH(no);
	if(hash_tablo[hash_index][0] == -1){
		hash_tablo[hash_index][0] = no;
		veri_liste[hash_index] -> musteri_no = no;
		strcpy(veri_liste[hash_index] -> ad,ad);
		strcpy(veri_liste[hash_index] -> soyad,soyad);
		
	}
	else{
		int i = 0, kontrol = -1;
		while(i < 10 && hash_tablo[i][0] != -1){
			if(HASH(hash_tablo[i][0]) ==hash_index && hash_tablo[i][1] == -1 ){
				hash_index = i;
			}
			if(hash_tablo[i][0] == -1){
				kontrol = 1;
			}
			i++;
		}
		if(hash_tablo[i][0] == -1 && i < 10) {
				kontrol = 1;
			}
		if(kontrol == -1) {
			printf("Tablo Dolu!\n");
			return 0;
		}
		hash_tablo[hash_index][1] = i;
		hash_tablo[i][0] = no;
		veri_liste[i] -> musteri_no = no;
		strcpy(veri_liste[i] -> ad,ad);
		strcpy(veri_liste[i] -> soyad,soyad);
	}
}

int adim_sayisi = 0;
//2)ARAMA ÝÞLEMÝ
int veriArama(int musteri_no, int indis){
	adim_sayisi++;
	if(hash_tablo[indis][0]==musteri_no){
		printf("%d %s %s\n",veri_liste[indis]->musteri_no, veri_liste[indis]->ad, veri_liste[indis]->soyad);
		printf("Veri %d adimda bulundu.\n",adim_sayisi);
		return adim_sayisi;
	}		
	if(hash_tablo[indis][1]==-1){
		printf("Veri Bulunamadi\n");
		return -1;
	}
		
	veriArama(musteri_no, hash_tablo[indis][1]);
	return adim_sayisi;	
}


//3)SÝLME ÝÞLEMÝ
veriSilme(int musteri_no, int indis){
	
	adim_sayisi++;
	if(hash_tablo[indis][0] == musteri_no){
		hash_tablo[indis][0] == -1;
		printf("Silindi.\n");
		return 0;
	}		
	if(hash_tablo[indis][1] == -1){
		printf("Bulunamadi\n");
		return -1;
	}
		
	veriSilme(musteri_no, hash_tablo[indis][1]);
	return 0;	
}

//4)HASH TABLOSU LÝSTELEME
hashTablosuListele(){
	
	for(int i=0;i<10;i++){
		printf("%5d  %2d \n",hash_tablo[i][0],hash_tablo[i][1]);
	}
}

//5)VERÝ LÝSTESÝ LÝSTELEME
veriListesiListele(){
	for(int i=0;i<10;i++){
		if(hash_tablo[i][0]!=-1){
			printf("%5d %8s %8s\n",veri_liste[i]->musteri_no,veri_liste[i]->ad, veri_liste[i]->soyad);
		}
	}
}

//6)ORTALAMA ADIM SAYISI
ortalamaAdimHesapla(){
    int eleman_sayisi = 0;
	int adimSayisi = 0;
	float ortalama = 0;
	for(int i=0;i<10;i++){
		if(hash_tablo[i][0]!=-1){
			eleman_sayisi++;
			adim_sayisi=0;
			adimSayisi += veriArama(hash_tablo[i][0],HASH(hash_tablo[i][0]));
		
		}
	}
	ortalama = adimSayisi/eleman_sayisi;
	printf("ortalama adim sayisi= %f\n",ortalama);
}


//ANA MENÜ
void menu() {
	char ad[20], soyad[20];
	int secim = 0;
	int musteri_no;

	while(secim != -1){
		printf("-----------------------------------------------------------\n");
		printf("1)Ekleme\n2)Arama\n3)Silme\n4)Hash Tablosu Listeleme\n5)Veri Listesini Listeleme\n6)Ortalama Adim Sayisi\n(Cikis Icin -1'e Basiniz.)\n");
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("Musteri No:");
				scanf("%d",&musteri_no);
				printf("Ad:");
				scanf("%s",&ad);
				printf("Soyad:");
				scanf("%s",&soyad);
				veriEkleme(musteri_no,ad,soyad);
				printf("Kisi Eklendi.\n");
				break;
			
			case 2: 
				
				printf("Musteri No:");
				scanf("%d",&musteri_no);
				veriArama(musteri_no,HASH(musteri_no));
				break;
		
			case 3:
				printf("Musteri No:");
				scanf("%d",&musteri_no);
				veriSilme(musteri_no,HASH(musteri_no));
				break;
			case 4:
				printf("HASH TABLOSU\n");
				printf("-----------------------------------------------------------\n");
				hashTablosuListele();
				break;		
			case 5:
				printf("VERI LISTESI\n");
				printf("-----------------------------------------------------------\n");
				veriListesiListele();
				break;
			case 6:
				ortalamaAdimHesapla();
			
		}
		
}
            printf("Programdan Cikiliyor...");
}
int main(){
	
	FILE *fp;
	int no;
	char ad[20], soyad[20];
	for(int i=0;i<10;i++){
		for(int j=0;j<2;j++){
			hash_tablo[i][j]=-1;
			veri_liste[i]=(struct liste*)malloc(sizeof(liste));
		}
	}
	    
    
    	if ((fp=fopen("veri.txt","r"))!= NULL){
		while (!feof(fp)){
		
  	    	fscanf(fp,"%d  %s  %s ",&no,&ad,&soyad);
  	        veriEkleme(no,ad,soyad);
  	    }
  	
	}
	    menu();
	
}
