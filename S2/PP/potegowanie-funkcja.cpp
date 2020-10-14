#include <iostream>

using namespace std;

int potegowanie(int liczba,int potega)
{
    int wynik=1;
    if(potega==0)return 1;
    for(int i=0;i<potega;i++)
    {
        wynik*=liczba;
    }
    return wynik;
}

int main()
{
    int liczba, potega;
    cout << "Podaj liczbe" << endl;
    cin >> liczba;
    cout << "Podaj potege" << endl;
    cin >> potega;
    cout << potegowanie(liczba,potega);
    return 0;
}
