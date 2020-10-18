#pragma once

// Elipsoida na potrzeby wykrywania kolizji.
class CCollisionEllipsoid {
public:

	vec3 r; // Promienie elipsoidy (trzy; po jednym dla ka¿dej osi)
	vec3 rInv; // Odwrotnoœci promieni, przydatne podczas przechodzenia do przestrzeni gdzie elipsa staje siê kul¹ o r=1.
	
	// Konstruktor, nale¿y podaæ promienie.
	CCollisionEllipsoid(float rx, float ry, float rz) {
		SetRadii(rx, ry, rz);
	}

	// Zmieñ wartoœci promieni - od razu oblicza te¿ odwrotnoœci.
	void SetRadii(float rx, float ry, float rz) {
		r.Set(rx, ry, rz);
		rInv.Set(1.0f / rx, 1.0f / ry, 1.0f / rz);
	}

};
