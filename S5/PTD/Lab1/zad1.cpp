#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double f = 3.5;
    double fi = 5*M_PI;
    double fs = 300;
    double T = 1.6;
    for (int n=1; n<1600; n++)
    {
        cout << sin(2*M_PI*f*(n/fs)+fi) << endl;
    }
    return 0;
}
