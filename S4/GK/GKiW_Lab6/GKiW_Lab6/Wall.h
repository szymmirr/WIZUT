#pragma once

// Œciana. Jedyny element sceny w przyk³adzie, z którym wykrywane bêd¹ kolizje.
// Jest to dowolny quad którego wszystkie wierzcho³ki le¿¹ na jednej p³aszczyŸnie (wa¿ne!).
// Œciana bêdzie rysowana oraz zostanie utworzony i zapamiêtany czworok¹t na potrzeby
// wykrywania kolizji.
class CWall : public CSceneObject
{
public:
	CWall(vec3 a, vec3 b, vec3 c, vec3 d); // Konstruktor - pozycje czterech wierzcho³ków (musz¹ le¿eæ na jednej p³aszczyŸnie!). Ich kolejnoœæ decyduje o zwrocie wektora normalnego. Podajemy je przeciwnie do ruchu wskazówek zegara.
	~CWall(void); // Destruktor.
	void Initialize(void); // Inicjalizacja (wywo³ana raz).
	void Update(void); // Aktualizacja stanu.
	void Render(void); // Rysowanie œciany.
	CCollisionPolygon * collisionPolygon; // Polygon (a tak naprawdê po prostu czworok¹t), z którym bêd¹ wykrywane kolizje.
	vec3 v[4]; // Pozycje wierzcho³ków.
	vec3 n; // Wektor normalny œciany.

protected:
	GLuint _displayListId; // Id displaylisty.
	static bool _isLoaded; // Czy tekstura zosta³a ju¿ za³adowana (jest identyczna dla wszystkich instancji klasy)?
	static CTexture * _wallTexture; // Tekstura.
};

