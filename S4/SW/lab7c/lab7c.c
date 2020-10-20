#include <8051.h>
#define StykP1 P1_3
#define StykP2 P1_4
#define PortLED P2

#define Czas 65536 - 5000
unsigned char Licznik = 0;

void CzasZwloki(unsigned int Ilosc)
{
TL0 = (65536 - Ilosc) % 256;
TH0 = (65536 - Ilosc) / 256;
TF0 = 0;
TR0 = 1;
while(!TF0);
TR0 = 0;
}

int main(void)
{
PortLED = 0;
while(1)
{
	while(StykP1 && StykP2);
	CzasZwloki(9600);
	if(StykP1)
	{
		CzasZwloki(9600);
		Licznik++;
	}
	else if(StykP2)
	{
		CzasZwloki(9600);
		Licznik--;
	}
	
	PortLED = Licznik;
	while(!StykP1 || !StykP2);
	CzasZwloki(9600);
}
}