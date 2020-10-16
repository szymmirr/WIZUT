#include <iostream>
using namespace std;

class Figura
{
public:
    int x,y;
    obwod()=0;
    pole();
    przeskalownie();
    obrot(int x,int y, int z);
    x=x+x1;
    y=y+y1;
};

class Prostokat : public Figura
{

};

class X
{
protected:
    //int a=5;

public:
    virtual void Druk()=0;
    //{
        //cout << a << " ";
    //}
};

class Y : public X
{
    int a=5;
    int b=6;
public:
    void Druk()
    {
        cout << a << " " << b << " ";
    }
};

int main()
{
    X *wskx;
    Y *wsky;
    X x1;
    //x1.a=5;
    Y y1;
    wskx = &x1;
    wsky = &y1;
    wskx->Druk();
    wsky->Druk();
    //int *tab[10];
    //tab[0]->Druk();
    wskx = &y1;
    //wskx = Druk();
    new kolo(10,10,20);
    for (i=0;i<10;i++)
    {
        tab[i]->Druk();
    }
    return 0;
}
