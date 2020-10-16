//SDIZO IS1 221B LAB01
//Szymon Mirr
//smirr@wi.zut.edu.pl
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct struktura{
  int a;
  char b;
  float c;
};

struktura** losowanie (int n)
{
    srand( time( 0 ) );
    struktura** tab = new struktura*[n];
    for(int i=0; i<n; i++)
    {
        tab[i] = new struktura();
        tab[i] -> a = 1 + rand() %( 10000 - 1 );
        tab[i] -> b = 'A' + rand() %( 'Z' - 'A' );
        tab[i] -> c = 100 + (1 + rand() %( n - 1 ));
    }
    return tab;
}

void kasowanie (struktura** tab, int n)
{
    for(int i=0; i<n; i++)
    {
        delete[] tab[i];
    }
    delete[] tab;
}

void sortowanie (struktura** tab, int n)
{
    int tmp,czeker;
    czeker=0;
    do
    {
        czeker = 0;
        for (int i=0; i<n-1; i++)
        {
            if (tab[i] -> a > tab[i+1] -> a)
            {
                tmp = tab[i] -> a;
                tab[i] -> a = tab[i+1] -> a;
                tab[i+1] -> a = tmp;
                czeker=1;
            }
        }
    }
    while(czeker==1);
}

int zliczanie (struktura** tab, int n, char znak)
{
    int licznik=0;
    for(int i=0; i<n; i++)
    {
        if(tab[i] -> b == znak)
        {
            licznik+=1;
        }
    }
    return licznik;
}

int main()
{
    clock_t begin, end;
    begin = clock();
    fstream plik;
    plik.open("inlab01.txt");
    int n;
    plik >> n;
    char znak;
    plik >> znak;
    struktura** tab = losowanie(n);
    sortowanie(tab, n);
    for(int i=0; i<20; i++)
    {
         cout << tab[i] -> a << " " << tab[i] -> b << " " << tab[i] -> c << endl;
    }
    cout << endl << "Ilosc znakow " << znak << ": " << zliczanie(tab, n, znak) << endl;
    kasowanie(tab, n);
    plik.close();
    end = clock();
    cout << "Czas: " << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
