#include <8051.h>
//#define Czas 65536 -808
#define krok 515//liczba kroków na obrót
//unsigned char TablSiln[] = {1, 2, 4, 8}; //falowy
unsigned char TablSiln[]={3,6,12,9};//krokowy
//unsigned char TablSiln[] = {9,1,3,2,6,4,12,8};//polkrokowy
char i;
unsigned int a =0;
int liczba =1;
int lobrotow =1;
char rozm=0;//rozmiar TablSiln
void Delay(int Ile)
{
for(a =0;a <Ile;++a);//opoznienie pomiedzy krokami
}
void Obrot(int kat, int lr, char TabSiln[])
{
if(lr=1)//prawo
{
for(i =rozm-1;i >=0;i--)
{
for(a =0;a <kat;++a);
P0 =TablSiln[i];
a++;
}
Delay(100);
}

if(lr=0)//lewo
{
for( i = 0; i < 4; i+=2)
{
for(a =0;a <kat;++a);
P0 =TablSiln[i];
a++;
}
Delay(100);
}
}
int main(void)
{
rozm=sizeof(TablSiln);//rozmiar tablicy 
//(praca pólkrokowa->8 lub falowa->4)
P2=rozm;//wyswietl;
while(1)
{
//for( i = 0; i < 4; i+=2)//wykonaj sekwencje (LEWO)
for(i =rozm-1;i >=0;i--)//wykonaj sekwencje (PRAWO)
{
for(a =0;a <500;++a);
P0 =TablSiln[i];
a++;
}
Delay(100);
};
}