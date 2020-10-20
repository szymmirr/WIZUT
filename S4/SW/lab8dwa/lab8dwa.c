#include <8051.h>
#define StykP1 P3_2
#define StykP2 P3_3
#define PortLED P2
#define Czas 65536 - 46080
unsigned char Licznik = 1;
unsigned char Zliczanie_1sek;
unsigned char KoniecImp=5;
unsigned int i;

int main(void)
{
TMOD=0x01;
PortLED=255;
TL0 = Czas % 256;
TH0 = Czas / 256;
TR0 = 1;
Zliczanie_1sek=0;
ET0 = 1;
EA = 1;
EX0 = 1;
EX1 = 1;


while(1)
{
	
}
}

void IntTIM0(void) __interrupt(1) __using(2)
{
TL0 = Czas % 256;
TH0 = Czas / 256;

Zliczanie_1sek++;
if(Zliczanie_1sek==20)
	{
		P2=1;
		Zliczanie_1sek=0;
	}
if(Zliczanie_1sek >= KoniecImp)
	{
		P2=0;
	}
}

void IntINT0(void) __interrupt(0) __using(2)
{
	(P3_2)=!(P3_2);
	for(i = 0; i<15000;i++);
	(P3_2)=!(P3_2);
	PortLED=16;
}

void IntINT1(void) __interrupt(2) __using(2)
{
	(P3_3)=!(P3_3);
	for(i = 0; i<15000;i++);
	(P3_3)=!(P3_3);
	PortLED = 8;
}
