#include <iostream>

using namespace std;

int main()
{
    int tab1[10][10]={},tab2[10][10]={},tab3[10][10]={},kol1,kol2,wier1,wier2;
    cout << "Podaj ilosc kolumn pierwszej macierzy" << endl;
    cin >> kol1;
    cout << "Podaj ilosc wierszy pierwszej macierzy" << endl;
    cin >> wier1;
    cout << "Podaj pierwsza macierz" << endl;
    for (int i=0;i<wier1;i++)
    {
        for (int j=0;j<kol1;j++)
        {
            cin >> tab1[i][j];
        }
    }
    cout << "Podaj ilosc kolumn drugiej macierzy" << endl;
    cin >> kol2;
    cout << "Podaj ilosc wierszy drugiej macierzy" << endl;
    cin >> wier2;
    cout << "Podaj druga macierz" << endl;
    for (int i=0;i<wier2;i++)
    {
        for (int j=0;j<kol2;j++)
        {
            cin >> tab2[i][j];
        }
    }

    for(int i=0;i<kol2;i++)
    {
        for(int j=0;j<kol1;j++)
        {
            for(int k=0;k<wier1;k++)
            {
                tab3[i][k]+=tab1[i][j]*tab2[j][k];
            }
        }
    }

    for (int i=0;i<kol2;i++)
    {
        for (int j=0;j<wier1;j++)
        {
            cout << tab3[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
