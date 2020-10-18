#pragma once

class CCollisionPolygon;

// Struktura przechowuj�ca informacje o zaistnia�ej kolizji.
struct SCollision {
	
	bool hasCollided; // Czy dosz�o do kolizji?
	vec3 reaction; // Wektor kierunku reakcji na kolizj�.
	float t; // Wsp�czynnik okre�laj�cy cz�� zak�adanego wektora przemieszczenia, kt�r� mo�na przeby� bez kolizji.
	float distance; // Odleg�o�� w jednostkach �wiata, po kt�rej dosz�o do kolizji.
	vec3 planeIntersectionPosition; // Pozycja punktu na p�aszczy�nie, z kt�rym nast�pi�a kolizja.
	CCollisionPolygon * target; // Polygon z kt�rym dosz�o do kolizji.
	
	SCollision() {
		hasCollided = false;
	}

};
