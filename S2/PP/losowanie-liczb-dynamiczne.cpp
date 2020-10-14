#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand( time( 0 ) );
    int dolny, gorny, liczba=0, ilosc,zm;
    int *wsk;
    cout << "podaj ilosc liczb";
    cin >> ilosc;
    cout << "podaj dolny zakres";
    cin >> dolny;
    cout << "podaj gorny zakres";
    cin >> gorny;
    gorny+=1;
    wsk=(int*) malloc (ilosc*sizeof(int));
    for (int i=0;i<ilosc;i++)
    {
        zm=0;
        liczba = dolny + rand() %( gorny - dolny );
        for (int j=0;j<=i;j++)
        {
            if (liczba==*(wsk+j))
            {
                i--;
                zm=1;
                break;
            }
        }
        if(zm==0)
        {
            cout << liczba << " ";
            *(wsk+i)=liczba;
        }
    }
    free(wsk);
    return 0;
}
