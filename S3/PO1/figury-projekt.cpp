#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
using namespace std;

class Figura
{
protected:
    char x[50],y[50];
    Figura(char* xx, char* yy);
public:
    virtual int Drukuj(int szukana, int kluczyk)=0;
    virtual void Drukuj_plik(ofstream & plik)=0;
    virtual void Modyfikuj(char* xxx,char* yyy,char* aaa,char* bbb,char* hhh,char* nnn)=0;
    virtual int Jaki()=0;
};
Figura::Figura(char* xx, char* yy)
{
    strcpy(x,xx);
    strcpy(y,yy);
}

class Prostokat : public Figura
{
protected:
    char a[50],b[50];
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
    void Modyfikuj(char* xxx,char* yyy,char* aaa,char* bbb,char* hhh,char* nnn)
    {
        strcpy(x,xxx);
        strcpy(y,yyy);
        strcpy(a,aaa);
        strcpy(b,bbb);
    }
    void Drukuj_plik(ofstream & plik)
    {
        plik<<"pro "<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
    }
public:
    Prostokat(char* xx, char* yy, char* aa, char* bb);
};
Prostokat::Prostokat(char* xx, char* yy, char* aa, char* bb) : Figura(xx,yy)
{
    strcpy(a,aa);
    strcpy(b,bb);
}

class Trojkat : public Figura
{
protected:
    char a[50],h[50];
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
    void Modyfikuj(char* xxx,char* yyy,char* aaa,char* bbb,char* hhh,char* nnn)
    {
        strcpy(x,xxx);
        strcpy(y,yyy);
        strcpy(a,aaa);
        strcpy(h,hhh);
    }
    void Drukuj_plik(ofstream & plik)
    {
        plik<<"tro "<<x<<" "<<y<<" "<<a<<" "<<h<<endl;
    }
public:
    Trojkat(char* xx, char* yy, char* aa, char* hh);
};
Trojkat::Trojkat(char* xx, char* yy, char* aa, char* hh) : Figura(xx,yy)
{
    strcpy(a,aa);
    strcpy(h,hh);
}

class Kolo : public Figura
{
protected:
    char n[50];
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
    void Modyfikuj(char* xxx,char* yyy,char* aaa,char* bbb,char* hhh,char* nnn)
    {
        strcpy(x,xxx);
        strcpy(y,yyy);
        strcpy(n,nnn);
    }
    void Drukuj_plik(ofstream & plik)
    {
        plik<<"kol "<<x<<" "<<y<<" "<<n<<endl;
    }
public:
    Kolo(char* xx, char* yy, char* nn);
};
Kolo::Kolo(char* xx, char* yy, char* nn) : Figura(xx,yy)
{
    strcpy(n,nn);
}

