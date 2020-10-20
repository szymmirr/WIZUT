#include <8051.h>
#define PortLED P2
#define czas50 65536-46080

int main(void)
{
unsigned int i=1;
unsigned char licznik=0;

PortLED=0;

TMOD=0b00010000;
TR1=1;
TH1=czas50/256;
TH1=czas50%256;

PortLED ^=1;
while(1)
{
	
	if(PortLED>=1)
	{
	/*while(TF1==0);
		if(++licznik>128)
		{
			PortLED ^=i;
			licznik=0;
		}*/
	
	PortLED<<1;
	PortLED==PortLED;
	}
	//PortLED ^=16;
	TF1=0;
	TH1=czas50/256;
	TH1=czas50%256;
}
}