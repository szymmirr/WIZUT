#include <8051.h>

void Czas(unsigned int Ilosc);

int main(void)
{
while(1)
{
	P2 = 0;
	Czas(10000);
	P2 = 1;
	Czas(10000);
}
}

void Czas(unsigned int Ilosc)
{
	unsigned int i;
	for(i = 0; i < Ilosc; i++);
}
