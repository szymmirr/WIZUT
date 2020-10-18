#include "stdafx.h"

vec3 CCollisionDetection::GetPositionAfterWorldCollisions(vec3 pos0, vec3 pos1, CPlayer &player, vector<CSceneObject *> * objects, int step, CCollisionPolygon * exclude) {

	// Funkcja bêdzie wywo³ywana reukrencyjnie. Jeœli poziom zagnie¿d¿enia przekroczy 10,
	// to zwracamy po prostu pos1 jako nasz¹ now¹, "zmodyfikowan¹" pozycjê.
	// Tak¿e w sytuacji, gdy d³ugoœæ naszego przewidywanego ruchu jest równa 0 (gracz stoi w miejscu),
	// to nie ma sensu wykonywaæ obliczeñ.
	if (step > 10 || (pos1 - pos0).Length() == 0.0f) {
		return pos1;
	}

	// Tu bêd¹ przechowywane dane o kolizji.
	SCollision collision;

	// SprawdŸmy, czy dochodzi do kolizji elipsoidy gracza z którymkolwiek z obiektów
	// spoœród tych przekazanych jako "objects". W miêdzyczasie zostanie zapisana informacja
	// o najbli¿szej z kolizji (jeœli jakakolwiek zostanie wykryta).
	for (int i = 0; i < objects->size(); ++i) {

		// W naszym przyk³adzie chcemy sprawdzaæ kolizje jedynie z obiektami klasy CWall, bo z nimi
		// bêdziemy wiedzieli co zrobiæ. Ten fragment na pewno nale¿y zmodyfikowaæ zale¿nie
		// od w³asnych potrzeb.

		// Rzutujemy nasz wskaŸnik na "jakiœ" obiekt na wskaŸnik na CWall.
		CWall * wall = reinterpret_cast<CWall *>(objects->at(i));

		// Jeœli u¿yliœmy reinterpret_cast zamiast zwyk³ego static_cast (lub
		// równowa¿nego zapisu (CWall*)(objects->at(i)), to w momencie gdy rzutowanie
		// nie jest mo¿liwe, otrzymamy wartoœæ NULL. Wtedy wiadomo, ¿e nie jest to na pewno
		// CWall i pomijamy ten obiekt.
		// Pomijamy te¿ obiekt jeœli jest to ten sam, co obiekt do którego adres zosta³
		// przekazany w parametrze - zostanie to u¿yte do rozwi¹zania sytuacji gdy odbicie siê
		// od jednego obiektu skutkuje odbiciem siê od drugiego.
		if (wall == NULL || wall->collisionPolygon == exclude) {
			continue;
		}

		// Wywo³ujemy sprawdzanie kolizji elipsoidy gracza z polygonem danej "œciany", na odcinku pos0 => pos1.
		// Wyniki bêd¹ zapisane w "collision", pod warunkiem ¿e wczeœniej nie znajdowa³a siê tam
		// bli¿sza kolizja.
		wall->collisionPolygon->CheckCollision(pos0, pos1, player.collisionEllipsoid, collision);
	}

	// Jeœli uda³o siê wykryæ jak¹kolwiek kolizjê (wtedy collision zawiera informacje o tej wystêpuj¹cej najbli¿ej)...
	if (collision.hasCollided) {
		
		// Ustawienie informacji o punkcie kolizji na potrzeby ewentualnego narysowania (klawisz "K").
		Scene->LastCollisionPoint = collision.planeIntersectionPosition;
		Scene->MarkCollision = true;

		// ¯¹danie wyliczenia odpowiedzi (reakcji) na kolizjê. Uaktualniona pozycja bêdzie t¹, do której
		// gracz powinien siê przemieœciæ po zaistnieniu tej kolizji.
		pos1 = CalculateReaction(pos0, pos1, collision);
		
		// Wywo³ujemy rekurencyjnie sprawdzanie i reakcjê na kolizjê, tym razem dla zaktualizowanej
		// œcie¿ki - zamiast pierwotnego pos1, mamy pozycjê po uwzglêdnieniu reakcji na dotychczas
		// znalezion¹ kolizjê. Dodatkowo w nastêpnym rozwa¿aniu pomijamy kolizje z polygonem, z którym
		// teraz j¹ wykryliœmy. Wynik zwracamy poziom wy¿ej.
		return GetPositionAfterWorldCollisions(pos0, pos1, player, objects, step + 1, collision.target);

	}

	// Jeœli nie by³o kolizji, idziemy œmia³o tam gdzie mieliœmy iœæ.
	return pos1;
}

vec3 CCollisionDetection::CalculateReaction(vec3 pos0, vec3 pos1, SCollision &collision) {

	// Offset, o który odsuwamy siê od œciany w celu unikniêcia tunelowania.
	// Jest to wartoœæ dobrana eksperymentalnie. To ona odpowiada za "skakanie" przy œcianach,
	// ale podczas jej zmniejszania dochodzi czasem do przejœcia przez œcianê.
	// Zachêcam do poszukania lepszego rozwi¹zania!
	float eps = .015f;

	vec3 vel = pos1 - pos0;
	vec3 destPoint = pos0 + vel;

	vec3 newVelocityVector;

	// Wyznaczenie p³aszczyzny, wzd³u¿ której gracz bêdzie siê poruszaæ po dotkniêciu obiektu z którym
	// nast¹pi³a kolizja.
	CCollisionPlane slidingPlane(collision.reaction, collision.planeIntersectionPosition);

	// Wyznaczenie wektora przemieszczenia odpowiadaj¹cego temu fragmentowi ruchu, który odby³by siê
	// "za powierzchni¹ œciany".
	vec3 newDestPoint = destPoint - slidingPlane.N * (slidingPlane.SDistanceTo(destPoint));
	newVelocityVector = newDestPoint - collision.planeIntersectionPosition;

	// Wyznaczenie nowej pozycji:
	pos1 = pos0 + vel * collision.t; // Doci¹gniêcie najbli¿ej do œciany.
	pos1 = pos1 + newVelocityVector; // Przesuniêcie wzd³u¿ p³aszczyzny "slidingu".
	pos1 = pos1 + collision.reaction * eps; // Odsuniêcie siê od œciany (najbrzydsza czêœæ ca³ego rozwi¹zania).

	// Zwracamy now¹ pozycjê.
	return pos1;
}

float CCollisionDetection::GetSmallestPositiveQuadEqSolution(float a, float b, float c, float xMin, float &newXMin) {
	// Rozwi¹zanie równania kwadratowego i sprawdzenie, czy któreœ z uzyskanych rozwi¹zañ jest mniejsze ni¿
	// to dotychczas uznawane za najmniejsze (xMin), przy za³o¿eniu ¿e nie interesuj¹ nas rozwi¹zania mniejsze od zera.
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
	// Rozwi¹zanie równania kwadratowego metod¹ ze szko³y œredniej (delta).
	float delta = b * b - 4.0f * a * c;
	if (delta < 0.0f) {
		return false;
	}
	float sqrDelta = sqrt(delta);
	x1 = (-b - sqrDelta) / (2.0f * a);
	x2 = (-b + sqrDelta) / (2.0f * a);
	return true;
}
