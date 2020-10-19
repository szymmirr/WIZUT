// Lab4.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <complex>
using namespace std;

class rownanie
{
	std::vector < int > dane_we;
    float d,pd,md;
	std::vector <std::complex <float>> z;
public:
    rownanie()
    {
		int dana1, dana2, dana3;
        cin >> dana1 >> dana2 >> dana3;
		dane_we.push_back( dana1 );
		dane_we.push_back( dana2 );
		dane_we.push_back( dana3 );
		z.push_back(0);
		z.push_back(0);
		z.push_back(0);
		z.push_back(0);
		z.push_back(0);
		z.push_back(0);
    }
    ~rownanie()
    {
		dane_we.pop_back();
		dane_we.pop_back();
		dane_we.pop_back();
		dane_we.empty();
		z.pop_back();
		z.pop_back();
		z.pop_back();
		z.pop_back();
		z.pop_back();
		z.pop_back();
		z.empty();
    }
    std::vector<int> getdane() { return dane_we; }
    std::vector <std::complex <float>> getzesp() { return z; }
    float getd() { return d; }
    void setd(float dd) { d = dd; }
    float getmd() { return md; }
    void setmd(float mdd) { md = mdd; }

    void wyswietl_rownanie()
    {
        if(dane_we.at(0)!=1&&dane_we.at(0)!=0&&dane_we.at(0)!=-1)
        {
            cout<<dane_we.at(0);
        }
        if(dane_we.at(0)!=0)
        {
            if(dane_we.at(0)==-1)
            {
                cout << "-";
            }
            cout<<"xx";
            if(dane_we.at(1)>0)
            {
                cout<<"+";
            }
        }
        if(dane_we.at(1)!=1&&dane_we.at(1)!=0&&dane_we.at(1)!=-1)
        {
            cout<<dane_we.at(1);
        }
        if(dane_we.at(1)!=0)
        {
            if(dane_we.at(1)==-1)
            {
                cout << "-";
            }
            cout<<"x";
            if(dane_we.at(2)>0)
            {
                cout<<"+";
            }
        }
        if(dane_we.at(2)!=0)
        {
            cout<<dane_we.at(2);
        }
        if(dane_we.at(0)==0&&dane_we.at(1)==0&&dane_we.at(2)==0)
        {
            cout<<0;
        }
        cout<<"=0"<<endl;
    }

