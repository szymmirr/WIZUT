#pragma once

// Element sceny - klasa abstrakcyjna, kt�ra w za�o�eniu powinna by�
// klas� bazow� dla wszystkich element�w sceny.
// Dzi�ki temu, �e wszystkie obiekty b�d� dziedziczy�y po tej klasie,
// mo�liwe jest cho�by wygodne trzymanie ujednoliconej ich listy.
class CSceneObject
{
public:
	vec3 Position; // Pozycja obiektu na scenie.
	vec3 Rotation; // Rotacja (trzy k�ty) obiektu na scenie.
	char *Name; // Nazwa obiektu u�atwiaj�ca ich rozpoznawanie (g��wnie programi�cie).

	CSceneObject(void); // Konstruktor.
	~CSceneObject(void); // Destruktor.
	virtual void Initialize(void) = 0; // Inicjalizacja obiektu - wywo�ana raz na pocz�tku.
	virtual void Update(void) = 0; // Aktualizacja stanu obiektu - wywo�ywana cyklicznie, np. jako timer.
	virtual void Render(void) = 0; // Rysowanie obiektu - wywo�ywane zawsze podczas rysowania tego elementu sceny.
};

