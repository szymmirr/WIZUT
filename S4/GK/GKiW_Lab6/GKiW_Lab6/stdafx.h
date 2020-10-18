// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define PI 3.14159265

#include "targetver.h"

#include <math.h>
#include <stdio.h>

#include <vector>

using namespace std;

#include <GL/freeglut.h>

#include "Vec3.h"
#include "Bitmap.h"
#include "Texture.h"

#include "CollisionDetection.h"
#include "Collision.h"
#include "CollisionEllipsoid.h"
#include "CollisionPlane.h"
#include "CollisionPolygon.h"

#include "Player.h"

#include "SceneObject.h"
#include "Skydome.h"
#include "Terrain.h"
#include "Wall.h"

#include "Scene.h"

#include "GKiW_Lab6.h"

#pragma region Zmienne globalne

	extern float T;

	extern int mouseX;
	extern int mouseY;

	extern bool captureMouse;
	extern bool free3DMovement;

	extern float mouseSensitivity;

	extern CScene * Scene;

	extern bool keystate[255];

#pragma endregion
