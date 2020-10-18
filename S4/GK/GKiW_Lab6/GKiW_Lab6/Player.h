#pragma once

// Stan gracza.
class CPlayer {

public:
	vec3 pos;
	vec3 dir;
	vec3 cam; // Przesuniêcie punktu zaczepienia kamery wzglêdem pozycji gracza.
	float speed;
	float velRX, velRY, velM, velS;
	CCollisionEllipsoid * collisionEllipsoid; // Elipsoida s³u¿¹ca do wykrywania kolizji.

	CPlayer() {
		pos.Set(0.0f, 0.0f, 0.0f);
		dir.Set(0.0f, 0.0f, -1.0f);
		cam.Set(0.0f, 0.25f, 0.0f);
		speed = 0.0f;
		velRX = 0.0f;
		velRY = 0.0f;
		velM = 0.0f;
		velS = 0.0f;
		collisionEllipsoid = new CCollisionEllipsoid(.15f, .3f, .15f);
	}

};
