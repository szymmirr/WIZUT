#include <iostream>
#include <cstdlib>
#include <fstream>
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

int wczytanie()
{
    fstream plik;
    fstream plik2;
    plik.open("dane.txt");
    plik2.open("wyjscie.txt");
    int kol1,kol2,wier1,wier2;
    plik>>wier1;
    plik>>kol1;
    int tab1[10][10];
    for (int i=0;i<wier1;i++)
    {
        for (int j=0;j<kol1;j++)
        {
            plik >> tab1[i][j];
        }
    }
    plik>>wier2;
    plik>>kol2;
    int tab2[10][10];
    for (int i=0;i<wier2;i++)
    {
        for (int j=0;j<kol2;j++)
        {
            plik >> tab2[i][j];
        }
    }
}

int zapis()
{
    for (int i=0;i<kol2;i++)
    {
        for (int j=0;j<wier1;j++)
        {
            cout << wsk3[i][j] << " ";
            plik2 << wsk3[i][j] << " ";
        }
        cout << endl;
        plik2 << endl;
    }
    for(int i=0; i<wier1; i++)
    {
        free(wsk3[i]);
    }
    free(wsk3);
}

int main()
{
    wczytanie();
    int **wsk3;
    wsk3=(int**) malloc (wier1*sizeof(int*));
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




    return 0;
}
