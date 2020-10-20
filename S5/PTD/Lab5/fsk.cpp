#include <iostream>
using namespace std;
double f1(double x) { return x; }
int main()
{
    double mdaszek;
    int N = 907;
    double zF[N] = {};
    double x1[N] = {};
    double x2[N] = {};
    double caleczka1[N] = {};
    double caleczka2[N] = {};
    double pt[N] = {};
    double h = 0.96;
    double sn1 = 0.5;
    double sn2 = 1.5;
    for (int t=0;t<180;t++)
    {
        for(int i=0;i<N;i++)
        {
            cin >> zF[i];
        }
        for(int i=0;i<N;i++)
        {
            x1[i]=zF[i]*sn1;
            //cout << x1[i] << endl;
        }
        for(int i=0;i<N;i++)
        {
            x2[i]=zF[i]*sn2;
            //cout << x2[i] << endl;
        }

        for (int i=0;i<N;i++)
        {
            caleczka1[i]=x1[i];
            caleczka2[i]=x2[i];
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
                caleczka1[j] += f1(xp + i*hcalka)*hcalka;
            }
            for (int i=1; i<=n; i++)
            {
                caleczka2[j] += f1(xp + i*hcalka)*hcalka;
            }
            //cout << caleczka[j] << endl;
            //cout << caleczka2[j] << endl;
        }

        for(int i=0;i<N;i++)
        {
            pt[i]=caleczka1[i]-caleczka2[i];
            //cout << pt[i] << endl;
        }

        for(int i=0;i<N;i++)
        {
            if (pt[i] >= h)
            {
                mdaszek = 1;
            }
            if (pt[i] < h)
            {
                mdaszek = 0;
            }
            cout << mdaszek << endl;
        }
    }
    return 0;
}
