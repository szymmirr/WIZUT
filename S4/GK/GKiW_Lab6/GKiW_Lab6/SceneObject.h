#pragma once

// Element sceny - klasa abstrakcyjna, która w za³o¿eniu powinna byæ
// klas¹ bazow¹ dla wszystkich elementów sceny.
// Dziêki temu, ¿e wszystkie obiekty bêd¹ dziedziczy³y po tej klasie,
// mo¿liwe jest choæby wygodne trzymanie ujednoliconej ich listy.
class CSceneObject
{
public:
	vec3 Position; // Pozycja obiektu na scenie.
	vec3 Rotation; // Rotacja (trzy k¹ty) obiektu na scenie.
	char *Name; // Nazwa obiektu u³atwiaj¹ca ich rozpoznawanie (g³ównie programiœcie).

	CSceneObject(void); // Konstruktor.
	~CSceneObject(void); // Destruktor.
	virtual void Initialize(void) = 0; // Inicjalizacja obiektu - wywo³ana raz na pocz¹tku.
	virtual void Update(void) = 0; // Aktualizacja stanu obiektu - wywo³ywana cyklicznie, np. jako timer.
	virtual void Render(void) = 0; // Rysowanie obiektu - wywo³ywane zawsze podczas rysowania tego elementu sceny.
};

