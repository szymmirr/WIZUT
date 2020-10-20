#include <8051.h>
#define Czas 65536 - 1000
#define PortAnod P0
#define PortSeg P2
#define Blank 10
unsigned char __code TablicaAnod[] = {0x0E, 0x0D, 0x0B, 0x7};

//uwaga  P0 ma odwrocona kolejnoœæ  - 0 -> klucze tranzystorowe -> 1 Anoda
//0000 1110  	x0E  	set A0
//0000 1101	x0D	set A1
//0000 1011	x0B	set A2
//0000 0111	x07   	set A3

//znak segment h - MSB
//unsigned char __code TablicaZnakow[] = {0xC0, 0x0f9, 0x0a4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

//znak segment a - MSB
unsigned char __code TablicaZnakow[] = {0x03, 0x9f, 0x25, 0x0d, 0x99, 0x49, 0x41, 0x1f, 0x01, 0x09, 0xff};
//MSB abcd efgh LSD  //1 - gasi; 0 - zapala
				
unsigned char Licznik = 0;
//unsigned char Bufor[] = {5,6,7,8};
unsigned char Bufor[4];

unsigned int count=50;	//co ktore przerwanie zmieniaj anode

int main(void)
{
TMOD = 1;
TH0 = Czas/256;
TL0 = Czas%256;
TR0 = 1;
ET0 = 1;
EA = 1;

Bufor[0]=Blank;
//Bufor[1]=4;
//Bufor[2]=3;
//Bufor[3]=2;

while(1);
}

int i=0;
void timer0(void) __interrupt(1) __using(1)
{
TH0 = Czas/256;
TL0 = Czas%256;

if (++count>500)
	{
	PortAnod = TablicaAnod[3];
	//PortSeg = TablicaZnakow[6];
	i++;
	if(i>10) i=1;
		PortAnod = TablicaAnod[3];
		PortSeg = TablicaZnakow[i];
		i++;
	
	//
	//Licznik++;
	//if(++Licznik > 3) Licznik = 1;
	//count=0;
	}
	i=0;
}












