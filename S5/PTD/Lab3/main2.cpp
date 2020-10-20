#include <iostream>
#include <complex>
using namespace std;
int main ()
{
    cout << fixed;
    int N = 295;
    double x[N] = {};
    for (int i=0; i < N; i++)
    {
        cin >> x[i];
    }
    cout << endl << endl << endl << endl << endl << endl;
    double zdaszek = 0;
    double fmin = 9999999;
    double fmax = -99999999;
    double W = 0;
    for(int k = 1; k < N; k++)
    {
        complex<double> X(0,0);

        for(int n = 0; n < N; n++)
        {
            complex<double> wykladnik(0.0, (2*M_PI*k*n)/N);
            X += x[n] * M_E * exp(wykladnik);
        }
        //cout << abs(X) << endl;
        zdaszek = 20*log10(abs(X));
        if (zdaszek < fmin)
        {
            fmin = zdaszek;
        }
        if (zdaszek > fmax)
        {
            fmax = zdaszek;
        }
        cout << zdaszek << endl;
    }
    W = fmax-fmin;
    cout<<"min: "<<fmin<<endl;
    cout<<"max: "<<fmax<<endl;
    cout<<"W: "<<W<<endl;

    int cokolwiek;
    cin >> cokolwiek;
    return 0;
}
