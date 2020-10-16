#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class Figura
{
protected:
    int x,y;
    Figura(int xx, int yy);
public:
    virtual int Drukuj(int szukana, int kluczyk)=0;
    virtual int Jaki()=0;
};
Figura::Figura(int xx, int yy)
{
    x=xx;
    y=yy;
}

class Prostokat : public Figura
{
protected:
    int a;
    string b;
    int Jaki()
    {
        return 1;
    }
    int Drukuj(int szukana, int kluczyk)
    {
        if (szukana==0||szukana==1)
        {
            cout << kluczyk << ". ";
            cout<<"pro "<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
            return 1;
        }
        else return 2;
    }

public:
    Prostokat(int xx, int yy, int aa, string bb);
};
Prostokat::Prostokat(int xx, int yy, int aa, string bb) : Figura(xx,yy)
{
    a=aa;
    b=bb;
}

class Trojkat : public Figura
{
protected:
    int a,h;
    int Drukuj(int szukana, int kluczyk)
    {
        if (szukana==0||szukana==2)
        {
            cout << kluczyk << ". ";
            cout<<"tro "<<x<<" "<<y<<" "<<a<<" "<<h<<endl;
            return 1;
        }
        else return 2;
    }
    int Jaki()
    {
        return 2;
    }

public:
    Trojkat(int xx, int yy, int aa, int hh);
};
Trojkat::Trojkat(int xx, int yy, int aa, int hh) : Figura(xx,yy)
{
    a=aa;
    h=hh;
}

class Kolo : public Figura
{
protected:
    int n;
    int Drukuj(int szukana, int kluczyk)
    {
        if (szukana==0||szukana==3)
        {
            cout << kluczyk << ". ";
            cout<<"kol "<<x<<" "<<y<<" "<<n<<endl;
            return 1;
        }
        else return 2;
    }
    int Jaki()
    {
        return 3;
    }
public:
    Kolo(int xx, int yy, int nn);
};
Kolo::Kolo(int xx, int yy, int nn) : Figura(xx,yy)
{
    n=nn;
}

class Trapez : public Figura
{
protected:
    int a,b,h;
    int Drukuj(int szukana, int kluczyk)
    {
        if (szukana==0||szukana==4)
        {
            cout << kluczyk << ". ";
            cout<<"tra "<<x<<" "<<y<<" "<<a<<" "<<b<<" "<<h<<endl;
            return 1;
        }
        else return 2;
    }
    int Jaki()
    {
        return 4;
    }
public:
    Trapez(int xx, int yy, int aa, int bb, int hh);
};
Trapez::Trapez(int xx, int yy, int aa, int bb, int hh) : Figura(xx,yy)
{
    a=aa;
    b=bb;
    h=hh;
}

struct node_rec
{
    int klucz;
    Figura *figura;
    struct node_rec *next;
};

