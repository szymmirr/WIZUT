//#define GLM_FORCE_RADIANS

#include "Game.h"
#include "3rd\glm\gtc\matrix_transform.hpp"
#include "3rd\glm\glm.hpp"
#include "Content.h"
#include "Keyboard.h"

Game::Game(void)
{

}

Game::~Game(void)
{
}

// inicjalizacja parametrow renderingu
void Game::Init()
{

	// parametry polozenia i ruchu gracza
	sceneWidth = 10;
	sceneHeight = 8;
	rotate = -90;
	speed = 0.05f; // predkosc ruchu czajnika
	posX = 0.0f;
	posY = 0.0f;
	posX2 = 0;
	posY2 = 0;
	rotate2 = 0;
	height = 0;

	theta = 1.0f;
	Effect::ShadersDirectory = "";
	glClearColor(0.6f, 0.5f, 1.0f, 1.0f);

	//stworzenie figury (quada) do wyœwietlania render targetów
	quad = new Quad();

	// wczytanie tekstury
	tex = Content::LoadTexture("../resources/test.png");

	// wczytanie modelu
	testModel = Content::LoadModel("../resources/teaPot.ASE");

	//ustawienie materia³u
	glm::mat4x4 mm;
	for (int i = 0; i < testModel->Elements(); i++)
	{
		//ustawienie koloru materia³u dla pobranego modelu
		testModel->GetMesh(i)->GetMaterial().Color = glm::vec3(1, 1, 0);
		//podmiana tekstury w modelu
		testModel->GetMesh(i)->GetMaterial().texture = tex;

		mm = testModel->GetMesh(i)->getLocalWorld();
	}

	// drugi model (sciany na scenie)
	sceneModelBox = Content::LoadModel("../resources/cube.ASE");
	for (int i = 0; i < sceneModelBox->Elements(); i++) {
		sceneModelBox->GetMesh(i)->GetMaterial().Color = glm::vec3(0.5f, 0.5f, 0.5f);
	}

	// wczytanie tekstury
	myTex = Content::LoadTexture("../resources/gun.png");

	// wczytanie modelu
	myModel = Content::LoadModel("../resources/gun.3ds");

	for (int i = 0; i < myModel->Elements(); i++)
	{
		//ustawienie koloru materia³u dla pobranego modelu
		myModel->GetMesh(i)->GetMaterial().Color = glm::vec3(1, 1, 0);
		//podmiana tekstury w modelu
		myModel->GetMesh(i)->GetMaterial().texture = myTex;
	}

	//////////////////////////////////////// RENDER TARGETS
	rtTMO = new RenderTarget2D(800, 600, GL_RGBA8, GL_RGBA, GL_UNSIGNED_INT, GL_DEPTH24_STENCIL8);
	rt = new RenderTarget2D(800, 600, GL_RGBA32F, GL_RGBA, GL_FLOAT, GL_DEPTH24_STENCIL8);


	/////////////////////////////////////// SHADERS
	// wczytanie i inicjalizacja shadera obliczajacego kolor powierzchni obiektu
	// wczytuje shadery (wspiera jedynie fragment (.ps) i vertex shadery (.vs), wystarczy podaæ nazwê pliku bez rozszerzenia)
	shaderColor = new Effect("shaders/color");
	// kompilacja shadera, alteratywnie mo¿na wykorzystaæ CreateShaderInfo, ktory wypisze w konsoli dane nt. shadera oraz ewnetualne b³êdy.
	shaderColor->CreateShader();

	// wczytanie i inicjalizacja shadera obliczajacego mapowanie tonow
	shaderTMO = new Effect("shaders/tmo");
	shaderTMO->CreateShader();

	// wczytanie i inicjalizacja shadera renderujacego obraz do framebuffera
	shaderTextureDrawer = new Effect("shaders/texture");
	shaderTextureDrawer->CreateShader();


	/////////////////////////////////////// KAMERA
	// ustawienie parametrów kamery (konstruktor przyjmuje rozdzielczoœæ viewportu),
	// domyœlny field of view to 45*, mo¿na zmieniæ metod¹ SetFOV(float)
	camera = Camera(800, 600);
	camera.setPosition(glm::vec3(0, 0, 15));
	camera.setTarget(glm::vec3(0, 0, 0));
	//camera.setFOV( 60.0f );

	// polozenie zrodla swiatla
	LightPosition = glm::vec3(10, 10, 10);
}

