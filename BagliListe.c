#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct liste{  //bağlı listede kullanılacak verileri tanımladık.
	
	char isim[20];
	char soyisim[20];
	int numara;
	struct liste *sonraki;
	
};

  struct liste*son, *ilk, *gecici, *gecici2 = NULL;
 
    
  void ara(struct liste *veri) { //gelecek veriyi kontrol edip bağlı listede yerine yazan fonksiyon
    if(gecici2->sonraki->numara%10==veri->numara%10) //eğer gelen verinin son rakamı bağlı listede varsa bulunduğu düğümün sonuna eklenir.
    {
    			gecici2 = gecici2 -> sonraki;
			   	while(gecici2 -> sonraki!=NULL && gecici2 -> sonraki -> numara%10 == veri -> numara%10){
			   		gecici2 = gecici2 -> sonraki;
				   }
	}

   struct liste*eklenecek=(struct liste*)malloc(sizeof(struct liste)); //araya ekleme işlemi için iki düğüm arasındaki yeri belirledim.
		        eklenecek=gecici2 -> sonraki; //böylece düğüm koparılan yerden araya eleman eklenerek birleştirileb,ilecek
		        gecici2 -> sonraki=veri;
		        veri->sonraki=eklenecek;
      }
  
  

    
	  void ekle( struct liste *veri){ //Gelen veriyi başa ekleyen fonksiyon
  	    
  	    veri->sonraki=ilk;
  	    ilk=veri;
  }
	  ekle2(struct liste *veri){ //eğer gelen veri baştaki veriye eşitse baştaki veriye eklenir.
	  		   gecici2 = ilk;
	   		while(gecici2 -> sonraki!=NULL && gecici2 -> sonraki -> numara %10 == veri-> numara%10){
   			   gecici2 = gecici2->sonraki;
			   }
			   if(gecici2->sonraki==NULL){ 
  	           gecici2 -> sonraki=veri;
		   	   veri -> sonraki=NULL;
                }
			   else{
			   ara(veri); //veriyi listedeki yerine eklemek için.
               }
			  
	  }
    
 
   
	  bul(struct liste *veri){ //gelen verinin yeri bulunur.
	  	
	  		if(ilk->numara%10==veri->numara%10){   // eğer veri ilk elemana eşitse baştakini ekle fonksiyonu ile baştakine eklenir.
	   	
	   	    ekle2(veri);
	   	
	   	
		   }
		   else{
		   	
		   		gecici2 = ilk;
		   	while(gecici2->sonraki!=NULL && gecici2->sonraki->numara%10!=veri->numara%10){
		   		gecici2 = gecici2->sonraki;
			   }
			   if(gecici2->sonraki==NULL){
			   	gecici2 ->sonraki=veri;
			   	veri->sonraki=NULL;
			   }
			   	else{
			   	ara(veri);
				   }
			   }
		   }
	  
	  
	  

    void kontrol(struct liste *veri){ //gelen verinin yeri kontrol edilir
    	
    	if(ilk==NULL){  //eğer bağlı listede eleman yoksa gelen eleman ilk eleman olur.
    		if(ilk==NULL){
  		
  		ilk = veri;
  		son = ilk;

  }
  	else {
  		
  		son->sonraki=veri;
  		son=veri;
	
  }
    	}
		
		else{ // eğer bağıl listede eleman varsa yeni gelen elemanın yeri bulunur.
			
			bul(veri);
    
		}
	}
	
	  void ara2(int x){ //girilen bilgiye göre aranılan kişi ve kaç adımda bulunduğu tespit edilir.
  	  int sayac=1; // bulunma adımını temsil ettiği için sayaç birden başlatılır.
      gecici2 =  ilk;
   	  while(gecici2!=NULL && gecici2->numara!=x){
   		gecici2 = gecici2 -> sonraki;
   		sayac++; 
	   }
	    if(!gecici2 -> numara == x){
		printf("Aradiginiz kisi listede bulunmamaktadir.."); // eğer aranılan kişi listede yoksa listede olmadığı ekrana yazdırılır.
	   	}
	   else {
	   	printf("Aradiginiz kisi %d adimda bulunmustur..",(sayac));
	   }
   	
   }
   
     
   
  void sil1(){ // silinecek eleman ilk eleman ise çalışan fonksiyon
  	
  struct liste*ikinci=NULL;
  ikinci=ilk->sonraki;
  free(ilk);
  ilk=ikinci; //ilk düğümden sonraki düğüm ilk olur.
  }
