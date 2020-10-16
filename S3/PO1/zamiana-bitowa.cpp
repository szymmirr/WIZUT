#include <iostream>
#include <cstdlib>
using namespace std;

char* mnozenie(int liczba)
{
	char *wynik;
	wynik = (char*)malloc(32 * sizeof(char));
	for (int i = 31; i >= 0; i--)
	{
		wynik[i] = (liczba >> i) & 1;
	}
	return(wynik);
}
int main()
{
	int liczba;
	char *wsk;
	cout << "Podaj liczbe";
	cin >> liczba;
	wsk = mnozenie(liczba);
	for (int i = 31; i >= 0; i--)
	{
		cout << (int)wsk[i];
	}
	free(wsk);
	cout<<endl;
	for (int i = 31; i >= 0; i--)
	{
		cout << (int)wsk[i];
	}
	return 0;
}
