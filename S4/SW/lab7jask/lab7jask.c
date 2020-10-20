#include <8051.h>
#define but1 P3_0
#define but2 P3_1
#define led P2
#define up 10
#define down 1
#define Czas 65536-46080

unsigned char licznik=1;
unsigned char zliczanie_1sek;
unsigned char KoniecImp = 5;
unsigned int i;

int main(void){
TMOD = 0x11;
led=0;

TL0=Czas%256;
TH0=Czas/256;
TR0=1;
zliczanie_1sek=0;

IE = 0b10000010;

ET0 = 1;
EA = 1;

while(1){
	while(but1 && but2);
	for(i=0;i<500;i++); //zwloka na drgania
	if(but1){
		if(KoniecImp < up)KoniecImp++;
	}
	else{
		if(KoniecImp > down)KoniecImp--;
	}
	
	while(!but1 || !but2);
	
	for(i=0;i<500;i++);
}
}
void IntTIM0() __interrupt(1) __using(2){
	TL0 = Czas % 256;
	TH0 = Czas / 256;
	
	zliczanie_1sek++;
	
	if(zliczanie_1sek >= KoniecImp){
		if(P2 == 1){
			P2 = 0;
		}
		else{
			P2 = 1;
		}
		zliczanie_1sek = 0;
	}
}
