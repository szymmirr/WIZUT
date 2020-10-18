#pragma once

// Scena - Jest to podstawowy element organizuj¹cy hierarchiê obiektów w grze.
// Z za³o¿enia, w danym momencie powinna istnieæ tylko jedna scena.
// W sytuacji gdy scen mo¿e byæ wiêcej, dobrze jest utworzyæ klasy dziedzicz¹ce po tej.
class CScene
{
public:
	
	CSkydome * Skydome; // Skydome - niebo.
	CTerrain * Terrain; // Teren - czyli w naszym przyk³adzie trawiasty quad.
	CPlayer Player; // Stan gracza.

	// Wszystkie obiekty na scenie, wektor na podstawie którego bêdzie mo¿na
	// po nich ³atwo iterowaæ, np. w celu ich narysowania.
	vector<CSceneObject *> * Objects;

	CScene(void); // Konstruktor.
	~CScene(void); // Destruktor.
	void Initialize(void); // Inicjalizacja (wywo³ywana raz).
	void Update(void); // Aktualizacja œwiata.
	void Render(void); // Rysowanie ca³ej sceny.
	
	bool DrawCollisions; // Czy maj¹ byæ rysowane kolizje (do debugowania, klawisz "K")?
	bool DrawNormals; // Czy maj¹ byæ rysowane wektory normalne (do debugowania, klawisz "N")?
	vec3 LastCollisionPoint; // Pozycja ostatniej kolizji.
	bool MarkCollision; // Czy ju¿ zaistnia³a jakakolwiek kolizja warta narysowania?

};

