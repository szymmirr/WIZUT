// Lab1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
using namespace std;
int a,b,c;
float d,pd,x1v,x2v,x1n,x2n;
int main()
{
    cin >> a >> b >> c;
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

    if(a!=0)
    {
        d=(b*b)-(4*a*c);
        cout<<"d="<<d<<endl;
        if(d>0)
        {
            if(d<=25)
            {
                x1v=0;
                x2n=d;
                pd = (((x2n - d)*1.0) / (x2n*1.0));
                if(pd<0)
                {
                    pd=pd/(-1);
                }
                x2n =( ((x2n + d)*1.0) / (x2n*1.0) ) / 2.0;
                x1v++;
				x2n =( ((x2n + d)*1.0) / (x2n*1.0) ) / 2.0;
                pd = (((x2n - d)*1.0) / (x2n*1.0) );
                if(pd<0)
                {
                    pd=pd/(-1);
                }
                x1v=((-b*1.0)-x2n)/(2*(a*1.0));
                cout<<"x1v="<<x1v<<endl;

                x1v=0;
                x2n=d;
                pd = (x2n - d / x2n);
                if(pd<0)
                {
                    pd=pd/(-1);
                }
                x2n =( x2n + d / x2n ) / 2;
                x1v++;
                pd = (x2n - d / x2n);
                if(pd<0)
                {
                    pd=pd/(-1);
                }
                x2v=(((-b*1.0)+x2n)*1.0)/((2*(a*1.0))*1.0);
                cout<<"x2v="<<x2v<<endl;
            }
            if(d>25)
            {
                cout << "Nie potrafie pierwiastkowac d";
            }
        }
        if(d==0)
        {
            x1v=(-b*1.0)/((2*(a*1.0))*1.0);
            cout<<"x1v="<<x1v<<endl;
        }
        if(d<0)
        {
            if(-d<=25)
            {
                x1v=(-b*1.0)/((2*a)*1.0);
                x2v=x1v;
                cout<<"z1="<<x1v;
                x2v=d;
                pd = (((x2v - d)*1.0) / (x2v*1.0));
                if(pd<0)
                {
                    pd=pd/(-1);
                }
                x2v =( x2v + d / x2v ) / 2;
                pd = (x2v - d / x2v);
                if(pd<0)
                {
                    pd=pd/(-1);
                }
                x1n=((-b*1.0)-x2v)/(2*(a*1.0));

                x1n=x1n/((2*(a*1.0)))*1.0;
                x2n=-x1n;
                if(x1n>=0)
                {
                    cout<<"+";
                }
                if(x1n==-1)
                {
                    cout<<"-";
                }
                if(x1n!=1&&x1n!=-1&&x1n!=0)
                {
                    cout<<x1n;
                }
                if(x1n!=0)
                {
                    cout<<"*";
                }
                cout<<"i"<<endl;
                cout<<"z2="<<x1v;
                if(x2n>=0)
                {
                    cout<<"+";
                }
                if(x2n==-1)
                {
                    cout<<"-";
                }
                if(x2n!=1&&x2n!=-1&&x2n!=0)
                {
                    cout<<x2n;
                }
                if(x1n!=0)
                {
                    cout<<"*";
                }
                cout<<"i"<<endl;
            }
            if(-d>25)
            {
                cout << "Nie potrafie pierwiastkowac wartosci bezwzglednej z d";
            }
        }
    }
    if(a==0&&b!=0)
    {
        x1v=((-c*1.0)/(b*1.0));
        cout<<"x1v="<<x1v<<endl;
    }
    if(a==0&&b==0&&c!=0)
    {
        cout<<"Rownanie sprzeczne";
    }
    if(a==0&&b==0&&c==0)
    {
        cout<<"Rownanie tozsamosciowe";
    }
	int i;
	cin >> i;
    return 0;
}