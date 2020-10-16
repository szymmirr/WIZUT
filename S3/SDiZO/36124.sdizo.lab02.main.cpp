//SDIZO IS1 221B LAB02
//Szymon Mirr
//smirr@wi.zut.edu.pl
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node_rec{
  int klucz;
  char b;
  double c;
  struct node_rec *next;
};

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

void wyswietl(node_rec * head)
{
    int i=0;
    node_rec * p = head;
    if(p)
    {
        do
        {
            if(p->klucz != 0)
            cout << p->klucz << " ";
            p = p->next;
            if(i == 20)
            {
                cout << endl << endl;
                return;
            }
            i++;
        }
        while(p != head);
    }
}

void insertuj(node_rec *& head, int klucz)
{
    if (!head)
    {
        head = new node_rec();
        head->next = head;
        return;
    }
    if(sprawdz(head, klucz)==1)
    {
        return;
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
    node_nowy->c = 1 + rand() %( 20000 - 1 );
    node_nowy->b = 'Z';
}

void losowanie(node_rec *& head, int n)
{
    srand( time( 0 ) );
    for(int i=0; i<n; i++)
    {
        int wylosowana = 10 + rand() %( 20000 - 10 );
        insertuj(head, wylosowana);
    }
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

void wyszukaj(node_rec * head, int klucz)
{
    node_rec * p;
    p = head;
    if(p)
    {
    do
    {
        if(p->klucz == klucz)
        {
            cout << "Znaleziono element " << klucz << endl << endl;
            return;
        }
        p = p->next;
    }
    while(p != head);
    }
    cout << "Nie znaleziono elementu " << klucz << endl << endl;
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

int main()
{
    clock_t begin, end;
    begin = clock();
    fstream plik;
    plik.open("inlab02.txt");
    int n,k1,k2,k3,k4,k5;
    plik >> n >> k1 >> k2 >> k3 >> k4 >> k5;
    node_rec * head;
    head = NULL;
    wyszukaj(head,k1);
    losowanie(head,n);
    wyswietl(head);
    insertuj(head,k2);
    wyswietl(head);
    insertuj(head,k3);
    wyswietl(head);
    insertuj(head,k4);
    wyswietl(head);
    insertuj(head,k5);
    usun(head,k3);
    wyswietl(head);
    usun(head,k2);
    wyswietl(head);
    usun(head,k5);
    wyszukaj(head,k5);
    usun_wszystko(head);
    plik.close();
    end = clock();
    cout << "Czas: " << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
