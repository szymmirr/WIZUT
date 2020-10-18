#pragma once

class CCollisionPolygon;

// Struktura przechowuj¹ca informacje o zaistnia³ej kolizji.
struct SCollision {
	
	bool hasCollided; // Czy dosz³o do kolizji?
	vec3 reaction; // Wektor kierunku reakcji na kolizjê.
	float t; // Wspó³czynnik okreœlaj¹cy czêœæ zak³adanego wektora przemieszczenia, któr¹ mo¿na przebyæ bez kolizji.
	float distance; // Odleg³oœæ w jednostkach œwiata, po której dosz³o do kolizji.
	vec3 planeIntersectionPosition; // Pozycja punktu na p³aszczyŸnie, z którym nast¹pi³a kolizja.
	CCollisionPolygon * target; // Polygon z którym dosz³o do kolizji.
	
	SCollision() {
		hasCollided = false;
	}

};
