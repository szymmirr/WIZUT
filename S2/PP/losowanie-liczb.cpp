#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand( time( 0 ) );
    int dolny, gorny, liczba=0, ilosc,tab[100]={},zm;
    cout << "podaj ilosc liczb";
    cin >> ilosc;
    cout << "podaj dolny zakres";
    cin >> dolny;
    cout << "podaj gorny zakres";
    cin >> gorny;
    gorny+=1;
    for (int i=0;i<ilosc;i++)
    {
        zm=0;
        liczba = dolny + rand() %( gorny - dolny );
        for (int j=0;j<=i;j++)
        {
            if (liczba==tab[j])
            {
                i--;
                zm=1;
                break;
            }
        }
        if(zm==0)
        {
            cout << liczba << " ";
            tab[i]=liczba;
        }

    }
    return 0;
}
