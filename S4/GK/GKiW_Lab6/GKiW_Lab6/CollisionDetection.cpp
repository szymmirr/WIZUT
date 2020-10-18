#include "stdafx.h"

vec3 CCollisionDetection::GetPositionAfterWorldCollisions(vec3 pos0, vec3 pos1, CPlayer &player, vector<CSceneObject *> * objects, int step, CCollisionPolygon * exclude) {

	// Funkcja b�dzie wywo�ywana reukrencyjnie. Je�li poziom zagnie�d�enia przekroczy 10,
	// to zwracamy po prostu pos1 jako nasz� now�, "zmodyfikowan�" pozycj�.
	// Tak�e w sytuacji, gdy d�ugo�� naszego przewidywanego ruchu jest r�wna 0 (gracz stoi w miejscu),
	// to nie ma sensu wykonywa� oblicze�.
	if (step > 10 || (pos1 - pos0).Length() == 0.0f) {
		return pos1;
	}

	// Tu b�d� przechowywane dane o kolizji.
	SCollision collision;

	// Sprawd�my, czy dochodzi do kolizji elipsoidy gracza z kt�rymkolwiek z obiekt�w
	// spo�r�d tych przekazanych jako "objects". W mi�dzyczasie zostanie zapisana informacja
	// o najbli�szej z kolizji (je�li jakakolwiek zostanie wykryta).
	for (int i = 0; i < objects->size(); ++i) {

		// W naszym przyk�adzie chcemy sprawdza� kolizje jedynie z obiektami klasy CWall, bo z nimi
		// b�dziemy wiedzieli co zrobi�. Ten fragment na pewno nale�y zmodyfikowa� zale�nie
		// od w�asnych potrzeb.

		// Rzutujemy nasz wska�nik na "jaki�" obiekt na wska�nik na CWall.
		CWall * wall = reinterpret_cast<CWall *>(objects->at(i));

		// Je�li u�yli�my reinterpret_cast zamiast zwyk�ego static_cast (lub
		// r�wnowa�nego zapisu (CWall*)(objects->at(i)), to w momencie gdy rzutowanie
		// nie jest mo�liwe, otrzymamy warto�� NULL. Wtedy wiadomo, �e nie jest to na pewno
		// CWall i pomijamy ten obiekt.
		// Pomijamy te� obiekt je�li jest to ten sam, co obiekt do kt�rego adres zosta�
		// przekazany w parametrze - zostanie to u�yte do rozwi�zania sytuacji gdy odbicie si�
		// od jednego obiektu skutkuje odbiciem si� od drugiego.
		if (wall == NULL || wall->collisionPolygon == exclude) {
			continue;
		}

		// Wywo�ujemy sprawdzanie kolizji elipsoidy gracza z polygonem danej "�ciany", na odcinku pos0 => pos1.
		// Wyniki b�d� zapisane w "collision", pod warunkiem �e wcze�niej nie znajdowa�a si� tam
		// bli�sza kolizja.
		wall->collisionPolygon->CheckCollision(pos0, pos1, player.collisionEllipsoid, collision);
	}

	// Je�li uda�o si� wykry� jak�kolwiek kolizj� (wtedy collision zawiera informacje o tej wyst�puj�cej najbli�ej)...
	if (collision.hasCollided) {
		
		// Ustawienie informacji o punkcie kolizji na potrzeby ewentualnego narysowania (klawisz "K").
		Scene->LastCollisionPoint = collision.planeIntersectionPosition;
		Scene->MarkCollision = true;

		// ��danie wyliczenia odpowiedzi (reakcji) na kolizj�. Uaktualniona pozycja b�dzie t�, do kt�rej
		// gracz powinien si� przemie�ci� po zaistnieniu tej kolizji.
		pos1 = CalculateReaction(pos0, pos1, collision);
		
		// Wywo�ujemy rekurencyjnie sprawdzanie i reakcj� na kolizj�, tym razem dla zaktualizowanej
		// �cie�ki - zamiast pierwotnego pos1, mamy pozycj� po uwzgl�dnieniu reakcji na dotychczas
		// znalezion� kolizj�. Dodatkowo w nast�pnym rozwa�aniu pomijamy kolizje z polygonem, z kt�rym
		// teraz j� wykryli�my. Wynik zwracamy poziom wy�ej.
		return GetPositionAfterWorldCollisions(pos0, pos1, player, objects, step + 1, collision.target);

	}

	// Je�li nie by�o kolizji, idziemy �mia�o tam gdzie mieli�my i��.
	return pos1;
}

