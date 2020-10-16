#include <iostream>
#include <cstdio>
using namespace std;

typedef int TypDanychT;

class CKlasa
{
public:
    CKlasa( TypDanychT wartosc )
        : m_wartosc( wartosc )
    { }

    CKlasa & operator =( const TypDanychT & argument )
    {
        return * this;
    }
    CKlasa operator +( const TypDanychT & wartosc ) const
    {
        printf( "Obiekt ma wartosc %d, a wartosc argumentu wynosi %d\n", m_wartosc, wartosc );
        return CKlasa( m_wartosc + wartosc );
    }
    private:
    TypDanychT m_wartosc;
}; //class CKlasa

int main()
{
    //CKlasa klasa;
    TypDanychT wartosc;

    //klasa = wartosc;

    CKlasa a( 5 );
    printf( "Wynik: %d\n",( a + 6 ).get() );
    printf( "Wynik: %d\n",( a + 7 ).get() );
    printf( "Wynik: %d\n",( a + 8 ).get() );
    return 0;
}
