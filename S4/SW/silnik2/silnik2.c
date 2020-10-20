#include <8051.h>
// 8 4 2 1 falowy
// 9 12 6 3 krokowy { 12,6,3,9};
// 8 12 4 6 2 3 1 9 polkroku
#define krok 515
#define Czas 65536 -3608
//unsigned char TablSiln[] = { 12,6,3,9}; //prawo
unsigned char TablSiln[]={3,6,12,9};//lewo
//
char i;
unsigned int a =0;
int liczba =515;
int lobrotow =0;
int main(void)
{
EA =1;
EX0 =1;
EX1 =1;
IT1 =1;
while(1);
}
void button0(void)__interrupt(0)
{
for(a =0;a <10000;++a);
++lobrotow;
for(a =0;a <10000;++a);
liczba =lobrotow *krok;
}
void button1(void)__interrupt(2)
{
while(liczba)
{
for(i =0;i <4;++i)
{
for(a =0;a <500;++a);
P0 =TablSiln[i];
}
liczba--;
}
}