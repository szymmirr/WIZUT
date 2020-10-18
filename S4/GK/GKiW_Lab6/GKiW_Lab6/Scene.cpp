#include "StdAfx.h"

// Konstruktor.
CScene::CScene(void)
{
	DrawCollisions = false;
	DrawNormals = false;
	MarkCollision = false;
}

// Destruktor - sprz¹tamy po sobie.
CScene::~CScene(void)
{
	if (Skydome != NULL) {
		delete Skydome;
	}
	if (Terrain != NULL) {
		delete Terrain;
	}
}

// Inicjalizacja sceny.
void CScene::Initialize(void) {
	
	#pragma region Ustawienia

		// Ustawienie wszelkiego rodzaju rzeczy, które s¹ charakterystyczne dla tej konkretnej sceny.

		glEnable(GL_LIGHT0);

		glEnable(GL_FOG);
		float gl_fogcolor[] = { 0.875f, 0.957f, 1.0f, 1.0f };
		glFogi(GL_FOG_MODE, GL_LINEAR);
		glFogfv(GL_FOG_COLOR, gl_fogcolor);
		glFogf(GL_FOG_START, -90.0f);
		glFogf(GL_FOG_END, 18.0f);

		Player.pos.x = 0.0f;
		Player.pos.y = 0.3f;
		Player.pos.z = 0.0f;

		Player.dir.x = 0.0f;
		Player.dir.y = 0.0f;
		Player.dir.z = -1.0f;

		Player.speed = .5f;

	#pragma endregion

	#pragma region Zawartosc sceny
	
		// Scena zawieraæ bêdzie skydome...
		Skydome = new CSkydome();
		Skydome->Initialize();

		// ...oraz teren.
		Terrain = new CTerrain();
		Terrain->Initialize();

		// Dodanie wszystkich obiektów sceny do wektora, po którym póŸniej bêdziemy iterowaæ chc¹c je rysowaæ.
		// Dlatego w³aœnie wygodnie jest, gdy wszystkie obiekty sceny dziedzicz¹ po jednej, wspólnej klasie bazowej (CSceneObject).

		Objects = new vector<CSceneObject *>();

		// Definicje po³o¿enia naszych œcian. Ka¿da kolejna czwórka wektorów to jeden quad.
		vec3 walls[][4] = {
			{ vec3( 1.0f,  0.0f, -3.0f), vec3( 1.0f,  1.0f, -3.0f), vec3( 0.0f,  1.0f, -3.0f), vec3( 0.0f,  0.0f, -3.0f) },
			{ vec3( 0.0f,  0.0f, -3.0f), vec3( 0.0f,  1.0f, -3.0f), vec3(-1.0f,  1.0f, -3.0f), vec3(-1.0f,  0.0f, -3.0f) },
			{ vec3(-1.0f,  0.0f, -3.0f), vec3(-1.0f,  1.0f, -3.0f), vec3(-1.0f,  1.0f, -1.0f), vec3(-1.0f,  0.0f, -1.0f) },
			{ vec3(-1.0f,  0.0f, -1.0f), vec3(-1.0f,  1.0f, -1.0f), vec3(-3.0f,  1.0f, -1.0f), vec3(-3.0f,  0.0f, -1.0f) },
			{ vec3(-3.0f,  0.0f, -1.0f), vec3(-3.0f,  1.0f, -1.0f), vec3(-1.0f,  1.0f,  1.0f), vec3(-1.0f,  0.0f,  1.0f) },
			{ vec3(-1.0f,  0.0f,  1.0f), vec3(-1.0f,  1.0f,  1.0f), vec3(-3.0f,  1.0f,  1.0f), vec3(-3.0f,  0.0f,  1.0f) },
			{ vec3(-3.0f,  0.0f,  2.0f), vec3(-3.0f,  1.0f,  2.0f), vec3(-1.0f,  1.0f,  2.0f), vec3(-1.0f,  0.0f,  2.0f) },
			{ vec3(-3.0f,  0.0f, -2.0f), vec3(-3.0f,  1.0f, -2.0f), vec3(-6.0f,  1.0f, -2.0f), vec3(-6.0f,  0.0f, -2.0f) },
			{ vec3(-3.0f,  0.0f,  1.0f), vec3(-3.0f,  1.0f,  1.0f), vec3(-3.0f,  1.0f, -2.0f), vec3(-3.0f,  0.0f, -2.0f) },
			{ vec3(-6.0f,  0.0f, -2.0f), vec3(-6.0f,  1.0f, -2.0f), vec3(-6.0f,  1.0f,  5.0f), vec3(-6.0f,  0.0f,  5.0f) },
			{ vec3(-6.0f,  0.0f,  5.0f), vec3(-6.0f,  1.0f,  5.0f), vec3(-4.0f,  1.0f,  4.0f), vec3(-4.0f,  0.0f,  4.0f) },
			{ vec3(-4.0f,  0.0f,  4.0f), vec3(-4.0f,  1.0f,  4.0f), vec3(-3.0f,  1.0f,  2.0f), vec3(-3.0f,  0.0f,  2.0f) },
			{ vec3(-5.5f,  0.0f,  0.0f), vec3(-5.0f,  0.3f,  1.0f), vec3(-4.0f,  0.3f,  1.0f), vec3(-4.0f,  0.0f,  0.0f) },
			{ vec3(-5.5f,  0.0f,  3.0f), vec3(-4.0f,  0.0f,  3.0f), vec3(-4.0f,  0.3f,  2.0f), vec3(-5.0f,  0.3f,  2.0f) },
			{ vec3(-5.0f,  0.3f,  1.0f), vec3(-5.0f,  0.3f,  2.0f), vec3(-4.0f,  0.3f,  2.0f), vec3(-4.0f,  0.3f,  1.0f) },
			{ vec3(-1.0f,  0.0f,  2.0f), vec3(-1.0f,  1.0f,  2.0f), vec3( 1.0f,  1.0f,  3.0f), vec3( 1.0f,  0.0f,  3.0f) },
			{ vec3( 1.0f,  0.0f,  3.0f), vec3( 1.0f,  1.0f,  3.0f), vec3( 4.0f,  1.0f,  0.0f), vec3( 4.0f,  0.0f,  0.0f) },
			{ vec3( 4.0f,  0.0f,  0.0f), vec3( 4.0f,  1.0f,  0.0f), vec3( 1.0f,  1.0f, -1.0f), vec3( 1.0f,  0.0f, -1.0f) },
			{ vec3( 1.0f,  0.0f, -1.0f), vec3( 1.0f,  1.0f, -1.0f), vec3( 1.0f,  1.0f, -3.0f), vec3( 1.0f,  0.0f, -3.0f) },
			{ vec3(-4.0f,  0.0f,  0.0f), vec3(-4.0f,  0.3f,  1.0f), vec3(-4.0f,  0.3f,  2.0f), vec3(-4.0f,  0.0f,  3.0f) },
			{ vec3(-5.5f,  0.0f,  0.0f), vec3(-5.5f,  0.0f,  3.0f), vec3(-5.0f,  0.3f,  2.0f), vec3(-5.0f,  0.3f,  1.0f) }
		};

		// Tyle mamy œcian.
		int N = 21;

		// Zamieniamy powy¿sz¹ tablicê na obiekty typu CWall, które dodamy do listy obiektów na scenie.
		for (int i = 0; i < N; ++i) {
			CWall *w = new CWall(walls[i][0], walls[i][1], walls[i][2], walls[i][3]);
			sprintf(w->Name, "Wall %d", i); // Nadanie nazwy, aby np. mo¿na by³o póŸniej ³atwo dowiedzieæ siê z czym mamy kolizjê.
			w->Initialize();
			Objects->push_back(w); // Dodanie do wektora rysowanych/przetwarzanych obiektów.
		}

	#pragma endregion
	
}