class Lista
{
protected:
    int sprawdz(node_rec * head, int klucz)
    {
        int i=0;
        node_rec * p = head;
        if(p)
        do
        {
            if(p->klucz == klucz)
            {
                return(1);
            }
            i++;
            p = p->next;
        }
        while(p != head);
        return 0;
    }
public:
    int drukuj(node_rec * head,int szukana)
    {
        int i=0;
        node_rec * p = head;
        int wynik2=0,wynik=0;
        if(p)
        {
            do
            {
                if(p->klucz != 0)
                {
                    int kluczyk = p->klucz;
                    wynik = p->figura->Drukuj(szukana,kluczyk);
                    if(wynik==1)
                    {
                        wynik2=wynik2+1;
                    }
                    wynik=0;
                }
                p = p->next;
                i++;
            }
            while(p != head);
        }
        return wynik2;
    }


int jaki(node_rec * head,int klucz)
{
    int i=0,nojaki=0;
    node_rec * p = head;
    if(p)
    {
        do
        {
            if(p->klucz == klucz)
            {
                nojaki = p->figura->Jaki();
            }
            p = p->next;
            i++;
        }
        while(p != head);
    }
    return nojaki;
}


void insertuj(node_rec *& head, Figura *& figura)
{
    if (!head)
    {
        head = new node_rec();
        head->next = head;
        return;
    }
    int klucz=1;
    while(sprawdz(head, klucz)==1)
    {
        klucz=klucz+1;
    }
    node_rec *p = head;
    node_rec *previous = NULL;
    do
    {
        previous = p;
        p = p->next;
        if (klucz <= p->klucz && klucz >= previous->klucz)
        {
            break;
        }
    }
    while (p != head);
    node_rec *node_nowy = new node_rec();
    node_nowy->next = p;
    previous->next = node_nowy;
    node_nowy->klucz = klucz;
    node_nowy->figura = figura;
}

void usun(node_rec *& head, int klucz)
{
    node_rec *tymcz, *drugi;
    drugi = head->next;
    if (head->next == head && head->klucz == klucz)
    {
        tymcz = head;
        head = NULL;
        free(tymcz);
        return;
    }
    if (drugi->klucz == klucz)
    {
        tymcz = drugi;
        head->next = drugi->next;
        free(tymcz);
        return;
    }
    while (drugi->next != head)
    {
        if (drugi->next->klucz == klucz)
        {
            tymcz = drugi->next;
            drugi->next = tymcz->next;
            free(tymcz);
            return;
        }
        drugi = drugi->next;
    }
    if (drugi->next->klucz == klucz)
    {
        tymcz = drugi->next;
        drugi->next = head->next;
        free(tymcz);
        head = drugi;
        return;
    }
}

void usun_wszystko(node_rec * head)
{
    node_rec * p;
    int i=0;
    p = head;
    if(p)
    {
        do
        {
            if(p->klucz != 0)
            {
                int element=p->klucz;
                usun(head,element);
            }
            p = p->next;
            i++;
        }
        while(p != head);
    }
}
};

void menu(node_rec * head, Lista lista)
{
    cout << "1. Dodawanie figur" << endl;
    cout << "2. Usuwanie figur" << endl;
    cout << "4. Wyswietl wszystkie figury" << endl;
    cout << "8. Wyjscie" << endl;
    int wybor;
    wybor = _getch();
    system("cls");
    if(wybor=='1')
    {
        int x,y,a;
        string b;
        cout << "Podaj x" << endl;
        cin >> x;
        cout << "Podaj y" << endl;
        cin >> y;
        cout << "Podaj a" << endl;
        cin >> a;
        cout << "Podaj b" << endl;
        cin >> b;
        Prostokat pro(x,y,a,b);
        Figura *wsk = &pro;
        lista.insertuj(head,wsk);
        system("cls");
        return;
    }
    else if(wybor=='2')
    {
        cout << "Wszystkie elementy:" << endl;
        int szukana=0;
        lista.drukuj(head,szukana);
        cout << "Ktory element usunac?" << endl;
        int klucz;
        cin >> klucz;
        if(klucz>0)
        {
            lista.usun(head, klucz);
        }
        cout << "Usunieto!" << endl;
        getch();
    }

    else if(wybor=='4')
    {
        cout << "Wszystkie elementy:" << endl;
        int szukana=0,prostokaty=0,trojkaty=0,kola=0,trapezy=0;
        prostokaty = lista.drukuj(head,1);
        trojkaty = lista.drukuj(head,2);
        kola = lista.drukuj(head,3);
        trapezy = lista.drukuj(head,4);
        system("cls");
        lista.drukuj(head,szukana);
        cout << "Ilosc prostokatow: " << prostokaty << endl;
        cout << "Ilosc trojkatow: " << trojkaty << endl;
        cout << "Ilosc kol: " << kola << endl;
        cout << "Ilosc trapezow: " << trapezy << endl;
        getch();
    }


    else if(wybor=='8')
    {
        lista.usun_wszystko(head);
        return;
    }
    else return;
    system("cls");
    return;
}

int main()
{
    Lista lista;
    node_rec * head;
    head = NULL;
    Figura *wsk = NULL;
    lista.insertuj(head,wsk);
    while(1)
    {
        menu(head, lista);
        //system("cls");
    }

    return 0;
}
