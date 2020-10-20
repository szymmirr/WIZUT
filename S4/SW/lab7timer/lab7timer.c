#include <8051.h>
#define StykP1 P3_0
#define StykP2 P3_1
#define PortLED P2
#define Gora 10
#define Dool 1
#define Czas 65536 - 46080
unsigned char Licznik = 1;
unsigned char Zliczanie_1sek;
unsigned char KoniecImp=5;
unsigned int i;

int main(void)
{
TMOD=0x11;
PortLED=0;
TL0 = Czas % 256;
TH0 = Czas / 256;
TR0 = 1;
Zliczanie_1sek=0;
ET0 = 1;
EA = 1;

while(1)
{
	while(StykP1 && StykP2);
		for(i=1;i<5000;i++);
			if(StykP1)
			{
				if(KoniecImp < Gora)Licznik++;
			}
			else
			{
				if(KoniecImp > Dool)Licznik--;
			}
			while(!StykP1 || !StykP2);
			for(i=0;i<5000;i++);
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
if(Zliczanie_1sek >= Licznik)
	{
		P2=0;
	}
	
}