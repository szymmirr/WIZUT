#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
using namespace std;

class Adres
{
protected:
    Adres(char* ulica1, char* kodpocz1, char* miasto1, char* woj1, char* ulicafirmy1, char* kodpoczfirmy1, char* miastofirmy1, char* wojfirmy1);
public:
    char ulica[50], kodpocz[50], miasto[50], woj[50], ulicafirmy[50], kodpoczfirmy[50], miastofirmy[50], wojfirmy[50];
    virtual int Drukuj(int szukana, int kluczyk, char* slowo)=0;
    virtual int Jaki()=0;
};
Adres::Adres(char* ulica1, char* kodpocz1, char* miasto1, char* woj1, char* ulicafirmy1, char* kodpoczfirmy1, char* miastofirmy1, char* wojfirmy1)
{
    strcpy(ulica,ulica1);
    strcpy(kodpocz,kodpocz1);
    strcpy(miasto,miasto1);
    strcpy(woj,woj1);
    strcpy(ulicafirmy,ulicafirmy1);
    strcpy(kodpoczfirmy,kodpoczfirmy1);
    strcpy(miastofirmy,miastofirmy1);
    strcpy(wojfirmy,wojfirmy1);
}

class Firma
{
protected:
    int Jaki()
    {
        return 1;
    }
public:
    char nazwafirmy[50], nip[50];
    Firma(char* nazwafirmy1, char* nip1);
    ~Firma();
};
Firma::Firma(char* nazwafirmy1, char* nip1)
{
    strcpy(nazwafirmy,nazwafirmy1);
    strcpy(nip,nip1);
}
Firma::~Firma()
{

}

class Osoba
{
protected:
    char imie[50], nazwisko[50], pesel[11];
    Adres* adres;
    Firma* firma;
    /*void setAdres(Adres* _adres)
    {
        adres=_adres;
    }*/
    /*void setFirma(Firma* _firma)
    {
        firma=_firma;
    }*/
    int Jaki()
    {
        return 1;
    }
public:
    int Drukuj(int szukana, int kluczyk, char* slowo)
    {
        if(szukana==1)
        {
            string nazw=nazwisko;
            string slow=slowo;
            if(nazw==slow)
            {
                return kluczyk;
            }
        }
        if (szukana==0||szukana==1)
        {
            cout << kluczyk << ". " << endl;
            cout << "Imie: " << imie << endl;
            cout << "Nazwisko: " << nazwisko << endl;
            cout << "Pesel: " << pesel << endl;
            cout << "Ulica zamieszkania: " << adres->ulica << endl;
            cout << "Kod pocztowy adresu zamieszkania: " << adres->kodpocz << endl;
            cout << "Miasto zamieszkania: " << adres->miasto << endl;
            cout << "Wojewodztwo: " << adres->woj << endl;
            cout << "Nazwa firmy zatrudniajacej: " << firma->nazwafirmy << endl;
            cout << "Nip firmy zatrudniajacej: " << firma->nip << endl;
            cout << "Ulica firmy zatrudniajacej: " << adres->ulicafirmy << endl;
            cout << "Kod pocztowy firmy zatrudniajacej: " << adres->kodpoczfirmy << endl;
            cout << "Miasto firmy zatrudniajacej: " << adres->miastofirmy << endl;
            cout << "Wojewodztwo firmy zatrudniajacej: " << adres->wojfirmy << endl << endl;
        }
    }
public:
    Osoba(char* imie1, char* nazwisko1, char* pesel1, char* ulica1, char* kodpocz1, char* miasto1, char* woj1, char* nazwafirmy1, char* nip1, char* ulicafirmy1, char* kodpoczfirmy1, char* miastofirmy1, char* wojfirmy1);
    ~Osoba();
};
Osoba::Osoba(char* imie1, char* nazwisko1, char* pesel1, char* ulica1, char* kodpocz1, char* miasto1, char* woj1, char* nazwafirmy1, char* nip1, char* ulicafirmy1, char* kodpoczfirmy1, char* miastofirmy1, char* wojfirmy1)
{
    strcpy(imie,imie1);
    strcpy(nazwisko,nazwisko1);
    strcpy(pesel,pesel1);
}
Osoba::~Osoba()
{

}

class Wyjatki
{
public:
    void zlypesel(char* pesel)
    {
        if(pesel[10]=='Z')
        {
            string zly = "Zly pesel!";
            throw zly;
        }
    }
    ~Wyjatki();
};
Wyjatki::~Wyjatki()
{

}

