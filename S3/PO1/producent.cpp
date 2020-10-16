#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
    ofstream plik;
    char znak;
    cout << "Podaj znak: ";
    while(1)
    {
        znak = _getch();
        cout << znak;
        plik.open("C:\magazyn.txt");
        plik << znak;
        plik.close();
    }
    return 0;
}