vec3 CCollisionDetection::CalculateReaction(vec3 pos0, vec3 pos1, SCollision &collision) {

	// Offset, o kt�ry odsuwamy si� od �ciany w celu unikni�cia tunelowania.
	// Jest to warto�� dobrana eksperymentalnie. To ona odpowiada za "skakanie" przy �cianach,
	// ale podczas jej zmniejszania dochodzi czasem do przej�cia przez �cian�.
	// Zach�cam do poszukania lepszego rozwi�zania!
	float eps = .015f;

	vec3 vel = pos1 - pos0;
	vec3 destPoint = pos0 + vel;

	vec3 newVelocityVector;

	// Wyznaczenie p�aszczyzny, wzd�u� kt�rej gracz b�dzie si� porusza� po dotkni�ciu obiektu z kt�rym
	// nast�pi�a kolizja.
	CCollisionPlane slidingPlane(collision.reaction, collision.planeIntersectionPosition);

	// Wyznaczenie wektora przemieszczenia odpowiadaj�cego temu fragmentowi ruchu, kt�ry odby�by si�
	// "za powierzchni� �ciany".
	vec3 newDestPoint = destPoint - slidingPlane.N * (slidingPlane.SDistanceTo(destPoint));
	newVelocityVector = newDestPoint - collision.planeIntersectionPosition;

	// Wyznaczenie nowej pozycji:
	pos1 = pos0 + vel * collision.t; // Doci�gni�cie najbli�ej do �ciany.
	pos1 = pos1 + newVelocityVector; // Przesuni�cie wzd�u� p�aszczyzny "slidingu".
	pos1 = pos1 + collision.reaction * eps; // Odsuni�cie si� od �ciany (najbrzydsza cz�� ca�ego rozwi�zania).

	// Zwracamy now� pozycj�.
	return pos1;
}

float CCollisionDetection::GetSmallestPositiveQuadEqSolution(float a, float b, float c, float xMin, float &newXMin) {
	// Rozwi�zanie r�wnania kwadratowego i sprawdzenie, czy kt�re� z uzyskanych rozwi�za� jest mniejsze ni�
	// to dotychczas uznawane za najmniejsze (xMin), przy za�o�eniu �e nie interesuj� nas rozwi�zania mniejsze od zera.
	float x1, x2;
	if (!SolveQuadEq(a, b, c, x1, x2) || (x1 < 0.0f && x2 < 0.0f) || (x1 > xMin && x2 > xMin)) {
		return false;
	}
	float x;
	if (x1 > x2) {
		float tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
	if (x1 < 0.0f) {
		x = x2;
	}
	else {
		x = x1;
	}
	if (x < xMin) {
		newXMin = x;
		return true;
	}
	return false;
}

bool CCollisionDetection::SolveQuadEq(float a, float b, float c, float &x1, float &x2) {
	// Rozwi�zanie r�wnania kwadratowego metod� ze szko�y �redniej (delta).
	float delta = b * b - 4.0f * a * c;
	if (delta < 0.0f) {
		return false;
	}
	float sqrDelta = sqrt(delta);
	x1 = (-b - sqrDelta) / (2.0f * a);
	x2 = (-b + sqrDelta) / (2.0f * a);
	return true;
}
