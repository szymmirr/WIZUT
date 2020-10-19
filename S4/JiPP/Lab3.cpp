// Lab3.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
struct urojona
{
    float x1n,x2n,sn,rn,iln,irn;
};
struct zespolona
{
    float x1v,x2v,sv,rv,ilv,irv;
    urojona lur;
};
class rownanie
{
    int *dane_we;
    float d,pd,md;
    zespolona *z;
public:
    rownanie()
    {
        dane_we = new int[3];
        z = new zespolona[6];
        cin >> dane_we[0] >> dane_we[1] >> dane_we[2];
    }
    ~rownanie()
    {
        delete(dane_we);
        delete(z);
    }
    int* getdane() { return dane_we; }
    zespolona* getzesp() { return z; }
    float getd() { return d; }
    void setd(float dd) { d = dd; }
    float getmd() { return md; }
    void setmd(float mdd) { md = mdd; }

    void wyswietl_rownanie()
    {
        if(dane_we[0]!=1&&dane_we[0]!=0&&dane_we[0]!=-1)
        {
            cout<<dane_we[0];
        }
        if(dane_we[0]!=0)
        {
            if(dane_we[0]==-1)
            {
                cout << "-";
            }
            cout<<"xx";
            if(dane_we[1]>0)
            {
                cout<<"+";
            }
        }
        if(dane_we[1]!=1&&dane_we[1]!=0&&dane_we[1]!=-1)
        {
            cout<<dane_we[1];
        }
        if(dane_we[1]!=0)
        {
            if(dane_we[1]==-1)
            {
                cout << "-";
            }
            cout<<"x";
            if(dane_we[2]>0)
            {
                cout<<"+";
            }
        }
        if(dane_we[2]!=0)
        {
            cout<<dane_we[2];
        }
        if(dane_we[0]==0&&dane_we[1]==0&&dane_we[2]==0)
        {
            cout<<0;
        }
        cout<<"=0"<<endl;
    }

    void oblicz_d()
    {
        int *dane_we = getdane();
        float d = getd();
        if(dane_we[0]!=0)
        {
            d=(dane_we[1]*dane_we[1])-(4*dane_we[0]*dane_we[2]);
            cout<<"d="<<d<<endl;
			setd(d);
        }
		else
		{
			setd(0);
		}
    }

    void oblicz_pierwiastki()
    {
        float d = getd();
        if(dane_we[0]!=0)
        {
            if(d>0)
            {
                z->x1v=((-dane_we[1]*1.0)-sqrt(d))/(2*(dane_we[0]*1.0));
                cout<<"x1v="<<z->x1v<<endl;
                z->x2v=(((-dane_we[1]*1.0)+sqrt(d))*1.0)/((2*(dane_we[0]*1.0))*1.0);
                cout<<"x2v="<<z->x2v<<endl;
            }
            if(d==0)
            {
                z->x1v=(-dane_we[1]*1.0)/((2*(dane_we[0]*1.0))*1.0);
                cout<<"x1v="<<z->x1v<<endl;
            }
            if(d<0)
            {
                z->x1v=(-dane_we[1]*1.0)/((2*dane_we[0])*1.0);
                z->x2v=z->x1v;
                z->lur.x1n=(sqrt(abs(d)))/(2*(dane_we[0]*1.0));
                z->lur.x2n=-(z->lur.x1n);
                formatuj_l_zesp();
            }
        }
        if(dane_we[0]==0&&dane_we[1]!=0)
        {
            z->x1v=((-dane_we[2]*1.0)/(dane_we[1]*1.0));
            cout<<"x1v="<<z->x1v<<endl;
        }
        if(dane_we[0]==0&&dane_we[1]==0&&dane_we[2]!=0)
        {
            cout<<"Rownanie sprzeczne";
        }
        if(dane_we[0]==0&&dane_we[1]==0&&dane_we[2]==0)
        {
            cout<<"Rownanie tozsamosciowe";
        }
    }

    void dodaj()
    {
        if(d>0)
        {
            z->sv=z->x1v+z->x2v;
        }
        if(d<0)
        {
            z->sv=z->x1v+z->x2v;
            z->lur.sn=z->lur.x1n+z->lur.x2n;
        }
    }

    void odejmij()
    {
        if(d>0)
        {
            z->rv=z->x1v-z->x2v;
        }
        if(d<0)
        {
            z->rv=z->x1v-z->x2v;
            z->lur.rn=z->lur.x1n-z->lur.x2n;
        }
    }

    void pomnoz()
    {
        if(d>0)
        {
            z->ilv=(z->x1v)*(z->x2v);
        }
        if(d<0)
        {
            z->ilv=(z->x1v)*(z->x2v)-(z->lur.x1n)*(z->lur.x2n);
            z->lur.iln=(z->x1v)*(z->lur.x2n)+(z->x1v)*(z->lur.x2n);
        }
    }