void sil3(){ //seçilen eleman en sondaysa sondaki düğümü silen fonskiyon. 
	 
 	if(gecici2 -> sonraki == NULL){ //sondan bi önceki düğümün sonrası null işaret eder.
	   	gecici2 = ilk;
   	while(gecici2->sonraki->sonraki!=NULL){
   		gecici2 = gecici2 -> sonraki;
	   }
	   free(gecici2 ->sonraki);
	   gecici2 ->sonraki=NULL;
	   }
   }
   void sil2(int x){ //silinecek eleman arada bir elemansa çalışan fonksiyon
   	
   	if(ilk->numara==x){
   		sil1();
	   }
	   struct liste*onceki=NULL; //silinecek elemanın önceki elemanına önceki, sonraki elemanına sonra ismi verilir.
	   struct liste*sonra=NULL;
	   
	   gecici2 = ilk;
	   while(gecici2 ->sonraki->numara!=x){
	   	gecici2 = gecici2->sonraki;
	   }
	   if(gecici2 ->sonraki==NULL){
	   	sil3();
	   }
	   onceki=gecici2;
	   sonra=gecici2->sonraki->sonraki;
	   free(gecici2->sonraki);
       onceki->sonraki=sonra;
   }
     
   void yazdir(){ //bağlı listeyi ekrana bastıran fonksiyon
	
	gecici=ilk;
	while(gecici->sonraki!=NULL){
		printf("%d %s %s=> ",gecici->numara,gecici->isim,gecici->soyisim);
		gecici=gecici->sonraki;
	}
	printf("%d %s %s=> ",gecici->numara,gecici->isim,gecici->soyisim); // son elemanı ekrana bastırmak için tekrar yazarız.
}
	 
    void sil(int x){ //silinmek istenen elemanın yerini bulup ona göre silen fonksiyon
   	if(ilk->numara==x){   //eğer istenen eleman ilk elemansa baştan silinir.
   	  
   	   sil1();
   	  
   	   yazdir(); //listenin yeni hali ekrana bastırılır.
	   }
	                     
	   
	   sil2(x);
	   
	   
	   if(gecici2->sonraki==NULL){ 
        sil3();  
   }

}
  
int main(){
	
	int sayi1,sayi2;
	FILE *p1= fopen("bagliListe.txt","r+");
	FILE *p2=fopen("dosya2.txt","w+");
    

 while(!feof(p1)){
	  	
	  	struct liste* x=(struct liste*)malloc(sizeof(struct liste)); 
	    x->sonraki=NULL;
	 
	  	fscanf(p1,"%d",&x->numara);
	  	fscanf(p1,"%[ ]s",&x->isim); //dosyada isimden önceki boşluk okunur.
	  	fscanf(p1,"%s",&x->isim); 
	  	fscanf(p1,"%[ ]s",&x->soyisim);
	  	fscanf(p1,"%s",&x->soyisim);


	  
	  	kontrol(x);
	  	
	  } 
	  	printf("\n");
	    yazdir();
	    printf ("\n");
	  while(true) {
	  	printf("\n");
	  	printf("*****Yapmak Istediginiz Islemi Seciniz:*****\n");
	  	printf("1-Eleman Ekleme\n");
	  	printf("2-Eleman Arama\n");
	  	printf("3-Liste Goruntuleme\n");
	  	printf("4-Eleman Silme\n");
	  	printf("5-Cikis\n");
	  	int islem;
	  	scanf("%d", &islem);
	  	
  	 if(islem == 1) { //Eleman Ekleme
	   struct liste* x=(struct liste*)malloc(sizeof(struct liste)); //yeni gelecek eleman için bellekten yer ayrılır.
	   x->sonraki=NULL;
       printf("\n\nekleyeceginiz kisinin bilgilerini giriniz:\n");
       printf("Numara:");
       scanf("%d", &x->numara);
       printf("Isim : ");
       scanf("%s", x -> isim);
       printf("Soyisim : ");
       scanf("%s", x -> soyisim);
       printf("\n\n");
       kontrol(x);
       yazdir();
   
   	        
			gecici2=ilk;
            while(gecici2 ->sonraki!=NULL){
	    	fprintf(p2,"%d  %s  %s\n",gecici2->numara,gecici2->isim,gecici2->soyisim);
	        gecici2 = gecici2->sonraki;
	}
	       fprintf(p2,"%d  %s  %s\n",gecici2 -> numara, gecici2 -> isim, gecici2->soyisim);
	 
		  }
		  
		   else if(islem == 2) { //Eleman Arama
		   printf("\nArayacaginiz kisinin numarasini giriniz:");
           scanf("%d",&sayi1);
           ara2(sayi1);
		   }
		  
		   else if(islem == 3) { //Listede Görüntüleme
		   yazdir();
	       }
	       
	       else if(islem == 4) { //Eleman Silme
	       printf("Silinecek kisinin numarasini giriniz:");
           scanf("%d",&sayi2);
           sil(sayi2);
           yazdir();
	  	
	  }
	  else if(islem == 5) {
	  	printf("Programdan Cikiliyor.......");
	  	break;
	  }
	  else {
	  	printf("Lutfen Gecerli Bir islem Giriniz....");
	  	break;
	  	
	  }
	  printf("\n");
}
	 
	 return 0;
}
