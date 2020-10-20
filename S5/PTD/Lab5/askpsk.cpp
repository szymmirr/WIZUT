#include <iostream>
using namespace std;
double f1(double x) { return x; }
int main()
{
    double mdaszek;
    int N = 907;
    double zA[N] = {};
    double zp[N] = {};
    double x[N] = {};
    double caleczka[N] = {};
    double h = 1;
    double sn1 = 0.5;
    double sn2 = 1.5;
    for (int t=0;t<180;t++)
    {
        for(int i=0;i<N;i++)
        {
            cin >> zA[i];
        }
        for(int i=0;i<N;i++)
        {
            cin >> zp[i];
        }
        for(int i=0;i<N;i++)
        {
            x[i]=zA[i]*zp[i];
            //cout << x[i] << endl;
        }

        for (int i=0;i<N;i++)
        {
            caleczka[i]=x[i];
        }

        double xp=0, xk=0, hcalka=0, calka=0;
        int n=0;

        xp = 0;
        xk = 1;
        n = 3;

        hcalka = (xk - xp) / (float)n;

        for(int j=0;j<N;j++)
        {
            for (int i=1; i<=n; i++)
            {
                caleczka[j] += f1(xp + i*hcalka)*hcalka;
            }
            //cout << caleczka[j] << endl;
        }
        for(int i=0;i<N;i++)
        {
            if (caleczka[i] >= h)
            {
                mdaszek = 1;
            }
            if (caleczka[i] < h)
            {
                mdaszek = 0;
            }
            cout << mdaszek << endl;
        }
    }
    return 0;
}