    void podziel()
    {
        if(d>0)
        {
            if(z->x2v!=0)
            {
                z->irv=(z->x1v)/(z->x2v);
            }
        }
        if(d<0)
        {
            z->irv=((z->x1v)*(z->x2v)+(z->lur.x1n)*(z->lur.x2n))/(((z->x2v)*(z->x2v))+((z->lur.x2n)*(z->lur.x2n)));
            z->lur.irn=((z->x1v)*(z->lur.x2n)-(z->lur.x1n)*(z->lur.x2n))/(((z->x2v)*(z->x2v))+((z->lur.x2n)*(z->lur.x2n)));
        }
    }
    void wyswietl_wynik()
    {
        float d = getd();
        if(dane_we[0]!=0)
        {
            if(d>0)
            {
                cout<<"sv="<<z->sv<<endl;
                cout<<"rv="<<z->rv<<endl;
                cout<<"ilv="<<z->ilv<<endl;
                cout<<"irv="<<z->irv<<endl;
            }
            if(d<0)
            {
                cout<<"sv="<<z->sv<<endl;
                cout<<"sn="<<z->lur.sn<<endl;
                cout<<"rv="<<z->rv<<endl;
                cout<<"rn="<<z->lur.rn<<endl;
                cout<<"ilv="<<z->ilv<<endl;
                cout<<"iln="<<z->lur.iln<<endl;
                cout<<"irv="<<z->irv<<endl;
                cout<<"irn="<<z->lur.irn<<endl;
            }
        }
    }

    void my_sqrt()
    {
		float t1=0,t2=1;
		if(t1!=t2)
		{
			t1=t2;
			t2=(t1+abs(d)/t1)/2;
		}
		if(t1!=t2)
		{
			t1=t2;
			t2=(t1+abs(d)/t1)/2;
		}
		if(t1!=t2)
		{
			t1=t2;
			t2=(t1+abs(d)/t1)/2;
		}
		if(t1!=t2)
		{
			t1=t2;
			t2=(t1+abs(d)/t1)/2;
		}
		if(t1!=t2)
		{
			t1=t2;
			t2=(t1+abs(d)/t1)/2;
		}
		if(t1!=t2)
		{
			t1=t2;
			t2=(t1+abs(d)/t1)/2;
		}
		cout << "sqrt(d)=" << sqrt(abs(d)) << endl;
		cout << "my_sqrt(d)=" << t2 << endl;
		if(t2-sqrt(abs(d))<0.000001)
		{
			cout << "my_sqrt(d)-sqrt(d)=" << 0 << endl;
		}
		else
		{
			cout << "my_sqrt(d)-sqrt(d)=" << t2-sqrt(abs(d)) << endl;
		}
    }

    void formatuj_l_zesp()
    {
        cout<<"z1="<<z->x1v;
        if(z->lur.x1n>=0)
        {
            cout<<"+";
        }
        if(z->lur.x1n==-1)
        {
            cout<<"-";
        }
        if(z->lur.x1n!=1&&z->lur.x1n!=-1&&z->lur.x1n!=0)
        {
            cout<<z->lur.x1n;
        }
        if(z->lur.x1n!=0)
        {
            cout<<"*";
        }
        cout<<"i"<<endl;
        cout<<"z2="<<z->x2v;
        if(z->lur.x2n>=0)
        {
            cout<<"+";
        }
        if(z->lur.x2n==-1)
        {
            cout<<"-";
        }
        if(z->lur.x2n!=1&&z->lur.x2n!=-1&&z->lur.x2n!=0)
        {
            cout<<z->lur.x2n;
        }
        if(z->lur.x1n!=0)
        {
            cout<<"*";
        }
        cout<<"i"<<endl;
    }
    void oblicz_modul()
    {
        float md = getmd();
		//cout<<"z->x1v="<<z->x1v<<endl;
		//cout<<"z->x1n="<<z->lur.x1n<<endl;
        md=sqrt(abs(((z->x1v)*(z->x1v))+((z->lur.x1n)*(z->lur.x1n))));
        cout<<"md="<<md<<endl;
        setmd(md);
    }
};

int main()
{
    rownanie obiekt;
    obiekt.wyswietl_rownanie();
    obiekt.oblicz_d();
    obiekt.oblicz_pierwiastki();
	obiekt.my_sqrt();
    obiekt.dodaj();
    obiekt.odejmij();
    obiekt.pomnoz();
    obiekt.podziel();
    obiekt.wyswietl_wynik();
    obiekt.oblicz_modul();
    obiekt.~rownanie();
	int i;
	cin >> i;
    exit(0);
    return 0;
}