#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout << fixed;
    double Am = 2;
    double fm = 1;
    double fn = 10;
    double kA = 25;
    double kp = 35;
    int N=5;
    double mt = 0;
    double zA = 0;
    double zp = 0;

    for (int i=0;i<N+1;i++)
    {
        for (double t=i;t<i+1;t=t+0.01)
        {
            mt=Am*sin(2*M_PI*fm*t);
            //zA=(kA*mt+1)*cos(2*M_PI*fn*t);
            zp=cos(2*M_PI*fn*t+kp*mt);
            cout << zp << endl;
        }
    }
    return 0;
}
