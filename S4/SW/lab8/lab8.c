#include<8051.h>
#define CZAS_50ms 65336 - 46080

#define PortLED P2

unsigned char Licznik = 0;
int i = 0;

int main(void)
{
	P2 = 255;
	TMOD = 1;
	TH0 = CZAS_50ms / 256;
	TL0 = CZAS_50ms % 256;
	TR0 = 1; ET0 = 1; EA = 1;
	EX0 = 1; EX1 = 1;
while(1);
}

void timer0(void) __interrupt(1)
{
	TH0 = CZAS_50ms / 256;
	TL0 = CZAS_50ms % 256;
	i++;
	if(i == 10)
	{
		if(P2 == 255) P2 = 254; else P2 = 255;
	}
	else if (i > 10) i = 0;
}

void button5(void) __interrupt(0)
{
	P2 = 250;
}

void button6(void) __interrupt(2)
{
	P2 = 240;
}
