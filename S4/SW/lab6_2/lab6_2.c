#include <8051.h>
#define Czas 0x4c00
unsigned char Licznik = 0;

int main(void)
{
P2=0;
TMOD=1;
TH0=Czas/256;
TL0=Czas%256;
TR0 = 1;
ET0 = 1;
EA = 1;

while(1);
}

void timer0(void) __interrupt(1) __using(1)
{
TH0 = Czas/256;
TL0 = Czas%256;

Licznik++;

if(Licznik > 63) Licznik = 0;
P2=Licznik;
}