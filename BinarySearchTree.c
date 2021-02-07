

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct dugum {
    int sayi; 
    struct dugum *sol; 
    struct dugum *sag; 
};

dugum *bas = NULL;


// 1) ELEMAN EKLEME
dugum* olustur(int deger) {
    dugum *gecici;
    gecici =  (struct dugum*)malloc(sizeof(dugum));
    gecici -> sag = NULL;
    gecici -> sol = NULL;
    gecici -> sayi = deger;
    return gecici;
}
dugum* ekle(dugum *iter, int deger) {
    
    if(iter == NULL){
    	return olustur(deger);
	}     
    else if(deger <= iter -> sayi){
    	iter -> sol = ekle(iter -> sol, deger);
	}       
    else {
    	iter -> sag = ekle(iter -> sag, deger);
   	}
    return iter;
}

int seviye = -1;
int adim = 0;
int ortalamaToplam = 0;
int sayac = 0;


// 2) GIRILEN SEVIYEYI LISTELEME
void listele(dugum *iter) {
    if(iter != NULL)  {
        listele(iter -> sol); 
        printf("%d", iter -> sayi); 
        listele(iter->sag);
    }
}
void seviyeListele(dugum *iter, int yukseklik) {  
    int kontrol = 0;
    if(iter != NULL) {	
    	++seviye;
        seviyeListele(iter -> sol, yukseklik);
		--seviye;
		if(yukseklik == seviye){
			printf("%d - ", iter -> sayi);
		}
		kontrol = 1;
		++seviye;
        seviyeListele(iter->sag,yukseklik);
        --seviye;
    }
}




// 3) ELEMAN ARAMA
dugum* ara( dugum *iter, int deger) {
    
	if(iter == NULL || iter -> sayi == deger) {
        return iter;
    }
    else if(deger > iter -> sayi){
    	adim++;
    	return ara(iter -> sag, deger);
	}
    else{
    	adim++;
    	return ara(iter -> sol,deger);
	}
}


//4) YAPRAK DUGUM ORTALAMASI HESAPLAMA
ortalamaHesapla(dugum *iter){
	
	 if(iter != NULL)  {
    	if(iter -> sag == NULL && iter -> sol == NULL){
    		ortalamaToplam += iter -> sayi;
    		sayac++;
		}
        ortalamaHesapla(iter -> sol);     
        ortalamaHesapla(iter -> sag);
        
    }
    
}


// 5) BUYUK ELEMAN LISTELEME
buyukListele(dugum *iter,int deger){
	
	if(iter != NULL) {
        buyukListele(iter -> sol, deger); 
        if(iter -> sayi > deger){
		printf(" %d -", iter->sayi); 
	}  
        buyukListele(iter -> sag, deger);
    }
}


void menu() {
	    dugum *sonuc= NULL;
     	int secim, deger, yukseklik;
		while(true){
		printf("\n1)EKLEME\n2)SEVIYE LISTELEME\n3)ARAMA\n4)YAPRAK DUGUM ORTALAMASI\n5)BUYUK ELEMANLARI LISTELEME\n(CIKIS ICIN -1'E BASINIZ.)\n");
		scanf("%d", &secim);
		switch(secim){
			case 1:
				printf("Eklemek Istediginiz Degeri Girin: ");
				scanf("%d",&deger);
				if(bas == NULL){
				bas = ekle(bas, deger);
				}
				else{
					ekle(bas, deger);
				}
				break;
			case 2:
				printf("Listelemek Istediginiz Seviye: ");
				scanf("%d",&yukseklik);
				seviyeListele(bas, yukseklik-1);	
				break;
			case 3: 
				printf("Aranacak Olan Eleman: ");
				scanf("%d",&deger);
				sonuc=ara(bas,deger);
				if(sonuc!=NULL){
					printf("%d elemani %d adimda bulundu\n",deger,adim+1);
				}
				else{
					printf("%d Elemani Bulunamadi\n",deger);
				}
				adim=0;
				break;
			case 4:
				 ortalamaHesapla(bas);
				 printf("Yaprak Dugumlerin Ortalamasi: %d\n",ortalamaToplam/sayac);
				 sayac = 0;
				break;
			case 5:
				printf("Degeri Girin:");
				scanf("%d",&deger);
				buyukListele(bas,deger);
				break;
			case -1: 
				printf("Programdan Cikiliyor...");
				exit(0);
				break;
			default:
				printf("Lutfen Gecerli Bir Islem Giriniz..\n");
				break;
			}
       }
}

int main(){
      menu();
      return 0;
}
