#include <iostream>
#include <fstream>
using namespace std;
class Macierz
{
    private:
        int a,b;
    public:
        Macierz(int a, int b);
        void geter(int x,int y)
        {
            //cout << tab[x][y];
        }
        void seter(int x,int y,int v)
        {
            //tab[x][y] = v;
        }
        void drukuj()
        {
            //cout << a << " " << b;
        }
        void zapisz()
        {
            fstream plik;
            plik.open("out.txt");
            plik << a << " " << b;
        }
        //Macierz();
        /*~Macierz()
        {
            cout << " destr ";
        }*/
};

Macierz::Macierz(int a,int b)
{
    int** tab = new int*[a];
    for(int i=0; i<b; i++)
    {
        tab[i] = new int();
    }
}

int main()
{
    Macierz z(10,100);
    Macierz z1(100,200);
    //Macierz z3("mac.txt");
    z.drukuj();
    z.zapisz();
    return 0;
}
