#include <iostream>
#include <cstdlib>
#include <list>
#include <conio.h>
using namespace std;
struct Osoby
    {
        int wiek;
        string nazwisko;
    };
char menu(Osoby osoba,list<Osoby> lista);
void dodaj(Osoby osoba,list<Osoby> lista);
void usun_to(Osoby osoba,list<Osoby> lista);
void wyswietl(Osoby osoba,list<Osoby> lista);
char menu(Osoby osoba,list<Osoby> lista)
{
    system("cls");
    cout << "1. Dodaj osobe" << endl;
    cout << "2. Usun osobe" << endl;
    cout << "3. Wyswietl osoby" << endl;
    cout << "4. Wyjdz" << endl;
    char wybor=getch();
    if (wybor=='1')
    {
        dodaj(osoba,lista);
    }
    if (wybor=='2')
    {
        usun_to(osoba,lista);
    }
    if (wybor=='3')
    {
        wyswietl(osoba,lista);
    }
    if (wybor=='4')
    {
        return 0;
    }
}
void dodaj(Osoby osoba,list<Osoby> lista)
{
    system("cls");
    string podane;
    cout << "Podaj nazwisko ";
    cin >> osoba.nazwisko;
    cout << "Podaj wiek ";
    cin >> osoba.wiek;
    lista.push_back(osoba);
    menu(osoba,lista);

}
void usun_to(Osoby osoba,list<Osoby> lista)
{
    system("cls");
    int i=0;
    for(list<Osoby>::iterator it = lista.begin(); it != lista.end(); it++,i++)
    {
        cout << i+1 << ". " << (it)->nazwisko << " " << (it)->wiek << endl;
    }
    cout << "Podaj numer osoby ktora chcesz usunac ";
    int numer;
    cin >> numer;
    numer-=1;
    list<Osoby>::iterator it;
    it = lista.begin();
    while( numer-- )
    {
        it++;
    }
    lista.erase( it );
    menu(osoba,lista);
}
void wyswietl(Osoby osoba,list<Osoby> lista)
{
    system("cls");
    int i=0;
    for(list<Osoby>::iterator it = lista.begin(); it != lista.end(); it++,i++)
    {
        cout << i+1 << ". " << (it)->nazwisko << " " << (it)->wiek << endl;
    }
    getch();
    menu(osoba,lista);
}
int main()
{
    list<Osoby> lista;
    Osoby osoba;
    menu(osoba,lista);
    return 0;
}
