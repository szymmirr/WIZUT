#include <iostream>

using namespace std;

class Klasa
{
protected:
    int a,b,c;
    public:
    void ryzykowne()
    {
        a=5;
        b=0;
        if(b==0)
        {
            string kurdebele = "no nie dziel";
            throw kurdebele;
        }
        c=a/b;
        cout<<"wynik "<<c;
    }
};

int main()
{
    Klasa k;
    try
    {
        k.ryzykowne();
    }
    catch(string komunikat)
    {
        cout<<komunikat;
    }
    return 0;
}
