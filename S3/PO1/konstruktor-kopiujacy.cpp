#include <iostream>
using namespace std;

class Punkt
{
  public:
    int X, Y;
    Punkt()
    {
        X=0; Y=0;
    }  //je¿eli go nie zdefiniujemy to w tej sytuacji kompilator nie zrobi tego za nas i deklaracja Punkt X() bêdzie b³êdna
    Punkt(double fi, double r);
    Punkt(Punkt &Pkt)
    {
        X=Pkt.X;
        Y=Pkt.Y;
    }   //konstruktor kopiuj¹cy
};

class Miesiac
   {
        public:
             int numer;
             int rok;
             Miesiac()
             {
                 numer=0;
                 rok=0;
             }
             Miesiac(int a, int b);
             Miesia(const Miesiac &miesiac)
             {
                  numer = miesiac.numer;
                  rok = miesiac.rok;
             }
   };


int main()
{
    Punkt A; //tutaj oczywiœcie dzia³a konstruktor bezparametryczny
    Punkt B(A);
    Punkt C = A;
    Miesiac miesia;
     Miesiac miesia(12, 2005);
 Miesiac kopia(miesia); //tu zostanie wywo³any konstruktor kopiuj¹cy
 /* obiekt kopia bêdzie mia³ tak¹ sam¹ zawartoœæ jak obiekt miesi¹c */
    return 0;
}
