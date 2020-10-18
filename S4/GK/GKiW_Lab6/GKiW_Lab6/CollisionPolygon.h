#pragma once

class CSceneObject;

// Wielok�t s�u��cy do wykrywania kolizji oraz metody do tego przydatne.
class CCollisionPolygon {
public:

	vec3 * v; // Tablica wierzcho�k�w polygonu.
	int vNum; // Liczba wierzcho�k�w.

	CSceneObject * parent; // Element sceny, do kt�rego przynale�y polygon.

	// Konstruktor - utworzenie polygonu na podstawie tablicy wierzcho�k�w.
	// Wszystkie wierzcho�ki musz� le�e� na jednej p�aszczy�nie!
	CCollisionPolygon(vec3 nV[], int nVNum) {
		parent = NULL;
		vNum = nVNum;
		v = new vec3[vNum];
		for (int i = 0; i < vNum; ++i) {
			v[i] = nV[i];
		}
	}
	
	// Destruktor - sprz�tanie �wiata.
	~CCollisionPolygon() {
		delete[] v;
	}

	// Sprawdzenie, czy na odcinku pos0 => pos1 dochodzi do kolizji elipsoidy e z naszym polygonem.
	void CheckCollision(vec3 pos0, vec3 pos1, CCollisionEllipsoid * e, SCollision &result);

	// Sprawdzenie, czy punkt p le�y wewn�trz naszego polygonu.
	bool CheckPointInPolygon(vec3 p, vec3 *vv);

};