// obsluga klawiatury, zmiana parametrow renderingu
void Game::Update()
{
	//posX2 = 0;
	theta += 0.02f;
	if (Keyboard::isPressed('W'))
	{
		LightPosition.z += 0.1f;
	}
	if (Keyboard::isPressed('S'))
	{
		LightPosition.z -= 0.1f;
	}
	if (Keyboard::isPressed('A'))
	{
		LightPosition.x -= 0.1f;
	}
	if (Keyboard::isPressed('D'))
	{
		LightPosition.x += 0.1f;
	}
	if (Keyboard::isPressed('I')) {
		posX2 = posX2 + 0.07f;
	}
	if (Keyboard::isPressed('K')) {
		posX2 = posX2 - 0.07f;
	}
	if (Keyboard::isPressed('J')) {
		rotate2 -= 1.0f;
	}
	if (Keyboard::isPressed('L')) {
		rotate2 += 1.0f;
	}
	if (Keyboard::isPressed('T')) {
		height += 0.1f;
	}
	if (Keyboard::isPressed('G')) {
		height -= 0.1f;
	}

	if (Keyboard::isPressed(GLFW_KEY_UP)) {
		posX = posX + speed * (float)cos(rotate * 3.14 / 180.0f);
		posY = posY - speed * (float)sin(rotate * 3.14 / 180.0f);
	}
	if (Keyboard::isPressed(GLFW_KEY_DOWN)) {
		posX = posX - speed * (float)cos(rotate * 3.14 / 180.0f);
		posY = posY + speed * (float)sin(rotate * 3.14 / 180.0f);
	}

	if (Keyboard::isPressed(GLFW_KEY_RIGHT)) {
		rotate += 1.0f;
	}
	if (Keyboard::isPressed(GLFW_KEY_LEFT)) {
		rotate -= 1.0f;
	}

	if (Keyboard::isPressed(GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(glfwGetCurrentContext(), GL_TRUE);
	}

	// zmiana parametrow kamery w czasie ruchu
	camera.setPosition(glm::vec3(posX, posY, 0.6));

	glm::mat4 camRot = glm::rotate(glm::mat4(1.0f), (rotate + 90), glm::vec3(0.0f, 0.0f, 1.0f));
	glm::vec4 up = camRot * glm::vec4(0, 1, 0, 1);

	float upX = (float)cos((rotate) * 3.14 / 180);
	float upY = (float)sin((rotate) * 3.14 / 180);
	camera.setUp(glm::vec3(upX, -upY, 0));

	float camTZ = 0;
	float camTY = posY - 3 * upY;
	float camTX = posX + 3 * upX;
	camera.setTarget(glm::vec3(camTX, camTY, camTZ));

}


// rysowanie planszy gry skladajacej sie z obiektow sceneModelBox
void Game::drawScene(void) {

	int i = 0;

	shaderColor->GetParameter("matColor")->SetValue(sceneModelBox->GetMesh(i)->GetMaterial().Color);
	shaderColor->GetParameter("mode")->SetValue(-1.0f);

	for (int yy = 0; yy < this->sceneHeight; yy++)
		for (int xx = 0; xx < this->sceneWidth; xx++) {

			if (xx != 0 && xx != (this->sceneWidth - 1) && yy > 0 && yy < (this->sceneHeight - 1))
				continue;

			this->shaderColor->GetParameter("World")->SetValue(
				sceneModelBox->GetMesh(i)->getLocalWorld() *
				glm::translate(glm::mat4(1.0f), glm::vec3(-(float)this->sceneWidth / 2.0f, -(float)this->sceneHeight / 2.0f, 0.0f)) *
				glm::translate(glm::mat4(1.0f), glm::vec3((float)xx, 0.0f, 0.0f)) *
				glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, (float)yy, 0.0f)) *
				//glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, -0.2f + posX2, 1.8f)) *
				glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f)) *
				glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(0.0f, 1.0f, 0.0f)) *
				//glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(1.0f, 1.0f, 0.0f)) *
				glm::scale(glm::mat4(1.0f), glm::vec3(0.01f, 0.01f, 0.01f)) 
				//glm::scale(glm::mat4(1.0f), glm::vec3(0.04f, 0.01f, 0.01f))
			);

			// rysowanie modelu
			sceneModelBox->GetMesh(i)->Draw();

		}
}


