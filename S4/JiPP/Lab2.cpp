// Lab2.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

void formatuj_rownanie(int a, int b, int c)
{
    if(a!=1&&a!=0&&a!=-1)
    {
        cout<<a;
    }
    if(a!=0)
    {
        if(a==-1)
        {
            cout << "-";
        }
        cout<<"xx";
        if(b>0)
        {
            cout<<"+";
        }
    }
    if(b!=1&&b!=0&&b!=-1)
    {
        cout<<b;
    }
    if(b!=0)
    {
        if(b==-1)
        {
            cout << "-";
        }
        cout<<"x";
        if(c>0)
        {
            cout<<"+";
        }
    }
    if(c!=0)
    {
        cout<<c;
    }
    if(a==0&&b==0&&c==0)
    {
        cout<<0;
    }
    cout<<"=0"<<endl;
}

float oblicz_d(int a, int b, int c)
{
    float d=0;
    if(a!=0)
    {
        d=(b*b)-(4*a*c);
        cout<<"d="<<d<<endl;
    }
    return d;
}

void formatuj_l_zesp(int a, int b, int c, float *x1v, float *x2v, float *x1n, float *x2n)
{
    cout<<"z1="<<*x1v;
    if(*x1n>=0)
    {
        cout<<"+";
    }
    if(*x1n==-1)
    {
        cout<<"-";
    }
    if(*x1n!=1&&*x1n!=-1&&*x1n!=0)
    {
        cout<<*x1n;
    }
    if(*x1n!=0)
    {
        cout<<"*";
    }
    cout<<"i"<<endl;
    cout<<"z2="<<*x2v;
    if(*x2n>=0)
    {
        cout<<"+";
    }
    if(*x2n==-1)
    {
        cout<<"-";
    }
    if(*x2n!=1&&*x2n!=-1&&*x2n!=0)
    {
        cout<<*x2n;
    }
    if(*x1n!=0)
    {
        cout<<"*";
    }
    cout<<"i"<<endl;
}

void oblicz_pierwiastki(int a, int b, int c, float d, float *x1v, float *x2v, float *x1n, float *x2n)
{
    if(a!=0)
    {
        if(d>0)
        {
            *x1v=((-b*1.0)-sqrt(d))/(2*(a*1.0));
            cout<<"x1v="<<*x1v<<endl;
            *x2v=(((-b*1.0)+sqrt(d))*1.0)/((2*(a*1.0))*1.0);
            cout<<"x2v="<<*x2v<<endl;
        }
        if(d==0)
        {
            *x1v=(-b*1.0)/((2*(a*1.0))*1.0);
            cout<<"x1v="<<*x1v<<endl;
        }
        if(d<0)
        {
            *x1v=(-b*1.0)/((2.0*a)*1.0);
            *x2v=*x1v;
            *x1n=(sqrt(abs(d)))/(2.0*(a*1.0));
            *x2n=-(*x1n);
            formatuj_l_zesp(a, b, c, x1v, x2v, x1n, x2n);
        }
    }
    if(a==0&&b!=0)
    {
        *x1v=((-c*1.0)/(b*1.0));
        cout<<"x1v="<<*x1v<<endl;
    }
    if(a==0&&b==0&&c!=0)
    {
        cout<<"Rownanie sprzeczne";
    }
    if(a==0&&b==0&&c==0)
    {
        cout<<"Rownanie tozsamosciowe";
    }
}

void dodaj(float d,float *x1v,float *x2v,float *x1n,float *x2n,float *sv,float *sn)
{
    if(d>0)
    {
        *sv=*x1v+*x2v;
    }
    if(d<0)
    {
        *sv=*x1v+*x2v;
        *sn=*x1n+*x2n;
    }
}

void odejmij(float d,float *x1v,float *x2v,float *x1n,float *x2n,float *rv,float *rn)
{
    if(d>0)
    {
        *rv=*x1v-*x2v;
    }
    if(d<0)
    {
        *rv=*x1v-*x2v;
        *rn=*x1n-*x2n;
    }
}

void pomnoz(float d,float *x1v,float *x2v,float *x1n,float *x2n,float *ilv,float *iln)
{
    if(d>0)
    {
        *ilv=(*x1v)*(*x2v);
    }
    if(d<0)
    {
        *ilv=(*x1v)*(*x2v)-(*x1n)*(*x2n);
        *iln=(*x1v)*(*x2n)+(*x1v)*(*x2n);
    }
}

