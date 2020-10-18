#include "stdafx.h"

void CCollisionPolygon::CheckCollision(vec3 pos0, vec3 pos1, CCollisionEllipsoid * e, SCollision &result) {
	// Sprawdzenie, czy na odcinku pos0 => pos1 dochodzi do kolizji elipsoidy e z naszym polygonem.

	// Pierwszy krok to transformacja do przestrzeni "elipsoidalnej". Przechodzimy do takiej przestrzeni,
	// w kt�rej nasza elipsoida jest kul� o r=1.0. Dzi�ki temu znacznie upro�cimy obliczenia.
	// Aby tego dokona�, skalujemy ka�d� wsp�rz�dn� �wiata przez odwrotno�� d�ugo�ci odpowiadaj�cego promienia elipsoidy.
	// Na koniec b�dziemy musieli powr�ci� do pierwotnej przestrzeni, poprzez przemno�enie wsp�rz�dnych
	// przez NIEodwr�cone d�ugo�ci promieni.

	// Transformujemy po�o�enia wierzcho�k�w polygonu, "vv" b�dzie zawiera� pozycje w nowej przestrzeni.
	vec3 * vv = new vec3[vNum];
	for (int i = 0; i < vNum; ++i) {
		vv[i] = v[i];
		vv[i].Scale(e->rInv);
	}
	// Trzeba pami�ta�, �eby przed wyj�ciem z funkcji zwolni� pami�� po vv!

	// Utworzenie p�aszczyzny przechodz�cej przez punkty "vv".
	CCollisionPlane plane(vv);

	// Transformacja pocz�tku i ko�ca naszego ruchu (pos0 i pos1).
	vec3 basePoint = pos0;
	vec3 destinationPoint = pos1;
	basePoint.Scale(e->rInv);
	destinationPoint.Scale(e->rInv);
	
	// Obliczenie wektora przemieszczenia w nowej przestrzeni, oraz znormalizowanego wektora kierunku.
	vec3 vel = destinationPoint - basePoint;
	vec3 velNormalized = vel;
	velNormalized.Normalize();

	// P�niej w razie wyst�pienia kolizji zapiszemy pod t� zmienn� wektor kierunku,
	// w jakim powinna nast�pi� reakcja na kolizj� (odbicie si�).
	vec3 reaction;

	#pragma region Sprawdzenie kolizji z p�aszczyzn� na kt�rej le�y polygon.

		// Nie interesuj� nas kolizje zachodz�ce podczas poruszania si� "zza" p�aszczyzny.
		// Inaczej mo�e doj�� do nieprzyjemnego blokowania si�.
		if (!plane.IsFrontFacingTo(velNormalized)) {
			delete[] vv;
			return;
		}

		float t0, t1; // Punkty pierwszego i drugiego przeci�cia powierzchni kuli z p�aszczyzn� (wej�cie i wyj�cie).
		bool embeddedInPlane = false;

		// Odleg�o�� �rodka kuli (dawnej elipsy) od najbli�szego punktu p�aszczyny.
		float distance = plane.SDistanceTo(basePoint);

		float normalDotVel = plane.N.Dot(vel);

		// Je�li poruszamy si� r�wnolegle do p�aszczyzny...
		if (normalDotVel == 0.0f) {
			if (abs(distance) >= 1.0f) {
				// �rodek kuli jest dalej od p�aszczyzny, ni� jej d�ugo�� promienia => nie ma kolizji.
				delete[] vv;
				return;
			}
			// W innym wypadku wnioskujemy, �e p�aszczyzna przecina kul� na ca�ej d�ugo�ci ruchu.
			embeddedInPlane = true;
			t0 = 0.0f;
			t1 = 1.0f;
		}

		// Je�li NIE poruszamy si� r�wnolegle do p�aszczyzny...
		else {
			// Punkty przeci�cia dw�ch punkt�w na powierzchni kuli z p�aszczyzn�.
			t0 = (-1.0f - distance) / normalDotVel;
			t1 = ( 1.0f - distance) / normalDotVel;

			// Uporz�dkowanie, aby t0 by�o zawsze mniejsz� z warto�ci.
			if (t0 > t1) {
				float tmp = t1;
				t1 = t0;
				t0 = tmp;
			}

			// Sprawdzenie, czy zachodzi kolizja z p�aszczyzn� na rozpatrywanym odcinku.
			if (t0 > 1.0f || t1 < 0.0f) {
				// t0 i t1 s� poza zakresem 0..1 => nie ma kolizji.
				delete[] vv;
				return;
			}

			// Clamping do przedzia�u 0..1.
			t0 = __max(0.0f, __min(1.0f, t0));
			t1 = __max(0.0f, __min(1.0f, t1));
		}

	#pragma endregion

	// Wiemy ju�, �e gdzie� dochodzi do przeci�cia/zetkni�cia kuli z p�aszczyzn�.
	// Pozostaje "tylko" sprawdzi�, czy to miejsce znajduje si� wewn�trz, na wierzcho�ku
	// lub kraw�dzi polygonu, czy te� jest zupe�nie gdzie indziej i wtedy nie zachodzi kolizja.

	vec3 collisionPoint;
	float tc = 1.0f;
	bool collided = false;

	#pragma region Sprawdzenie kolizji z wn�trzem polygonu.
	
		if (!embeddedInPlane) {
			
			// Obliczamy punkt na p�aszczy�nie z bli�szym (wcze�niejszym) miejscem przeci�cia kuli.
			vec3 planeIntersectionPoint = (basePoint - plane.N) + vel * t0;

			// Czy punkt znajduje si� wewn�trz polygonu?
			if (CheckPointInPolygon(planeIntersectionPoint, vv)) {
				// Mamy kolizj�!
				tc = t0;
				collided = true;
				collisionPoint = planeIntersectionPoint; // Punktem kolizji b�dzie punkt na p�aszczy�nie.
				reaction = plane.N; // Kierunkiem reakcji/odbicia b�dzie wektor normalny p�aszczyzny.
				
				//printf("%s: interior\n", parent->Name);
			}

		}
	
	#pragma endregion
		
	if (!collided) {

		float t = 1.0f; // Nasz najlepszy do tej pory wynik - je�li znajdziemy kolizj� z wierzcho�kiem lub kraw�dzi�, to t si� zmniejszy.
		vec3 velocity = vel;
		vec3 base = basePoint;
		float velocityL2 = vel.Length2(); // Cz�sto b�dziemy u�ywa� kwadratu d�ugo�ci pr�dko�ci, wi�c wyliczamy go raz.
		float a, b, c; // Wsp�czynniki r�wnania kwadratowego.
		float newT; // Miejsce, gdzie b�dzie wpisywana warto�� nowowyliczonego "t".

		#pragma region Sprawdzenie kolizji z wierzcho�kami polygonu.

			// Wymaga rozwi�zania r�wnania kwadratowego dla ka�dego z wierzcho�k�w polygonu.
			// Wyt�umaczenie wsp�czynnik�w a, b, c znale�� mo�na w sugerowanej literaturze.

			a = velocityL2; // "a" jest wsp�lne dla wszystkich wierzcho�k�w.

			// Dla ka�dego wierzcho�ka rozwi��emy r�wnanie z innymi "b" i "c".
			for (int i = 0; i < vNum; ++i) {
				b = 2.0f * (velocity.Dot(base - vv[i]));
				c = (vv[i] - base).Length2() - 1.0f;
				if (CCollisionDetection::GetSmallestPositiveQuadEqSolution(a, b, c, t, newT)) {
					// Uda�o si� znale�� lepsze od poprzedniego rozwi�zanie. Mamy kolizj�!
					t = newT;
					tc = t;
					collided = true;
					collisionPoint = vv[i]; // Miejscem kolizji b�dzie wierzcho�ek.
					reaction = basePoint - collisionPoint; // Kierunkiem reakcji b�dzie kierunek pomi�dzy �rodkiem kuli a wierzcho�kiem.
					
					//printf("%s: vertex\n", parent->Name);
				}
			}

		#pragma endregion

		#pragma region Sprawdzenie kolizji z kraw�dziami polygonu.

			// Wymaga rozwi�zania r�wnania kwadratowego dla ka�dej z kraw�dzi polygonu.
			// Wyt�umaczenie wsp�czynnik�w a, b, c znale�� mo�na w sugerowanej literaturze.

			for (int i = 0; i < vNum; ++i) {
				vec3 e = vv[(i + 1) % vNum] - vv[i];
				vec3 btv = vv[i] - base;
				float eL2 = e.Length2();
				float edv = e.Dot(velocity);
				float edbtv = e.Dot(btv);
				a = -eL2 * velocityL2 + edv * edv;
				b = eL2 * 2.0f * velocity.Dot(btv) - 2.0f * edv * edbtv;
				c = eL2 * (1.0f - btv.Length2()) + edbtv * edbtv;
			
				// Je�eli ten komentarz si� tutaj znajduje, to znaczy
				// �e kto� nawet nie pr�bowa� przejrze� i zrozumie� kodu (taki ma�y �arcik).

				if (CCollisionDetection::GetSmallestPositiveQuadEqSolution(a, b, c, t, newT)) {
					
					// Obliczamy wsp�czynnik okre�laj�cy odleg�o�� od jednego wierzcho�ka kraw�dzi do drugiego,
					// odpowiadaj�cy odleg�o�ci po kt�rej jest miejsce wyst�pienia kolizji.
					float f = (edv * newT - edbtv) / eL2;

					// Je�li jeste�my w obr�bie kraw�dzi (f=0..1)...
					if (f >= 0.0f && f <= 1.0f) {
						//...to mamy kolizj�!
						t = newT;
						tc = t;
						collided = true;
						collisionPoint = vv[i] + e * f; // Miejscem kolizji jest punkt oddalony o "f" od pierwszego z wierzcho�k�w kraw�dzi, w stron� drugiego z wierzcho�k�w.
						reaction = basePoint - collisionPoint; // Kierunkiem reakcji b�dzie kierunek pomi�dzy �rodkiem kuli a miejscem kolizji.
						//printf("%s: edge\n", parent->Name);
					}
				}
			}

		#pragma endregion

	}

	#pragma region Ustawienie odpowiedzi o kolizji.
		
		if (collided) {

			// Odleg�o�� od punktu startowego, po kt�rej nast�puje znaleziona kolizja (w pierwotnej przestrzeni!).
			float distToCollision = tc * (pos1 - pos0).Length();

			// Czy znaleziona kolizja jest bli�sza od poprzednio uznanej za najbli�sz�?
			// (lub czy do tej pory jeszcze nie znaleziono �adnej?)
			if (!result.hasCollided || result.distance > distToCollision) {
				
				// Powracamy do pierwotnej przestrzeni.
				reaction.Scale(e->r);
				reaction.Normalize();
				collisionPoint.Scale(e->r);

				result.hasCollided = true; // Dosz�o do kolizji!
				result.target = this; // Z czym dosz�o do kolizji?
				result.t = tc; // Wsp�czynnik 0..1 przemieszczenia po jakim nast�puje kolizja.
				result.distance = distToCollision; // Odleg�o�� kt�r� mo�na przeby� do wyst�pienia kolizji.
				result.planeIntersectionPosition = collisionPoint; // Punkt przeci�cia z polygonem - miejsce kolizji.
				result.reaction = reaction; // Kierunek reakcji na kolizj�.

			}
		}

	#pragma endregion

	delete[] vv;

}

bool CCollisionPolygon::CheckPointInPolygon(vec3 p, vec3 *vv) {
	// Test "Point In Polygon", czyli sprawdzenie czy zadany punkt le�y wewn�trz wielok�ta.
	// Metoda do�� brzydka, ale do b�lu prosta. Sprawdzenie, czy suma k�t�w pomi�dzy
	// zadanym punktem a kolejnymi parami wierzcho�k�w jest r�wna 2*PI. Je�li punkt b�dzie
	// poza wielok�tem, suma k�t�w b�dzie inna. �eby zrozumie�, wystarczy zrobi� sobie prosty rysunek.
	float angle = 0.0f;
	for (int i = 0; i < vNum; ++i) {
		vec3 a = vv[i] - p;
		vec3 b = vv[(i + 1) % vNum] - p;
		float albl = a.Length() * b.Length();
		angle += acos(a.Dot(b) / albl);
	}
	if (abs(angle - PI * 2.0f) > .01f) {
		return false;
	}
	return true;
}
