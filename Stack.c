#include <stdio.h>
#include <stdlib.h>
#define boyut 100


struct islemStack{
	int dizi[boyut];
	int x;
}stack;


struct geriStack{
	int dizi2[boyut];
    int silSayaci = 0;
    int ekleSayaci = 0;
}stack2;


int stackDoluMu() { 
   if (stack.x >= boyut - 1) {
      return 1;
  }
   else {
      return 0;
  }
}


int stackBosMu() { 
   if (stack.x == -1)
      return 1;
   else {
      return 0;
  }
}


int ekle(int deger) { 
   stack.x++;
   stack.dizi[stack.x] = deger; 
   return deger;
}


int sil() { 
   int deger;
   deger = stack.dizi[stack.x];
   stack.x--;
   return deger;
}


void yazdir() {
   if(stackBosMu()) {
   	printf("Stack Bos..\n");
   } 
   else {
   	for(int i = stack.x; i >= 0; i-- ) {
   		printf("%d - ", stack.dizi[i]);
	   }
   }
   printf("\n");
}


int main() {
    
	stack2.dizi2[boyut] = stack.dizi[boyut];
    stack.x = -1;
	int islem;
	int i,a;
	
	while(true) {
		printf("Yapmak Istediginiz Islemi Seciniz:\n");
		printf("1-Eleman Ekleme\n2-Son Elemani Silme\n3-Yigini Ekrana Yazdirma\n4-Yapilan Islemi Geri Alma\n5-Cikis\n");
		scanf("%d",&islem);
		    switch(islem) {
			
			case 1: 
			
			printf("EKLE : ");
			scanf("%d", &i);
			if(stackDoluMu()) {
				printf("Stackta Eleman Ekleyecek Yer Yok!!!\n");
			}
			else {
				ekle(i);
				stack2.ekleSayaci++;
			}
			break;
		
			case 2:
		
			if(stackBosMu()) {
				printf("Stack Bos! Silinecek Eleman Yok!!\n");
			}
			else {
				i = sil();
				printf("SILINDI %d\n",i);
				stack2.silSayaci++;
			}
			break;
		
			case 3:
				printf("Ekrana Yazdirildi:  ");
			yazdir();
			
			break;
		
			case 4:
			if(stack2.silSayaci > 0) {
		        
				printf("%d silinmesi geri alindi \n",ekle(i));
			 	}
            
			else if(stack2.ekleSayaci) {
            	a = sil();
            	printf("%d eklemesi geri alindi.\n", a);
			}
			else {
				printf("Henuz Islem Yapilmamistir..\n");
			}
			
			break;
		
			case 5:
			printf("Programdan Cikiliyor...");
			exit(0);
		    default:
	    	printf("Lutfen Gecerli Bir Islem Giriniz!!\n");
		
		}
	}
}