// Aktualizacja œwiata gry.
void CScene::Update(void) {

	#pragma region Ruch kamery

		if (captureMouse) {
			Player.velRY = -mouseSensitivity * (glutGet(GLUT_WINDOW_WIDTH) / 2 - mouseX);
			Player.velRX = mouseSensitivity * (glutGet(GLUT_WINDOW_HEIGHT) / 2 - mouseY);
			glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
		}

		if (keystate['w']) {
			Player.velM = Player.speed;
		}
		if (keystate['s']) {
			Player.velM = -Player.speed;
		}
		if (keystate['a']) {
			Player.velS = -Player.speed;
		}
		if (keystate['d']) {
			Player.velS = Player.speed;
		}
		if (keystate['q']) {
			Player.velRY = -Player.speed;
		}
		if (keystate['e']) {
			Player.velRY = Player.speed;
		}
		if (keystate['f']) {
			Player.velRX = -Player.speed;
		}
		if (keystate['c']) {
			Player.velRX = Player.speed;
		}

		float T = acos(Player.dir.y);
		float G = atan2(Player.dir.z, Player.dir.x);
		T -= Player.velRX * .03f;
		G += Player.velRY * .03f;
		Player.dir.x = sin(T) * cos(G);
		Player.dir.y = cos(T);
		Player.dir.z = sin(T) * sin(G);

		vec3 per;
		per.x = -Player.dir.z;
		per.y = 0;
		per.z = Player.dir.x;

		vec3 nextPlayerPos = Player.pos;

		nextPlayerPos.x += Player.dir.x * Player.velM * .1f;
		if (free3DMovement) {
			nextPlayerPos.y += Player.dir.y * Player.velM * .1f;
		}
		else {
			// Niby-grawitacja
			nextPlayerPos.y -= .1f;
		}
		nextPlayerPos.z += Player.dir.z * Player.velM * .1f;

		nextPlayerPos.x += per.x * Player.velS * .1f;
		if (free3DMovement) {
			nextPlayerPos.y += Player.dir.y * Player.velM * .1f;
		}
		nextPlayerPos.z += per.z * Player.velS * .1f;
		
		// Uniemo¿liwiamy zejœcie gracza poni¿ej poziomu terenu
		nextPlayerPos.y = __max(0.3f, nextPlayerPos.y);

		// Zmieniamy pozycjê gracza o wyliczony wczeœniej wektor przemieszczenia, uwzglêdniaj¹c przy tym kolizje ze œwiatem
		// "Objects" powinno byæ wektorem tylko tych obiektów, z którymi chcemy sprawdziæ kolizjê. Dobrze by³oby
		// wprowadziæ wczeœniejsz¹ fazê detekcji kolizji w oparciu np. o AABB i zawêziæ liczbê elementów Objects.
		Player.pos = CCollisionDetection::GetPositionAfterWorldCollisions(Player.pos, nextPlayerPos, Player, Objects);

		Player.velRX /= 1.2;
		Player.velRY /= 1.2;
		Player.velM /= 1.2;
		Player.velS /= 1.2;

	#pragma endregion

	#pragma region Aktualizacja obiektow sceny

		// Ró¿ne obiekty mog¹ potrzebowaæ aktualizacji - np. poruszaj¹cy siê wrogowie.
		for (int i = 0; i < Objects->size(); ++i) {
			Objects->at(i)->Update();
		}

		Terrain->Update();
		Skydome->Update();

	#pragma endregion

}

