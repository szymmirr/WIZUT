#pragma once

class CSceneObject;

// Wielok¹t s³u¿¹cy do wykrywania kolizji oraz metody do tego przydatne.
class CCollisionPolygon {
public:

	vec3 * v; // Tablica wierzcho³ków polygonu.
	int vNum; // Liczba wierzcho³ków.

	CSceneObject * parent; // Element sceny, do którego przynale¿y polygon.

	// Konstruktor - utworzenie polygonu na podstawie tablicy wierzcho³ków.
	// Wszystkie wierzcho³ki musz¹ le¿eæ na jednej p³aszczyŸnie!
	CCollisionPolygon(vec3 nV[], int nVNum) {
		parent = NULL;
		vNum = nVNum;
		v = new vec3[vNum];
		for (int i = 0; i < vNum; ++i) {
			v[i] = nV[i];
		}
	}
	
	// Destruktor - sprz¹tanie œwiata.
	~CCollisionPolygon() {
		delete[] v;
	}

	// Sprawdzenie, czy na odcinku pos0 => pos1 dochodzi do kolizji elipsoidy e z naszym polygonem.
	void CheckCollision(vec3 pos0, vec3 pos1, CCollisionEllipsoid * e, SCollision &result);

	// Sprawdzenie, czy punkt p le¿y wewn¹trz naszego polygonu.
	bool CheckPointInPolygon(vec3 p, vec3 *vv);

};