class Trapez : public Figura
{
protected:
    char a[50],b[50],h[50];
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
    void Modyfikuj(char* xxx,char* yyy,char* aaa,char* bbb,char* hhh,char* nnn)
    {
        strcpy(x,xxx);
        strcpy(y,yyy);
        strcpy(a,aaa);
        strcpy(b,bbb);
        strcpy(h,hhh);
    }
    void Drukuj_plik(ofstream & plik)
    {
        plik<<"tra "<<x<<" "<<y<<" "<<a<<" "<<b<<" "<<h<<endl;
    }
public:
    Trapez(char* xx, char* yy, char* aa, char* bb, char* hh);
};
Trapez::Trapez(char* xx, char* yy, char* aa, char* bb, char* hh) : Figura(xx,yy)
{
    strcpy(a,aa);
    strcpy(b,bb);
    strcpy(h,hh);
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

void modyfikuj(node_rec * head,int klucz,int x,int y,int a,int b,int h,int n)
{
    int i=0;
    node_rec * p = head;
    if(p)
    {
        do
        {
            if(p->klucz == klucz)
            {
                //p->figura->Modyfikuj(x,y,a,b,h,n);
            }
            p = p->next;
            i++;
        }
        while(p != head);
    }
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

void zapisz(node_rec * head)
{
    ofstream plik;
    plik.open("zapis.txt");
    int i=0;
    node_rec * p = head;
    if(p)
    {
        do
        {
            if(p->klucz != 0)
            {
                p->figura->Drukuj_plik(plik);
            }
            p = p->next;
            i++;
        }
        while(p != head);
    }
    plik.close();
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
    cout << "3. Wyszukiwanie figur" << endl;
    cout << "4. Wyswietl wszystkie figury" << endl;
    cout << "5. Zapis do pliku" << endl;
    cout << "6. Odczyt z pliku" << endl;
    cout << "7. Modyfikuj figure" << endl;
    cout << "8. Wyjscie" << endl;
    int wybor;
    wybor = _getch();
    system("cls");
    if(wybor=='1')
    {
        cout << "Co chcesz dodac?" << endl;
        cout << "1. Prostokat" << endl;
        cout << "2. Trojkat" << endl;
        cout << "3. Kolo" << endl;
        cout << "4. Trapez" << endl;
        cout << endl << "5. Powrot" << endl;
        wybor = _getch();
        if(wybor=='1')
        {
            char x[50],y[50],a[50],b[50];
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
        }
        else if(wybor=='2')
        {
            char x[50],y[50],a[50],h[50];
            cout << "Podaj x" << endl;
            cin >> x;
            cout << "Podaj y" << endl;
            cin >> y;
            cout << "Podaj a" << endl;
            cin >> a;
            cout << "Podaj h" << endl;
            cin >> h;
            Trojkat tro(x,y,a,h);
            Figura *wsk = &tro;
            lista.insertuj(head,wsk);
        }
        else if(wybor=='3')
        {
            char x[50],y[50],n[50];
            cout << "Podaj x" << endl;
            cin >> x;
            cout << "Podaj y" << endl;
            cin >> y;
            cout << "Podaj n" << endl;
            cin >> n;
            Kolo kol(x,y,n);
            Figura *wsk = &kol;
            lista.insertuj(head,wsk);
        }
        else if(wybor=='4')
        {
            char x[50],y[50],a[50],b[50],h[50];
            cout << "Podaj x" << endl;
            cin >> x;
            cout << "Podaj y" << endl;
            cin >> y;
            cout << "Podaj a" << endl;
            cin >> a;
            cout << "Podaj b" << endl;
            cin >> b;
            cout << "Podaj h" << endl;
            cin >> h;
            Trapez tra(x,y,a,b,h);
            Figura *wsk = &tra;
            lista.insertuj(head,wsk);
        }
        else return;
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
    else if(wybor=='3')
    {
        cout << "Co chcesz wyszukac?" << endl;
        cout << "1. Prostokat" << endl;
        cout << "2. Trojkat" << endl;
        cout << "3. Kolo" << endl;
        cout << "4. Trapez" << endl;
        cout << endl << "5. Powrot" << endl;
        wybor = _getch();
        if(wybor=='1')
        {
            int szukana=1;
            lista.drukuj(head,szukana);
            getch();
        }
        else if(wybor=='2')
        {
            int szukana=2;
            lista.drukuj(head,szukana);
            getch();
        }
        else if(wybor=='3')
        {
            int szukana=3;
            lista.drukuj(head,szukana);
            getch();
        }
        else if(wybor=='4')
        {
            int szukana=4;
            lista.drukuj(head,szukana);
            getch();
        }
        else menu(head, lista);
    }
    else if(wybor=='4')
    {
        cout << "Wszystkie elementy:" << endl;
        int szukana=0,prostokaty=0,trojkaty=0,kola=0,trapezy=0;
        //prostokaty = lista.drukuj(head,1);
        //trojkaty = lista.drukuj(head,2);
        //kola = lista.drukuj(head,3);
        //trapezy = lista.drukuj(head,4);
        system("cls");
        lista.drukuj(head,szukana);
        //cout << "Ilosc prostokatow: " << prostokaty << endl;
        //cout << "Ilosc trojkatow: " << trojkaty << endl;
        //cout << "Ilosc kol: " << kola << endl;
        //cout << "Ilosc trapezow: " << trapezy << endl;
        getch();
    }
    else if(wybor=='5')
    {
        lista.zapisz(head);
        cout << "Zapisano!" << endl;
        getch();
    }
    /*else if(wybor=='6')
    {
        ifstream plik;
        plik.open("odczyt.txt");
        string jakafigura;
        while(1)
        {
            plik >> jakafigura;
            if(plik.eof()) break;
            if(jakafigura=="pro")
            {
                int x,y,a,b;
                plik >> x;
                plik >> y;
                plik >> a;
                plik >> b;
                Prostokat pro(x,y,a,b);
                Figura *wsk = &pro;
                lista.insertuj(head,wsk);
            }
            else if(jakafigura=="tro")
            {
                int x,y,a,h;
                plik >> x;
                plik >> y;
                plik >> a;
                plik >> h;
                Trojkat tro(x,y,a,h);
                Figura *wsk = &tro;
                lista.insertuj(head,wsk);
            }
            else if(jakafigura=="kol")
            {
                int x,y,n;
                plik >> x;
                plik >> y;
                plik >> n;
                Kolo kol(x,y,n);
                Figura *wsk = &kol;
                lista.insertuj(head,wsk);
            }
            else if(jakafigura=="tra")
            {
                int x,y,a,b,h;
                plik >> x;
                plik >> y;
                plik >> a;
                plik >> b;
                plik >> h;
                Trapez tra(x,y,a,b,h);
                Figura *wsk = &tra;
                lista.insertuj(head,wsk);
            }
            else
            {
                break;
            }
        }
        plik.close();
        cout << "Wczytano!" <<endl;
        getch();
    }*/
    else if(wybor=='7')
    {
        cout << "Wszystkie elementy:" << endl;
        int szukana=0;
        lista.drukuj(head,szukana);
        cout << "Ktory element chcesz zmodyfikowac?" << endl;
        int klucz;
        cin >> klucz;
        int x,y,a,b,h,n;
        if(lista.jaki(head,klucz)==1)
        {
            cout << "Podaj x" << endl;
            cin >> x;
            cout << "Podaj y" << endl;
            cin >> y;
            cout << "Podaj a" << endl;
            cin >> a;
            cout << "Podaj b" << endl;
            cin >> b;
        }
        if(lista.jaki(head,klucz)==2)
        {
            cout << "Podaj x" << endl;
            cin >> x;
            cout << "Podaj y" << endl;
            cin >> y;
            cout << "Podaj a" << endl;
            cin >> a;
            cout << "Podaj h" << endl;
            cin >> h;
        }
        if(lista.jaki(head,klucz)==3)
        {
            cout << "Podaj x" << endl;
            cin >> x;
            cout << "Podaj y" << endl;
            cin >> y;
            cout << "Podaj n" << endl;
            cin >> n;
        }
        if(lista.jaki(head,klucz)==4)
        {
            cout << "Podaj x" << endl;
            cin >> x;
            cout << "Podaj y" << endl;
            cin >> y;
            cout << "Podaj a" << endl;
            cin >> a;
            cout << "Podaj b" << endl;
            cin >> b;
            cout << "Podaj h" << endl;
            cin >> h;
        }
        if(klucz>0)
        {
            lista.modyfikuj(head,klucz,x,y,a,b,h,n);
        }
        cout<<"Zmodyfikowano!"<<endl;
        getch();
    }
    else if(wybor=='8')
    {
        lista.usun_wszystko(head);
        return;
    }
    else menu(head, lista);
    system("cls");
    menu(head, lista);
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
    }
    return 0;
}
