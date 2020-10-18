#pragma once

// P�aszczyzna wraz z u�ytecznymi metodami.
class CCollisionPlane {
public:

	// Jednoznaczna definicja p�aszczyzny: Ax + By + Cz + D = 0
	vec3 N; // Wektor normalny (ABC).
	float Cp; // D (-N*P0, gdzie P0 jest punktem na p�aszczy�nie a * oznacza iloczyn skalarny)

	CCollisionPlane() {
		N.Set(0.0f, 0.0f, -1.0f);
		Cp = 0.0f;
	}

	// Konstruktor - budowa z zestawu punkt�w.
	CCollisionPlane(vec3 v[]) {
		FromPoints(v);
	}

	// Konstruktor - budowa z wektora normalnego i punktu le��cego na p�aszczy�nie.
	CCollisionPlane(vec3 nN, vec3 pO) {
		FromNormalAndPoint(nN, pO);
	}

	// Budowa p�aszczyzny z trzech punkt�w na niej le��cych.
	void FromPoints(vec3 v[]) {
		vec3::Cross(v[2] - v[1], v[0] - v[1], N);
		N.Normalize();
		Cp = -N.Dot(v[0]);
	}

	// Budowa p�aszczyzny z wektora normalnego i punktu na tej p�aszczy�nie.
	void FromNormalAndPoint(vec3 nN, vec3 pO) {
		N = nN;
		N.Normalize();
		Cp = -N.Dot(pO);
	}

	// Czy dany wektor jest skierowany w stron� przedniej strony p�aszczyzny, lub jest do niej r�wnoleg�y?
	bool IsFrontFacingTo(vec3 v) {
		return N.Dot(v) <= 0.0f;
	}

	// Najkr�tsza odleg�o�� zadanego punktu do p�aszczyzny (ze znakiem).
	float SDistanceTo(vec3 p) {
		return p.Dot(N) + Cp;
	}
	
	// Najkr�tsza odleg�o�� zadanego punktu do p�aszczyzny (bez znaku).
	float DistanceTo(vec3 p) {
		return abs(p.Dot(N) + Cp);
	}

	// Projekcja punktu na p�aszczyzn�.
	vec3 Project(vec3 p) {
		return p - N * N.Dot(p);
	}
};
