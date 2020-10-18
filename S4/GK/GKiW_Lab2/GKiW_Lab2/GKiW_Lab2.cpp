#include "stdafx.h"
#include <GL/glut.h>
#include "GKiW_Lab2.h"

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 360);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("GKiW: Lab 2");

	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnReshape);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyUp);
	glutTimerFunc(17, OnTimer, 0);

	glEnable(GL_DEPTH_TEST);

	// Inicjalizacja stanu kamery:
	player.pos.x = 0.0f;
	player.pos.y = 1.75f;
	player.pos.z = 0.0f;
	player.dir.x = 0.0f;
	player.dir.y = 0.0f;
	player.dir.z = -1.0f;
	player.speed = .1f;

	//float T = acos(player.dir.y);
	//player.dir.x = sin(T)*cos(xyz);
	//player.dir.y = cos(T);
	//player.dir.z = sin(T)*sin(xyz);

	//float xyz = atan2(player.dir.z, player.dir.x);
	//xyz += 0.03f;
	//player.dir.x = cos(xyz);
	//player.dir.z = sin(xyz);

	glutMainLoop();

	return 0;
}

// Tablica przechowująca stan klawiszy w formie flag, indeksowana wg kodów ASCII.
bool keystate[256];


// Obsługa zdarzenia, gdy zostanie wciśnięty klawisz - zdarzenie nieoodporne na repetycję klawiszy.
void OnKeyPress(unsigned char key, int x, int y) {
	printf("KeyPress: %c\n", key);
	if (!keystate[key]) {
		OnKeyDown(key, x, y); // Emulacja zdarzenia związanego z pojedynczym wciśnięciem klawisza
	}
	keystate[key] = true;
}

// Obsługa naszego własnego zdarzenia, gdy zostanie po raz pierwszy wciśnięty klawisz - zdarzenie odporne na repetycję.
void OnKeyDown(unsigned char key, int x, int y) {
	//printf("KeyDown: %c\n", key);
	if (key == 27) { // ESC - wyjście
		glutLeaveMainLoop();
	}
}

// Obsługa zdarzenia puszczenia klawisza.
void OnKeyUp(unsigned char key, int x, int y) {
	printf("KeyUp: %c\n", key);
	keystate[key] = false;
}

void Mouse(int x, int y)
{
	float xyz = atan2(x, y);
	float T = acos(player.dir.y);
	player.dir.x = sin(T)*cos(xyz);
	player.dir.y = cos(T);
	player.dir.z = sin(T)*sin(xyz);
}

float rotx = 0.0f, roty = 0.0f;// initialization

void rotateCamera(int x, int y) {

	rotx += (float)(x - glutGet(GLUT_WINDOW_WIDTH) / 2); // do an additive operation because with "=" your object view, etc... would always set to default
	roty += (float)(y - glutGet(GLUT_WINDOW_HEIGHT) / 2);
	glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
}

// Aktualizacja stanu gry - wywoływana za pośrednictwem zdarzenia-timera.
void OnTimer(int id) {

	// Chcemy, by ta funkcja została wywołana ponownie za 17ms.
	glutTimerFunc(17, OnTimer, 0);

	// Chodzenie do przodu:
	if (keystate['w']) {
		player.pos.x += player.dir.x * player.speed;
		player.pos.y += player.dir.y * player.speed;
		player.pos.z += player.dir.z * player.speed;
	}

	// Chodzenie do tyłu:
	if (keystate['s']) {
		player.pos.x -= player.dir.x * player.speed;
		player.pos.y -= player.dir.y * player.speed;
		player.pos.z -= player.dir.z * player.speed;
	}

	// Chodzenie w lewo:
	if (keystate['d']) {
		player.pos.x -= 1.0f * player.speed;
		player.pos.y += 0.0f * player.speed;
		player.pos.z += 0.0f * player.speed;
	}

	// Chodzenie w prawo:
	if (keystate['a']) {
		player.pos.x += 1.0f * player.speed;
		player.pos.y += 0.0f * player.speed;
		player.pos.z += 0.0f * player.speed;
	}

	// Obrot w lewo:
	if (keystate['j'])
	{
		float xyz = atan2(player.dir.z, player.dir.x);
		xyz -= 0.03f;
		player.dir.x = cos(xyz);
		player.dir.z = sin(xyz);
	}

	// Obrot w prawo:
	if (keystate['l'])
	{
		float xyz = atan2(player.dir.z, player.dir.x);
		xyz += 0.03f;
		player.dir.x = cos(xyz);
		player.dir.z = sin(xyz);
	}

	//glutWarpPointer(320, 190);
	//glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
	glutSetCursor(GLUT_CURSOR_NONE);
	glutPassiveMotionFunc(Mouse);
}

void OnRender() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Ustawienie kamery na podstawie jej stanu przechowywanego w zmiennej player.
	gluLookAt(
		player.pos.x, player.pos.y, player.pos.z, // Pozycja kamery
		player.pos.x + player.dir.x, player.pos.y + player.dir.y, player.pos.z + player.dir.z, // Punkt na ktory patrzy kamera (pozycja + kierunek)
		0.0f, 1.0f, 0.0f // Wektor wyznaczajacy pion
	);

	// Narysowanie "siatki" złożonej ze 121 kolorowych sfer.
	for (int ix = -5; ix <= 5; ix += 1) {
		for (int iz = -5; iz <= 5; iz += 1) {
			glColor3f(.5f + .1f * ix, .5f - .1f * iz, 0.0f);
			glPushMatrix();
			glTranslatef(ix, 1.0f, iz);
			glutSolidSphere(.05f, 8, 8);
			glPopMatrix();
		}
	}

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}

void OnReshape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(60.0f, (float)width / height, .01f, 100.0f);
}