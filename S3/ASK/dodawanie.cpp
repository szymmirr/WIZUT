#include <iostream>

using namespace std;

int main()
{
    unsigned char a=12;
		unsigned char b=2;
		unsigned char y;
		//int y=a+b;
		_asm
		{
			MOV AH,a ;dodawanie
			MOV AL,b
			ADD AH,AL
			MOV y,AH

			MOV BL,0
			MOV AH,a
			MOV al,0x01
			AND ah,0x01
			JZ etyk
			MOV bl,1
			etyk:
			MOV y,BL


		}
		CString str1;
		cout << y;
    cout << "Hello world!" << endl;
    return 0;
}
