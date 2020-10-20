#include <iostream>
#include <cmath>
using namespace std;
double f11(double x) { return x; }
int main()
{
    long long int x1,x2,x3,x4,x5,x6,x7;
    for (int i=0;i<180;i++)
    {
        cin >> x7 >> x6 >> x5 >> x3;
        if(x3==1&&x5==1&&x7==1)
        {
            x1=1;
        }
        else if(x3==0&&x5==0&&x7==0)
        {
            x1=1;
        }
        else
        {
            x1=0;
        }

        if(x3==1&&x6==1&&x7==1)
        {
            x2=1;
        }
        else if(x3==0&&x6==0&&x7==0)
        {
            x2=1;
        }
        else
        {
            x2=0;
        }

        if(x5==1&&x6==1&&x7==1)
        {
            x4=1;
        }
        else if(x5==0&&x6==0&&x7==0)
        {
            x4=1;
        }
        else
        {
            x4=0;
        }
        cout << "Slowo zakodowane wyslane: " << x7 << x6 << x5 << x4 << x3 << x2 << x1 << endl;

        int N = 7;
        double x[N] = {};
        int f=5;
        int f1=N+1;
        int f2=N+2;
        int A1=2;
        int A2=1;
        int N2 = 1000;
        double ask[N2] = {};
        x[0]=x7;
        x[1]=x6;
        x[2]=x5;
        x[3]=x4;
        x[4]=x3;
        x[5]=x2;
        x[6]=x1;
        int licznik=0;
        for (int i=0;i<N+1;i++)
        {
            for (double t=i;t<i+1;t=t+0.01)
            {
                if (x[i]==1)
                {
                    ask[licznik]=A1*sin(2*M_PI*f*t);
                    //cout << ask[licznik] << endl;
                }
                else
                {
                    ask[licznik]=A2*sin(2*M_PI*f*t);
                    //cout << ask[licznik] << endl;
                }
                licznik+=1;
            }

        }

        double mdaszek;
        N = 806;
        double zA[N] = {};
        double zp[N] = {};
        double x2[N] = {};
        double caleczka[N] = {};
        double h = 2;
        double sn1 = 0.5;
        double sn2 = 1.5;
        for (int t=0;t<1;t++)
        {
            for(int i=0;i<N;i++)
            {
                zA[i]=ask[i];
            }
            for(int i=0;i<N;i++)
            {
                x2[i]=zA[i];
                //cout << x[i] << endl;
            }
            for (int i=0;i<N;i++)
            {
                caleczka[i]=x2[i];
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
                    caleczka[j] += f11(xp + i*hcalka)*hcalka;
                }
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
}