// rysowanie sceny (glowna petla)
void Game::Redraw()
{
	//ustawienie textury do ktorej chcemy renderowaæ
	rt->SetRenderTarget();
	glClearColor(0.6f, 0.5f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//ustawienie shadera e jako aktywnego
	shaderColor->Apply();
	//ustawienie macierzy widoku i projekcji
	shaderColor->GetParameter("View")->SetValue(camera.getView());
	shaderColor->GetParameter("Projection")->SetValue(camera.getProjection());
	//ustawienie pozycji œwiat³a i camery
	shaderColor->GetParameter("LightPosition")->SetValue(LightPosition);
	shaderColor->GetParameter("EyePosition")->SetValue(camera.getPosition());

	int i = 0;

	//ustawienie koloru materia³u
	shaderColor->GetParameter("matColor")->SetValue(testModel->GetMesh(i)->GetMaterial().Color);

	if (testModel->GetMesh(i)->GetMaterial().texture != NULL)
	{
		//jeœli mamy teksturê to j¹ bindujemy i ustawiamy tryb teskturowania w shaderze
		shaderColor->GetParameter("mode")->SetValue(1.0f);
		shaderColor->GetParameter("tex")->SetValue(*testModel->GetMesh(i)->GetMaterial().texture);
	}
	if (myModel->GetMesh(i)->GetMaterial().texture != NULL)
	{
		//jeœli mamy teksturê to j¹ bindujemy i ustawiamy tryb teskturowania w shaderze
		shaderColor->GetParameter("mode")->SetValue(1.0f);
		shaderColor->GetParameter("tex")->SetValue(*myModel->GetMesh(i)->GetMaterial().texture);
	}
	else
	{
		//w³¹czenie trybu bez tekstury
		shaderColor->GetParameter("mode")->SetValue(-1.0f);
	}

	// ustawienie transformacji obiektu
	// model mo¿e siê sk³adaæ z kilku czêœci (meshy) które znajduj¹ siê w przestrzeni lokalnej modelu,
	// musimy skorygowaæ ich pozycjê i przekszta³ciæ do przestrzeni naszego œwiata,
	// w tym celu wyci¹gamy macierz transformacji mesha testModel->GetMesh(i)->getLocalWorld(),
	// a nastêpnie przekszta³camy w podobny sposób jak w starszych wersjach OpenGL

	for (int i = 0; i < testModel->Elements(); i++) {

		shaderColor->GetParameter("World")->SetValue(

			testModel->GetMesh(i)->getLocalWorld() *
			glm::translate(glm::mat4(1.0f), glm::vec3(posX, posY, 0)) *
			glm::rotate(glm::mat4(1.0f), -rotate, glm::vec3(0.0f, 0.0f, 1.0f)) *
			glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f)) *

			glm::scale(glm::mat4(1.0f), glm::vec3(0.1, 0.1, 0.1))
		);

		// rysowanie modelu
		//testModel->GetMesh(i)->Draw();
	}

	for (int i = 0; i < myModel->Elements(); i++) {

		this->shaderColor->GetParameter("World")->SetValue(

			myModel->GetMesh(i)->getLocalWorld() *
			//glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, -0.2f + posX2, 1.8f)) *
			//glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(1.0f, 1.0f, 0.0f)) *
			//glm::scale(glm::mat4(1.0f), glm::vec3(0.04f, 0.01f, 0.01f)) *

			glm::translate(glm::mat4(1.0f), glm::vec3(posX2, posY2, height)) *
			glm::rotate(glm::mat4(1.0f), -rotate2, glm::vec3(0.0f, 0.0f, 1.0f)) *
			glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f)) *

			//glm::translate(glm::mat4(1.0f), glm::vec3(posX, posY, 0)) *
			//glm::rotate(glm::mat4(1.0f), -rotate, glm::vec3(0.0f, 0.0f, 1.0f)) *
			//glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f)) *

			glm::scale(glm::mat4(1.0f), glm::vec3(0.2, 0.2, 0.2))
		);

		// rysowanie modelu
		myModel->GetMesh(i)->Draw();
	}

	/*for (float j = 0; j < 1; j = j + 0.1)
	{
		for (int i = 0; i < myModel->Elements(); i++) {

			this->shaderColor->GetParameter("World")->SetValue(

				myModel->GetMesh(i)->getLocalWorld() *
				//glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, -0.2f + posX2, 1.8f)) *
				//glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(1.0f, 1.0f, 0.0f)) *
				//glm::scale(glm::mat4(1.0f), glm::vec3(0.04f, 0.01f, 0.01f)) *
				glm::translate(glm::mat4(1.0f), glm::vec3(posX2, posY2, j)) *
				//glm::rotate(glm::mat4(1.0f), -rotate, glm::vec3(0.0f, 0.0f, 1.0f)) *
				glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f)) *

				//glm::translate(glm::mat4(1.0f), glm::vec3(posX, posY, 0)) *
				//glm::rotate(glm::mat4(1.0f), -rotate, glm::vec3(0.0f, 0.0f, 1.0f)) *
				//glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f)) *

				glm::scale(glm::mat4(1.0f), glm::vec3(0.2, 0.2, 0.2))
			);

			// rysowanie modelu
			myModel->GetMesh(i)->Draw();
		}
	}*/

	// rysowanie sceny
	drawScene();

	shaderColor->GetParameter("matColor")->SetValue(myModel->GetMesh(i)->GetMaterial().Color);

	if (myModel->GetMesh(i)->GetMaterial().texture != NULL)
	{
		//jeœli mamy teksturê to j¹ bindujemy i ustawiamy tryb teskturowania w shaderze
		shaderColor->GetParameter("mode")->SetValue(1.0f);
		shaderColor->GetParameter("tex")->SetValue(*myModel->GetMesh(i)->GetMaterial().texture);
	}
	else
	{
		//w³¹czenie trybu bez tekstury
		shaderColor->GetParameter("mode")->SetValue(-1.0f);
	}

	for (int i = 0; i < myModel->Elements(); i++) {

		shaderColor->GetParameter("World")->SetValue(

			myModel->GetMesh(i)->getLocalWorld() *
			//glm::rotate(glm::mat4(1.0f), -rotate, glm::vec3(0.0f, 0.0f, 1.0f)) *
			glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f)) *
			glm::scale(glm::mat4(1.0f), glm::vec3(0.2, 0.2, 0.2))
		);

		// rysowanie modelu
		//myModel->GetMesh(i)->Draw();
	}


	// mapowanie tonow za pomoca drugiego shadera, wynik renderowany jest do drugiego render targetu (rtTMO)
	rtTMO->SetRenderTarget();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shaderTMO->Apply();
	shaderTMO->GetParameter("tex")->SetValue(*rt);
	shaderTMO->GetParameter("gamma")->SetValue(1.6f);
	quad->Draw(0, 0, 800, 600, shaderTMO->GetParameter("World"));

	//rendering na ekran (do framebuffera)
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, 800, 600);
	glClearColor(0.0, 0.0, 0.0, 0.0); //zmiana glClearColor by sprawdziæ czy faktycznie wyrenderowaliœmy coœ do tekstury
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shaderTextureDrawer->Apply();
	quad->Draw(0, 0, 800, 600, shaderTextureDrawer->GetParameter("World"));

}
