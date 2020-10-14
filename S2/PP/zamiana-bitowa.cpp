#include <iostream>
#include <cstdlib>
using namespace std;
char *zamiana(int liczba)
{
    char *wsk;
    wsk=(char*) malloc (32*sizeof(int));
    bool spr=false;
    for (int i=31;i>=0;i--)
    {
        *(wsk+i)=((liczba>>i)&1);
    }
    return wsk;
}
int main()
{
    int liczba;
    char *wsk2;
    cout << "Podaj liczbe" << endl;
    cin>>liczba;
    wsk2 = zamiana (liczba);
    for (int i=31;i>=0;i--)
    {
        cout << (int)wsk2[i];
    }
    free(wsk2);
    return 0;
}
