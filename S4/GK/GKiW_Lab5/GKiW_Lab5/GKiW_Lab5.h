#pragma once

#define PI 3.14159265

// Deklaracje funkcji u¿ywanych jako obs³uga zdarzeñ GLUT-a.
void OnRender();
void OnReshape(int, int);
void OnKeyPress(unsigned char, int, int);
void OnKeyDown(unsigned char, int, int);
void OnKeyUp(unsigned char, int, int);
void OnMouseMove(int, int);
void OnTimer(int);

struct vec3 {
	float x, y, z;
};

struct SCameraState {
	vec3 pos;
	vec3 dir;
	float speed;
	float velRX, velRY, velM, velS;
};
