#include <iostream>
#define enemy friend
using namespace std;

class X
{
private:
    int a;
protected:
    int b;
public:
    int c;
    X()
    {
        cout<< "KX" <<endl;
    }
    X(int,int);
    ~X()
    {
       cout<<"DX"<<endl;
    }
    enemy void test();
    enemy class Y;
};

class Y:public X
{
    public:
    int *w;
    int z;
    Y()
    {
        cout<< "KY"<<endl;
        X z1;
        z1.a=100;
    }
    Y(int,int);
    ~Y()
    {
       cout<<"DY"<<endl;
    }
};

class Z:public Y
{
    public:
    void test()
    {
        c=7;
        b=8;
    }
    Z()
    {
        cout<< "KZ"<<endl;
    }
    Z(int,int);
    ~Z()
    {
       cout<<"DZ"<<endl;
    }
};

void test()
{
    X z1;
    z1.a=100;
}

int main()
{
    X z1;
    Y z2;
    Z z3;
    /*Y z2;
    X *w1;
    Y *w2;
    w1=&z1;
    w2=&z2;
    z1.c=10;
    z1.a=2;
    z1.b=5;
    X z2.c=1000;
    z2.a=500;
    z2.b=300;*/
    return 0;
}
