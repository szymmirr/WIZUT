#include <iostream>
#include <cmath>
using namespace std;

double f = 3.5;
double fi = 5*M_PI;
double fs = 300;
double T = 1.6;

double x (int n)
{
    return sin(2*M_PI*f*(n/fs)+fi);
}

double y (int n)
{
    return pow((3*n+2.7),0.9)*sin(12*M_PI*(n/fs));
}

int main()
{
    for (int n=1; n<1600; n++)
    {
        cout << y(n)-abs(x(n)) << endl;
    }
    cout << endl << endl;
    for (int n=1; n<50; n++)
    {
        cout << x(n)*(abs(y(n))+1.6)*pow(M_E,-0.3*n) << endl;
    }
    return 0;
}
