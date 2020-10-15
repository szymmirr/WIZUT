#pragma once
#include "Effect.h"
#include "Model.h"
#include "Texture2D.h"
#include "Camera.hpp"
#include "RenderTarget2D.h"
#include "Quad.h"
using namespace std;

class Game {
	Quad* quad;
	Texture2D* tex;
	RenderTarget2D* rtTMO;
	RenderTarget2D* rt;

	Model* testModel;
	float posX;
	float posY;
	float posX2;
	float posY2;
	float rotate;
	float rotate2;
	float height;
	float speed;
	//float horizontal;

	Model* sceneModelBox;
	int sceneWidth;
	int sceneHeight;

	Model* myModel;
	Texture2D* myTex;


	Effect* shaderColor;
	Effect* shaderTMO;
	Effect* shaderTextureDrawer;
	Camera camera;
	glm::vec3 LightPosition;
	float theta;
public:
	Game(void);
	~Game(void);
	void Update();
	void Init();
	void Redraw();
	void Input();
	void drawScene(void);
};