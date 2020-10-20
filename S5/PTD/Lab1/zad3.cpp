#include <iostream>
#include <cmath>
using namespace std;

double f = 3.5;
double fi = 5*M_PI;
double fs = 9000;
double T = 3;

int main()
{
    for (double t=0; t<=3; t=t+0.01)
    {
        double n=t;
        if (0.3>t&&t>=0)
        {
            cout << t*sin(34*M_PI*n/fs) << endl;
        }
        if (0.8>t&&t>=0.3)
        {
            cout << (cos(12*M_PI*t/fs)/2*pow(t,3))*cos(22*M_PI*t/fs) << endl;
        }
        if (1.4>t&&t>=0.8)
        {
            cout << (cos(12*M_PI*t/fs)/pow(t,2)) << endl;
        }
        if (3>t&&t>=1.4)
        {
            cout << sin(20*M_PI*n/fs)-log2(t) << endl;
        }
    }
    return 0;
}
