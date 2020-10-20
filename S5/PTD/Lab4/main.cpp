#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << fixed;
    int N = 8;
    double x[N] = {};
    int f=5;
    int f1=9;
    int f2=10;
    int A1=2;
    int A2=1;
    for(int i=0;i<N;i++)
    {
        cin >> x[i];
    }
    int i=0;
    double ask=0,fsk=0,psk=0;
    for (int i=0;i<N+1;i++)
    {
        for (double t=i;t<i+1;t=t+0.01)
        {
            if (x[i]==1)
            {
                ask=A1*sin(2*M_PI*f*t);
                //fsk=sin(2*M_PI*f*t);
                //psk=sin(2*M_PI*f*t);
                cout << ask << endl;
            }
            else
            {
                ask=A2*sin(2*M_PI*f*t);
                //fsk=sin(2*M_PI*f2*t);
                //psk=sin(2*M_PI*f*t+M_PI);
                cout << ask << endl;
            }
        }
    }
    int cokolwiek;
    cin >> cokolwiek;
    return 0;
}