class Lista
{
protected:
    struct node_rec
    {
        int klucz;
        Osoba *osoba;
        struct node_rec *next;
    };
    node_rec * head = NULL;
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
    int drukuj(int szukana, char* slowo)
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
                    wynik = p->osoba->Drukuj(szukana,kluczyk,slowo);
                    {
                        if(szukana==1)
                        {
                            usun(wynik);
                            cout << "Usunieto!" << endl;
                        }
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

void insertuj(Osoba *& osoba)
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
    node_nowy->osoba = osoba;
}

void usun(int klucz)
{
    node_rec *tymcz, *drugi;
    drugi = head->next;
    if (head->next == head && head->klucz == klucz)
    {
        tymcz = head;
        head = NULL;
        delete tymcz;
        free(tymcz);
        return;
    }
    if (drugi->klucz == klucz)
    {
        tymcz = drugi;
        head->next = drugi->next;
        delete tymcz;
        free(tymcz);
        return;
    }
    while (drugi->next != head)
    {
        if (drugi->next->klucz == klucz)
        {
            tymcz = drugi->next;
            drugi->next = tymcz->next;
            delete tymcz;
            free(tymcz);
            return;
        }
        drugi = drugi->next;
    }
    if (drugi->next->klucz == klucz)
    {
        tymcz = drugi->next;
        drugi->next = head->next;
        delete tymcz;
        free(tymcz);
        head = drugi;
        return;
    }
}

void usun_wszystko()
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
                usun(element);
            }
            p = p->next;
            i++;
        }
        while(p != head);
    }
}
};

void menu(Lista lista)
{
    cout << "1. Dodawanie osoby" << endl;
    cout << "2. Usuwanie osoby" << endl;
    cout << "3. Wyswietl wszystkie osoby" << endl;
    cout << "4. Wyjscie" << endl;
    int wybor;
    wybor = _getch();
    system("cls");
    if(wybor=='1')
    {
        char imie[50], nazwisko[50], pesel[11], ulica[50], kodpocz[50], miasto[50], woj[50], nazwafirmy[50], nip[50], ulicafirmy[50], kodpoczfirmy[50], miastofirmy[50], wojfirmy[50];
        cout << "Podaj imie" << endl;
        cin >> imie;
        cout << "Podaj nazwisko" << endl;
        cin >> nazwisko;
        int dobrze=1;
        do
        {
            cout << "Podaj pesel" << endl;
            cin >> pesel;
            dobrze=1;
            Wyjatki wyjatek;
            try
            {
                wyjatek.zlypesel(pesel);
            }
            catch(string komunikat)
            {
                cout<<komunikat<<endl;
                dobrze=0;
            }
        }
        while(dobrze==0);
        cout << "Podaj ulice zamieszkania" << endl;
        cin >> ulica;
        cout << "Podaj kod pocztowy adresu zamieszkania" << endl;
        cin >> kodpocz;
        cout << "Podaj miasto zamieszkania" << endl;
        cin >> miasto;
        cout << "Podaj wojewodztwo zamieszkania" << endl;
        cin >> woj;
        cout << "Podaj nazwe firmy zatrudniajacej" << endl;
        cin >> nazwafirmy;
        cout << "Podaj nip firmy zatrudniajacej" << endl;
        cin >> nip;
        cout << "Podaj ulice firmy zatrudniajacej" << endl;
        cin >> ulicafirmy;
        cout << "Podaj kod pocztowy firmy zatrudniajacej" << endl;
        cin >> kodpoczfirmy;
        cout << "Podaj miasto firmy zatrudniajacej" << endl;
        cin >> miastofirmy;
        cout << "Podaj wojewodztwo firmy zatrudniajacej" << endl;
        cin >> wojfirmy;
        Osoba oso(imie, nazwisko, pesel, ulica, kodpocz, miasto, woj, nazwafirmy, nip, ulicafirmy, kodpoczfirmy, miastofirmy, wojfirmy);
        Osoba *wsk = &oso;
        lista.insertuj(wsk);
    }
    else if(wybor=='2')
    {
        cout << "Wszystkie elementy:" << endl;
        int szukana=1;
        char slowo[50];
        cout << "Podaj nazwisko osoby ktora chcesz usunac" << endl;
        cin >> slowo;
        int numerek = lista.drukuj(szukana, slowo);
        getch();
    }
    else if(wybor=='3')
    {
        cout << "Wszystkie elementy:" << endl;
        char slowo[50];
        int szukana=0;
        system("cls");
        lista.drukuj(szukana,slowo);
        getch();
    }
    else if(wybor=='4')
    {
        lista.usun_wszystko();
        exit(0);
    }
    system("cls");
    menu(lista);
}

int main()
{
    Lista lista;
    Osoba *wsk = NULL;
    lista.insertuj(wsk);
    while(1)
    {
        menu(lista);
    }
    return 0;
}
