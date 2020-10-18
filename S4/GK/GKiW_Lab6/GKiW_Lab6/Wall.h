#pragma once

// �ciana. Jedyny element sceny w przyk�adzie, z kt�rym wykrywane b�d� kolizje.
// Jest to dowolny quad kt�rego wszystkie wierzcho�ki le�� na jednej p�aszczy�nie (wa�ne!).
// �ciana b�dzie rysowana oraz zostanie utworzony i zapami�tany czworok�t na potrzeby
// wykrywania kolizji.
class CWall : public CSceneObject
{
public:
	CWall(vec3 a, vec3 b, vec3 c, vec3 d); // Konstruktor - pozycje czterech wierzcho�k�w (musz� le�e� na jednej p�aszczy�nie!). Ich kolejno�� decyduje o zwrocie wektora normalnego. Podajemy je przeciwnie do ruchu wskaz�wek zegara.
	~CWall(void); // Destruktor.
	void Initialize(void); // Inicjalizacja (wywo�ana raz).
	void Update(void); // Aktualizacja stanu.
	void Render(void); // Rysowanie �ciany.
	CCollisionPolygon * collisionPolygon; // Polygon (a tak naprawd� po prostu czworok�t), z kt�rym b�d� wykrywane kolizje.
	vec3 v[4]; // Pozycje wierzcho�k�w.
	vec3 n; // Wektor normalny �ciany.

protected:
	GLuint _displayListId; // Id displaylisty.
	static bool _isLoaded; // Czy tekstura zosta�a ju� za�adowana (jest identyczna dla wszystkich instancji klasy)?
	static CTexture * _wallTexture; // Tekstura.
};

