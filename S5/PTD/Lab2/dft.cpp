#include <iostream>
#include <complex>
using namespace std;
int main ()
{
    int N = 301;
    double x[N] = {};
    for (int i=0; i < N; i++)
    {
        cin >> x[i];
    }
    cout << endl << endl << endl << endl << endl << endl;
    for(int k = 0; k < N; k++)
    {
        complex<double> X(0,0);
        for(int n = 0; n < N; n++)
        {
            complex<double> wykladnik(0.0, (2*M_PI*k*n)/N);
            X += x[n] * M_E * exp(wykladnik);
        }
        cout << abs(X) << endl;
    }
    return 0;
}
