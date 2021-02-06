#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<conio.h>

typedef struct bilgi{
char ad[20];
int oncelikID;
struct bilgi *next;
} Bilgiler;
Bilgiler *head=NULL,*tail=NULL,*temp,*newPerson,*person;

char name[100][100];
int oncelikID[100000];


Bilgiler *dugum(char ad[], int oncelikID) {
      return newPerson;
 }

void kackisivar(char ad[20]){
	int kontrol = 0;
    if(head == NULL) {
    	printf("Kuyrukta Eleman Bulunamad�!");
        return;
    }
    int i=0;
    temp = head;
    while(temp!= NULL) {
         
        if(strcmp(ad,temp->ad)==0){
        	printf("%s Isimli Kisinin Onunde %d Kisi Bulunmaktadir.\n",temp->ad, i);
        	kontrol=1;
		}
        temp = temp->next;
        i++;
}
    if(kontrol ==0 ){
    	printf("Kuyrukta Bu Isimde Biri Bulunamadi\n");
	}
}
void siraliekle(int oncelikID,char ad[20]){
	person = (Bilgiler*)malloc(sizeof(Bilgiler));
    strcpy(person->ad,ad);
    
     person->oncelikID = oncelikID;
     person->next = NULL;

	 if(head==NULL) {
     head = person;
     tail = person;
     return;
    }
    else if(person->oncelikID<head->oncelikID){
    	person->next=head;
    	head=person;
    	return;
	}
	temp=head;
	while(temp->next!=NULL && temp->next->oncelikID<=person->oncelikID){
		temp=temp->next;
	}
	if(temp->next==NULL){
		temp->next=person;
		tail=person;
	}
	else{
		person->next=temp->next;
		temp->next=person;
	}
	
}

void yazdir() {
    int i = 1;
    if(head == NULL) {
        return;
    }
    temp = head;
    while(temp->next != NULL){
    printf("%d %s\n",temp->oncelikID,temp->ad);
    temp = temp->next;
    i++;
 }
    printf("%d %s\n",temp->oncelikID,temp->ad);
}
void menu() {
    int secim;
    int oncelik;
    char isim[20];
    
    while( 1 == 1 ) {
    	
        printf("1- Kuyruktaki Kisileri Listelemek Icin Basiniz.\n");
		printf("2- Kisinin Onunde Kac Kisi Oldugunu Ogrenmek Icin Basiniz.\n");
        printf("3- Kuyruga Ekleme Yapmak Icin Basiniz.\n");
        scanf("%d", &secim);
   
    switch(secim)  {
        case 1:
            yazdir();
            break;
        case 2:
        	printf("Onunde Kac Kisi Oldugunu Bulmak Istediginiz Kisinin Ismini Giriniz:(KUCUK BUYUK HARF DUYARLIDIR!)");
        	scanf("%s", &isim);
        	kackisivar(isim);
            break;
        case 3:
		    printf("Isim Giriniz:");
            scanf("%s",&isim);
		    printf("Oncelik Durumunu Giriniz:(0 en oncelikli kayittir.)");
            scanf("%d", &oncelik);
            siraliekle(oncelik,isim);
            yazdir();
            break;
        default: 
            printf("Lutfen Gecerli Bir Islem Giriniz!!");
            break;
        }
        printf("\n");
    }
}

int main() {
            FILE *f1;
            f1 = fopen("dosya.txt","a+");
            
			int i = 0;
            while(!feof(f1))
            {
                fscanf(f1,"%d %s",&oncelikID[i],&name[i]);
                siraliekle(oncelikID[i],name[i]);
                i++;
            }
           
    menu();
    return 0;
}
