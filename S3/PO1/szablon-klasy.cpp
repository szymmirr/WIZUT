#include <iostream>
using namespace std;

template<class T> class W
{
public:
    T a,b;
    T Drukuj()
    {
        cout << a << b;
        return a + b;
    }
};

class Z
{

};

void Test()
{
    W<int> w1;
    w1.a=20;
    W<float> w2;
    w2.a=5;
    W<Z> w3;
    cout << w1.a;
}

template<> class W<int>
{
public:
    int a,b;
    int Drukuj()
    {
        cout << "hello world";
    }
}

int main()
{
    Test();
    return 0;
}
