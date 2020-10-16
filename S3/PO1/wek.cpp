#include <iostream>

using namespace std;

class wek
{
    public:
    int x;
    int y;

    wek operator+(const wek &p)
    {
        wek temp;
        temp.x=this->x+p.x;
        temp.y=this->y+p.y;
        return temp;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    wek a(10,10),b(20,20),c(30,30);
    a=b+c;
    return 0;
}
