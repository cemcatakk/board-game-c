#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Oyuncu{
	char ad[20];
	int tahta[2][20];	
};
int Hamle1(struct Oyuncu hamleyapan,int tas,int renk){
	if(tas*2>20){
		return -1;
	}
	if(tas<0)return -1;
	if(hamleyapan.tahta[renk][tas*2]>0){
		return 1;
	}
	else return -1;
}
int Hamle2(struct Oyuncu hamleyapan,int tas,int renk){
	if(tas-4<0)return -1;
	if(renk==1){
		if(hamleyapan.tahta[renk-1][tas-4]>0)return 1;
		else return -1;
	}
	else{
		if(hamleyapan.tahta[renk+1][tas-4]>0)return 1;
		else return -1;
	}
}
void oyuncuYazdir(struct Oyuncu oyuncu){
	printf("%s\n",oyuncu.ad);
	int i;
	printf("Mavi: ");
	for(i=0;i<20;i++){
		printf("%d ",oyuncu.tahta[0][i]);
	}
	printf("\n");
	printf("Kirmizi: ");
	for(i=0;i<20;i++){
		printf("%d ",oyuncu.tahta[0][i]);
	}
	printf("\n");
}
int main(){
	srand(time(NULL));
	struct Oyuncu oyuncu1={"Oyuncu 1"
	};
	struct Oyuncu oyuncu2={"Oyuncu 2"
	};
	int sayac=0;
	for(sayac=0;sayac<20;sayac++){
		oyuncu1.tahta[0][sayac]=1;
		oyuncu1.tahta[1][sayac]=1;
		oyuncu2.tahta[0][sayac]=1;
		oyuncu2.tahta[1][sayac]=1;
	}
	int tas = rand()%10;
	int oyuncu = rand()%2;
	int renk = rand()%2;
	int hamleSayisi=0;
	while(1){
		hamleSayisi++;
		if(oyuncu==0){
			if((Hamle1(oyuncu1,tas,renk)==1)&&(Hamle2(oyuncu1,tas,renk)==1)){
				int rastgele = rand()%2;
				if(rastgele==0){
					tas=tas*2;
				}
				else{
					tas=tas-4;
					if(renk==0)renk=1;
					else renk=0;
				}
			}
			else if(Hamle1(oyuncu1,tas,renk)==1){
				tas=tas*2;
			}
			else if(Hamle2(oyuncu1,tas,renk)==1){
				tas=tas-4;
				if(renk==0)renk=1;
				else renk=0;
			}
			else{
				printf("Oyuncu 2 kazandi!");
				break;
			}
			printf("Oyuncu 1 Hamlesi: ");
			if(renk==0)printf("Mavi %d\n",tas);
			else printf("Kirmizi %d\n",tas);
			oyuncu1.tahta[renk][tas]--;
			oyuncu2.tahta[renk][tas]++;
		}
		else{
			if((Hamle1(oyuncu2,tas,renk)==1)&&(Hamle2(oyuncu2,tas,renk)==1)){
				int rastgele = rand()%2;
				if(rastgele==0){
					tas=tas*2;
				}
				else{
					tas=tas-4;
					if(renk==0)renk=1;
					else renk=0;
				}
			}
			else if(Hamle1(oyuncu2,tas,renk)==1){
				tas=tas*2;
			}
			else if(Hamle2(oyuncu2,tas,renk)==1){
				tas=tas-4;
				if(renk==0)renk=1;
				else renk=0;
			}
			else{
				printf("Oyuncu 1 kazandi!");
				break;
			}
			printf("Oyuncu 2 Hamlesi: ");
			if(renk==0)printf("Mavi %d\n",tas);
			else printf("Kirmizi %d\n",tas);
			oyuncu2.tahta[renk][tas]--;
			oyuncu1.tahta[renk][tas]++;
		}
		oyuncuYazdir(oyuncu1);
		printf("\n");
		oyuncuYazdir(oyuncu2);
		printf("\n");
		if(tas==0)tas++;
		
	}
	printf("\nToplam hamle sayisi: %d\n",hamleSayisi);
	getch();
}
