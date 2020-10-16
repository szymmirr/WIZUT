#include <iostream>

using namespace std;

class Bar
{
    //Baz baz;
};
class Foo
{
    Bar* bar;
    void setBar(Bar* _bar)
    {
        bar=_bar;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