// Narysowanie sceny.
void CScene::Render(void) {

	#pragma region Kamera

		gluLookAt(
			Player.pos.x + Player.cam.x, Player.pos.y + Player.cam.y, Player.pos.z + Player.cam.z,
			Player.pos.x + Player.cam.x + Player.dir.x, Player.pos.y + Player.cam.y + Player.dir.y, Player.pos.z + Player.cam.z + Player.dir.z,
			0.0f, 1.0f, 0.0f
		);

	#pragma endregion

	#pragma region Swiatlo
	
		float l0_amb[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		float l0_dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		float l0_spe[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		float l0_pos[] = { -1.0f, .2f, 0.5f, 0.0f };
		glLightfv(GL_LIGHT0, GL_AMBIENT, l0_amb);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, l0_dif);
		glLightfv(GL_LIGHT0, GL_SPECULAR, l0_spe);
		glLightfv(GL_LIGHT0, GL_POSITION, l0_pos);

	#pragma endregion

	#pragma region Skydome

		glDisable(GL_FOG); // Nie chcemy, by nasz zawsze odleg³y skydome by³ za mg³¹, bo nie by³oby go widaæ.

		Skydome->Position = Player.pos;
		Skydome->Render();
		
		glEnable(GL_FOG);

	#pragma endregion

	#pragma region Teren

		Terrain->Render();

	#pragma endregion

	#pragma region Obiekty

		// Narysowanie wszystkich obiektów sceny (w tym przypadku - tylko œcian, ale do Objects mo¿na dodaæ te¿ wszystkie inne obiekty).
		for (int i = 0; i < Objects->size(); ++i) {
			Objects->at(i)->Render();
		}

	#pragma endregion

	#pragma region Pomocnicze rysowanie kolizji
		// Narysowanie elipsoidy gracza oraz znalezionego punktu kolizji jeœli u¿ytkownik sobie tego ¿yczy (klawisz "K").
		if (DrawCollisions) {
			glDisable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
			glLineWidth(1.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			glPushMatrix();
				glTranslatef(Player.pos.x, Player.pos.y, Player.pos.z);
				glScalef(Player.collisionEllipsoid->r.x, Player.collisionEllipsoid->r.y, Player.collisionEllipsoid->r.z);
				glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
				glutWireSphere(1.0f, 64, 64);
			glPopMatrix();
			if (MarkCollision) {
				glColor3f(1.0f, 0.0f, 1.0f);
				glPointSize(16.0f);
				glDisable(GL_DEPTH_TEST);
				glBegin(GL_POINTS);
					glVertex3f(LastCollisionPoint.x, LastCollisionPoint.y, LastCollisionPoint.z);
				glEnd();
				glEnable(GL_DEPTH_TEST);
			}
			glEnable(GL_LIGHTING);
		}
	#pragma endregion

}