    void oblicz_d()
    {
        std::vector<int> dane_we = getdane();
        float d = getd();
        if(dane_we.at(0)!=0)
        {
            d=(dane_we.at(1)*dane_we.at(1))-(4*dane_we.at(0)*dane_we.at(2));
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
        if(dane_we.at(0)!=0)
        {
            if(d>0)
            {
				z.at(0)=((-dane_we.at(1)*1.0)-sqrt(d))/(2*(dane_we.at(0)*1.0));
                cout<<"x1v="<<z.at(0).real()<<endl;
                z.at(1)=(((-dane_we.at(1)*1.0)+sqrt(d))*1.0)/((2*(dane_we.at(0)*1.0))*1.0);
				cout<<"x2v="<<z.at(1).real()<<endl;
            }
            if(d==0)
            {
                z.at(0)=(-dane_we.at(1)*1.0)/((2*(dane_we.at(0)*1.0))*1.0);
                cout<<"x1v="<<z.at(0).real()<<endl;
            }
            if(d<0)
            {
				z.at(0)=(-dane_we.at(1)*1.0)/((2*dane_we.at(0))*1.0);
				z.at(1)=z.at(0);
                z.at(0).imag((sqrt(abs(d)))/(2*(dane_we.at(0)*1.0)));
                z.at(1).imag(-z.at(0).imag());
                formatuj_l_zesp();
            }
        }
        if(dane_we.at(0)==0&&dane_we.at(1)!=0)
        {
            float x1v=((-dane_we.at(2)*1.0)/(dane_we.at(1)*1.0));
			z.at(0)=x1v;
            cout<<"x1v="<<z.at(0).real()<<endl;
        }
        if(dane_we.at(0)==0&&dane_we.at(1)==0&&dane_we.at(2)!=0)
        {
            cout<<"Rownanie sprzeczne";
        }
        if(dane_we.at(0)==0&&dane_we.at(1)==0&&dane_we.at(2)==0)
        {
            cout<<"Rownanie tozsamosciowe";
        }
    }

    void dodaj()
    {
        if(d>0)
        {
			z.at(2)=z.at(0)+z.at(1);
        }
        if(d<0)
        {
            z.at(2)=z.at(0)+z.at(1);
			z.at(2).imag(z.at(0).imag()+z.at(1).imag());
        }
    }

    void odejmij()
    {
        if(d>0)
        {
            z.at(3)=z.at(0)-z.at(1);
        }
        if(d<0)
        {
            z.at(3)=z.at(0)-z.at(1);
            z.at(3).imag(z.at(0).imag()-z.at(1).imag());
        }
    }

    void pomnoz()
    {
        if(d>0)
        {
            z.at(4)=(z.at(0))*(z.at(1));
        }
        if(d<0)
        {
            z.at(4)=(z.at(0).real())*(z.at(1).real())-(z.at(0).imag())*(z.at(1).imag());
			z.at(4).imag((z.at(0).real())*(z.at(1).imag())+(z.at(0).real())*(z.at(1).imag()));
        }
    }

    void podziel()
    {
        if(d>0)
        {
            if(real(z.at(1))!=0)
            {
                z.at(5)=(z.at(0))/(z.at(1));
            }
        }
        if(d<0)
        {
            z.at(5)=((z.at(0).real())*(z.at(1).real())+(z.at(0).imag())*(z.at(1).imag()))/(((z.at(1).real())*(z.at(1).real()))+((z.at(1).imag())*(z.at(1).imag())));
            z.at(5).imag((z.at(0).real())*(z.at(1).imag())-(z.at(0).imag())*(z.at(1).imag()))/(((z.at(1).real())*(z.at(1).real()))+((z.at(1).imag())*(z.at(1).imag())));
        }
    }
    void wyswietl_wynik()
    {
        float d = getd();
        if(dane_we.at(0)!=0)
        {
            if(d>0)
            {
                cout<<"sv="<<real(z.at(2))<<endl;
                cout<<"rv="<<real(z.at(3))<<endl;
                cout<<"ilv="<<real(z.at(4))<<endl;
                cout<<"irv="<<real(z.at(5))<<endl;
            }
            if(d<0)
            {
                cout<<"sv="<<real(z.at(2))<<endl;
                cout<<"sn="<<z.at(2).imag()<<endl;
                cout<<"rv="<<real(z.at(3))<<endl;
                cout<<"rn="<<z.at(3).imag()<<endl;
                cout<<"ilv="<<real(z.at(4))<<endl;
                cout<<"iln="<<z.at(4).imag()<<endl;
                cout<<"irv="<<real(z.at(5))<<endl;
                cout<<"irn="<<z.at(5).imag()<<endl;
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
        cout<<"z1="<<real(z.at(0));
        if(z.at(0).imag()>=0)
        {
            cout<<"+";
        }
        if(z.at(0).imag()==-1)
        {
            cout<<"-";
        }
        if(z.at(0).imag()!=1&&z.at(0).imag()!=-1&&z.at(0).imag()!=0)
        {
            cout<<z.at(0).imag();
        }
        if(z.at(0).imag()!=0)
        {
            cout<<"*";
        }
        cout<<"i"<<endl;
        cout<<"z2="<<real(z.at(1));
        if(z.at(1).imag()>=0)
        {
            cout<<"+";
        }
        if(z.at(1).imag()==-1)
        {
            cout<<"-";
        }
        if(z.at(1).imag()!=1&&z.at(1).imag()!=-1&&z.at(1).imag()!=0)
        {
            cout<<z.at(1).imag();
        }
        if(z.at(1).imag()!=0)
        {
            cout<<"*";
        }
        cout<<"i"<<endl;
    }

    void oblicz_modul()
    {
        float md = getmd();
		md=sqrt(abs((z.at(0).real()*z.at(0).real())+((z.at(0).imag())*(z.at(0).imag()))));
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