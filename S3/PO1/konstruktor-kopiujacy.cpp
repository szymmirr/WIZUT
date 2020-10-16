#include <iostream>
using namespace std;

class Punkt
{
  public:
    int X, Y;
    Punkt()
    {
        X=0; Y=0;
    }  //je�eli go nie zdefiniujemy to w tej sytuacji kompilator nie zrobi tego za nas i deklaracja Punkt X() b�dzie b��dna
    Punkt(double fi, double r);
    Punkt(Punkt &Pkt)
    {
        X=Pkt.X;
        Y=Pkt.Y;
    }   //konstruktor kopiuj�cy
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
    Punkt A; //tutaj oczywi�cie dzia�a konstruktor bezparametryczny
    Punkt B(A);
    Punkt C = A;
    Miesiac miesia;
     Miesiac miesia(12, 2005);
 Miesiac kopia(miesia); //tu zostanie wywo�any konstruktor kopiuj�cy
 /* obiekt kopia b�dzie mia� tak� sam� zawarto�� jak obiekt miesi�c */
    return 0;
}
