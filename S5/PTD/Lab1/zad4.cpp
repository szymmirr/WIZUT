#include <iostream>
#include <cmath>
using namespace std;

double f = 3.5;
double fi = 5*M_PI;
double fs = 9000;
double T = 3;
int H = 40;

int main()
{
    double suma;
    for (double t=0; t<=3; t=t+0.01)
    {
        suma = 0;
        for (int n=1;n<=H;n++)
        {
            suma = suma + (1/n)*sin(n*M_PI*0.2*fs)*sin(n*M_PI*(t/fs));
        }
        cout << (4/M_PI)*suma << endl;
    }
    return 0;
}
