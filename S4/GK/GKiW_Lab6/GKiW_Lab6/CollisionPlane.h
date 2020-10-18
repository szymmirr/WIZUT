#pragma once

// P³aszczyzna wraz z u¿ytecznymi metodami.
class CCollisionPlane {
public:

	// Jednoznaczna definicja p³aszczyzny: Ax + By + Cz + D = 0
	vec3 N; // Wektor normalny (ABC).
	float Cp; // D (-N*P0, gdzie P0 jest punktem na p³aszczyŸnie a * oznacza iloczyn skalarny)

	CCollisionPlane() {
		N.Set(0.0f, 0.0f, -1.0f);
		Cp = 0.0f;
	}

	// Konstruktor - budowa z zestawu punktów.
	CCollisionPlane(vec3 v[]) {
		FromPoints(v);
	}

	// Konstruktor - budowa z wektora normalnego i punktu le¿¹cego na p³aszczyŸnie.
	CCollisionPlane(vec3 nN, vec3 pO) {
		FromNormalAndPoint(nN, pO);
	}

	// Budowa p³aszczyzny z trzech punktów na niej le¿¹cych.
	void FromPoints(vec3 v[]) {
		vec3::Cross(v[2] - v[1], v[0] - v[1], N);
		N.Normalize();
		Cp = -N.Dot(v[0]);
	}

	// Budowa p³aszczyzny z wektora normalnego i punktu na tej p³aszczyŸnie.
	void FromNormalAndPoint(vec3 nN, vec3 pO) {
		N = nN;
		N.Normalize();
		Cp = -N.Dot(pO);
	}

	// Czy dany wektor jest skierowany w stronê przedniej strony p³aszczyzny, lub jest do niej równoleg³y?
	bool IsFrontFacingTo(vec3 v) {
		return N.Dot(v) <= 0.0f;
	}

	// Najkrótsza odleg³oœæ zadanego punktu do p³aszczyzny (ze znakiem).
	float SDistanceTo(vec3 p) {
		return p.Dot(N) + Cp;
	}
	
	// Najkrótsza odleg³oœæ zadanego punktu do p³aszczyzny (bez znaku).
	float DistanceTo(vec3 p) {
		return abs(p.Dot(N) + Cp);
	}

	// Projekcja punktu na p³aszczyznê.
	vec3 Project(vec3 p) {
		return p - N * N.Dot(p);
	}
};
