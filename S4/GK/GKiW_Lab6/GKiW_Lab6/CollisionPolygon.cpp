#include "stdafx.h"

void CCollisionPolygon::CheckCollision(vec3 pos0, vec3 pos1, CCollisionEllipsoid * e, SCollision &result) {
	// Sprawdzenie, czy na odcinku pos0 => pos1 dochodzi do kolizji elipsoidy e z naszym polygonem.

	// Pierwszy krok to transformacja do przestrzeni "elipsoidalnej". Przechodzimy do takiej przestrzeni,
	// w której nasza elipsoida jest kul¹ o r=1.0. Dziêki temu znacznie uproœcimy obliczenia.
	// Aby tego dokonaæ, skalujemy ka¿d¹ wspó³rzêdn¹ œwiata przez odwrotnoœæ d³ugoœci odpowiadaj¹cego promienia elipsoidy.
	// Na koniec bêdziemy musieli powróciæ do pierwotnej przestrzeni, poprzez przemno¿enie wspó³rzêdnych
	// przez NIEodwrócone d³ugoœci promieni.

	// Transformujemy po³o¿enia wierzcho³ków polygonu, "vv" bêdzie zawieraæ pozycje w nowej przestrzeni.
	vec3 * vv = new vec3[vNum];
	for (int i = 0; i < vNum; ++i) {
		vv[i] = v[i];
		vv[i].Scale(e->rInv);
	}
	// Trzeba pamiêtaæ, ¿eby przed wyjœciem z funkcji zwolniæ pamiêæ po vv!

	// Utworzenie p³aszczyzny przechodz¹cej przez punkty "vv".
	CCollisionPlane plane(vv);

	// Transformacja pocz¹tku i koñca naszego ruchu (pos0 i pos1).
	vec3 basePoint = pos0;
	vec3 destinationPoint = pos1;
	basePoint.Scale(e->rInv);
	destinationPoint.Scale(e->rInv);
	
	// Obliczenie wektora przemieszczenia w nowej przestrzeni, oraz znormalizowanego wektora kierunku.
	vec3 vel = destinationPoint - basePoint;
	vec3 velNormalized = vel;
	velNormalized.Normalize();

	// PóŸniej w razie wyst¹pienia kolizji zapiszemy pod t¹ zmienn¹ wektor kierunku,
	// w jakim powinna nast¹piæ reakcja na kolizjê (odbicie siê).
	vec3 reaction;

	#pragma region Sprawdzenie kolizji z p³aszczyzn¹ na której le¿y polygon.

		// Nie interesuj¹ nas kolizje zachodz¹ce podczas poruszania siê "zza" p³aszczyzny.
		// Inaczej mo¿e dojœæ do nieprzyjemnego blokowania siê.
		if (!plane.IsFrontFacingTo(velNormalized)) {
			delete[] vv;
			return;
		}

		float t0, t1; // Punkty pierwszego i drugiego przeciêcia powierzchni kuli z p³aszczyzn¹ (wejœcie i wyjœcie).
		bool embeddedInPlane = false;

		// Odleg³oœæ œrodka kuli (dawnej elipsy) od najbli¿szego punktu p³aszczyny.
		float distance = plane.SDistanceTo(basePoint);

		float normalDotVel = plane.N.Dot(vel);

		// Jeœli poruszamy siê równolegle do p³aszczyzny...
		if (normalDotVel == 0.0f) {
			if (abs(distance) >= 1.0f) {
				// Œrodek kuli jest dalej od p³aszczyzny, ni¿ jej d³ugoœæ promienia => nie ma kolizji.
				delete[] vv;
				return;
			}
			// W innym wypadku wnioskujemy, ¿e p³aszczyzna przecina kulê na ca³ej d³ugoœci ruchu.
			embeddedInPlane = true;
			t0 = 0.0f;
			t1 = 1.0f;
		}

		// Jeœli NIE poruszamy siê równolegle do p³aszczyzny...
		else {
			// Punkty przeciêcia dwóch punktów na powierzchni kuli z p³aszczyzn¹.
			t0 = (-1.0f - distance) / normalDotVel;
			t1 = ( 1.0f - distance) / normalDotVel;

			// Uporz¹dkowanie, aby t0 by³o zawsze mniejsz¹ z wartoœci.
			if (t0 > t1) {
				float tmp = t1;
				t1 = t0;
				t0 = tmp;
			}

			// Sprawdzenie, czy zachodzi kolizja z p³aszczyzn¹ na rozpatrywanym odcinku.
			if (t0 > 1.0f || t1 < 0.0f) {
				// t0 i t1 s¹ poza zakresem 0..1 => nie ma kolizji.
				delete[] vv;
				return;
			}

			// Clamping do przedzia³u 0..1.
			t0 = __max(0.0f, __min(1.0f, t0));
			t1 = __max(0.0f, __min(1.0f, t1));
		}

	#pragma endregion

	// Wiemy ju¿, ¿e gdzieœ dochodzi do przeciêcia/zetkniêcia kuli z p³aszczyzn¹.
	// Pozostaje "tylko" sprawdziæ, czy to miejsce znajduje siê wewn¹trz, na wierzcho³ku
	// lub krawêdzi polygonu, czy te¿ jest zupe³nie gdzie indziej i wtedy nie zachodzi kolizja.

	vec3 collisionPoint;
	float tc = 1.0f;
	bool collided = false;

	#pragma region Sprawdzenie kolizji z wnêtrzem polygonu.
	
		if (!embeddedInPlane) {
			
			// Obliczamy punkt na p³aszczyŸnie z bli¿szym (wczeœniejszym) miejscem przeciêcia kuli.
			vec3 planeIntersectionPoint = (basePoint - plane.N) + vel * t0;

			// Czy punkt znajduje siê wewn¹trz polygonu?
			if (CheckPointInPolygon(planeIntersectionPoint, vv)) {
				// Mamy kolizjê!
				tc = t0;
				collided = true;
				collisionPoint = planeIntersectionPoint; // Punktem kolizji bêdzie punkt na p³aszczyŸnie.
				reaction = plane.N; // Kierunkiem reakcji/odbicia bêdzie wektor normalny p³aszczyzny.
				
				//printf("%s: interior\n", parent->Name);
			}

		}
	
	#pragma endregion
		
	if (!collided) {

		float t = 1.0f; // Nasz najlepszy do tej pory wynik - jeœli znajdziemy kolizjê z wierzcho³kiem lub krawêdzi¹, to t siê zmniejszy.
		vec3 velocity = vel;
		vec3 base = basePoint;
		float velocityL2 = vel.Length2(); // Czêsto bêdziemy u¿ywaæ kwadratu d³ugoœci prêdkoœci, wiêc wyliczamy go raz.
		float a, b, c; // Wspó³czynniki równania kwadratowego.
		float newT; // Miejsce, gdzie bêdzie wpisywana wartoœæ nowowyliczonego "t".

		#pragma region Sprawdzenie kolizji z wierzcho³kami polygonu.

			// Wymaga rozwi¹zania równania kwadratowego dla ka¿dego z wierzcho³ków polygonu.
			// Wyt³umaczenie wspó³czynników a, b, c znaleŸæ mo¿na w sugerowanej literaturze.

			a = velocityL2; // "a" jest wspólne dla wszystkich wierzcho³ków.

			// Dla ka¿dego wierzcho³ka rozwi¹¿emy równanie z innymi "b" i "c".
			for (int i = 0; i < vNum; ++i) {
				b = 2.0f * (velocity.Dot(base - vv[i]));
				c = (vv[i] - base).Length2() - 1.0f;
				if (CCollisionDetection::GetSmallestPositiveQuadEqSolution(a, b, c, t, newT)) {
					// Uda³o siê znaleŸæ lepsze od poprzedniego rozwi¹zanie. Mamy kolizjê!
					t = newT;
					tc = t;
					collided = true;
					collisionPoint = vv[i]; // Miejscem kolizji bêdzie wierzcho³ek.
					reaction = basePoint - collisionPoint; // Kierunkiem reakcji bêdzie kierunek pomiêdzy œrodkiem kuli a wierzcho³kiem.
					
					//printf("%s: vertex\n", parent->Name);
				}
			}

		#pragma endregion

		#pragma region Sprawdzenie kolizji z krawêdziami polygonu.

			// Wymaga rozwi¹zania równania kwadratowego dla ka¿dej z krawêdzi polygonu.
			// Wyt³umaczenie wspó³czynników a, b, c znaleŸæ mo¿na w sugerowanej literaturze.

			for (int i = 0; i < vNum; ++i) {
				vec3 e = vv[(i + 1) % vNum] - vv[i];
				vec3 btv = vv[i] - base;
				float eL2 = e.Length2();
				float edv = e.Dot(velocity);
				float edbtv = e.Dot(btv);
				a = -eL2 * velocityL2 + edv * edv;
				b = eL2 * 2.0f * velocity.Dot(btv) - 2.0f * edv * edbtv;
				c = eL2 * (1.0f - btv.Length2()) + edbtv * edbtv;
			
				// Je¿eli ten komentarz siê tutaj znajduje, to znaczy
				// ¿e ktoœ nawet nie próbowa³ przejrzeæ i zrozumieæ kodu (taki ma³y ¿arcik).

				if (CCollisionDetection::GetSmallestPositiveQuadEqSolution(a, b, c, t, newT)) {
					
					// Obliczamy wspó³czynnik okreœlaj¹cy odleg³oœæ od jednego wierzcho³ka krawêdzi do drugiego,
					// odpowiadaj¹cy odleg³oœci po której jest miejsce wyst¹pienia kolizji.
					float f = (edv * newT - edbtv) / eL2;

					// Jeœli jesteœmy w obrêbie krawêdzi (f=0..1)...
					if (f >= 0.0f && f <= 1.0f) {
						//...to mamy kolizjê!
						t = newT;
						tc = t;
						collided = true;
						collisionPoint = vv[i] + e * f; // Miejscem kolizji jest punkt oddalony o "f" od pierwszego z wierzcho³ków krawêdzi, w stronê drugiego z wierzcho³ków.
						reaction = basePoint - collisionPoint; // Kierunkiem reakcji bêdzie kierunek pomiêdzy œrodkiem kuli a miejscem kolizji.
						//printf("%s: edge\n", parent->Name);
					}
				}
			}

		#pragma endregion

	}

	#pragma region Ustawienie odpowiedzi o kolizji.
		
		if (collided) {

			// Odleg³oœæ od punktu startowego, po której nastêpuje znaleziona kolizja (w pierwotnej przestrzeni!).
			float distToCollision = tc * (pos1 - pos0).Length();

			// Czy znaleziona kolizja jest bli¿sza od poprzednio uznanej za najbli¿sz¹?
			// (lub czy do tej pory jeszcze nie znaleziono ¿adnej?)
			if (!result.hasCollided || result.distance > distToCollision) {
				
				// Powracamy do pierwotnej przestrzeni.
				reaction.Scale(e->r);
				reaction.Normalize();
				collisionPoint.Scale(e->r);

				result.hasCollided = true; // Dosz³o do kolizji!
				result.target = this; // Z czym dosz³o do kolizji?
				result.t = tc; // Wspó³czynnik 0..1 przemieszczenia po jakim nastêpuje kolizja.
				result.distance = distToCollision; // Odleg³oœæ któr¹ mo¿na przebyæ do wyst¹pienia kolizji.
				result.planeIntersectionPosition = collisionPoint; // Punkt przeciêcia z polygonem - miejsce kolizji.
				result.reaction = reaction; // Kierunek reakcji na kolizjê.

			}
		}

	#pragma endregion

	delete[] vv;

}

bool CCollisionPolygon::CheckPointInPolygon(vec3 p, vec3 *vv) {
	// Test "Point In Polygon", czyli sprawdzenie czy zadany punkt le¿y wewn¹trz wielok¹ta.
	// Metoda doœæ brzydka, ale do bólu prosta. Sprawdzenie, czy suma k¹tów pomiêdzy
	// zadanym punktem a kolejnymi parami wierzcho³ków jest równa 2*PI. Jeœli punkt bêdzie
	// poza wielok¹tem, suma k¹tów bêdzie inna. ¯eby zrozumieæ, wystarczy zrobiæ sobie prosty rysunek.
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
