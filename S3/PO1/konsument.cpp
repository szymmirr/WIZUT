#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
    ifstream plik;
    char znak;
    cout << "Skonsumowane znaki: ";
    while(1)
    {
        plik.open("C:\magazyn.txt");
        if(plik.is_open())
        {
            plik >> znak;
            cout << znak;
            plik.close();
            remove("C:\magazyn.txt");
        }
    }
    return 0;
}
