#include <iostream>
#include <fstream>
using namespace std;

class klasa
{
    private:
        int a,b;
    public:
        klasa(int a, int b)
        {
            cout << "konstr ";
            this->a=a;
            this->b=b;
        }
        void drukuj()
        {
            cout << a << " " << b;
        }
        void zapisz()
        {
            fstream plik;
            plik.open("plik.txt");
            plik << a << " " << b;
        }
        ~klasa()
        {
            cout << " destr ";
        }
};

int main()
{
    klasa klasa1(2,3);
    klasa1.drukuj();
    klasa1.zapisz();
    return 0;
}
