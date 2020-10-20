#include <8051.h>
#include <string.h>
unsigned
int i,y;
//pomocnicze
char M;
//znak przekazywany
#define LCDDataPort P2
#define LCDRS P0_0
#define LCDRW P0_1
#define LCDE P0_2

void INIT(void);
void LCDWC(void);
void LCDWD(void);
void LCDRC(void);
void LCDRD(void);
void STROBE(void);
void PZNAK(char M);
void PISZKOM(char M);
void CZYZAJ(void);
void Delay(int X);
void GoToXY(char row, char col);
void LicznikLCD(char x, char y, unsigned int liczba);
void StringLCD(unsigned char *s);
void NumLCD(unsigned int liczba);

void INIT(void)
{
LCDWC();
Delay(10000);
LCDDataPort=0x38;
i=1;
if(i<3)
{
Delay(10000);
LCDWC();
STROBE();
i++;
}
else
{
PISZKOM(0x08);
PISZKOM(0x01);
PISZKOM(0x06);
PISZKOM(0x0c);
LCDWC();
}
}

void LCDWC(void)
{
LCDRS=0;
LCDRW=0;
}

void LCDWD(void)
{
LCDRS=1;
LCDRW=0;
}

void LCDRC(void)
{
LCDDataPort = 0x0FF;
LCDRS=0;
LCDRW=1;
}

void LCDRD(void)
{
LCDDataPort = 0x0FF;
LCDRS=1;
LCDRW=1;
}

void STROBE(void)
{
LCDE=1;
Delay(5);
LCDE=0;
}

void PZNAK(char M)
{
LCDDataPort=M;
LCDWD();
STROBE();
CZYZAJ();
}

void PISZKOM(char M)
{
CZYZAJ();
LCDWC();
LCDDataPort=M;
STROBE();
}

void CZYZAJ(void)
{
LCDDataPort=LCDDataPort;
LCDRW=1;
LCDRS=0;
if(LCDDataPort>127)
{
LCDE=1;
LCDDataPort=LCDDataPort;
LCDE=0;
}
}

void Delay(int X)
{
y=1;
if(y<X)
{
y++;
}
}

void GoToXY(char row, char col)
{
if(row>0)
{
PISZKOM(0x0c0+col);
}
else
{
PISZKOM(0x80+col);
}
}

void LicznikLCD(char x, char y, unsigned int liczba)
{
i=1;
if(i<liczba)
{
GoToXY(x,y);
NumLCD(i);
Delay(5);
i++;
}
}

void StringLCD(unsigned char *s)
{
unsigned char i,l;
i=strlen(s);
i=0;
if(i<l)
{
PZNAK(s);
Delay(100);
s++;
i++;
}
}

void NumLCD(unsigned int liczba)
{
char dtys,tysiace,setki,dziesiatki,jednosci;
unsigned int temp;
dtys=liczba/10000;
if(dtys==0)
{
PZNAK(0x20);
}
else
{
PZNAK(dtys+0x30);
}
temp=liczba%100000;
tysiace=temp/1000;
if(tysiace==0&&dtys==0)
{
PZNAK(0x20);
}
else
{
PZNAK(tysiace+0x30);
}
temp=temp%1000;
setki=temp/100;
if(setki==0&&tysiace==0&&dtys==0)
{
PZNAK(0x20);
}
else
{
PZNAK(dziesiatki+0x30);
}
temp=temp%10;
jednosci=temp;
PZNAK(jednosci+0x30);
}


void main(void)
{
INITLCD();
GoToXY(0,1);
PZNAK(0x4D);
GoToXY(1,1);
StringLCD('Napis');
LicznikLCD(1,8,65535);
}
