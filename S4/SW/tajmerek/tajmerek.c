#include <8051.h>
#define Czas 65536 - 46080

int main(void)
{
	TMOD = 0x1;
	TR0 = 1;
	P2 = 0;
	while(1)
	{
		P2 = P2 | 1;
		TH0 = Czas/256;
		TL0 = Czas%256;
		while(TF0 == 0);
		TF0 = 0;
		
		P2 = P2 & ~1;
		TH0 = Czas/256;
		TL0 = Czas%256;
		while(TF0 == 0);
		TF0 = 0;
	}
}
