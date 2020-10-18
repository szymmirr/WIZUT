#pragma once

class CPlayer;
class CSceneObject;
class CCollisionPolygon;
struct SCollision;

// Klasa dostarczaj¹ca metod przetwarzania kolizji oraz paru pomocniczych "narzêdzi".
class CCollisionDetection {
public:
	static vec3 GetPositionAfterWorldCollisions(vec3 pos0, vec3 pos1, CPlayer &player, vector<CSceneObject *> * objects, int step = 0, CCollisionPolygon * exclude = NULL);
	static vec3 CalculateReaction(vec3 pos0, vec3 pos1, SCollision &collision);
	static bool SolveQuadEq(float a, float b, float c, float &x1, float &x2);
	static float GetSmallestPositiveQuadEqSolution(float a, float b, float c, float xMin, float &newXMin);
};
