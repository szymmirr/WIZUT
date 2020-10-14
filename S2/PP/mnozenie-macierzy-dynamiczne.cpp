#include <iostream>
#include <cstdlib>
using namespace std;

int **mnozenie(int tab1[10][10], int tab2[10][10], int **wsk3, int kol1, int kol2, int wier1)
{
    for(int i=0;i<kol2;i++)
    {
        for(int j=0;j<kol1;j++)
        {
            for(int k=0;k<wier1;k++)
            {
                wsk3[i][k]+=tab1[i][j]*tab2[j][k];
            }
        }
    }
    return wsk3;
}

int main()
{
    int kol1,kol2,wier1,wier2;
    cout << "Podaj ilosc kolumn pierwszej macierzy" << endl;
    cin >> kol1;
    cout << "Podaj ilosc wierszy pierwszej macierzy" << endl;
    cin >> wier1;
    cout << "Podaj pierwsza macierz" << endl;
    int tab1[10][10];
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
    int tab2[10][10];
    for (int i=0;i<wier2;i++)
    {
        for (int j=0;j<kol2;j++)
        {
            cin >> tab2[i][j];
        }
    }

    int **wsk3;
    wsk3=(int**) malloc (wier1*sizeof(int));
    for (int i=0;i<kol2;i++)
    {
        wsk3[i]=(int*) malloc (kol2*sizeof(int));
    }
    for(int i=0;i<kol2;i++)
    {
        for(int j=0;j<kol1;j++)
        {
            for(int k=0;k<wier1;k++)
            {
                wsk3[i][k]=0;
            }
        }
    }

    mnozenie(tab1,tab2,wsk3,kol1,kol2,wier1);

    for (int i=0;i<kol2;i++)
    {
        for (int j=0;j<wier1;j++)
        {
            cout << wsk3[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<wier1; i++) 
    {
        free(wsk3[i]);
    }
    free(wsk3);
    return 0;
}