void podziel(float d,float *x1v,float *x2v,float *x1n,float *x2n,float *irv,float *irn)
{
    if(d>0)
    {
        if(x2v!=0)
        {
            *irv=(*x1v)/(*x2v);
        }
    }
    if(d<0)
    {
        *irv=((*x1v)*(*x2v)+(*x1n)*(*x2n))/(((*x2v)*(*x2v))+((*x2n)*(*x2n)));
        *irn=((*x1v)*(*x2n)-(*x1n)*(*x2n))/(((*x2v)*(*x2v))+((*x2n)*(*x2n)));
    }
}

void wyswietl_wynik(int a,int b,int c,float d,float *x1v,float *x2v,float *x1n,float *x2n,float *sv, float *sn, float *rv, float *rn, float *ilv, float *iln, float *irv, float *irn)
{
    if(a!=0)
    {
        if(d>0)
        {
            cout<<"sv="<<*sv<<endl;
            cout<<"rv="<<*rv<<endl;
            cout<<"ilv="<<*ilv<<endl;
            cout<<"irv="<<*irv<<endl;
            cout<<endl;
        }
        if(d<0)
        {
            cout<<"sv="<<*sv<<endl;
            cout<<"sn="<<*sn<<endl;
            cout<<"rv="<<*rv<<endl;
            cout<<"rn="<<*rn<<endl;
            cout<<"ilv="<<*ilv<<endl;
            cout<<"iln="<<*iln<<endl;
            cout<<"irv="<<*irv<<endl;
            cout<<"irn="<<*irn<<endl;
            cout<<endl;
        }
    }
}

float my_sqrt(float x)
{
	float t1=0,t2=1;
	if(t1!=t2)
	{
		t1=t2;
		t2=(t1+x/t1)/2;
	}
	if(t1!=t2)
	{
		t1=t2;
		t2=(t1+x/t1)/2;
	}
	if(t1!=t2)
	{
		t1=t2;
		t2=(t1+x/t1)/2;
	}
	if(t1!=t2)
	{
		t1=t2;
		t2=(t1+x/t1)/2;
	}
	if(t1!=t2)
	{
		t1=t2;
		t2=(t1+x/t1)/2;
	}
	if(t1!=t2)
	{
		t1=t2;
		t2=(t1+x/t1)/2;
	}
	return t2;
}

int podaj_a()
{
	int a;
    cin >> a;
    return a;
}

int podaj_b()
{
	int b;
    cin >> b;
    return b;
}

int podaj_c()
{
	int c;
    cin >> c;
    return c;
}

int main()
{
    int a,b,c;
    float d,pd,x1v,x2v,x1n,x2n,sv,sn,rv,rn,ilv,iln,irv,irn;
    a=podaj_a();
    b=podaj_b();
    c=podaj_c();
    formatuj_rownanie(a,b,c);
    d = oblicz_d(a,b,c);
	cout << "sqrt(d)=" << sqrt(abs(d)) << endl;
	cout << "my_sqrt(d)=" << my_sqrt(abs(d)) << endl;
	if(my_sqrt(abs(d))-sqrt(abs(d))<0.000001)
	{
		cout << "my_sqrt(d)-sqrt(d)=" << 0 << endl;
	}
	else
	{
		cout << "my_sqrt(d)-sqrt(d)=" << my_sqrt(abs(d))-sqrt(abs(d)) << endl;
	}
	oblicz_pierwiastki(a,b,c,d,&x1v,&x2v,&x1n,&x2n);
    dodaj(d,&x1v,&x2v,&x1n,&x2n,&sv,&sn);
    odejmij(d,&x1v,&x2v,&x1n,&x2n,&rv,&rn);
    pomnoz(d,&x1v,&x2v,&x1n,&x2n,&ilv,&iln);
    podziel(d,&x1v,&x2v,&x1n,&x2n,&irv,&irn);
    wyswietl_wynik(a,b,c,d,&x1v,&x2v,&x1n,&x2n,&sv,&sn,&rv,&rn,&ilv,&iln,&irv,&irn);
	int i;
	cin >> i;
    return 0;
}